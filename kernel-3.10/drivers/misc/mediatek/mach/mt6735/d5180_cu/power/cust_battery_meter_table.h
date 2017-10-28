#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#include <mach/mt_typedefs.h>

// ============================================================
// define
// ============================================================
#define BAT_NTC_10 1
#define BAT_NTC_47 0

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             16900	
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900	
#endif

#define RBAT_PULL_UP_VOLT          1800



// ============================================================
// ENUM
// ============================================================

// ============================================================
// structure
// ============================================================

// ============================================================
// typedef
// ============================================================
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// ============================================================
// External Variables
// ============================================================

// ============================================================
// External function
// ============================================================

// ============================================================
// <DOD, Battery_Voltage> Table
// ============================================================
#if (BAT_NTC_10 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,68237},
        {-15,53650},
        {-10,42506},
        { -5,33892},
        {  0,27219},
        {  5,22021},
        { 10,17926},
        { 15,14674},
        { 20,12081},
        { 25,10000},
        { 30,8315},
        { 35,6948},
        { 40,5834},
        { 45,4917},
        { 50,4161},
        { 55,3535},
        { 60,3014}
    };
#endif

#if (BAT_NTC_47 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[] = {
        {-20,483954},
        {-15,360850},
        {-10,271697},
        { -5,206463},
        {  0,158214},
        {  5,122259},
        { 10,95227},
        { 15,74730},
        { 20,59065},
        { 25,47000},
        { 30,37643},
        { 35,30334},
        { 40,24591},
        { 45,20048},
        { 50,16433},
        { 55,13539},
        { 60,11210}        
    };
#endif

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
#if 1//fenghua
{0   , 4182},
{1   , 4154},
{2   , 4128},
{3   , 4113},
{4   , 4100},
{5   , 4089},
{6   , 4078},
{7   , 4068},
{8   , 4059},
{9   , 4049},
{10  , 4040},
{10  , 4031},
{11  , 4021},
{12  , 4011},
{13  , 4001},
{14  , 3991},
{15  , 3981},
{16  , 3971},
{17  , 3962},
{18  , 3953},
{19  , 3945},
{20  , 3937},
{21  , 3930},
{22  , 3923},
{23  , 3916},
{24  , 3910},
{25  , 3903},
{26  , 3897},
{27  , 3890},
{28  , 3885},
{29  , 3878},
{30  , 3872},
{30  , 3866},
{31  , 3861},
{32  , 3855},
{33  , 3849},
{34  , 3844},
{35  , 3838},
{36  , 3833},
{37  , 3828},
{38  , 3823},
{39  , 3818},
{40  , 3813},
{41  , 3808},
{42  , 3804},
{43  , 3799},
{44  , 3795},
{45  , 3791},
{46  , 3786},
{47  , 3782},
{48  , 3778},
{49  , 3774},
{50  , 3770},
{50  , 3766},
{51  , 3763},
{52  , 3759},
{53  , 3756},
{54  , 3752},
{55  , 3749},
{56  , 3746},
{57  , 3743},
{58  , 3740},
{59  , 3737},
{60  , 3735},
{61  , 3732},
{62  , 3729},
{63  , 3726},
{64  , 3724},
{65  , 3721},
{66  , 3719},
{67  , 3716},
{68  , 3713},
{69  , 3711},
{70  , 3708},
{70  , 3705},
{71  , 3703},
{72  , 3699},
{73  , 3697},
{74  , 3694},
{75  , 3690},
{76  , 3687},
{77  , 3684},
{78  , 3680},
{79  , 3676},
{80  , 3672},
{81  , 3668},
{82  , 3664},
{83  , 3660},
{84  , 3655},
{85  , 3650},
{86  , 3645},
{87  , 3639},
{88  , 3633},
{89  , 3628},
{90  , 3621},
{90  , 3614},
{91  , 3606},
{92  , 3597},
{93  , 3588},
{94  , 3578},
{95  , 3568},
{96  , 3556},
{97  , 3542},
{98  , 3527},
{99  , 3510},
{100 , 3400},
{100 , 3400},
{100 , 3400},
{100 , 3400},
{100 , 3400},
{100 , 3400},
{100 , 3400},
{100 , 3400} 

