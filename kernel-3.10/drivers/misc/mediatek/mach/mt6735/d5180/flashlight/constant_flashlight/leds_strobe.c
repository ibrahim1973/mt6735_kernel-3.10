#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/time.h>
#include "kd_flashlight.h"
#include <asm/io.h>
#include <asm/uaccess.h>
#include "kd_camera_hw.h"
#include <cust_gpio_usage.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/xlog.h>
#include <linux/version.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37))
#include <linux/mutex.h>
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
#include <linux/semaphore.h>
#else
#include <asm/semaphore.h>
#endif
#endif

#include <mach/upmu_common.h> 
#include <mach/upmu_hw.h> 
#include <linux/leds.h>
#include <leds_sw.h>


/******************************************************************************
 * Debug configuration
******************************************************************************/
// availible parameter
// ANDROID_LOG_ASSERT
// ANDROID_LOG_ERROR
// ANDROID_LOG_WARNING
// ANDROID_LOG_INFO
// ANDROID_LOG_DEBUG
// ANDROID_LOG_VERBOSE
#define TAG_NAME "leds_strobe.c"
#define PK_DBG_NONE(fmt, arg...)    do {} while (0)
#define PK_DBG_FUNC(fmt, arg...)    xlog_printk(ANDROID_LOG_DEBUG  , TAG_NAME, KERN_INFO  "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_WARN(fmt, arg...)        xlog_printk(ANDROID_LOG_WARNING, TAG_NAME, KERN_WARNING  "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_NOTICE(fmt, arg...)      xlog_printk(ANDROID_LOG_DEBUG  , TAG_NAME, KERN_NOTICE  "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_INFO(fmt, arg...)        xlog_printk(ANDROID_LOG_INFO   , TAG_NAME, KERN_INFO  "%s: " fmt, __FUNCTION__ ,##arg)
#define PK_TRC_FUNC(f)              xlog_printk(ANDROID_LOG_DEBUG  , TAG_NAME,  "<%s>\n", __FUNCTION__);
#define PK_TRC_VERBOSE(fmt, arg...) xlog_printk(ANDROID_LOG_VERBOSE, TAG_NAME,  fmt, ##arg)
#define PK_ERROR(fmt, arg...)       xlog_printk(ANDROID_LOG_ERROR  , TAG_NAME, KERN_ERR "%s: " fmt, __FUNCTION__ ,##arg)


#define DEBUG_LEDS_STROBE
#ifdef  DEBUG_LEDS_STROBE
	#define PK_DBG PK_DBG_FUNC
	#define PK_VER PK_TRC_VERBOSE
	#define PK_ERR PK_ERROR
#else
	#define PK_DBG(a,...)
	#define PK_VER(a,...)
	#define PK_ERR(a,...)
#endif

/******************************************************************************
 * local variables
******************************************************************************/

static DEFINE_SPINLOCK(g_strobeSMPLock); /* cotta-- SMP proection */


static u32 strobe_Res = 0;
static u32 strobe_Timeus = 0;
static BOOL g_strobe_On = 0;
static int g_duty_torch=0;
static int g_duty=-1;
static int g_timeOutTimeMs=0;

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37))
static DEFINE_MUTEX(g_strobeSem);
#else
static DECLARE_MUTEX(g_strobeSem);
#endif


#define STROBE_DEVICE_ID 0x60


static int flashCur[] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


static struct work_struct workTimeOut;

/*****************************************************************************
Functions
*****************************************************************************/
#define GPIO_ENF GPIO_CAMERA_FLASH_EN_PIN
#define GPIO_ENT GPIO_CAMERA_FLASH_MODE_PIN


    /*CAMERA-FLASH-EN */


extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
static void work_timeOutFunc(struct work_struct *data);











/* add by lisong start
--------------------------------------------
true flash(KTD265EJH-TR)
ENF:GPIO12
ENM(ENT):GPIO13
1)ENF-HIGH,ENM-LOW is flash-mode
2)ENF-LOW,ENM-HIGH is torch-mode
3)ENF-HIGH,ENM-HIGH is torch-mode
4)ENF-LOW,ENM-LOW is off

--------------------------------------------
fake flash
ENABLE_PIN:GPIO12
GPIO12-HIGH:on
GPIO12-LOW:off

add by lisong end */
int FL_Enable(void)
{
	/*
	pmic_config_interface(0x0828,1,1,0);*/

	 pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down 				

    if(g_duty_torch == 1) {
		pmic_set_register_value(PMIC_ISINK_CH0_EN,0x1); // Turn on ISINK Channel 0
	} else {
		pmic_set_register_value(PMIC_ISINK_CH0_EN,0x1); // Turn on ISINK Channel 0
		pmic_set_register_value(PMIC_ISINK_CH1_EN,0x1); // Turn on ISINK Channel 0
	}
	PK_DBG(" FL_Enable line=%d\n",__LINE__);
	return 0;
}