#else
//weike
{0   , 4161 },
{1   , 4147 },
{3   , 4133 },
{4   , 4115 },
{5   , 4094 },
{7   , 4067 },
{8   , 4040 },
{9   , 4018 },
{11  , 4002 },
{12  , 3990 },
{13  , 3980 },
{15  , 3972 },
{16  , 3965 },
{17  , 3958 },
{19  , 3951 },
{20  , 3943 },
{21  , 3936 },
{23  , 3929 },
{24  , 3921 },
{25  , 3914 },
{27  , 3906 },
{28  , 3898 },
{29  , 3891 },
{31  , 3883 },
{32  , 3875 },
{33  , 3866 },
{35  , 3858 },
{36  , 3849 },
{37  , 3841 },
{39  , 3833 },
{40  , 3826 },
{41  , 3819 },
{43  , 3813 },
{44  , 3808 },
{45  , 3804 },
{46  , 3800 },
{48  , 3797 },
{49  , 3794 },
{50  , 3792 },
{52  , 3791 },
{53  , 3790 },
{54  , 3789 },
{56  , 3789 },
{57  , 3788 },
{58  , 3787 },
{60  , 3786 },
{61  , 3784 },
{62  , 3783 },
{64  , 3781 },
{65  , 3779 },
{66  , 3776 },
{68  , 3774 },
{69  , 3771 },
{70  , 3768 },
{72  , 3765 },
{73  , 3761 },
{74  , 3757 },
{76  , 3752 },
{77  , 3747 },
{78  , 3742 },
{80  , 3735 },
{81  , 3729 },
{82  , 3721 },
{84  , 3715 },
{85  , 3707 },
{86  , 3700 },
{88  , 3695 },
{89  , 3690 },
{90  , 3686 },
{92  , 3680 },
{93  , 3673 },
{94  , 3663 },
{96  , 3643 },
{97  , 3608 },
{98  , 3548 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 }

#endif
};      
        
// T1 0C 
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{
#if 1//fenghua
{0   , 4178},
{1   , 4149},
{2   , 4134},
{3   , 4122},
{4   , 4111},
{5   , 4123},
{5   , 4102},
{6   , 4086},
{7   , 4075},
{8   , 4067},
{9   , 4058},
{10  , 4049},
{11  , 4040},
{12  , 4031},
{13  , 4023},
{14  , 4013},
{15  , 4003},
{15  , 3993},
{16  , 3984},
{17  , 3976},
{18  , 3968},
{19  , 3960},
{20  , 3953},
{21  , 3946},
{22  , 3939},
{23  , 3932},
{24  , 3926},
{25  , 3920},
{26  , 3913},
{26  , 3907},
{27  , 3900},
{28  , 3894},
{29  , 3888},
{30  , 3882},
{31  , 3877},
{32  , 3871},
{33  , 3865},
{34  , 3860},
{35  , 3855},
{36  , 3849},
{36  , 3844},
{37  , 3840},
{38  , 3835},
{39  , 3830},
{40  , 3825},
{41  , 3821},
{42  , 3816},
{43  , 3812},
{44  , 3808},
{45  , 3804},
{46  , 3800},
{46  , 3796},
{47  , 3792},
{48  , 3788},
{49  , 3785},
{50  , 3781},
{51  , 3778},
{52  , 3774},
{53  , 3771},
{54  , 3768},
{55  , 3765},
{56  , 3762},
{57  , 3760},
{57  , 3757},
{58  , 3754},
{59  , 3752},
{60  , 3750},
{61  , 3747},
{62  , 3745},
{63  , 3743},
{64  , 3741},
{65  , 3739},
{66  , 3737},
{67  , 3734},
{67  , 3732},
{68  , 3730},
{69  , 3728},
{70  , 3726},
{71  , 3724},
{72  , 3721},
{73  , 3719},
{74  , 3716},
{75  , 3713},
{76  , 3711},
{77  , 3708},
{77  , 3705},
{78  , 3702},
{79  , 3699},
{80  , 3695},
{81  , 3691},
{82  , 3688},
{83  , 3683},
{84  , 3679},
{85  , 3674},
{86  , 3668},
{87  , 3663},
{88  , 3657},
{88  , 3650},
{89  , 3642},
{90  , 3634},
{91  , 3624},
{92  , 3614},
{93  , 3602},
{94  , 3588},
{95  , 3573},
{96  , 3555},
{97  , 3533},
{98  , 3508},
{98  , 3476},
{99  , 3437},
{100 , 3400},
{100 , 3400},
{100 , 3400} 

#else
//weike
{0   , 4165 },
{1   , 4140 },
{2   , 4124 },
{4   , 4111 },
{5   , 4100 },
{6   , 4090 },
{7   , 4080 },
{8   , 4069 },
{10  , 4057 },
{11  , 4045 },
{12  , 4032 },
{13  , 4020 },
{14  , 4010 },
{16  , 4000 },
{17  , 3991 },
{18  , 3983 },
{19  , 3976 },
{20  , 3969 },
{22  , 3962 },
{23  , 3956 },
{24  , 3949 },
{25  , 3942 },
{26  , 3936 },
{28  , 3929 },
{29  , 3923 },
{30  , 3916 },
{31  , 3910 },
{33  , 3904 },
{34  , 3897 },
{35  , 3890 },
{36  , 3883 },
{37  , 3876 },
{39  , 3867 },
{40  , 3858 },
{41  , 3850 },
{42  , 3840 },
{43  , 3832 },
{45  , 3825 },
{46  , 3819 },
{47  , 3814 },
{48  , 3810 },
{49  , 3805 },
{51  , 3801 },
{52  , 3798 },
{53  , 3795 },
{54  , 3792 },
{55  , 3789 },
{57  , 3795 },
{58  , 3789 },
{59  , 3787 },
{60  , 3786 },
{61  , 3785 },
{63  , 3784 },
{64  , 3783 },
{65  , 3783 },
{66  , 3782 },
{67  , 3781 },
{69  , 3780 },
{70  , 3779 },
{71  , 3777 },
{72  , 3775 },
{73  , 3772 },
{75  , 3769 },
{76  , 3766 },
{77  , 3763 },
{78  , 3759 },
{79  , 3753 },
{81  , 3748 },
{82  , 3742 },
{83  , 3734 },
{84  , 3726 },
{85  , 3716 },
{87  , 3706 },
{88  , 3695 },
{89  , 3689 },
{90  , 3685 },
{91  , 3680 },
{93  , 3676 },
{94  , 3672 },
{95  , 3664 },
{96  , 3646 },
{98  , 3601 },
{99  , 3527 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 },
{100 , 3400 }

#endif
};           

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
#if 1//fenghua
{0   , 4173},
{1   , 4155},
{2   , 4144},
{3   , 4134},
{4   , 4125},
{4   , 4116},
{5   , 4107},
{6   , 4098},
{7   , 4090},
{8   , 4081},
{9   , 4073},
{10  , 4066},
{11  , 4058},
{12  , 4050},
{13  , 4042},
{13  , 4034},
{14  , 4027},
{15  , 4019},
{16  , 4011},
{17  , 4004},
{18  , 3997},
{19  , 3989},
{20  , 3983},
{21  , 3976},
{22  , 3969},
{22  , 3963},
{23  , 3956},
{24  , 3950},
{25  , 3944},
{26  , 3938},
{27  , 3931},
{28  , 3925},
{29  , 3919},
{30  , 3912},
{30  , 3906},
{31  , 3900},
{32  , 3894},
{33  , 3888},
{34  , 3882},
{35  , 3876},
{36  , 3870},
{37  , 3864},
{38  , 3859},
{39  , 3853},
{39  , 3848},
{40  , 3843},
{41  , 3838},
{42  , 3833},
{43  , 3828},
{44  , 3824},
{45  , 3820},
{46  , 3816},
{47  , 3812},
{48  , 3809},
{48  , 3805},
{49  , 3802},
{50  , 3798},
{51  , 3796},
{52  , 3792},
{53  , 3789},
{54  , 3787},
{55  , 3784},
{56  , 3782},
{57  , 3779},
{57  , 3777},
{58  , 3774},
{59  , 3772},
{60  , 3770},
{61  , 3768},
{62  , 3766},
{63  , 3764},
{64  , 3762},
{65  , 3761},
{65  , 3759},
{66  , 3758},
{67  , 3756},
{68  , 3755},
{69  , 3753},
{70  , 3751},
{71  , 3749},
{72  , 3747},
{73  , 3745},
{74  , 3743},
{74  , 3741},
{75  , 3739},
{76  , 3736},
{77  , 3734},
{78  , 3731},
{79  , 3728},
{80  , 3725},
{81  , 3721},
{82  , 3718},
{83  , 3714},
{83  , 3709},
{84  , 3705},
{85  , 3700},
{86  , 3695},
{87  , 3690},
{88  , 3683},
{89  , 3678},
{90  , 3674},
{91  , 3672},
{91  , 3669},
{92  , 3666},
{93  , 3663},
{94  , 3658},
{95  , 3650},
{96  , 3636},
{97  , 3610},
{98  , 3570},
{99  , 3518},
{100 , 3400},
{100 , 3400} 

#else
//weike
{0  , 4184 },
{1  , 4168 },
{2  , 4155 },
{3  , 4142 },
{5  , 4130 },
{6  , 4118 },
{7  , 4107 },
{8  , 4096 },
{9  , 4085 },
{10 , 4076 },
{11 , 4066 },
{13 , 4057 },
{14 , 4046 },
{15 , 4035 },
{16 , 4025 },
{17 , 4014 },
{18 , 4005 },
{20 , 3996 },
{21 , 3988 },
{22 , 3980 },
{23 , 3973 },
{24 , 3966 },
{25 , 3959 },
{26 , 3951 },
{28 , 3944 },
{29 , 3938 },
{30 , 3931 },
{31 , 3924 },
{32 , 3918 },
{33 , 3912 },
{34 , 3906 },
{36 , 3900 },
{37 , 3894 },
{38 , 3889 },
{39 , 3883 },
{40 , 3877 },
{41 , 3872 },
{42 , 3865 },
{44 , 3857 },
{45 , 3845 },
{46 , 3834 },
{47 , 3825 },
{48 , 3818 },
{49 , 3813 },
{51 , 3808 },
{52 , 3804 },
{53 , 3800 },
{54 , 3797 },
{55 , 3793 },
{56 , 3790 },
{57 , 3788 },
{59 , 3785 },
{60 , 3783 },
{61 , 3780 },
{62 , 3778 },
{63 , 3776 },
{64 , 3774 },
{65 , 3774 },
{67 , 3773 },
{68 , 3772 },
{69 , 3771 },
{70 , 3770 },
{71 , 3769 },
{72 , 3767 },
{73 , 3764 },
{75 , 3761 },
{76 , 3757 },
{77 , 3753 },
{78 , 3749 },
{79 , 3744 },
{80 , 3739 },
{81 , 3735 },
{83 , 3730 },
{84 , 3723 },
{85 , 3715 },
{86 , 3707 },
{87 , 3697 },
{88 , 3686 },
{90 , 3680 },
{91 , 3677 },
{92 , 3675 },
{93 , 3672 },
{94 , 3668 },
{95 , 3661 },
{96 , 3643 },
{98 , 3595 },
{99 , 3525 },
{100, 3400 }