int FL_Disable(void)
{
    if(g_duty_torch == 1) {	
		pmic_set_register_value(PMIC_ISINK_CH0_EN,0x0); // Turn off ISINK Channel 0
	} else {
		pmic_set_register_value(PMIC_ISINK_CH0_EN,0x0); // Turn off ISINK Channel 0
		pmic_set_register_value(PMIC_ISINK_CH1_EN,0x0); // Turn off ISINK Channel 0
	}
	
	PK_DBG(" FL_Disable line=%d\n",__LINE__);
	return 0;
}


int FL_dim_duty(kal_uint32 duty)
{
	g_duty=duty;
	g_duty_torch = duty;
	PK_DBG(" FL_dim_duty line=%d\n",__LINE__);
    return 0;
}


int FL_Init(void)
{
		pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN,0x0); // Disable power down	
		pmic_set_register_value(PMIC_RG_DRV_ISINK0_CK_PDN,0);
		pmic_set_register_value(PMIC_RG_DRV_ISINK0_CK_CKSEL,0);
		pmic_set_register_value(PMIC_ISINK_CH0_MODE,ISINK_PWM_MODE);
		pmic_set_register_value(PMIC_ISINK_CH0_STEP,ISINK_5);//24mA
		pmic_set_register_value(PMIC_ISINK_DIM0_DUTY,31);
		pmic_set_register_value(PMIC_ISINK_DIM0_FSEL,ISINK_1KHZ);//1KHz


 
		pmic_set_register_value(PMIC_RG_DRV_ISINK1_CK_PDN,0);
		pmic_set_register_value(PMIC_RG_DRV_ISINK1_CK_CKSEL,0);
		pmic_set_register_value(PMIC_ISINK_CH1_MODE,ISINK_PWM_MODE);
		pmic_set_register_value(PMIC_ISINK_CH1_STEP,ISINK_5);//24mA
		pmic_set_register_value(PMIC_ISINK_DIM1_DUTY,31);
		pmic_set_register_value(PMIC_ISINK_DIM1_FSEL,ISINK_1KHZ);//1KHz

	INIT_WORK(&workTimeOut, work_timeOutFunc);
	PK_DBG(" FL_Init line=%d\n",__LINE__);
	return 0;
}



int FL_Uninit(void)
{
	FL_Disable();
    return 0;
}

/*****************************************************************************
User interface
*****************************************************************************/

static void work_timeOutFunc(struct work_struct *data)
{
    FL_Disable();
    PK_DBG("ledTimeOut_callback\n");
    //printk(KERN_ALERT "work handler function./n");
}



enum hrtimer_restart ledTimeOutCallback(struct hrtimer *timer)
{
    schedule_work(&workTimeOut);
    return HRTIMER_NORESTART;
}
static struct hrtimer g_timeOutTimer;
void timerInit(void)
{
	g_timeOutTimeMs=1000; //1s
	hrtimer_init( &g_timeOutTimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL );
	g_timeOutTimer.function=ledTimeOutCallback;

}