#endif
};     

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
#if 1//fenghua
{0   , 4197},
{1   , 4181},
{2   , 4168},
{3   , 4157},
{4   , 4146},
{4   , 4137},
{5   , 4127},
{6   , 4118},
{7   , 4109},
{8   , 4101},
{9   , 4093},
{10  , 4084},
{11  , 4076},
{12  , 4068},
{12  , 4060},
{13  , 4053},
{14  , 4045},
{15  , 4037},
{16  , 4030},
{17  , 4023},
{18  , 4015},
{19  , 4009},
{20  , 4002},
{20  , 3995},
{21  , 3988},
{22  , 3981},
{23  , 3975},
{24  , 3969},
{25  , 3962},
{26  , 3956},
{27  , 3950},
{28  , 3944},
{28  , 3938},
{29  , 3933},
{30  , 3927},
{31  , 3921},
{32  , 3916},
{33  , 3910},
{34  , 3905},
{35  , 3899},
{36  , 3894},
{36  , 3888},
{37  , 3883},
{38  , 3878},
{39  , 3872},
{40  , 3866},
{41  , 3860},
{42  , 3854},
{43  , 3848},
{44  , 3841},
{44  , 3835},
{45  , 3830},
{46  , 3825},
{47  , 3820},
{48  , 3816},
{49  , 3812},
{50  , 3809},
{51  , 3805},
{52  , 3802},
{52  , 3799},
{53  , 3796},
{54  , 3793},
{55  , 3791},
{56  , 3788},
{57  , 3786},
{58  , 3783},
{59  , 3781},
{60  , 3779},
{60  , 3777},
{61  , 3774},
{62  , 3773},
{63  , 3770},
{64  , 3769},
{65  , 3767},
{66  , 3765},
{67  , 3763},
{68  , 3761},
{68  , 3759},
{69  , 3757},
{70  , 3756},
{71  , 3753},
{72  , 3750},
{73  , 3747},
{74  , 3743},
{75  , 3739},
{76  , 3736},
{76  , 3733},
{77  , 3730},
{78  , 3726},
{79  , 3722},
{80  , 3720},
{81  , 3717},
{82  , 3713},
{83  , 3709},
{84  , 3707},
{84  , 3700},
{85  , 3695},
{86  , 3690},
{87  , 3685},
{88  , 3679},
{89  , 3672},
{90  , 3667},
{91  , 3664},
{92  , 3663},
{92  , 3661},
{93  , 3658},
{94  , 3654},
{95  , 3648},
{96  , 3634},
{97  , 3605},
{98  , 3563},
{99  , 3512},
{100 , 3400} 

#else
//weike
{0   , 4194 },
{1   , 4176 },
{2   , 4161 },
{3   , 4147 },
{5   , 4134 },
{6   , 4122 },
{7   , 4110 },
{8   , 4099 },
{9   , 4088 },
{10  , 4077 },
{12  , 4066 },
{13  , 4056 },
{14  , 4046 },
{15  , 4036 },
{16  , 4027 },
{17  , 4017 },
{19  , 4008 },
{20  , 3999 },
{21  , 3990 },
{22  , 3982 },
{23  , 3973 },
{24  , 3965 },
{26  , 3957 },
{27  , 3950 },
{28  , 3942 },
{29  , 3935 },
{30  , 3928 },
{31  , 3921 },
{33  , 3915 },
{34  , 3908 },
{35  , 3902 },
{36  , 3895 },
{37  , 3890 },
{38  , 3884 },
{40  , 3878 },
{41  , 3873 },
{42  , 3868 },
{43  , 3862 },
{44  , 3855 },
{45  , 3844 },
{47  , 3831 },
{48  , 3822 },
{49  , 3815 },
{50  , 3810 },
{51  , 3805 },
{52  , 3801 },
{54  , 3798 },
{55  , 3794 },
{56  , 3791 },
{57  , 3788 },
{58  , 3785 },
{59  , 3782 },
{61  , 3780 },
{62  , 3778 },
{63  , 3775 },
{64  , 3774 },
{65  , 3772 },
{66  , 3770 },
{68  , 3769 },
{69  , 3768 },
{70  , 3766 },
{71  , 3765 },
{72  , 3761 },
{73  , 3753 },
{75  , 3746 },
{76  , 3743 },
{77  , 3739 },
{78  , 3734 },
{79  , 3729 },
{80  , 3725 },
{82  , 3720 },
{83  , 3716 },
{84  , 3710 },
{85  , 3701 },
{86  , 3693 },
{87  , 3684 },
{89  , 3672 },
{90  , 3667 },
{91  , 3665 },
{92  , 3663 },
{93  , 3660 },
{94  , 3656 },
{96  , 3648 },
{97  , 3620 },
{98  , 3566 },
{99  , 3491 },
{100 , 3400 },
{100 , 3400 }

#endif
};           

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
#if 1//fenghua
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0} 

#else
//weike
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 }

#endif
};    

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
#if 1//fenghua
{616 , 4182},
{616 , 4154},
{827 , 4128},
{834 , 4113},
{825 , 4100},
{817 , 4089},
{823 , 4078},
{823 , 4068},
{820 , 4059},
{821 , 4049},
{820 , 4040},
{820 , 4031},
{820 , 4021},
{817 , 4011},
{817 , 4001},
{815 , 3991},
{815 , 3981},
{817 , 3971},
{816 , 3962},
{813 , 3953},
{813 , 3945},
{813 , 3937},
{813 , 3930},
{812 , 3923},
{814 , 3916},
{810 , 3910},
{811 , 3903},
{810 , 3897},
{807 , 3890},
{810 , 3885},
{808 , 3878},
{809 , 3872},
{806 , 3866},
{808 , 3861},
{810 , 3855},
{796 , 3849},
{803 , 3844},
{799 , 3838},
{799 , 3833},
{802 , 3828},
{798 , 3823},
{796 , 3818},
{791 , 3813},
{792 , 3808},
{779 , 3804},
{778 , 3799},
{772 , 3795},
{777 , 3791},
{775 , 3786},
{766 , 3782},
{765 , 3778},
{758 , 3774},
{761 , 3770},
{755 , 3766},
{755 , 3763},
{755 , 3759},
{751 , 3756},
{751 , 3752},
{751 , 3749},
{747 , 3746},
{751 , 3743},
{751 , 3740},
{748 , 3737},
{747 , 3735},
{746 , 3732},
{745 , 3729},
{744 , 3726},
{747 , 3724},
{744 , 3721},
{746 , 3719},
{747 , 3716},
{744 , 3713},
{744 , 3711},
{744 , 3708},
{744 , 3705},
{744 , 3703},
{748 , 3699},
{748 , 3697},
{747 , 3694},
{750 , 3690},
{747 , 3687},
{751 , 3684},
{750 , 3680},
{754 , 3676},
{752 , 3672},
{754 , 3668},
{758 , 3664},
{758 , 3660},
{760 , 3655},
{766 , 3650},
{765 , 3645},
{774 , 3639},
{778 , 3633},
{783 , 3628},
{787 , 3621},
{792 , 3614},
{797 , 3606},
{795 , 3597},
{811 , 3588},
{808 , 3578},
{829 , 3568},
{849 , 3556},
{869 , 3542},
{886 , 3527},
{904 , 3510},
{913 , 3400},
{913 , 3400},
{913 , 3400},
{913 , 3400},
{913 , 3400},
{913 , 3400},
{913 , 3400},
{913 , 3400} 

#else
//weike
{425  , 4161 },
{425  , 4147 },
{465  , 4133 },
{474  , 4115 },
{485  , 4094 },
{501  , 4067 },
{540  , 4040 },
{589  , 4018 },
{613  , 4002 },
{618  , 3990 },
{623  , 3980 },
{630  , 3972 },
{640  , 3965 },
{646  , 3958 },
{653  , 3951 },
{658  , 3943 },
{665  , 3936 },
{667  , 3929 },
{668  , 3921 },
{671  , 3914 },
{679  , 3906 },
{679  , 3898 },
{678  , 3891 },
{682  , 3883 },
{684  , 3875 },
{682  , 3866 },
{683  , 3858 },
{680  , 3849 },
{680  , 3841 },
{677  , 3833 },
{676  , 3826 },
{678  , 3819 },
{676  , 3813 },
{677  , 3808 },
{687  , 3804 },
{691  , 3800 },
{692  , 3797 },
{694  , 3794 },
{693  , 3792 },
{704  , 3791 },
{713  , 3790 },
{720  , 3789 },
{740  , 3789 },
{754  , 3788 },
{776  , 3787 },
{809  , 3786 },
{836  , 3784 },
{882  , 3783 },
{920  , 3781 },
{972  , 3779 },
{1012 , 3776 },
{1059 , 3774 },
{1094 , 3771 },
{1136 , 3768 },
{1164 , 3765 },
{1205 , 3761 },
{1230 , 3757 },
{1270 , 3752 },
{1298 , 3747 },
{1343 , 3742 },
{1369 , 3735 },
{1417 , 3729 },
{1446 , 3721 },
{1491 , 3715 },
{1532 , 3707 },
{1564 , 3700 },
{1604 , 3695 },
{1656 , 3690 },
{1712 , 3686 },
{1780 , 3680 },
{1863 , 3673 },
{1957 , 3663 },
{2066 , 3643 },
{2201 , 3608 },
{2388 , 3548 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 },
{2710 , 3400 }