static int constant_flashlight_ioctl(MUINT32 cmd, MUINT32 arg)
{
	int i4RetValue = 0;
	int ior_shift;
	int iow_shift;
	int iowr_shift;
	ior_shift = cmd - (_IOR(FLASHLIGHT_MAGIC,0, int));
	iow_shift = cmd - (_IOW(FLASHLIGHT_MAGIC,0, int));
	iowr_shift = cmd - (_IOWR(FLASHLIGHT_MAGIC,0, int));
	PK_DBG("constant_flashlight_ioctl() line=%d ior_shift=%d, iow_shift=%d iowr_shift=%d arg=%d\n",__LINE__, ior_shift, iow_shift, iowr_shift, arg);
    switch(cmd)
    {

		case FLASH_IOC_SET_TIME_OUT_TIME_MS:
			PK_DBG("FLASH_IOC_SET_TIME_OUT_TIME_MS: %d\n",arg);
			g_timeOutTimeMs=arg;
		break;


    	case FLASH_IOC_SET_DUTY :
    		PK_DBG("FLASHLIGHT_DUTY: %d\n",arg);
    		FL_dim_duty(arg);
    		break;


    	case FLASH_IOC_SET_STEP:
    		PK_DBG("FLASH_IOC_SET_STEP: %d\n",arg);

    		break;

    	case FLASH_IOC_SET_ONOFF :
    		PK_DBG("FLASHLIGHT_ONOFF: %d\n",arg);
    		if(arg==1)
    		{

    		    int s;
    		    int ms;
    		    if(g_timeOutTimeMs>1000)
            	{
            		s = g_timeOutTimeMs/1000;
            		ms = g_timeOutTimeMs - s*1000;
            	}
            	else
            	{
            		s = 0;
            		ms = g_timeOutTimeMs;
            	}

				if(g_timeOutTimeMs!=0)
	            {
	            	ktime_t ktime;
					ktime = ktime_set( s, ms*1000000 );
					hrtimer_start( &g_timeOutTimer, ktime, HRTIMER_MODE_REL );
	            }
    			FL_Enable();
    		}
    		else
    		{
    			FL_Disable();
				g_duty_torch = 0;
				hrtimer_cancel( &g_timeOutTimer );
    		}
    		break;
		default :
    		PK_DBG(" No such command \n");
    		i4RetValue = -EPERM;
    		break;
    }
    return i4RetValue;
}




static int constant_flashlight_open(void *pArg)
{
    int i4RetValue = 0;
    PK_DBG("constant_flashlight_open line=%d\n", __LINE__);

	if (0 == strobe_Res)
	{
	    FL_Init();
		timerInit();
	}
	PK_DBG("constant_flashlight_open line=%d\n", __LINE__);
	spin_lock_irq(&g_strobeSMPLock);


    if(strobe_Res)
    {
        PK_ERR(" busy!\n");
        i4RetValue = -EBUSY;
    }
    else
    {
        strobe_Res += 1;
    }


    spin_unlock_irq(&g_strobeSMPLock);
    PK_DBG("constant_flashlight_open line=%d\n", __LINE__);

    return i4RetValue;

}


static int constant_flashlight_release(void *pArg)
{
    PK_DBG(" constant_flashlight_release\n");

    if (strobe_Res)
    {
        spin_lock_irq(&g_strobeSMPLock);

        strobe_Res = 0;
        strobe_Timeus = 0;

        /* LED On Status */
        g_strobe_On = FALSE;

        spin_unlock_irq(&g_strobeSMPLock);

    	FL_Uninit();
    }

    PK_DBG(" Done\n");

    return 0;

}


FLASHLIGHT_FUNCTION_STRUCT	constantFlashlightFunc=
{
	constant_flashlight_open,
	constant_flashlight_release,
	constant_flashlight_ioctl
};


MUINT32 constantFlashlightInit(PFLASHLIGHT_FUNCTION_STRUCT *pfFunc)
{
    if (pfFunc != NULL)
    {
        *pfFunc = &constantFlashlightFunc;
    }
    return 0;
}



/* LED flash control for high current capture mode*/
ssize_t strobe_VDIrq(void)
{

    return 0;
}

EXPORT_SYMBOL(strobe_VDIrq);


#if 1//add by lisong for test start

struct class *main_flashlight_class;
struct device *main_flashlight_dev;

static ssize_t main_flashlight_enable_store(struct device *dev,struct device_attribute *attr, const char *buf, size_t size)
{
    int enable = 0;
    
    if(buf != NULL && size != 0)
    {
        enable = (int)simple_strtoul(buf, NULL, 0);
    }
    if (enable)
    {
        FL_Init();
        mdelay(10);
        FL_Enable();
    }
    else
    {
        FL_Disable();
    }
    return size;
}

static DEVICE_ATTR(main_flashlight_enable, 0644, NULL, main_flashlight_enable_store);

static int __init main_flashlight_init(void)  
{		
	main_flashlight_class = class_create(THIS_MODULE, "main_flashlight");
	main_flashlight_dev = device_create(main_flashlight_class,NULL, 0, NULL,  "main_flashlight");
    device_create_file(main_flashlight_dev, &dev_attr_main_flashlight_enable);
	
	return 0;
}
static void __exit main_flashlight_exit(void)
{
	return;
}



//-----------------------------------------
module_init(main_flashlight_init);
module_exit(main_flashlight_exit);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("main_flashlight");
MODULE_AUTHOR("lisong <song.li@ragentek.com>");
#endif//add by lisong for test end