#endif
};      

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
#if 1//fenghua
{453 , 4178},
{453 , 4149},
{452 , 4134},
{452 , 4122},
{450 , 4111},
{239 , 4123},
{433 , 4102},
{462 , 4086},
{459 , 4075},
{462 , 4067},
{459 , 4058},
{458 , 4049},
{457 , 4040},
{456 , 4031},
{456 , 4023},
{454 , 4013},
{455 , 4003},
{454 , 3993},
{454 , 3984},
{454 , 3976},
{453 , 3968},
{454 , 3960},
{452 , 3953},
{452 , 3946},
{452 , 3939},
{451 , 3932},
{451 , 3926},
{451 , 3920},
{451 , 3913},
{451 , 3907},
{450 , 3900},
{450 , 3894},
{449 , 3888},
{449 , 3882},
{450 , 3877},
{449 , 3871},
{450 , 3865},
{450 , 3860},
{450 , 3855},
{448 , 3849},
{450 , 3844},
{451 , 3840},
{450 , 3835},
{450 , 3830},
{450 , 3825},
{451 , 3821},
{451 , 3816},
{450 , 3812},
{450 , 3808},
{451 , 3804},
{451 , 3800},
{451 , 3796},
{451 , 3792},
{451 , 3788},
{452 , 3785},
{452 , 3781},
{452 , 3778},
{451 , 3774},
{452 , 3771},
{451 , 3768},
{452 , 3765},
{454 , 3762},
{454 , 3760},
{454 , 3757},
{454 , 3754},
{454 , 3752},
{454 , 3750},
{454 , 3747},
{455 , 3745},
{455 , 3743},
{456 , 3741},
{455 , 3739},
{456 , 3737},
{456 , 3734},
{456 , 3732},
{456 , 3730},
{456 , 3728},
{458 , 3726},
{458 , 3724},
{458 , 3721},
{458 , 3719},
{458 , 3716},
{459 , 3713},
{459 , 3711},
{460 , 3708},
{459 , 3705},
{460 , 3702},
{461 , 3699},
{462 , 3695},
{462 , 3691},
{463 , 3688},
{462 , 3683},
{464 , 3679},
{464 , 3674},
{465 , 3668},
{466 , 3663},
{468 , 3657},
{468 , 3650},
{470 , 3642},
{471 , 3634},
{472 , 3624},
{476 , 3614},
{479 , 3602},
{484 , 3588},
{489 , 3573},
{496 , 3555},
{504 , 3533},
{514 , 3508},
{530 , 3476},
{548 , 3437},
{576 , 3400},
{576 , 3400},
{576 , 3400} 

#else
//weike
{250  , 4165 },
{250  , 4140 },
{257  , 4124 },
{258  , 4111 },
{261  , 4100 },
{267  , 4090 },
{282  , 4080 },
{291  , 4069 },
{295  , 4057 },
{298  , 4045 },
{297  , 4032 },
{294  , 4020 },
{291  , 4010 },
{288  , 4000 },
{288  , 3991 },
{288  , 3983 },
{292  , 3976 },
{294  , 3969 },
{299  , 3962 },
{304  , 3956 },
{305  , 3949 },
{307  , 3942 },
{309  , 3936 },
{312  , 3929 },
{313  , 3923 },
{314  , 3916 },
{316  , 3910 },
{318  , 3904 },
{318  , 3897 },
{316  , 3890 },
{316  , 3883 },
{312  , 3876 },
{308  , 3867 },
{301  , 3858 },
{296  , 3850 },
{286  , 3840 },
{280  , 3832 },
{275  , 3825 },
{272  , 3819 },
{270  , 3814 },
{270  , 3810 },
{270  , 3805 },
{270  , 3801 },
{271  , 3798 },
{271  , 3795 },
{271  , 3792 },
{271  , 3789 },
{290  , 3795 },
{276  , 3789 },
{278  , 3787 },
{280  , 3786 },
{282  , 3785 },
{284  , 3784 },
{289  , 3783 },
{298  , 3783 },
{306  , 3782 },
{320  , 3781 },
{336  , 3780 },
{357  , 3779 },
{379  , 3777 },
{403  , 3775 },
{425  , 3772 },
{446  , 3769 },
{464  , 3766 },
{480  , 3763 },
{495  , 3759 },
{510  , 3753 },
{529  , 3748 },
{545  , 3742 },
{564  , 3734 },
{587  , 3726 },
{611  , 3716 },
{638  , 3706 },
{669  , 3695 },
{705  , 3689 },
{751  , 3685 },
{807  , 3680 },
{881  , 3676 },
{977  , 3672 },
{1096 , 3664 },
{1243 , 3646 },
{1402 , 3601 },
{1641 , 3527 },
{2049 , 3400 },
{2049 , 3400 },
{2049 , 3400 },
{2049 , 3400 },
{2049 , 3400 }

#endif
};     

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
#if 1//fenghua
{202 , 4173},
{202 , 4155},
{192 , 4144},
{213 , 4134},
{213 , 4125},
{206 , 4116},
{204 , 4107},
{203 , 4098},
{190 , 4090},
{182 , 4081},
{181 , 4073},
{194 , 4066},
{149 , 4058},
{167 , 4050},
{177 , 4042},
{171 , 4034},
{168 , 4027},
{167 , 4019},
{161 , 4011},
{165 , 4004},
{154 , 3997},
{151 , 3989},
{151 , 3983},
{150 , 3976},
{141 , 3969},
{140 , 3963},
{138 , 3956},
{136 , 3950},
{133 , 3944},
{131 , 3938},
{131 , 3931},
{134 , 3925},
{142 , 3919},
{143 , 3912},
{120 , 3906},
{138 , 3900},
{146 , 3894},
{143 , 3888},
{148 , 3882},
{149 , 3876},
{148 , 3870},
{149 , 3864},
{147 , 3859},
{146 , 3853},
{137 , 3848},
{140 , 3843},
{138 , 3838},
{139 , 3833},
{132 , 3828},
{140 , 3824},
{139 , 3820},
{137 , 3816},
{136 , 3812},
{133 , 3809},
{136 , 3805},
{138 , 3802},
{138 , 3798},
{138 , 3796},
{136 , 3792},
{133 , 3789},
{133 , 3787},
{130 , 3784},
{128 , 3782},
{126 , 3779},
{124 , 3777},
{121 , 3774},
{122 , 3772},
{112 , 3770},
{118 , 3768},
{116 , 3766},
{112 , 3764},
{112 , 3762},
{112 , 3761},
{111 , 3759},
{110 , 3758},
{111 , 3756},
{111 , 3755},
{109 , 3753},
{105 , 3751},
{109 , 3749},
{107 , 3747},
{105 , 3745},
{105 , 3743},
{103 , 3741},
{102 , 3739},
{102 , 3736},
{100 , 3734},
{102 , 3731},
{102 , 3728},
{102 , 3725},
{101 , 3721},
{100 , 3718},
{101 , 3714},
{102 , 3709},
{102 , 3705},
{102 , 3700},
{101 , 3695},
{103 , 3690},
{105 , 3683},
{102 , 3678},
{106 , 3674},
{102 , 3672},
{107 , 3669},
{107 , 3666},
{104 , 3663},
{94  , 3658},
{109 , 3650},
{107 , 3636},
{109 , 3610},
{111 , 3570},
{113 , 3518},
{121 , 3400},
{121 , 3400} 

#else
//weike
{85   , 4184 },
{85   , 4168 },
{88   , 4155 },
{88   , 4142 },
{88   , 4130 },
{89   , 4118 },
{89   , 4107 },
{88   , 4096 },
{89   , 4085 },
{91   , 4076 },
{91   , 4066 },
{89   , 4057 },
{91   , 4046 },
{91   , 4035 },
{90   , 4025 },
{91   , 4014 },
{94   , 4005 },
{93   , 3996 },
{90   , 3988 },
{93   , 3980 },
{93   , 3973 },
{94   , 3966 },
{99   , 3959 },
{98   , 3951 },
{101  , 3944 },
{100  , 3938 },
{104  , 3931 },
{107  , 3924 },
{109  , 3918 },
{110  , 3912 },
{110  , 3906 },
{111  , 3900 },
{115  , 3894 },
{116  , 3889 },
{119  , 3883 },
{120  , 3877 },
{120  , 3872 },
{122  , 3865 },
{117  , 3857 },
{108  , 3845 },
{99   , 3834 },
{91   , 3825 },
{89   , 3818 },
{88   , 3813 },
{86   , 3808 },
{84   , 3804 },
{82   , 3800 },
{85   , 3797 },
{84   , 3793 },
{85   , 3790 },
{86   , 3788 },
{87   , 3785 },
{87   , 3783 },
{88   , 3780 },
{87   , 3778 },
{88   , 3776 },
{88   , 3774 },
{87   , 3774 },
{88   , 3773 },
{89   , 3772 },
{90   , 3771 },
{91   , 3770 },
{92   , 3769 },
{91   , 3767 },
{91   , 3764 },
{91   , 3761 },
{91   , 3757 },
{92   , 3753 },
{94   , 3749 },
{98   , 3744 },
{98   , 3739 },
{100  , 3735 },
{102  , 3730 },
{106  , 3723 },
{108  , 3715 },
{109  , 3707 },
{113  , 3697 },
{113  , 3686 },
{115  , 3680 },
{119  , 3677 },
{123  , 3675 },
{130  , 3672 },
{141  , 3668 },
{149  , 3661 },
{156  , 3643 },
{171  , 3595 },
{196  , 3525 },
{252  , 3400 }

#endif
}; 

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
#if 1//fenghua
{99  , 4197},
{99  , 4181},
{98  , 4168},
{98  , 4157},
{96  , 4146},
{96  , 4137},
{96  , 4127},
{95  , 4118},
{96  , 4109},
{97  , 4101},
{96  , 4093},
{97  , 4084},
{97  , 4076},
{97  , 4068},
{97  , 4060},
{96  , 4053},
{97  , 4045},
{96  , 4037},
{98  , 4030},
{98  , 4023},
{97  , 4015},
{98  , 4009},
{98  , 4002},
{97  , 3995},
{98  , 3988},
{97  , 3981},
{98  , 3975},
{98  , 3969},
{98  , 3962},
{98  , 3956},
{99  , 3950},
{98  , 3944},
{98  , 3938},
{99  , 3933},
{97  , 3927},
{99  , 3921},
{99  , 3916},
{98  , 3910},
{98  , 3905},
{99  , 3899},
{99  , 3894},
{98  , 3888},
{99  , 3883},
{99  , 3878},
{99  , 3872},
{99  , 3866},
{99  , 3860},
{99  , 3854},
{99  , 3848},
{99  , 3841},
{99  , 3835},
{100 , 3830},
{101 , 3825},
{101 , 3820},
{102 , 3816},
{102 , 3812},
{102 , 3809},
{103 , 3805},
{104 , 3802},
{104 , 3799},
{105 , 3796},
{106 , 3793},
{106 , 3791},
{107 , 3788},
{108 , 3786},
{108 , 3783},
{108 , 3781},
{109 , 3779},
{109 , 3777},
{109 , 3774},
{110 , 3773},
{111 , 3770},
{112 , 3769},
{112 , 3767},
{111 , 3765},
{111 , 3763},
{111 , 3761},
{111 , 3759},
{111 , 3757},
{111 , 3756},
{111 , 3753},
{111 , 3750},
{112 , 3747},
{112 , 3743},
{111 , 3739},
{113 , 3736},
{113 , 3733},
{113 , 3730},
{113 , 3726},
{113 , 3722},
{115 , 3720},
{113 , 3717},
{115 , 3713},
{115 , 3709},
{119 , 3707},
{119 , 3700},
{120 , 3695},
{120 , 3690},
{120 , 3685},
{120 , 3679},
{121 , 3672},
{120 , 3667},
{122 , 3664},
{122 , 3663},
{123 , 3661},
{123 , 3658},
{124 , 3654},
{123 , 3648},
{123 , 3634},
{127 , 3605},
{127 , 3563},
{129 , 3512},
{133 , 3400} 

#else
//weike
{50  , 4194 },
{50  , 4176 },
{50  , 4161 },
{52  , 4147 },
{52  , 4134 },
{51  , 4122 },
{53  , 4110 },
{52  , 4099 },
{52  , 4088 },
{53  , 4077 },
{53  , 4066 },
{53  , 4056 },
{54  , 4046 },
{54  , 4036 },
{54  , 4027 },
{54  , 4017 },
{54  , 4008 },
{54  , 3999 },
{55  , 3990 },
{56  , 3982 },
{55  , 3973 },
{56  , 3965 },
{56  , 3957 },
{57  , 3950 },
{58  , 3942 },
{57  , 3935 },
{60  , 3928 },
{59  , 3921 },
{61  , 3915 },
{62  , 3908 },
{62  , 3902 },
{64  , 3895 },
{66  , 3890 },
{68  , 3884 },
{70  , 3878 },
{72  , 3873 },
{75  , 3868 },
{78  , 3862 },
{78  , 3855 },
{70  , 3844 },
{60  , 3831 },
{56  , 3822 },
{57  , 3815 },
{55  , 3810 },
{54  , 3805 },
{54  , 3801 },
{55  , 3798 },
{54  , 3794 },
{54  , 3791 },
{54  , 3788 },
{54  , 3785 },
{55  , 3782 },
{56  , 3780 },
{56  , 3778 },
{57  , 3775 },
{57  , 3774 },
{58  , 3772 },
{59  , 3770 },
{60  , 3769 },
{61  , 3768 },
{63  , 3766 },
{64  , 3765 },
{60  , 3761 },
{52  , 3753 },
{53  , 3746 },
{57  , 3743 },
{55  , 3739 },
{56  , 3734 },
{55  , 3729 },
{56  , 3725 },
{55  , 3720 },
{57  , 3716 },
{58  , 3710 },
{58  , 3701 },
{59  , 3693 },
{59  , 3684 },
{58  , 3672 },
{59  , 3667 },
{61  , 3665 },
{64  , 3663 },
{68  , 3660 },
{70  , 3656 },
{71  , 3648 },
{72  , 3620 },
{78  , 3566 },
{84  , 3491 },
{92  , 3400 },
{92  , 3400 }

#endif
}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
#if 1//fenghua
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0},
{0 , 0} 

#else
//weike
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 },
{0  , 0 }

#endif
};    

// ============================================================
// function prototype
// ============================================================
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);

#endif	//#ifndef _CUST_BATTERY_METER_TABLE_H

