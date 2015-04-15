#line 1 "WyzBee_gpio\\WyzBee_gpio.c"













 












 






 

#line 1 ".\\WyzBee_gpio\\WyzBee_gpio.h"













 













 










 


#line 1 ".\\common\\gpio.h"







































 
 









 




 
 
 
#line 1 ".\\common\\pdl.h"







































 
 








 




 
 
 
#line 1 ".\\common\\base_types.h"







































 
 








 




 
 
 
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   










#line 107 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

#line 59 ".\\common\\base_types.h"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 60 ".\\common\\base_types.h"
  
 
 
 

   




   



 


 


 




 

 
typedef uint8_t      boolean_t;
  
 
typedef float        float32_t;

 
typedef double       float64_t;

 
typedef char         char_t;

 
typedef void         (*func_ptr_t)(void);

 
typedef void         (*func_ptr_arg1_t)(uint8_t);

 
typedef enum en_result
{
    Ok                          = 0,  
    Error                       = 1,  
    ErrorAddressAlignment       = 2,  
    ErrorAccessRights           = 3,  
    ErrorInvalidParameter       = 4,  
    ErrorOperationInProgress    = 5,  
    ErrorInvalidMode            = 6,  
    ErrorUninitialized          = 7,  
    ErrorBufferFull             = 8,  
    ErrorTimeout                = 9,  
    ErrorNotReady               = 10, 
    OperationInProgress         = 11  
} en_result_t;







 
typedef enum en_level
{
    PDLLow      = 0,  
    PDLHigh     = 1   
} en_level_t;







 
typedef enum en_flag
{
    PdlClr = 0,       
    PdlSet = 1        
} en_stat_flag_t, en_int_flag_t;      

 
 
 

 
 
 



 
 
 
#line 59 ".\\common\\pdl.h"
#line 1 ".\\common\\mcu.h"







































 








 








  
#line 1 ".\\common\\mb9abxxx.h"







































 
 












 










 




  



 

typedef enum IRQn
{
    NMI_IRQn          = -14,  
    HardFault_IRQn    = -13,  
    MemManage_IRQn    = -12,  
    BusFault_IRQn     = -11,  
    UsageFault_IRQn   = -10,  
    SVC_IRQn          = -5,   
    DebugMonitor_IRQn = -4,   
    PendSV_IRQn       = -2,   
    SysTick_IRQn      = -1,   

    CSV_IRQn              =   0,   
    SWDT_IRQn             =   1,   
    LVD_IRQn              =   2,   
    IRQ003SEL_IRQn        =   3,   
    IRQ004SEL_IRQn        =   4,   
    IRQ005SEL_IRQn        =   5,   
    IRQ006SEL_IRQn        =   6,   
    IRQ007SEL_IRQn        =   7,   
    IRQ008SEL_IRQn        =   8,   
    IRQ009SEL_IRQn        =   9,   
    IRQ010SEL_IRQn        =  10,   
    EXINT0_IRQn           =  11,   
    EXINT1_IRQn           =  12,   
    EXINT2_IRQn           =  13,   
    EXINT3_IRQn           =  14,   
    EXINT4_IRQn           =  15,   
    EXINT5_IRQn           =  16,   
    EXINT6_IRQn           =  17,   
    EXINT7_IRQn           =  18,   
    QPRC0_IRQn            =  19,   
    QPRC1_IRQn            =  20,   
    WFG0_DTIF0_IRQn       =  21,   
    WFG1_DTIF1_IRQn       =  22,   
    WFG2_DTIF2_IRQn       =  23,   
    FRT0_PEAK_IRQn        =  24,   
    FRT0_ZERO_IRQn        =  25,   
    ICU0_IRQn             =  26,   
    OCU0_IRQn             =  27,   
    FRT1_PEAK_IRQn        =  28,   
    FRT1_ZERO_IRQn        =  29,   
    ICU1_IRQn             =  30,   
    OCU1_IRQn             =  31,   
    FRT2_PEAK_IRQn        =  32,   
    FRT2_ZERO_IRQn        =  33,   
    ICU2_IRQn             =  34,   
    OCU2_IRQn             =  35,   
    PPG00_02_04_IRQn      =  36,   
    PPG08_10_12_IRQn      =  37,   
    PPG16_18_20_IRQn      =  38,   
    BT0_IRQn              =  39,   
    BT1_IRQn              =  40,   
    BT2_IRQn              =  41,   
    BT3_IRQn              =  42,   
    BT4_IRQn              =  43,   
    BT5_IRQn              =  44,   
    BT6_IRQn              =  45,   
    BT7_IRQn              =  46,   
    DT1_2_IRQn            =  47,   
    WC_IRQn               =  48,   
    EXTBUS_ERR_IRQn       =  49,   
    RTC_IRQn              =  50,   
    EXINT8_IRQn           =  51,   
    EXINT9_IRQn           =  52,   
    EXINT10_IRQn          =  53,   
    EXINT11_IRQn          =  54,   
    EXINT12_IRQn          =  55,   
    EXINT13_IRQn          =  56,   
    EXINT14_IRQn          =  57,   
    EXINT15_IRQn          =  58,   
    TIM_IRQn              =  59,   
    MFS0_RX_IRQn          =  60,   
    MFS0_TX_IRQn          =  61,   
    MFS1_RX_IRQn          =  62,   
    MFS1_TX_IRQn          =  63,   
    MFS2_RX_IRQn          =  64,   
    MFS2_TX_IRQn          =  65,   
    MFS3_RX_IRQn          =  66,   
    MFS3_TX_IRQn          =  67,   
    MFS4_RX_IRQn          =  68,   
    MFS4_TX_IRQn          =  69,   
    MFS5_RX_IRQn          =  70,   
    MFS5_TX_IRQn          =  71,   
    MFS6_RX_IRQn          =  72,   
    MFS6_TX_IRQn          =  73,   
    MFS7_RX_IRQn          =  74,   
    MFS7_TX_IRQn          =  75,   
    ADC0_IRQn             =  76,   
    ADC1_IRQn             =  77,   
    USB0_IRQn             =  78,   
    USB0_HOST_IRQn        =  79,   
    CAN0_IRQn             =  80,   
    CAN1_IRQn             =  81,   
    ETHER0_IRQn           =  82,   
    DMAC0_IRQn            =  83,   
    DMAC1_IRQn            =  84,   
    DMAC2_IRQn            =  85,   
    DMAC3_IRQn            =  86,   
    DMAC4_IRQn            =  87,   
    DMAC5_IRQn            =  88,   
    DMAC6_IRQn            =  89,   
    DMAC7_IRQn            =  90,   
    DSTC_IRQn             =  91,   
    EXINT16_17_18_19_IRQn =  92,   
    EXINT20_21_22_23_IRQn =  93,   
    EXINT24_25_26_27_IRQn =  94,   
    EXINT28_29_30_31_IRQn =  95,   
    QPRC2_IRQn            =  96,   
    QPRC3_IRQn            =  97,   
    BT8_IRQn              =  98,   
    BT9_IRQn              =  99,   
    BT10_IRQn             = 100,   
    BT11_IRQn             = 101,   
    BT12_13_14_15_IRQn    = 102,   
    MFS8_RX_IRQn          = 103,   
    MFS8_TX_IRQn          = 104,   
    MFS9_RX_IRQn          = 105,   
    MFS9_TX_IRQn          = 106,   
    MFS10_RX_IRQn         = 107,   
    MFS10_TX_IRQn         = 108,   
    MFS11_RX_IRQn         = 109,   
    MFS11_TX_IRQn         = 110,   
    ADC2_IRQn             = 111,   
    USB1_IRQn             = 113,   
    USB1_HOST_IRQn        = 114,   
    SD_IRQn               = 118,   
    FLASH_IRQn            = 119,   
    MFS12_RX_IRQn         = 120,   
    MFS12_TX_IRQn         = 121,   
    MFS13_RX_IRQn         = 122,   
    MFS13_TX_IRQn         = 123,   
    MFS14_RX_IRQn         = 124,   
    MFS14_TX_IRQn         = 125,   
    MFS15_RX_IRQn         = 126,   
    MFS15_TX_IRQn         = 127    
} IRQn_Type;






#line 1 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"
 







 

























 
























 




 


 

 













#line 110 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"


 
#line 124 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"

#line 185 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"

#line 187 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"
#line 1 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cmInstr.h"
 







 

























 






 



 


 









 







 







 






 








 







 







 









 









 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}










 










 











 









 









 









 











 











 











 







 










 










 









 





#line 684 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cmInstr.h"

   

#line 188 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"
#line 1 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cmFunc.h"
 







 

























 






 



 


 





 
 






 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}







 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}







 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}







 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}







 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}







 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}







 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}







 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}







 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}








 







 








 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}







 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xff);
}







 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}







 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1);
}











 
static __inline uint32_t __get_FPSCR(void)
{

  register uint32_t __regfpscr         __asm("fpscr");
  return(__regfpscr);



}







 
static __inline void __set_FPSCR(uint32_t fpscr)
{

  register uint32_t __regfpscr         __asm("fpscr");
  __regfpscr = (fpscr);

}




#line 634 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cmFunc.h"

 

#line 189 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"
#line 1 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4_simd.h"
 







 

























 
















 


 



 


 
#line 122 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4_simd.h"











#line 689 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4_simd.h"

 






#line 190 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"








 
#line 225 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"

 






 
#line 241 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"

 













 


 





 


 
typedef union
{
  struct
  {



    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                

    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;



 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;



 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       



    uint32_t _reserved0:7;                
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                

    uint32_t T:1;                         
    uint32_t IT:2;                        
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;



 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 






 


 
typedef struct
{
  volatile uint32_t ISER[8];                  
       uint32_t RESERVED0[24];
  volatile uint32_t ICER[8];                  
       uint32_t RSERVED1[24];
  volatile uint32_t ISPR[8];                  
       uint32_t RESERVED2[24];
  volatile uint32_t ICPR[8];                  
       uint32_t RESERVED3[24];
  volatile uint32_t IABR[8];                  
       uint32_t RESERVED4[56];
  volatile uint8_t  IP[240];                  
       uint32_t RESERVED5[644];
  volatile  uint32_t STIR;                     
}  NVIC_Type;

 



 






 


 
typedef struct
{
  volatile const  uint32_t CPUID;                    
  volatile uint32_t ICSR;                     
  volatile uint32_t VTOR;                     
  volatile uint32_t AIRCR;                    
  volatile uint32_t SCR;                      
  volatile uint32_t CCR;                      
  volatile uint8_t  SHP[12];                  
  volatile uint32_t SHCSR;                    
  volatile uint32_t CFSR;                     
  volatile uint32_t HFSR;                     
  volatile uint32_t DFSR;                     
  volatile uint32_t MMFAR;                    
  volatile uint32_t BFAR;                     
  volatile uint32_t AFSR;                     
  volatile const  uint32_t PFR[2];                   
  volatile const  uint32_t DFR;                      
  volatile const  uint32_t ADR;                      
  volatile const  uint32_t MMFR[4];                  
  volatile const  uint32_t ISAR[5];                  
       uint32_t RESERVED0[5];
  volatile uint32_t CPACR;                    
} SCB_Type;

 















 






























 



 





















 









 


















 










































 









 









 















 






 


 
typedef struct
{
       uint32_t RESERVED0[1];
  volatile const  uint32_t ICTR;                     
  volatile uint32_t ACTLR;                    
} SCnSCB_Type;

 



 















 






 


 
typedef struct
{
  volatile uint32_t CTRL;                     
  volatile uint32_t LOAD;                     
  volatile uint32_t VAL;                      
  volatile const  uint32_t CALIB;                    
} SysTick_Type;

 












 



 



 









 






 


 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                   
    volatile  uint16_t   u16;                  
    volatile  uint32_t   u32;                  
  }  PORT [32];                           
       uint32_t RESERVED0[864];
  volatile uint32_t TER;                      
       uint32_t RESERVED1[15];
  volatile uint32_t TPR;                      
       uint32_t RESERVED2[15];
  volatile uint32_t TCR;                      
       uint32_t RESERVED3[29];
  volatile  uint32_t IWR;                      
  volatile const  uint32_t IRR;                      
  volatile uint32_t IMCR;                     
       uint32_t RESERVED4[43];
  volatile  uint32_t LAR;                      
  volatile const  uint32_t LSR;                      
       uint32_t RESERVED5[6];
  volatile const  uint32_t PID4;                     
  volatile const  uint32_t PID5;                     
  volatile const  uint32_t PID6;                     
  volatile const  uint32_t PID7;                     
  volatile const  uint32_t PID0;                     
  volatile const  uint32_t PID1;                     
  volatile const  uint32_t PID2;                     
  volatile const  uint32_t PID3;                     
  volatile const  uint32_t CID0;                     
  volatile const  uint32_t CID1;                     
  volatile const  uint32_t CID2;                     
  volatile const  uint32_t CID3;                     
} ITM_Type;

 



 



























 



 



 



 









   






 


 
typedef struct
{
  volatile uint32_t CTRL;                     
  volatile uint32_t CYCCNT;                   
  volatile uint32_t CPICNT;                   
  volatile uint32_t EXCCNT;                   
  volatile uint32_t SLEEPCNT;                 
  volatile uint32_t LSUCNT;                   
  volatile uint32_t FOLDCNT;                  
  volatile const  uint32_t PCSR;                     
  volatile uint32_t COMP0;                    
  volatile uint32_t MASK0;                    
  volatile uint32_t FUNCTION0;                
       uint32_t RESERVED0[1];
  volatile uint32_t COMP1;                    
  volatile uint32_t MASK1;                    
  volatile uint32_t FUNCTION1;                
       uint32_t RESERVED1[1];
  volatile uint32_t COMP2;                    
  volatile uint32_t MASK2;                    
  volatile uint32_t FUNCTION2;                
       uint32_t RESERVED2[1];
  volatile uint32_t COMP3;                    
  volatile uint32_t MASK3;                    
  volatile uint32_t FUNCTION3;                
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   






 


 
typedef struct
{
  volatile uint32_t SSPSR;                    
  volatile uint32_t CSPSR;                    
       uint32_t RESERVED0[2];
  volatile uint32_t ACPR;                     
       uint32_t RESERVED1[55];
  volatile uint32_t SPPR;                     
       uint32_t RESERVED2[131];
  volatile const  uint32_t FFSR;                     
  volatile uint32_t FFCR;                     
  volatile const  uint32_t FSCR;                     
       uint32_t RESERVED3[759];
  volatile const  uint32_t TRIGGER;                  
  volatile const  uint32_t FIFO0;                    
  volatile const  uint32_t ITATBCTR2;                
       uint32_t RESERVED4[1];
  volatile const  uint32_t ITATBCTR0;                
  volatile const  uint32_t FIFO1;                    
  volatile uint32_t ITCTRL;                   
       uint32_t RESERVED5[39];
  volatile uint32_t CLAIMSET;                 
  volatile uint32_t CLAIMCLR;                 
       uint32_t RESERVED7[8];
  volatile const  uint32_t DEVID;                    
  volatile const  uint32_t DEVTYPE;                  
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   







 


 
typedef struct
{
  volatile const  uint32_t TYPE;                     
  volatile uint32_t CTRL;                     
  volatile uint32_t RNR;                      
  volatile uint32_t RBAR;                     
  volatile uint32_t RASR;                     
  volatile uint32_t RBAR_A1;                  
  volatile uint32_t RASR_A1;                  
  volatile uint32_t RBAR_A2;                  
  volatile uint32_t RASR_A2;                  
  volatile uint32_t RBAR_A3;                  
  volatile uint32_t RASR_A3;                  
} MPU_Type;

 









 









 



 









 






























 








 


 
typedef struct
{
       uint32_t RESERVED0[1];
  volatile uint32_t FPCCR;                    
  volatile uint32_t FPCAR;                    
  volatile uint32_t FPDSCR;                   
  volatile const  uint32_t MVFR0;                    
  volatile const  uint32_t MVFR1;                    
} FPU_Type;

 



























 



 












 
























 












 







 


 
typedef struct
{
  volatile uint32_t DHCSR;                    
  volatile  uint32_t DCRSR;                    
  volatile uint32_t DCRDR;                    
  volatile uint32_t DEMCR;                    
} CoreDebug_Type;

 




































 






 







































 






 

 
#line 1399 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"

#line 1408 "C:\\Keil_v5\\ARM\\CMSIS\\Include\\core_cm4.h"











 










 

 



 




 










 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07);                

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((0xFFFFUL << 16) | (7UL << 8));              
  reg_value  =  (reg_value                                 |
                ((uint32_t)0x5FA << 16) |
                (PriorityGroupTmp << 8));                                      
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}







 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8)) >> 8);    
}







 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
 
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(uint32_t)((int32_t)IRQn) >> 5] = (uint32_t)(1 << ((uint32_t)((int32_t)IRQn) & (uint32_t)0x1F));  
}







 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}











 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}







 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}







 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}










 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}










 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4)) & 0xff);    }         
}












 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[(uint32_t)(IRQn)]           >> (8 - 4)));  }  
}













 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;

  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}













 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;

  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}





 
static __inline void NVIC_SystemReset(void)
{
  __dsb(0xF);                                                     
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = ((0x5FA << 16)      |
                 (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8)) |
                 (1UL << 2));                    
  __dsb(0xF);                                                      
  while(1);                                                     
}

 



 




 

















 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1) > (0xFFFFFFUL << 0))  return (1);       

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = ticks - 1;                                   
  NVIC_SetPriority (SysTick_IRQn, (1<<4) - 1);   
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2) |
                   (1UL << 1)   |
                   (1UL << 0);                     
  return (0);                                                   
}



 



 




 

extern volatile int32_t ITM_RxBuffer;                     












 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL << 0))                  &&       
      (((ITM_Type *) (0xE0000000UL) )->TER & (1UL << 0)        )                    )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000UL) )->PORT[0].u8 = (uint8_t) ch;
  }
  return (ch);
}








 
static __inline int32_t ITM_ReceiveChar (void) {
  int32_t ch = -1;                            

  if (ITM_RxBuffer != 0x5AA55AA5) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5;        
  }

  return (ch);
}








 
static __inline int32_t ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5) {
    return (0);                                  
  } else {
    return (1);                                  
  }
}

 





#line 220 ".\\common\\mb9abxxx.h"
#line 1 ".\\common\\system_mb9abxxx.h"







































 
 















 








 
 
 
#line 70 ".\\common\\system_mb9abxxx.h"

 
 
 
   
 
 
 
    
 
 
 
 








  


  









  









   

  




     






   


































  




















     

 














     

   
























      

   
























     




















   









   

  












   

 




































      


























     






















     

















     

   







   









   


   
 
 
 
  
 
 

 
 
 





     

   




  






  

   




  






  

   




  

   




  

   




  






  

   




  






  








  

   







  



 
 
 


















































 
 
 




 





 





 





 


 
 
 




 
#line 642 ".\\common\\system_mb9abxxx.h"




 
#line 664 ".\\common\\system_mb9abxxx.h"

 
 
 















   



   
  
  
 
 
 

extern uint32_t SystemCoreClock;          
   
extern void SystemInit (void);            

extern void SystemCoreClockUpdate (void); 





#line 221 ".\\common\\mb9abxxx.h"
#line 222 ".\\common\\mb9abxxx.h"









 
 
 


#pragma anon_unions




 


 
typedef struct
{
    volatile uint32_t DRQSEL;
    uint8_t RESERVED0[12];
    volatile uint32_t EXC02MON;
    volatile uint32_t IRQ000MON;
    volatile uint32_t IRQ001MON;
    volatile uint32_t IRQ002MON;
    volatile uint32_t IRQ003MON;
    volatile uint32_t IRQ004MON;
    volatile uint32_t IRQ005MON;
    volatile uint32_t IRQ006MON;
    volatile uint32_t IRQ007MON;
    volatile uint32_t IRQ008MON;
    volatile uint32_t IRQ009MON;
    volatile uint32_t IRQ010MON;
    volatile uint32_t IRQ011MON;
    volatile uint32_t IRQ012MON;
    volatile uint32_t IRQ013MON;
    volatile uint32_t IRQ014MON;
    volatile uint32_t IRQ015MON;
    volatile uint32_t IRQ016MON;
    volatile uint32_t IRQ017MON;
    volatile uint32_t IRQ018MON;
    volatile uint32_t IRQ019MON;
    volatile uint32_t IRQ020MON;
    volatile uint32_t IRQ021MON;
    volatile uint32_t IRQ022MON;
    volatile uint32_t IRQ023MON;
    volatile uint32_t IRQ024MON;
    volatile uint32_t IRQ025MON;
    volatile uint32_t IRQ026MON;
    volatile uint32_t IRQ027MON;
    volatile uint32_t IRQ028MON;
    volatile uint32_t IRQ029MON;
    volatile uint32_t IRQ030MON;
    volatile uint32_t IRQ031MON;
    volatile uint32_t IRQ032MON;
    volatile uint32_t IRQ033MON;
    volatile uint32_t IRQ034MON;
    volatile uint32_t IRQ035MON;
    volatile uint32_t IRQ036MON;
    volatile uint32_t IRQ037MON;
    volatile uint32_t IRQ038MON;
    volatile uint32_t IRQ039MON;
    volatile uint32_t IRQ040MON;
    volatile uint32_t IRQ041MON;
    volatile uint32_t IRQ042MON;
    volatile uint32_t IRQ043MON;
    volatile uint32_t IRQ044MON;
    volatile uint32_t IRQ045MON;
    volatile uint32_t IRQ046MON;
    volatile uint32_t IRQ047MON;
    volatile uint32_t IRQ048MON;
    volatile uint32_t IRQ049MON;
    volatile uint32_t IRQ050MON;
    volatile uint32_t IRQ051MON;
    volatile uint32_t IRQ052MON;
    volatile uint32_t IRQ053MON;
    volatile uint32_t IRQ054MON;
    volatile uint32_t IRQ055MON;
    volatile uint32_t IRQ056MON;
    volatile uint32_t IRQ057MON;
    volatile uint32_t IRQ058MON;
    volatile uint32_t IRQ059MON;
    volatile uint32_t IRQ060MON;
    volatile uint32_t IRQ061MON;
    volatile uint32_t IRQ062MON;
    volatile uint32_t IRQ063MON;
    volatile uint32_t IRQ064MON;
    volatile uint32_t IRQ065MON;
    volatile uint32_t IRQ066MON;
    volatile uint32_t IRQ067MON;
    volatile uint32_t IRQ068MON;
    volatile uint32_t IRQ069MON;
    volatile uint32_t IRQ070MON;
    volatile uint32_t IRQ071MON;
    volatile uint32_t IRQ072MON;
    volatile uint32_t IRQ073MON;
    volatile uint32_t IRQ074MON;
    volatile uint32_t IRQ075MON;
    volatile uint32_t IRQ076MON;
    volatile uint32_t IRQ077MON;
    volatile uint32_t IRQ078MON;
    volatile uint32_t IRQ079MON;
    volatile uint32_t IRQ080MON;
    volatile uint32_t IRQ081MON;
    volatile uint32_t IRQ082MON;
    volatile uint32_t IRQ083MON;
    volatile uint32_t IRQ084MON;
    volatile uint32_t IRQ085MON;
    volatile uint32_t IRQ086MON;
    volatile uint32_t IRQ087MON;
    volatile uint32_t IRQ088MON;
    volatile uint32_t IRQ089MON;
    volatile uint32_t IRQ090MON;
    volatile uint32_t IRQ091MON;
    volatile uint32_t IRQ092MON;
    volatile uint32_t IRQ093MON;
    volatile uint32_t IRQ094MON;
    volatile uint32_t IRQ095MON;
    volatile uint32_t IRQ096MON;
    volatile uint32_t IRQ097MON;
    volatile uint32_t IRQ098MON;
    volatile uint32_t IRQ099MON;
    volatile uint32_t IRQ100MON;
    volatile uint32_t IRQ101MON;
    volatile uint32_t IRQ102MON;
    volatile uint32_t IRQ103MON;
    volatile uint32_t IRQ104MON;
    volatile uint32_t IRQ105MON;
    volatile uint32_t IRQ106MON;
    volatile uint32_t IRQ107MON;
    volatile uint32_t IRQ108MON;
    volatile uint32_t IRQ109MON;
    volatile uint32_t IRQ110MON;
    volatile uint32_t IRQ111MON;
    volatile uint32_t IRQ112MON;
    volatile uint32_t IRQ113MON;
    volatile uint32_t IRQ114MON;
    volatile uint32_t IRQ115MON;
    volatile uint32_t IRQ116MON;
    volatile uint32_t IRQ117MON;
    volatile uint32_t IRQ118MON;
    volatile uint32_t IRQ119MON;
    volatile uint32_t IRQ120MON;
    volatile uint32_t IRQ121MON;
    volatile uint32_t IRQ122MON;
    volatile uint32_t IRQ123MON;
    volatile uint32_t IRQ124MON;
    volatile uint32_t IRQ125MON;
    volatile uint32_t IRQ126MON;
    volatile uint32_t IRQ127MON;
    volatile uint32_t IRQ128MON;
    volatile uint32_t IRQ129MON;
    volatile uint32_t IRQ130MON;
    volatile uint32_t IRQ131MON;
    volatile uint32_t IRQ132MON;
    volatile uint32_t IRQ133MON;
    volatile uint32_t IRQ134MON;
    volatile uint32_t IRQ135MON;
    volatile uint32_t IRQ136MON;
    volatile uint32_t IRQ137MON;
    volatile uint32_t IRQ138MON;
    volatile uint32_t IRQ139MON;
    volatile uint32_t IRQ140MON;
    volatile uint32_t IRQ141MON;
    volatile uint32_t IRQ142MON;
    volatile uint32_t IRQ143MON;
    volatile uint32_t IRQ144MON;
    volatile uint32_t IRQ145MON;
    volatile uint32_t IRQ146MON;
    volatile uint32_t IRQ147MON;
    volatile uint32_t IRQ148MON;
    volatile uint32_t IRQ149MON;
    volatile uint32_t IRQ150MON;
    volatile uint32_t IRQ151MON;
    volatile uint32_t IRQ152MON;
    volatile uint32_t IRQ153MON;
    volatile uint32_t IRQ154MON;
    volatile uint32_t IRQ155MON;
    volatile uint32_t IRQ156MON;
    volatile uint32_t IRQ157MON;
    volatile uint32_t IRQ158MON;
    volatile uint32_t IRQ159MON;
    volatile uint32_t IRQ160MON;
    volatile uint32_t IRQ161MON;
    volatile uint32_t IRQ162MON;
    volatile uint32_t IRQ163MON;
    volatile uint32_t IRQ164MON;
    volatile uint32_t IRQ165MON;
    volatile uint32_t IRQ166MON;
    volatile uint32_t IRQ167MON;
    volatile uint32_t IRQ168MON;
    volatile uint32_t IRQ169MON;
    volatile uint32_t IRQ170MON;
    volatile uint32_t IRQ171MON;
    volatile uint32_t IRQ172MON;
    volatile uint32_t IRQ173MON;
    volatile uint32_t IRQ174MON;
    volatile uint32_t IRQ175MON;
    volatile uint32_t IRQ176MON;
    volatile uint32_t IRQ177MON;
    volatile uint32_t IRQ178MON;
    volatile uint32_t IRQ179MON;
    volatile uint32_t IRQ180MON;
    volatile uint32_t IRQ181MON;
    volatile uint32_t IRQ182MON;
    volatile uint32_t IRQ183MON;
    volatile uint32_t IRQ184MON;
    volatile uint32_t IRQ185MON;
    volatile uint32_t IRQ186MON;
    volatile uint32_t IRQ187MON;
    volatile uint32_t IRQ188MON;
    volatile uint32_t IRQ189MON;
    volatile uint32_t IRQ190MON;
    volatile uint32_t IRQ191MON;
    volatile uint32_t IRQ192MON;
    volatile uint32_t IRQ193MON;
    volatile uint32_t IRQ194MON;
    volatile uint32_t IRQ195MON;
    volatile uint32_t IRQ196MON;
    volatile uint32_t IRQ197MON;
    volatile uint32_t IRQ198MON;
    volatile uint32_t IRQ199MON;
    volatile uint32_t IRQ200MON;
    volatile uint32_t IRQ201MON;
    volatile uint32_t IRQ202MON;
    volatile uint32_t IRQ203MON;
    volatile uint32_t IRQ204MON;
    volatile uint32_t IRQ205MON;
    volatile uint32_t IRQ206MON;
    volatile uint32_t IRQ207MON;
    volatile uint32_t IRQ208MON;
    volatile uint32_t IRQ209MON;
    volatile uint32_t IRQ210MON;
    volatile uint32_t IRQ211MON;
    volatile uint32_t IRQ212MON;
    volatile uint32_t IRQ213MON;
    volatile uint32_t IRQ214MON;
    volatile uint32_t IRQ215MON;
    volatile uint32_t IRQ216MON;
    volatile uint32_t IRQ217MON;
    volatile uint32_t IRQ218MON;
    volatile uint32_t IRQ219MON;
    volatile uint32_t IRQ220MON;
    volatile uint32_t IRQ221MON;
    volatile uint32_t IRQ222MON;
    volatile uint32_t IRQ223MON;
    volatile uint32_t IRQ224MON;
    volatile uint32_t IRQ225MON;
    volatile uint32_t IRQ226MON;
    volatile uint32_t IRQ227MON;
    volatile uint32_t IRQ228MON;
    volatile uint32_t IRQ229MON;
    volatile uint32_t IRQ230MON;
    volatile uint32_t IRQ231MON;
    volatile uint32_t IRQ232MON;
    volatile uint32_t IRQ233MON;
    volatile uint32_t IRQ234MON;
    volatile uint32_t IRQ235MON;
    volatile uint32_t IRQ236MON;
    volatile uint32_t IRQ237MON;
    volatile uint32_t IRQ238MON;
    volatile uint32_t IRQ239MON;
    volatile uint32_t IRQ240MON;
    volatile uint32_t IRQ241MON;
    volatile uint32_t IRQ242MON;
    volatile uint32_t IRQ243MON;
    volatile uint32_t IRQ244MON;
    volatile uint32_t IRQ245MON;
    volatile uint32_t IRQ246MON;
    volatile uint32_t IRQ247MON;
    volatile uint32_t IRQ248MON;
    volatile uint32_t IRQ249MON;
    volatile uint32_t IRQ250MON;
    volatile uint32_t IRQ251MON;
    volatile uint32_t IRQ252MON;
    volatile uint32_t IRQ253MON;
    volatile uint32_t IRQ254MON;
    volatile uint32_t IRQ255MON;
}PDL_INTREQ_TypeDef;











 



 
 
typedef struct stc_workflash_if_wfaszr_field
{
  volatile uint32_t ASZ        : 1;
} stc_workflash_if_wfaszr_field_t;

typedef struct stc_workflash_if_wfrwtr_field
{
  volatile uint32_t RWT        : 3;
} stc_workflash_if_wfrwtr_field_t;

typedef struct stc_workflash_if_wfstr_field
{
  volatile uint32_t RDY        : 1;
  volatile uint32_t HNG        : 1;
} stc_workflash_if_wfstr_field_t;



 
 
typedef struct stc_flash_if_faszr_field
{
  volatile uint32_t ASZ        : 2;
} stc_flash_if_faszr_field_t;

typedef struct stc_flash_if_frwtr_field
{
  volatile uint32_t RWT        : 2;
} stc_flash_if_frwtr_field_t;

typedef struct stc_flash_if_fstr_field
{
  volatile uint32_t RDY        : 1;
  volatile uint32_t HNG        : 1;
  volatile uint32_t ERR        : 1;
} stc_flash_if_fstr_field_t;

typedef struct stc_flash_if_fsyndn_field
{
  volatile uint32_t SD         : 3;
} stc_flash_if_fsyndn_field_t;

typedef struct stc_flash_if_fbfcr_field
{
  volatile uint32_t BE         : 1;
  volatile uint32_t BS         : 1;
} stc_flash_if_fbfcr_field_t;

typedef struct stc_flash_if_ficr_field
{
  volatile uint32_t RDYIE      : 1;
  volatile uint32_t HANGIE     : 1;
  volatile uint32_t ERRIE      : 1;
} stc_flash_if_ficr_field_t;

typedef struct stc_flash_if_fisr_field
{
  volatile uint32_t RDYIF      : 1;
  volatile uint32_t HANGIF     : 1;
  volatile uint32_t ERRIF      : 1;
} stc_flash_if_fisr_field_t;

typedef struct stc_flash_if_ficlr_field
{
  volatile uint32_t RDYIC      : 1;
  volatile uint32_t HANGIC     : 1;
  volatile uint32_t ERRIC      : 1;
} stc_flash_if_ficlr_field_t;

typedef struct stc_flash_if_crtrmm_field
{
  volatile uint32_t TRMM       :10;
       uint32_t RESERVED10 : 6;
  volatile uint32_t TTRMM      : 5;
} stc_flash_if_crtrmm_field_t;



 
 
typedef struct stc_unique_id_uidr0_field
{
       uint32_t RESERVED0  : 4;
  volatile uint32_t UID        :28;
} stc_unique_id_uidr0_field_t;

typedef struct stc_unique_id_uidr1_field
{
  volatile uint32_t UID        :13;
} stc_unique_id_uidr1_field_t;



 
 
typedef struct stc_ecc_capture_ferrad_field
{
  volatile uint32_t FERRAD     :23;
} stc_ecc_capture_ferrad_field_t;



 
 
typedef struct stc_crg_scm_ctl_field
{
        uint8_t RESERVED1  : 1;
  volatile  uint8_t MOSCE      : 1;
        uint8_t RESERVED2  : 1;
  volatile  uint8_t SOSCE      : 1;
  volatile  uint8_t PLLE       : 1;
  volatile  uint8_t RCS        : 3;
} stc_crg_scm_ctl_field_t;

typedef struct stc_crg_scm_str_field
{
        uint8_t RESERVED1  : 1;
  volatile  uint8_t MORDY      : 1;
        uint8_t RESERVED2  : 1;
  volatile  uint8_t SORDY      : 1;
  volatile  uint8_t PLRDY      : 1;
  volatile  uint8_t RCM0       : 1;
  volatile  uint8_t RCM1       : 1;
  volatile  uint8_t RCM2       : 1;
} stc_crg_scm_str_field_t;

typedef struct stc_crg_rst_str_field
{
  volatile uint16_t PONR       : 1;
  volatile uint16_t INITX      : 1;
  volatile uint16_t LVDH       : 1;
       uint16_t RESERVED1  : 1;
  volatile uint16_t SWDT       : 1;
  volatile uint16_t HWDT       : 1;
  volatile uint16_t CSVR       : 1;
  volatile uint16_t FCSR       : 1;
  volatile uint16_t SRST       : 1;
} stc_crg_rst_str_field_t;

typedef struct stc_crg_bsc_psr_field
{
  volatile  uint8_t BSR0       : 1;
  volatile  uint8_t BSR1       : 1;
  volatile  uint8_t BSR2       : 1;
} stc_crg_bsc_psr_field_t;

typedef struct stc_crg_apbc0_psr_field
{
  volatile  uint8_t APBC00     : 1;
  volatile  uint8_t APBC01     : 1;
} stc_crg_apbc0_psr_field_t;

typedef struct stc_crg_apbc1_psr_field
{
  volatile  uint8_t APBC10     : 1;
  volatile  uint8_t APBC11     : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t APBC1RST   : 1;
        uint8_t RESERVED2  : 2;
  volatile  uint8_t APBC1EN    : 1;
} stc_crg_apbc1_psr_field_t;

typedef struct stc_crg_apbc2_psr_field
{
  volatile  uint8_t APBC20     : 1;
  volatile  uint8_t APBC21     : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t APBC2RST   : 1;
        uint8_t RESERVED2  : 2;
  volatile  uint8_t APBC2EN    : 1;
} stc_crg_apbc2_psr_field_t;

typedef struct stc_crg_swc_psr_field
{
  volatile  uint8_t SWDS0      : 1;
  volatile  uint8_t SWDS1      : 1;
        uint8_t RESERVED1  : 5;
  volatile  uint8_t TESTB      : 1;
} stc_crg_swc_psr_field_t;

typedef struct stc_crg_ttc_psr_field
{
  volatile  uint8_t TTC        : 1;
} stc_crg_ttc_psr_field_t;

typedef struct stc_crg_csw_tmr_field
{
  volatile  uint8_t MOWT0      : 1;
  volatile  uint8_t MOWT1      : 1;
  volatile  uint8_t MOWT2      : 1;
  volatile  uint8_t MOWT3      : 1;
  volatile  uint8_t SOWT0      : 1;
  volatile  uint8_t SOWT1      : 1;
  volatile  uint8_t SOWT2      : 1;
} stc_crg_csw_tmr_field_t;

typedef struct stc_crg_psw_tmr_field
{
  volatile  uint8_t POWT0      : 1;
  volatile  uint8_t POWT1      : 1;
  volatile  uint8_t POWT2      : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t PINC       : 1;
} stc_crg_psw_tmr_field_t;

typedef struct stc_crg_pll_ctl1_field
{
  volatile  uint8_t PLLM0      : 1;
  volatile  uint8_t PLLM1      : 1;
  volatile  uint8_t PLLM2      : 1;
  volatile  uint8_t PLLM3      : 1;
  volatile  uint8_t PLLK0      : 1;
  volatile  uint8_t PLLK1      : 1;
  volatile  uint8_t PLLK2      : 1;
  volatile  uint8_t PLLK3      : 1;
} stc_crg_pll_ctl1_field_t;

typedef struct stc_crg_pll_ctl2_field
{
  volatile  uint8_t PLLN0      : 1;
  volatile  uint8_t PLLN1      : 1;
  volatile  uint8_t PLLN2      : 1;
  volatile  uint8_t PLLN3      : 1;
  volatile  uint8_t PLLN4      : 1;
} stc_crg_pll_ctl2_field_t;

typedef struct stc_crg_csv_ctl_field
{
  volatile uint16_t MCSVE      : 1;
  volatile uint16_t SCSVE      : 1;
       uint16_t RESERVED1  : 6;
  volatile uint16_t FCSDE      : 1;
  volatile uint16_t FCSRE      : 1;
       uint16_t RESERVED2  : 2;
  volatile uint16_t FCD0       : 1;
  volatile uint16_t FCD1       : 1;
  volatile uint16_t FCD2       : 1;
} stc_crg_csv_ctl_field_t;

typedef struct stc_crg_csv_str_field
{
  volatile  uint8_t MCMF       : 1;
  volatile  uint8_t SCMF       : 1;
} stc_crg_csv_str_field_t;

typedef struct stc_crg_dbwdt_ctl_field
{
        uint8_t RESERVED1  : 5;
  volatile  uint8_t DPSWBE     : 1;
        uint8_t RESERVED2  : 1;
  volatile  uint8_t DPHWBE     : 1;
} stc_crg_dbwdt_ctl_field_t;

typedef struct stc_crg_int_enr_field
{
  volatile  uint8_t MCSE       : 1;
  volatile  uint8_t SCSE       : 1;
  volatile  uint8_t PCSE       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t FCSE       : 1;
} stc_crg_int_enr_field_t;

typedef struct stc_crg_int_str_field
{
  volatile  uint8_t MCSI       : 1;
  volatile  uint8_t SCSI       : 1;
  volatile  uint8_t PCSI       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t FCSI       : 1;
} stc_crg_int_str_field_t;

typedef struct stc_crg_int_clr_field
{
  volatile  uint8_t MCSC       : 1;
  volatile  uint8_t SCSC       : 1;
  volatile  uint8_t PCSC       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t FCSC       : 1;
} stc_crg_int_clr_field_t;



 
 
typedef struct stc_hwwdt_wdg_ctl_field
{
  volatile  uint8_t INTEN      : 1;
  volatile  uint8_t RESEN      : 1;
} stc_hwwdt_wdg_ctl_field_t;

typedef struct stc_hwwdt_wdg_ris_field
{
  volatile  uint8_t RIS        : 1;
} stc_hwwdt_wdg_ris_field_t;



 
 
typedef struct stc_swwdt_wdogcontrol_field
{
  union {
    struct {
      volatile  uint8_t INTEN      : 1;
      volatile  uint8_t RESEN      : 1;
      volatile  uint8_t TWD        : 2;
      volatile  uint8_t SPM        : 1;
            uint8_t RESERVED1  : 3;
    };
    struct {
            uint8_t RESERVED2  : 2;
      volatile  uint8_t TWD0       : 1;
      volatile  uint8_t TWD1       : 1;
            uint8_t RESERVED3  : 4;
    };
  };
} stc_swwdt_wdogcontrol_field_t;

typedef struct stc_swwdt_wdogris_field
{
  volatile  uint8_t RIS        : 1;
        uint8_t RESERVED1  : 7;
} stc_swwdt_wdogris_field_t;

typedef struct stc_swwdt_wdogspmc_field
{
  volatile  uint8_t TGR        : 1;
        uint8_t RESERVED1  : 7;
} stc_swwdt_wdogspmc_field_t;



 
 
typedef struct stc_dtim_timerXcontrol_field
{
  union {
    struct {
      volatile uint32_t ONESHOT    : 1;
      volatile uint32_t TIMERSIZE  : 1;
      volatile uint32_t TIMERPRE   : 2;
           uint32_t RESERVED1  : 1;
      volatile uint32_t INTENABLE  : 1;
      volatile uint32_t TIMERMODE  : 1;
      volatile uint32_t TIMEREN    : 1;
           uint32_t RESERVED2  : 24;
    };
    struct {
           uint32_t RESERVED3  : 2;
      volatile uint32_t TIMERPRE0  : 1;
      volatile uint32_t TIMERPRE1  : 1;
           uint32_t RESERVED4  : 28;
    };
  };
} stc_dtim_timerXcontrol_field_t;

typedef struct stc_dtim_timerXris_field
{
  volatile uint32_t TIMERXRIS  : 1;
       uint32_t RESERVED1  : 31;
} stc_dtim_timerXris_field_t;

typedef struct stc_dtim_timerXmis_field
{
  volatile uint32_t TIMERXMIS  : 1;
       uint32_t RESERVED1  : 31;
} stc_dtim_timerXmis_field_t;



 
 
typedef struct stc_mft_frt_tcsa0_field
{
  volatile uint16_t CLK0       : 1;
  volatile uint16_t CLK1       : 1;
  volatile uint16_t CLK2       : 1;
  volatile uint16_t CLK3       : 1;
  volatile uint16_t SCLR       : 1;
  volatile uint16_t MODE       : 1;
  volatile uint16_t STOP       : 1;
  volatile uint16_t BFE        : 1;
  volatile uint16_t ICRE       : 1;
  volatile uint16_t ICLR       : 1;
       uint16_t RESERVED1  : 3;
  volatile uint16_t IRQZE      : 1;
  volatile uint16_t IRQZF      : 1;
  volatile uint16_t ECKE       : 1;
} stc_mft_frt_tcsa0_field_t;

typedef struct stc_mft_frt_tcsc0_field
{
  volatile uint16_t MSZI       : 4;
  volatile uint16_t MSPI       : 4;
  volatile uint16_t MSZC       : 4;
  volatile uint16_t MSPC       : 4;
} stc_mft_frt_tcsc0_field_t;

typedef struct stc_mft_frt_tcsa1_field
{
  volatile uint16_t CLK0       : 1;
  volatile uint16_t CLK1       : 1;
  volatile uint16_t CLK2       : 1;
  volatile uint16_t CLK3       : 1;
  volatile uint16_t SCLR       : 1;
  volatile uint16_t MODE       : 1;
  volatile uint16_t STOP       : 1;
  volatile uint16_t BFE        : 1;
  volatile uint16_t ICRE       : 1;
  volatile uint16_t ICLR       : 1;
       uint16_t RESERVED1  : 3;
  volatile uint16_t IRQZE      : 1;
  volatile uint16_t IRQZF      : 1;
  volatile uint16_t ECKE       : 1;
} stc_mft_frt_tcsa1_field_t;

typedef struct stc_mft_frt_tcsc1_field
{
  volatile uint16_t MSZI       : 4;
  volatile uint16_t MSPI       : 4;
  volatile uint16_t MSZC       : 4;
  volatile uint16_t MSPC       : 4;
} stc_mft_frt_tcsc1_field_t;

typedef struct stc_mft_frt_tcsa2_field
{
  volatile uint16_t CLK0       : 1;
  volatile uint16_t CLK1       : 1;
  volatile uint16_t CLK2       : 1;
  volatile uint16_t CLK3       : 1;
  volatile uint16_t SCLR       : 1;
  volatile uint16_t MODE       : 1;
  volatile uint16_t STOP       : 1;
  volatile uint16_t BFE        : 1;
  volatile uint16_t ICRE       : 1;
  volatile uint16_t ICLR       : 1;
       uint16_t RESERVED1  : 3;
  volatile uint16_t IRQZE      : 1;
  volatile uint16_t IRQZF      : 1;
  volatile uint16_t ECKE       : 1;
} stc_mft_frt_tcsa2_field_t;

typedef struct stc_mft_frt_tcsc2_field
{
  volatile uint16_t MSZI       : 4;
  volatile uint16_t MSPI       : 4;
  volatile uint16_t MSZC       : 4;
  volatile uint16_t MSPC       : 4;
} stc_mft_frt_tcsc2_field_t;

typedef struct stc_mft_frt_tcal_field
{
  volatile uint32_t STOP00     : 1;
  volatile uint32_t STOP01     : 1;
  volatile uint32_t STOP02     : 1;
  volatile uint32_t STOP10     : 1;
  volatile uint32_t STOP11     : 1;
  volatile uint32_t STOP12     : 1;
  volatile uint32_t STOP20     : 1;
  volatile uint32_t STOP21     : 1;
  volatile uint32_t STOP22     : 1;
  volatile uint32_t RESERVED1  : 7;
  volatile uint32_t SCLR00     : 1;
  volatile uint32_t SCLR01     : 1;
  volatile uint32_t SCLR02     : 1;
  volatile uint32_t SCLR10     : 1;
  volatile uint32_t SCLR11     : 1;
  volatile uint32_t SCLR12     : 1;
  volatile uint32_t SCLR20     : 1;
  volatile uint32_t SCLR21     : 1;
  volatile uint32_t SCLR22     : 1;
  volatile uint32_t RESERVED2  : 7;
} stc_mft_frt_tcal_field_t;



 
 
typedef struct stc_mft_ocu_ocsa10_field
{
  volatile  uint8_t CST0       : 1;
  volatile  uint8_t CST1       : 1;
  volatile  uint8_t RESERVED1  : 2;
  volatile  uint8_t IOE0       : 1;
  volatile  uint8_t IOE1       : 1;
  volatile  uint8_t IOP0       : 1;
  volatile  uint8_t IOP1       : 1;
} stc_mft_ocu_ocsa10_field_t;

typedef struct stc_mft_ocu_ocsb10_field
{
  volatile  uint8_t OTD0       : 1;
  volatile  uint8_t OTD1       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t CMOD       : 1;
        uint8_t RESERVED2  : 2;
  volatile  uint8_t FM4        : 1;
} stc_mft_ocu_ocsb10_field_t;

typedef struct stc_mft_ocu_ocsa32_field
{
  volatile  uint8_t CST0       : 1;
  volatile  uint8_t CST1       : 1;
  volatile  uint8_t RESERVED1  : 2;
  volatile  uint8_t IOE0       : 1;
  volatile  uint8_t IOE1       : 1;
  volatile  uint8_t IOP0       : 1;
  volatile  uint8_t IOP1       : 1;
} stc_mft_ocu_ocsa32_field_t;

typedef struct stc_mft_ocu_ocsb32_field
{
  volatile  uint8_t OTD0       : 1;
  volatile  uint8_t OTD1       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t CMOD       : 1;
        uint8_t RESERVED2  : 2;
  volatile  uint8_t FM4        : 1;
} stc_mft_ocu_ocsb32_field_t;

typedef struct stc_mft_ocu_ocsa54_field
{
  volatile  uint8_t CST0       : 1;
  volatile  uint8_t CST1       : 1;
  volatile  uint8_t RESERVED1  : 2;
  volatile  uint8_t IOE0       : 1;
  volatile  uint8_t IOE1       : 1;
  volatile  uint8_t IOP0       : 1;
  volatile  uint8_t IOP1       : 1;
} stc_mft_ocu_ocsa54_field_t;

typedef struct stc_mft_ocu_ocsb54_field
{
  volatile  uint8_t OTD0       : 1;
  volatile  uint8_t OTD1       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t CMOD       : 1;
        uint8_t RESERVED2  : 2;
  volatile  uint8_t FM4        : 1;
} stc_mft_ocu_ocsb54_field_t;

typedef struct stc_mft_ocu_ocsc_field
{
  volatile  uint8_t MOD0       : 1;
  volatile  uint8_t MOD1       : 1;
  volatile  uint8_t MOD2       : 1;
  volatile  uint8_t MOD3       : 1;
  volatile  uint8_t MOD4       : 1;
  volatile  uint8_t MOD5       : 1;
} stc_mft_ocu_ocsc_field_t;

typedef struct stc_mft_ocu_ocfs10_field
{
  volatile  uint8_t FSO00      : 1;
  volatile  uint8_t FSO01      : 1;
  volatile  uint8_t FSO02      : 1;
  volatile  uint8_t FSO03      : 1;
  volatile  uint8_t FSO10      : 1;
  volatile  uint8_t FSO11      : 1;
  volatile  uint8_t FSO12      : 1;
  volatile  uint8_t FSO13      : 1;
} stc_mft_ocu_ocfs10_field_t;

typedef struct stc_mft_ocu_ocfs32_field
{
  volatile  uint8_t FSO00      : 1;
  volatile  uint8_t FSO01      : 1;
  volatile  uint8_t FSO02      : 1;
  volatile  uint8_t FSO03      : 1;
  volatile  uint8_t FSO10      : 1;
  volatile  uint8_t FSO11      : 1;
  volatile  uint8_t FSO12      : 1;
  volatile  uint8_t FSO13      : 1;
} stc_mft_ocu_ocfs32_field_t;

typedef struct stc_mft_ocu_ocfs54_field
{
  volatile  uint8_t FSO00      : 1;
  volatile  uint8_t FSO01      : 1;
  volatile  uint8_t FSO02      : 1;
  volatile  uint8_t FSO03      : 1;
  volatile  uint8_t FSO10      : 1;
  volatile  uint8_t FSO11      : 1;
  volatile  uint8_t FSO12      : 1;
  volatile  uint8_t FSO13      : 1;
} stc_mft_ocu_ocfs54_field_t;

typedef struct stc_mft_ocu_ocsd10_field
{
  volatile  uint8_t OCCP0BUFE  : 2;
  volatile  uint8_t OCCP1BUFE  : 2;
  volatile  uint8_t OCSE0BUFE  : 2;
  volatile  uint8_t OCSE1BUFE  : 2;
} stc_mft_ocu_ocsd10_field_t;

typedef struct stc_mft_ocu_ocsd32_field
{
  volatile  uint8_t OCCP2BUFE  : 2;
  volatile  uint8_t OCCP3BUFE  : 2;
  volatile  uint8_t OCSE2BUFE  : 2;
  volatile  uint8_t OCSE3BUFE  : 2;
} stc_mft_ocu_ocsd32_field_t;

typedef struct stc_mft_ocu_ocsd54_field
{
  volatile  uint8_t OCCP4BUFE  : 2;
  volatile  uint8_t OCCP5BUFE  : 2;
  volatile  uint8_t OCSE4BUFE  : 2;
  volatile  uint8_t OCSE5BUFE  : 2;
} stc_mft_ocu_ocsd54_field_t;

typedef struct stc_mft_ocu_ocse0_field
{
  volatile  uint16_t OCSE      : 16;
} stc_mft_ocu_ocse0_field_t;

typedef struct stc_mft_ocu_ocse1_field
{
  volatile  uint32_t OCSE      : 32;
} stc_mft_ocu_ocse1_field_t;

typedef struct stc_mft_ocu_ocse2_field
{
  volatile  uint16_t OCSE      : 16;
} stc_mft_ocu_ocse2_field_t;

typedef struct stc_mft_ocu_ocse3_field
{
  volatile  uint32_t OCSE      : 32;
} stc_mft_ocu_ocse3_field_t;

typedef struct stc_mft_ocu_ocse4_field
{
  volatile  uint16_t OCSE      : 16;
} stc_mft_ocu_ocse4_field_t;

typedef struct stc_mft_ocu_ocse5_field
{
  volatile  uint32_t OCSE      : 32;
} stc_mft_ocu_ocse5_field_t;



 
 
typedef struct stc_mft_wfg_wfsa10_field
{
  volatile uint16_t DCK0       : 1;
  volatile uint16_t DCK1       : 1;
  volatile uint16_t DCK2       : 1;
  volatile uint16_t TMD        : 3;
  volatile uint16_t GTEN0      : 1;
  volatile uint16_t GTEN1      : 1;
  volatile uint16_t PSEL0      : 1;
  volatile uint16_t PSEL1      : 1;
  volatile uint16_t PGEN0      : 1;
  volatile uint16_t PGEN1      : 1;
  volatile uint16_t DMOD       : 2;
} stc_mft_wfg_wfsa10_field_t;

typedef struct stc_mft_wfg_wfsa32_field
{
  volatile uint16_t DCK0       : 1;
  volatile uint16_t DCK1       : 1;
  volatile uint16_t DCK2       : 1;
  volatile uint16_t TMD        : 3;
  volatile uint16_t GTEN0      : 1;
  volatile uint16_t GTEN1      : 1;
  volatile uint16_t PSEL0      : 1;
  volatile uint16_t PSEL1      : 1;
  volatile uint16_t PGEN0      : 1;
  volatile uint16_t PGEN1      : 1;
  volatile uint16_t DMOD       : 2;
} stc_mft_wfg_wfsa32_field_t;

typedef struct stc_mft_wfg_wfsa54_field
{
  volatile uint16_t DCK0       : 1;
  volatile uint16_t DCK1       : 1;
  volatile uint16_t DCK2       : 1;
  volatile uint16_t TMD        : 3;
  volatile uint16_t GTEN0      : 1;
  volatile uint16_t GTEN1      : 1;
  volatile uint16_t PSEL0      : 1;
  volatile uint16_t PSEL1      : 1;
  volatile uint16_t PGEN0      : 1;
  volatile uint16_t PGEN1      : 1;
  volatile uint16_t DMOD       : 2;
} stc_mft_wfg_wfsa54_field_t;

typedef struct stc_mft_wfg_wfir_field
{
  volatile uint16_t DTIFA      : 1;
  volatile uint16_t DTICA      : 1;
  volatile uint16_t DTIFB      : 1;
  volatile uint16_t DTICB      : 1;
  volatile uint16_t TMIF10     : 1;
  volatile uint16_t TMIC10     : 1;
  volatile uint16_t TMIE10     : 1;
  volatile uint16_t TMIS10     : 1;
  volatile uint16_t TMIF32     : 1;
  volatile uint16_t TMIC32     : 1;
  volatile uint16_t TMIE32     : 1;
  volatile uint16_t TMIS32     : 1;
  volatile uint16_t TMIF54     : 1;
  volatile uint16_t TMIC54     : 1;
  volatile uint16_t TMIE54     : 1;
  volatile uint16_t TMIS54     : 1;
} stc_mft_wfg_wfir_field_t;

typedef struct stc_mft_wfg_nzcl_field
{
  volatile uint16_t DTIEA      : 1;
  volatile uint16_t NWS0       : 1;
  volatile uint16_t NWS1       : 1;
  volatile uint16_t NWS2       : 1;
  volatile uint16_t SDTI       : 1;
  volatile uint16_t DTIEB      : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t DIMA       : 1;
  volatile uint16_t DIMB       : 1;
       uint16_t RESERVED2  : 2;
  volatile uint16_t WIM10      : 1;
  volatile uint16_t WIM32      : 1;
  volatile uint16_t WIM54      : 1;
       uint16_t RESERVED3  : 1;
} stc_mft_wfg_nzcl_field_t;



 
 
typedef struct stc_mft_icu_icfs10_field
{
  volatile  uint8_t FSI00      : 1;
  volatile  uint8_t FSI01      : 1;
  volatile  uint8_t FSI02      : 1;
  volatile  uint8_t FSI03      : 1;
  volatile  uint8_t FSI10      : 1;
  volatile  uint8_t FSI11      : 1;
  volatile  uint8_t FSI12      : 1;
  volatile  uint8_t FSI13      : 1;
} stc_mft_icu_icfs10_field_t;

typedef struct stc_mft_icu_icfs32_field
{
  volatile  uint8_t FSI00      : 1;
  volatile  uint8_t FSI01      : 1;
  volatile  uint8_t FSI02      : 1;
  volatile  uint8_t FSI03      : 1;
  volatile  uint8_t FSI10      : 1;
  volatile  uint8_t FSI11      : 1;
  volatile  uint8_t FSI12      : 1;
  volatile  uint8_t FSI13      : 1;
} stc_mft_icu_icfs32_field_t;

typedef struct stc_mft_icu_icsa10_field
{
  volatile  uint8_t EG00       : 1;
  volatile  uint8_t EG01       : 1;
  volatile  uint8_t EG10       : 1;
  volatile  uint8_t EG11       : 1;
  volatile  uint8_t ICE0       : 1;
  volatile  uint8_t ICE1       : 1;
  volatile  uint8_t ICP0       : 1;
  volatile  uint8_t ICP1       : 1;
} stc_mft_icu_icsa10_field_t;

typedef struct stc_mft_icu_icsb10_field
{
  volatile  uint8_t IEI0       : 1;
  volatile  uint8_t IEI1       : 1;
} stc_mft_icu_icsb10_field_t;

typedef struct stc_mft_icu_icsa32_field
{
  volatile  uint8_t EG00       : 1;
  volatile  uint8_t EG01       : 1;
  volatile  uint8_t EG10       : 1;
  volatile  uint8_t EG11       : 1;
  volatile  uint8_t ICE0       : 1;
  volatile  uint8_t ICE1       : 1;
  volatile  uint8_t ICP0       : 1;
  volatile  uint8_t ICP1       : 1;
} stc_mft_icu_icsa32_field_t;

typedef struct stc_mft_icu_icsb32_field
{
  volatile  uint8_t IEI0       : 1;
  volatile  uint8_t IEI1       : 1;
} stc_mft_icu_icsb32_field_t;



 
 
typedef struct stc_mft_adcmp_acfs10_field
{
  volatile  uint8_t FSA0       : 4;
  volatile  uint8_t FSA1       : 4;
} stc_mft_adcmp_acfs10_field_t;

typedef struct stc_mft_adcmp_acfs32_field
{
  volatile  uint8_t FSA2       : 4;
  volatile  uint8_t FSA3       : 4;
} stc_mft_adcmp_acfs32_field_t;

typedef struct stc_mft_adcmp_acfs54_field
{
  volatile  uint8_t FSA4       : 4;
  volatile  uint8_t FSA5       : 4;
} stc_mft_adcmp_acfs54_field_t;

typedef struct stc_mft_adcmp_acsa_field
{
  volatile uint16_t CE10       : 2;
  volatile uint16_t CE32       : 2;
  volatile uint16_t CE54       : 2;
       uint16_t RESERVED1  : 2;
  volatile uint16_t SEL10      : 2;
  volatile uint16_t SEL32      : 2;
  volatile uint16_t SEL54      : 2;
} stc_mft_adcmp_acsa_field_t;

typedef struct stc_mft_adcmp_acsc_field
{
  volatile uint8_t BUFE        : 2;
  volatile uint8_t ADSEL       : 3;
       uint8_t RESERVED1   : 3;
} stc_mft_adcmp_acsc_field_t;

typedef struct stc_mft_adcmp_acsd_field
{
  volatile uint8_t AMOD        : 1;
  volatile uint8_t OCUS        : 1;
       uint8_t RESERVED1   : 2;
  volatile uint8_t DE          : 1;
  volatile uint8_t PE          : 1;
  volatile uint8_t UE          : 1;
  volatile uint8_t ZE          : 1;
} stc_mft_adcmp_acsd_field_t;



 
typedef struct stc_dadr_field
{
  volatile  uint16_t DA         : 12;
  volatile  uint16_t RESERVED   : 4;
} stc_dadr_field_t;

typedef struct stc_dacr_field
{
  volatile  uint8_t DAE        : 1;
  volatile  uint8_t DRDY       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t DAC10      : 1;
  volatile  uint8_t DDAS       : 1;
  volatile  uint8_t RESERVED2  : 2;
} stc_dacr_field_t;




 
 
typedef struct stc_mft_ppg_ttcr0_field
{
  volatile  uint8_t STR0       : 1;
  volatile  uint8_t MONI0      : 1;
  volatile  uint8_t CS00       : 1;
  volatile  uint8_t CS01       : 1;
  volatile  uint8_t TRG0O      : 1;
  volatile  uint8_t TRG2O      : 1;
  volatile  uint8_t TRG4O      : 1;
  volatile  uint8_t TRG6O      : 1;
} stc_mft_ppg_ttcr0_field_t;

typedef struct stc_mft_ppg_ttcr1_field
{
  volatile  uint8_t STR1       : 1;
  volatile  uint8_t MONI1      : 1;
  volatile  uint8_t CS10       : 1;
  volatile  uint8_t CS11       : 1;
  volatile  uint8_t TRG1O      : 1;
  volatile  uint8_t TRG3O      : 1;
  volatile  uint8_t TRG5O      : 1;
  volatile  uint8_t TRG7O      : 1;
} stc_mft_ppg_ttcr1_field_t;

typedef struct stc_mft_ppg_ttcr2_field
{
  volatile  uint8_t STR2       : 1;
  volatile  uint8_t MONI2      : 1;
  volatile  uint8_t CS20       : 1;
  volatile  uint8_t CS21       : 1;
  volatile  uint8_t TRG16O     : 1;
  volatile  uint8_t TRG18O     : 1;
  volatile  uint8_t TRG20O     : 1;
  volatile  uint8_t TRG22O     : 1;
} stc_mft_ppg_ttcr2_field_t;

typedef struct stc_mft_ppg_trg_field
{
  volatile uint16_t PEN00      : 1;
  volatile uint16_t PEN01      : 1;
  volatile uint16_t PEN02      : 1;
  volatile uint16_t PEN03      : 1;
  volatile uint16_t PEN04      : 1;
  volatile uint16_t PEN05      : 1;
  volatile uint16_t PEN06      : 1;
  volatile uint16_t PEN07      : 1;
  volatile uint16_t PEN08      : 1;
  volatile uint16_t PEN09      : 1;
  volatile uint16_t PEN10      : 1;
  volatile uint16_t PEN11      : 1;
  volatile uint16_t PEN12      : 1;
  volatile uint16_t PEN13      : 1;
  volatile uint16_t PEN14      : 1;
  volatile uint16_t PEN15      : 1;
} stc_mft_ppg_trg0_field_t;

typedef struct stc_mft_ppg_trg1_field
{
  volatile uint16_t PEN16      : 1;
  volatile uint16_t PEN17      : 1;
  volatile uint16_t PEN18      : 1;
  volatile uint16_t PEN19      : 1;
  volatile uint16_t PEN20      : 1;
  volatile uint16_t PEN21      : 1;
  volatile uint16_t PEN22      : 1;
  volatile uint16_t PEN23      : 1;
} stc_mft_ppg_trg1_field_t;

typedef struct stc_mft_ppg_revc_field
{
  volatile uint16_t REV00      : 1;
  volatile uint16_t REV01      : 1;
  volatile uint16_t REV02      : 1;
  volatile uint16_t REV03      : 1;
  volatile uint16_t REV04      : 1;
  volatile uint16_t REV05      : 1;
  volatile uint16_t REV06      : 1;
  volatile uint16_t REV07      : 1;
  volatile uint16_t REV08      : 1;
  volatile uint16_t REV09      : 1;
  volatile uint16_t REV10      : 1;
  volatile uint16_t REV11      : 1;
  volatile uint16_t REV12      : 1;
  volatile uint16_t REV13      : 1;
  volatile uint16_t REV14      : 1;
  volatile uint16_t REV15      : 1;
} stc_mft_ppg_revc0_field_t;

typedef struct stc_mft_ppg_revc1_field
{
  volatile uint16_t REV16      : 1;
  volatile uint16_t REV17      : 1;
  volatile uint16_t REV18      : 1;
  volatile uint16_t REV19      : 1;
  volatile uint16_t REV20      : 1;
  volatile uint16_t REV21      : 1;
  volatile uint16_t REV22      : 1;
  volatile uint16_t REV23      : 1;
} stc_mft_ppg_revc1_field_t;

typedef struct stc_mft_ppg_ppgc1_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc1_field_t;

typedef struct stc_mft_ppg_ppgc0_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc0_field_t;

typedef struct stc_mft_ppg_ppgc3_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc3_field_t;

typedef struct stc_mft_ppg_ppgc2_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc2_field_t;

typedef struct stc_mft_ppg_gatec0_field
{
  volatile  uint8_t EDGE0      : 1;
  volatile  uint8_t STRG0      : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t EDGE2      : 1;
  volatile  uint8_t STRG2      : 1;
} stc_mft_ppg_gatec0_field_t;

typedef struct stc_mft_ppg_ppgc5_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc5_field_t;

typedef struct stc_mft_ppg_ppgc4_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc4_field_t;

typedef struct stc_mft_ppg_ppgc7_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc7_field_t;

typedef struct stc_mft_ppg_ppgc6_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc6_field_t;

typedef struct stc_mft_ppg_gatec4_field
{
  volatile  uint8_t EDGE4      : 1;
  volatile  uint8_t STRG4      : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t EDGE6      : 1;
  volatile  uint8_t STRG6      : 1;
} stc_mft_ppg_gatec4_field_t;

typedef struct stc_mft_ppg_ppgc9_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc9_field_t;

typedef struct stc_mft_ppg_ppgc8_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc8_field_t;

typedef struct stc_mft_ppg_ppgc11_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc11_field_t;

typedef struct stc_mft_ppg_ppgc10_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc10_field_t;

typedef struct stc_mft_ppg_gatec8_field
{
  volatile  uint8_t EDGE8      : 1;
  volatile  uint8_t STRG8      : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t EDGE10     : 1;
  volatile  uint8_t STRG10     : 1;
} stc_mft_ppg_gatec8_field_t;

typedef struct stc_mft_ppg_ppgc13_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc13_field_t;

typedef struct stc_mft_ppg_ppgc12_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc12_field_t;

typedef struct stc_mft_ppg_ppgc15_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc15_field_t;

typedef struct stc_mft_ppg_ppgc14_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc14_field_t;

typedef struct stc_mft_ppg_gatec12_field
{
  volatile  uint8_t EDGE12     : 1;
  volatile  uint8_t STRG12     : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t EDGE14     : 1;
  volatile  uint8_t STRG14     : 1;
} stc_mft_ppg_gatec12_field_t;

typedef struct stc_mft_ppg_ppgc17_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc17_field_t;

typedef struct stc_mft_ppg_ppgc16_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc16_field_t;

typedef struct stc_mft_ppg_ppgc19_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc19_field_t;

typedef struct stc_mft_ppg_ppgc18_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc18_field_t;

typedef struct stc_mft_ppg_gatec16_field
{
  volatile  uint8_t EDGE16     : 1;
  volatile  uint8_t STRG16     : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t EDGE18     : 1;
  volatile  uint8_t STRG18     : 1;
} stc_mft_ppg_gatec16_field_t;

typedef struct stc_mft_ppg_ppgc21_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc21_field_t;

typedef struct stc_mft_ppg_ppgc20_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc20_field_t;

typedef struct stc_mft_ppg_ppgc23_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc23_field_t;

typedef struct stc_mft_ppg_ppgc22_field
{
  volatile  uint8_t TTRG       : 1;
  volatile  uint8_t MD         : 2;
  volatile  uint8_t PCS0       : 1;
  volatile  uint8_t PCS1       : 1;
  volatile  uint8_t INTM       : 1;
  volatile  uint8_t PUF        : 1;
  volatile  uint8_t PIE        : 1;
} stc_mft_ppg_ppgc22_field_t;

typedef struct stc_mft_ppg_gatec20_field
{
  volatile  uint8_t EDGE20     : 1;
  volatile  uint8_t STRG20     : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t EDGE22     : 1;
  volatile  uint8_t STRG22     : 1;
} stc_mft_ppg_gatec20_field_t;



 
 
typedef struct stc_bt_ppg_tmcr_field
{
  volatile uint16_t STRG       : 1;
  volatile uint16_t CTEN       : 1;
  volatile uint16_t MDSE       : 1;
  volatile uint16_t OSEL       : 1;
  volatile uint16_t FMD0       : 1;
  volatile uint16_t FMD1       : 1;
  volatile uint16_t FMD2       : 1;
       uint16_t RESERVED1  : 1;
  volatile uint16_t EGS0       : 1;
  volatile uint16_t EGS1       : 1;
  volatile uint16_t PMSK       : 1;
  volatile uint16_t RTGEN      : 1;
  volatile uint16_t CKS0       : 1;
  volatile uint16_t CKS1       : 1;
  volatile uint16_t CKS2       : 1;
} stc_bt_ppg_tmcr_field_t;

typedef struct stc_bt_ppg_stc_field
{
  volatile  uint8_t UDIR       : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t TGIR       : 1;
        uint8_t RESERVED2  : 1;
  volatile  uint8_t UDIE       : 1;
        uint8_t RESERVED3  : 1;
  volatile  uint8_t TGIE       : 1;
} stc_bt_ppg_stc_field_t;

typedef struct stc_bt_ppg_tmcr2_field
{
  volatile  uint8_t CKS3       : 1;
} stc_bt_ppg_tmcr2_field_t;



 
 
typedef struct stc_bt_pwm_tmcr_field
{
  volatile uint16_t STRG       : 1;
  volatile uint16_t CTEN       : 1;
  volatile uint16_t MDSE       : 1;
  volatile uint16_t OSEL       : 1;
  volatile uint16_t FMD0       : 1;
  volatile uint16_t FMD1       : 1;
  volatile uint16_t FMD2       : 1;
       uint16_t RESERVED1  : 1;
  volatile uint16_t EGS0       : 1;
  volatile uint16_t EGS1       : 1;
  volatile uint16_t PMSK       : 1;
  volatile uint16_t RTGEN      : 1;
  volatile uint16_t CKS0       : 1;
  volatile uint16_t CKS1       : 1;
  volatile uint16_t CKS2       : 1;
} stc_bt_pwm_tmcr_field_t;

typedef struct stc_bt_pwm_stc_field
{
  volatile  uint8_t UDIR       : 1;
  volatile  uint8_t DTIR       : 1;
  volatile  uint8_t TGIR       : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t UDIE       : 1;
  volatile  uint8_t DTIE       : 1;
  volatile  uint8_t TGIE       : 1;
} stc_bt_pwm_stc_field_t;

typedef struct stc_bt_pwm_tmcr2_field
{
  volatile  uint8_t CKS3       : 1;
} stc_bt_pwm_tmcr2_field_t;



 
 
typedef struct stc_bt_rt_tmcr_field
{
  volatile uint16_t STRG       : 1;
  volatile uint16_t CTEN       : 1;
  volatile uint16_t MDSE       : 1;
  volatile uint16_t OSEL       : 1;
  volatile uint16_t FMD0       : 1;
  volatile uint16_t FMD1       : 1;
  volatile uint16_t FMD2       : 1;
  volatile uint16_t T32        : 1;
  volatile uint16_t EGS0       : 1;
  volatile uint16_t EGS1       : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t CKS0       : 1;
  volatile uint16_t CKS1       : 1;
  volatile uint16_t CKS2       : 1;
} stc_bt_rt_tmcr_field_t;

typedef struct stc_bt_rt_stc_field
{
  volatile  uint8_t UDIR       : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t TGIR       : 1;
        uint8_t RESERVED2  : 1;
  volatile  uint8_t UDIE       : 1;
        uint8_t RESERVED3  : 1;
  volatile  uint8_t TGIE       : 1;
} stc_bt_rt_stc_field_t;

typedef struct stc_bt_rt_tmcr2_field
{
  volatile  uint8_t CKS3       : 1;
  volatile  uint8_t RESERVED1  : 6;
  volatile  uint8_t GATE       : 1; 
} stc_bt_rt_tmcr2_field_t;



 
 
typedef struct stc_bt_pwc_tmcr_field
{
       uint16_t RESERVED1  : 1;
  volatile uint16_t CTEN       : 1;
  volatile uint16_t MDSE       : 1;
       uint16_t RESERVED2  : 1;
  volatile uint16_t FMD0       : 1;
  volatile uint16_t FMD1       : 1;
  volatile uint16_t FMD2       : 1;
  volatile uint16_t T32        : 1;
  volatile uint16_t EGS0       : 1;
  volatile uint16_t EGS1       : 1;
  volatile uint16_t EGS2       : 1;
       uint16_t RESERVED3  : 1;
  volatile uint16_t CKS0       : 1;
  volatile uint16_t CKS1       : 1;
  volatile uint16_t CKS2       : 1;
} stc_bt_pwc_tmcr_field_t;

typedef struct stc_bt_pwc_stc_field
{
  volatile  uint8_t OVIR       : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t EDIR       : 1;
        uint8_t RESERVED2  : 1;
  volatile  uint8_t OVIE       : 1;
        uint8_t RESERVED3  : 1;
  volatile  uint8_t EDIE       : 1;
  volatile  uint8_t ERR        : 1;
} stc_bt_pwc_stc_field_t;

typedef struct stc_bt_pwc_tmcr2_field
{
  volatile  uint8_t CKS3       : 1;
} stc_bt_pwc_tmcr2_field_t;



 
 
typedef struct stc_btiosel03_btsel0123_field
{
  volatile  uint8_t SEL01_0    : 1;
  volatile  uint8_t SEL01_1    : 1;
  volatile  uint8_t SEL01_2    : 1;
  volatile  uint8_t SEL01_3    : 1;
  volatile  uint8_t SEL23_0    : 1;
  volatile  uint8_t SEL23_1    : 1;
  volatile  uint8_t SEL23_2    : 1;
  volatile  uint8_t SEL23_3    : 1;
} stc_btiosel03_btsel0123_field_t;



 
 
typedef struct stc_btiosel47_btsel4567_field
{
  volatile  uint8_t SEL45_0    : 1;
  volatile  uint8_t SEL45_1    : 1;
  volatile  uint8_t SEL45_2    : 1;
  volatile  uint8_t SEL45_3    : 1;
  volatile  uint8_t SEL67_0    : 1;
  volatile  uint8_t SEL67_1    : 1;
  volatile  uint8_t SEL67_2    : 1;
  volatile  uint8_t SEL67_3    : 1;
} stc_btiosel47_btsel4567_field_t;



 
 
typedef struct stc_btiosel8b_btsel89ab_field
{
  volatile  uint8_t SEL89_0    : 1;
  volatile  uint8_t SEL89_1    : 1;
  volatile  uint8_t SEL89_2    : 1;
  volatile  uint8_t SEL89_3    : 1;
  volatile  uint8_t SELAB_0    : 1;
  volatile  uint8_t SELAB_1    : 1;
  volatile  uint8_t SELAB_2    : 1;
  volatile  uint8_t SELAB_3    : 1;
} stc_btiosel8b_btsel89ab_field_t;



 
 
typedef struct stc_btioselcf_btselcdef_field
{
  volatile  uint8_t SELCD_0    : 1;
  volatile  uint8_t SELCD_1    : 1;
  volatile  uint8_t SELCD_2    : 1;
  volatile  uint8_t SELCD_3    : 1;
  volatile  uint8_t SELEF_0    : 1;
  volatile  uint8_t SELEF_1    : 1;
  volatile  uint8_t SELEF_2    : 1;
  volatile  uint8_t SELEF_3    : 1;
} stc_btioselcf_btselcdef_field_t;



 
 
typedef struct stc_sbssr_btsssr_field
{
  volatile uint16_t SSR0       : 1;
  volatile uint16_t SSR1       : 1;
  volatile uint16_t SSR2       : 1;
  volatile uint16_t SSR3       : 1;
  volatile uint16_t SSR4       : 1;
  volatile uint16_t SSR5       : 1;
  volatile uint16_t SSR6       : 1;
  volatile uint16_t SSR7       : 1;
  volatile uint16_t SSR8       : 1;
  volatile uint16_t SSR9       : 1;
  volatile uint16_t SSR10      : 1;
  volatile uint16_t SSR11      : 1;
  volatile uint16_t SSR12      : 1;
  volatile uint16_t SSR13      : 1;
  volatile uint16_t SSR14      : 1;
  volatile uint16_t SSR15      : 1;
} stc_sbssr_btsssr_field_t;



 
 
typedef struct stc_qprc_qicr_field
{
  volatile uint16_t QPCMIE     : 1;
  volatile uint16_t QPCMF      : 1;
  volatile uint16_t QPRCMIE    : 1;
  volatile uint16_t QPRCMF     : 1;
  volatile uint16_t OUZIE      : 1;
  volatile uint16_t UFDF       : 1;
  volatile uint16_t OFDF       : 1;
  volatile uint16_t ZIIF       : 1;
  volatile uint16_t CDCIE      : 1;
  volatile uint16_t CDCF       : 1;
  volatile uint16_t DIRPC      : 1;
  volatile uint16_t DIROU      : 1;
  volatile uint16_t QPCNRCMIE  : 1;
  volatile uint16_t QPCNRCMF   : 1;
} stc_qprc_qicr_field_t;

typedef struct stc_qprc_qicrl_field
{
  volatile  uint8_t QPCMIE     : 1;
  volatile  uint8_t QPCMF      : 1;
  volatile  uint8_t QPRCMIE    : 1;
  volatile  uint8_t QPRCMF     : 1;
  volatile  uint8_t OUZIE      : 1;
  volatile  uint8_t UFDF       : 1;
  volatile  uint8_t OFDF       : 1;
  volatile  uint8_t ZIIF       : 1;
} stc_qprc_qicrl_field_t;

typedef struct stc_qprc_qicrh_field
{
  volatile  uint8_t CDCIE      : 1;
  volatile  uint8_t CDCF       : 1;
  volatile  uint8_t DIRPC      : 1;
  volatile  uint8_t DIROU      : 1;
  volatile  uint8_t QPCNRCMIE  : 1;
  volatile  uint8_t QPCNRCMF   : 1;
} stc_qprc_qicrh_field_t;

typedef struct stc_qprc_qcr_field
{
  volatile uint16_t PCM0       : 1;
  volatile uint16_t PCM1       : 1;
  volatile uint16_t RCM0       : 1;
  volatile uint16_t RCM1       : 1;
  volatile uint16_t PSTP       : 1;
  volatile uint16_t CGSC       : 1;
  volatile uint16_t RSEL       : 1;
  volatile uint16_t SWAP       : 1;
  volatile uint16_t PCRM0      : 1;
  volatile uint16_t PCRM1      : 1;
  volatile uint16_t AES0       : 1;
  volatile uint16_t AES1       : 1;
  volatile uint16_t BES0       : 1;
  volatile uint16_t BES1       : 1;
  volatile uint16_t CGE0       : 1;
  volatile uint16_t CGE1       : 1;
} stc_qprc_qcr_field_t;

typedef struct stc_qprc_qcrl_field
{
  volatile  uint8_t PCM0       : 1;
  volatile  uint8_t PCM1       : 1;
  volatile  uint8_t RCM0       : 1;
  volatile  uint8_t RCM1       : 1;
  volatile  uint8_t PSTP       : 1;
  volatile  uint8_t CGSC       : 1;
  volatile  uint8_t RSEL       : 1;
  volatile  uint8_t SWAP       : 1;
} stc_qprc_qcrl_field_t;

typedef struct stc_qprc_qcrh_field
{
  volatile  uint8_t PCRM0      : 1;
  volatile  uint8_t PCRM1      : 1;
  volatile  uint8_t AES0       : 1;
  volatile  uint8_t AES1       : 1;
  volatile  uint8_t BES0       : 1;
  volatile  uint8_t BES1       : 1;
  volatile  uint8_t CGE0       : 1;
  volatile  uint8_t CGE1       : 1;
} stc_qprc_qcrh_field_t;

typedef struct stc_qprc_qecr_field
{
  volatile uint16_t ORNGMD     : 1;
  volatile uint16_t ORNGF      : 1;
  volatile uint16_t ORNGIE     : 1;
} stc_qprc_qecr_field_t;



 
 
typedef struct stc_qprc_nf_nfctla_field
{
  volatile uint8_t AINNWS     : 3;
       uint8_t RESERVED1  : 1;
  volatile uint8_t AINLV      : 1;
  volatile uint8_t AINMD      : 1;
} stc_qprc_nf_nfctla_field_t;

typedef struct stc_qprc_nf_nfctlb_field
{
  volatile uint8_t BINNWS     : 3;
       uint8_t RESERVED1  : 1;
  volatile uint8_t BINLV      : 1;
  volatile uint8_t BINMD      : 1;
} stc_qprc_nf_nfctlb_field_t;

typedef struct stc_qprc_nf_nfrctlz_field
{
  volatile uint8_t ZINNWS     : 3;
       uint8_t RESERVED1  : 1;
  volatile uint8_t ZINLV      : 1;
  volatile uint8_t ZINMD      : 1;
} stc_qprc_nf_nfrctlz_field_t;



 
 
typedef struct stc_adc_adsr_field
{
  volatile  uint8_t SCS        : 1;
  volatile  uint8_t PCS        : 1;
  volatile  uint8_t PCNS       : 1;
        uint8_t RESERVED1  : 3;
  volatile  uint8_t FDAS       : 1;
  volatile  uint8_t ADSTP      : 1;
} stc_adc_adsr_field_t;

typedef struct stc_adc_adcr_field
{
  volatile  uint8_t OVRIE      : 1;
  volatile  uint8_t CMPIE      : 1;
  volatile  uint8_t PCIE       : 1;
  volatile  uint8_t SCIE       : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t CMPIF      : 1;
  volatile  uint8_t PCIF       : 1;
  volatile  uint8_t SCIF       : 1;
} stc_adc_adcr_field_t;

typedef struct stc_adc_sfns_field
{
  volatile  uint8_t SFS0       : 1;
  volatile  uint8_t SFS1       : 1;
  volatile  uint8_t SFS2       : 1;
  volatile  uint8_t SFS3       : 1;
} stc_adc_sfns_field_t;

typedef struct stc_adc_sccr_field
{
  volatile  uint8_t SSTR       : 1;
  volatile  uint8_t SHEN       : 1;
  volatile  uint8_t RPT        : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t SFCLR      : 1;
  volatile  uint8_t SOVR       : 1;
  volatile  uint8_t SFUL       : 1;
  volatile  uint8_t SEMP       : 1;
} stc_adc_sccr_field_t;

typedef struct stc_adc_scfd_field
{
  volatile uint32_t SC0        : 1;
  volatile uint32_t SC1        : 1;
  volatile uint32_t SC2        : 1;
  volatile uint32_t SC3        : 1;
  volatile uint32_t SC4        : 1;
       uint32_t RESERVED1  : 3;
  volatile uint32_t RS0        : 1;
  volatile uint32_t RS1        : 1;
       uint32_t RESERVED2  : 2;
  volatile uint32_t INVL       : 1;
       uint32_t RESERVED3  : 7;
  volatile uint32_t SD0        : 1;
  volatile uint32_t SD1        : 1;
  volatile uint32_t SD2        : 1;
  volatile uint32_t SD3        : 1;
  volatile uint32_t SD4        : 1;
  volatile uint32_t SD5        : 1;
  volatile uint32_t SD6        : 1;
  volatile uint32_t SD7        : 1;
  volatile uint32_t SD8        : 1;
  volatile uint32_t SD9        : 1;
  volatile uint32_t SD10       : 1;
  volatile uint32_t SD11       : 1;
} stc_adc_scfd_field_t;

typedef struct stc_adc_scfdl_field
{
  volatile uint16_t SC0        : 1;
  volatile uint16_t SC1        : 1;
  volatile uint16_t SC2        : 1;
  volatile uint16_t SC3        : 1;
  volatile uint16_t SC4        : 1;
       uint16_t RESERVED1  : 3;
  volatile uint16_t RS0        : 1;
  volatile uint16_t RS1        : 1;
       uint16_t RESERVED2  : 2;
  volatile uint16_t INVL       : 1;
} stc_adc_scfdl_field_t;

typedef struct stc_adc_scfdh_field
{
       uint16_t RESERVED1  : 4;
  volatile uint16_t SD0        : 1;
  volatile uint16_t SD1        : 1;
  volatile uint16_t SD2        : 1;
  volatile uint16_t SD3        : 1;
  volatile uint16_t SD4        : 1;
  volatile uint16_t SD5        : 1;
  volatile uint16_t SD6        : 1;
  volatile uint16_t SD7        : 1;
  volatile uint16_t SD8        : 1;
  volatile uint16_t SD9        : 1;
  volatile uint16_t SD10       : 1;
  volatile uint16_t SD11       : 1;
} stc_adc_scfdh_field_t;

typedef struct stc_adc_scis23_field
{
  volatile uint16_t AN16       : 1;
  volatile uint16_t AN17       : 1;
  volatile uint16_t AN18       : 1;
  volatile uint16_t AN19       : 1;
  volatile uint16_t AN20       : 1;
  volatile uint16_t AN21       : 1;
  volatile uint16_t AN22       : 1;
  volatile uint16_t AN23       : 1;
  volatile uint16_t AN24       : 1;
  volatile uint16_t AN25       : 1;
  volatile uint16_t AN26       : 1;
  volatile uint16_t AN27       : 1;
  volatile uint16_t AN28       : 1;
  volatile uint16_t AN29       : 1;
  volatile uint16_t AN30       : 1;
  volatile uint16_t AN31       : 1;
} stc_adc_scis23_field_t;

typedef struct stc_adc_scis2_field
{
  volatile  uint8_t AN16       : 1;
  volatile  uint8_t AN17       : 1;
  volatile  uint8_t AN18       : 1;
  volatile  uint8_t AN19       : 1;
  volatile  uint8_t AN20       : 1;
  volatile  uint8_t AN21       : 1;
  volatile  uint8_t AN22       : 1;
  volatile  uint8_t AN23       : 1;
} stc_adc_scis2_field_t;

typedef struct stc_adc_scis3_field
{
  volatile  uint8_t AN24       : 1;
  volatile  uint8_t AN25       : 1;
  volatile  uint8_t AN26       : 1;
  volatile  uint8_t AN27       : 1;
  volatile  uint8_t AN28       : 1;
  volatile  uint8_t AN29       : 1;
  volatile  uint8_t AN30       : 1;
  volatile  uint8_t AN31       : 1;
} stc_adc_scis3_field_t;

typedef struct stc_adc_scis01_field
{
  volatile uint16_t AN0        : 1;
  volatile uint16_t AN1        : 1;
  volatile uint16_t AN2        : 1;
  volatile uint16_t AN3        : 1;
  volatile uint16_t AN4        : 1;
  volatile uint16_t AN5        : 1;
  volatile uint16_t AN6        : 1;
  volatile uint16_t AN7        : 1;
  volatile uint16_t AN8        : 1;
  volatile uint16_t AN9        : 1;
  volatile uint16_t AN10       : 1;
  volatile uint16_t AN11       : 1;
  volatile uint16_t AN12       : 1;
  volatile uint16_t AN13       : 1;
  volatile uint16_t AN14       : 1;
  volatile uint16_t AN15       : 1;
} stc_adc_scis01_field_t;

typedef struct stc_adc_scis0_field
{
  volatile  uint8_t AN0        : 1;
  volatile  uint8_t AN1        : 1;
  volatile  uint8_t AN2        : 1;
  volatile  uint8_t AN3        : 1;
  volatile  uint8_t AN4        : 1;
  volatile  uint8_t AN5        : 1;
  volatile  uint8_t AN6        : 1;
  volatile  uint8_t AN7        : 1;
} stc_adc_scis0_field_t;

typedef struct stc_adc_scis1_field
{
  volatile  uint8_t AN8        : 1;
  volatile  uint8_t AN9        : 1;
  volatile  uint8_t AN10       : 1;
  volatile  uint8_t AN11       : 1;
  volatile  uint8_t AN12       : 1;
  volatile  uint8_t AN13       : 1;
  volatile  uint8_t AN14       : 1;
  volatile  uint8_t AN15       : 1;
} stc_adc_scis1_field_t;

typedef struct stc_adc_pfns_field
{
  volatile  uint8_t PFS        : 2;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t TEST0      : 1;
  volatile  uint8_t TEST1      : 1;
} stc_adc_pfns_field_t;

typedef struct stc_adc_pccr_field
{
  volatile  uint8_t PSTR       : 1;
  volatile  uint8_t PHEN       : 1;
  volatile  uint8_t PEEN       : 1;
  volatile  uint8_t ESCE       : 1;
  volatile  uint8_t PFCLR      : 1;
  volatile  uint8_t POVR       : 1;
  volatile  uint8_t PFUL       : 1;
  volatile  uint8_t PEMP       : 1;
} stc_adc_pccr_field_t;

typedef struct stc_adc_pcfd_field
{
  volatile uint32_t PC0        : 1;
  volatile uint32_t PC1        : 1;
  volatile uint32_t PC2        : 1;
  volatile uint32_t PC3        : 1;
  volatile uint32_t PC4        : 1;
       uint32_t RESERVED1  : 3;
  volatile uint32_t RS0        : 1;
  volatile uint32_t RS1        : 1;
  volatile uint32_t RS2        : 1;
       uint32_t RESERVED2  : 1;
  volatile uint32_t INVL       : 1;
       uint32_t RESERVED3  : 7;
  volatile uint32_t PD0        : 1;
  volatile uint32_t PD1        : 1;
  volatile uint32_t PD2        : 1;
  volatile uint32_t PD3        : 1;
  volatile uint32_t PD4        : 1;
  volatile uint32_t PD5        : 1;
  volatile uint32_t PD6        : 1;
  volatile uint32_t PD7        : 1;
  volatile uint32_t PD8        : 1;
  volatile uint32_t PD9        : 1;
  volatile uint32_t PD10       : 1;
  volatile uint32_t PD11       : 1;
} stc_adc_pcfd_field_t;

typedef struct stc_adc_pcfdl_field
{
  volatile uint16_t PC0        : 1;
  volatile uint16_t PC1        : 1;
  volatile uint16_t PC2        : 1;
  volatile uint16_t PC3        : 1;
  volatile uint16_t PC4        : 1;
       uint16_t RESERVED1  : 3;
  volatile uint16_t RS0        : 1;
  volatile uint16_t RS1        : 1;
  volatile uint16_t RS2        : 1;
       uint16_t RESERVED2  : 1;
  volatile uint16_t INVL       : 1;
} stc_adc_pcfdl_field_t;

typedef struct stc_adc_pcfdh_field
{
       uint16_t RESERVED1  : 4;
  volatile uint16_t PD0        : 1;
  volatile uint16_t PD1        : 1;
  volatile uint16_t PD2        : 1;
  volatile uint16_t PD3        : 1;
  volatile uint16_t PD4        : 1;
  volatile uint16_t PD5        : 1;
  volatile uint16_t PD6        : 1;
  volatile uint16_t PD7        : 1;
  volatile uint16_t PD8        : 1;
  volatile uint16_t PD9        : 1;
  volatile uint16_t PD10       : 1;
  volatile uint16_t PD11       : 1;
} stc_adc_pcfdh_field_t;

typedef struct stc_adc_pcis_field
{
  volatile  uint8_t P1A        : 3;
  volatile  uint8_t P2A        : 5;
} stc_adc_pcis_field_t;

typedef struct stc_adc_cmpcr_field
{
  volatile  uint8_t CCH        : 5;
  volatile  uint8_t CMD0       : 1;
  volatile  uint8_t CMD1       : 1;
  volatile  uint8_t CMPEN      : 1;
} stc_adc_cmpcr_field_t;

typedef struct stc_adc_cmpd_field
{
       uint16_t RESERVED1  : 6;
  volatile uint16_t CMAD2      : 1;
  volatile uint16_t CMAD3      : 1;
  volatile uint16_t CMAD4      : 1;
  volatile uint16_t CMAD5      : 1;
  volatile uint16_t CMAD6      : 1;
  volatile uint16_t CMAD7      : 1;
  volatile uint16_t CMAD8      : 1;
  volatile uint16_t CMAD9      : 1;
  volatile uint16_t CMAD10     : 1;
  volatile uint16_t CMAD11     : 1;
} stc_adc_cmpd_field_t;

typedef struct stc_adc_adss23_field
{
  volatile uint16_t TS16       : 1;
  volatile uint16_t TS17       : 1;
  volatile uint16_t TS18       : 1;
  volatile uint16_t TS19       : 1;
  volatile uint16_t TS20       : 1;
  volatile uint16_t TS21       : 1;
  volatile uint16_t TS22       : 1;
  volatile uint16_t TS23       : 1;
  volatile uint16_t TS24       : 1;
  volatile uint16_t TS25       : 1;
  volatile uint16_t TS26       : 1;
  volatile uint16_t TS27       : 1;
  volatile uint16_t TS28       : 1;
  volatile uint16_t TS29       : 1;
  volatile uint16_t TS30       : 1;
  volatile uint16_t TS31       : 1;
} stc_adc_adss23_field_t;

typedef struct stc_adc_adss2_field
{
  volatile  uint8_t TS16       : 1;
  volatile  uint8_t TS17       : 1;
  volatile  uint8_t TS18       : 1;
  volatile  uint8_t TS19       : 1;
  volatile  uint8_t TS20       : 1;
  volatile  uint8_t TS21       : 1;
  volatile  uint8_t TS22       : 1;
  volatile  uint8_t TS23       : 1;
} stc_adc_adss2_field_t;

typedef struct stc_adc_adss3_field
{
  volatile  uint8_t TS24       : 1;
  volatile  uint8_t TS25       : 1;
  volatile  uint8_t TS26       : 1;
  volatile  uint8_t TS27       : 1;
  volatile  uint8_t TS28       : 1;
  volatile  uint8_t TS29       : 1;
  volatile  uint8_t TS30       : 1;
  volatile  uint8_t TS31       : 1;
} stc_adc_adss3_field_t;

typedef struct stc_adc_adss01_field
{
  volatile uint16_t TS0        : 1;
  volatile uint16_t TS1        : 1;
  volatile uint16_t TS2        : 1;
  volatile uint16_t TS3        : 1;
  volatile uint16_t TS4        : 1;
  volatile uint16_t TS5        : 1;
  volatile uint16_t TS6        : 1;
  volatile uint16_t TS7        : 1;
  volatile uint16_t TS8        : 1;
  volatile uint16_t TS9        : 1;
  volatile uint16_t TS10       : 1;
  volatile uint16_t TS11       : 1;
  volatile uint16_t TS12       : 1;
  volatile uint16_t TS13       : 1;
  volatile uint16_t TS14       : 1;
  volatile uint16_t TS15       : 1;
} stc_adc_adss01_field_t;

typedef struct stc_adc_adss0_field
{
  volatile  uint8_t TS0        : 1;
  volatile  uint8_t TS1        : 1;
  volatile  uint8_t TS2        : 1;
  volatile  uint8_t TS3        : 1;
  volatile  uint8_t TS4        : 1;
  volatile  uint8_t TS5        : 1;
  volatile  uint8_t TS6        : 1;
  volatile  uint8_t TS7        : 1;
} stc_adc_adss0_field_t;

typedef struct stc_adc_adss1_field
{
  volatile  uint8_t TS8        : 1;
  volatile  uint8_t TS9        : 1;
  volatile  uint8_t TS10       : 1;
  volatile  uint8_t TS11       : 1;
  volatile  uint8_t TS12       : 1;
  volatile  uint8_t TS13       : 1;
  volatile  uint8_t TS14       : 1;
  volatile  uint8_t TS15       : 1;
} stc_adc_adss1_field_t;

typedef struct stc_adc_adst01_field
{
  volatile uint16_t ST10       : 1;
  volatile uint16_t ST11       : 1;
  volatile uint16_t ST12       : 1;
  volatile uint16_t ST13       : 1;
  volatile uint16_t ST14       : 1;
  volatile uint16_t STX10      : 1;
  volatile uint16_t STX11      : 1;
  volatile uint16_t STX12      : 1;
  volatile uint16_t ST00       : 1;
  volatile uint16_t ST01       : 1;
  volatile uint16_t ST02       : 1;
  volatile uint16_t ST03       : 1;
  volatile uint16_t ST04       : 1;
  volatile uint16_t STX00      : 1;
  volatile uint16_t STX01      : 1;
  volatile uint16_t STX02      : 1;
} stc_adc_adst01_field_t;

typedef struct stc_adc_adst1_field
{
  volatile  uint8_t ST1        : 5;
  volatile  uint8_t STX1       : 3;
} stc_adc_adst1_field_t;

typedef struct stc_adc_adst0_field
{
  volatile  uint8_t ST0        : 5;
  volatile  uint8_t STX0       : 3;
} stc_adc_adst0_field_t;

typedef struct stc_adc_adct_field
{
  volatile  uint8_t CT0        : 1;
  volatile  uint8_t CT1        : 1;
  volatile  uint8_t CT2        : 1;
} stc_adc_adct_field_t;

typedef struct stc_adc_prtsl_field
{
  volatile  uint8_t PRTSL0     : 1;
  volatile  uint8_t PRTSL1     : 1;
  volatile  uint8_t PRTSL2     : 1;
  volatile  uint8_t PRTSL3     : 1;
} stc_adc_prtsl_field_t;

typedef struct stc_adc_sctsl_field
{
  volatile  uint8_t SCTSL0     : 1;
  volatile  uint8_t SCTSL1     : 1;
  volatile  uint8_t SCTSL2     : 1;
  volatile  uint8_t SCTSL3     : 1;
} stc_adc_sctsl_field_t;

typedef struct stc_adc_adcen_field
{
  volatile  uint16_t ENBL       : 1;
  volatile  uint16_t READY      : 1;
  volatile  uint16_t RESERVED   : 6;
  volatile  uint16_t ENBLTIME   : 8;  
} stc_adc_adcen_field_t;

typedef struct stc_adc_wcmpdh_field
{
        uint16_t RESERVED   : 6;
  volatile  uint16_t CMHD       : 10;
} stc_adc_wcmpdh_field_t;

typedef struct stc_adc_wcmpcr_field
{
        uint8_t  RESERVED   : 2;
  volatile  uint8_t  RCOE       : 1;
  volatile  uint8_t  RCOIE      : 1;
  volatile  uint8_t  RCOIRRS    : 1;
  volatile  uint8_t  RCOCD      : 3;
} stc_adc_wcmpcr_field_t;

typedef struct stc_adc_wcmpdl_field
{
        uint16_t RESERVED   : 6;
  volatile  uint16_t CMLD       : 10;
} stc_adc_wcmpdl_field_t;

typedef struct stc_adc_wcmpsr_field
{
  volatile  uint8_t  WCCH       : 5;
  volatile  uint8_t  WCMD       : 1;
  volatile  uint8_t  RESERVED   : 2;
} stc_adc_wcmpsr_field_t;

typedef struct stc_adc_wcmrcot_field
{
  volatile  uint32_t RCOOF      : 1;
        uint32_t RESERVED   : 31;
} stc_adc_wcmrcot_field_t;

typedef struct stc_adc_wcmrcif_field
{
  volatile  uint32_t RCINT      : 1;
        uint32_t RESERVED   : 31;
} stc_adc_wcmrcif_field_t;



 
 
typedef struct stc_crtrim_mcr_psr_field
{
  volatile  uint8_t CSR        : 3;
} stc_crtrim_mcr_psr_field_t;

typedef struct stc_crtrim_mcr_ftrm_field
{
  volatile uint16_t TRD        :10;
} stc_crtrim_mcr_ftrm_field_t;

typedef struct stc_crtrim_mcr_ttrm_field
{
  volatile  uint8_t TRT        : 5;
} stc_crtrim_mcr_ttrm_field_t;

typedef struct stc_crtrim_mcr_rlr_field
{
  volatile uint32_t TRMLCK     :32;
} stc_crtrim_mcr_rlr_field_t;



 
 
typedef struct stc_exti_enir_field
{
  volatile uint32_t EN0        : 1;
  volatile uint32_t EN1        : 1;
  volatile uint32_t EN2        : 1;
  volatile uint32_t EN3        : 1;
  volatile uint32_t EN4        : 1;
  volatile uint32_t EN5        : 1;
  volatile uint32_t EN6        : 1;
  volatile uint32_t EN7        : 1;
  volatile uint32_t EN8        : 1;
  volatile uint32_t EN9        : 1;
  volatile uint32_t EN10       : 1;
  volatile uint32_t EN11       : 1;
  volatile uint32_t EN12       : 1;
  volatile uint32_t EN13       : 1;
  volatile uint32_t EN14       : 1;
  volatile uint32_t EN15       : 1;
  volatile uint32_t EN16       : 1;
  volatile uint32_t EN17       : 1;
  volatile uint32_t EN18       : 1;
  volatile uint32_t EN19       : 1;
  volatile uint32_t EN20       : 1;
  volatile uint32_t EN21       : 1;
  volatile uint32_t EN22       : 1;
  volatile uint32_t EN23       : 1;
  volatile uint32_t EN24       : 1;
  volatile uint32_t EN25       : 1;
  volatile uint32_t EN26       : 1;
  volatile uint32_t EN27       : 1;
  volatile uint32_t EN28       : 1;
  volatile uint32_t EN29       : 1;
  volatile uint32_t EN30       : 1;
  volatile uint32_t EN31       : 1;
} stc_exti_enir_field_t;

typedef struct stc_exti_eirr_field
{
  volatile uint32_t ER0        : 1;
  volatile uint32_t ER1        : 1;
  volatile uint32_t ER2        : 1;
  volatile uint32_t ER3        : 1;
  volatile uint32_t ER4        : 1;
  volatile uint32_t ER5        : 1;
  volatile uint32_t ER6        : 1;
  volatile uint32_t ER7        : 1;
  volatile uint32_t ER8        : 1;
  volatile uint32_t ER9        : 1;
  volatile uint32_t ER10       : 1;
  volatile uint32_t ER11       : 1;
  volatile uint32_t ER12       : 1;
  volatile uint32_t ER13       : 1;
  volatile uint32_t ER14       : 1;
  volatile uint32_t ER15       : 1;
  volatile uint32_t ER16       : 1;
  volatile uint32_t ER17       : 1;
  volatile uint32_t ER18       : 1;
  volatile uint32_t ER19       : 1;
  volatile uint32_t ER20       : 1;
  volatile uint32_t ER21       : 1;
  volatile uint32_t ER22       : 1;
  volatile uint32_t ER23       : 1;
  volatile uint32_t ER24       : 1;
  volatile uint32_t ER25       : 1;
  volatile uint32_t ER26       : 1;
  volatile uint32_t ER27       : 1;
  volatile uint32_t ER28       : 1;
  volatile uint32_t ER29       : 1;
  volatile uint32_t ER30       : 1;
  volatile uint32_t ER31       : 1;
} stc_exti_eirr_field_t;

typedef struct stc_exti_eicl_field
{
  volatile uint32_t ECL0       : 1;
  volatile uint32_t ECL1       : 1;
  volatile uint32_t ECL2       : 1;
  volatile uint32_t ECL3       : 1;
  volatile uint32_t ECL4       : 1;
  volatile uint32_t ECL5       : 1;
  volatile uint32_t ECL6       : 1;
  volatile uint32_t ECL7       : 1;
  volatile uint32_t ECL8       : 1;
  volatile uint32_t ECL9       : 1;
  volatile uint32_t ECL10      : 1;
  volatile uint32_t ECL11      : 1;
  volatile uint32_t ECL12      : 1;
  volatile uint32_t ECL13      : 1;
  volatile uint32_t ECL14      : 1;
  volatile uint32_t ECL15      : 1;
  volatile uint32_t ECL16      : 1;
  volatile uint32_t ECL17      : 1;
  volatile uint32_t ECL18      : 1;
  volatile uint32_t ECL19      : 1;
  volatile uint32_t ECL20      : 1;
  volatile uint32_t ECL21      : 1;
  volatile uint32_t ECL22      : 1;
  volatile uint32_t ECL23      : 1;
  volatile uint32_t ECL24      : 1;
  volatile uint32_t ECL25      : 1;
  volatile uint32_t ECL26      : 1;
  volatile uint32_t ECL27      : 1;
  volatile uint32_t ECL28      : 1;
  volatile uint32_t ECL29      : 1;
  volatile uint32_t ECL30      : 1;
  volatile uint32_t ECL31      : 1;
} stc_exti_eicl_field_t;

typedef struct stc_exti_elvr_field
{
  volatile uint32_t LA0        : 1;
  volatile uint32_t LB0        : 1;
  volatile uint32_t LA1        : 1;
  volatile uint32_t LB1        : 1;
  volatile uint32_t LA2        : 1;
  volatile uint32_t LB2        : 1;
  volatile uint32_t LA3        : 1;
  volatile uint32_t LB3        : 1;
  volatile uint32_t LA4        : 1;
  volatile uint32_t LB4        : 1;
  volatile uint32_t LA5        : 1;
  volatile uint32_t LB5        : 1;
  volatile uint32_t LA6        : 1;
  volatile uint32_t LB6        : 1;
  volatile uint32_t LA7        : 1;
  volatile uint32_t LB7        : 1;
  volatile uint32_t LA8        : 1;
  volatile uint32_t LB8        : 1;
  volatile uint32_t LA9        : 1;
  volatile uint32_t LB9        : 1;
  volatile uint32_t LA10       : 1;
  volatile uint32_t LB10       : 1;
  volatile uint32_t LA11       : 1;
  volatile uint32_t LB11       : 1;
  volatile uint32_t LA12       : 1;
  volatile uint32_t LB12       : 1;
  volatile uint32_t LA13       : 1;
  volatile uint32_t LB13       : 1;
  volatile uint32_t LA14       : 1;
  volatile uint32_t LB14       : 1;
  volatile uint32_t LA15       : 1;
  volatile uint32_t LB15       : 1;
} stc_exti_elvr_field_t;

typedef struct stc_exti_elvr1_field
{
  volatile uint32_t LA16       : 1;
  volatile uint32_t LB16       : 1;
  volatile uint32_t LA17       : 1;
  volatile uint32_t LB17       : 1;
  volatile uint32_t LA18       : 1;
  volatile uint32_t LB18       : 1;
  volatile uint32_t LA19       : 1;
  volatile uint32_t LB19       : 1;
  volatile uint32_t LA20       : 1;
  volatile uint32_t LB20       : 1;
  volatile uint32_t LA21       : 1;
  volatile uint32_t LB21       : 1;
  volatile uint32_t LA22       : 1;
  volatile uint32_t LB22       : 1;
  volatile uint32_t LA23       : 1;
  volatile uint32_t LB23       : 1;
  volatile uint32_t LA24       : 1;
  volatile uint32_t LB24       : 1;
  volatile uint32_t LA25       : 1;
  volatile uint32_t LB25       : 1;
  volatile uint32_t LA26       : 1;
  volatile uint32_t LB26       : 1;
  volatile uint32_t LA27       : 1;
  volatile uint32_t LB27       : 1;
  volatile uint32_t LA28       : 1;
  volatile uint32_t LB28       : 1;
  volatile uint32_t LA29       : 1;
  volatile uint32_t LB29       : 1;
  volatile uint32_t LA30       : 1;
  volatile uint32_t LB30       : 1;
  volatile uint32_t LA31       : 1;
  volatile uint32_t LB31       : 1;
} stc_exti_elvr1_field_t;

typedef struct stc_exti_nmirr_field
{
  volatile  uint8_t NR         : 1;
} stc_exti_nmirr_field_t;

typedef struct stc_exti_nmicl_field
{
  volatile  uint8_t NCL        : 1;
} stc_exti_nmicl_field_t;



 
 
typedef struct stc_intreq_drqsel_field
{
  volatile uint32_t DRQSEL0    : 1;
  volatile uint32_t DRQSEL1    : 1;
  volatile uint32_t DRQSEL2    : 1;
  volatile uint32_t DRQSEL3    : 1;
  volatile uint32_t DRQSEL4    : 1;
  volatile uint32_t DRQSEL5    : 1;
  volatile uint32_t DRQSEL6    : 1;
  volatile uint32_t DRQSEL7    : 1;
  volatile uint32_t DRQSEL8    : 1;
  volatile uint32_t DRQSEL9    : 1;
  volatile uint32_t DRQSEL10   : 1;
  volatile uint32_t DRQSEL11   : 1;
  volatile uint32_t DRQSEL12   : 1;
  volatile uint32_t DRQSEL13   : 1;
  volatile uint32_t DRQSEL14   : 1;
  volatile uint32_t DRQSEL15   : 1;
  volatile uint32_t DRQSEL16   : 1;
  volatile uint32_t DRQSEL17   : 1;
  volatile uint32_t DRQSEL18   : 1;
  volatile uint32_t DRQSEL19   : 1;
  volatile uint32_t DRQSEL20   : 1;
  volatile uint32_t DRQSEL21   : 1;
  volatile uint32_t DRQSEL22   : 1;
  volatile uint32_t DRQSEL23   : 1;
  volatile uint32_t DRQSEL24   : 1;
  volatile uint32_t DRQSEL25   : 1;
  volatile uint32_t DRQSEL26   : 1;
  volatile uint32_t DRQSEL27   : 1;
  volatile uint32_t DRQSEL28   : 1;
  volatile uint32_t DRQSEL29   : 1;
  volatile uint32_t DRQSEL30   : 1;
  volatile uint32_t DRQSEL31   : 1;
} stc_intreq_drqsel_field_t;

typedef struct stc_intreq_oddpks_field
{
  volatile  uint8_t ODDPKS0    : 1;
  volatile  uint8_t ODDPKS1    : 1;
  volatile  uint8_t ODDPKS2    : 1;
  volatile  uint8_t ODDPKS3    : 1;
  volatile  uint8_t ODDPKS4    : 1;
} stc_intreq_oddpks_field_t;

typedef struct stc_intreq_irq003sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq003sel_field_t;

typedef struct stc_intreq_irq004sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq004sel_field_t;

typedef struct stc_intreq_irq005sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq005sel_field_t;

typedef struct stc_intreq_irq006sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq006sel_field_t;

typedef struct stc_intreq_irq007sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq007sel_field_t;

typedef struct stc_intreq_irq008sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq008sel_field_t;

typedef struct stc_intreq_irq009sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq009sel_field_t;

typedef struct stc_intreq_irq010sel_field
{
  volatile uint32_t SELIRQ     : 8;
       uint32_t RESERVED8  : 8;
  volatile uint32_t SELBIT     : 8;
} stc_intreq_irq010sel_field_t;

typedef struct stc_intreq_exc02mon_field
{
  volatile uint32_t NMI        : 1;
  volatile uint32_t HWINT      : 1;
} stc_intreq_exc02mon_field_t;

typedef struct stc_intreq_irq000mon_field
{
  volatile uint32_t FCSINT     : 1;
} stc_intreq_irq000mon_field_t;

typedef struct stc_intreq_irq001mon_field
{
  volatile uint32_t SWWDTINT   : 1;
} stc_intreq_irq001mon_field_t;

typedef struct stc_intreq_irq002mon_field
{
  volatile uint32_t LVDINT     : 1;
} stc_intreq_irq002mon_field_t;

typedef struct stc_intreq_irq003mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq003mon_field_t;

typedef struct stc_intreq_irq004mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq004mon_field_t;

typedef struct stc_intreq_irq005mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq005mon_field_t;

typedef struct stc_intreq_irq006mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq006mon_field_t;

typedef struct stc_intreq_irq007mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq007mon_field_t;

typedef struct stc_intreq_irq008mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq008mon_field_t;

typedef struct stc_intreq_irq009mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq009mon_field_t;

typedef struct stc_intreq_irq010mon_field
{
  volatile uint32_t IRQBIT0    : 1;
  volatile uint32_t IRQBIT1    : 1;
  volatile uint32_t IRQBIT2    : 1;
  volatile uint32_t IRQBIT3    : 1;
  volatile uint32_t IRQBIT4    : 1;
  volatile uint32_t IRQBIT5    : 1;
  volatile uint32_t IRQBIT6    : 1;
  volatile uint32_t IRQBIT7    : 1;
} stc_intreq_irq010mon_field_t;

typedef struct stc_intreq_irq011mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq011mon_field_t;

typedef struct stc_intreq_irq012mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq012mon_field_t;

typedef struct stc_intreq_irq013mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq013mon_field_t;

typedef struct stc_intreq_irq014mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq014mon_field_t;

typedef struct stc_intreq_irq015mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq015mon_field_t;

typedef struct stc_intreq_irq016mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq016mon_field_t;

typedef struct stc_intreq_irq017mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq017mon_field_t;

typedef struct stc_intreq_irq018mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq018mon_field_t;

typedef struct stc_intreq_irq019mon_field
{
  volatile uint32_t QUDINT0    : 1;
  volatile uint32_t QUDINT1    : 1;
  volatile uint32_t QUDINT2    : 1;
  volatile uint32_t QUDINT3    : 1;
  volatile uint32_t QUDINT4    : 1;
  volatile uint32_t QUDINT5    : 1;
} stc_intreq_irq019mon_field_t;

typedef struct stc_intreq_irq020mon_field
{
  volatile uint32_t QUDINT0    : 1;
  volatile uint32_t QUDINT1    : 1;
  volatile uint32_t QUDINT2    : 1;
  volatile uint32_t QUDINT3    : 1;
  volatile uint32_t QUDINT4    : 1;
  volatile uint32_t QUDINT5    : 1;
} stc_intreq_irq020mon_field_t;

typedef struct stc_intreq_irq021mon_field
{
  volatile uint32_t WAVEINT0   : 1;
  volatile uint32_t WAVEINT1   : 1;
  volatile uint32_t WAVEINT2   : 1;
  volatile uint32_t WAVEINT3   : 1;
} stc_intreq_irq021mon_field_t;

typedef struct stc_intreq_irq022mon_field
{
  volatile uint32_t WAVEINT0   : 1;
  volatile uint32_t WAVEINT1   : 1;
  volatile uint32_t WAVEINT2   : 1;
  volatile uint32_t WAVEINT3   : 1;
} stc_intreq_irq022mon_field_t;

typedef struct stc_intreq_irq023mon_field
{
  volatile uint32_t WAVEINT0   : 1;
  volatile uint32_t WAVEINT1   : 1;
  volatile uint32_t WAVEINT2   : 1;
  volatile uint32_t WAVEINT3   : 1;
} stc_intreq_irq023mon_field_t;

typedef struct stc_intreq_irq024mon_field
{
  volatile uint32_t FRT_PEAK_INT0: 1;
  volatile uint32_t FRT_PEAK_INT1: 1;
  volatile uint32_t FRT_PEAK_INT2: 1;
} stc_intreq_irq024mon_field_t;

typedef struct stc_intreq_irq025mon_field
{
  volatile uint32_t FRT_ZERO_INT0: 1;
  volatile uint32_t FRT_ZERO_INT1: 1;
  volatile uint32_t FRT_ZERO_INT2: 1;
} stc_intreq_irq025mon_field_t;

typedef struct stc_intreq_irq026mon_field
{
  volatile uint32_t ICUINT0    : 1;
  volatile uint32_t ICUINT1    : 1;
  volatile uint32_t ICUINT2    : 1;
  volatile uint32_t ICUINT3    : 1;
} stc_intreq_irq026mon_field_t;

typedef struct stc_intreq_irq027mon_field
{
  volatile uint32_t OCUINT0    : 1;
  volatile uint32_t OCUINT1    : 1;
  volatile uint32_t OCUINT2    : 1;
  volatile uint32_t OCUINT3    : 1;
  volatile uint32_t OCUINT4    : 1;
  volatile uint32_t OCUINT5    : 1;
} stc_intreq_irq027mon_field_t;

typedef struct stc_intreq_irq028mon_field
{
  volatile uint32_t FRT_PEAK_INT0: 1;
  volatile uint32_t FRT_PEAK_INT1: 1;
  volatile uint32_t FRT_PEAK_INT2: 1;
} stc_intreq_irq028mon_field_t;

typedef struct stc_intreq_irq029mon_field
{
  volatile uint32_t FRT_ZERO_INT0: 1;
  volatile uint32_t FRT_ZERO_INT1: 1;
  volatile uint32_t FRT_ZERO_INT2: 1;
} stc_intreq_irq029mon_field_t;

typedef struct stc_intreq_irq030mon_field
{
  volatile uint32_t ICUINT0    : 1;
  volatile uint32_t ICUINT1    : 1;
  volatile uint32_t ICUINT2    : 1;
  volatile uint32_t ICUINT3    : 1;
} stc_intreq_irq030mon_field_t;

typedef struct stc_intreq_irq031mon_field
{
  volatile uint32_t OCUINT0    : 1;
  volatile uint32_t OCUINT1    : 1;
  volatile uint32_t OCUINT2    : 1;
  volatile uint32_t OCUINT3    : 1;
  volatile uint32_t OCUINT4    : 1;
  volatile uint32_t OCUINT5    : 1;
} stc_intreq_irq031mon_field_t;

typedef struct stc_intreq_irq032mon_field
{
  volatile uint32_t FRT_PEAK_INT0: 1;
  volatile uint32_t FRT_PEAK_INT1: 1;
  volatile uint32_t FRT_PEAK_INT2: 1;
} stc_intreq_irq032mon_field_t;

typedef struct stc_intreq_irq033mon_field
{
  volatile uint32_t FRT_ZERO_INT0: 1;
  volatile uint32_t FRT_ZERO_INT1: 1;
  volatile uint32_t FRT_ZERO_INT2: 1;
} stc_intreq_irq033mon_field_t;

typedef struct stc_intreq_irq034mon_field
{
  volatile uint32_t ICUINT0    : 1;
  volatile uint32_t ICUINT1    : 1;
  volatile uint32_t ICUINT2    : 1;
  volatile uint32_t ICUINT3    : 1;
} stc_intreq_irq034mon_field_t;

typedef struct stc_intreq_irq035mon_field
{
  volatile uint32_t OCUINT0    : 1;
  volatile uint32_t OCUINT1    : 1;
  volatile uint32_t OCUINT2    : 1;
  volatile uint32_t OCUINT3    : 1;
  volatile uint32_t OCUINT4    : 1;
  volatile uint32_t OCUINT5    : 1;
} stc_intreq_irq035mon_field_t;

typedef struct stc_intreq_irq036mon_field
{
  volatile uint32_t PPGINT0    : 1;
  volatile uint32_t PPGINT1    : 1;
  volatile uint32_t PPGINT2    : 1;
} stc_intreq_irq036mon_field_t;

typedef struct stc_intreq_irq037mon_field
{
  volatile uint32_t PPGINT0    : 1;
  volatile uint32_t PPGINT1    : 1;
  volatile uint32_t PPGINT2    : 1;
} stc_intreq_irq037mon_field_t;

typedef struct stc_intreq_irq038mon_field
{
  volatile uint32_t PPGINT0    : 1;
  volatile uint32_t PPGINT1    : 1;
  volatile uint32_t PPGINT2    : 1;
} stc_intreq_irq038mon_field_t;

typedef struct stc_intreq_irq039mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq039mon_field_t;

typedef struct stc_intreq_irq040mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq040mon_field_t;

typedef struct stc_intreq_irq041mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq041mon_field_t;

typedef struct stc_intreq_irq042mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq042mon_field_t;

typedef struct stc_intreq_irq043mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq043mon_field_t;

typedef struct stc_intreq_irq044mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq044mon_field_t;

typedef struct stc_intreq_irq045mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq045mon_field_t;

typedef struct stc_intreq_irq046mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq046mon_field_t;

typedef struct stc_intreq_irq047mon_field
{
  volatile uint32_t TIMINT1    : 1;
  volatile uint32_t TIMINT2    : 1;
} stc_intreq_irq047mon_field_t;

typedef struct stc_intreq_irq048mon_field
{
  volatile uint32_t WCINT      : 1;
} stc_intreq_irq048mon_field_t;

typedef struct stc_intreq_irq049mon_field
{
  volatile uint32_t BMEMCS     : 1;
} stc_intreq_irq049mon_field_t;

typedef struct stc_intreq_irq050mon_field
{
  volatile uint32_t RTCINT     : 1;
} stc_intreq_irq050mon_field_t;

typedef struct stc_intreq_irq051mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq051mon_field_t;

typedef struct stc_intreq_irq052mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq052mon_field_t;

typedef struct stc_intreq_irq053mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq053mon_field_t;

typedef struct stc_intreq_irq054mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq054mon_field_t;

typedef struct stc_intreq_irq055mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq055mon_field_t;

typedef struct stc_intreq_irq056mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq056mon_field_t;

typedef struct stc_intreq_irq057mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq057mon_field_t;

typedef struct stc_intreq_irq058mon_field
{
  volatile uint32_t EXTINT     : 1;
} stc_intreq_irq058mon_field_t;

typedef struct stc_intreq_irq059mon_field
{
  volatile uint32_t MOSCINT    : 1;
  volatile uint32_t SOSCINT    : 1;
  volatile uint32_t MPLLINT    : 1;
  volatile uint32_t UPLLINT    : 1;
} stc_intreq_irq059mon_field_t;

typedef struct stc_intreq_irq060mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq060mon_field_t;

typedef struct stc_intreq_irq061mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq061mon_field_t;

typedef struct stc_intreq_irq062mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq062mon_field_t;

typedef struct stc_intreq_irq063mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq063mon_field_t;

typedef struct stc_intreq_irq064mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq064mon_field_t;

typedef struct stc_intreq_irq065mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq065mon_field_t;

typedef struct stc_intreq_irq066mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq066mon_field_t;

typedef struct stc_intreq_irq067mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq067mon_field_t;

typedef struct stc_intreq_irq068mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq068mon_field_t;

typedef struct stc_intreq_irq069mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq069mon_field_t;

typedef struct stc_intreq_irq070mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq070mon_field_t;

typedef struct stc_intreq_irq071mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq071mon_field_t;

typedef struct stc_intreq_irq072mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq072mon_field_t;

typedef struct stc_intreq_irq073mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq073mon_field_t;

typedef struct stc_intreq_irq074mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq074mon_field_t;

typedef struct stc_intreq_irq075mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq075mon_field_t;

typedef struct stc_intreq_irq076mon_field
{
  volatile uint32_t ADCINT0    : 1;
  volatile uint32_t ADCINT1    : 1;
  volatile uint32_t ADCINT2    : 1;
  volatile uint32_t ADCINT3    : 1;
  volatile uint32_t ADCINT4    : 1;
} stc_intreq_irq076mon_field_t;

typedef struct stc_intreq_irq077mon_field
{
  volatile uint32_t ADCINT0    : 1;
  volatile uint32_t ADCINT1    : 1;
  volatile uint32_t ADCINT2    : 1;
  volatile uint32_t ADCINT3    : 1;
  volatile uint32_t ADCINT4    : 1;
} stc_intreq_irq077mon_field_t;

typedef struct stc_intreq_irq078mon_field
{
  volatile uint32_t USB_DRQ_INT0: 1;
  volatile uint32_t USB_DRQ_INT1: 1;
  volatile uint32_t USB_DRQ_INT2: 1;
  volatile uint32_t USB_DRQ_INT3: 1;
  volatile uint32_t USB_DRQ_INT4: 1;
} stc_intreq_irq078mon_field_t;

typedef struct stc_intreq_irq079mon_field
{
  volatile uint32_t USB_INT0   : 1;
  volatile uint32_t USB_INT1   : 1;
  volatile uint32_t USB_INT2   : 1;
  volatile uint32_t USB_INT3   : 1;
  volatile uint32_t USB_INT4   : 1;
  volatile uint32_t USB_INT5   : 1;
} stc_intreq_irq079mon_field_t;

typedef struct stc_intreq_irq080mon_field
{
  volatile uint32_t CANINT     : 1;
} stc_intreq_irq080mon_field_t;

typedef struct stc_intreq_irq081mon_field
{
  volatile uint32_t CANINT     : 1;
} stc_intreq_irq081mon_field_t;

typedef struct stc_intreq_irq082mon_field
{
  volatile uint32_t MACSBD     : 1;
  volatile uint32_t MACPMT     : 1;
  volatile uint32_t MACLPI     : 1;
} stc_intreq_irq082mon_field_t;

typedef struct stc_intreq_irq083mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq083mon_field_t;

typedef struct stc_intreq_irq084mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq084mon_field_t;

typedef struct stc_intreq_irq085mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq085mon_field_t;

typedef struct stc_intreq_irq086mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq086mon_field_t;

typedef struct stc_intreq_irq087mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq087mon_field_t;

typedef struct stc_intreq_irq088mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq088mon_field_t;

typedef struct stc_intreq_irq089mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq089mon_field_t;

typedef struct stc_intreq_irq090mon_field
{
  volatile uint32_t DMACINT    : 1;
} stc_intreq_irq090mon_field_t;

typedef struct stc_intreq_irq091mon_field
{
  volatile uint32_t DSTCINT0   : 1;
  volatile uint32_t DSTCINT1   : 1;
} stc_intreq_irq091mon_field_t;

typedef struct stc_intreq_irq092mon_field
{
  volatile uint32_t EXTINT0    : 1;
  volatile uint32_t EXTINT1    : 1;
  volatile uint32_t EXTINT2    : 1;
  volatile uint32_t EXTINT3    : 1;
} stc_intreq_irq092mon_field_t;

typedef struct stc_intreq_irq093mon_field
{
  volatile uint32_t EXTINT0    : 1;
  volatile uint32_t EXTINT1    : 1;
  volatile uint32_t EXTINT2    : 1;
  volatile uint32_t EXTINT3    : 1;
} stc_intreq_irq093mon_field_t;

typedef struct stc_intreq_irq094mon_field
{
  volatile uint32_t EXTINT0    : 1;
  volatile uint32_t EXTINT1    : 1;
  volatile uint32_t EXTINT2    : 1;
  volatile uint32_t EXTINT3    : 1;
} stc_intreq_irq094mon_field_t;

typedef struct stc_intreq_irq095mon_field
{
  volatile uint32_t EXTINT0    : 1;
  volatile uint32_t EXTINT1    : 1;
  volatile uint32_t EXTINT2    : 1;
  volatile uint32_t EXTINT3    : 1;
} stc_intreq_irq095mon_field_t;

typedef struct stc_intreq_irq096mon_field
{
  volatile uint32_t QUDINT0    : 1;
  volatile uint32_t QUDINT1    : 1;
  volatile uint32_t QUDINT2    : 1;
  volatile uint32_t QUDINT3    : 1;
  volatile uint32_t QUDINT4    : 1;
  volatile uint32_t QUDINT5    : 1;
} stc_intreq_irq096mon_field_t;

typedef struct stc_intreq_irq097mon_field
{
  volatile uint32_t QUDINT0    : 1;
  volatile uint32_t QUDINT1    : 1;
  volatile uint32_t QUDINT2    : 1;
  volatile uint32_t QUDINT3    : 1;
  volatile uint32_t QUDINT4    : 1;
  volatile uint32_t QUDINT5    : 1;
} stc_intreq_irq097mon_field_t;

typedef struct stc_intreq_irq098mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq098mon_field_t;

typedef struct stc_intreq_irq099mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq099mon_field_t;

typedef struct stc_intreq_irq100mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq100mon_field_t;

typedef struct stc_intreq_irq101mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
} stc_intreq_irq101mon_field_t;

typedef struct stc_intreq_irq102mon_field
{
  volatile uint32_t BTINT0     : 1;
  volatile uint32_t BTINT1     : 1;
  volatile uint32_t BTINT2     : 1;
  volatile uint32_t BTINT3     : 1;
  volatile uint32_t BTINT4     : 1;
  volatile uint32_t BTINT5     : 1;
  volatile uint32_t BTINT6     : 1;
  volatile uint32_t BTINT7     : 1;
} stc_intreq_irq102mon_field_t;

typedef struct stc_intreq_irq103mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq103mon_field_t;

typedef struct stc_intreq_irq104mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq104mon_field_t;

typedef struct stc_intreq_irq105mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq105mon_field_t;

typedef struct stc_intreq_irq106mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq106mon_field_t;

typedef struct stc_intreq_irq107mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq107mon_field_t;

typedef struct stc_intreq_irq108mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq108mon_field_t;

typedef struct stc_intreq_irq109mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq109mon_field_t;

typedef struct stc_intreq_irq110mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq110mon_field_t;

typedef struct stc_intreq_irq111mon_field
{
  volatile uint32_t ADCINT0    : 1;
  volatile uint32_t ADCINT1    : 1;
  volatile uint32_t ADCINT2    : 1;
  volatile uint32_t ADCINT3    : 1;
  volatile uint32_t ADCINT4    : 1;
} stc_intreq_irq111mon_field_t;

typedef struct stc_intreq_irq113mon_field
{
  volatile uint32_t USB_DRQ_INT0: 1;
  volatile uint32_t USB_DRQ_INT1: 1;
  volatile uint32_t USB_DRQ_INT2: 1;
  volatile uint32_t USB_DRQ_INT3: 1;
  volatile uint32_t USB_DRQ_INT4: 1;
} stc_intreq_irq113mon_field_t;

typedef struct stc_intreq_irq114mon_field
{
  volatile uint32_t USB_INT0   : 1;
  volatile uint32_t USB_INT1   : 1;
  volatile uint32_t USB_INT2   : 1;
  volatile uint32_t USB_INT3   : 1;
  volatile uint32_t USB_INT4   : 1;
  volatile uint32_t USB_INT5   : 1;
} stc_intreq_irq114mon_field_t;

typedef struct stc_intreq_irq118mon_field
{
  volatile uint32_t SDINT0     : 1;
  volatile uint32_t SDINT1     : 1;
} stc_intreq_irq118mon_field_t;

typedef struct stc_intreq_irq119mon_field
{
  volatile uint32_t FLINT      : 1;
} stc_intreq_irq119mon_field_t;

typedef struct stc_intreq_irq120mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq120mon_field_t;

typedef struct stc_intreq_irq121mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq121mon_field_t;

typedef struct stc_intreq_irq122mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq122mon_field_t;

typedef struct stc_intreq_irq123mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq123mon_field_t;

typedef struct stc_intreq_irq124mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq124mon_field_t;

typedef struct stc_intreq_irq125mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq125mon_field_t;

typedef struct stc_intreq_irq126mon_field
{
  volatile uint32_t MFSRINT    : 1;
} stc_intreq_irq126mon_field_t;

typedef struct stc_intreq_irq127mon_field
{
  volatile uint32_t MFSINT0    : 1;
  volatile uint32_t MFSINT1    : 1;
} stc_intreq_irq127mon_field_t;



 
typedef struct stc_irqsel_field
{
  volatile uint32_t	SELIRQ    : 8;
       uint32_t RESERVED0 : 8;
  volatile uint32_t SELBIT    : 8;
       uint32_t RESERVED1 : 8;
} stc_irqsel_field_t;
 


 
 
typedef struct stc_dstc_hwdesp_field
{
  volatile uint32_t CHANNEL    : 8;
       uint32_t RESERVED1  : 8;
  volatile uint32_t HWDESP     : 14;
       uint32_t RESERVED2  : 2;
} stc_dstc_hwdesp_field_t;

typedef struct stc_dstc_cfg_field
{
  volatile uint8_t  SWINTE     : 1;
  volatile uint8_t  ERINTE     : 1;
  volatile uint8_t  RBDIS      : 1;
  volatile uint8_t  ESTE       : 1;
  volatile uint8_t  SWPR       : 3;
       uint8_t  RESERVED   : 1;
} stc_dstc_cfg_field_t;

typedef struct stc_dstc_swtr_field
{
  volatile uint16_t SWDESP     : 14;
  volatile uint16_t SWREQ      : 1;
  volatile uint16_t SWST       : 1;
} stc_dstc_swtr_field_t;

typedef struct stc_dstc_moners_field
{
  volatile uint32_t EST        : 3;
  volatile uint32_t DER        : 1;
  volatile uint32_t ESTOP      : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t EHS        : 1;
  volatile uint32_t RESERVED2  : 1;
  volatile uint32_t ECH        : 8;
  volatile uint32_t EDESP      : 14;
       uint32_t RESERVED3  : 2;
} stc_dstc_moners_field_t;



 
 
typedef struct stc_gpio_pfr0_field
{
  volatile uint32_t P00        : 1;
  volatile uint32_t P01        : 1;
  volatile uint32_t P02        : 1;
  volatile uint32_t P03        : 1;
  volatile uint32_t P04        : 1;
  volatile uint32_t P05        : 1;
  volatile uint32_t P06        : 1;
  volatile uint32_t P07        : 1;
  volatile uint32_t P08        : 1;
  volatile uint32_t P09        : 1;
  volatile uint32_t P0A        : 1;
  volatile uint32_t P0B        : 1;
  volatile uint32_t P0C        : 1;
  volatile uint32_t P0D        : 1;
  volatile uint32_t P0E        : 1;
} stc_gpio_pfr0_field_t;

typedef struct stc_gpio_pfr1_field
{
  volatile uint32_t P10        : 1;
  volatile uint32_t P11        : 1;
  volatile uint32_t P12        : 1;
  volatile uint32_t P13        : 1;
  volatile uint32_t P14        : 1;
  volatile uint32_t P15        : 1;
  volatile uint32_t P16        : 1;
  volatile uint32_t P17        : 1;
  volatile uint32_t P18        : 1;
  volatile uint32_t P19        : 1;
  volatile uint32_t P1A        : 1;
  volatile uint32_t P1B        : 1;
  volatile uint32_t P1C        : 1;
  volatile uint32_t P1D        : 1;
  volatile uint32_t P1E        : 1;
  volatile uint32_t P1F        : 1;
} stc_gpio_pfr1_field_t;

typedef struct stc_gpio_pfr2_field
{
  volatile uint32_t P20        : 1;
  volatile uint32_t P21        : 1;
  volatile uint32_t P22        : 1;
  volatile uint32_t P23        : 1;
  volatile uint32_t P24        : 1;
  volatile uint32_t P25        : 1;
  volatile uint32_t P26        : 1;
  volatile uint32_t P27        : 1;
} stc_gpio_pfr2_field_t;

typedef struct stc_gpio_pfr3_field
{
  volatile uint32_t P30        : 1;
  volatile uint32_t P31        : 1;
  volatile uint32_t P32        : 1;
  volatile uint32_t P33        : 1;
  volatile uint32_t P34        : 1;
  volatile uint32_t P35        : 1;
  volatile uint32_t P36        : 1;
  volatile uint32_t P37        : 1;
  volatile uint32_t P38        : 1;
  volatile uint32_t P39        : 1;
  volatile uint32_t P3A        : 1;
  volatile uint32_t P3B        : 1;
  volatile uint32_t P3C        : 1;
  volatile uint32_t P3D        : 1;
  volatile uint32_t P3E        : 1;
  volatile uint32_t P3F        : 1;
} stc_gpio_pfr3_field_t;

typedef struct stc_gpio_pfr4_field
{
  volatile uint32_t P40        : 1;
  volatile uint32_t P41        : 1;
  volatile uint32_t P42        : 1;
  volatile uint32_t P43        : 1;
  volatile uint32_t P44        : 1;
  volatile uint32_t P45        : 1;
  volatile uint32_t P46        : 1;
  volatile uint32_t P47        : 1;
  volatile uint32_t P48        : 1;
  volatile uint32_t P49        : 1;
  volatile uint32_t P4A        : 1;
  volatile uint32_t P4B        : 1;
  volatile uint32_t P4C        : 1;
  volatile uint32_t P4D        : 1;
  volatile uint32_t P4E        : 1;
} stc_gpio_pfr4_field_t;

typedef struct stc_gpio_pfr5_field
{
  volatile uint32_t P50        : 1;
  volatile uint32_t P51        : 1;
  volatile uint32_t P52        : 1;
  volatile uint32_t P53        : 1;
  volatile uint32_t P54        : 1;
  volatile uint32_t P55        : 1;
  volatile uint32_t P56        : 1;
  volatile uint32_t P57        : 1;
  volatile uint32_t P58        : 1;
  volatile uint32_t P59        : 1;
  volatile uint32_t P5A        : 1;
  volatile uint32_t P5B        : 1;
} stc_gpio_pfr5_field_t;

typedef struct stc_gpio_pfr6_field
{
  volatile uint32_t P60        : 1;
  volatile uint32_t P61        : 1;
  volatile uint32_t P62        : 1;
  volatile uint32_t P63        : 1;
  volatile uint32_t P64        : 1;
  volatile uint32_t P65        : 1;
  volatile uint32_t P66        : 1;
  volatile uint32_t P67        : 1;
  volatile uint32_t P68        : 1;
} stc_gpio_pfr6_field_t;

typedef struct stc_gpio_pfr7_field
{
  volatile uint32_t P70        : 1;
  volatile uint32_t P71        : 1;
  volatile uint32_t P72        : 1;
  volatile uint32_t P73        : 1;
  volatile uint32_t P74        : 1;
} stc_gpio_pfr7_field_t;

typedef struct stc_gpio_pfr8_field
{
  volatile uint32_t P80        : 1;
  volatile uint32_t P81        : 1;
} stc_gpio_pfr8_field_t;

typedef struct stc_gpio_pfre_field
{
  volatile uint32_t PE0        : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t PE2        : 1;
  volatile uint32_t PE3        : 1;
} stc_gpio_pfre_field_t;

typedef struct stc_gpio_pcr0_field
{
  volatile uint32_t P00        : 1;
  volatile uint32_t P01        : 1;
  volatile uint32_t P02        : 1;
  volatile uint32_t P03        : 1;
  volatile uint32_t P04        : 1;
  volatile uint32_t P05        : 1;
  volatile uint32_t P06        : 1;
  volatile uint32_t P07        : 1;
  volatile uint32_t P08        : 1;
  volatile uint32_t P09        : 1;
  volatile uint32_t P0A        : 1;
  volatile uint32_t P0B        : 1;
  volatile uint32_t P0C        : 1;
  volatile uint32_t P0D        : 1;
  volatile uint32_t P0E        : 1;
} stc_gpio_pcr0_field_t;

typedef struct stc_gpio_pcr1_field
{
  volatile uint32_t P10        : 1;
  volatile uint32_t P11        : 1;
  volatile uint32_t P12        : 1;
  volatile uint32_t P13        : 1;
  volatile uint32_t P14        : 1;
  volatile uint32_t P15        : 1;
  volatile uint32_t P16        : 1;
  volatile uint32_t P17        : 1;
  volatile uint32_t P18        : 1;
  volatile uint32_t P19        : 1;
  volatile uint32_t P1A        : 1;
  volatile uint32_t P1B        : 1;
  volatile uint32_t P1C        : 1;
  volatile uint32_t P1D        : 1;
  volatile uint32_t P1E        : 1;
  volatile uint32_t P1F        : 1;
} stc_gpio_pcr1_field_t;

typedef struct stc_gpio_pcr2_field
{
  volatile uint32_t P20        : 1;
  volatile uint32_t P21        : 1;
  volatile uint32_t P22        : 1;
  volatile uint32_t P23        : 1;
  volatile uint32_t P24        : 1;
  volatile uint32_t P25        : 1;
  volatile uint32_t P26        : 1;
  volatile uint32_t P27        : 1;
} stc_gpio_pcr2_field_t;

typedef struct stc_gpio_pcr3_field
{
  volatile uint32_t P30        : 1;
  volatile uint32_t P31        : 1;
  volatile uint32_t P32        : 1;
  volatile uint32_t P33        : 1;
  volatile uint32_t P34        : 1;
  volatile uint32_t P35        : 1;
  volatile uint32_t P36        : 1;
  volatile uint32_t P37        : 1;
  volatile uint32_t P38        : 1;
  volatile uint32_t P39        : 1;
  volatile uint32_t P3A        : 1;
  volatile uint32_t P3B        : 1;
  volatile uint32_t P3C        : 1;
  volatile uint32_t P3D        : 1;
  volatile uint32_t P3E        : 1;
  volatile uint32_t P3F        : 1;
} stc_gpio_pcr3_field_t;

typedef struct stc_gpio_pcr4_field
{
  volatile uint32_t P40        : 1;
  volatile uint32_t P41        : 1;
  volatile uint32_t P42        : 1;
  volatile uint32_t P43        : 1;
  volatile uint32_t P44        : 1;
  volatile uint32_t P45        : 1;
  volatile uint32_t P46        : 1;
  volatile uint32_t P47        : 1;
  volatile uint32_t P48        : 1;
  volatile uint32_t P49        : 1;
  volatile uint32_t P4A        : 1;
  volatile uint32_t P4B        : 1;
  volatile uint32_t P4C        : 1;
  volatile uint32_t P4D        : 1;
  volatile uint32_t P4E        : 1;
} stc_gpio_pcr4_field_t;

typedef struct stc_gpio_pcr5_field
{
  volatile uint32_t P50        : 1;
  volatile uint32_t P51        : 1;
  volatile uint32_t P52        : 1;
  volatile uint32_t P53        : 1;
  volatile uint32_t P54        : 1;
  volatile uint32_t P55        : 1;
  volatile uint32_t P56        : 1;
  volatile uint32_t P57        : 1;
  volatile uint32_t P58        : 1;
  volatile uint32_t P59        : 1;
  volatile uint32_t P5A        : 1;
  volatile uint32_t P5B        : 1;
} stc_gpio_pcr5_field_t;

typedef struct stc_gpio_pcr6_field
{
  volatile uint32_t P60        : 1;
  volatile uint32_t P61        : 1;
  volatile uint32_t P62        : 1;
  volatile uint32_t P63        : 1;
  volatile uint32_t P64        : 1;
  volatile uint32_t P65        : 1;
  volatile uint32_t P66        : 1;
  volatile uint32_t P67        : 1;
  volatile uint32_t P68        : 1;
} stc_gpio_pcr6_field_t;

typedef struct stc_gpio_pcr7_field
{
  volatile uint32_t P70        : 1;
  volatile uint32_t P71        : 1;
  volatile uint32_t P72        : 1;
  volatile uint32_t P73        : 1;
  volatile uint32_t P74        : 1;
} stc_gpio_pcr7_field_t;

typedef struct stc_gpio_pcr8_field
{
  volatile uint32_t P80        : 1;
  volatile uint32_t P81        : 1;
} stc_gpio_pcr8_field_t;

typedef struct stc_gpio_pcre_field
{
  volatile uint32_t PE0        : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t PE2        : 1;
  volatile uint32_t PE3        : 1;
} stc_gpio_pcre_field_t;

typedef struct stc_gpio_ddr0_field
{
  volatile uint32_t P00        : 1;
  volatile uint32_t P01        : 1;
  volatile uint32_t P02        : 1;
  volatile uint32_t P03        : 1;
  volatile uint32_t P04        : 1;
  volatile uint32_t P05        : 1;
  volatile uint32_t P06        : 1;
  volatile uint32_t P07        : 1;
  volatile uint32_t P08        : 1;
  volatile uint32_t P09        : 1;
  volatile uint32_t P0A        : 1;
  volatile uint32_t P0B        : 1;
  volatile uint32_t P0C        : 1;
  volatile uint32_t P0D        : 1;
  volatile uint32_t P0E        : 1;
  volatile uint32_t P0F        : 1;
} stc_gpio_ddr0_field_t;

typedef struct stc_gpio_ddr1_field
{
  volatile uint32_t P10        : 1;
  volatile uint32_t P11        : 1;
  volatile uint32_t P12        : 1;
  volatile uint32_t P13        : 1;
  volatile uint32_t P14        : 1;
  volatile uint32_t P15        : 1;
  volatile uint32_t P16        : 1;
  volatile uint32_t P17        : 1;
  volatile uint32_t P18        : 1;
  volatile uint32_t P19        : 1;
  volatile uint32_t P1A        : 1;
  volatile uint32_t P1B        : 1;
  volatile uint32_t P1C        : 1;
  volatile uint32_t P1D        : 1;
  volatile uint32_t P1E        : 1;
  volatile uint32_t P1F        : 1;
} stc_gpio_ddr1_field_t;

typedef struct stc_gpio_ddr2_field
{
  volatile uint32_t P20        : 1;
  volatile uint32_t P21        : 1;
  volatile uint32_t P22        : 1;
  volatile uint32_t P23        : 1;
  volatile uint32_t P24        : 1;
  volatile uint32_t P25        : 1;
  volatile uint32_t P26        : 1;
  volatile uint32_t P27        : 1;
} stc_gpio_ddr2_field_t;

typedef struct stc_gpio_ddr3_field
{
  volatile uint32_t P30        : 1;
  volatile uint32_t P31        : 1;
  volatile uint32_t P32        : 1;
  volatile uint32_t P33        : 1;
  volatile uint32_t P34        : 1;
  volatile uint32_t P35        : 1;
  volatile uint32_t P36        : 1;
  volatile uint32_t P37        : 1;
  volatile uint32_t P38        : 1;
  volatile uint32_t P39        : 1;
  volatile uint32_t P3A        : 1;
  volatile uint32_t P3B        : 1;
  volatile uint32_t P3C        : 1;
  volatile uint32_t P3D        : 1;
  volatile uint32_t P3E        : 1;
  volatile uint32_t P3F        : 1;
} stc_gpio_ddr3_field_t;

typedef struct stc_gpio_ddr4_field
{
  volatile uint32_t P40        : 1;
  volatile uint32_t P41        : 1;
  volatile uint32_t P42        : 1;
  volatile uint32_t P43        : 1;
  volatile uint32_t P44        : 1;
  volatile uint32_t P45        : 1;
  volatile uint32_t P46        : 1;
  volatile uint32_t P47        : 1;
  volatile uint32_t P48        : 1;
  volatile uint32_t P49        : 1;
  volatile uint32_t P4A        : 1;
  volatile uint32_t P4B        : 1;
  volatile uint32_t P4C        : 1;
  volatile uint32_t P4D        : 1;
  volatile uint32_t P4E        : 1;
} stc_gpio_ddr4_field_t;

typedef struct stc_gpio_ddr5_field
{
  volatile uint32_t P50        : 1;
  volatile uint32_t P51        : 1;
  volatile uint32_t P52        : 1;
  volatile uint32_t P53        : 1;
  volatile uint32_t P54        : 1;
  volatile uint32_t P55        : 1;
  volatile uint32_t P56        : 1;
  volatile uint32_t P57        : 1;
  volatile uint32_t P58        : 1;
  volatile uint32_t P59        : 1;
  volatile uint32_t P5A        : 1;
  volatile uint32_t P5B        : 1;
} stc_gpio_ddr5_field_t;

typedef struct stc_gpio_ddr6_field
{
  volatile uint32_t P60        : 1;
  volatile uint32_t P61        : 1;
  volatile uint32_t P62        : 1;
  volatile uint32_t P63        : 1;
  volatile uint32_t P64        : 1;
  volatile uint32_t P65        : 1;
  volatile uint32_t P66        : 1;
  volatile uint32_t P67        : 1;
  volatile uint32_t P68        : 1;
} stc_gpio_ddr6_field_t;

typedef struct stc_gpio_ddr7_field
{
  volatile uint32_t P70        : 1;
  volatile uint32_t P71        : 1;
  volatile uint32_t P72        : 1;
  volatile uint32_t P73        : 1;
  volatile uint32_t P74        : 1;
} stc_gpio_ddr7_field_t;

typedef struct stc_gpio_ddr8_field
{
  volatile uint32_t P80        : 1;
  volatile uint32_t P81        : 1;
} stc_gpio_ddr8_field_t;

typedef struct stc_gpio_ddre_field
{
  volatile uint32_t PE0        : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t PE2        : 1;
  volatile uint32_t PE3        : 1;
} stc_gpio_ddre_field_t;

typedef struct stc_gpio_pdir0_field
{
  volatile uint32_t P00        : 1;
  volatile uint32_t P01        : 1;
  volatile uint32_t P02        : 1;
  volatile uint32_t P03        : 1;
  volatile uint32_t P04        : 1;
  volatile uint32_t P05        : 1;
  volatile uint32_t P06        : 1;
  volatile uint32_t P07        : 1;
  volatile uint32_t P08        : 1;
  volatile uint32_t P09        : 1;
  volatile uint32_t P0A        : 1;
  volatile uint32_t P0B        : 1;
  volatile uint32_t P0C        : 1;
  volatile uint32_t P0D        : 1;
  volatile uint32_t P0E        : 1;
  volatile uint32_t P0F        : 1;
} stc_gpio_pdir0_field_t;

typedef struct stc_gpio_pdir1_field
{
  volatile uint32_t P10        : 1;
  volatile uint32_t P11        : 1;
  volatile uint32_t P12        : 1;
  volatile uint32_t P13        : 1;
  volatile uint32_t P14        : 1;
  volatile uint32_t P15        : 1;
  volatile uint32_t P16        : 1;
  volatile uint32_t P17        : 1;
  volatile uint32_t P18        : 1;
  volatile uint32_t P19        : 1;
  volatile uint32_t P1A        : 1;
  volatile uint32_t P1B        : 1;
  volatile uint32_t P1C        : 1;
  volatile uint32_t P1D        : 1;
  volatile uint32_t P1E        : 1;
  volatile uint32_t P1F        : 1;
} stc_gpio_pdir1_field_t;

typedef struct stc_gpio_pdir2_field
{
  volatile uint32_t P20        : 1;
  volatile uint32_t P21        : 1;
  volatile uint32_t P22        : 1;
  volatile uint32_t P23        : 1;
  volatile uint32_t P24        : 1;
  volatile uint32_t P25        : 1;
  volatile uint32_t P26        : 1;
  volatile uint32_t P27        : 1;
} stc_gpio_pdir2_field_t;

typedef struct stc_gpio_pdir3_field
{
  volatile uint32_t P30        : 1;
  volatile uint32_t P31        : 1;
  volatile uint32_t P32        : 1;
  volatile uint32_t P33        : 1;
  volatile uint32_t P34        : 1;
  volatile uint32_t P35        : 1;
  volatile uint32_t P36        : 1;
  volatile uint32_t P37        : 1;
  volatile uint32_t P38        : 1;
  volatile uint32_t P39        : 1;
  volatile uint32_t P3A        : 1;
  volatile uint32_t P3B        : 1;
  volatile uint32_t P3C        : 1;
  volatile uint32_t P3D        : 1;
  volatile uint32_t P3E        : 1;
  volatile uint32_t P3F        : 1;
} stc_gpio_pdir3_field_t;

typedef struct stc_gpio_pdir4_field
{
  volatile uint32_t P40        : 1;
  volatile uint32_t P41        : 1;
  volatile uint32_t P42        : 1;
  volatile uint32_t P43        : 1;
  volatile uint32_t P44        : 1;
  volatile uint32_t P45        : 1;
  volatile uint32_t P46        : 1;
  volatile uint32_t P47        : 1;
  volatile uint32_t P48        : 1;
  volatile uint32_t P49        : 1;
  volatile uint32_t P4A        : 1;
  volatile uint32_t P4B        : 1;
  volatile uint32_t P4C        : 1;
  volatile uint32_t P4D        : 1;
  volatile uint32_t P4E        : 1;
} stc_gpio_pdir4_field_t;

typedef struct stc_gpio_pdir5_field
{
  volatile uint32_t P50        : 1;
  volatile uint32_t P51        : 1;
  volatile uint32_t P52        : 1;
  volatile uint32_t P53        : 1;
  volatile uint32_t P54        : 1;
  volatile uint32_t P55        : 1;
  volatile uint32_t P56        : 1;
  volatile uint32_t P57        : 1;
  volatile uint32_t P58        : 1;
  volatile uint32_t P59        : 1;
  volatile uint32_t P5A        : 1;
  volatile uint32_t P5B        : 1;
} stc_gpio_pdir5_field_t;

typedef struct stc_gpio_pdir6_field
{
  volatile uint32_t P60        : 1;
  volatile uint32_t P61        : 1;
  volatile uint32_t P62        : 1;
  volatile uint32_t P63        : 1;
  volatile uint32_t P64        : 1;
  volatile uint32_t P65        : 1;
  volatile uint32_t P66        : 1;
  volatile uint32_t P67        : 1;
  volatile uint32_t P68        : 1;
} stc_gpio_pdir6_field_t;

typedef struct stc_gpio_pdir7_field
{
  volatile uint32_t P70        : 1;
  volatile uint32_t P71        : 1;
  volatile uint32_t P72        : 1;
  volatile uint32_t P73        : 1;
  volatile uint32_t P74        : 1;
} stc_gpio_pdir7_field_t;

typedef struct stc_gpio_pdir8_field
{
  volatile uint32_t P80        : 1;
  volatile uint32_t P81        : 1;
} stc_gpio_pdir8_field_t;

typedef struct stc_gpio_pdire_field
{
  volatile uint32_t PE0        : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t PE2        : 1;
  volatile uint32_t PE3        : 1;
} stc_gpio_pdire_field_t;

typedef struct stc_gpio_pdor0_field
{
  volatile uint32_t P00        : 1;
  volatile uint32_t P01        : 1;
  volatile uint32_t P02        : 1;
  volatile uint32_t P03        : 1;
  volatile uint32_t P04        : 1;
  volatile uint32_t P05        : 1;
  volatile uint32_t P06        : 1;
  volatile uint32_t P07        : 1;
  volatile uint32_t P08        : 1;
  volatile uint32_t P09        : 1;
  volatile uint32_t P0A        : 1;
  volatile uint32_t P0B        : 1;
  volatile uint32_t P0C        : 1;
  volatile uint32_t P0D        : 1;
  volatile uint32_t P0E        : 1;
  volatile uint32_t P0F        : 1;
} stc_gpio_pdor0_field_t;

typedef struct stc_gpio_pdor1_field
{
  volatile uint32_t P10        : 1;
  volatile uint32_t P11        : 1;
  volatile uint32_t P12        : 1;
  volatile uint32_t P13        : 1;
  volatile uint32_t P14        : 1;
  volatile uint32_t P15        : 1;
  volatile uint32_t P16        : 1;
  volatile uint32_t P17        : 1;
  volatile uint32_t P18        : 1;
  volatile uint32_t P19        : 1;
  volatile uint32_t P1A        : 1;
  volatile uint32_t P1B        : 1;
  volatile uint32_t P1C        : 1;
  volatile uint32_t P1D        : 1;
  volatile uint32_t P1E        : 1;
  volatile uint32_t P1F        : 1;
} stc_gpio_pdor1_field_t;

typedef struct stc_gpio_pdor2_field
{
  volatile uint32_t P20        : 1;
  volatile uint32_t P21        : 1;
  volatile uint32_t P22        : 1;
  volatile uint32_t P23        : 1;
  volatile uint32_t P24        : 1;
  volatile uint32_t P25        : 1;
  volatile uint32_t P26        : 1;
  volatile uint32_t P27        : 1;
} stc_gpio_pdor2_field_t;

typedef struct stc_gpio_pdor3_field
{
  volatile uint32_t P30        : 1;
  volatile uint32_t P31        : 1;
  volatile uint32_t P32        : 1;
  volatile uint32_t P33        : 1;
  volatile uint32_t P34        : 1;
  volatile uint32_t P35        : 1;
  volatile uint32_t P36        : 1;
  volatile uint32_t P37        : 1;
  volatile uint32_t P38        : 1;
  volatile uint32_t P39        : 1;
  volatile uint32_t P3A        : 1;
  volatile uint32_t P3B        : 1;
  volatile uint32_t P3C        : 1;
  volatile uint32_t P3D        : 1;
  volatile uint32_t P3E        : 1;
  volatile uint32_t P3F        : 1;
} stc_gpio_pdor3_field_t;

typedef struct stc_gpio_pdor4_field
{
  volatile uint32_t P40        : 1;
  volatile uint32_t P41        : 1;
  volatile uint32_t P42        : 1;
  volatile uint32_t P43        : 1;
  volatile uint32_t P44        : 1;
  volatile uint32_t P45        : 1;
  volatile uint32_t P46        : 1;
  volatile uint32_t P47        : 1;
  volatile uint32_t P48        : 1;
  volatile uint32_t P49        : 1;
  volatile uint32_t P4A        : 1;
  volatile uint32_t P4B        : 1;
  volatile uint32_t P4C        : 1;
  volatile uint32_t P4D        : 1;
  volatile uint32_t P4E        : 1;
} stc_gpio_pdor4_field_t;

typedef struct stc_gpio_pdor5_field
{
  volatile uint32_t P50        : 1;
  volatile uint32_t P51        : 1;
  volatile uint32_t P52        : 1;
  volatile uint32_t P53        : 1;
  volatile uint32_t P54        : 1;
  volatile uint32_t P55        : 1;
  volatile uint32_t P56        : 1;
  volatile uint32_t P57        : 1;
  volatile uint32_t P58        : 1;
  volatile uint32_t P59        : 1;
  volatile uint32_t P5A        : 1;
  volatile uint32_t P5B        : 1;
} stc_gpio_pdor5_field_t;

typedef struct stc_gpio_pdor6_field
{
  volatile uint32_t P60        : 1;
  volatile uint32_t P61        : 1;
  volatile uint32_t P62        : 1;
  volatile uint32_t P63        : 1;
  volatile uint32_t P64        : 1;
  volatile uint32_t P65        : 1;
  volatile uint32_t P66        : 1;
  volatile uint32_t P67        : 1;
  volatile uint32_t P68        : 1;
} stc_gpio_pdor6_field_t;

typedef struct stc_gpio_pdor7_field
{
  volatile uint32_t P70        : 1;
  volatile uint32_t P71        : 1;
  volatile uint32_t P72        : 1;
  volatile uint32_t P73        : 1;
  volatile uint32_t P74        : 1;
} stc_gpio_pdor7_field_t;

typedef struct stc_gpio_pdor8_field
{
  volatile uint32_t P80        : 1;
  volatile uint32_t P81        : 1;
} stc_gpio_pdor8_field_t;

typedef struct stc_gpio_pdore_field
{
  volatile uint32_t PE0        : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t PE2        : 1;
  volatile uint32_t PE3        : 1;
} stc_gpio_pdore_field_t;

typedef struct stc_gpio_ade_field
{
  volatile uint32_t AN0        : 1;
  volatile uint32_t AN1        : 1;
  volatile uint32_t AN2        : 1;
  volatile uint32_t AN3        : 1;
  volatile uint32_t AN4        : 1;
  volatile uint32_t AN5        : 1;
  volatile uint32_t AN6        : 1;
  volatile uint32_t AN7        : 1;
  volatile uint32_t AN8        : 1;
  volatile uint32_t AN9        : 1;
  volatile uint32_t AN10       : 1;
  volatile uint32_t AN11       : 1;
  volatile uint32_t AN12       : 1;
  volatile uint32_t AN13       : 1;
  volatile uint32_t AN14       : 1;
  volatile uint32_t AN15       : 1;
  volatile uint32_t AN16       : 1;
  volatile uint32_t AN17       : 1;
  volatile uint32_t AN18       : 1;
  volatile uint32_t AN19       : 1;
  volatile uint32_t AN20       : 1;
  volatile uint32_t AN21       : 1;
  volatile uint32_t AN22       : 1;
  volatile uint32_t AN23       : 1;
  volatile uint32_t AN24       : 1;
  volatile uint32_t AN25       : 1;
  volatile uint32_t AN26       : 1;
  volatile uint32_t AN27       : 1;
  volatile uint32_t AN28       : 1;
  volatile uint32_t AN29       : 1;
  volatile uint32_t AN30       : 1;
  volatile uint32_t AN31       : 1;
} stc_gpio_ade_field_t;

typedef struct stc_gpio_spsr_field
{
       uint32_t RESERVED0  : 2;
  volatile uint32_t MAINXC     : 2;
  volatile uint32_t USB0C      : 1;
  volatile uint32_t USB1C      : 1;
} stc_gpio_spsr_field_t;

typedef struct stc_gpio_epfr00_field
{
  volatile uint32_t NMIS       : 1;
  volatile uint32_t CROUTE     : 2;
       uint32_t RESERVED3  : 1;
  volatile uint32_t RTCCOE     : 2;
  volatile uint32_t SUBOUTE    : 2;
       uint32_t RESERVED8  : 1;
  volatile uint32_t USBP0E     : 1;
       uint32_t RESERVED10 : 3;
  volatile uint32_t USBP1E     : 1;
       uint32_t RESERVED14 : 2;
  volatile uint32_t JTAGEN0B   : 1;
  volatile uint32_t JTAGEN1S   : 1;
       uint32_t RESERVED18 : 6;
  volatile uint32_t TRC0E      : 1;
  volatile uint32_t TRC1E      : 1;
} stc_gpio_epfr00_field_t;

typedef struct stc_gpio_epfr01_field
{
  volatile uint32_t RTO00E     : 2;
  volatile uint32_t RTO01E     : 2;
  volatile uint32_t RTO02E     : 2;
  volatile uint32_t RTO03E     : 2;
  volatile uint32_t RTO04E     : 2;
  volatile uint32_t RTO05E     : 2;
  volatile uint32_t DTTI0C     : 1;
       uint32_t RESERVED13 : 3;
  volatile uint32_t DTTI0S     : 2;
  volatile uint32_t FRCK0S     : 2;
  volatile uint32_t IC00S      : 3;
  volatile uint32_t IC01S      : 3;
  volatile uint32_t IC02S      : 3;
  volatile uint32_t IC03S      : 3;
} stc_gpio_epfr01_field_t;

typedef struct stc_gpio_epfr02_field
{
  volatile uint32_t RTO10E     : 2;
  volatile uint32_t RTO11E     : 2;
  volatile uint32_t RTO12E     : 2;
  volatile uint32_t RTO13E     : 2;
  volatile uint32_t RTO14E     : 2;
  volatile uint32_t RTO15E     : 2;
  volatile uint32_t DTTI1C     : 1;
       uint32_t RESERVED13 : 3;
  volatile uint32_t DTTI1S     : 2;
  volatile uint32_t FRCK1S     : 2;
  volatile uint32_t IC10S      : 3;
  volatile uint32_t IC11S      : 3;
  volatile uint32_t IC12S      : 3;
  volatile uint32_t IC13S      : 3;
} stc_gpio_epfr02_field_t;

typedef struct stc_gpio_epfr03_field
{
  volatile uint32_t RTO20E     : 2;
  volatile uint32_t RTO21E     : 2;
  volatile uint32_t RTO22E     : 2;
  volatile uint32_t RTO23E     : 2;
  volatile uint32_t RTO24E     : 2;
  volatile uint32_t RTO25E     : 2;
  volatile uint32_t DTTI2C     : 1;
       uint32_t RESERVED13 : 3;
  volatile uint32_t DTTI2S     : 2;
  volatile uint32_t FRCK2S     : 2;
  volatile uint32_t IC20S      : 3;
  volatile uint32_t IC21S      : 3;
  volatile uint32_t IC22S      : 3;
  volatile uint32_t IC23S      : 3;
} stc_gpio_epfr03_field_t;

typedef struct stc_gpio_epfr04_field
{
       uint32_t RESERVED0  : 2;
  volatile uint32_t TIOA0E     : 2;
  volatile uint32_t TIOB0S     : 3;
       uint32_t RESERVED7  : 1;
  volatile uint32_t TIOA1S     : 2;
  volatile uint32_t TIOA1E     : 2;
  volatile uint32_t TIOB1S     : 2;
       uint32_t RESERVED14 : 4;
  volatile uint32_t TIOA2E     : 2;
  volatile uint32_t TIOB2S     : 2;
       uint32_t RESERVED22 : 2;
  volatile uint32_t TIOA3S     : 2;
  volatile uint32_t TIOA3E     : 2;
  volatile uint32_t TIOB3S     : 2;
} stc_gpio_epfr04_field_t;

typedef struct stc_gpio_epfr05_field
{
       uint32_t RESERVED0  : 2;
  volatile uint32_t TIOA4E     : 2;
  volatile uint32_t TIOB4S     : 2;
       uint32_t RESERVED6  : 2;
  volatile uint32_t TIOA5S     : 2;
  volatile uint32_t TIOA5E     : 2;
  volatile uint32_t TIOB5S     : 2;
       uint32_t RESERVED14 : 4;
  volatile uint32_t TIOA6E     : 2;
  volatile uint32_t TIOB6S     : 2;
       uint32_t RESERVED22 : 2;
  volatile uint32_t TIOA7S     : 2;
  volatile uint32_t TIOA7E     : 2;
  volatile uint32_t TIOB7S     : 2;
} stc_gpio_epfr05_field_t;

typedef struct stc_gpio_epfr06_field
{
  volatile uint32_t EINT00S    : 2;
  volatile uint32_t EINT01S    : 2;
  volatile uint32_t EINT02S    : 2;
  volatile uint32_t EINT03S    : 2;
  volatile uint32_t EINT04S    : 2;
  volatile uint32_t EINT05S    : 2;
  volatile uint32_t EINT06S    : 2;
  volatile uint32_t EINT07S    : 2;
  volatile uint32_t EINT08S    : 2;
  volatile uint32_t EINT09S    : 2;
  volatile uint32_t EINT10S    : 2;
  volatile uint32_t EINT11S    : 2;
  volatile uint32_t EINT12S    : 2;
  volatile uint32_t EINT13S    : 2;
  volatile uint32_t EINT14S    : 2;
  volatile uint32_t EINT15S    : 2;
} stc_gpio_epfr06_field_t;

typedef struct stc_gpio_epfr07_field
{
       uint32_t RESERVED0  : 4;
  volatile uint32_t SIN0S      : 2;
  volatile uint32_t SOT0B      : 2;
  volatile uint32_t SCK0B      : 2;
  volatile uint32_t SIN1S      : 2;
  volatile uint32_t SOT1B      : 2;
  volatile uint32_t SCK1B      : 2;
  volatile uint32_t SIN2S      : 2;
  volatile uint32_t SOT2B      : 2;
  volatile uint32_t SCK2B      : 2;
  volatile uint32_t SIN3S      : 2;
  volatile uint32_t SOT3B      : 2;
  volatile uint32_t SCK3B      : 2;
} stc_gpio_epfr07_field_t;

typedef struct stc_gpio_epfr08_field
{
  volatile uint32_t RTS4E      : 2;
  volatile uint32_t CTS4S      : 2;
  volatile uint32_t SIN4S      : 2;
  volatile uint32_t SOT4B      : 2;
  volatile uint32_t SCK4B      : 2;
  volatile uint32_t SIN5S      : 2;
  volatile uint32_t SOT5B      : 2;
  volatile uint32_t SCK5B      : 2;
  volatile uint32_t SIN6S      : 2;
  volatile uint32_t SOT6B      : 2;
  volatile uint32_t SCK6B      : 2;
  volatile uint32_t SIN7S      : 2;
  volatile uint32_t SOT7B      : 2;
  volatile uint32_t SCK7B      : 2;
  volatile uint32_t RTS5E      : 2;
  volatile uint32_t CTS5S      : 2;
} stc_gpio_epfr08_field_t;

typedef struct stc_gpio_epfr09_field
{
  volatile uint32_t QAIN0S     : 2;
  volatile uint32_t QBIN0S     : 2;
  volatile uint32_t QZIN0S     : 2;
  volatile uint32_t QAIN1S     : 2;
  volatile uint32_t QBIN1S     : 2;
  volatile uint32_t QZIN1S     : 2;
  volatile uint32_t ADTRG0S    : 4;
  volatile uint32_t ADTRG1S    : 4;
  volatile uint32_t ADTRG2S    : 4;
  volatile uint32_t CRX0S      : 2;
  volatile uint32_t CTX0E      : 2;
  volatile uint32_t CRX1S      : 2;
  volatile uint32_t CTX1E      : 2;
} stc_gpio_epfr09_field_t;

typedef struct stc_gpio_epfr10_field
{
  volatile uint32_t UEDEFB     : 1;
  volatile uint32_t UEDTHB     : 1;
  volatile uint32_t UECLKE     : 1;
  volatile uint32_t UEWEXE     : 1;
  volatile uint32_t UEDQME     : 1;
  volatile uint32_t UEOEXE     : 1;
  volatile uint32_t UEFLSE     : 1;
  volatile uint32_t UECS1E     : 1;
  volatile uint32_t UECS2E     : 1;
  volatile uint32_t UECS3E     : 1;
  volatile uint32_t UECS4E     : 1;
  volatile uint32_t UECS5E     : 1;
  volatile uint32_t UECS6E     : 1;
  volatile uint32_t UECS7E     : 1;
  volatile uint32_t UEAOOE     : 1;
  volatile uint32_t UEA08E     : 1;
  volatile uint32_t UEA09E     : 1;
  volatile uint32_t UEA10E     : 1;
  volatile uint32_t UEA11E     : 1;
  volatile uint32_t UEA12E     : 1;
  volatile uint32_t UEA13E     : 1;
  volatile uint32_t UEA14E     : 1;
  volatile uint32_t UEA15E     : 1;
  volatile uint32_t UEA16E     : 1;
  volatile uint32_t UEA17E     : 1;
  volatile uint32_t UEA18E     : 1;
  volatile uint32_t UEA19E     : 1;
  volatile uint32_t UEA20E     : 1;
  volatile uint32_t UEA21E     : 1;
  volatile uint32_t UEA22E     : 1;
  volatile uint32_t UEA23E     : 1;
  volatile uint32_t UEA24E     : 1;
} stc_gpio_epfr10_field_t;

typedef struct stc_gpio_epfr11_field
{
  volatile uint32_t UEALEE     : 1;
  volatile uint32_t UECS0E     : 1;
  volatile uint32_t UEA01E     : 1;
  volatile uint32_t UEA02E     : 1;
  volatile uint32_t UEA03E     : 1;
  volatile uint32_t UEA04E     : 1;
  volatile uint32_t UEA05E     : 1;
  volatile uint32_t UEA06E     : 1;
  volatile uint32_t UEA07E     : 1;
  volatile uint32_t UED00B     : 1;
  volatile uint32_t UED01B     : 1;
  volatile uint32_t UED02B     : 1;
  volatile uint32_t UED03B     : 1;
  volatile uint32_t UED04B     : 1;
  volatile uint32_t UED05B     : 1;
  volatile uint32_t UED06B     : 1;
  volatile uint32_t UED07B     : 1;
  volatile uint32_t UED08B     : 1;
  volatile uint32_t UED09B     : 1;
  volatile uint32_t UED10B     : 1;
  volatile uint32_t UED11B     : 1;
  volatile uint32_t UED12B     : 1;
  volatile uint32_t UED13B     : 1;
  volatile uint32_t UED14B     : 1;
  volatile uint32_t UED15B     : 1;
  volatile uint32_t UERLC      : 1;
} stc_gpio_epfr11_field_t;

typedef struct stc_gpio_epfr12_field
{
       uint32_t RESERVED0  : 2;
  volatile uint32_t TIOA8E     : 2;
  volatile uint32_t TIOB8S     : 2;
       uint32_t RESERVED6  : 2;
  volatile uint32_t TIOA9S     : 2;
  volatile uint32_t TIOA9E     : 2;
  volatile uint32_t TIOB9S     : 2;
       uint32_t RESERVED14 : 4;
  volatile uint32_t TIOA10E    : 2;
  volatile uint32_t TIOB10S    : 2;
       uint32_t RESERVED22 : 2;
  volatile uint32_t TIOA11S    : 2;
  volatile uint32_t TIOA11E    : 2;
  volatile uint32_t TIOB11S    : 2;
} stc_gpio_epfr12_field_t;

typedef struct stc_gpio_epfr13_field
{
       uint32_t RESERVED0  : 2;
  volatile uint32_t TIOA12E    : 2;
  volatile uint32_t TIOB12S    : 2;
       uint32_t RESERVED6  : 2;
  volatile uint32_t TIOA13S    : 2;
  volatile uint32_t TIOA13E    : 2;
  volatile uint32_t TIOB13S    : 2;
       uint32_t RESERVED14 : 4;
  volatile uint32_t TIOA14E    : 2;
  volatile uint32_t TIOB14S    : 2;
       uint32_t RESERVED22 : 2;
  volatile uint32_t TIOA15S    : 2;
  volatile uint32_t TIOA15E    : 2;
  volatile uint32_t TIOB15S    : 2;
} stc_gpio_epfr13_field_t;

typedef struct stc_gpio_epfr14_field
{
  volatile uint32_t QAIN2S     : 2;
  volatile uint32_t QBIN2S     : 2;
  volatile uint32_t QZIN2S     : 2;
       uint32_t RESERVED6  :12;
  volatile uint32_t E_TD0E     : 1;
  volatile uint32_t E_TD1E     : 1;
  volatile uint32_t E_TE0E     : 1;
  volatile uint32_t E_TE1E     : 1;
  volatile uint32_t E_MC0E     : 1;
  volatile uint32_t E_MC1B     : 1;
  volatile uint32_t E_MD0B     : 1;
  volatile uint32_t E_MD1B     : 1;
  volatile uint32_t E_CKE      : 1;
  volatile uint32_t E_PSE      : 1;
  volatile uint32_t E_SPLC     : 2;
} stc_gpio_epfr14_field_t;

typedef struct stc_gpio_epfr15_field
{
  volatile uint32_t EINT16S    : 2;
  volatile uint32_t EINT17S    : 2;
  volatile uint32_t EINT18S    : 2;
  volatile uint32_t EINT19S    : 2;
  volatile uint32_t EINT20S    : 2;
  volatile uint32_t EINT21S    : 2;
  volatile uint32_t EINT22S    : 2;
  volatile uint32_t EINT23S    : 2;
  volatile uint32_t EINT24S    : 2;
  volatile uint32_t EINT25S    : 2;
  volatile uint32_t EINT26S    : 2;
  volatile uint32_t EINT27S    : 2;
  volatile uint32_t EINT28S    : 2;
  volatile uint32_t EINT29S    : 2;
  volatile uint32_t EINT30S    : 2;
  volatile uint32_t EINT31S    : 2;
} stc_gpio_epfr15_field_t;

typedef struct stc_gpio_epfr16_field
{
  volatile uint32_t SCS6B      : 2;
  volatile uint32_t SCS7B      : 2;
  volatile uint32_t SIN8S      : 2;
  volatile uint32_t SOT8B      : 2;
  volatile uint32_t SCK8B      : 2;
  volatile uint32_t SIN9S      : 2;
  volatile uint32_t SOT9B      : 2;
  volatile uint32_t SCK9B      : 2;
  volatile uint32_t SIN10S     : 2;
  volatile uint32_t SOT10B     : 2;
  volatile uint32_t SCK10B     : 2;
  volatile uint32_t SIN11S     : 2;
  volatile uint32_t SOT11B     : 2;
  volatile uint32_t SCK11B     : 2;
  volatile uint32_t SFMPAC     : 1;
  volatile uint32_t SFMPBC     : 1;
} stc_gpio_epfr16_field_t;

typedef struct stc_gpio_epfr17_field
{
       uint32_t RESERVED0  : 4;
  volatile uint32_t SIN12S     : 2;
  volatile uint32_t SOT12B     : 2;
  volatile uint32_t SCK12B     : 2;
  volatile uint32_t SIN13S     : 2;
  volatile uint32_t SOT13B     : 2;
  volatile uint32_t SCK13B     : 2;
  volatile uint32_t SIN14S     : 2;
  volatile uint32_t SOT14B     : 2;
  volatile uint32_t SCK14B     : 2;
  volatile uint32_t SIN15S     : 2;
  volatile uint32_t SOT15B     : 2;
  volatile uint32_t SCK15B     : 2;
} stc_gpio_epfr17_field_t;

typedef struct stc_gpio_epfr18_field
{
       uint32_t RESERVED0  : 4;
  volatile uint32_t QAIN3S     : 2;
  volatile uint32_t QBIN3S     : 2;
  volatile uint32_t QZIN3S     : 2;
       uint32_t RESERVED10 : 4;
  volatile uint32_t SDCLKE     : 2;
  volatile uint32_t SDCMDB     : 2;
  volatile uint32_t SDDATA0B   : 2;
  volatile uint32_t SDDATA1B   : 2;
  volatile uint32_t SDDATA2B   : 2;
  volatile uint32_t SDDATA3B   : 2;
  volatile uint32_t SDCDS      : 2;
  volatile uint32_t SDWPS      : 2;
} stc_gpio_epfr18_field_t;

typedef struct stc_gpio_epfr20_field
{
  volatile uint32_t UESMCE     : 1;
  volatile uint32_t UESMCKE    : 1;
  volatile uint32_t UERASE     : 1;
  volatile uint32_t UECASE     : 1;
  volatile uint32_t UEDWEXE    : 1;
  volatile uint32_t UECSXE     : 1;
  volatile uint32_t UEDQM2E    : 1;
  volatile uint32_t UEDQM3E    : 1;
  volatile uint32_t UEDTHHB    : 1;
  volatile uint32_t UED16B     : 1;
  volatile uint32_t UED17B     : 1;
  volatile uint32_t UED18B     : 1;
  volatile uint32_t UED19B     : 1;
  volatile uint32_t UED20B     : 1;
  volatile uint32_t UED21B     : 1;
  volatile uint32_t UED22B     : 1;
  volatile uint32_t UED23B     : 1;
  volatile uint32_t UED24B     : 1;
  volatile uint32_t UED25B     : 1;
  volatile uint32_t UED26B     : 1;
  volatile uint32_t UED27B     : 1;
  volatile uint32_t UED28B     : 1;
  volatile uint32_t UED29B     : 1;
  volatile uint32_t UED30B     : 1;
  volatile uint32_t UED31B     : 1;
} stc_gpio_epfr20_field_t;

typedef struct stc_gpio_pzr0_field
{
  volatile uint32_t P00        : 1;
  volatile uint32_t P01        : 1;
  volatile uint32_t P02        : 1;
  volatile uint32_t P03        : 1;
  volatile uint32_t P04        : 1;
  volatile uint32_t P05        : 1;
  volatile uint32_t P06        : 1;
  volatile uint32_t P07        : 1;
  volatile uint32_t P08        : 1;
  volatile uint32_t P09        : 1;
  volatile uint32_t P0A        : 1;
  volatile uint32_t P0B        : 1;
  volatile uint32_t P0C        : 1;
  volatile uint32_t P0D        : 1;
  volatile uint32_t P0E        : 1;
  volatile uint32_t P0F        : 1;
} stc_gpio_pzr0_field_t;

typedef struct stc_gpio_pzr1_field
{
  volatile uint32_t P10        : 1;
  volatile uint32_t P11        : 1;
  volatile uint32_t P12        : 1;
  volatile uint32_t P13        : 1;
  volatile uint32_t P14        : 1;
  volatile uint32_t P15        : 1;
  volatile uint32_t P16        : 1;
  volatile uint32_t P17        : 1;
  volatile uint32_t P18        : 1;
  volatile uint32_t P19        : 1;
  volatile uint32_t P1A        : 1;
  volatile uint32_t P1B        : 1;
  volatile uint32_t P1C        : 1;
  volatile uint32_t P1D        : 1;
  volatile uint32_t P1E        : 1;
  volatile uint32_t P1F        : 1;
} stc_gpio_pzr1_field_t;

typedef struct stc_gpio_pzr2_field
{
  volatile uint32_t P20        : 1;
  volatile uint32_t P21        : 1;
  volatile uint32_t P22        : 1;
  volatile uint32_t P23        : 1;
  volatile uint32_t P24        : 1;
  volatile uint32_t P25        : 1;
  volatile uint32_t P26        : 1;
  volatile uint32_t P27        : 1;
} stc_gpio_pzr2_field_t;

typedef struct stc_gpio_pzr3_field
{
  volatile uint32_t P30        : 1;
  volatile uint32_t P31        : 1;
  volatile uint32_t P32        : 1;
  volatile uint32_t P33        : 1;
  volatile uint32_t P34        : 1;
  volatile uint32_t P35        : 1;
  volatile uint32_t P36        : 1;
  volatile uint32_t P37        : 1;
  volatile uint32_t P38        : 1;
  volatile uint32_t P39        : 1;
  volatile uint32_t P3A        : 1;
  volatile uint32_t P3B        : 1;
  volatile uint32_t P3C        : 1;
  volatile uint32_t P3D        : 1;
  volatile uint32_t P3E        : 1;
  volatile uint32_t P3F        : 1;
} stc_gpio_pzr3_field_t;

typedef struct stc_gpio_pzr4_field
{
  volatile uint32_t P40        : 1;
  volatile uint32_t P41        : 1;
  volatile uint32_t P42        : 1;
  volatile uint32_t P43        : 1;
  volatile uint32_t P44        : 1;
  volatile uint32_t P45        : 1;
  volatile uint32_t P46        : 1;
  volatile uint32_t P47        : 1;
  volatile uint32_t P48        : 1;
  volatile uint32_t P49        : 1;
  volatile uint32_t P4A        : 1;
  volatile uint32_t P4B        : 1;
  volatile uint32_t P4C        : 1;
  volatile uint32_t P4D        : 1;
  volatile uint32_t P4E        : 1;
} stc_gpio_pzr4_field_t;

typedef struct stc_gpio_pzr5_field
{
  volatile uint32_t P50        : 1;
  volatile uint32_t P51        : 1;
  volatile uint32_t P52        : 1;
  volatile uint32_t P53        : 1;
  volatile uint32_t P54        : 1;
  volatile uint32_t P55        : 1;
  volatile uint32_t P56        : 1;
  volatile uint32_t P57        : 1;
  volatile uint32_t P58        : 1;
  volatile uint32_t P59        : 1;
  volatile uint32_t P5A        : 1;
  volatile uint32_t P5B        : 1;
} stc_gpio_pzr5_field_t;

typedef struct stc_gpio_pzr6_field
{
  volatile uint32_t P60        : 1;
  volatile uint32_t P61        : 1;
  volatile uint32_t P62        : 1;
  volatile uint32_t P63        : 1;
  volatile uint32_t P64        : 1;
  volatile uint32_t P65        : 1;
  volatile uint32_t P66        : 1;
  volatile uint32_t P67        : 1;
  volatile uint32_t P68        : 1;
} stc_gpio_pzr6_field_t;

typedef struct stc_gpio_pzr7_field
{
  volatile uint32_t P70        : 1;
  volatile uint32_t P71        : 1;
  volatile uint32_t P72        : 1;
  volatile uint32_t P73        : 1;
  volatile uint32_t P74        : 1;
} stc_gpio_pzr7_field_t;

typedef struct stc_gpio_pzr8_field
{
  volatile uint32_t P80        : 1;
  volatile uint32_t P81        : 1;
} stc_gpio_pzr8_field_t;

typedef struct stc_gpio_pzre_field
{
  volatile uint32_t PE0        : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t PE2        : 1;
  volatile uint32_t PE3        : 1;
} stc_gpio_pzre_field_t;



 
 
typedef struct stc_lvd_lvd_ctl_field
{
  union {
    struct {
            uint8_t RESERVED1  : 2;
      volatile  uint8_t SVHI       : 5;
      volatile  uint8_t LVDIE      : 1;
    };
    struct {
            uint8_t RESERVED3  : 2;
      volatile  uint8_t SVHI0      : 1;
      volatile  uint8_t SVHI1      : 1;
      volatile  uint8_t SVHI2      : 1;
      volatile  uint8_t SVHI3      : 1;
      volatile  uint8_t SVHI4      : 1;
            uint8_t RESERVED4  : 1;
    };
  };
} stc_lvd_lvd_ctl_field_t;

typedef struct stc_lvd_lvd_str_field
{
        uint8_t RESERVED1  : 7;
  volatile  uint8_t LVDIR      : 1;
} stc_lvd_lvd_str_field_t;

typedef struct stc_lvd_lvd_clr_field
{
        uint8_t RESERVED1  : 7;
  volatile  uint8_t LVDCL      : 1;
} stc_lvd_lvd_clr_field_t;

typedef struct stc_lvd_lvd_str2_field
{
        uint8_t RESERVED1  : 6;
  volatile  uint8_t LVDRRDY    : 1;
  volatile  uint8_t LVDIRDY    : 1;
} stc_lvd_lvd_str2_field_t;



 
 
typedef struct stc_ds_rck_ctl_field
{
  volatile  uint8_t RTCCKE     : 1;
} stc_ds_rck_ctl_field_t;

typedef struct stc_ds_pmd_ctl_field
{
  volatile  uint8_t RTCE       : 1;
} stc_ds_pmd_ctl_field_t;

typedef struct stc_ds_wrfsr_field
{
  volatile  uint8_t WINITX     : 1;
  volatile  uint8_t WLVDH      : 1;
} stc_ds_wrfsr_field_t;

typedef struct stc_ds_wifsr_field
{
  volatile uint16_t WRTCI      : 1;
  volatile uint16_t WLVDI      : 1;
  volatile uint16_t WUI0       : 1;
  volatile uint16_t WUI1       : 1;
  volatile uint16_t WUI2       : 1;
  volatile uint16_t WUI3       : 1;
  volatile uint16_t WUI4       : 1;
  volatile uint16_t WUI5       : 1;
} stc_ds_wifsr_field_t;

typedef struct stc_ds_wier_field
{
  volatile uint16_t WRTCE      : 1;
  volatile uint16_t WLVDE      : 1;
       uint16_t RESERVED2  : 1;
  volatile uint16_t WUI1E      : 1;
  volatile uint16_t WUI2E      : 1;
  volatile uint16_t WUI3E      : 1;
  volatile uint16_t WUI4E      : 1;
  volatile uint16_t WUI5E      : 1;
} stc_ds_wier_field_t;

typedef struct stc_ds_wilvr_field
{
  volatile  uint8_t WUI1LV     : 1;
  volatile  uint8_t WUI2LV     : 1;
  volatile  uint8_t WUI3LV     : 1;
  volatile  uint8_t WUI4LV     : 1;
  volatile  uint8_t WUI5LV     : 1;
} stc_ds_wilvr_field_t;

typedef struct stc_ds_dsramr_field
{
  volatile  uint8_t SRAMR      : 2;
} stc_ds_dsramr_field_t;



 
 
typedef struct stc_usbethernetclk_uccr_field
{
  volatile  uint8_t UCEN0      : 1;
  volatile  uint8_t UCSEL0     : 1;
  volatile  uint8_t UCSEL1     : 1;
  volatile  uint8_t UCEN1      : 1;
  volatile  uint8_t ECEN       : 1;
  volatile  uint8_t ECSEL0     : 1;
  volatile  uint8_t ECSEL1     : 1;
} stc_usbethernetclk_uccr_field_t;

typedef struct stc_usbethernetclk_upcr1_field
{
  volatile  uint8_t UPLLEN     : 1;
  volatile  uint8_t UPINC      : 1;
} stc_usbethernetclk_upcr1_field_t;

typedef struct stc_usbethernetclk_upcr2_field
{
  volatile  uint8_t UPOWT0     : 1;
  volatile  uint8_t UPOWT1     : 1;
  volatile  uint8_t UPOWT2     : 1;
} stc_usbethernetclk_upcr2_field_t;

typedef struct stc_usbethernetclk_upcr3_field
{
  volatile  uint8_t UPLLK0     : 1;
  volatile  uint8_t UPLLK1     : 1;
  volatile  uint8_t UPLLK2     : 1;
  volatile  uint8_t UPLLK3     : 1;
  volatile  uint8_t UPLLK4     : 1;
} stc_usbethernetclk_upcr3_field_t;

typedef struct stc_usbethernetclk_upcr4_field
{
  volatile  uint8_t UPLLN0     : 1;
  volatile  uint8_t UPLLN1     : 1;
  volatile  uint8_t UPLLN2     : 1;
  volatile  uint8_t UPLLN3     : 1;
  volatile  uint8_t UPLLN4     : 1;
  volatile  uint8_t UPLLN5     : 1;
  volatile  uint8_t UPLLN6     : 1;
} stc_usbethernetclk_upcr4_field_t;

typedef struct stc_usbethernetclk_up_str_field
{
  volatile  uint8_t UPRDY      : 1;
} stc_usbethernetclk_up_str_field_t;

typedef struct stc_usbethernetclk_upint_enr_field
{
  volatile  uint8_t UPCSE      : 1;
} stc_usbethernetclk_upint_enr_field_t;

typedef struct stc_usbethernetclk_upint_clr_field
{
  volatile  uint8_t UPCSC      : 1;
} stc_usbethernetclk_upint_clr_field_t;

typedef struct stc_usbethernetclk_upint_str_field
{
  volatile  uint8_t UPCSI      : 1;
} stc_usbethernetclk_upint_str_field_t;

typedef struct stc_usbethernetclk_upcr5_field
{
  volatile  uint8_t UPLLM0     : 1;
  volatile  uint8_t UPLLM1     : 1;
  volatile  uint8_t UPLLM2     : 1;
  volatile  uint8_t UPLLM3     : 1;
} stc_usbethernetclk_upcr5_field_t;

typedef struct stc_usbethernetclk_upcr6_field
{
  volatile  uint8_t UBSR0      : 1;
  volatile  uint8_t UBSR1      : 1;
  volatile  uint8_t UBSR2      : 1;
  volatile  uint8_t UBSR3      : 1;
} stc_usbethernetclk_upcr6_field_t;

typedef struct stc_usbethernetclk_upcr7_field
{
  volatile  uint8_t EPLLEN     : 1;
} stc_usbethernetclk_upcr7_field_t;

typedef struct stc_usbethernetclk_usben0_field
{
  volatile  uint8_t USBEN0     : 1;
} stc_usbethernetclk_usben0_field_t;

typedef struct stc_usbethernetclk_usben1_field
{
  volatile  uint8_t USBEN1     : 1;
} stc_usbethernetclk_usben1_field_t;




 
 






























































  



 
 
typedef struct stc_canpre_canpre_field
{
  volatile  uint8_t CANPRE0    : 1;
  volatile  uint8_t CANPRE1    : 1;
  volatile  uint8_t CANPRE2    : 1;
  volatile  uint8_t CANPRE3    : 1;
} stc_canpre_canpre_field_t;



 
 
typedef struct stc_mfs_smr_field
{
  union {
    struct {
      volatile  uint8_t SOE        : 1;  
            uint8_t RESERVED1  : 1;
      volatile  uint8_t BDS        : 1;  
      volatile  uint8_t SBL        : 1;  
      volatile  uint8_t WUCR       : 1;  
      volatile  uint8_t MD         : 3;  
    };
    struct {
            uint8_t RESERVED2  : 1;
      volatile  uint8_t SCKE       : 1;  
            uint8_t RESERVED3  : 1;
      volatile  uint8_t SCINV      : 1;  
            uint8_t RESERVED4  : 4;
    };
    struct {
            uint8_t RESERVED5  : 2;
      volatile  uint8_t TIE        : 1;  
      volatile  uint8_t RIE        : 1;  
            uint8_t RESERVED6  : 4;
    };
  };
} stc_mfs_smr_field_t;

typedef struct stc_mfs_scr_field
{
  union {
    struct {
      volatile  uint8_t TXE        : 1;  
      volatile  uint8_t RXE        : 1;  
      volatile  uint8_t TBIE       : 1;  
      volatile  uint8_t TIE        : 1;  
      volatile  uint8_t RIE        : 1;  
            uint8_t RESERVED1  : 2;
      volatile  uint8_t UPCL       : 1;  
    };
    struct {
            uint8_t RESERVED2  : 5;
      volatile  uint8_t SPI        : 1;  
      volatile  uint8_t MS         : 1;  
            uint8_t RESERVED3  : 1;
    };
    struct {
            uint8_t RESERVED4  : 5;
      volatile  uint8_t LBR        : 1;  
            uint8_t RESERVED5  : 2;
    };
  };
} stc_mfs_scr_field_t;

typedef struct stc_mfs_escr_field
{
  union {
    struct {
      volatile  uint8_t L          : 3;  
      volatile  uint8_t P          : 1;  
      volatile  uint8_t PEN        : 1;  
      volatile  uint8_t INV        : 1;  
      volatile  uint8_t ESBL       : 1;  
      volatile  uint8_t FLWEN      : 1;  
    };
    struct {
      volatile  uint8_t L0         : 1;  
      volatile  uint8_t L1         : 1;  
      volatile  uint8_t L2         : 1;  
      volatile  uint8_t WT         : 2;  
            uint8_t RESERVED2  : 1;
      volatile  uint8_t L3         : 1;  
      volatile  uint8_t SOP        : 1;  
    };
    struct {
            uint8_t RESERVED3  : 3;
      volatile  uint8_t WT0        : 1;  
      volatile  uint8_t WT1        : 1;  
            uint8_t RESERVED4  : 3;
    };
    struct {
      volatile  uint8_t DEL        : 2;  
      volatile  uint8_t LBL        : 2;  
      volatile  uint8_t LBIE       : 1;  
            uint8_t RESERVED5  : 3;
    };
    struct {
      volatile  uint8_t DEL0       : 1;  
      volatile  uint8_t DEL1       : 1;  
      volatile  uint8_t LBL0       : 1;  
      volatile  uint8_t LBL1       : 1;  
            uint8_t RESERVED6  : 4;
    };
  };
} stc_mfs_escr_field_t;

typedef struct stc_mfs_ssr_field
{
  union {
    struct {
      volatile  uint8_t TBI        : 1;  
      volatile  uint8_t TDRE       : 1;  
      volatile  uint8_t RDRF       : 1;  
      volatile  uint8_t ORE        : 1;  
      volatile  uint8_t FRE        : 1;  
      volatile  uint8_t PE         : 1;  
            uint8_t RESERVED1  : 1;
      volatile  uint8_t REC        : 1;  
    };
    struct {
            uint8_t RESERVED2  : 4;
      volatile  uint8_t AWC        : 1;  
            uint8_t RESERVED3  : 3;
    };
    struct {
            uint8_t RESERVED4  : 5;
      volatile  uint8_t LBD        : 1;  
            uint8_t RESERVED5  : 2;
    };
    struct {
            uint8_t RESERVED6  : 4;
      volatile  uint8_t TBIE       : 1;  
      volatile  uint8_t DMA        : 1;  
      volatile  uint8_t TSET       : 1;  
            uint8_t RESERVED7  : 1;
    };
  };
} stc_mfs_ssr_field_t;

typedef struct stc_mfs_bgr_field
{
       uint16_t RESERVED1  : 15;
  volatile uint16_t EXT        : 1;
} stc_mfs_bgr_field_t;

typedef struct stc_mfs_bgr1_field
{
        uint8_t RESERVED1  : 7;
  volatile  uint8_t EXT        : 1;
} stc_mfs_bgr1_field_t;

typedef struct stc_mfs_fcr_field
{
  volatile uint16_t FE1        : 1;
  volatile uint16_t FE2        : 1;
  volatile uint16_t FCL1       : 1;
  volatile uint16_t FCL2       : 1;
  volatile uint16_t FSET       : 1;
  volatile uint16_t FLD        : 1;
  volatile uint16_t FLST       : 1;
       uint16_t RESERVED1  : 1;
  volatile uint16_t FSEL       : 1;
  volatile uint16_t FTIE       : 1;
  volatile uint16_t FDRQ       : 1;
  volatile uint16_t FRIIE      : 1;
  volatile uint16_t FLSTE      : 1;
       uint16_t RESERVED2  : 1;
  volatile uint16_t FTST0      : 1;
  volatile uint16_t FTST1      : 1;
} stc_mfs_fcr_field_t;

typedef struct stc_mfs_fcr0_field
{
  volatile  uint8_t FE1        : 1;
  volatile  uint8_t FE2        : 1;
  volatile  uint8_t FCL1       : 1;
  volatile  uint8_t FCL2       : 1;
  volatile  uint8_t FSET       : 1;
  volatile  uint8_t FLD        : 1;
  volatile  uint8_t FLST       : 1;
        uint8_t RESERVED1  : 1;
} stc_mfs_fcr0_field_t;

typedef struct stc_mfs_fcr1_field
{
  volatile  uint8_t FSEL       : 1;
  volatile  uint8_t FTIE       : 1;
  volatile  uint8_t FDRQ       : 1;
  volatile  uint8_t FRIIE      : 1;
  volatile  uint8_t FLSTE      : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t FTST0      : 1;
  volatile  uint8_t FTST1      : 1;
} stc_mfs_fcr1_field_t;

typedef struct stc_mfs_fbyte_field
{
  volatile uint16_t FD0        : 1;
  volatile uint16_t FD1        : 1;
  volatile uint16_t FD2        : 1;
  volatile uint16_t FD3        : 1;
  volatile uint16_t FD4        : 1;
  volatile uint16_t FD5        : 1;
  volatile uint16_t FD6        : 1;
  volatile uint16_t FD7        : 1;
  volatile uint16_t FD8        : 1;
  volatile uint16_t FD9        : 1;
  volatile uint16_t FD10       : 1;
  volatile uint16_t FD11       : 1;
  volatile uint16_t FD12       : 1;
  volatile uint16_t FD13       : 1;
  volatile uint16_t FD14       : 1;
  volatile uint16_t FD15       : 1;
} stc_mfs_fbyte_field_t;

typedef struct stc_mfs_fbyte1_field
{
  volatile  uint8_t FD0        : 1;
  volatile  uint8_t FD1        : 1;
  volatile  uint8_t FD2        : 1;
  volatile  uint8_t FD3        : 1;
  volatile  uint8_t FD4        : 1;
  volatile  uint8_t FD5        : 1;
  volatile  uint8_t FD6        : 1;
  volatile  uint8_t FD7        : 1;
} stc_mfs_fbyte1_field_t;

typedef struct stc_mfs_fbyte2_field
{
  volatile  uint8_t FD8        : 1;
  volatile  uint8_t FD9        : 1;
  volatile  uint8_t FD10       : 1;
  volatile  uint8_t FD11       : 1;
  volatile  uint8_t FD12       : 1;
  volatile  uint8_t FD13       : 1;
  volatile  uint8_t FD14       : 1;
  volatile  uint8_t FD15       : 1;
} stc_mfs_fbyte2_field_t;



 
 
typedef struct stc_mfs_uart_rdr_field
{
       uint16_t RESERVED1  : 8;
  volatile uint16_t AD         : 1;
       uint16_t RESERVED2  : 7;
} stc_mfs_uart_rdr_field_t;

typedef struct stc_mfs_uart_tdr_field
{
       uint16_t RESERVED1  : 8;
  volatile uint16_t AD         : 1;
       uint16_t RESERVED2  : 7;
} stc_mfs_uart_tdr_field_t;



 
 
typedef struct stc_mfs_csio_scstr10_field
{
  volatile uint16_t CSHD0      : 1;
  volatile uint16_t CSHD1      : 1;
  volatile uint16_t CSHD2      : 1;
  volatile uint16_t CSHD3      : 1;
  volatile uint16_t CSHD4      : 1;
  volatile uint16_t CSHD5      : 1;
  volatile uint16_t CSHD6      : 1;
  volatile uint16_t CSHD7      : 1;
  volatile uint16_t CSSU0      : 1;
  volatile uint16_t CSSU1      : 1;
  volatile uint16_t CSSU2      : 1;
  volatile uint16_t CSSU3      : 1;
  volatile uint16_t CSSU4      : 1;
  volatile uint16_t CSSU5      : 1;
  volatile uint16_t CSSU6      : 1;
  volatile uint16_t CSSU7      : 1;
} stc_mfs_csio_scstr10_field_t;

typedef struct stc_mfs_csio_scstr0_field
{
  volatile  uint8_t CSHD0      : 1;
  volatile  uint8_t CSHD1      : 1;
  volatile  uint8_t CSHD2      : 1;
  volatile  uint8_t CSHD3      : 1;
  volatile  uint8_t CSHD4      : 1;
  volatile  uint8_t CSHD5      : 1;
  volatile  uint8_t CSHD6      : 1;
  volatile  uint8_t CSHD7      : 1;
} stc_mfs_csio_scstr0_field_t;

typedef struct stc_mfs_csio_scstr1_field
{
  volatile  uint8_t CSSU0      : 1;
  volatile  uint8_t CSSU1      : 1;
  volatile  uint8_t CSSU2      : 1;
  volatile  uint8_t CSSU3      : 1;
  volatile  uint8_t CSSU4      : 1;
  volatile  uint8_t CSSU5      : 1;
  volatile  uint8_t CSSU6      : 1;
  volatile  uint8_t CSSU7      : 1;
} stc_mfs_csio_scstr1_field_t;

typedef struct stc_mfs_csio_scstr32_field
{
  volatile uint16_t CSDS0      : 1;
  volatile uint16_t CSDS1      : 1;
  volatile uint16_t CSDS2      : 1;
  volatile uint16_t CSDS3      : 1;
  volatile uint16_t CSDS4      : 1;
  volatile uint16_t CSDS5      : 1;
  volatile uint16_t CSDS6      : 1;
  volatile uint16_t CSDS7      : 1;
  volatile uint16_t CSDS8      : 1;
  volatile uint16_t CSDS9      : 1;
  volatile uint16_t CSDS10     : 1;
  volatile uint16_t CSDS11     : 1;
  volatile uint16_t CSDS12     : 1;
  volatile uint16_t CSDS13     : 1;
  volatile uint16_t CSDS14     : 1;
  volatile uint16_t CSDS15     : 1;
} stc_mfs_csio_scstr32_field_t;

typedef struct stc_mfs_csio_scstr2_field
{
  volatile  uint8_t CSDS0      : 1;
  volatile  uint8_t CSDS1      : 1;
  volatile  uint8_t CSDS2      : 1;
  volatile  uint8_t CSDS3      : 1;
  volatile  uint8_t CSDS4      : 1;
  volatile  uint8_t CSDS5      : 1;
  volatile  uint8_t CSDS6      : 1;
  volatile  uint8_t CSDS7      : 1;
} stc_mfs_csio_scstr2_field_t;

typedef struct stc_mfs_csio_scstr3_field
{
  volatile  uint8_t CSDS8      : 1;
  volatile  uint8_t CSDS9      : 1;
  volatile  uint8_t CSDS10     : 1;
  volatile  uint8_t CSDS11     : 1;
  volatile  uint8_t CSDS12     : 1;
  volatile  uint8_t CSDS13     : 1;
  volatile  uint8_t CSDS14     : 1;
  volatile  uint8_t CSDS15     : 1;
} stc_mfs_csio_scstr3_field_t;

typedef struct stc_mfs_csio_sacsr_field
{
  volatile uint16_t TMRE       : 1;
  volatile uint16_t TDIV       : 4;
       uint16_t RESERVED1  : 1;
  volatile uint16_t TSYNE      : 1;
  volatile uint16_t TINTE      : 1;
  volatile uint16_t TINT       : 1;
       uint16_t RESERVED2  : 2;
  volatile uint16_t CSE        : 1;
  volatile uint16_t CSEIE      : 1;
  volatile uint16_t TBEEN      : 1;
       uint16_t RESERVED3  : 2;
} stc_mfs_csio_sacsr_field_t;

typedef struct stc_mfs_csio_sacsr0_field
{
  volatile  uint8_t TMRE       : 1;
  volatile  uint8_t TDIV       : 4;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t TSYNE      : 1;
  volatile  uint8_t TINTE      : 1;
} stc_mfs_csio_sacsr0_field_t;

typedef struct stc_mfs_csio_sacsr1_field
{
  volatile  uint8_t TINT       : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t CSE        : 1;
  volatile  uint8_t CSEIE      : 1;
  volatile  uint8_t TBEEN      : 1;
        uint8_t RESERVED2  : 2;
} stc_mfs_csio_sacsr1_field_t;

typedef struct stc_mfs_csio_stmr_field
{
  volatile uint16_t TM0        : 1;
  volatile uint16_t TM1        : 1;
  volatile uint16_t TM2        : 1;
  volatile uint16_t TM3        : 1;
  volatile uint16_t TM4        : 1;
  volatile uint16_t TM5        : 1;
  volatile uint16_t TM6        : 1;
  volatile uint16_t TM7        : 1;
  volatile uint16_t TM8        : 1;
  volatile uint16_t TM9        : 1;
  volatile uint16_t TM10       : 1;
  volatile uint16_t TM11       : 1;
  volatile uint16_t TM12       : 1;
  volatile uint16_t TM13       : 1;
  volatile uint16_t TM14       : 1;
  volatile uint16_t TM15       : 1;
} stc_mfs_csio_stmr_field_t;

typedef struct stc_mfs_csio_stmr0_field
{
  volatile  uint8_t TM0        : 1;
  volatile  uint8_t TM1        : 1;
  volatile  uint8_t TM2        : 1;
  volatile  uint8_t TM3        : 1;
  volatile  uint8_t TM4        : 1;
  volatile  uint8_t TM5        : 1;
  volatile  uint8_t TM6        : 1;
  volatile  uint8_t TM7        : 1;
} stc_mfs_csio_stmr0_field_t;

typedef struct stc_mfs_csio_stmr1_field
{
  volatile  uint8_t TM8        : 1;
  volatile  uint8_t TM9        : 1;
  volatile  uint8_t TM10       : 1;
  volatile  uint8_t TM11       : 1;
  volatile  uint8_t TM12       : 1;
  volatile  uint8_t TM13       : 1;
  volatile  uint8_t TM14       : 1;
  volatile  uint8_t TM15       : 1;
} stc_mfs_csio_stmr1_field_t;

typedef struct stc_mfs_csio_stmcr_field
{
  volatile uint16_t TC0        : 1;
  volatile uint16_t TC1        : 1;
  volatile uint16_t TC2        : 1;
  volatile uint16_t TC3        : 1;
  volatile uint16_t TC4        : 1;
  volatile uint16_t TC5        : 1;
  volatile uint16_t TC6        : 1;
  volatile uint16_t TC7        : 1;
  volatile uint16_t TC8        : 1;
  volatile uint16_t TC9        : 1;
  volatile uint16_t TC10       : 1;
  volatile uint16_t TC11       : 1;
  volatile uint16_t TC12       : 1;
  volatile uint16_t TC13       : 1;
  volatile uint16_t TC14       : 1;
  volatile uint16_t TC15       : 1;
} stc_mfs_csio_stmcr_field_t;

typedef struct stc_mfs_csio_stmcr0_field
{
  volatile  uint8_t TC0        : 1;
  volatile  uint8_t TC1        : 1;
  volatile  uint8_t TC2        : 1;
  volatile  uint8_t TC3        : 1;
  volatile  uint8_t TC4        : 1;
  volatile  uint8_t TC5        : 1;
  volatile  uint8_t TC6        : 1;
  volatile  uint8_t TC7        : 1;
} stc_mfs_csio_stmcr0_field_t;

typedef struct stc_mfs_csio_stmcr1_field
{
  volatile  uint8_t TC8        : 1;
  volatile  uint8_t TC9        : 1;
  volatile  uint8_t TC10       : 1;
  volatile  uint8_t TC11       : 1;
  volatile  uint8_t TC12       : 1;
  volatile  uint8_t TC13       : 1;
  volatile  uint8_t TC14       : 1;
  volatile  uint8_t TC15       : 1;
} stc_mfs_csio_stmcr1_field_t;

typedef struct stc_mfs_csio_scscr_field
{
  volatile uint16_t CSOE       : 1;
  volatile uint16_t CSEN0      : 1;
       uint16_t RESERVED1  : 3;
  volatile uint16_t CSLVL      : 1;
  volatile uint16_t CDIV       : 3;
  volatile uint16_t SCAM       : 1;
       uint16_t RESERVED2  : 6;
} stc_mfs_csio_scscr_field_t;



 
 
typedef struct stc_mfs_i2c_ibcr_field
{
  volatile  uint8_t INT        : 1;
  volatile  uint8_t BER        : 1;
  volatile  uint8_t INTE       : 1;
  volatile  uint8_t CNDE       : 1;
  volatile  uint8_t WSEL       : 1;
  volatile  uint8_t ACKE       : 1;
  volatile  uint8_t ACT_SCC    : 1;
  volatile  uint8_t MSS        : 1;
} stc_mfs_i2c_ibcr_field_t;

typedef struct stc_mfs_i2c_ibsr_field
{
  volatile  uint8_t BB         : 1;
  volatile  uint8_t SPC        : 1;
  volatile  uint8_t RSC        : 1;
  volatile  uint8_t AL         : 1;
  volatile  uint8_t TRX        : 1;
  volatile  uint8_t RSA        : 1;
  volatile  uint8_t RACK       : 1;
  volatile  uint8_t FBT        : 1;
} stc_mfs_i2c_ibsr_field_t;

typedef struct stc_mfs_i2c_isba_field
{
  union {
    struct {
      volatile  uint8_t SA         : 7;
      volatile  uint8_t SAEN       : 1;
    };
    struct {
      volatile  uint8_t SA0        : 1;
      volatile  uint8_t SA1        : 1;
      volatile  uint8_t SA2        : 1;
      volatile  uint8_t SA3        : 1;
      volatile  uint8_t SA4        : 1;
      volatile  uint8_t SA5        : 1;
      volatile  uint8_t SA6        : 1;
            uint8_t RESERVED1  : 1;
    };
  };
} stc_mfs_i2c_isba_field_t;

typedef struct stc_mfs_i2c_ismk_field
{
  union {
    struct {
      volatile  uint8_t SM         : 7;
      volatile  uint8_t EN         : 1;
    };
    struct {
      volatile  uint8_t SM0        : 1;
      volatile  uint8_t SM1        : 1;
      volatile  uint8_t SM2        : 1;
      volatile  uint8_t SM3        : 1;
      volatile  uint8_t SM4        : 1;
      volatile  uint8_t SM5        : 1;
      volatile  uint8_t SM6        : 1;
            uint8_t RESERVED1  : 1;
    };
  };
} stc_mfs_i2c_ismk_field_t;

typedef struct stc_mfs_i2c_nfcr_field
{
  volatile  uint8_t NFT        : 5;
        uint8_t RESERVED1  : 3;
} stc_mfs_i2c_nfcr_field_t;

typedef struct stc_mfs_i2c_eibcr_field
{
  volatile  uint8_t BEC        : 1;
  volatile  uint8_t SOCE       : 1;
  volatile  uint8_t SCLC       : 1;
  volatile  uint8_t SDAC       : 1;
  volatile  uint8_t SCLS       : 1;
  volatile  uint8_t SDAS       : 1;
        uint8_t RESERVED1  : 2;
} stc_mfs_i2c_eibcr_field_t;



 
 
typedef struct stc_crc_crccr_field
{
  volatile  uint8_t INIT       : 1;
  volatile  uint8_t CRC32      : 1;
  volatile  uint8_t LTLEND     : 1;
  volatile  uint8_t LSBFST     : 1;
  volatile  uint8_t CRCLTE     : 1;
  volatile  uint8_t CRCLSF     : 1;
  volatile  uint8_t FXOR       : 1;
} stc_crc_crccr_field_t;



 
 
typedef struct stc_wc_wcrd_field
{
  volatile  uint8_t CTR0       : 1;
  volatile  uint8_t CTR1       : 1;
  volatile  uint8_t CTR2       : 1;
  volatile  uint8_t CTR3       : 1;
  volatile  uint8_t CTR4       : 1;
  volatile  uint8_t CTR5       : 1;
} stc_wc_wcrd_field_t;

typedef struct stc_wc_wcrl_field
{
  volatile  uint8_t RLC0       : 1;
  volatile  uint8_t RLC1       : 1;
  volatile  uint8_t RLC2       : 1;
  volatile  uint8_t RLC3       : 1;
  volatile  uint8_t RLC4       : 1;
  volatile  uint8_t RLC5       : 1;
} stc_wc_wcrl_field_t;

typedef struct stc_wc_wccr_field
{
  volatile  uint8_t WCIF       : 1;
  volatile  uint8_t WCIE       : 1;
  volatile  uint8_t CS0        : 1;
  volatile  uint8_t CS1        : 1;
        uint8_t RESERVED1  : 2;
  volatile  uint8_t WCOP       : 1;
  volatile  uint8_t WCEN       : 1;
} stc_wc_wccr_field_t;

typedef struct stc_wc_clk_sel_field
{
  volatile uint16_t SEL_IN     : 2;
       uint16_t RESERVED1  : 6;
  volatile uint16_t SEL_OUT    : 3;
} stc_wc_clk_sel_field_t;

typedef struct stc_wc_clk_en_field
{
  volatile  uint8_t CLK_EN     : 1;
  volatile  uint8_t CLK_EN_R   : 1;
} stc_wc_clk_en_field_t;



 
 
 
typedef struct stc_rtc_wtcr10_field
{
  volatile  uint8_t ST         : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t RUN        : 1;
  volatile  uint8_t SRST       : 1;
  volatile  uint8_t SCST       : 1;
  volatile  uint8_t SCRST      : 1;
  volatile  uint8_t BUSY       : 1;
  volatile  uint8_t TRANS      : 1;
} stc_rtc_wtcr10_field_t;

typedef struct stc_rtc_wtcr11_field
{
  volatile  uint8_t MIEN       : 1;
  volatile  uint8_t HEN        : 1;
  volatile  uint8_t DEN        : 1;
  volatile  uint8_t MOEN       : 1;
  volatile  uint8_t YEN        : 1;
        uint8_t RESERVED1  : 3;
} stc_rtc_wtcr11_field_t;

typedef struct stc_rtc_wtcr12_field
{
  volatile  uint8_t INTSSI     : 1;
  volatile  uint8_t INTSI      : 1;
  volatile  uint8_t INTMI      : 1;
  volatile  uint8_t INTHI      : 1;
  volatile  uint8_t INTTMI     : 1;
  volatile  uint8_t INTALI     : 1;
  volatile  uint8_t INTERI     : 1;
  volatile  uint8_t INTCRI     : 1;
} stc_rtc_wtcr12_field_t;

typedef struct stc_rtc_wtcr13_field
{
  volatile  uint8_t INTSSIE    : 1;
  volatile  uint8_t INTSIE     : 1;
  volatile  uint8_t INTMIE     : 1;
  volatile  uint8_t INTHIE     : 1;
  volatile  uint8_t INTTMIE    : 1;
  volatile  uint8_t INTALIE    : 1;
  volatile  uint8_t INTERIE    : 1;
  volatile  uint8_t INTCRIE    : 1;
} stc_rtc_wtcr13_field_t;

typedef struct stc_rtc_wtcr20_field
{
  volatile  uint8_t CREAD      : 1;
  volatile  uint8_t CWRITE     : 1;
  volatile  uint8_t BREAD      : 1;
  volatile  uint8_t BWRITE     : 1;
  volatile  uint8_t PREAD      : 1;
  volatile  uint8_t PWRITE     : 1;
        uint8_t RESERVED1  : 2;
} stc_rtc_wtcr20_field_t;

typedef struct stc_rtc_wtcr21_field
{
  volatile  uint8_t TMST       : 1;
  volatile  uint8_t TMEN       : 1;
  volatile  uint8_t TMRUN      : 1;
        uint8_t RESERVED1  : 5;
} stc_rtc_wtcr21_field_t;

typedef struct stc_rtc_wtsr_field
{
  union {
    struct {
      volatile  uint8_t S          : 4;
      volatile  uint8_t TS         : 3;
            uint8_t RESERVED1  : 1;
    };
    struct {
      volatile  uint8_t S0         : 1;
      volatile  uint8_t S1         : 1;
      volatile  uint8_t S2         : 1;
      volatile  uint8_t S3         : 1;
      volatile  uint8_t TS0        : 1;
      volatile  uint8_t TS1        : 1;
      volatile  uint8_t TS2        : 1;
            uint8_t RESERVED2  : 1;
    };
  };
} stc_rtc_wtsr_field_t;

typedef struct stc_rtc_wtmir_field
{
  union {
    struct {
      volatile  uint8_t MI         : 4;
      volatile  uint8_t TMI        : 3;
            uint8_t RESERVED1  : 1;
    };
    struct {
      volatile  uint8_t MI0        : 1;
      volatile  uint8_t MI1        : 1;
      volatile  uint8_t MI2        : 1;
      volatile  uint8_t MI3        : 1;
      volatile  uint8_t TMI0       : 1;
      volatile  uint8_t TMI1       : 1;
      volatile  uint8_t TMI2       : 1;
            uint8_t RESERVED2  : 1;
    };
  };
} stc_rtc_wtmir_field_t;

typedef struct stc_rtc_wthr_field
{
  union {
    struct {
      volatile  uint8_t H          : 4;
      volatile  uint8_t TH         : 2;
            uint8_t RESERVED1  : 2;
    };
    struct {
      volatile  uint8_t H0         : 1;
      volatile  uint8_t H1         : 1;
      volatile  uint8_t H2         : 1;
      volatile  uint8_t H3         : 1;
      volatile  uint8_t TH0        : 1;
      volatile  uint8_t TH1        : 1;
            uint8_t RESERVED2  : 2;
    };
  };
} stc_rtc_wthr_field_t;

typedef struct stc_rtc_wtdr_field
{
  union {
    struct {
      volatile  uint8_t D          : 4;
      volatile  uint8_t TD         : 2;
            uint8_t RESERVED1  : 2;
    };
    struct {
      volatile  uint8_t D0         : 1;
      volatile  uint8_t D1         : 1;
      volatile  uint8_t D2         : 1;
      volatile  uint8_t D3         : 1;
      volatile  uint8_t TD0        : 1;
      volatile  uint8_t TD1        : 1;
            uint8_t RESERVED2  : 2;
    };
  };
} stc_rtc_wtdr_field_t;

typedef struct stc_rtc_wtdw_field
{
  union {
    struct {
      volatile  uint8_t DW         : 3;
            uint8_t RESERVED1  : 5;
    };
    struct {
      volatile  uint8_t DW0        : 1;
      volatile  uint8_t DW1        : 1;
      volatile  uint8_t DW2        : 1;
            uint8_t RESERVED2  : 5;
    };
  };
} stc_rtc_wtdw_field_t;

typedef struct stc_rtc_wtmor_field
{
  union {
    struct {
      volatile  uint8_t MO         : 4;
      volatile  uint8_t TMO        : 1;
            uint8_t RESERVED1  : 3;
    };
    struct {
      volatile  uint8_t MO0        : 1;
      volatile  uint8_t MO1        : 1;
      volatile  uint8_t MO2        : 1;
      volatile  uint8_t MO3        : 1;
            uint8_t RESERVED2  : 4;
    };
  };
} stc_rtc_wtmor_field_t;

typedef struct stc_rtc_wtyr_field
{
  union {
    struct {
      volatile  uint8_t Y          : 4;
      volatile  uint8_t TY         : 4;
    };
    struct {
      volatile  uint8_t Y0         : 1;
      volatile  uint8_t Y1         : 1;
      volatile  uint8_t Y2         : 1;
      volatile  uint8_t Y3         : 1;
      volatile  uint8_t TY0        : 1;
      volatile  uint8_t TY1        : 1;
      volatile  uint8_t TY2        : 1;
      volatile  uint8_t TY3        : 1;
    };
  };
} stc_rtc_wtyr_field_t;

typedef struct stc_rtc_almir_field
{
  union {
    struct {
      volatile  uint8_t AMI        : 4;
      volatile  uint8_t TAMI       : 3;
            uint8_t RESERVED1  : 1;
    };
    struct {
      volatile  uint8_t AMI0       : 1;
      volatile  uint8_t AMI1       : 1;
      volatile  uint8_t AMI2       : 1;
      volatile  uint8_t AMI3       : 1;
      volatile  uint8_t TAMI0      : 1;
      volatile  uint8_t TAMI1      : 1;
      volatile  uint8_t TAMI2      : 1;
            uint8_t RESERVED2  : 1;
    };
  };
} stc_rtc_almir_field_t;

typedef struct stc_rtc_alhr_field
{
  union {
    struct {
      volatile  uint8_t AH         : 4;
      volatile  uint8_t TAH        : 2;
            uint8_t RESERVED1  : 2;
    };
    struct {
      volatile  uint8_t AH0        : 1;
      volatile  uint8_t AH1        : 1;
      volatile  uint8_t AH2        : 1;
      volatile  uint8_t AH3        : 1;
      volatile  uint8_t TAH0       : 1;
      volatile  uint8_t TAH1       : 1;
            uint8_t RESERVED2  : 2;
    };
  };
} stc_rtc_alhr_field_t;

typedef struct stc_rtc_aldr_field
{
  union {
    struct {
      volatile  uint8_t AD         : 4;
      volatile  uint8_t TAD        : 2;
            uint8_t RESERVED1  : 2;
    };
    struct {
      volatile  uint8_t AD0        : 1;
      volatile  uint8_t AD1        : 1;
      volatile  uint8_t AD2        : 1;
      volatile  uint8_t AD3        : 1;
      volatile  uint8_t TAD0       : 1;
      volatile  uint8_t TAD1       : 1;
            uint8_t RESERVED2  : 2;
    };
  };
} stc_rtc_aldr_field_t;

typedef struct stc_rtc_almor_field
{
  union {
    struct {
      volatile  uint8_t AMO        : 4;
      volatile  uint8_t TAMO       : 1;
            uint8_t RESERVED1  : 3;
    };
    struct {
      volatile  uint8_t AMO0       : 1;
      volatile  uint8_t AMO1       : 1;
      volatile  uint8_t AMO2       : 1;
      volatile  uint8_t AMO3       : 1;
            uint8_t RESERVED2  : 4;
    };
  };
} stc_rtc_almor_field_t;

typedef struct stc_rtc_alyr_field
{
  union {
    struct {
      volatile  uint8_t AY         : 4;
      volatile  uint8_t TAY        : 4;
    };
    struct {
      volatile  uint8_t AY0        : 1;
      volatile  uint8_t AY1        : 1;
      volatile  uint8_t AY2        : 1;
      volatile  uint8_t AY3        : 1;
      volatile  uint8_t TAY0       : 1;
      volatile  uint8_t TAY1       : 1;
      volatile  uint8_t TAY2       : 1;
      volatile  uint8_t TAY3       : 1;
    };
  };
} stc_rtc_alyr_field_t;

typedef struct stc_rtc_wttr0_field
{
  volatile  uint8_t TM0        : 1;
  volatile  uint8_t TM1        : 1;
  volatile  uint8_t TM2        : 1;
  volatile  uint8_t TM3        : 1;
  volatile  uint8_t TM4        : 1;
  volatile  uint8_t TM5        : 1;
  volatile  uint8_t TM6        : 1;
  volatile  uint8_t TM7        : 1;
} stc_rtc_wttr0_field_t;

typedef struct stc_rtc_wttr1_field
{
  volatile  uint8_t TM8        : 1;
  volatile  uint8_t TM9        : 1;
  volatile  uint8_t TM10       : 1;
  volatile  uint8_t TM11       : 1;
  volatile  uint8_t TM12       : 1;
  volatile  uint8_t TM13       : 1;
  volatile  uint8_t TM14       : 1;
  volatile  uint8_t TM15       : 1;
} stc_rtc_wttr1_field_t;

typedef struct stc_rtc_wttr2_field
{
  volatile  uint8_t TM16       : 1;
  volatile  uint8_t TM17       : 1;
        uint8_t RESERVED1  : 6;
} stc_rtc_wttr2_field_t;

 
typedef struct stc_rtc_wtcal1_field
{
  union {
    struct {
      volatile  uint8_t WTCAL1     : 2;
            uint8_t RESERVED1  : 6;
    };
    struct {
      volatile  uint8_t WTCAL10    : 1;
      volatile  uint8_t WTCAL11    : 1;
            uint8_t RESERVED2  : 6;
    };
  };
} stc_rtc_wtcal1_field_t;

typedef struct stc_rtc_wtcalen_field
{
  volatile  uint8_t WTCALEN    : 1;
        uint8_t RESERVED1  : 7;
} stc_rtc_wtcalen_field_t;

typedef struct stc_rtc_wtdiv_field
{
  union {
    struct {
      volatile  uint8_t WTDIV      : 4;
            uint8_t RESERVED1  : 4;
    };
    struct {
      volatile  uint8_t WTDIV0     : 1;
      volatile  uint8_t WTDIV1     : 1;
      volatile  uint8_t WTDIV2     : 1;
      volatile  uint8_t WTDIV3     : 1;
            uint8_t RESERVED2  : 4;
    };
  };
} stc_rtc_wtdiv_field_t;

typedef struct stc_rtc_wtdiven_field
{
  volatile  uint8_t WTDIVEN    : 1;
  volatile  uint8_t WTDIVRDY   : 1;
        uint8_t RESERVED1  : 6;
} stc_rtc_wtdiven_field_t;

typedef struct stc_rtc_wtcalprd_field
{
  union {
    struct {
      volatile  uint8_t WTCALPRD   : 6;
            uint8_t RESERVED1  : 2;
    };
    struct {
      volatile  uint8_t WTCALPRD0  : 1;
      volatile  uint8_t WTCALPRD1  : 1;
      volatile  uint8_t WTCALPRD2  : 1;
      volatile  uint8_t WTCALPRD3  : 1;
      volatile  uint8_t WTCALPRD4  : 1;
      volatile  uint8_t WTCALPRD5  : 1;
            uint8_t RESERVED2  : 2;
    };
  };
} stc_rtc_wtcalprd_field_t;

typedef struct stc_rtc_wtcosel_field
{
  volatile  uint8_t WTCOSEL    : 1;
  volatile  uint8_t WTDIVRDY   : 7;
} stc_rtc_wtcosel_field_t;

 
typedef struct stc_rtc_vb_clkdiv_field
{
  volatile  uint8_t DIV        : 8;
} stc_rtc_vb_clkdiv_field_t;

typedef struct stc_rtc_wtosccnt_field
{
  volatile  uint8_t SOSCEX     : 1;
  volatile  uint8_t SOSCNTL    : 1;
} stc_rtc_wtosccnt_field_t;

typedef struct stc_rtc_boost_field
{
  volatile  uint8_t BOOST      : 2;
} stc_rtc_boost_field_t;

typedef struct stc_rtc_ewkup_field
{
  volatile  uint8_t WUP0       : 1;
} stc_rtc_ewkup_field_t;

typedef struct stc_rtc_vdet_field
{
        uint8_t RESERVED0  : 7;
  volatile  uint8_t PON        : 1;
} stc_rtc_vdet_field_t;

typedef struct stc_rtc_hibrst_field
{
  volatile  uint8_t HIBRST     : 1;
} stc_rtc_hibrst_field_t;

typedef struct stc_rtc_vbpfr_field
{
  volatile  uint8_t VPFR0      : 1;
  volatile  uint8_t VPFR1      : 1;
  volatile  uint8_t VPFR2      : 1;
  volatile  uint8_t VPFR3      : 1;
  volatile  uint8_t SPSR0      : 1;
  volatile  uint8_t SPSR1      : 1;
} stc_rtc_vbpfr_field_t;

typedef struct stc_rtc_vbpcr_field
{
  volatile  uint8_t VPCR0      : 1;
  volatile  uint8_t VPCR1      : 1;
  volatile  uint8_t VPCR2      : 1;
  volatile  uint8_t VPCR3      : 1;
} stc_rtc_vbpcr_field_t;

typedef struct stc_rtc_vbddr_field
{
  volatile  uint8_t VDDR0      : 1;
  volatile  uint8_t VDDR1      : 1;
  volatile  uint8_t VDDR2      : 1;
  volatile  uint8_t VDDR3      : 1;
} stc_rtc_vbddr_field_t;

typedef struct stc_rtc_vbdir_field
{
  volatile  uint8_t VDIR0      : 1;
  volatile  uint8_t VDIR1      : 1;
  volatile  uint8_t VDIR2      : 1;
  volatile  uint8_t VDIR3      : 1;
} stc_rtc_vbdir_field_t;

typedef struct stc_rtc_vbdor_field
{
  volatile  uint8_t VDOR0      : 1;
  volatile  uint8_t VDOR1      : 1;
  volatile  uint8_t VDOR2      : 1;
  volatile  uint8_t VDOR3      : 1;
} stc_rtc_vbdor_field_t;

typedef struct stc_rtc_vbpzr_field
{
  volatile  uint8_t VPZR0      : 1;
  volatile  uint8_t VPZR1      : 1;
} stc_rtc_vbpzr_field_t;



 
 
typedef struct stc_lcr_lcr_prsld_field
{
  volatile  uint8_t LCR_PRSLD  : 6;
} stc_lcr_lcr_prsld_field_t;



 
 
typedef struct stc_clk_gating_cken0_field
{
  volatile uint32_t MFSCK0     : 1;
  volatile uint32_t MFSCK1     : 1;
  volatile uint32_t MFSCK2     : 1;
  volatile uint32_t MFSCK3     : 1;
  volatile uint32_t MFSCK4     : 1;
  volatile uint32_t MFSCK5     : 1;
  volatile uint32_t MFSCK6     : 1;
  volatile uint32_t MFSCK7     : 1;
  volatile uint32_t MFSCK8     : 1;
  volatile uint32_t MFSCK9     : 1;
  volatile uint32_t MFSCK10    : 1;
  volatile uint32_t MFSCK11    : 1;
  volatile uint32_t MFSCK12    : 1;
  volatile uint32_t MFSCK13    : 1;
  volatile uint32_t MFSCK14    : 1;
  volatile uint32_t MFSCK15    : 1;
  volatile uint32_t ADCCK0     : 1;
  volatile uint32_t ADCCK1     : 1;
  volatile uint32_t ADCCK2     : 1;
  volatile uint32_t ADCCK3     : 1;
       uint32_t RESERVED20 : 4;
  volatile uint32_t DMACK      : 1;
       uint32_t RESERVED25 : 1;
  volatile uint32_t EXBCK      : 1;
       uint32_t RESERVED27 : 1;
  volatile uint32_t GIOCK      : 1;
} stc_clk_gating_cken0_field_t;

typedef struct stc_clk_gating_mrst0_field
{
  volatile uint32_t MFSRST0    : 1;
  volatile uint32_t MFSRST1    : 1;
  volatile uint32_t MFSRST2    : 1;
  volatile uint32_t MFSRST3    : 1;
  volatile uint32_t MFSRST4    : 1;
  volatile uint32_t MFSRST5    : 1;
  volatile uint32_t MFSRST6    : 1;
  volatile uint32_t MFSRST7    : 1;
  volatile uint32_t MFSRST8    : 1;
  volatile uint32_t MFSRST9    : 1;
  volatile uint32_t MFSRST10   : 1;
  volatile uint32_t MFSRST11   : 1;
  volatile uint32_t MFSRST12   : 1;
  volatile uint32_t MFSRST13   : 1;
  volatile uint32_t MFSRST14   : 1;
  volatile uint32_t MFSRST15   : 1;
  volatile uint32_t ADCRST0    : 1;
  volatile uint32_t ADCRST1    : 1;
  volatile uint32_t ADCRST2    : 1;
  volatile uint32_t ADCRST3    : 1;
       uint32_t RESERVED20 : 4;
  volatile uint32_t DMARST     : 1;
       uint32_t RESERVED25 : 1;
  volatile uint32_t EXBRST     : 1;
} stc_clk_gating_mrst0_field_t;

typedef struct stc_clk_gating_cken1_field
{
  volatile uint32_t BTMCK0     : 1;
  volatile uint32_t BTMCK1     : 1;
  volatile uint32_t BTMCK2     : 1;
  volatile uint32_t BTMCK3     : 1;
       uint32_t RESERVED4  : 4;
  volatile uint32_t MFTCK0     : 1;
  volatile uint32_t MFTCK1     : 1;
  volatile uint32_t MFTCK2     : 1;
  volatile uint32_t MFTCK3     : 1;
       uint32_t RESERVED12 : 4;
  volatile uint32_t QDUCK0     : 1;
  volatile uint32_t QDUCK1     : 1;
  volatile uint32_t QDUCK2     : 1;
  volatile uint32_t QDUCK3     : 1;
} stc_clk_gating_cken1_field_t;

typedef struct stc_clk_gating_mrst1_field
{
  volatile uint32_t BTMRST0    : 1;
  volatile uint32_t BTMRST1    : 1;
  volatile uint32_t BTMRST2    : 1;
  volatile uint32_t BTMRST3    : 1;
       uint32_t RESERVED4  : 4;
  volatile uint32_t MFTRST0    : 1;
  volatile uint32_t MFTRST1    : 1;
  volatile uint32_t MFTRST2    : 1;
  volatile uint32_t MFTRST3    : 1;
       uint32_t RESERVED12 : 4;
  volatile uint32_t QDURST0    : 1;
  volatile uint32_t QDURST1    : 1;
  volatile uint32_t QDURST2    : 1;
  volatile uint32_t QDURST3    : 1;
} stc_clk_gating_mrst1_field_t;

typedef struct stc_clk_gating_cken2_field
{
  volatile uint32_t USBCK0     : 1;
  volatile uint32_t USBCK1     : 1;
       uint32_t RESERVED2  : 2;
  volatile uint32_t CANCK0     : 1;
  volatile uint32_t CANCK1     : 1;
       uint32_t RESERVED6  : 2;
  volatile uint32_t SDCCK      : 1;
} stc_clk_gating_cken2_field_t;

typedef struct stc_clk_gating_mrst2_field
{
  volatile uint32_t USBRST0    : 1;
  volatile uint32_t USBRST1    : 1;
       uint32_t RESERVED2  : 2;
  volatile uint32_t CANRST0    : 1;
  volatile uint32_t CANRST1    : 1;
       uint32_t RESERVED6  : 2;
  volatile uint32_t SDCRST     : 1;
} stc_clk_gating_mrst2_field_t;




 
 
typedef struct stc_exbus_mode_field
{
  volatile uint32_t WDTH       : 2;
  volatile uint32_t RBMON      : 1;
  volatile uint32_t WEOFF      : 1;
  volatile uint32_t NAND       : 1;
  volatile uint32_t PAGE       : 1;
  volatile uint32_t RDY        : 1;
  volatile uint32_t SHRTDOUT   : 1;
  volatile uint32_t MPXMODE    : 1;
  volatile uint32_t ALEINV     : 1;
  volatile uint32_t MPXDOFF    : 1;
  volatile uint32_t MPXCSOF    : 1;
  volatile uint32_t MOEXEUP    : 1;
       uint32_t RESERVED   : 18;
} stc_exbus_mode_field_t;

typedef struct stc_exbus_tim_field
{
  volatile uint32_t RACC       : 4;
  volatile uint32_t RADC       : 4;
  volatile uint32_t FRADC      : 4;
  volatile uint32_t RIDLC      : 4;
  volatile uint32_t WACC       : 4;
  volatile uint32_t WADC       : 4;
  volatile uint32_t WWEC       : 4;
  volatile uint32_t WIDLC      : 4;
} stc_exbus_tim_field_t;

typedef struct stc_exbus_area_field
{
  volatile uint32_t ADDR       : 8;
       uint32_t RESERVED1  : 8;
  volatile uint32_t MASK       : 7;
       uint32_t RESERVED2  : 9;
} stc_exbus_area_field_t;

typedef struct stc_exbus_atim_field
{
  volatile uint32_t ALC        : 4;
  volatile uint32_t ALES       : 4;
  volatile uint32_t ALEW       : 4;
       uint32_t RESERVED   : 20;
} stc_exbus_atim_field_t;

typedef struct stc_exbus_sdmode_field
{
  volatile uint32_t SDON       : 1;
  volatile uint32_t PDON       : 1;
  volatile uint32_t ROFF       : 1;
       uint32_t RESERVED1  : 1;
  volatile uint32_t CASEL      : 2;
       uint32_t RESERVED2  : 2;
  volatile uint32_t RASEL      : 4;
  volatile uint32_t BASEL      : 4;
  volatile uint32_t MSDCLK     : 1;
       uint32_t RESERVED3  : 15;
} stc_exbus_sdmode_field_t;

typedef struct stc_exbus_reftim_field
{
  volatile uint32_t REFC       : 16;
  volatile uint32_t NREF       : 8;
  volatile uint32_t PREF       : 1;
       uint32_t RESERVED   : 7;
} stc_exbus_reftim_field_t;

typedef struct stc_exbus_pwrdwn_field
{
  volatile uint32_t PDC        : 16;
       uint32_t RESERVED   : 16;
} stc_exbus_pwrdwn_field_t;

typedef struct stc_exbus_sdtim_field
{
  volatile uint32_t CL         : 2;
       uint32_t RESERVED1  : 2;
  volatile uint32_t TRC        : 4;
  volatile uint32_t TRP        : 4;
  volatile uint32_t TRCD       : 4;
  volatile uint32_t TRAS       : 4;
  volatile uint32_t TREFC      : 4;
  volatile uint32_t TDPL       : 2;
       uint32_t RESERVED2  : 6;
} stc_exbus_sdtim_field_t;

typedef struct stc_exbus_sdcmd_field
{
  volatile uint32_t SDAD       : 16;
  volatile uint32_t SDWE       : 1;
  volatile uint32_t SDCAS      : 1;
  volatile uint32_t SDRAS      : 1;
  volatile uint32_t SDCS       : 1;
  volatile uint32_t SDCKE      : 1;
       uint32_t RESERVED2  : 10;
  volatile uint32_t PEND       : 1;   
} stc_exbus_sdcmd_field_t;

typedef struct stc_exbus_memcerr_field
{
  volatile uint32_t SFER       : 1;
  volatile uint32_t SDER       : 1;
  volatile uint32_t SFION      : 1;
  volatile uint32_t SDION      : 1;
       uint32_t RESERVED   : 28;  
} stc_exbus_memcerr_field_t;

typedef struct stc_exbus_dclkr_field
{
  volatile uint32_t MDIV       : 4;
  volatile uint32_t MCLKON     : 1;
       uint32_t RESERVED   : 27;  
} stc_exbus_dclkr_field_t;

typedef struct stc_exbus_est_field
{
  volatile uint32_t WERR       : 1;
       uint32_t RESERVED   : 31;  
} stc_exbus_est_field_t;

typedef struct stc_exbus_wead_field
{
  volatile uint32_t ADDR       : 32; 
} stc_exbus_wead_field_t;

typedef struct stc_exbus_esclr_field
{
  volatile uint32_t WERRCLR    : 1;
       uint32_t RESERVED   : 31;  
} stc_exbus_esclr_field_t;

typedef struct stc_exbus_amode_field
{
  volatile uint32_t WAEN       : 1;
       uint32_t RESERVED   : 31;  
} stc_exbus_amode_field_t;



 
 
typedef struct stc_usb_hcnt_field
{
  volatile uint16_t HOST       : 1;
  volatile uint16_t URST       : 1;
  volatile uint16_t SOFIRE     : 1;
  volatile uint16_t DIRE       : 1;
  volatile uint16_t CNNIRE     : 1;
  volatile uint16_t CMPIRE     : 1;
  volatile uint16_t URIRE      : 1;
  volatile uint16_t RWKIRE     : 1;
  volatile uint16_t RETRY      : 1;
  volatile uint16_t CANCEL     : 1;
  volatile uint16_t SOFSTEP    : 1;
} stc_usb_hcnt_field_t;

typedef struct stc_usb_hcnt0_field
{
  volatile  uint8_t HOST       : 1;
  volatile  uint8_t URST       : 1;
  volatile  uint8_t SOFIRE     : 1;
  volatile  uint8_t DIRE       : 1;
  volatile  uint8_t CNNIRE     : 1;
  volatile  uint8_t CMPIRE     : 1;
  volatile  uint8_t URIRE      : 1;
  volatile  uint8_t RWKIRE     : 1;
} stc_usb_hcnt0_field_t;

typedef struct stc_usb_hcnt1_field
{
  volatile  uint8_t RETRY      : 1;
  volatile  uint8_t CANCEL     : 1;
  volatile  uint8_t SOFSTEP    : 1;
} stc_usb_hcnt1_field_t;

typedef struct stc_usb_hirq_field
{
  volatile  uint8_t SOFIRQ     : 1;
  volatile  uint8_t DIRQ       : 1;
  volatile  uint8_t CNNIRQ     : 1;
  volatile  uint8_t CMPIRQ     : 1;
  volatile  uint8_t URIRQ      : 1;
  volatile  uint8_t RWKIRQ     : 1;
        uint8_t RESERVED1  : 1;
  volatile  uint8_t TCAN       : 1;
} stc_usb_hirq_field_t;

typedef struct stc_usb_herr_field
{
  volatile  uint8_t HS0        : 1;
  volatile  uint8_t HS1        : 1;
  volatile  uint8_t STUFF      : 1;
  volatile  uint8_t TGERR      : 1;
  volatile  uint8_t CRC        : 1;
  volatile  uint8_t TOUT       : 1;
  volatile  uint8_t RERR       : 1;
  volatile  uint8_t LSTOF      : 1;
} stc_usb_herr_field_t;

typedef struct stc_usb_hstate_field
{
  volatile  uint8_t CSTAT      : 1;
  volatile  uint8_t TMODE      : 1;
  volatile  uint8_t SUSP       : 1;
  volatile  uint8_t SOFBUSY    : 1;
  volatile  uint8_t CLKSEL     : 1;
  volatile  uint8_t ALIVE      : 1;
} stc_usb_hstate_field_t;

typedef struct stc_usb_hfcomp_field
{
  volatile  uint8_t FRAMECOMP0 : 1;
  volatile  uint8_t FRAMECOMP1 : 1;
  volatile  uint8_t FRAMECOMP2 : 1;
  volatile  uint8_t FRAMECOMP3 : 1;
  volatile  uint8_t FRAMECOMP4 : 1;
  volatile  uint8_t FRAMECOMP5 : 1;
  volatile  uint8_t FRAMECOMP6 : 1;
  volatile  uint8_t FRAMECOMP7 : 1;
} stc_usb_hfcomp_field_t;

typedef struct stc_usb_hrtimer_field
{
  volatile uint16_t RTIMER0    : 1;
  volatile uint16_t RTIMER1    : 1;
  volatile uint16_t RTIMER2    : 1;
  volatile uint16_t RTIMER3    : 1;
  volatile uint16_t RTIMER4    : 1;
  volatile uint16_t RTIMER5    : 1;
  volatile uint16_t RTIMER6    : 1;
  volatile uint16_t RTIMER7    : 1;
  volatile uint16_t RTIMER8    : 1;
  volatile uint16_t RTIMER9    : 1;
  volatile uint16_t RTIMER10   : 1;
  volatile uint16_t RTIMER11   : 1;
  volatile uint16_t RTIMER12   : 1;
  volatile uint16_t RTIMER13   : 1;
  volatile uint16_t RTIMER14   : 1;
  volatile uint16_t RTIMER15   : 1;
} stc_usb_hrtimer_field_t;

typedef struct stc_usb_hrtimer0_field
{
  volatile  uint8_t RTIMER00   : 1;
  volatile  uint8_t RTIMER01   : 1;
  volatile  uint8_t RTIMER02   : 1;
  volatile  uint8_t RTIMER03   : 1;
  volatile  uint8_t RTIMER04   : 1;
  volatile  uint8_t RTIMER05   : 1;
  volatile  uint8_t RTIMER06   : 1;
  volatile  uint8_t RTIMER07   : 1;
} stc_usb_hrtimer0_field_t;

typedef struct stc_usb_hrtimer1_field
{
  volatile  uint8_t RTIMER10   : 1;
  volatile  uint8_t RTIMER11   : 1;
  volatile  uint8_t RTIMER12   : 1;
  volatile  uint8_t RTIMER13   : 1;
  volatile  uint8_t RTIMER14   : 1;
  volatile  uint8_t RTIMER15   : 1;
  volatile  uint8_t RTIMER16   : 1;
  volatile  uint8_t RTIMER17   : 1;
} stc_usb_hrtimer1_field_t;

typedef struct stc_usb_hrtimer2_field
{
  volatile  uint8_t RTIMER20   : 1;
  volatile  uint8_t RTIMER21   : 1;
  volatile  uint8_t RTIMER22   : 1;
} stc_usb_hrtimer2_field_t;

typedef struct stc_usb_hadr_field
{
  volatile  uint8_t ADDRESS0   : 1;
  volatile  uint8_t ADDRESS1   : 1;
  volatile  uint8_t ADDRESS2   : 1;
  volatile  uint8_t ADDRESS3   : 1;
  volatile  uint8_t ADDRESS4   : 1;
  volatile  uint8_t ADDRESS5   : 1;
  volatile  uint8_t ADDRESS6   : 1;
} stc_usb_hadr_field_t;

typedef struct stc_usb_heof_field
{
  volatile uint16_t EOF0       : 1;
  volatile uint16_t EOF1       : 1;
  volatile uint16_t EOF2       : 1;
  volatile uint16_t EOF3       : 1;
  volatile uint16_t EOF4       : 1;
  volatile uint16_t EOF5       : 1;
  volatile uint16_t EOF6       : 1;
  volatile uint16_t EOF7       : 1;
  volatile uint16_t EOF8       : 1;
  volatile uint16_t EOF9       : 1;
  volatile uint16_t EOF10      : 1;
  volatile uint16_t EOF11      : 1;
  volatile uint16_t EOF12      : 1;
  volatile uint16_t EOF13      : 1;
  volatile uint16_t EOF14      : 1;
  volatile uint16_t EOF15      : 1;
} stc_usb_heof_field_t;

typedef struct stc_usb_heof0_field
{
  volatile  uint8_t EOF00      : 1;
  volatile  uint8_t EOF01      : 1;
  volatile  uint8_t EOF02      : 1;
  volatile  uint8_t EOF03      : 1;
  volatile  uint8_t EOF04      : 1;
  volatile  uint8_t EOF05      : 1;
  volatile  uint8_t EOF06      : 1;
  volatile  uint8_t EOF07      : 1;
} stc_usb_heof0_field_t;

typedef struct stc_usb_heof1_field
{
  volatile  uint8_t EOF10      : 1;
  volatile  uint8_t EOF11      : 1;
  volatile  uint8_t EOF12      : 1;
  volatile  uint8_t EOF13      : 1;
  volatile  uint8_t EOF14      : 1;
  volatile  uint8_t EOF15      : 1;
} stc_usb_heof1_field_t;

typedef struct stc_usb_hframe_field
{
  volatile uint16_t FRAME0     : 1;
  volatile uint16_t FRAME1     : 1;
  volatile uint16_t FRAME2     : 1;
  volatile uint16_t FRAME3     : 1;
  volatile uint16_t FRAME4     : 1;
  volatile uint16_t FRAME5     : 1;
  volatile uint16_t FRAME6     : 1;
  volatile uint16_t FRAME7     : 1;
  volatile uint16_t FRAME8     : 1;
  volatile uint16_t FRAME9     : 1;
  volatile uint16_t FRAME10    : 1;
} stc_usb_hframe_field_t;

typedef struct stc_usb_hframe0_field
{
  volatile  uint8_t FRAME00    : 1;
  volatile  uint8_t FRAME01    : 1;
  volatile  uint8_t FRAME02    : 1;
  volatile  uint8_t FRAME03    : 1;
  volatile  uint8_t FRAME04    : 1;
  volatile  uint8_t FRAME05    : 1;
  volatile  uint8_t FRAME06    : 1;
  volatile  uint8_t FRAME07    : 1;
} stc_usb_hframe0_field_t;

typedef struct stc_usb_hframe1_field
{
  volatile  uint8_t FRAME10    : 1;
  volatile  uint8_t FRAME11    : 1;
  volatile  uint8_t FRAME12    : 1;
  volatile  uint8_t FRAME13    : 1;
} stc_usb_hframe1_field_t;

typedef struct stc_usb_htoken_field
{
  volatile  uint8_t ENDPT0     : 1;
  volatile  uint8_t ENDPT1     : 1;
  volatile  uint8_t ENDPT2     : 1;
  volatile  uint8_t ENDPT3     : 1;
  volatile  uint8_t TKNEN0     : 1;
  volatile  uint8_t TKNEN1     : 1;
  volatile  uint8_t TKNEN2     : 1;
  volatile  uint8_t TGGL       : 1;
} stc_usb_htoken_field_t;

typedef struct stc_usb_udcc_field
{
  volatile uint16_t PWC        : 1;
  volatile uint16_t RFBK       : 1;
       uint16_t RESERVED1  : 1;
  volatile uint16_t STALCLREN  : 1;
  volatile uint16_t USTP       : 1;
  volatile uint16_t HCONX      : 1;
  volatile uint16_t RESUM      : 1;
  volatile uint16_t RST        : 1;
} stc_usb_udcc_field_t;

typedef struct stc_usb_ep0c_field
{
  volatile uint16_t PKS00      : 1;
  volatile uint16_t PKS01      : 1;
  volatile uint16_t PKS02      : 1;
  volatile uint16_t PKS03      : 1;
  volatile uint16_t PKS04      : 1;
  volatile uint16_t PKS05      : 1;
  volatile uint16_t PKS06      : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t STAL       : 1;
} stc_usb_ep0c_field_t;

typedef struct stc_usb_ep1c_field
{
  volatile uint16_t PKS10      : 1;
  volatile uint16_t PKS11      : 1;
  volatile uint16_t PKS12      : 1;
  volatile uint16_t PKS13      : 1;
  volatile uint16_t PKS14      : 1;
  volatile uint16_t PKS15      : 1;
  volatile uint16_t PKS16      : 1;
  volatile uint16_t PKS17      : 1;
  volatile uint16_t PKS18      : 1;
  volatile uint16_t STAL       : 1;
  volatile uint16_t NULE       : 1;
  volatile uint16_t DMAE       : 1;
  volatile uint16_t DIR        : 1;
  volatile uint16_t TYPE0      : 1;
  volatile uint16_t TYPE1      : 1;
  volatile uint16_t EPEN       : 1;
} stc_usb_ep1c_field_t;

typedef struct stc_usb_ep2c_field
{
  volatile uint16_t PKS20      : 1;
  volatile uint16_t PKS21      : 1;
  volatile uint16_t PKS22      : 1;
  volatile uint16_t PKS23      : 1;
  volatile uint16_t PKS24      : 1;
  volatile uint16_t PKS25      : 1;
  volatile uint16_t PKS26      : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t STAL       : 1;
  volatile uint16_t NULE       : 1;
  volatile uint16_t DMAE       : 1;
  volatile uint16_t DIR        : 1;
  volatile uint16_t TYPE0      : 1;
  volatile uint16_t TYPE1      : 1;
  volatile uint16_t EPEN       : 1;
} stc_usb_ep2c_field_t;

typedef struct stc_usb_ep3c_field
{
  volatile uint16_t PKS30      : 1;
  volatile uint16_t PKS31      : 1;
  volatile uint16_t PKS32      : 1;
  volatile uint16_t PKS33      : 1;
  volatile uint16_t PKS34      : 1;
  volatile uint16_t PKS35      : 1;
  volatile uint16_t PKS36      : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t STAL       : 1;
  volatile uint16_t NULE       : 1;
  volatile uint16_t DMAE       : 1;
  volatile uint16_t DIR        : 1;
  volatile uint16_t TYPE0      : 1;
  volatile uint16_t TYPE1      : 1;
  volatile uint16_t EPEN       : 1;
} stc_usb_ep3c_field_t;

typedef struct stc_usb_ep4c_field
{
  volatile uint16_t PKS40      : 1;
  volatile uint16_t PKS41      : 1;
  volatile uint16_t PKS42      : 1;
  volatile uint16_t PKS43      : 1;
  volatile uint16_t PKS44      : 1;
  volatile uint16_t PKS45      : 1;
  volatile uint16_t PKS46      : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t STAL       : 1;
  volatile uint16_t NULE       : 1;
  volatile uint16_t DMAE       : 1;
  volatile uint16_t DIR        : 1;
  volatile uint16_t TYPE0      : 1;
  volatile uint16_t TYPE1      : 1;
  volatile uint16_t EPEN       : 1;
} stc_usb_ep4c_field_t;

typedef struct stc_usb_ep5c_field
{
  volatile uint16_t PKS50      : 1;
  volatile uint16_t PKS51      : 1;
  volatile uint16_t PKS52      : 1;
  volatile uint16_t PKS53      : 1;
  volatile uint16_t PKS54      : 1;
  volatile uint16_t PKS55      : 1;
  volatile uint16_t PKS56      : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t STAL       : 1;
  volatile uint16_t NULE       : 1;
  volatile uint16_t DMAE       : 1;
  volatile uint16_t DIR        : 1;
  volatile uint16_t TYPE0      : 1;
  volatile uint16_t TYPE1      : 1;
  volatile uint16_t EPEN       : 1;
} stc_usb_ep5c_field_t;

typedef struct stc_usb_tmsp_field
{
  volatile uint16_t TMSP0      : 1;
  volatile uint16_t TMSP1      : 1;
  volatile uint16_t TMSP2      : 1;
  volatile uint16_t TMSP3      : 1;
  volatile uint16_t TMSP4      : 1;
  volatile uint16_t TMSP5      : 1;
  volatile uint16_t TMSP6      : 1;
  volatile uint16_t TMSP7      : 1;
  volatile uint16_t TMSP8      : 1;
  volatile uint16_t TMSP9      : 1;
  volatile uint16_t TMSP10     : 1;
} stc_usb_tmsp_field_t;

typedef struct stc_usb_udcs_field
{
  volatile  uint8_t CONF       : 1;
  volatile  uint8_t SETP       : 1;
  volatile  uint8_t WKUP       : 1;
  volatile  uint8_t BRST       : 1;
  volatile  uint8_t SOF        : 1;
  volatile  uint8_t SUSP       : 1;
} stc_usb_udcs_field_t;

typedef struct stc_usb_udcie_field
{
  volatile  uint8_t CONFIE     : 1;
  volatile  uint8_t CONFN      : 1;
  volatile  uint8_t WKUPIE     : 1;
  volatile  uint8_t BRSTIE     : 1;
  volatile  uint8_t SOFIE      : 1;
  volatile  uint8_t SUSPIE     : 1;
} stc_usb_udcie_field_t;

typedef struct stc_usb_ep0is_field
{
       uint16_t RESERVED1  : 10;
  volatile uint16_t DRQI       : 1;
       uint16_t RESERVED2  : 3;
  volatile uint16_t DRQIIE     : 1;
  volatile uint16_t BFINI      : 1;
} stc_usb_ep0is_field_t;

typedef struct stc_usb_ep0os_field
{
  volatile uint16_t SIZE0      : 1;
  volatile uint16_t SIZE1      : 1;
  volatile uint16_t SIZE2      : 1;
  volatile uint16_t SIZE3      : 1;
  volatile uint16_t SIZE4      : 1;
  volatile uint16_t SIZE5      : 1;
  volatile uint16_t SIZE6      : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t SPK        : 1;
  volatile uint16_t DRQO       : 1;
       uint16_t RESERVED2  : 2;
  volatile uint16_t SPKIE      : 1;
  volatile uint16_t DRQOIE     : 1;
  volatile uint16_t BFINI      : 1;
} stc_usb_ep0os_field_t;

typedef struct stc_usb_ep1s_field
{
  volatile uint16_t SIZE10     : 1;
  volatile uint16_t SIZE11     : 1;
  volatile uint16_t SIZE12     : 1;
  volatile uint16_t SIZE13     : 1;
  volatile uint16_t SIZE14     : 1;
  volatile uint16_t SIZE15     : 1;
  volatile uint16_t SIZE16     : 1;
  volatile uint16_t SIZE17     : 1;
  volatile uint16_t SIZE18     : 1;
  volatile uint16_t SPK        : 1;
  volatile uint16_t DRQ        : 1;
  volatile uint16_t BUSY       : 1;
       uint16_t RESERVED1  : 1;
  volatile uint16_t SPKIE      : 1;
  volatile uint16_t DRQIE      : 1;
  volatile uint16_t BFINI      : 1;
} stc_usb_ep1s_field_t;

typedef struct stc_usb_ep2s_field
{
  volatile uint16_t SIZE20     : 1;
  volatile uint16_t SIZE21     : 1;
  volatile uint16_t SIZE22     : 1;
  volatile uint16_t SIZE23     : 1;
  volatile uint16_t SIZE24     : 1;
  volatile uint16_t SIZE25     : 1;
  volatile uint16_t SIZE26     : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t SPK        : 1;
  volatile uint16_t DRQ        : 1;
  volatile uint16_t BUSY       : 1;
       uint16_t RESERVED2  : 1;
  volatile uint16_t SPKIE      : 1;
  volatile uint16_t DRQIE      : 1;
  volatile uint16_t BFINI      : 1;
} stc_usb_ep2s_field_t;

typedef struct stc_usb_ep4s_field
{
  volatile uint16_t SIZE40     : 1;
  volatile uint16_t SIZE41     : 1;
  volatile uint16_t SIZE42     : 1;
  volatile uint16_t SIZE43     : 1;
  volatile uint16_t SIZE44     : 1;
  volatile uint16_t SIZE45     : 1;
  volatile uint16_t SIZE46     : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t SPK        : 1;
  volatile uint16_t DRQ        : 1;
  volatile uint16_t BUSY       : 1;
       uint16_t RESERVED2  : 1;
  volatile uint16_t SPKIE      : 1;
  volatile uint16_t DRQIE      : 1;
  volatile uint16_t BFINI      : 1;
} stc_usb_ep4s_field_t;

typedef struct stc_usb_ep5s_field
{
  volatile uint16_t SIZE50     : 1;
  volatile uint16_t SIZE51     : 1;
  volatile uint16_t SIZE52     : 1;
  volatile uint16_t SIZE53     : 1;
  volatile uint16_t SIZE54     : 1;
  volatile uint16_t SIZE55     : 1;
  volatile uint16_t SIZE56     : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t SPK        : 1;
  volatile uint16_t DRQ        : 1;
  volatile uint16_t BUSY       : 1;
       uint16_t RESERVED2  : 1;
  volatile uint16_t SPKIE      : 1;
  volatile uint16_t DRQIE      : 1;
  volatile uint16_t BFINI      : 1;
} stc_usb_ep5s_field_t;



 
 
typedef struct stc_dmac_dmacr_field
{
       uint32_t RESERVED1  : 24;
  volatile uint32_t DH0        : 1;
  volatile uint32_t DH1        : 1;
  volatile uint32_t DH2        : 1;
  volatile uint32_t DH3        : 1;
  volatile uint32_t PR         : 1;
       uint32_t RESERVED2  : 1;
  volatile uint32_t DS         : 1;
  volatile uint32_t DE         : 1;
} stc_dmac_dmacr_field_t;

typedef struct stc_dmac_dmaca0_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca0_field_t;

typedef struct stc_dmac_dmacb0_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t FS         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb0_field_t;

typedef struct stc_dmac_dmaca1_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca1_field_t;

typedef struct stc_dmac_dmacb1_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t FS         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb1_field_t;

typedef struct stc_dmac_dmaca2_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca2_field_t;

typedef struct stc_dmac_dmacb2_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t FS         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb2_field_t;

typedef struct stc_dmac_dmaca3_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca3_field_t;

typedef struct stc_dmac_dmacb3_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb3_field_t;

typedef struct stc_dmac_dmaca4_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca4_field_t;

typedef struct stc_dmac_dmacb4_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t FS         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb4_field_t;

typedef struct stc_dmac_dmaca5_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca5_field_t;

typedef struct stc_dmac_dmacb5_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t FS         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb5_field_t;

typedef struct stc_dmac_dmaca6_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca6_field_t;

typedef struct stc_dmac_dmacb6_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t FS         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb6_field_t;

typedef struct stc_dmac_dmaca7_field
{
  volatile uint32_t TC         : 16;
  volatile uint32_t BC         : 4;
       uint32_t RESERVED1  : 3;
  volatile uint32_t IS         : 6;
  volatile uint32_t ST         : 1;
  volatile uint32_t PB         : 1;
  volatile uint32_t EB         : 1;
} stc_dmac_dmaca7_field_t;

typedef struct stc_dmac_dmacb7_field
{
  volatile uint32_t EM         : 1;
       uint32_t RESERVED1  : 15;
  volatile uint32_t SS         : 3;
  volatile uint32_t CI         : 1;
  volatile uint32_t EI         : 1;
  volatile uint32_t RD         : 1;
  volatile uint32_t RS         : 1;
  volatile uint32_t RC         : 1;
  volatile uint32_t FD         : 1;
  volatile uint32_t FS         : 1;
  volatile uint32_t TW         : 2;
  volatile uint32_t MS         : 2;
} stc_dmac_dmacb7_field_t;



 
 
typedef struct stc_can_ctrlr_field
{
  volatile uint16_t INIT       : 1;
  volatile uint16_t IE         : 1;
  volatile uint16_t SIE        : 1;
  volatile uint16_t EIE        : 1;
       uint16_t RESERVED1  : 1;
  volatile uint16_t DAR        : 1;
  volatile uint16_t CCE        : 1;
  volatile uint16_t TEST       : 1;
} stc_can_ctrlr_field_t;

typedef struct stc_can_statr_field
{
  volatile uint16_t LEC        : 3;
  volatile uint16_t TXOK       : 1;
  volatile uint16_t RXOK       : 1;
  volatile uint16_t EPASS      : 1;
  volatile uint16_t EWARN      : 1;
  volatile uint16_t BOFF       : 1;
} stc_can_statr_field_t;

typedef struct stc_can_errcnt_field
{
  volatile uint16_t TEC0       : 1;
  volatile uint16_t TEC1       : 1;
  volatile uint16_t TEC2       : 1;
  volatile uint16_t TEC3       : 1;
  volatile uint16_t TEC4       : 1;
  volatile uint16_t TEC5       : 1;
  volatile uint16_t TEC6       : 1;
  volatile uint16_t TEC7       : 1;
  volatile uint16_t REC0       : 1;
  volatile uint16_t REC1       : 1;
  volatile uint16_t REC2       : 1;
  volatile uint16_t REC3       : 1;
  volatile uint16_t REC4       : 1;
  volatile uint16_t REC5       : 1;
  volatile uint16_t REC6       : 1;
  volatile uint16_t RP         : 1;
} stc_can_errcnt_field_t;

typedef struct stc_can_btr_field
{
  volatile uint16_t BRP        : 6;
  volatile uint16_t SJW        : 2;
  volatile uint16_t TSEG1      : 4;
  volatile uint16_t TSEG2      : 3;
} stc_can_btr_field_t;

typedef struct stc_can_intr_field
{
  volatile uint16_t INTID0     : 1;
  volatile uint16_t INTID1     : 1;
  volatile uint16_t INTID2     : 1;
  volatile uint16_t INTID3     : 1;
  volatile uint16_t INTID4     : 1;
  volatile uint16_t INTID5     : 1;
  volatile uint16_t INTID6     : 1;
  volatile uint16_t INTID7     : 1;
  volatile uint16_t INTID8     : 1;
  volatile uint16_t INTID9     : 1;
  volatile uint16_t INTID10    : 1;
  volatile uint16_t INTID11    : 1;
  volatile uint16_t INTID12    : 1;
  volatile uint16_t INTID13    : 1;
  volatile uint16_t INTID14    : 1;
  volatile uint16_t INTID15    : 1;
} stc_can_intr_field_t;

typedef struct stc_can_testr_field
{
       uint16_t RESERVED1  : 2;
  volatile uint16_t BASIC      : 1;
  volatile uint16_t SILENT     : 1;
  volatile uint16_t LBACK      : 1;
  volatile uint16_t TX0        : 1;
  volatile uint16_t TX1        : 1;
  volatile uint16_t RX         : 1;
} stc_can_testr_field_t;

typedef struct stc_can_brper_field
{
  volatile uint16_t BRPE0      : 1;
  volatile uint16_t BRPE1      : 1;
  volatile uint16_t BRPE2      : 1;
  volatile uint16_t BRPE3      : 1;
} stc_can_brper_field_t;

typedef struct stc_can_if1creq_field
{
       uint16_t RESERVED1  : 15;
  volatile uint16_t BUSY       : 1;
} stc_can_if1creq_field_t;

typedef struct stc_can_if1cmsk_field
{
  volatile uint16_t DATAB      : 1;
  volatile uint16_t DATAA      : 1;
  volatile uint16_t NEWDAT     : 1;
  volatile uint16_t CIP        : 1;
  volatile uint16_t CONTROL    : 1;
  volatile uint16_t ARB        : 1;
  volatile uint16_t MASK       : 1;
  volatile uint16_t WRRD       : 1;
} stc_can_if1cmsk_field_t;

typedef struct stc_can_if1msk_field
{
  volatile uint32_t MSK        : 29;
       uint32_t RESERVED1  : 1;
  volatile uint32_t MDIR       : 1;
  volatile uint32_t MXTD       : 1;
} stc_can_if1msk_field_t;

typedef struct stc_can_if1msk2_field
{
       uint16_t RESERVED1  : 14;
  volatile uint16_t MDIR       : 1;
  volatile uint16_t MXTD       : 1;
} stc_can_if1msk2_field_t;

typedef struct stc_can_if1arb_field
{
  volatile uint32_t ID         : 29;
  volatile uint32_t DIR        : 1;
  volatile uint32_t XTD        : 1;
  volatile uint32_t MSGVAL     : 1;
} stc_can_if1arb_field_t;

typedef struct stc_can_if1arb2_field
{
       uint16_t RESERVED1  : 13;
  volatile uint16_t DIR        : 1;
  volatile uint16_t XTD        : 1;
  volatile uint16_t MSGVAL     : 1;
} stc_can_if1arb2_field_t;

typedef struct stc_can_if1mctr_field
{
  volatile uint16_t DLC        : 4;
       uint16_t RESERVED1  : 3;
  volatile uint16_t EOB        : 1;
  volatile uint16_t TXRQST     : 1;
  volatile uint16_t RMTEN      : 1;
  volatile uint16_t RXIE       : 1;
  volatile uint16_t TXIE       : 1;
  volatile uint16_t UMASK      : 1;
  volatile uint16_t INTPND     : 1;
  volatile uint16_t MSGLST     : 1;
  volatile uint16_t NEWDAT     : 1;
} stc_can_if1mctr_field_t;

typedef struct stc_can_if2creq_field
{
       uint16_t RESERVED1  : 15;
  volatile uint16_t BUSY       : 1;
} stc_can_if2creq_field_t;

typedef struct stc_can_if2cmsk_field
{
  volatile uint16_t DATAB      : 1;
  volatile uint16_t DATAA      : 1;
  volatile uint16_t NEWDAT     : 1;
  volatile uint16_t CIP        : 1;
  volatile uint16_t CONTROL    : 1;
  volatile uint16_t ARB        : 1;
  volatile uint16_t MASK       : 1;
  volatile uint16_t WRRD       : 1;
} stc_can_if2cmsk_field_t;

typedef struct stc_can_if2msk_field
{
       uint32_t RESERVED1  : 30;
  volatile uint32_t MDIR       : 1;
  volatile uint32_t MXTD       : 1;
} stc_can_if2msk_field_t;

typedef struct stc_can_if2msk2_field
{
       uint16_t RESERVED1  : 14;
  volatile uint16_t MDIR       : 1;
  volatile uint16_t MXTD       : 1;
} stc_can_if2msk2_field_t;

typedef struct stc_can_if2arb2_field
{
       uint16_t RESERVED1  : 13;
  volatile uint16_t DIR        : 1;
  volatile uint16_t XTD        : 1;
  volatile uint16_t MSGVAL     : 1;
} stc_can_if2arb2_field_t;

typedef struct stc_can_if2mctr_field
{
  volatile uint16_t DLC        : 4;
       uint16_t RESERVED1  : 3;
  volatile uint16_t EOB        : 1;
  volatile uint16_t TXRQST     : 1;
  volatile uint16_t RMTEN      : 1;
  volatile uint16_t RXIE       : 1;
  volatile uint16_t TXIE       : 1;
  volatile uint16_t UMASK      : 1;
  volatile uint16_t INTPND     : 1;
  volatile uint16_t MSGLST     : 1;
  volatile uint16_t NEWDAT     : 1;
} stc_can_if2mctr_field_t;

typedef struct stc_can_treqr_field
{
  volatile uint32_t TXRQST1    : 1;
  volatile uint32_t TXRQST2    : 1;
  volatile uint32_t TXRQST3    : 1;
  volatile uint32_t TXRQST4    : 1;
  volatile uint32_t TXRQST5    : 1;
  volatile uint32_t TXRQST6    : 1;
  volatile uint32_t TXRQST7    : 1;
  volatile uint32_t TXRQST8    : 1;
  volatile uint32_t TXRQST9    : 1;
  volatile uint32_t TXRQST10   : 1;
  volatile uint32_t TXRQST11   : 1;
  volatile uint32_t TXRQST12   : 1;
  volatile uint32_t TXRQST13   : 1;
  volatile uint32_t TXRQST14   : 1;
  volatile uint32_t TXRQST15   : 1;
  volatile uint32_t TXRQST16   : 1;
  volatile uint32_t TXRQST17   : 1;
  volatile uint32_t TXRQST18   : 1;
  volatile uint32_t TXRQST19   : 1;
  volatile uint32_t TXRQST20   : 1;
  volatile uint32_t TXRQST21   : 1;
  volatile uint32_t TXRQST22   : 1;
  volatile uint32_t TXRQST23   : 1;
  volatile uint32_t TXRQST24   : 1;
  volatile uint32_t TXRQST25   : 1;
  volatile uint32_t TXRQST26   : 1;
  volatile uint32_t TXRQST27   : 1;
  volatile uint32_t TXRQST28   : 1;
  volatile uint32_t TXRQST29   : 1;
  volatile uint32_t TXRQST30   : 1;
  volatile uint32_t TXRQST31   : 1;
  volatile uint32_t TXRQST32   : 1;
} stc_can_treqr_field_t;

typedef struct stc_can_treqr1_field
{
  volatile uint16_t TXRQST1    : 1;
  volatile uint16_t TXRQST2    : 1;
  volatile uint16_t TXRQST3    : 1;
  volatile uint16_t TXRQST4    : 1;
  volatile uint16_t TXRQST5    : 1;
  volatile uint16_t TXRQST6    : 1;
  volatile uint16_t TXRQST7    : 1;
  volatile uint16_t TXRQST8    : 1;
  volatile uint16_t TXRQST9    : 1;
  volatile uint16_t TXRQST10   : 1;
  volatile uint16_t TXRQST11   : 1;
  volatile uint16_t TXRQST12   : 1;
  volatile uint16_t TXRQST13   : 1;
  volatile uint16_t TXRQST14   : 1;
  volatile uint16_t TXRQST15   : 1;
  volatile uint16_t TXRQST16   : 1;
} stc_can_treqr1_field_t;

typedef struct stc_can_treqr2_field
{
  volatile uint16_t TXRQST17   : 1;
  volatile uint16_t TXRQST18   : 1;
  volatile uint16_t TXRQST19   : 1;
  volatile uint16_t TXRQST20   : 1;
  volatile uint16_t TXRQST21   : 1;
  volatile uint16_t TXRQST22   : 1;
  volatile uint16_t TXRQST23   : 1;
  volatile uint16_t TXRQST24   : 1;
  volatile uint16_t TXRQST25   : 1;
  volatile uint16_t TXRQST26   : 1;
  volatile uint16_t TXRQST27   : 1;
  volatile uint16_t TXRQST28   : 1;
  volatile uint16_t TXRQST29   : 1;
  volatile uint16_t TXRQST30   : 1;
  volatile uint16_t TXRQST31   : 1;
  volatile uint16_t TXRQST32   : 1;
} stc_can_treqr2_field_t;

typedef struct stc_can_newdt_field
{
  volatile uint32_t NEWDAT1    : 1;
  volatile uint32_t NEWDAT2    : 1;
  volatile uint32_t NEWDAT3    : 1;
  volatile uint32_t NEWDAT4    : 1;
  volatile uint32_t NEWDAT5    : 1;
  volatile uint32_t NEWDAT6    : 1;
  volatile uint32_t NEWDAT7    : 1;
  volatile uint32_t NEWDAT8    : 1;
  volatile uint32_t NEWDAT9    : 1;
  volatile uint32_t NEWDAT10   : 1;
  volatile uint32_t NEWDAT11   : 1;
  volatile uint32_t NEWDAT12   : 1;
  volatile uint32_t NEWDAT13   : 1;
  volatile uint32_t NEWDAT14   : 1;
  volatile uint32_t NEWDAT15   : 1;
  volatile uint32_t NEWDAT16   : 1;
  volatile uint32_t NEWDAT17   : 1;
  volatile uint32_t NEWDAT18   : 1;
  volatile uint32_t NEWDAT19   : 1;
  volatile uint32_t NEWDAT20   : 1;
  volatile uint32_t NEWDAT21   : 1;
  volatile uint32_t NEWDAT22   : 1;
  volatile uint32_t NEWDAT23   : 1;
  volatile uint32_t NEWDAT24   : 1;
  volatile uint32_t NEWDAT25   : 1;
  volatile uint32_t NEWDAT26   : 1;
  volatile uint32_t NEWDAT27   : 1;
  volatile uint32_t NEWDAT28   : 1;
  volatile uint32_t NEWDAT29   : 1;
  volatile uint32_t NEWDAT30   : 1;
  volatile uint32_t NEWDAT31   : 1;
  volatile uint32_t NEWDAT32   : 1;
} stc_can_newdt_field_t;

typedef struct stc_can_newdt1_field
{
  volatile uint16_t NEWDAT1    : 1;
  volatile uint16_t NEWDAT2    : 1;
  volatile uint16_t NEWDAT3    : 1;
  volatile uint16_t NEWDAT4    : 1;
  volatile uint16_t NEWDAT5    : 1;
  volatile uint16_t NEWDAT6    : 1;
  volatile uint16_t NEWDAT7    : 1;
  volatile uint16_t NEWDAT8    : 1;
  volatile uint16_t NEWDAT9    : 1;
  volatile uint16_t NEWDAT10   : 1;
  volatile uint16_t NEWDAT11   : 1;
  volatile uint16_t NEWDAT12   : 1;
  volatile uint16_t NEWDAT13   : 1;
  volatile uint16_t NEWDAT14   : 1;
  volatile uint16_t NEWDAT15   : 1;
  volatile uint16_t NEWDAT16   : 1;
} stc_can_newdt1_field_t;

typedef struct stc_can_intpnd_field
{
  volatile uint32_t INTPND1    : 1;
  volatile uint32_t INTPND2    : 1;
  volatile uint32_t INTPND3    : 1;
  volatile uint32_t INTPND4    : 1;
  volatile uint32_t INTPND5    : 1;
  volatile uint32_t INTPND6    : 1;
  volatile uint32_t INTPND7    : 1;
  volatile uint32_t INTPND8    : 1;
  volatile uint32_t INTPND9    : 1;
  volatile uint32_t INTPND10   : 1;
  volatile uint32_t INTPND11   : 1;
  volatile uint32_t INTPND12   : 1;
  volatile uint32_t INTPND13   : 1;
  volatile uint32_t INTPND14   : 1;
  volatile uint32_t INTPND15   : 1;
  volatile uint32_t INTPND16   : 1;
  volatile uint32_t INTPND17   : 1;
  volatile uint32_t INTPND18   : 1;
  volatile uint32_t INTPND19   : 1;
  volatile uint32_t INTPND20   : 1;
  volatile uint32_t INTPND21   : 1;
  volatile uint32_t INTPND22   : 1;
  volatile uint32_t INTPND23   : 1;
  volatile uint32_t INTPND24   : 1;
  volatile uint32_t INTPND25   : 1;
  volatile uint32_t INTPND26   : 1;
  volatile uint32_t INTPND27   : 1;
  volatile uint32_t INTPND28   : 1;
  volatile uint32_t INTPND29   : 1;
  volatile uint32_t INTPND30   : 1;
  volatile uint32_t INTPND31   : 1;
  volatile uint32_t INTPND32   : 1;
} stc_can_intpnd_field_t;

typedef struct stc_can_intpnd1_field
{
  volatile uint16_t INTPND1    : 1;
  volatile uint16_t INTPND2    : 1;
  volatile uint16_t INTPND3    : 1;
  volatile uint16_t INTPND4    : 1;
  volatile uint16_t INTPND5    : 1;
  volatile uint16_t INTPND6    : 1;
  volatile uint16_t INTPND7    : 1;
  volatile uint16_t INTPND8    : 1;
  volatile uint16_t INTPND9    : 1;
  volatile uint16_t INTPND10   : 1;
  volatile uint16_t INTPND11   : 1;
  volatile uint16_t INTPND12   : 1;
  volatile uint16_t INTPND13   : 1;
  volatile uint16_t INTPND14   : 1;
  volatile uint16_t INTPND15   : 1;
  volatile uint16_t INTPND16   : 1;
} stc_can_intpnd1_field_t;

typedef struct stc_can_intpnd2_field
{
  volatile uint16_t INTPND17   : 1;
  volatile uint16_t INTPND18   : 1;
  volatile uint16_t INTPND19   : 1;
  volatile uint16_t INTPND20   : 1;
  volatile uint16_t INTPND21   : 1;
  volatile uint16_t INTPND22   : 1;
  volatile uint16_t INTPND23   : 1;
  volatile uint16_t INTPND24   : 1;
  volatile uint16_t INTPND25   : 1;
  volatile uint16_t INTPND26   : 1;
  volatile uint16_t INTPND27   : 1;
  volatile uint16_t INTPND28   : 1;
  volatile uint16_t INTPND29   : 1;
  volatile uint16_t INTPND30   : 1;
  volatile uint16_t INTPND31   : 1;
  volatile uint16_t INTPND32   : 1;
} stc_can_intpnd2_field_t;

typedef struct stc_can_msgval_field
{
  volatile uint32_t MSGVAL1    : 1;
  volatile uint32_t MSGVAL2    : 1;
  volatile uint32_t MSGVAL3    : 1;
  volatile uint32_t MSGVAL4    : 1;
  volatile uint32_t MSGVAL5    : 1;
  volatile uint32_t MSGVAL6    : 1;
  volatile uint32_t MSGVAL7    : 1;
  volatile uint32_t MSGVAL8    : 1;
  volatile uint32_t MSGVAL9    : 1;
  volatile uint32_t MSGVAL10   : 1;
  volatile uint32_t MSGVAL11   : 1;
  volatile uint32_t MSGVAL12   : 1;
  volatile uint32_t MSGVAL13   : 1;
  volatile uint32_t MSGVAL14   : 1;
  volatile uint32_t MSGVAL15   : 1;
  volatile uint32_t MSGVAL16   : 1;
  volatile uint32_t MSGVAL17   : 1;
  volatile uint32_t MSGVAL18   : 1;
  volatile uint32_t MSGVAL19   : 1;
  volatile uint32_t MSGVAL20   : 1;
  volatile uint32_t MSGVAL21   : 1;
  volatile uint32_t MSGVAL22   : 1;
  volatile uint32_t MSGVAL23   : 1;
  volatile uint32_t MSGVAL24   : 1;
  volatile uint32_t MSGVAL25   : 1;
  volatile uint32_t MSGVAL26   : 1;
  volatile uint32_t MSGVAL27   : 1;
  volatile uint32_t MSGVAL28   : 1;
  volatile uint32_t MSGVAL29   : 1;
  volatile uint32_t MSGVAL30   : 1;
  volatile uint32_t MSGVAL31   : 1;
  volatile uint32_t MSGVAL32   : 1;
} stc_can_msgval_field_t;

typedef struct stc_can_msgval1_field
{
  volatile uint16_t MSGVAL1    : 1;
  volatile uint16_t MSGVAL2    : 1;
  volatile uint16_t MSGVAL3    : 1;
  volatile uint16_t MSGVAL4    : 1;
  volatile uint16_t MSGVAL5    : 1;
  volatile uint16_t MSGVAL6    : 1;
  volatile uint16_t MSGVAL7    : 1;
  volatile uint16_t MSGVAL8    : 1;
  volatile uint16_t MSGVAL9    : 1;
  volatile uint16_t MSGVAL10   : 1;
  volatile uint16_t MSGVAL11   : 1;
  volatile uint16_t MSGVAL12   : 1;
  volatile uint16_t MSGVAL13   : 1;
  volatile uint16_t MSGVAL14   : 1;
  volatile uint16_t MSGVAL15   : 1;
  volatile uint16_t MSGVAL16   : 1;
} stc_can_msgval1_field_t;

typedef struct stc_can_msgval2_field
{
  volatile uint16_t MSGVAL17   : 1;
  volatile uint16_t MSGVAL18   : 1;
  volatile uint16_t MSGVAL19   : 1;
  volatile uint16_t MSGVAL20   : 1;
  volatile uint16_t MSGVAL21   : 1;
  volatile uint16_t MSGVAL22   : 1;
  volatile uint16_t MSGVAL23   : 1;
  volatile uint16_t MSGVAL24   : 1;
  volatile uint16_t MSGVAL25   : 1;
  volatile uint16_t MSGVAL26   : 1;
  volatile uint16_t MSGVAL27   : 1;
  volatile uint16_t MSGVAL28   : 1;
  volatile uint16_t MSGVAL29   : 1;
  volatile uint16_t MSGVAL30   : 1;
  volatile uint16_t MSGVAL31   : 1;
  volatile uint16_t MSGVAL32   : 1;
} stc_can_msgval2_field_t;



 
 
typedef struct stc_sdif_sbsize_field
{
  volatile uint16_t TRSFBLCKSZ : 12;
  volatile uint16_t HSDMABUFBD : 3;
       uint16_t RESERVED1  : 1;
} stc_sdif_sbsize_field_t;

typedef struct stc_sdif_strsfmd_field
{
  volatile uint16_t DMAEN      : 1;
  volatile uint16_t BLCKCNTEN  : 1;
  volatile uint16_t AUTOCMDEN  : 2;
  volatile uint16_t DTTRSFDIR  : 1;
  volatile uint16_t BLCKCNTSEL : 1;
} stc_sdif_strsfmd_field_t;

typedef struct stc_sdif_scmmd_field
{
  volatile uint16_t RESPTYPE   : 2;
       uint16_t RESERVED1  : 1;
  volatile uint16_t CMDCRCCHKE : 1;
  volatile uint16_t CMDIDXCHKE : 1;
  volatile uint16_t DATPRESSEL : 1;
  volatile uint16_t CMDTYPE    : 2;
  volatile uint16_t CMDINDEX   : 6;
} stc_sdif_scmmd_field_t;

typedef struct stc_sdif_sprstat_field
{
  volatile uint32_t CMDINH     : 1;
  volatile uint32_t CMDDATINH : 1;
  volatile uint32_t DATLNACT   : 1;
  volatile uint32_t RETUNEREQ  : 1;
       uint32_t RESERVED1  : 4;
  volatile uint32_t WRTRSFACT  : 1;
  volatile uint32_t RDTRSFACT  : 1;
  volatile uint32_t BUFWREN    : 1;
  volatile uint32_t BUFRDEN    : 1;
       uint32_t RESERVED2  : 4;
  volatile uint32_t CARDINS    : 1;
  volatile uint32_t CARDSTB    : 1;
  volatile uint32_t CARDDET    : 1;
  volatile uint32_t WPPINLVL   : 1;
  volatile uint32_t LNSGNLVL   : 4;
  volatile uint32_t CMDLNSGN   : 1;
       uint32_t RESERVED3  : 7;
} stc_sdif_sprstat_field_t;

typedef struct stc_sdif_shctl1_field
{
  volatile uint8_t LEDCTRL     : 1;
  volatile uint8_t DATAWIDTH   : 1;
  volatile uint8_t HIGHSPDEN   : 1;
  volatile uint8_t DMASEL      : 2;
  volatile uint8_t EXTDTWIDTH  : 1;
  volatile uint8_t CDTSTLVL    : 1;
  volatile uint8_t CDSGNSEL    : 1;
} stc_sdif_shctl1_field_t;

typedef struct stc_sdif_spwrctl_field
{
  volatile uint8_t SDBUSPWR    : 1;
  volatile uint8_t SDBUSVLSEL  : 3;
       uint8_t RESERVED1   : 4;
} stc_sdif_spwrctl_field_t;

typedef struct stc_sdif_sblkgpctl_field
{
  volatile uint8_t BLCKGSTPREQ : 1;
  volatile uint8_t CONTREQ     : 1;
  volatile uint8_t RDWAITCTL   : 1;
  volatile uint8_t BLCKGAPINT  : 1;
       uint8_t RESERVED1   : 4;
} stc_sdif_sblkgpctl_field_t;

typedef struct stc_sdif_swkupctl_field
{
  volatile uint8_t WKUPEVNTEN0 : 1;
  volatile uint8_t WKUPEVNTEN1 : 1;
  volatile uint8_t WKUPEVNTEN2 : 1;
       uint8_t RESERVED1   : 5;
} stc_sdif_swkupctl_field_t;

typedef struct stc_sdif_sclkctl_field
{
  volatile uint16_t INTLCLCKEN : 1;
  volatile uint16_t INTLCLCKST : 1;
  volatile uint16_t SDCLCKEN   : 1;
       uint16_t RESERVED1  : 2;
  volatile uint16_t CLCKGENSEL : 1;
  volatile uint16_t UPSDCLKSEL : 2;
  volatile uint16_t SDCLKSEL   : 8;
} stc_sdif_sclkctl_field_t;

typedef struct stc_sdif_stoctl_field
{
  volatile uint8_t DTTMOUTVAL : 4;
       uint8_t RESERVED1  : 4;
} stc_sdif_stoctl_field_t;

typedef struct stc_sdif_ssrst_field
{
  volatile uint8_t SWRSTALL   : 1;
  volatile uint8_t SWRSTCMDLN : 1;
  volatile uint8_t SWRSTDATLN : 1;
       uint8_t RESERVED1  : 5;
} stc_sdif_ssrst_field_t;

typedef struct stc_sdif_snintst_field
{
  volatile uint16_t CMDCMPLT  : 1;
  volatile uint16_t TRSFCMPLT : 1;
  volatile uint16_t BLCKGEVNT : 1;
  volatile uint16_t DMAINT    : 1;
  volatile uint16_t BUFWRRDY  : 1;
  volatile uint16_t BUFRDRDY  : 1;
  volatile uint16_t CARDINS   : 1;
  volatile uint16_t CARDRMV   : 1;
  volatile uint16_t CARDINT   : 1;
  volatile uint16_t INT_A     : 1;
  volatile uint16_t INT_B     : 1;
  volatile uint16_t INT_C     : 1;
  volatile uint16_t RETUNEEVT : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t ERRORINT  : 1;
} stc_sdif_snintst_field_t;

typedef struct stc_sdif_seintst_field
{
  volatile uint16_t CMDTOERR  : 1;
  volatile uint16_t CMDCRCERR : 1;
  volatile uint16_t CMDEBERR  : 1;
  volatile uint16_t CMDIDXERR : 1;
  volatile uint16_t DTTOERR   : 1;
  volatile uint16_t DTEBERR   : 1;
  volatile uint16_t DTCRCERR  : 1;
  volatile uint16_t CRTLMTERR : 1;
  volatile uint16_t ACMD12ERR : 1;
  volatile uint16_t ADMAERR   : 1;
  volatile uint16_t TUNINGERR : 1;
       uint16_t RESERVED1 : 1;
  volatile uint16_t BTACKERR  : 1;
  volatile uint16_t ACMD19ERR : 1;
  volatile uint16_t AHBMSTERR : 1;
       uint16_t RESERVED2 : 1;
} stc_sdif_seintst_field_t;

typedef struct stc_sdif_snintste_field
{
  volatile uint16_t CMDCMPLTS : 1;
  volatile uint16_t TRSFCMPLTS: 1;
  volatile uint16_t BLCKGEVNTS: 1;
  volatile uint16_t DMAINTS   : 1;
  volatile uint16_t BUFWRRDYS : 1;
  volatile uint16_t BUFRDRDYS : 1;
  volatile uint16_t CARDINSS  : 1;
  volatile uint16_t CARDRMVS  : 1;
  volatile uint16_t CARDINTS  : 1;
  volatile uint16_t INT_AS    : 1;
  volatile uint16_t INT_BS    : 1;
  volatile uint16_t INT_CS    : 1;
  volatile uint16_t RETUNEEVTS: 1;
       uint16_t RESERVED1 : 3;
} stc_sdif_snintste_field_t;

typedef struct stc_sdif_seintste_field
{
  volatile uint16_t CMDTOERRS : 1;
  volatile uint16_t CMDCRCERRS: 1;
  volatile uint16_t CMDEBERRS : 1;
  volatile uint16_t CMDIDXERRS: 1;
  volatile uint16_t DTTOERRS  : 1;
  volatile uint16_t DTEBERRS  : 1;
  volatile uint16_t DTCRCERRS : 1;
  volatile uint16_t CRTLMTERRS: 1;
  volatile uint16_t ACMD12ERRS: 1;
  volatile uint16_t ADMAERRS  : 1;
  volatile uint16_t TUNINGERRS: 1;
       uint16_t RESERVED1 : 1;
  volatile uint16_t BTACKERRS : 1;
  volatile uint16_t ACMD19ERRS: 1;
  volatile uint16_t AHBMSTERRS: 1;
       uint16_t RESERVED2 : 1;
} stc_sdif_seintste_field_t;

typedef struct stc_sdif_snintsge_field
{
  volatile uint16_t CMDCMPLTG : 1;
  volatile uint16_t TRSFCMPLTG: 1;
  volatile uint16_t BLCKGEVNTG: 1;
  volatile uint16_t DMAINTG   : 1;
  volatile uint16_t BUFWRRDYG : 1;
  volatile uint16_t BUFRDRDYG : 1;
  volatile uint16_t CARDINSG  : 1;
  volatile uint16_t CARDRMVG  : 1;
  volatile uint16_t CARDINTG  : 1;
  volatile uint16_t INT_AG    : 1;
  volatile uint16_t INT_BG    : 1;
  volatile uint16_t INT_CG    : 1;
  volatile uint16_t RETUNEEVTG: 1;
       uint16_t RESERVED1 : 3;
} stc_sdif_snintsge_field_t;

typedef struct stc_sdif_seintsge_field
{
  volatile uint16_t CMDTOERRG : 1;
  volatile uint16_t CMDCRCERRG: 1;
  volatile uint16_t CMDEBERRG : 1;
  volatile uint16_t CMDIDXERRG: 1;
  volatile uint16_t DTTOERRG  : 1;
  volatile uint16_t DTEBERRG  : 1;
  volatile uint16_t DTCRCERRG : 1;
  volatile uint16_t CRTLMTERRG: 1;
  volatile uint16_t ACMD12ERRG: 1;
  volatile uint16_t ADMAERRG  : 1;
  volatile uint16_t TUNINGERRG: 1;
       uint16_t RESERVED1 : 1;
  volatile uint16_t BTACKERRG : 1;
  volatile uint16_t ACMD19ERRG: 1;
  volatile uint16_t AHBMSTERRG: 1;
       uint16_t RESERVED2 : 1;
} stc_sdif_seintsge_field_t;

typedef struct stc_sdif_sacmdest_field
{
  volatile uint16_t ACMD12NOEX: 1;
  volatile uint16_t ACMDTOERR : 1;
  volatile uint16_t ACMDCRCERR: 1;
  volatile uint16_t ACMDEBERR : 1;
  volatile uint16_t ACMDIDXERR: 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t CMDND12ERR: 1;
       uint16_t RESERVED2 : 8;
} stc_sdif_sacmdest_field_t;

typedef struct stc_sdif_shctl2_field
{
  volatile uint16_t UHSMDSEL  : 3;
  volatile uint16_t V18SGNEN  : 1;
  volatile uint16_t DRVSEL    : 2;
  volatile uint16_t DOTUING   : 1;
  volatile uint16_t SMPCLKSEK : 1;
       uint16_t RESERVED1 : 6;
  volatile uint16_t ASYINTEN  : 1;
  volatile uint16_t PREVALEN  : 1;
} stc_sdif_shctl2_field_t;

typedef struct stc_sdif_capblty0_field
{
  volatile uint16_t TOCLKFREQ : 6;
       uint16_t RESERVED1 : 1;
  volatile uint16_t TOCLKUNIT : 1;
  volatile uint16_t SDBASECLK : 8;
} stc_sdif_capblty0_field_t;

typedef struct stc_sdif_capblty1_field
{
  volatile uint16_t MAXBLCKLEN: 2;
  volatile uint16_t EMBD8BIT  : 1;
  volatile uint16_t ADMA2SPT  : 1;
       uint16_t RESERVED1 : 1;
  volatile uint16_t HGHSPDSPT : 1;
  volatile uint16_t SDMASPT   : 1;
  volatile uint16_t LWPWRSPT  : 1;
  volatile uint16_t V33SPT    : 1;
  volatile uint16_t V30SPT    : 1;
  volatile uint16_t V18SPT    : 1;
       uint16_t RESERVED2 : 1;
  volatile uint16_t BUS64SPT  : 1;
  volatile uint16_t ASYINTSPT : 1;
  volatile uint16_t STOPTYPE  : 2;
} stc_sdif_capblty1_field_t;

typedef struct stc_sdif_capblty2_field
{
  volatile uint16_t SDR50SPT  : 1;
  volatile uint16_t SDR104SPT : 1;
  volatile uint16_t DDR50SPT  : 1;
       uint16_t RESERVED1 : 1;
  volatile uint16_t DRVTPASPT : 1;
  volatile uint16_t DRVTPBSPT : 1;
  volatile uint16_t DRVTPCSPT : 1;
       uint16_t RESERVED2 : 1;
  volatile uint16_t TMCNTRETN : 4;
       uint16_t RESERVED3 : 1;
  volatile uint16_t USETNSDR50: 1;
  volatile uint16_t RETNMODE  : 2;
} stc_sdif_capblty2_field_t;

typedef struct stc_sdif_capblty3_field
{
  volatile uint16_t CLKMULTPL : 8;
       uint16_t RESERVED1 : 8;
} stc_sdif_capblty3_field_t;

typedef struct stc_sdif_mxccapy0_field
{
  volatile uint16_t V33MAXCUR : 8;
  volatile uint16_t V30MAXCUR : 8;
} stc_sdif_mxccapy0_field_t;

typedef struct stc_sdif_mxccapy1_field
{
  volatile uint16_t V18MAXCUR : 8;
       uint16_t RESERVED1 : 8;
} stc_sdif_mxccapy1_field_t;

typedef struct stc_sdif_mxccapy2_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_mxccapy2_field_t;

typedef struct stc_sdif_mxccapy3_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_mxccapy3_field_t;

typedef struct stc_sdif_feacest_field
{
  volatile uint16_t FEVNT12ND : 1;
  volatile uint16_t FEVNTTO   : 1;
  volatile uint16_t FEVNTCRC  : 1;
  volatile uint16_t FEVNTEB   : 1;
  volatile uint16_t FEVNTIDX  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t FEVNTCMD12: 1;
       uint16_t RESERVED2 : 8;
} stc_sdif_feacest_field_t;

typedef struct stc_sdif_sfeeist_field
{
  volatile uint16_t FETOERR   : 1;
  volatile uint16_t FECRCERR  : 1;
  volatile uint16_t FEEBERR   : 1;
  volatile uint16_t FEIDXERR  : 1;
  volatile uint16_t FEDTOTERR : 1;
  volatile uint16_t FEDTCRCERR: 1;
  volatile uint16_t FEDTEBERR : 1;
  volatile uint16_t FECRLTERR : 1;
  volatile uint16_t FEA12ERR  : 1;
  volatile uint16_t FEADMAERR : 1;
  volatile uint16_t FETUNEERR : 1;
       uint16_t RESERVED1 : 1;
  volatile uint16_t FEACKERR  : 1;
  volatile uint16_t FEA19ERR  : 1;
  volatile uint16_t FEAHBMSERR: 1;
       uint16_t RESERVED2 : 1;
} stc_sdif_sfeeist_field_t;

typedef struct stc_sdif_admaest_field
{
  volatile uint8_t ADMAERRS  : 2;
  volatile uint8_t ADMALENME : 1;
       uint8_t RESERVED1 : 5;
} stc_sdif_admaest_field_t;

typedef struct stc_sdif_sadsa0_field
{
  volatile uint16_t ADR1500   : 16;
} stc_sdif_sadsa0_field_t;

typedef struct stc_sdif_sadsa1_field
{
  volatile uint16_t ADR3116   : 16;
} stc_sdif_sadsa1_field_t;

typedef struct stc_sdif_sadsa2_field
{
  volatile uint16_t ADR4732   : 16;
} stc_sdif_sadsa2_field_t;

typedef struct stc_sdif_sadsa3_field
{
  volatile uint16_t ADR6348   : 16;
} stc_sdif_sadsa3_field_t;

typedef struct stc_sdif_sprval0_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval0_field_t;

typedef struct stc_sdif_sprval1_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval1_field_t;

typedef struct stc_sdif_sprval2_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval2_field_t;

typedef struct stc_sdif_sprval3_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval3_field_t;

typedef struct stc_sdif_sprval4_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval4_field_t;

typedef struct stc_sdif_sprval5_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval5_field_t;

typedef struct stc_sdif_sprval6_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval6_field_t;

typedef struct stc_sdif_sprval7_field
{
  volatile uint16_t SCFSELVAL : 10;
  volatile uint16_t CGSELVAL  : 1;
       uint16_t RESERVED1 : 2;
  volatile uint16_t DSSELVAL  : 2;
} stc_sdif_sprval7_field_t;

typedef struct stc_sdif_sshbctll_field
{
  volatile uint16_t CLCKPIN   : 3;
       uint16_t RESERVED1 : 1;
  volatile uint16_t INTINPIN  : 2;
       uint16_t RESERVED2 : 2;
  volatile uint16_t BUSWDPRST : 7;
       uint16_t RESERVED3 : 1;
} stc_sdif_sshbctll_field_t;

typedef struct stc_sdif_sshbctlh_field
{
  volatile uint16_t CLCKPINSEL: 3;
       uint16_t RESERVED1 : 1;
  volatile uint16_t INTPINSEL : 3;
       uint16_t RESERVED2 : 1;
  volatile uint16_t BEPWRCTL  : 7;
       uint16_t RESERVED3 : 1;
} stc_sdif_sshbctlh_field_t;


typedef struct stc_sdif_sslist_field
{
  volatile uint16_t SLOTINTSGN: 8;
       uint16_t RESERVED1 : 8;
} stc_sdif_sslist_field_t;

typedef struct stc_sdif_shctlv_field
{
  volatile uint16_t SPECVERNUM: 8;
  volatile uint16_t VNDVERNUM : 8;
} stc_sdif_shctlv_field_t;

typedef struct stc_sdif_ahbcfgl_field
{
  volatile uint16_t INCRSEL   : 3;
  volatile uint16_t SINEN     : 1;
  volatile uint16_t BSLOCK    : 1;
  volatile uint16_t BSLOCKSEL : 1;
  volatile uint16_t ENDIANSEL : 1;
       uint16_t RESERVED1 : 9;
} stc_sdif_ahbcfgl_field_t;

typedef struct stc_sdif_ahbcfgh_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_ahbcfgh_field_t;

typedef struct stc_sdif_spwswcl_field
{
  volatile uint16_t ATPWRSWEN : 1;
  volatile uint16_t IOREGSEL  : 1;
       uint16_t RESERVED1 : 14;
} stc_sdif_spwswcl_field_t;

typedef struct stc_sdif_spwswch_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_spwswch_field_t;

typedef struct stc_sdif_stunsetl_field
{
  volatile uint16_t TNPTSEL   : 8;
  volatile uint16_t TNPHSELEN : 1;
  volatile uint16_t TNERRBDSEL: 1;
  volatile uint16_t RETNTAPSEL: 1;
  volatile uint16_t RETNRNGSEL: 2;
       uint16_t RESERVED1 : 3;
} stc_sdif_stunsetl_field_t;

typedef struct stc_sdif_stunseth_field
{
  volatile uint16_t CMDCFCHKDS: 1;
       uint16_t RESERVED1 : 7;
  volatile uint16_t DTOTCNTVAL: 4;
       uint16_t RESERVED2 : 4;
} stc_sdif_stunseth_field_t;

typedef struct stc_sdif_stunstl_field
{
  volatile uint16_t REP8TNRSLT: 8;
  volatile uint16_t REP3TNRSLT: 3;
       uint16_t RESERVED1 : 5;
} stc_sdif_stunstl_field_t;

typedef struct stc_sdif_stunsth_field
{
  volatile uint16_t PRSTTNPNT : 8;
       uint16_t RESERVED1 : 8;
} stc_sdif_stunsth_field_t;

typedef struct stc_sdif_pswistl_field
{
  volatile uint16_t INT5MS    : 1;
  volatile uint16_t INT1MS    : 1;
       uint16_t RESERVED1 : 14;
} stc_sdif_pswistl_field_t;

typedef struct stc_sdif_pswisth_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_pswisth_field_t;


typedef struct stc_sdif_pswistel_field
{
  volatile uint16_t INT5MSSTS : 1;
  volatile uint16_t INT1MSSTS : 1;
       uint16_t RESERVED1 : 14;
} stc_sdif_pswistel_field_t;

typedef struct stc_sdif_pswisteh_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_pswisteh_field_t;

typedef struct stc_sdif_pswisgel_field
{
  volatile uint16_t INT5MSSGEN: 1;
  volatile uint16_t INT1MSSGEN: 1;
       uint16_t RESERVED1 : 14;
} stc_sdif_pswisgel_field_t;

typedef struct stc_sdif_pswisgeh_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_pswisgeh_field_t;

typedef struct stc_sdif_mmcsdcl_field
{
  volatile uint16_t LCKRSTESD : 1;
  volatile uint16_t RSTMMC    : 1;
  volatile uint16_t VCCCTLMMC : 1;
  volatile uint16_t VCCQCTLMMC: 1;
       uint16_t RESERVED1 : 4;
  volatile uint16_t MMCDDRSEL : 1;
  volatile uint16_t CMDDATDLY : 1;
       uint16_t RESERVED2 : 6;
} stc_sdif_mmcsdcl_field_t;

typedef struct stc_sdif_mmcsdch_field
{
  volatile uint16_t BTACKENMMC: 1;
  volatile uint16_t BTABTENMMC: 1;
  volatile uint16_t BTMDENMMC : 1;
       uint16_t RESERVED1 : 13;
} stc_sdif_mmcsdch_field_t;

typedef struct stc_sdif_mcwirqc0_field
{
  volatile uint16_t WTIRQEN   : 1;
  volatile uint16_t WTIRQST   : 1;
       uint16_t RESERVED1 : 14;
} stc_sdif_mcwirqc0_field_t;

typedef struct stc_sdif_mcwirqc1_field
{
  volatile uint16_t WTIRQCNCLR: 16;
} stc_sdif_mcwirqc1_field_t;

typedef struct stc_sdif_mcwirqc2_field
{
  volatile uint16_t WTIRQCNCLR: 16;
} stc_sdif_mcwirqc2_field_t;

typedef struct stc_sdif_mcwirqc3_field
{
  volatile uint16_t WTIRQCNCLR: 16;
} stc_sdif_mcwirqc3_field_t;

typedef struct stc_sdif_mcrpckbl_field
{
  volatile uint16_t CHECKBIT1 : 7;
  volatile uint16_t CHECKBIT2 : 6;
       uint16_t RESERVED1 : 3;
} stc_sdif_mcrpckbl_field_t;

typedef struct stc_sdif_mcrpckbh_field
{
       uint16_t RESERVED1 : 16;
} stc_sdif_mcrpckbh_field_t;

typedef struct stc_sdif_scdetecs_field
{
       uint16_t RESERVED1 : 8;
  volatile uint16_t CDDEBTCVAL: 4;
       uint16_t RESERVED2 : 4;
} stc_sdif_scdetecs_field_t;



 



 
 
typedef struct
{
  union {
    volatile uint32_t WFASZR;
    stc_workflash_if_wfaszr_field_t WFASZR_f;
  };
  union {
    volatile uint32_t WFRWTR;
    stc_workflash_if_wfrwtr_field_t WFRWTR_f;
  };
  union {
    volatile uint32_t WFSTR;
    stc_workflash_if_wfstr_field_t WFSTR_f;
  };
}FM4_WORKFLASH_IF_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t FASZR;
    stc_flash_if_faszr_field_t FASZR_f;
  };
  union {
    volatile uint32_t FRWTR;
    stc_flash_if_frwtr_field_t FRWTR_f;
  };
  union {
    volatile uint32_t FSTR;
    stc_flash_if_fstr_field_t FSTR_f;
  };
       uint8_t RESERVED2[4];
  union {
    volatile uint32_t FSYNDN;
    stc_flash_if_fsyndn_field_t FSYNDN_f;
  };
  union {
    volatile uint32_t FBFCR;
    stc_flash_if_fbfcr_field_t FBFCR_f;
  };
       uint8_t RESERVED4[8];
  union {
    volatile uint32_t FICR;
    stc_flash_if_ficr_field_t FICR_f;
  };
  union {
    volatile uint32_t FISR;
    stc_flash_if_fisr_field_t FISR_f;
  };
  union {
    volatile uint32_t FICLR;
    stc_flash_if_ficlr_field_t FICLR_f;
  };
       uint8_t RESERVED7[212];
  union {
    volatile uint32_t CRTRMM;
    stc_flash_if_crtrmm_field_t CRTRMM_f;
  };
}FM4_FLASH_IF_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t UIDR0;
    stc_unique_id_uidr0_field_t UIDR0_f;
  };
  union {
    volatile uint32_t UIDR1;
    stc_unique_id_uidr1_field_t UIDR1_f;
  };
}FM4_UNIQUE_ID_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t FERRAD;
    stc_ecc_capture_ferrad_field_t FERRAD_f;
  };
}FM4_ECC_CAPTURE_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t SCM_CTL;
    stc_crg_scm_ctl_field_t SCM_CTL_f;
  };
        uint8_t RESERVED0[3];
  union {
    volatile  uint8_t SCM_STR;
    stc_crg_scm_str_field_t SCM_STR_f;
  };
        uint8_t RESERVED1[3];
  volatile uint32_t STB_CTL;
  union {
    volatile uint16_t RST_STR;
    stc_crg_rst_str_field_t RST_STR_f;
  };
        uint8_t RESERVED2[2];
  union {
    volatile  uint8_t BSC_PSR;
    stc_crg_bsc_psr_field_t BSC_PSR_f;
  };
        uint8_t RESERVED3[3];
  union {
    volatile  uint8_t APBC0_PSR;
    stc_crg_apbc0_psr_field_t APBC0_PSR_f;
  };
        uint8_t RESERVED4[3];
  union {
    volatile  uint8_t APBC1_PSR;
    stc_crg_apbc1_psr_field_t APBC1_PSR_f;
  };
        uint8_t RESERVED5[3];
  union {
    volatile  uint8_t APBC2_PSR;
    stc_crg_apbc2_psr_field_t APBC2_PSR_f;
  };
        uint8_t RESERVED6[3];
  union {
    volatile  uint8_t SWC_PSR;
    stc_crg_swc_psr_field_t SWC_PSR_f;
  };
        uint8_t RESERVED7[7];
  union {
    volatile  uint8_t TTC_PSR;
    stc_crg_ttc_psr_field_t TTC_PSR_f;
  };
        uint8_t RESERVED8[7];
  union {
    volatile  uint8_t CSW_TMR;
    stc_crg_csw_tmr_field_t CSW_TMR_f;
  };
        uint8_t RESERVED9[3];
  union {
    volatile  uint8_t PSW_TMR;
    stc_crg_psw_tmr_field_t PSW_TMR_f;
  };
        uint8_t RESERVED10[3];
  union {
    volatile  uint8_t PLL_CTL1;
    stc_crg_pll_ctl1_field_t PLL_CTL1_f;
  };
        uint8_t RESERVED11[3];
  union {
    volatile  uint8_t PLL_CTL2;
    stc_crg_pll_ctl2_field_t PLL_CTL2_f;
  };
        uint8_t RESERVED12[3];
  union {
    volatile uint16_t CSV_CTL;
    stc_crg_csv_ctl_field_t CSV_CTL_f;
  };
        uint8_t RESERVED13[2];
  union {
    volatile  uint8_t CSV_STR;
    stc_crg_csv_str_field_t CSV_STR_f;
  };
        uint8_t RESERVED14[3];
  volatile uint16_t FCSWH_CTL;
        uint8_t RESERVED15[2];
  volatile uint16_t FCSWL_CTL;
        uint8_t RESERVED16[2];
  volatile uint16_t FCSWD_CTL;
        uint8_t RESERVED17[2];
  union {
    volatile  uint8_t DBWDT_CTL;
    stc_crg_dbwdt_ctl_field_t DBWDT_CTL_f;
  };
        uint8_t RESERVED18[11];
  union {
    volatile  uint8_t INT_ENR;
    stc_crg_int_enr_field_t INT_ENR_f;
  };
        uint8_t RESERVED19[3];
  union {
    volatile  uint8_t INT_STR;
    stc_crg_int_str_field_t INT_STR_f;
  };
        uint8_t RESERVED20[3];
  union {
    volatile  uint8_t INT_CLR;
    stc_crg_int_clr_field_t INT_CLR_f;
  };
}FM4_CRG_TypeDef;



 
 
typedef struct
{
  volatile uint32_t WDG_LDR;
  volatile uint32_t WDG_VLR;
  union {
    volatile  uint8_t WDG_CTL;
    stc_hwwdt_wdg_ctl_field_t WDG_CTL_f;
  };
        uint8_t RESERVED0[3];
  volatile  uint8_t WDG_ICL;
        uint8_t RESERVED1[3];
  union {
    volatile  uint8_t WDG_RIS;
    stc_hwwdt_wdg_ris_field_t WDG_RIS_f;
  };
        uint8_t RESERVED2[3055];
  volatile uint32_t WDG_LCK;
}FM4_HWWDT_TypeDef;



 
 
typedef struct
{
  volatile uint32_t WDOGLOAD;
  volatile uint32_t WDOGVALUE;
  union {
    volatile  uint8_t                 WDOGCONTROL;
    stc_swwdt_wdogcontrol_field_t WDOGCONTROL_f;
  };
        uint8_t RESERVED0[3];
  volatile uint32_t WDOGINTCLR;
  union {
    volatile  uint8_t             WDOGRIS;
    stc_swwdt_wdogris_field_t WDOGRIS_f;
  };
        uint8_t RESERVED1[7];
  union {
    volatile  uint8_t              WDOGSPMC;
    stc_swwdt_wdogspmc_field_t WDOGSPMC_f;
  };
        uint8_t RESERVED2[3047];
  volatile uint32_t WDOGLOCK;
}FM4_SWWDT_TypeDef;



 
 
typedef struct
{
  volatile uint32_t TIMERXLOAD;
  volatile uint32_t TIMERXVALUE;
  union {
    volatile uint32_t                  TIMERXCONTROL;
    stc_dtim_timerXcontrol_field_t TIMERXCONTROL_f;
  };
  volatile uint32_t TIMERXINTCLR;
  union {
    volatile uint32_t              TIMERXRIS;
    stc_dtim_timerXris_field_t TIMERXRIS_f;
  };
  union {
    volatile uint32_t              TIMERXMIS;
    stc_dtim_timerXmis_field_t TIMERXMIS_f;
  };
  volatile uint32_t TIMERXBGLOAD;
        uint8_t RESERVED0[4];
}FM4_DTIM_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0[66];
  volatile uint16_t TCCP0;
        uint8_t RESERVED1[2];
  volatile uint16_t TCDT0;
  union {
    volatile uint16_t TCSA0;
    stc_mft_frt_tcsa0_field_t TCSA0_f;
  };
  union {
    volatile uint16_t TCSC0;
    stc_mft_frt_tcsc0_field_t TCSC0_f;
  };
        uint8_t RESERVED2[2];
  volatile uint16_t TCCP1;
        uint8_t RESERVED3[2];
  volatile uint16_t TCDT1;
  union {
    volatile uint16_t TCSA1;
    stc_mft_frt_tcsa1_field_t TCSA1_f;
  };
  union {
    volatile uint16_t TCSC1;
    stc_mft_frt_tcsc1_field_t TCSC1_f;
  };
        uint8_t RESERVED4[2];
  volatile uint16_t TCCP2;
        uint8_t RESERVED5[2];
  volatile uint16_t TCDT2;
  union {
    volatile uint16_t TCSA2;
    stc_mft_frt_tcsa2_field_t TCSA2_f;
  };
  union {
    volatile uint16_t TCSC2;
    stc_mft_frt_tcsc2_field_t TCSC2_f;
  };
  union {
    volatile uint32_t TCAL;
    stc_mft_frt_tcal_field_t TCAL_f;
  };
}FM4_MFT_FRT_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0[2];
  volatile uint16_t OCCP0;
        uint8_t RESERVED1[2];
  volatile uint16_t OCCP1;
        uint8_t RESERVED2[2];
  volatile uint16_t OCCP2;
        uint8_t RESERVED3[2];
  volatile uint16_t OCCP3;
        uint8_t RESERVED4[2];
  volatile uint16_t OCCP4;
        uint8_t RESERVED5[2];
  volatile uint16_t OCCP5;
  union {
    volatile  uint8_t OCSA10;
    stc_mft_ocu_ocsa10_field_t OCSA10_f;
  };
  union {
    volatile  uint8_t OCSB10;
    stc_mft_ocu_ocsb10_field_t OCSB10_f;
  };
  union {
    volatile  uint8_t OCSD10;
    stc_mft_ocu_ocsd10_field_t OCSD10_f;
  };
        uint8_t RESERVED6;
  union {
    volatile  uint8_t OCSA32;
    stc_mft_ocu_ocsa32_field_t OCSA32_f;
  };
  union {
    volatile  uint8_t OCSB32;
    stc_mft_ocu_ocsb32_field_t OCSB32_f;
  };
  union {
    volatile  uint8_t OCSD32;
    stc_mft_ocu_ocsd32_field_t OCSD32_f;
  };
        uint8_t RESERVED7;
  union {
    volatile  uint8_t OCSA54;
    stc_mft_ocu_ocsa54_field_t OCSA54_f;
  };
  union {
    volatile  uint8_t OCSB54;
    stc_mft_ocu_ocsb54_field_t OCSB54_f;
  };
  union {
    volatile  uint8_t OCSD54;
    stc_mft_ocu_ocsd54_field_t OCSD54_f;
  };
        uint8_t RESERVED8[2];
  union {
    volatile  uint8_t OCSC;
    stc_mft_ocu_ocsc_field_t OCSC_f;
  };
        uint8_t RESERVED9[2];
  union {
    volatile  uint16_t OCSE0;
    stc_mft_ocu_ocse0_field_t OCSE0_f;
  };
        uint8_t RESERVED10[2];
  union {
    volatile  uint32_t OCSE1;
    stc_mft_ocu_ocse1_field_t OCSE1_f;
  };
  union {
    volatile  uint16_t OCSE2;
    stc_mft_ocu_ocse2_field_t OCSE2_f;
  };
        uint8_t RESERVED11[2];
  union {
    volatile  uint32_t OCSE3;
    stc_mft_ocu_ocse3_field_t OCSE3_f;
  };
  union {
    volatile  uint16_t OCSE4;
    stc_mft_ocu_ocse4_field_t OCSE4_f;
  };
        uint8_t RESERVED12[2];
  union {
    volatile  uint32_t OCSE5;
    stc_mft_ocu_ocse5_field_t OCSE5_f;
  };
        uint8_t RESERVED13[40];
  union {
    volatile  uint8_t OCFS10;
    stc_mft_ocu_ocfs10_field_t OCFS10_f;
  };
  union {
    volatile  uint8_t OCFS32;
    stc_mft_ocu_ocfs32_field_t OCFS32_f;
  };
  union {
    volatile  uint8_t OCFS54;
    stc_mft_ocu_ocfs54_field_t OCFS54_f;
  };
}FM4_MFT_OCU_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0[142];
  volatile uint16_t WFTF10;
  volatile uint16_t WFTA10;
  volatile uint16_t WFTB10;
        uint8_t RESERVED1[2];
  volatile uint16_t WFTF32;
  volatile uint16_t WFTA32;
  volatile uint16_t WFTB32;
        uint8_t RESERVED2[2];
  volatile uint16_t WFTF54;
  volatile uint16_t WFTA54;
  volatile uint16_t WFTB54;
  union {
    volatile uint16_t WFSA10;
    stc_mft_wfg_wfsa10_field_t WFSA10_f;
  };
        uint8_t RESERVED3[2];
  union {
    volatile uint16_t WFSA32;
    stc_mft_wfg_wfsa32_field_t WFSA32_f;
  };
        uint8_t RESERVED4[2];
  union {
    volatile uint16_t WFSA54;
    stc_mft_wfg_wfsa54_field_t WFSA54_f;
  };
        uint8_t RESERVED5[2];
  union {
    volatile uint16_t WFIR;
    stc_mft_wfg_wfir_field_t WFIR_f;
  };
        uint8_t RESERVED6[2];
  union {
    volatile uint16_t NZCL;
    stc_mft_wfg_nzcl_field_t NZCL_f;
  };
}FM4_MFT_WFG_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0[108];
  union {
    volatile  uint8_t ICFS10;
    stc_mft_icu_icfs10_field_t ICFS10_f;
  };
  union {
    volatile  uint8_t ICFS32;
    stc_mft_icu_icfs32_field_t ICFS32_f;
  };
        uint8_t RESERVED1[8];
  volatile uint16_t ICCP0;
        uint8_t RESERVED2[2];
  volatile uint16_t ICCP1;
        uint8_t RESERVED3[2];
  volatile uint16_t ICCP2;
        uint8_t RESERVED4[2];
  volatile uint16_t ICCP3;
  union {
    volatile  uint8_t ICSA10;
    stc_mft_icu_icsa10_field_t ICSA10_f;
  };
  union {
    volatile  uint8_t ICSB10;
    stc_mft_icu_icsb10_field_t ICSB10_f;
  };
        uint8_t RESERVED6[2];
  union {
    volatile  uint8_t ICSA32;
    stc_mft_icu_icsa32_field_t ICSA32_f;
  };
  union {
    volatile  uint8_t ICSB32;
    stc_mft_icu_icsb32_field_t ICSB32_f;
  };
}FM4_MFT_ICU_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0[112];
  union {
    volatile  uint8_t ACFS10;
    stc_mft_adcmp_acfs10_field_t ACFS10_f;
  };
  union {
    volatile  uint8_t ACFS32;
    stc_mft_adcmp_acfs32_field_t ACFS32_f;
  };
  union {
    volatile  uint8_t ACFS54;
    stc_mft_adcmp_acfs54_field_t ACFS54_f;
  };
        uint8_t RESERVED1[71];
  volatile uint16_t ACMP0;
        uint8_t RESERVED2[2];
  volatile uint16_t ACMP1;
        uint8_t RESERVED3[2];
  volatile uint16_t ACMP2;
        uint8_t RESERVED4[2];
  volatile uint16_t ACMP3;
        uint8_t RESERVED5[2];
  volatile uint16_t ACMP4;
        uint8_t RESERVED6[2];
  volatile uint16_t ACMP5;
  union {
    volatile  uint16_t ACSA;
    stc_mft_adcmp_acsa_field_t ACSA_f;
  };
        uint8_t RESERVED7[2];
  union {
    volatile  uint8_t ACSC0;
    stc_mft_adcmp_acsc_field_t ACSC0_f;
  };
  union {
    volatile  uint8_t ACSD0;
    stc_mft_adcmp_acsd_field_t ACSD0_f;
  };
        uint8_t RESERVED8[2];
  union {
    volatile  uint8_t ACSC1;
    stc_mft_adcmp_acsc_field_t ACSC1_f;
  };
  union {
    volatile  uint8_t ACSD1;
    stc_mft_adcmp_acsd_field_t ACSD1_f;
  };
        uint8_t RESERVED9[2];
  union {
    volatile  uint8_t ACSC2;
    stc_mft_adcmp_acsc_field_t ACSC2_f;
  };
  union {
    volatile  uint8_t ACSD2;
    stc_mft_adcmp_acsd_field_t ACSD2_f;
  };
        uint8_t RESERVED10[2];
  union {
    volatile  uint8_t ACSC3;
    stc_mft_adcmp_acsc_field_t ACSC3_f;
  };
  union {
    volatile  uint8_t ACSD3;
    stc_mft_adcmp_acsd_field_t ACSD3_f;
  };
        uint8_t RESERVED11[2];
  union {
    volatile  uint8_t ACSC4;
    stc_mft_adcmp_acsc_field_t ACSC4_f;
  };
  union {
    volatile  uint8_t ACSD4;
    stc_mft_adcmp_acsd_field_t ACSD4_f;
  };
        uint8_t RESERVED12[2];
  union {
    volatile  uint8_t ACSC5;
    stc_mft_adcmp_acsc_field_t ACSC5_f;
  };
  union {
    volatile  uint8_t ACSD5;
    stc_mft_adcmp_acsd_field_t ACSD5_f;
  };
        uint8_t RESERVED13[2];
}FM4_MFT_ADCMP_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0;
  union {
    volatile  uint8_t TTCR0;
    stc_mft_ppg_ttcr0_field_t TTCR0_f;
  };
        uint8_t RESERVED1[2];
  volatile  uint8_t TSTPR0;
        uint8_t RESERVED3[4];
  volatile  uint8_t COMP0;
        uint8_t RESERVED4[2];
  volatile  uint8_t COMP2;
        uint8_t RESERVED5[4];
  volatile  uint8_t COMP4;
        uint8_t RESERVED6[2];
  volatile  uint8_t COMP6;
        uint8_t RESERVED7[12];
  union {
    volatile  uint8_t TTCR1;
    stc_mft_ppg_ttcr1_field_t TTCR1_f;
  };
        uint8_t RESERVED8[2];
  volatile  uint8_t TSTPR1;
        uint8_t RESERVED9[4];
  volatile  uint8_t COMP1;
        uint8_t RESERVED10[2];
  volatile  uint8_t COMP3;
        uint8_t RESERVED11[4];
  volatile  uint8_t COMP5;
        uint8_t RESERVED12[2];
  volatile  uint8_t COMP7;
        uint8_t RESERVED13[12];
  union {
    volatile  uint8_t TTCR2;
    stc_mft_ppg_ttcr2_field_t TTCR2_f;
  };
        uint8_t RESERVED14[2];
  volatile  uint8_t TSTPR2;
        uint8_t RESERVED15[4];
  volatile  uint8_t COMP8;
        uint8_t RESERVED16[2];
  volatile  uint8_t COMP10;
        uint8_t RESERVED17[4];
  volatile  uint8_t COMP12;
        uint8_t RESERVED18[2];
  volatile  uint8_t COMP14;
        uint8_t RESERVED19[171];
  union {
    volatile uint16_t TRG0;
    stc_mft_ppg_trg0_field_t TRG0_f;
  };
        uint8_t RESERVED20[2];
  union {
    volatile uint16_t REVC0;
    stc_mft_ppg_revc0_field_t REVC0_f;
  };
        uint8_t RESERVED21[58];
  union {
    volatile uint16_t TRG1;
    stc_mft_ppg_trg1_field_t TRG1_f;
  };
        uint8_t RESERVED22[2];
  union {
    volatile uint16_t REVC1;
    stc_mft_ppg_revc1_field_t REVC1_f;
  };
        uint8_t RESERVED23[186];
  union {
    volatile  uint8_t PPGC1;
    stc_mft_ppg_ppgc1_field_t PPGC1_f;
  };
  union {
    volatile  uint8_t PPGC0;
    stc_mft_ppg_ppgc0_field_t PPGC0_f;
  };
        uint8_t RESERVED24[2];
  union {
    volatile  uint8_t PPGC3;
    stc_mft_ppg_ppgc3_field_t PPGC3_f;
  };
  union {
    volatile  uint8_t PPGC2;
    stc_mft_ppg_ppgc2_field_t PPGC2_f;
  };
        uint8_t RESERVED25[2];
  union {
    volatile uint16_t PRL0;
    struct {
      volatile  uint8_t PRLL0;
      volatile  uint8_t PRLH0;
    };
  };
        uint8_t RESERVED26[2];
  union {
    volatile uint16_t PRL1;
    struct {
      volatile  uint8_t PRLL1;
      volatile  uint8_t PRLH1;
    };
  };
        uint8_t RESERVED27[2];
  union {
    volatile uint16_t PRL2;
    struct {
      volatile  uint8_t PRLL2;
      volatile  uint8_t PRLH2;
    };
  };
        uint8_t RESERVED28[2];
  union {
    volatile uint16_t PRL3;
    struct {
      volatile  uint8_t PRLL3;
      volatile  uint8_t PRLH3;
    };
  };
        uint8_t RESERVED29[2];
  union {
    volatile  uint8_t GATEC0;
    stc_mft_ppg_gatec0_field_t GATEC0_f;
  };
        uint8_t RESERVED30[39];
  union {
    volatile  uint8_t PPGC5;
    stc_mft_ppg_ppgc5_field_t PPGC5_f;
  };
  union {
    volatile  uint8_t PPGC4;
    stc_mft_ppg_ppgc4_field_t PPGC4_f;
  };
        uint8_t RESERVED31[2];
  union {
    volatile  uint8_t PPGC7;
    stc_mft_ppg_ppgc7_field_t PPGC7_f;
  };
  union {
    volatile  uint8_t PPGC6;
    stc_mft_ppg_ppgc6_field_t PPGC6_f;
  };
        uint8_t RESERVED32[2];
  union {
    volatile uint16_t PRL4;
    struct {
      volatile  uint8_t PRLL4;
      volatile  uint8_t PRLH4;
    };
  };
        uint8_t RESERVED33[2];
  union {
    volatile uint16_t PRL5;
    struct {
      volatile  uint8_t PRLL5;
      volatile  uint8_t PRLH5;
    };
  };
        uint8_t RESERVED34[2];
  union {
    volatile uint16_t PRL6;
    struct {
      volatile  uint8_t PRLL6;
      volatile  uint8_t PRLH6;
    };
  };
        uint8_t RESERVED35[2];
  union {
    volatile uint16_t PRL7;
    struct {
      volatile  uint8_t PRLL7;
      volatile  uint8_t PRLH7;
    };
  };
        uint8_t RESERVED36[2];
  union {
    volatile  uint8_t GATEC4;
    stc_mft_ppg_gatec4_field_t GATEC4_f;
  };
        uint8_t RESERVED37[39];
  union {
    volatile  uint8_t PPGC9;
    stc_mft_ppg_ppgc9_field_t PPGC9_f;
  };
  union {
    volatile  uint8_t PPGC8;
    stc_mft_ppg_ppgc8_field_t PPGC8_f;
  };
        uint8_t RESERVED38[2];
  union {
    volatile  uint8_t PPGC11;
    stc_mft_ppg_ppgc11_field_t PPGC11_f;
  };
  union {
    volatile  uint8_t PPGC10;
    stc_mft_ppg_ppgc10_field_t PPGC10_f;
  };
        uint8_t RESERVED39[2];
  union {
    volatile uint16_t PRL8;
    struct {
      volatile  uint8_t PRLL8;
      volatile  uint8_t PRLH8;
    };
  };
        uint8_t RESERVED40[2];
  union {
    volatile uint16_t PRL9;
    struct {
      volatile  uint8_t PRLL9;
      volatile  uint8_t PRLH9;
    };
  };
        uint8_t RESERVED41[2];
  union {
    volatile uint16_t PRL10;
    struct {
      volatile  uint8_t PRLL10;
      volatile  uint8_t PRLH10;
    };
  };
        uint8_t RESERVED42[2];
  union {
    volatile uint16_t PRL11;
    struct {
      volatile  uint8_t PRLL11;
      volatile  uint8_t PRLH11;
    };
  };
        uint8_t RESERVED43[2];
  union {
    volatile  uint8_t GATEC8;
    stc_mft_ppg_gatec8_field_t GATEC8_f;
  };
        uint8_t RESERVED44[39];
  union {
    volatile  uint8_t PPGC13;
    stc_mft_ppg_ppgc13_field_t PPGC13_f;
  };
  union {
    volatile  uint8_t PPGC12;
    stc_mft_ppg_ppgc12_field_t PPGC12_f;
  };
        uint8_t RESERVED45[2];
  union {
    volatile  uint8_t PPGC15;
    stc_mft_ppg_ppgc15_field_t PPGC15_f;
  };
  union {
    volatile  uint8_t PPGC14;
    stc_mft_ppg_ppgc14_field_t PPGC14_f;
  };
        uint8_t RESERVED46[2];
  union {
    volatile uint16_t PRL12;
    struct {
      volatile  uint8_t PRLL12;
      volatile  uint8_t PRLH12;
    };
  };
        uint8_t RESERVED47[2];
  union {
    volatile uint16_t PRL13;
    struct {
      volatile  uint8_t PRLL13;
      volatile  uint8_t PRLH13;
    };
  };
        uint8_t RESERVED48[2];
  union {
    volatile uint16_t PRL14;
    struct {
      volatile  uint8_t PRLL14;
      volatile  uint8_t PRLH14;
    };
  };
        uint8_t RESERVED49[2];
  union {
    volatile uint16_t PRL15;
    struct {
      volatile  uint8_t PRLL15;
      volatile  uint8_t PRLH15;
    };
  };
        uint8_t RESERVED50[2];
  union {
    volatile  uint8_t GATEC12;
    stc_mft_ppg_gatec12_field_t GATEC12_f;
  };
        uint8_t RESERVED51[39];  
  union {
    volatile  uint8_t PPGC17;
    stc_mft_ppg_ppgc17_field_t PPGC17_f;
  };
  union {
    volatile  uint8_t PPGC16;
    stc_mft_ppg_ppgc16_field_t PPGC16_f;
  };
        uint8_t RESERVED52[2];
  union {
    volatile  uint8_t PPGC19;
    stc_mft_ppg_ppgc19_field_t PPGC19_f;
  };
  union {
    volatile  uint8_t PPGC18;
    stc_mft_ppg_ppgc18_field_t PPGC18_f;
  };
        uint8_t RESERVED53[2];
  union {
    volatile uint16_t PRL16;
    struct {
      volatile  uint8_t PRLL16;
      volatile  uint8_t PRLH16;
    };
  };
        uint8_t RESERVED54[2];
  union {
    volatile uint16_t PRL17;
    struct {
      volatile  uint8_t PRLL17;
      volatile  uint8_t PRLH17;
    };
  };
        uint8_t RESERVED55[2];
  union {
    volatile uint16_t PRL18;
    struct {
      volatile  uint8_t PRLL18;
      volatile  uint8_t PRLH18;
    };
  };
        uint8_t RESERVED56[2];
  union {
    volatile uint16_t PRL19;
    struct {
      volatile  uint8_t PRLL19;
      volatile  uint8_t PRLH19;
    };
  };
        uint8_t RESERVED57[2];
  union {
    volatile  uint8_t GATEC16;
    stc_mft_ppg_gatec16_field_t GATEC16_f;
  };
        uint8_t RESERVED58[39];
  union {
    volatile  uint8_t PPGC21;
    stc_mft_ppg_ppgc21_field_t PPGC21_f;
  };
  union {
    volatile  uint8_t PPGC20;
    stc_mft_ppg_ppgc20_field_t PPGC20_f;
  };
        uint8_t RESERVED59[2];
  union {
    volatile  uint8_t PPGC23;
    stc_mft_ppg_ppgc23_field_t PPGC23_f;
  };
  union {
    volatile  uint8_t PPGC22;
    stc_mft_ppg_ppgc22_field_t PPGC22_f;
  };
        uint8_t RESERVED60[2];
  union {
    volatile uint16_t PRL20;
    struct {
      volatile  uint8_t PRLL20;
      volatile  uint8_t PRLH20;
    };
  };
        uint8_t RESERVED61[2];
  union {
    volatile uint16_t PRL21;
    struct {
      volatile  uint8_t PRLL21;
      volatile  uint8_t PRLH21;
    };
  };
        uint8_t RESERVED62[2];
  union {
    volatile uint16_t PRL22;
    struct {
      volatile  uint8_t PRLL22;
      volatile  uint8_t PRLH22;
    };
  };
        uint8_t RESERVED63[2];
  union {
    volatile uint16_t PRL23;
    struct {
      volatile  uint8_t PRLL23;
      volatile  uint8_t PRLH23;
    };
  };
        uint8_t RESERVED64[2];
  union {
    volatile  uint8_t GATEC20;
    stc_mft_ppg_gatec20_field_t GATEC20_f;
  };
        uint8_t RESERVED65[39];
  volatile  uint8_t IGBTC;
        uint8_t RESERVED66[39];
}FM4_MFT_PPG_TypeDef;



 
 
typedef struct
{
  volatile uint16_t PRLL;
        uint8_t RESERVED0[2];
  volatile uint16_t PRLH;
        uint8_t RESERVED1[2];
  volatile uint16_t TMR;
        uint8_t RESERVED2[2];
  union {
    volatile uint16_t TMCR;
    stc_bt_ppg_tmcr_field_t TMCR_f;
  };
        uint8_t RESERVED3[2];
  union {
    volatile  uint8_t STC;
    stc_bt_ppg_stc_field_t STC_f;
  };
  union {
    volatile  uint8_t TMCR2;
    stc_bt_ppg_tmcr2_field_t TMCR2_f;
  };
}FM4_BT_PPG_TypeDef;



 
 
typedef struct
{
  volatile uint16_t PCSR;
        uint8_t RESERVED0[2];
  volatile uint16_t PDUT;
        uint8_t RESERVED1[2];
  volatile uint16_t TMR;
        uint8_t RESERVED2[2];
  union {
    volatile uint16_t TMCR;
    stc_bt_pwm_tmcr_field_t TMCR_f;
  };
        uint8_t RESERVED3[2];
  union {
    volatile  uint8_t STC;
    stc_bt_pwm_stc_field_t STC_f;
  };
  union {
    volatile  uint8_t TMCR2;
    stc_bt_pwm_tmcr2_field_t TMCR2_f;
  };
}FM4_BT_PWM_TypeDef;



 
 
typedef struct
{
  volatile uint16_t PCSR;
        uint8_t RESERVED0[6];
  volatile uint16_t TMR;
        uint8_t RESERVED1[2];
  union {
    volatile uint16_t TMCR;
    stc_bt_rt_tmcr_field_t TMCR_f;
  };
        uint8_t RESERVED2[2];
  union {
    volatile  uint8_t STC;
    stc_bt_rt_stc_field_t STC_f;
  };
  union {
    volatile  uint8_t TMCR2;
    stc_bt_rt_tmcr2_field_t TMCR2_f;
  };
}FM4_BT_RT_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0[4];
  volatile uint16_t DTBF;
        uint8_t RESERVED1[6];
  union {
    volatile uint16_t TMCR;
    stc_bt_pwc_tmcr_field_t TMCR_f;
  };
        uint8_t RESERVED2[2];
  union {
    volatile  uint8_t STC;
    stc_bt_pwc_stc_field_t STC_f;
  };
  union {
    volatile  uint8_t TMCR2;
    stc_bt_pwc_tmcr2_field_t TMCR2_f;
  };
}FM4_BT_PWC_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0;
  union {
    volatile  uint8_t BTSEL0123;
    stc_btiosel03_btsel0123_field_t BTSEL0123_f;
  };
}FM4_BTIOSEL03_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0;
  union {
    volatile  uint8_t BTSEL4567;
    stc_btiosel47_btsel4567_field_t BTSEL4567_f;
  };
}FM4_BTIOSEL47_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0;
  union {
    volatile  uint8_t BTSEL89AB;
    stc_btiosel8b_btsel89ab_field_t BTSEL89AB_f;
  };
}FM4_BTIOSEL8B_TypeDef;



 
 
typedef struct
{
        uint8_t RESERVED0;
  union {
    volatile  uint8_t BTSELCDEF;
    stc_btioselcf_btselcdef_field_t BTSELCDEF_f;
  };
}FM4_BTIOSELCF_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint16_t BTSSSR;
    stc_sbssr_btsssr_field_t BTSSSR_f;
  };
}FM4_SBSSR_TypeDef;



 
 
typedef struct
{
  volatile uint16_t QPCR;
        uint8_t RESERVED0[2];
  volatile uint16_t QRCR;
        uint8_t RESERVED1[2];
  volatile uint16_t QPCCR;
        uint8_t RESERVED2[2];
  volatile uint16_t QPRCR;
        uint8_t RESERVED3[2];
  volatile uint16_t QMPR;
        uint8_t RESERVED4[2];
  union {
    union {
      volatile uint16_t QICR;
      stc_qprc_qicr_field_t QICR_f;
    };
    struct {
      union {
        volatile  uint8_t QICRL;
        stc_qprc_qicrl_field_t QICRL_f;
      };
      union {
        volatile  uint8_t QICRH;
        stc_qprc_qicrh_field_t QICRH_f;
      };
    };
  };
        uint8_t RESERVED5[2];
  union {
    union {
      volatile uint16_t QCR;
      stc_qprc_qcr_field_t QCR_f;
    };
    struct {
      union {
        volatile  uint8_t QCRL;
        stc_qprc_qcrl_field_t QCRL_f;
      };
      union {
        volatile  uint8_t QCRH;
        stc_qprc_qcrh_field_t QCRH_f;
      };
    };
  };
        uint8_t RESERVED6[2];
  union {
    volatile uint16_t QECR;
    stc_qprc_qecr_field_t QECR_f;
  };
}FM4_QPRC_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t NFCTLA;
    stc_qprc_nf_nfctla_field_t NFCTLA_f;
  };
        uint8_t RESERVED0[3];
  union {
    volatile  uint8_t NFCTLB;
    stc_qprc_nf_nfctlb_field_t NFCTLB_f;
  };
        uint8_t RESERVED1[3];
  union {
    volatile  uint8_t NFRCTLZ;
    stc_qprc_nf_nfrctlz_field_t NFRCTLZ_f;
  };
        uint8_t RESERVED2[7];
}FM4_QPRC_NF_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t ADSR;
    stc_adc_adsr_field_t ADSR_f;
  };
  union {
    volatile  uint8_t ADCR;
    stc_adc_adcr_field_t ADCR_f;
  };
        uint8_t RESERVED0[6];
  union {
    volatile  uint8_t SFNS;
    stc_adc_sfns_field_t SFNS_f;
  };
  union {
    volatile  uint8_t SCCR;
    stc_adc_sccr_field_t SCCR_f;
  };
        uint8_t RESERVED1[2];
  union {
    union {
      volatile uint32_t SCFD;
      stc_adc_scfd_field_t SCFD_f;
    };
    struct {
      union {
        volatile uint16_t SCFDL;
        stc_adc_scfdl_field_t SCFDL_f;
      };
      union {
        volatile uint16_t SCFDH;
        stc_adc_scfdh_field_t SCFDH_f;
      };
    };
  };
  union {
    union {
      volatile uint16_t SCIS23;
      stc_adc_scis23_field_t SCIS23_f;
    };
    struct {
      union {
        volatile  uint8_t SCIS2;
        stc_adc_scis2_field_t SCIS2_f;
      };
      union {
        volatile  uint8_t SCIS3;
        stc_adc_scis3_field_t SCIS3_f;
      };
    };
  };
        uint8_t RESERVED2[2];
  union {
    union {
      volatile uint16_t SCIS01;
      stc_adc_scis01_field_t SCIS01_f;
    };
    struct {
      union {
        volatile  uint8_t SCIS0;
        stc_adc_scis0_field_t SCIS0_f;
      };
      union {
        volatile  uint8_t SCIS1;
        stc_adc_scis1_field_t SCIS1_f;
      };
    };
  };
        uint8_t RESERVED3[2];
  union {
    volatile  uint8_t PFNS;
    stc_adc_pfns_field_t PFNS_f;
  };
  union {
    volatile  uint8_t PCCR;
    stc_adc_pccr_field_t PCCR_f;
  };
        uint8_t RESERVED4[2];
  union {
    union {
      volatile uint32_t PCFD;
      stc_adc_pcfd_field_t PCFD_f;
    };
    struct {
      union {
        volatile uint16_t PCFDL;
        stc_adc_pcfdl_field_t PCFDL_f;
      };
      union {
        volatile uint16_t PCFDH;
        stc_adc_pcfdh_field_t PCFDH_f;
      };
    };
  };
  union {
    volatile  uint8_t PCIS;
    stc_adc_pcis_field_t PCIS_f;
  };
        uint8_t RESERVED5[3];
  union {
    volatile  uint8_t CMPCR;
    stc_adc_cmpcr_field_t CMPCR_f;
  };
        uint8_t RESERVED6;
  union {
    volatile uint16_t CMPD;
    stc_adc_cmpd_field_t CMPD_f;
  };
  union {
    union {
      volatile uint16_t ADSS23;
      stc_adc_adss23_field_t ADSS23_f;
    };
    struct {
      union {
        volatile  uint8_t ADSS2;
        stc_adc_adss2_field_t ADSS2_f;
      };
      union {
        volatile  uint8_t ADSS3;
        stc_adc_adss3_field_t ADSS3_f;
      };
    };
  };
        uint8_t RESERVED7[2];
  union {
    union {
      volatile uint16_t ADSS01;
      stc_adc_adss01_field_t ADSS01_f;
    };
    struct {
      union {
        volatile  uint8_t ADSS0;
        stc_adc_adss0_field_t ADSS0_f;
      };
      union {
        volatile  uint8_t ADSS1;
        stc_adc_adss1_field_t ADSS1_f;
      };
    };
  };
        uint8_t RESERVED8[2];
  union {
    union {
      volatile uint16_t ADST01;
      stc_adc_adst01_field_t ADST01_f;
    };
    struct {
      union {
        volatile  uint8_t ADST1;
        stc_adc_adst1_field_t ADST1_f;
      };
      union {
        volatile  uint8_t ADST0;
        stc_adc_adst0_field_t ADST0_f;
      };
    };
  };
        uint8_t RESERVED9[2];
  union {
    volatile  uint8_t ADCT;
    stc_adc_adct_field_t ADCT_f;
  };
        uint8_t RESERVED10[3];
  union {
    volatile  uint8_t PRTSL;
    stc_adc_prtsl_field_t PRTSL_f;
  };
  union {
    volatile  uint8_t SCTSL;
    stc_adc_sctsl_field_t SCTSL_f;
  };
        uint8_t RESERVED11[2];
  union {
    volatile  uint16_t ADCEN;
    stc_adc_adcen_field_t ADCEN_f;
  };
        uint8_t  RESERVED12[2];
        uint32_t OFFESET;
  union {
    volatile uint8_t WCMRCOT;
	stc_adc_wcmrcot_field_t WCMRCOT_f;
  };
        uint8_t  RESERVED13[3];
  union {
    volatile uint8_t WCMRCIF;
	stc_adc_wcmrcif_field_t WCMRCIF_f;
  };
        uint8_t  RESERVED14[3];
  union {
    volatile uint8_t WCMPCR;
	stc_adc_wcmpcr_field_t WCMPCR_f;
  };
  union {
    volatile uint8_t WCMPSR;
	stc_adc_wcmpsr_field_t WCMPSR_f;
  };
        uint8_t  RESERVED15[2];
  union {
    volatile uint16_t WCMPDL;
	stc_adc_wcmpdl_field_t WCMPDL_f;
  };
  union {
    volatile uint16_t WCMPDH;
	stc_adc_wcmpdh_field_t WCMPDH_f;
  };
}FM4_ADC_TypeDef;



 

typedef struct
{
  union {
    volatile uint8_t      DACR0;
    stc_dacr_field_t  DACR0_f;
  };
  uint8_t             RESERVED0[3];
  union {
    volatile uint16_t     DADR0;
    stc_dadr_field_t  DADR0_f;
  };
  uint8_t             RESERVED1[2];
  union {
    volatile uint8_t      DACR1;
    stc_dacr_field_t  DACR1_f;
  };
  uint8_t             RESERVED3[3];
  union {
    volatile uint16_t     DADR1;
    stc_dadr_field_t  DADR1_f;
  };

}FM4_DAC_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t MCR_PSR;
    stc_crtrim_mcr_psr_field_t MCR_PSR_f;
  };
        uint8_t RESERVED0[3];
  union {
    volatile uint16_t MCR_FTRM;
    stc_crtrim_mcr_ftrm_field_t MCR_FTRM_f;
  };
       uint8_t RESERVED1[2];
  union {
    volatile  uint8_t MCR_TTRM;
    stc_crtrim_mcr_ttrm_field_t MCR_TTRM_f;
  };
       uint8_t RESERVED2[3];
  union {
    volatile uint32_t MCR_RLR;
    stc_crtrim_mcr_rlr_field_t MCR_RLR_f;
  };
}FM4_CRTRIM_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t ENIR;
    stc_exti_enir_field_t ENIR_f;
  };
  union {
    volatile uint32_t EIRR;
    stc_exti_eirr_field_t EIRR_f;
  };
  union {
    volatile uint32_t EICL;
    stc_exti_eicl_field_t EICL_f;
  };
  union {
    volatile uint32_t ELVR;
    stc_exti_elvr_field_t ELVR_f;
  };
  union {
    volatile uint32_t ELVR1;
    stc_exti_elvr1_field_t ELVR1_f;
  };
  union {
    volatile  uint8_t NMIRR;
    stc_exti_nmirr_field_t NMIRR_f;
  };
       uint8_t RESERVED5[3];
  union {
    volatile  uint8_t NMICL;
    stc_exti_nmicl_field_t NMICL_f;
  };
}FM4_EXTI_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t DRQSEL;
    stc_intreq_drqsel_field_t DRQSEL_f;
  };
       uint8_t RESERVED0[12];
  union {
    volatile  uint8_t ODDPKS;
    stc_intreq_oddpks_field_t ODDPKS_f;
  };
       uint8_t RESERVED1[255];
  union {
    volatile uint32_t IRQ003SEL;
    stc_intreq_irq003sel_field_t IRQ003SEL_f;
  };
  union {
    volatile uint32_t IRQ004SEL;
    stc_intreq_irq004sel_field_t IRQ004SEL_f;
  };
  union {
    volatile uint32_t IRQ005SEL;
    stc_intreq_irq005sel_field_t IRQ005SEL_f;
  };
  union {
    volatile uint32_t IRQ006SEL;
    stc_intreq_irq006sel_field_t IRQ006SEL_f;
  };
  union {
    volatile uint32_t IRQ007SEL;
    stc_intreq_irq007sel_field_t IRQ007SEL_f;
  };
  union {
    volatile uint32_t IRQ008SEL;
    stc_intreq_irq008sel_field_t IRQ008SEL_f;
  };
  union {
    volatile uint32_t IRQ009SEL;
    stc_intreq_irq009sel_field_t IRQ009SEL_f;
  };
  union {
    volatile uint32_t IRQ010SEL;
    stc_intreq_irq010sel_field_t IRQ010SEL_f;
  };
       uint8_t RESERVED9[208];
  union {
    volatile uint32_t EXC02MON;
    stc_intreq_exc02mon_field_t EXC02MON_f;
  };
  union {
    volatile uint32_t IRQ000MON;
    stc_intreq_irq000mon_field_t IRQ000MON_f;
  };
  union {
    volatile uint32_t IRQ001MON;
    stc_intreq_irq001mon_field_t IRQ001MON_f;
  };
  union {
    volatile uint32_t IRQ002MON;
    stc_intreq_irq002mon_field_t IRQ002MON_f;
  };
  union {
    volatile uint32_t IRQ003MON;
    stc_intreq_irq003mon_field_t IRQ003MON_f;
  };
  union {
    volatile uint32_t IRQ004MON;
    stc_intreq_irq004mon_field_t IRQ004MON_f;
  };
  union {
    volatile uint32_t IRQ005MON;
    stc_intreq_irq005mon_field_t IRQ005MON_f;
  };
  union {
    volatile uint32_t IRQ006MON;
    stc_intreq_irq006mon_field_t IRQ006MON_f;
  };
  union {
    volatile uint32_t IRQ007MON;
    stc_intreq_irq007mon_field_t IRQ007MON_f;
  };
  union {
    volatile uint32_t IRQ008MON;
    stc_intreq_irq008mon_field_t IRQ008MON_f;
  };
  union {
    volatile uint32_t IRQ009MON;
    stc_intreq_irq009mon_field_t IRQ009MON_f;
  };
  union {
    volatile uint32_t IRQ010MON;
    stc_intreq_irq010mon_field_t IRQ010MON_f;
  };
  union {
    volatile uint32_t IRQ011MON;
    stc_intreq_irq011mon_field_t IRQ011MON_f;
  };
  union {
    volatile uint32_t IRQ012MON;
    stc_intreq_irq012mon_field_t IRQ012MON_f;
  };
  union {
    volatile uint32_t IRQ013MON;
    stc_intreq_irq013mon_field_t IRQ013MON_f;
  };
  union {
    volatile uint32_t IRQ014MON;
    stc_intreq_irq014mon_field_t IRQ014MON_f;
  };
  union {
    volatile uint32_t IRQ015MON;
    stc_intreq_irq015mon_field_t IRQ015MON_f;
  };
  union {
    volatile uint32_t IRQ016MON;
    stc_intreq_irq016mon_field_t IRQ016MON_f;
  };
  union {
    volatile uint32_t IRQ017MON;
    stc_intreq_irq017mon_field_t IRQ017MON_f;
  };
  union {
    volatile uint32_t IRQ018MON;
    stc_intreq_irq018mon_field_t IRQ018MON_f;
  };
  union {
    volatile uint32_t IRQ019MON;
    stc_intreq_irq019mon_field_t IRQ019MON_f;
  };
  union {
    volatile uint32_t IRQ020MON;
    stc_intreq_irq020mon_field_t IRQ020MON_f;
  };
  union {
    volatile uint32_t IRQ021MON;
    stc_intreq_irq021mon_field_t IRQ021MON_f;
  };
  union {
    volatile uint32_t IRQ022MON;
    stc_intreq_irq022mon_field_t IRQ022MON_f;
  };
  union {
    volatile uint32_t IRQ023MON;
    stc_intreq_irq023mon_field_t IRQ023MON_f;
  };
  union {
    volatile uint32_t IRQ024MON;
    stc_intreq_irq024mon_field_t IRQ024MON_f;
  };
  union {
    volatile uint32_t IRQ025MON;
    stc_intreq_irq025mon_field_t IRQ025MON_f;
  };
  union {
    volatile uint32_t IRQ026MON;
    stc_intreq_irq026mon_field_t IRQ026MON_f;
  };
  union {
    volatile uint32_t IRQ027MON;
    stc_intreq_irq027mon_field_t IRQ027MON_f;
  };
  union {
    volatile uint32_t IRQ028MON;
    stc_intreq_irq028mon_field_t IRQ028MON_f;
  };
  union {
    volatile uint32_t IRQ029MON;
    stc_intreq_irq029mon_field_t IRQ029MON_f;
  };
  union {
    volatile uint32_t IRQ030MON;
    stc_intreq_irq030mon_field_t IRQ030MON_f;
  };
  union {
    volatile uint32_t IRQ031MON;
    stc_intreq_irq031mon_field_t IRQ031MON_f;
  };
  union {
    volatile uint32_t IRQ032MON;
    stc_intreq_irq032mon_field_t IRQ032MON_f;
  };
  union {
    volatile uint32_t IRQ033MON;
    stc_intreq_irq033mon_field_t IRQ033MON_f;
  };
  union {
    volatile uint32_t IRQ034MON;
    stc_intreq_irq034mon_field_t IRQ034MON_f;
  };
  union {
    volatile uint32_t IRQ035MON;
    stc_intreq_irq035mon_field_t IRQ035MON_f;
  };
  union {
    volatile uint32_t IRQ036MON;
    stc_intreq_irq036mon_field_t IRQ036MON_f;
  };
  union {
    volatile uint32_t IRQ037MON;
    stc_intreq_irq037mon_field_t IRQ037MON_f;
  };
  union {
    volatile uint32_t IRQ038MON;
    stc_intreq_irq038mon_field_t IRQ038MON_f;
  };
  union {
    volatile uint32_t IRQ039MON;
    stc_intreq_irq039mon_field_t IRQ039MON_f;
  };
  union {
    volatile uint32_t IRQ040MON;
    stc_intreq_irq040mon_field_t IRQ040MON_f;
  };
  union {
    volatile uint32_t IRQ041MON;
    stc_intreq_irq041mon_field_t IRQ041MON_f;
  };
  union {
    volatile uint32_t IRQ042MON;
    stc_intreq_irq042mon_field_t IRQ042MON_f;
  };
  union {
    volatile uint32_t IRQ043MON;
    stc_intreq_irq043mon_field_t IRQ043MON_f;
  };
  union {
    volatile uint32_t IRQ044MON;
    stc_intreq_irq044mon_field_t IRQ044MON_f;
  };
  union {
    volatile uint32_t IRQ045MON;
    stc_intreq_irq045mon_field_t IRQ045MON_f;
  };
  union {
    volatile uint32_t IRQ046MON;
    stc_intreq_irq046mon_field_t IRQ046MON_f;
  };
  union {
    volatile uint32_t IRQ047MON;
    stc_intreq_irq047mon_field_t IRQ047MON_f;
  };
  union {
    volatile uint32_t IRQ048MON;
    stc_intreq_irq048mon_field_t IRQ048MON_f;
  };
  union {
    volatile uint32_t IRQ049MON;
    stc_intreq_irq049mon_field_t IRQ049MON_f;
  };
  union {
    volatile uint32_t IRQ050MON;
    stc_intreq_irq050mon_field_t IRQ050MON_f;
  };
  union {
    volatile uint32_t IRQ051MON;
    stc_intreq_irq051mon_field_t IRQ051MON_f;
  };
  union {
    volatile uint32_t IRQ052MON;
    stc_intreq_irq052mon_field_t IRQ052MON_f;
  };
  union {
    volatile uint32_t IRQ053MON;
    stc_intreq_irq053mon_field_t IRQ053MON_f;
  };
  union {
    volatile uint32_t IRQ054MON;
    stc_intreq_irq054mon_field_t IRQ054MON_f;
  };
  union {
    volatile uint32_t IRQ055MON;
    stc_intreq_irq055mon_field_t IRQ055MON_f;
  };
  union {
    volatile uint32_t IRQ056MON;
    stc_intreq_irq056mon_field_t IRQ056MON_f;
  };
  union {
    volatile uint32_t IRQ057MON;
    stc_intreq_irq057mon_field_t IRQ057MON_f;
  };
  union {
    volatile uint32_t IRQ058MON;
    stc_intreq_irq058mon_field_t IRQ058MON_f;
  };
  union {
    volatile uint32_t IRQ059MON;
    stc_intreq_irq059mon_field_t IRQ059MON_f;
  };
  union {
    volatile uint32_t IRQ060MON;
    stc_intreq_irq060mon_field_t IRQ060MON_f;
  };
  union {
    volatile uint32_t IRQ061MON;
    stc_intreq_irq061mon_field_t IRQ061MON_f;
  };
  union {
    volatile uint32_t IRQ062MON;
    stc_intreq_irq062mon_field_t IRQ062MON_f;
  };
  union {
    volatile uint32_t IRQ063MON;
    stc_intreq_irq063mon_field_t IRQ063MON_f;
  };
  union {
    volatile uint32_t IRQ064MON;
    stc_intreq_irq064mon_field_t IRQ064MON_f;
  };
  union {
    volatile uint32_t IRQ065MON;
    stc_intreq_irq065mon_field_t IRQ065MON_f;
  };
  union {
    volatile uint32_t IRQ066MON;
    stc_intreq_irq066mon_field_t IRQ066MON_f;
  };
  union {
    volatile uint32_t IRQ067MON;
    stc_intreq_irq067mon_field_t IRQ067MON_f;
  };
  union {
    volatile uint32_t IRQ068MON;
    stc_intreq_irq068mon_field_t IRQ068MON_f;
  };
  union {
    volatile uint32_t IRQ069MON;
    stc_intreq_irq069mon_field_t IRQ069MON_f;
  };
  union {
    volatile uint32_t IRQ070MON;
    stc_intreq_irq070mon_field_t IRQ070MON_f;
  };
  union {
    volatile uint32_t IRQ071MON;
    stc_intreq_irq071mon_field_t IRQ071MON_f;
  };
  union {
    volatile uint32_t IRQ072MON;
    stc_intreq_irq072mon_field_t IRQ072MON_f;
  };
  union {
    volatile uint32_t IRQ073MON;
    stc_intreq_irq073mon_field_t IRQ073MON_f;
  };
  union {
    volatile uint32_t IRQ074MON;
    stc_intreq_irq074mon_field_t IRQ074MON_f;
  };
  union {
    volatile uint32_t IRQ075MON;
    stc_intreq_irq075mon_field_t IRQ075MON_f;
  };
  union {
    volatile uint32_t IRQ076MON;
    stc_intreq_irq076mon_field_t IRQ076MON_f;
  };
  union {
    volatile uint32_t IRQ077MON;
    stc_intreq_irq077mon_field_t IRQ077MON_f;
  };
  union {
    volatile uint32_t IRQ078MON;
    stc_intreq_irq078mon_field_t IRQ078MON_f;
  };
  union {
    volatile uint32_t IRQ079MON;
    stc_intreq_irq079mon_field_t IRQ079MON_f;
  };
  union {
    volatile uint32_t IRQ080MON;
    stc_intreq_irq080mon_field_t IRQ080MON_f;
  };
  union {
    volatile uint32_t IRQ081MON;
    stc_intreq_irq081mon_field_t IRQ081MON_f;
  };
  union {
    volatile uint32_t IRQ082MON;
    stc_intreq_irq082mon_field_t IRQ082MON_f;
  };
  union {
    volatile uint32_t IRQ083MON;
    stc_intreq_irq083mon_field_t IRQ083MON_f;
  };
  union {
    volatile uint32_t IRQ084MON;
    stc_intreq_irq084mon_field_t IRQ084MON_f;
  };
  union {
    volatile uint32_t IRQ085MON;
    stc_intreq_irq085mon_field_t IRQ085MON_f;
  };
  union {
    volatile uint32_t IRQ086MON;
    stc_intreq_irq086mon_field_t IRQ086MON_f;
  };
  union {
    volatile uint32_t IRQ087MON;
    stc_intreq_irq087mon_field_t IRQ087MON_f;
  };
  union {
    volatile uint32_t IRQ088MON;
    stc_intreq_irq088mon_field_t IRQ088MON_f;
  };
  union {
    volatile uint32_t IRQ089MON;
    stc_intreq_irq089mon_field_t IRQ089MON_f;
  };
  union {
    volatile uint32_t IRQ090MON;
    stc_intreq_irq090mon_field_t IRQ090MON_f;
  };
  union {
    volatile uint32_t IRQ091MON;
    stc_intreq_irq091mon_field_t IRQ091MON_f;
  };
  union {
    volatile uint32_t IRQ092MON;
    stc_intreq_irq092mon_field_t IRQ092MON_f;
  };
  union {
    volatile uint32_t IRQ093MON;
    stc_intreq_irq093mon_field_t IRQ093MON_f;
  };
  union {
    volatile uint32_t IRQ094MON;
    stc_intreq_irq094mon_field_t IRQ094MON_f;
  };
  union {
    volatile uint32_t IRQ095MON;
    stc_intreq_irq095mon_field_t IRQ095MON_f;
  };
  union {
    volatile uint32_t IRQ096MON;
    stc_intreq_irq096mon_field_t IRQ096MON_f;
  };
  union {
    volatile uint32_t IRQ097MON;
    stc_intreq_irq097mon_field_t IRQ097MON_f;
  };
  union {
    volatile uint32_t IRQ098MON;
    stc_intreq_irq098mon_field_t IRQ098MON_f;
  };
  union {
    volatile uint32_t IRQ099MON;
    stc_intreq_irq099mon_field_t IRQ099MON_f;
  };
  union {
    volatile uint32_t IRQ100MON;
    stc_intreq_irq100mon_field_t IRQ100MON_f;
  };
  union {
    volatile uint32_t IRQ101MON;
    stc_intreq_irq101mon_field_t IRQ101MON_f;
  };
  union {
    volatile uint32_t IRQ102MON;
    stc_intreq_irq102mon_field_t IRQ102MON_f;
  };
  union {
    volatile uint32_t IRQ103MON;
    stc_intreq_irq103mon_field_t IRQ103MON_f;
  };
  union {
    volatile uint32_t IRQ104MON;
    stc_intreq_irq104mon_field_t IRQ104MON_f;
  };
  union {
    volatile uint32_t IRQ105MON;
    stc_intreq_irq105mon_field_t IRQ105MON_f;
  };
  union {
    volatile uint32_t IRQ106MON;
    stc_intreq_irq106mon_field_t IRQ106MON_f;
  };
  union {
    volatile uint32_t IRQ107MON;
    stc_intreq_irq107mon_field_t IRQ107MON_f;
  };
  union {
    volatile uint32_t IRQ108MON;
    stc_intreq_irq108mon_field_t IRQ108MON_f;
  };
  union {
    volatile uint32_t IRQ109MON;
    stc_intreq_irq109mon_field_t IRQ109MON_f;
  };
  union {
    volatile uint32_t IRQ110MON;
    stc_intreq_irq110mon_field_t IRQ110MON_f;
  };
  union {
    volatile uint32_t IRQ111MON;
    stc_intreq_irq111mon_field_t IRQ111MON_f;
  };
  volatile uint32_t IRQ112MON;
  union {
    volatile uint32_t IRQ113MON;
    stc_intreq_irq113mon_field_t IRQ113MON_f;
  };
  union {
    volatile uint32_t IRQ114MON;
    stc_intreq_irq114mon_field_t IRQ114MON_f;
  };
  volatile uint32_t IRQ115MON;
  volatile uint32_t IRQ116MON;
  volatile uint32_t IRQ117MON;
  union {
    volatile uint32_t IRQ118MON;
    stc_intreq_irq118mon_field_t IRQ118MON_f;
  };
  union {
    volatile uint32_t IRQ119MON;
    stc_intreq_irq119mon_field_t IRQ119MON_f;
  };
  union {
    volatile uint32_t IRQ120MON;
    stc_intreq_irq120mon_field_t IRQ120MON_f;
  };
  union {
    volatile uint32_t IRQ121MON;
    stc_intreq_irq121mon_field_t IRQ121MON_f;
  };
  union {
    volatile uint32_t IRQ122MON;
    stc_intreq_irq122mon_field_t IRQ122MON_f;
  };
  union {
    volatile uint32_t IRQ123MON;
    stc_intreq_irq123mon_field_t IRQ123MON_f;
  };
  union {
    volatile uint32_t IRQ124MON;
    stc_intreq_irq124mon_field_t IRQ124MON_f;
  };
  union {
    volatile uint32_t IRQ125MON;
    stc_intreq_irq125mon_field_t IRQ125MON_f;
  };
  union {
    volatile uint32_t IRQ126MON;
    stc_intreq_irq126mon_field_t IRQ126MON_f;
  };
  union {
    volatile uint32_t IRQ127MON;
    stc_intreq_irq127mon_field_t IRQ127MON_f;
  };
}FM4_INTREQ_TypeDef;



 
typedef struct
{
  union {
    volatile uint32_t      IRQ03SEL;
    stc_irqsel_field_t IRQ03SEL_f;
  };
  union {
    volatile uint32_t      IRQ04SEL;
    stc_irqsel_field_t IRQ04SEL_f;
  };
  union {
    volatile uint32_t      IRQ05SEL;
    stc_irqsel_field_t IRQ05SEL_f;
  };
  union {
    volatile uint32_t      IRQ06SEL;
    stc_irqsel_field_t IRQ06SEL_f;
  };
  union {
    volatile uint32_t      IRQ07SEL;
    stc_irqsel_field_t IRQ07SEL_f;
  };
  union {
    volatile uint32_t      IRQ08SEL;
    stc_irqsel_field_t IRQ08SEL_f;
  };
  union {
    volatile uint32_t      IRQ09SEL;
    stc_irqsel_field_t IRQ09SEL_f;
  };
  union {
    volatile uint32_t      IRQ10SEL;
    stc_irqsel_field_t IRQ10SEL_f;
  };
} FM4_IRQSEL_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t PFR0;
    stc_gpio_pfr0_field_t PFR0_f;
  };
  union {
    volatile uint32_t PFR1;
    stc_gpio_pfr1_field_t PFR1_f;
  };
  union {
    volatile uint32_t PFR2;
    stc_gpio_pfr2_field_t PFR2_f;
  };
  union {
    volatile uint32_t PFR3;
    stc_gpio_pfr3_field_t PFR3_f;
  };
  union {
    volatile uint32_t PFR4;
    stc_gpio_pfr4_field_t PFR4_f;
  };
  union {
    volatile uint32_t PFR5;
    stc_gpio_pfr5_field_t PFR5_f;
  };
  union {
    volatile uint32_t PFR6;
    stc_gpio_pfr6_field_t PFR6_f;
  };
  union {
    volatile uint32_t PFR7;
    stc_gpio_pfr7_field_t PFR7_f;
  };
  union {
    volatile uint32_t PFR8;
    stc_gpio_pfr8_field_t PFR8_f;
  };
       uint8_t RESERVED8[20];
  union {
    volatile uint32_t PFRE;
    stc_gpio_pfre_field_t PFRE_f;
  };
       uint8_t RESERVED9[196];
  union {
    volatile uint32_t PCR0;
    stc_gpio_pcr0_field_t PCR0_f;
  };
  union {
    volatile uint32_t PCR1;
    stc_gpio_pcr1_field_t PCR1_f;
  };
  union {
    volatile uint32_t PCR2;
    stc_gpio_pcr2_field_t PCR2_f;
  };
  union {
    volatile uint32_t PCR3;
    stc_gpio_pcr3_field_t PCR3_f;
  };
  union {
    volatile uint32_t PCR4;
    stc_gpio_pcr4_field_t PCR4_f;
  };
  union {
    volatile uint32_t PCR5;
    stc_gpio_pcr5_field_t PCR5_f;
  };
  union {
    volatile uint32_t PCR6;
    stc_gpio_pcr6_field_t PCR6_f;
  };
  union {
    volatile uint32_t PCR7;
    stc_gpio_pcr7_field_t PCR7_f;
  };
  union {
    volatile uint32_t PCR8;
    stc_gpio_pcr8_field_t PCR8_f;
  };
       uint8_t RESERVED18[20];
  union {
    volatile uint32_t PCRE;
    stc_gpio_pcre_field_t PCRE_f;
  };
       uint8_t RESERVED19[196];
  union {
    volatile uint32_t DDR0;
    stc_gpio_ddr0_field_t DDR0_f;
  };
  union {
    volatile uint32_t DDR1;
    stc_gpio_ddr1_field_t DDR1_f;
  };
  union {
    volatile uint32_t DDR2;
    stc_gpio_ddr2_field_t DDR2_f;
  };
  union {
    volatile uint32_t DDR3;
    stc_gpio_ddr3_field_t DDR3_f;
  };
  union {
    volatile uint32_t DDR4;
    stc_gpio_ddr4_field_t DDR4_f;
  };
  union {
    volatile uint32_t DDR5;
    stc_gpio_ddr5_field_t DDR5_f;
  };
  union {
    volatile uint32_t DDR6;
    stc_gpio_ddr6_field_t DDR6_f;
  };
  union {
    volatile uint32_t DDR7;
    stc_gpio_ddr7_field_t DDR7_f;
  };
  union {
    volatile uint32_t DDR8;
    stc_gpio_ddr8_field_t DDR8_f;
  };
       uint8_t RESERVED28[20];
  union {
    volatile uint32_t DDRE;
    stc_gpio_ddre_field_t DDRE_f;
  };
       uint8_t RESERVED29[196];
  union {
    volatile uint32_t PDIR0;
    stc_gpio_pdir0_field_t PDIR0_f;
  };
  union {
    volatile uint32_t PDIR1;
    stc_gpio_pdir1_field_t PDIR1_f;
  };
  union {
    volatile uint32_t PDIR2;
    stc_gpio_pdir2_field_t PDIR2_f;
  };
  union {
    volatile uint32_t PDIR3;
    stc_gpio_pdir3_field_t PDIR3_f;
  };
  union {
    volatile uint32_t PDIR4;
    stc_gpio_pdir4_field_t PDIR4_f;
  };
  union {
    volatile uint32_t PDIR5;
    stc_gpio_pdir5_field_t PDIR5_f;
  };
  union {
    volatile uint32_t PDIR6;
    stc_gpio_pdir6_field_t PDIR6_f;
  };
  union {
    volatile uint32_t PDIR7;
    stc_gpio_pdir7_field_t PDIR7_f;
  };
  union {
    volatile uint32_t PDIR8;
    stc_gpio_pdir8_field_t PDIR8_f;
  };
       uint8_t RESERVED38[20];
  union {
    volatile uint32_t PDIRE;
    stc_gpio_pdire_field_t PDIRE_f;
  };
       uint8_t RESERVED39[196];
  union {
    volatile uint32_t PDOR0;
    stc_gpio_pdor0_field_t PDOR0_f;
  };
  union {
    volatile uint32_t PDOR1;
    stc_gpio_pdor1_field_t PDOR1_f;
  };
  union {
    volatile uint32_t PDOR2;
    stc_gpio_pdor2_field_t PDOR2_f;
  };
  union {
    volatile uint32_t PDOR3;
    stc_gpio_pdor3_field_t PDOR3_f;
  };
  union {
    volatile uint32_t PDOR4;
    stc_gpio_pdor4_field_t PDOR4_f;
  };
  union {
    volatile uint32_t PDOR5;
    stc_gpio_pdor5_field_t PDOR5_f;
  };
  union {
    volatile uint32_t PDOR6;
    stc_gpio_pdor6_field_t PDOR6_f;
  };
  union {
    volatile uint32_t PDOR7;
    stc_gpio_pdor7_field_t PDOR7_f;
  };
  union {
    volatile uint32_t PDOR8;
    stc_gpio_pdor8_field_t PDOR8_f;
  };
       uint8_t RESERVED48[20];
  union {
    volatile uint32_t PDORE;
    stc_gpio_pdore_field_t PDORE_f;
  };
       uint8_t RESERVED49[196];
  union {
    volatile uint32_t ADE;
    stc_gpio_ade_field_t ADE_f;
  };
       uint8_t RESERVED50[124];
  union {
    volatile uint32_t SPSR;
    stc_gpio_spsr_field_t SPSR_f;
  };
       uint8_t RESERVED51[124];
  union {
    volatile uint32_t EPFR00;
    stc_gpio_epfr00_field_t EPFR00_f;
  };
  union {
    volatile uint32_t EPFR01;
    stc_gpio_epfr01_field_t EPFR01_f;
  };
  union {
    volatile uint32_t EPFR02;
    stc_gpio_epfr02_field_t EPFR02_f;
  };
  union {
    volatile uint32_t EPFR03;
    stc_gpio_epfr03_field_t EPFR03_f;
  };
  union {
    volatile uint32_t EPFR04;
    stc_gpio_epfr04_field_t EPFR04_f;
  };
  union {
    volatile uint32_t EPFR05;
    stc_gpio_epfr05_field_t EPFR05_f;
  };
  union {
    volatile uint32_t EPFR06;
    stc_gpio_epfr06_field_t EPFR06_f;
  };
  union {
    volatile uint32_t EPFR07;
    stc_gpio_epfr07_field_t EPFR07_f;
  };
  union {
    volatile uint32_t EPFR08;
    stc_gpio_epfr08_field_t EPFR08_f;
  };
  union {
    volatile uint32_t EPFR09;
    stc_gpio_epfr09_field_t EPFR09_f;
  };
  union {
    volatile uint32_t EPFR10;
    stc_gpio_epfr10_field_t EPFR10_f;
  };
  union {
    volatile uint32_t EPFR11;
    stc_gpio_epfr11_field_t EPFR11_f;
  };
  union {
    volatile uint32_t EPFR12;
    stc_gpio_epfr12_field_t EPFR12_f;
  };
  union {
    volatile uint32_t EPFR13;
    stc_gpio_epfr13_field_t EPFR13_f;
  };
  union {
    volatile uint32_t EPFR14;
    stc_gpio_epfr14_field_t EPFR14_f;
  };
  union {
    volatile uint32_t EPFR15;
    stc_gpio_epfr15_field_t EPFR15_f;
  };
  union {
    volatile uint32_t EPFR16;
    stc_gpio_epfr16_field_t EPFR16_f;
  };
  union {
    volatile uint32_t EPFR17;
    stc_gpio_epfr17_field_t EPFR17_f;
  };
  union {
    volatile uint32_t EPFR18;
    stc_gpio_epfr18_field_t EPFR18_f;
  };
  volatile uint32_t EPFR19;
  union {
    volatile uint32_t EPFR20;
    stc_gpio_epfr20_field_t EPFR20_f;
  };
       uint8_t RESERVED72[172];
  union {
    volatile uint32_t PZR0;
    stc_gpio_pzr0_field_t PZR0_f;
  };
  union {
    volatile uint32_t PZR1;
    stc_gpio_pzr1_field_t PZR1_f;
  };
  union {
    volatile uint32_t PZR2;
    stc_gpio_pzr2_field_t PZR2_f;
  };
  union {
    volatile uint32_t PZR3;
    stc_gpio_pzr3_field_t PZR3_f;
  };
  union {
    volatile uint32_t PZR4;
    stc_gpio_pzr4_field_t PZR4_f;
  };
  union {
    volatile uint32_t PZR5;
    stc_gpio_pzr5_field_t PZR5_f;
  };
  union {
    volatile uint32_t PZR6;
    stc_gpio_pzr6_field_t PZR6_f;
  };
  union {
    volatile uint32_t PZR7;
    stc_gpio_pzr7_field_t PZR7_f;
  };
  union {
    volatile uint32_t PZR8;
    stc_gpio_pzr8_field_t PZR8_f;
  };
       uint8_t RESERVED81[20];
  union {
    volatile uint32_t PZRE;
    stc_gpio_pzre_field_t PZRE_f;
  };
}FM4_GPIO_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t LVD_CTL;
    stc_lvd_lvd_ctl_field_t LVD_CTL_f;
  };
        uint8_t RESERVED0[3];
  union {
    volatile  uint8_t LVD_STR;
    stc_lvd_lvd_str_field_t LVD_STR_f;
  };
        uint8_t RESERVED1[3];
  union {
    volatile  uint8_t LVD_CLR;
    stc_lvd_lvd_clr_field_t LVD_CLR_f;
  };
        uint8_t RESERVED2[3];
  volatile uint32_t LVD_RLR;
  union {
    volatile  uint8_t LVD_STR2;
    stc_lvd_lvd_str2_field_t LVD_STR2_f;
  };
}FM4_LVD_TypeDef;



 
 
typedef struct
{
       uint8_t RESERVED10[4];
  union {
    volatile  uint8_t RCK_CTL;
    stc_ds_rck_ctl_field_t RCK_CTL_f;
  };
       uint8_t RESERVED0[1787];
  union {
    volatile  uint8_t PMD_CTL;
    stc_ds_pmd_ctl_field_t PMD_CTL_f;
  };
       uint8_t RESERVED1[3];
  union {
    volatile  uint8_t WRFSR;
    stc_ds_wrfsr_field_t WRFSR_f;
  };
       uint8_t RESERVED2[3];
  union {
    volatile uint16_t WIFSR;
    stc_ds_wifsr_field_t WIFSR_f;
  };
       uint8_t RESERVED3[2];
  union {
    volatile uint16_t WIER;
    stc_ds_wier_field_t WIER_f;
  };
       uint8_t RESERVED4[2];
  union {
    volatile  uint8_t WILVR;
    stc_ds_wilvr_field_t WILVR_f;
  };
       uint8_t RESERVED5[3];
  union {
    volatile  uint8_t DSRAMR;
    stc_ds_dsramr_field_t DSRAMR_f;
  };
       uint8_t RESERVED6[235];
  volatile  uint8_t BUR01;
  volatile  uint8_t BUR02;
  volatile  uint8_t BUR03;
  volatile  uint8_t BUR04;
  volatile  uint8_t BUR05;
  volatile  uint8_t BUR06;
  volatile  uint8_t BUR07;
  volatile  uint8_t BUR08;
  volatile  uint8_t BUR09;
  volatile  uint8_t BUR10;
  volatile  uint8_t BUR11;
  volatile  uint8_t BUR12;
  volatile  uint8_t BUR13;
  volatile  uint8_t BUR14;
  volatile  uint8_t BUR15;
  volatile  uint8_t BUR16;
}FM4_DS_TypeDef;



 
 





















































 



 
 
typedef struct
{
  union {
    volatile  uint8_t CANPRE;
    stc_canpre_canpre_field_t CANPRE_f;
  };
}FM4_CANPRE_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t UCCR;
    stc_usbethernetclk_uccr_field_t UCCR_f;
  };
        uint8_t RESERVED0[3];
  union {
    volatile  uint8_t UPCR1;
    stc_usbethernetclk_upcr1_field_t UPCR1_f;
  };
        uint8_t RESERVED1[3];
  union {
    volatile  uint8_t UPCR2;
    stc_usbethernetclk_upcr2_field_t UPCR2_f;
  };
        uint8_t RESERVED2[3];
  union {
    volatile  uint8_t UPCR3;
    stc_usbethernetclk_upcr3_field_t UPCR3_f;
  };
        uint8_t RESERVED3[3];
  union {
    volatile  uint8_t UPCR4;
    stc_usbethernetclk_upcr4_field_t UPCR4_f;
  };
        uint8_t RESERVED4[3];
  union {
    volatile  uint8_t UP_STR;
    stc_usbethernetclk_up_str_field_t UP_STR_f;
  };
        uint8_t RESERVED5[3];
  union {
    volatile  uint8_t UPINT_ENR;
    stc_usbethernetclk_upint_enr_field_t UPINT_ENR_f;
  };
        uint8_t RESERVED6[3];
  union {
    volatile  uint8_t UPINT_CLR;
    stc_usbethernetclk_upint_clr_field_t UPINT_CLR_f;
  };
        uint8_t RESERVED7[3];
  union {
    volatile  uint8_t UPINT_STR;
    stc_usbethernetclk_upint_str_field_t UPINT_STR_f;
  };
        uint8_t RESERVED8[3];
  union {
    volatile  uint8_t UPCR5;
    stc_usbethernetclk_upcr5_field_t UPCR5_f;
  };
        uint8_t RESERVED9[3];
  union {
    volatile  uint8_t UPCR6;
    stc_usbethernetclk_upcr6_field_t UPCR6_f;
  };
        uint8_t RESERVED10[3];
  union {
    volatile  uint8_t UPCR7;
    stc_usbethernetclk_upcr7_field_t UPCR7_f;
  };
        uint8_t RESERVED11[3];
  union {
    volatile  uint8_t USBEN0;
    stc_usbethernetclk_usben0_field_t USBEN0_f;
  };
        uint8_t RESERVED12[3];
  union {
    volatile  uint8_t USBEN1;
    stc_usbethernetclk_usben1_field_t USBEN1_f;
  };
}FM4_USBETHERNETCLK_TypeDef;



 
typedef struct
{
  union {
    volatile  uint8_t       SMR;
    stc_mfs_smr_field_t SMR_f;
  };
  union {
    volatile  uint8_t            SCR;
    stc_mfs_scr_field_t      SCR_f;
    volatile  uint8_t            IBCR;
    stc_mfs_i2c_ibcr_field_t IBCR_f;
  };
        uint8_t RESERVED0[2];
  union {
    volatile  uint8_t            ESCR;
    stc_mfs_escr_field_t     ESCR_f;
    volatile  uint8_t            IBSR;
    stc_mfs_i2c_ibsr_field_t IBSR_f;
  };
  union {
    volatile  uint8_t       SSR;
    stc_mfs_ssr_field_t SSR_f;
  };
        uint8_t RESERVED1[2];
  union {
    volatile uint32_t RDR32;
    volatile uint32_t TDR32;
    struct {
      union {
        volatile uint16_t            RDR;
        stc_mfs_uart_rdr_field_t RDR_f;
      };
             uint8_t RESERVED2[2];
    };
    struct {
      union {
        volatile uint16_t            TDR;
        stc_mfs_uart_tdr_field_t TDR_f;
      };
             uint8_t RESERVED3[2];
    };
  };
  union {
    union {
      volatile uint16_t       BGR;
      stc_mfs_bgr_field_t BGR_f;
    };
    struct {
      volatile  uint8_t BGR0;
      union {
        volatile  uint8_t        BGR1;
        stc_mfs_bgr1_field_t BGR1_f;
      };
    };
  };
        uint8_t RESERVED4[2];
  union {
    volatile  uint8_t            ISBA;
    stc_mfs_i2c_isba_field_t ISBA_f;
  };
  union {
    volatile  uint8_t            ISMK;
    stc_mfs_i2c_ismk_field_t ISMK_f;
  };
        uint8_t RESERVED5[2];
  union {
    union {
      volatile uint16_t       FCR;
      stc_mfs_fcr_field_t FCR_f;
    };
    struct {
      union {
        volatile  uint8_t        FCR0;
        stc_mfs_fcr0_field_t FCR0_f;
      };
      union {
        volatile  uint8_t        FCR1;
        stc_mfs_fcr1_field_t FCR1_f;
      };
    };
  };
        uint8_t RESERVED6[2];
  union {
    union {
      volatile uint16_t         FBYTE;
      stc_mfs_fbyte_field_t FBYTE_f;
    };
    struct {
      union {
        volatile  uint8_t          FBYTE1;
        stc_mfs_fbyte1_field_t FBYTE1_f;
      };
      union {
        volatile  uint8_t          FBYTE2;
        stc_mfs_fbyte2_field_t FBYTE2_f;
      };
    };
  };
        uint8_t RESERVED7[2];
  union {
    volatile uint16_t                SCSTR10;
    stc_mfs_csio_scstr10_field_t SCSTR10_f;
    struct {
      union {
        volatile  uint8_t               SCSTR0;
        stc_mfs_csio_scstr0_field_t SCSTR0_f;
        volatile  uint8_t NFCR;
        stc_mfs_i2c_nfcr_field_t NFCR_f;
      };
      union {
        volatile  uint8_t               SCSTR1;
        stc_mfs_csio_scstr1_field_t SCSTR1_f;
        volatile  uint8_t               EIBCR;
        stc_mfs_i2c_eibcr_field_t   EIBCR_f;
      };
    };
  };
        uint8_t RESERVED8[2];
  union {
    volatile uint16_t                SCSTR32;
    stc_mfs_csio_scstr32_field_t SCSTR32_f;
    struct {
      union {
        volatile  uint8_t               SCSTR2;
        stc_mfs_csio_scstr2_field_t SCSTR2_f;
      };
      union {
        volatile  uint8_t               SCSTR3;
        stc_mfs_csio_scstr3_field_t SCSTR3_f;
      };
    };
  };
        uint8_t RESERVED9[2];
  union {
    volatile uint16_t              SACSR;
    stc_mfs_csio_sacsr_field_t SACSR_f;
    struct {
      union {
        volatile  uint8_t               SACSR0;
        stc_mfs_csio_sacsr0_field_t SACSR0_f;
      };
      union {
        volatile  uint8_t               SACSR1;
        stc_mfs_csio_sacsr1_field_t SACSR1_f;
      };
    };
  };
        uint8_t RESERVED10[2];
  union {
    volatile uint16_t             STMR;
    stc_mfs_csio_stmr_field_t STMR_f;
    struct {
      union {
        volatile  uint8_t              STMR0;
        stc_mfs_csio_stmr0_field_t STMR0_f;
      };
      union {
        volatile  uint8_t              STMR1;
        stc_mfs_csio_stmr1_field_t STMR1_f;
      };
    };
  };
        uint8_t RESERVED11[2];
  union {
    volatile uint16_t              STMCR;
    stc_mfs_csio_stmcr_field_t STMCR_f;
    struct {
      union {
        volatile  uint8_t               STMCR0;
        stc_mfs_csio_stmcr0_field_t STMCR0_f;
      };
      union {
        volatile  uint8_t               STMCR1;
        stc_mfs_csio_stmcr1_field_t STMCR1_f;
      };
    };
  };
        uint8_t RESERVED12[2];
  union {
    volatile uint16_t              SCSCR;
    stc_mfs_csio_scscr_field_t SCSCR_f;
  };
        uint8_t RESERVED13[2];
  union {
    volatile uint16_t SCSFR;
    struct {
      volatile  uint8_t SCSFR0;
      volatile  uint8_t SCSFR1;
    };
  };
        uint8_t RESERVED14[2];
  volatile  uint8_t SCSFR2;
        uint8_t RESERVED15[3];
  union {
    volatile uint16_t TBYTE10;
    struct {
      volatile  uint8_t TBYTE0;
      volatile  uint8_t TBYTE1;
    };
  };
        uint8_t RESERVED16[2];
  union {
    volatile uint16_t TBYTE32;
    struct {
      volatile  uint8_t TBYTE2;
      volatile  uint8_t TBYTE3;
    };
  };
}FM4_MFS_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t CRCCR;
    stc_crc_crccr_field_t CRCCR_f;
  };
        uint8_t RESERVED0[3];
  volatile uint32_t CRCINIT;
  union {
    volatile uint32_t CRCIN;
    struct {
      union {
        volatile uint16_t CRCINL;
        struct {
          volatile  uint8_t CRCINLL;
          volatile  uint8_t CRCINLH;
        };
      };
      union {
        volatile uint16_t CRCINH;
        struct {
          volatile  uint8_t CRCINHL;
          volatile  uint8_t CRCINHH;
        };
      };
    };
  };
  volatile uint32_t CRCR;
}FM4_CRC_TypeDef;



 
 
typedef struct
{
  volatile uint32_t DESTP;
  union {
    volatile uint32_t HWDESP;
	stc_dstc_hwdesp_field_t HWDESP_f;
  };
  volatile uint8_t CMD;
  union {
    volatile uint8_t CFG;
	stc_dstc_cfg_field_t CFG_f;
  };
  union {
    volatile uint16_t SWTR;
	stc_dstc_swtr_field_t SWTR_f;
  };
  union {
    volatile uint32_t MONERS;
	stc_dstc_moners_field_t MONERS_f;
  };
  volatile uint32_t DREQENB0;
  volatile uint32_t DREQENB1;
  volatile uint32_t DREQENB2;
  volatile uint32_t DREQENB3;
  volatile uint32_t DREQENB4;
  volatile uint32_t DREQENB5;
  volatile uint32_t DREQENB6;
  volatile uint32_t DREQENB7;
  volatile uint32_t HWINT0;
  volatile uint32_t HWINT1;
  volatile uint32_t HWINT2;
  volatile uint32_t HWINT3;
  volatile uint32_t HWINT4;
  volatile uint32_t HWINT5;
  volatile uint32_t HWINT6;
  volatile uint32_t HWINT7;
  volatile uint32_t HWINTCLR0;
  volatile uint32_t HWINTCLR1;
  volatile uint32_t HWINTCLR2;
  volatile uint32_t HWINTCLR3;
  volatile uint32_t HWINTCLR4;
  volatile uint32_t HWINTCLR5;
  volatile uint32_t HWINTCLR6;
  volatile uint32_t HWINTCLR7;
  volatile uint32_t DQMSK0;
  volatile uint32_t DQMSK1;
  volatile uint32_t DQMSK2;
  volatile uint32_t DQMSK3;
  volatile uint32_t DQMSK4;
  volatile uint32_t DQMSK5;
  volatile uint32_t DQMSK6;
  volatile uint32_t DQMSK7;
  volatile uint32_t DQMSKCLR0;
  volatile uint32_t DQMSKCLR1;
  volatile uint32_t DQMSKCLR2;
  volatile uint32_t DQMSKCLR3;
  volatile uint32_t DQMSKCLR4;
  volatile uint32_t DQMSKCLR5;
  volatile uint32_t DQMSKCLR6;
  volatile uint32_t DQMSKCLR7;
}FM4_DSTC_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t WCRD;
    stc_wc_wcrd_field_t WCRD_f;
  };
  union {
    volatile  uint8_t WCRL;
    stc_wc_wcrl_field_t WCRL_f;
  };
  union {
    volatile  uint8_t WCCR;
    stc_wc_wccr_field_t WCCR_f;
  };
        uint8_t RESERVED0[13];
  union {
    volatile uint16_t CLK_SEL;
    stc_wc_clk_sel_field_t CLK_SEL_f;
  };
        uint8_t RESERVED1[2];
  union {
    volatile  uint8_t CLK_EN;
    stc_wc_clk_en_field_t CLK_EN_f;
  };
}FM4_WC_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t WTCR10;
    stc_rtc_wtcr10_field_t WTCR10_f;
  };
        uint8_t RESERVED1[3];
  union {
    volatile  uint8_t WTCR11;
    stc_rtc_wtcr11_field_t WTCR11_f;
  };
        uint8_t RESERVED2[3];
  union {
    volatile  uint8_t WTCR12;
    stc_rtc_wtcr12_field_t WTCR12_f;
  };
        uint8_t RESERVED3[3];
  union {
    volatile  uint8_t WTCR13;
    stc_rtc_wtcr13_field_t WTCR13_f;
  };
        uint8_t RESERVED4[3];
  union {
    volatile  uint8_t WTCR20;
    stc_rtc_wtcr20_field_t WTCR20_f;
  };
        uint8_t RESERVED5[3];
  union {
    volatile  uint8_t WTCR21;
    stc_rtc_wtcr21_field_t WTCR21_f;
  };
        uint8_t RESERVED6[3];
  volatile  uint8_t WTCR22;
        uint8_t RESERVED7[3];
  union {
    volatile  uint8_t WTSR;
    stc_rtc_wtsr_field_t WTSR_f;
  };
        uint8_t RESERVED8[3];
  union {
    volatile  uint8_t WTMIR;
    stc_rtc_wtmir_field_t WTMIR_f;
  };
        uint8_t RESERVED9[3];
  union {
    volatile  uint8_t WTHR;
    stc_rtc_wthr_field_t WTHR_f;
  };
        uint8_t RESERVED10[3];
  union {
    volatile  uint8_t WTDR;
    stc_rtc_wtdr_field_t WTDR_f;
  };
        uint8_t RESERVED11[3];
  union {
    volatile  uint8_t WTDW;
    stc_rtc_wtdw_field_t WTDW_f;
  };
        uint8_t RESERVED12[3];
  union {
    volatile  uint8_t WTMOR;
    stc_rtc_wtmor_field_t WTMOR_f;
  };
        uint8_t RESERVED13[3];
  union {
    volatile  uint8_t WTYR;
    stc_rtc_wtyr_field_t WTYR_f;
  };
        uint8_t RESERVED14[3];
  union {
    volatile  uint8_t ALMIR;
    stc_rtc_almir_field_t ALMIR_f;
  };
        uint8_t RESERVED15[3];
  union {
    volatile  uint8_t ALHR;
    stc_rtc_alhr_field_t ALHR_f;
  };
        uint8_t RESERVED16[3];
  union {
    volatile  uint8_t ALDR;
    stc_rtc_aldr_field_t ALDR_f;
  };
        uint8_t RESERVED17[3];
  union {
    volatile  uint8_t ALMOR;
    stc_rtc_almor_field_t ALMOR_f;
  };
        uint8_t RESERVED18[3];
  union {
    volatile  uint8_t ALYR;
    stc_rtc_alyr_field_t ALYR_f;
  };
        uint8_t RESERVED19[3];
  union {
    volatile  uint8_t WTTR0;
    stc_rtc_wttr0_field_t WTTR0_f;
  };
        uint8_t RESERVED20[3];
  union {
    volatile  uint8_t WTTR1;
    stc_rtc_wttr1_field_t WTTR1_f;
  };
        uint8_t RESERVED21[3];
  union {
    volatile  uint8_t WTTR2;
    stc_rtc_wttr2_field_t WTTR2_f;
  };
        uint8_t RESERVED22[3];
  volatile  uint8_t WTCAL0;
        uint8_t RESERVED23[3];
  union {
    volatile  uint8_t WTCAL1;
    stc_rtc_wtcal1_field_t WTCAL1_f;
  };
        uint8_t RESERVED24[3];
  union {
    volatile  uint8_t WTCALEN;
    stc_rtc_wtcalen_field_t WTCALEN_f;
  };
        uint8_t RESERVED25[3];
  union {
    volatile  uint8_t WTDIV;
    stc_rtc_wtdiv_field_t WTDIV_f;
  };
        uint8_t RESERVED26[3];
  union {
    volatile  uint8_t WTDIVEN;
    stc_rtc_wtdiven_field_t WTDIVEN_f;
  };
        uint8_t RESERVED27[3];
  union {
    volatile  uint8_t WTCALPRD;
    stc_rtc_wtcalprd_field_t WTCALPRD_f;
  };
        uint8_t RESERVED28[3];
  union {
    volatile  uint8_t WTCOSEL;
    stc_rtc_wtcosel_field_t WTCOSEL_f;
  };
        uint8_t RESERVED29[3];
  union {
    volatile  uint8_t VB_CLKDIV;
    stc_rtc_vb_clkdiv_field_t VB_CLKDIV_f;
  };
        uint8_t RESERVED30[3];
  union {
    volatile  uint8_t WTOSCCNT;
    stc_rtc_wtosccnt_field_t WTOSCCNT_f;
  };
        uint8_t RESERVED31[3];
  volatile  uint8_t CCS;
        uint8_t RESERVED32[3];
  volatile  uint8_t CCB;
        uint8_t RESERVED33[3];
   
  volatile  uint8_t TRIM;
        uint8_t RESERVED34[3];
  union {
    volatile  uint8_t BOOST;
    stc_rtc_boost_field_t BOOST_f;
  };
        uint8_t RESERVED35[3];
  union {
    volatile  uint8_t EWKUP;
    stc_rtc_ewkup_field_t EWKUP_f;
  };
        uint8_t RESERVED36[3];
  union {
    volatile  uint8_t VDET;
    stc_rtc_vdet_field_t VDET_f;
  };
        uint8_t RESERVED37[3];
   
  volatile  uint8_t FDET;
        uint8_t RESERVED38[3];
  union {
    volatile  uint8_t HIBRST;
    stc_rtc_hibrst_field_t HIBRST_f;
  };
        uint8_t RESERVED39[3];
  union {
    volatile  uint8_t VBPFR;
    stc_rtc_vbpfr_field_t VBPFR_f;
  };
        uint8_t RESERVED40[3];
  union {
    volatile  uint8_t VBPCR;
    stc_rtc_vbpcr_field_t VBPCR_f;
  };
        uint8_t RESERVED41[3];
  union {
    volatile  uint8_t VBDDR;
    stc_rtc_vbddr_field_t VBDDR_f;
  };
        uint8_t RESERVED42[3];
  union {
    volatile  uint8_t VBDIR;
    stc_rtc_vbdir_field_t VBDIR_f;
  };
        uint8_t RESERVED43[3];
  union {
    volatile  uint8_t VBDOR;
    stc_rtc_vbdor_field_t VBDOR_f;
  };
        uint8_t RESERVED44[3];
  union {
    volatile  uint8_t VBPZR;
    stc_rtc_vbpzr_field_t VBPZR_f;
  };
        uint8_t RESERVED45[79];
  union {
    volatile uint32_t BREG00_03;
    struct {
      volatile uint16_t BREG00_01;
      volatile uint16_t BREG02_03;
    };
    struct {
      volatile  uint8_t BREG00;
      volatile  uint8_t BREG01;
      volatile  uint8_t BREG02;
      volatile  uint8_t BREG03;
    };
  };
  union {
    volatile uint32_t BREG04_07;
    struct {
      volatile uint16_t BREG04_05;
      volatile uint16_t BREG06_07;
    };
    struct {
      volatile  uint8_t BREG04;
      volatile  uint8_t BREG05;
      volatile  uint8_t BREG06;
      volatile  uint8_t BREG07;
    };
  };
  union {
    volatile uint32_t BREG08_0B;
    struct {
      volatile uint16_t BREG08_09;
      volatile uint16_t BREG0A_0B;
    };
    struct {
      volatile  uint8_t BREG08;
      volatile  uint8_t BREG09;
      volatile  uint8_t BREG0A;
      volatile  uint8_t BREG0B;
    };
  };
  union {
    volatile uint32_t BREG0C_0F;
    struct {
      volatile uint16_t BREG0C_0D;
      volatile uint16_t BREG0E_0F;
    };
    struct {
      volatile  uint8_t BREG0C;
      volatile  uint8_t BREG0D;
      volatile  uint8_t BREG0E;
      volatile  uint8_t BREG0F;
    };
  };
  union {
    volatile uint32_t BREG10_13;
    struct {
      volatile uint16_t BREG10_11;
      volatile uint16_t BREG12_13;
    };
    struct {
      volatile  uint8_t BREG10;
      volatile  uint8_t BREG11;
      volatile  uint8_t BREG12;
      volatile  uint8_t BREG13;
    };
  };
  union {
    volatile uint32_t BREG14_17;
    struct {
      volatile uint16_t BREG14_15;
      volatile uint16_t BREG16_17;
    };
    struct {
      volatile  uint8_t BREG14;
      volatile  uint8_t BREG15;
      volatile  uint8_t BREG16;
      volatile  uint8_t BREG17;
    };
  };
  union {
    volatile uint32_t BREG18_1B;
    struct {
      volatile uint16_t BREG18_19;
      volatile uint16_t BREG1A_1B;
    };
    struct {
      volatile  uint8_t BREG18;
      volatile  uint8_t BREG19;
      volatile  uint8_t BREG1A;
      volatile  uint8_t BREG1B;
    };
  };
  union {
    volatile uint32_t BREG1C_1F;
    struct {
      volatile uint16_t BREG1C_1D;
      volatile uint16_t BREG1E_1F;
    };
    struct {
      volatile  uint8_t BREG1C;
      volatile  uint8_t BREG1D;
      volatile  uint8_t BREG1E;
      volatile  uint8_t BREG1F;
    };
  };
  union {
    volatile uint32_t BREG20_23;
    struct {
      volatile uint16_t BREG20_21;
      volatile uint16_t BREG22_23;
    };
    struct {
      volatile  uint8_t BREG20;
      volatile  uint8_t BREG21;
      volatile  uint8_t BREG22;
      volatile  uint8_t BREG23;
    };
  };
  union {
    volatile uint32_t BREG24_27;
    struct {
      volatile uint16_t BREG24_25;
      volatile uint16_t BREG26_27;
    };
    struct {
      volatile  uint8_t BREG24;
      volatile  uint8_t BREG25;
      volatile  uint8_t BREG26;
      volatile  uint8_t BREG27;
    };
  };
  union {
    volatile uint32_t BREG28_2B;
    struct {
      volatile uint16_t BREG28_29;
      volatile uint16_t BREG2A_2B;
    };
    struct {
      volatile  uint8_t BREG28;
      volatile  uint8_t BREG29;
      volatile  uint8_t BREG2A;
      volatile  uint8_t BREG2B;
    };
  };
  union {
    volatile uint32_t BREG2C_2F;
    struct {
      volatile uint16_t BREG2C_2D;
      volatile uint16_t BREG2E_2F;
    };
    struct {
      volatile  uint8_t BREG2C;
      volatile  uint8_t BREG2D;
      volatile  uint8_t BREG2E;
      volatile  uint8_t BREG2F;
    };
  };
  union {
    volatile uint32_t BREG30_33;
    struct {
      volatile uint16_t BREG30_31;
      volatile uint16_t BREG32_33;
    };
    struct {
      volatile  uint8_t BREG30;
      volatile  uint8_t BREG31;
      volatile  uint8_t BREG32;
      volatile  uint8_t BREG33;
    };
  };
  union {
    volatile uint32_t BREG34_37;
    struct {
      volatile uint16_t BREG34_35;
      volatile uint16_t BREG36_37;
    };
    struct {
      volatile  uint8_t BREG34;
      volatile  uint8_t BREG35;
      volatile  uint8_t BREG36;
      volatile  uint8_t BREG37;
    };
  };
  union {
    volatile uint32_t BREG38_3B;
    struct {
      volatile uint16_t BREG38_39;
      volatile uint16_t BREG3A_3B;
    };
    struct {
      volatile  uint8_t BREG38;
      volatile  uint8_t BREG39;
      volatile  uint8_t BREG3A;
      volatile  uint8_t BREG3B;
    };
  };
  union {
    volatile uint32_t BREG3C_3F;
    struct {
      volatile uint16_t BREG3C_3D;
      volatile uint16_t BREG3E_3F;
    };
    struct {
      volatile  uint8_t BREG3C;
      volatile  uint8_t BREG3D;
      volatile  uint8_t BREG3E;
      volatile  uint8_t BREG3F;
    };
  };
  union {
    volatile uint32_t BREG40_43;
    struct {
      volatile uint16_t BREG40_41;
      volatile uint16_t BREG42_43;
    };
    struct {
      volatile  uint8_t BREG40;
      volatile  uint8_t BREG41;
      volatile  uint8_t BREG42;
      volatile  uint8_t BREG43;
    };
  };
  union {
    volatile uint32_t BREG44_47;
    struct {
      volatile uint16_t BREG44_45;
      volatile uint16_t BREG46_47;
    };
    struct {
      volatile  uint8_t BREG44;
      volatile  uint8_t BREG45;
      volatile  uint8_t BREG46;
      volatile  uint8_t BREG47;
    };
  };
  union {
    volatile uint32_t BREG48_4B;
    struct {
      volatile uint16_t BREG48_49;
      volatile uint16_t BREG4A_4B;
    };
    struct {
      volatile  uint8_t BREG48;
      volatile  uint8_t BREG49;
      volatile  uint8_t BREG4A;
      volatile  uint8_t BREG4B;
    };
  };
  union {
    volatile uint32_t BREG4C_4F;
    struct {
      volatile uint16_t BREG4C_4D;
      volatile uint16_t BREG4E_4F;
    };
    struct {
      volatile  uint8_t BREG4C;
      volatile  uint8_t BREG4D;
      volatile  uint8_t BREG4E;
      volatile  uint8_t BREG4F;
    };
  };
  union {
    volatile uint32_t BREG50_53;
    struct {
      volatile uint16_t BREG50_51;
      volatile uint16_t BREG52_53;
    };
    struct {
      volatile  uint8_t BREG50;
      volatile  uint8_t BREG51;
      volatile  uint8_t BREG52;
      volatile  uint8_t BREG53;
    };
  };
  union {
    volatile uint32_t BREG54_57;
    struct {
      volatile uint16_t BREG54_55;
      volatile uint16_t BREG56_57;
    };
    struct {
      volatile  uint8_t BREG54;
      volatile  uint8_t BREG55;
      volatile  uint8_t BREG56;
      volatile  uint8_t BREG57;
    };
  };
  union {
    volatile uint32_t BREG58_5B;
    struct {
      volatile uint16_t BREG58_59;
      volatile uint16_t BREG5A_5B;
    };
    struct {
      volatile  uint8_t BREG58;
      volatile  uint8_t BREG59;
      volatile  uint8_t BREG5A;
      volatile  uint8_t BREG5B;
    };
  };
  union {
    volatile uint32_t BREG5C_5F;
    struct {
      volatile uint16_t BREG5C_5D;
      volatile uint16_t BREG5E_5F;
    };
    struct {
      volatile  uint8_t BREG5C;
      volatile  uint8_t BREG5D;
      volatile  uint8_t BREG5E;
      volatile  uint8_t BREG5F;
    };
  };
  union {
    volatile uint32_t BREG60_63;
    struct {
      volatile uint16_t BREG60_61;
      volatile uint16_t BREG62_63;
    };
    struct {
      volatile  uint8_t BREG60;
      volatile  uint8_t BREG61;
      volatile  uint8_t BREG62;
      volatile  uint8_t BREG63;
    };
  };
  union {
    volatile uint32_t BREG64_67;
    struct {
      volatile uint16_t BREG64_65;
      volatile uint16_t BREG66_67;
    };
    struct {
      volatile  uint8_t BREG64;
      volatile  uint8_t BREG65;
      volatile  uint8_t BREG66;
      volatile  uint8_t BREG67;
    };
  };
  union {
    volatile uint32_t BREG68_6B;
    struct {
      volatile uint16_t BREG68_69;
      volatile uint16_t BREG6A_6B;
    };
    struct {
      volatile  uint8_t BREG68;
      volatile  uint8_t BREG69;
      volatile  uint8_t BREG6A;
      volatile  uint8_t BREG6B;
    };
  };
  union {
    volatile uint32_t BREG6C_6F;
    struct {
      volatile uint16_t BREG6C_6D;
      volatile uint16_t BREG6E_6F;
    };
    struct {
      volatile  uint8_t BREG6C;
      volatile  uint8_t BREG6D;
      volatile  uint8_t BREG6E;
      volatile  uint8_t BREG6F;
    };
  };
  union {
    volatile uint32_t BREG70_73;
    struct {
      volatile uint16_t BREG70_71;
      volatile uint16_t BREG72_73;
    };
    struct {
      volatile  uint8_t BREG70;
      volatile  uint8_t BREG71;
      volatile  uint8_t BREG72;
      volatile  uint8_t BREG73;
    };
  };
  union {
    volatile uint32_t BREG74_77;
    struct {
      volatile uint16_t BREG74_75;
      volatile uint16_t BREG76_77;
    };
    struct {
      volatile  uint8_t BREG74;
      volatile  uint8_t BREG75;
      volatile  uint8_t BREG76;
      volatile  uint8_t BREG77;
    };
  };
  union {
    volatile uint32_t BREG78_7B;
    struct {
      volatile uint16_t BREG78_79;
      volatile uint16_t BREG7A_7B;
    };
    struct {
      volatile  uint8_t BREG78;
      volatile  uint8_t BREG79;
      volatile  uint8_t BREG7A;
      volatile  uint8_t BREG7B;
    };
  };
  union {
    volatile uint32_t BREG7C_7F;
    struct {
      volatile uint16_t BREG7C_7D;
      volatile uint16_t BREG7E_7F;
    };
    struct {
      volatile  uint8_t BREG7C;
      volatile  uint8_t BREG7D;
      volatile  uint8_t BREG7E;
      volatile  uint8_t BREG7F;
    };
  };
}FM4_RTC_TypeDef;



 
 
typedef struct
{
  union {
    volatile  uint8_t LCR_PRSLD;
    stc_lcr_lcr_prsld_field_t LCR_PRSLD_f;
  };
}FM4_LCR_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t CKEN0;
    stc_clk_gating_cken0_field_t CKEN0_f;
  };
  union {
    volatile uint32_t MRST0;
    stc_clk_gating_mrst0_field_t MRST0_f;
  };
       uint8_t RESERVED1[8];
  union {
    volatile uint32_t CKEN1;
    stc_clk_gating_cken1_field_t CKEN1_f;
  };
  union {
    volatile uint32_t MRST1;
    stc_clk_gating_mrst1_field_t MRST1_f;
  };
       uint8_t RESERVED3[8];
  union {
    volatile uint32_t CKEN2;
    stc_clk_gating_cken2_field_t CKEN2_f;
  };
  union {
    volatile uint32_t MRST2;
    stc_clk_gating_mrst2_field_t MRST2_f;
  };
}FM4_CLK_GATING_TypeDef;



 
 
typedef struct
{
  volatile uint32_t SSCTL1;
  volatile uint32_t SSCTL2;
}FM4_PLL_CONTROL_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t MODE0;
    stc_exbus_mode_field_t MODE0_f;
  };
  union {
    volatile uint32_t MODE1;
    stc_exbus_mode_field_t MODE1_f;
  };
  union {
    volatile uint32_t MODE2;
    stc_exbus_mode_field_t MODE2_f;
  };
  union {
    volatile uint32_t MODE3;
    stc_exbus_mode_field_t MODE3_f;
  };
  union {
    volatile uint32_t MODE4;
    stc_exbus_mode_field_t MODE4_f;
  };
  union {
    volatile uint32_t MODE5;
    stc_exbus_mode_field_t MODE5_f;
  };
  union {
    volatile uint32_t MODE6;
    stc_exbus_mode_field_t MODE6_f;
  };
  union {
    volatile uint32_t MODE7;
    stc_exbus_mode_field_t MODE7_f;
  };
  union {
    volatile uint32_t TIM0;
    stc_exbus_tim_field_t TIM0_f;
  };
  volatile uint32_t TIM1;
  union {
    volatile uint32_t TIM2;
    stc_exbus_tim_field_t TIM2_f;
  };
  union {
    volatile uint32_t TIM3;
    stc_exbus_tim_field_t TIM3_f;
  };
  union {
    volatile uint32_t TIM4;
    stc_exbus_tim_field_t TIM4_f;
  };
  union {
    volatile uint32_t TIM5;
    stc_exbus_tim_field_t TIM5_f;
  };
  union {
    volatile uint32_t TIM6;
    stc_exbus_tim_field_t TIM6_f;
  };
  union {
    volatile uint32_t TIM7;
    stc_exbus_tim_field_t TIM7_f;
  };
  union {
    volatile uint32_t AREA0;
    stc_exbus_area_field_t AREA0_f;
  };
  union {
    volatile uint32_t AREA1;
    stc_exbus_area_field_t AREA1_f;
  };
  union {
    volatile uint32_t AREA2;
    stc_exbus_area_field_t AREA2_f;
  };
  union {
    volatile uint32_t AREA3;
    stc_exbus_area_field_t AREA3_f;
  };
  union {
    volatile uint32_t AREA4;
    stc_exbus_area_field_t AREA4_f;
  };
  union {
    volatile uint32_t AREA5;
    stc_exbus_area_field_t AREA5_f;
  };
  union {
    volatile uint32_t AREA6;
    stc_exbus_area_field_t AREA6_f;
  };
  union {
    volatile uint32_t AREA7;
    stc_exbus_area_field_t AREA7_f;
  };
  union {
    volatile uint32_t ATIM0;
	stc_exbus_atim_field_t ATIM0_f;
  };
  union {
    volatile uint32_t ATIM1;
	stc_exbus_atim_field_t ATIM1_f;
  };
  union {
    volatile uint32_t ATIM2;
	stc_exbus_atim_field_t ATIM2_f;
  }; 
  union {
    volatile uint32_t ATIM3;
	stc_exbus_atim_field_t ATIM3_f;
  };
  union {
    volatile uint32_t ATIM4;
	stc_exbus_atim_field_t ATIM4_f;
  };
  union {
    volatile uint32_t ATIM5;
	stc_exbus_atim_field_t ATIM5_f;
  };
  union {
    volatile uint32_t ATIM6;
	stc_exbus_atim_field_t ATIM6_f;
  };
  union {
    volatile uint32_t ATIM7;
	stc_exbus_atim_field_t ATIM7_f;
  };
	uint8_t RESERVED1[128];
  union {
    volatile uint32_t SDMODE;
	stc_exbus_sdmode_field_t SDMODE_f;
  };
  union {
    volatile uint32_t REFTIM;
	stc_exbus_reftim_field_t REFTIM_f;
  };
  union {
    volatile uint32_t PWRDWN;
	stc_exbus_pwrdwn_field_t PWRDWN_f;
  };
  union {
    volatile uint32_t SDTIM;
	stc_exbus_sdtim_field_t SDTIM_f;
  };
  union {
    volatile uint32_t SDCMD;
	stc_exbus_sdcmd_field_t SDCMD_f;
  };
	uint8_t RESERVED2[236];
  union {
    volatile uint32_t MEMCERR;
	stc_exbus_memcerr_field_t MEMCERR_f;
  };
	uint8_t RESERVED3[252];
  union {
    volatile uint32_t DCLKR;
	stc_exbus_dclkr_field_t DCLKR_f;
  };
  union {
    volatile uint32_t EST;
	stc_exbus_est_field_t EST_f;
  };
  union {
    volatile uint32_t WEAD;
	stc_exbus_wead_field_t WEAD_f;
  };
  union {
    volatile uint32_t ESCLR;
	stc_exbus_esclr_field_t ESCLR_f;
  };
  union {
    volatile uint32_t AMODE;
	stc_exbus_amode_field_t AMODE_f;
  };
}FM4_EXBUS_TypeDef;



 
 
typedef struct
{
  union {
    union {
      volatile uint16_t HCNT;
      stc_usb_hcnt_field_t HCNT_f;
    };
    struct {
      union {
        volatile  uint8_t HCNT0;
        stc_usb_hcnt0_field_t HCNT0_f;
      };
      union {
        volatile  uint8_t HCNT1;
        stc_usb_hcnt1_field_t HCNT1_f;
      };
    };
  };
        uint8_t RESERVED0[2];
  union {
    volatile  uint8_t HIRQ;
    stc_usb_hirq_field_t HIRQ_f;
  };
  union {
    volatile  uint8_t HERR;
    stc_usb_herr_field_t HERR_f;
  };
        uint8_t RESERVED1[2];
  union {
    volatile  uint8_t HSTATE;
    stc_usb_hstate_field_t HSTATE_f;
  };
  union {
    volatile  uint8_t HFCOMP;
    stc_usb_hfcomp_field_t HFCOMP_f;
  };
        uint8_t RESERVED2[2];
  union {
    union {
      volatile uint16_t HRTIMER;
      stc_usb_hrtimer_field_t HRTIMER_f;
    };
    struct {
      union {
        volatile  uint8_t HRTIMER0;
        stc_usb_hrtimer0_field_t HRTIMER0_f;
      };
      union {
        volatile  uint8_t HRTIMER1;
        stc_usb_hrtimer1_field_t HRTIMER1_f;
      };
    };
  };
        uint8_t RESERVED3[2];
  union {
    volatile  uint8_t HRTIMER2;
    stc_usb_hrtimer2_field_t HRTIMER2_f;
  };
  union {
    volatile  uint8_t HADR;
    stc_usb_hadr_field_t HADR_f;
  };
        uint8_t RESERVED4[2];
  union {
    union {
      volatile uint16_t HEOF;
      stc_usb_heof_field_t HEOF_f;
    };
    struct {
      union {
        volatile  uint8_t HEOF0;
        stc_usb_heof0_field_t HEOF0_f;
      };
      union {
        volatile  uint8_t HEOF1;
        stc_usb_heof1_field_t HEOF1_f;
      };
    };
  };
        uint8_t RESERVED5[2];
  union {
    union {
      volatile uint16_t HFRAME;
      stc_usb_hframe_field_t HFRAME_f;
    };
    struct {
      union {
        volatile  uint8_t HFRAME0;
        stc_usb_hframe0_field_t HFRAME0_f;
      };
      union {
        volatile  uint8_t HFRAME1;
        stc_usb_hframe1_field_t HFRAME1_f;
      };
    };
  };
        uint8_t RESERVED6[2];
  union {
    volatile  uint8_t HTOKEN;
    stc_usb_htoken_field_t HTOKEN_f;
  };
        uint8_t RESERVED7[3];
  union {
    volatile uint16_t UDCC;
    stc_usb_udcc_field_t UDCC_f;
  };
        uint8_t RESERVED8[2];
  union {
    volatile uint16_t EP0C;
    stc_usb_ep0c_field_t EP0C_f;
  };
        uint8_t RESERVED9[2];
  union {
    volatile uint16_t EP1C;
    stc_usb_ep1c_field_t EP1C_f;
  };
        uint8_t RESERVED10[2];
  union {
    volatile uint16_t EP2C;
    stc_usb_ep2c_field_t EP2C_f;
  };
        uint8_t RESERVED11[2];
  union {
    volatile uint16_t EP3C;
    stc_usb_ep3c_field_t EP3C_f;
  };
        uint8_t RESERVED12[2];
  union {
    volatile uint16_t EP4C;
    stc_usb_ep4c_field_t EP4C_f;
  };
        uint8_t RESERVED13[2];
  union {
    volatile uint16_t EP5C;
    stc_usb_ep5c_field_t EP5C_f;
  };
        uint8_t RESERVED14[2];
  union {
    volatile uint16_t TMSP;
    stc_usb_tmsp_field_t TMSP_f;
  };
        uint8_t RESERVED15[2];
  union {
    volatile  uint8_t UDCS;
    stc_usb_udcs_field_t UDCS_f;
  };
  union {
    volatile  uint8_t UDCIE;
    stc_usb_udcie_field_t UDCIE_f;
  };
        uint8_t RESERVED16[2];
  union {
    volatile uint16_t EP0IS;
    stc_usb_ep0is_field_t EP0IS_f;
  };
        uint8_t RESERVED17[2];
  union {
    volatile uint16_t EP0OS;
    stc_usb_ep0os_field_t EP0OS_f;
  };
        uint8_t RESERVED18[2];
  union {
    volatile uint16_t EP1S;
    stc_usb_ep1s_field_t EP1S_f;
  };
        uint8_t RESERVED19[2];
  union {
    volatile uint16_t EP2S;
    stc_usb_ep2s_field_t EP2S_f;
  };
        uint8_t RESERVED20[2];
  volatile uint16_t EP3S;
        uint8_t RESERVED21[2];
  union {
    volatile uint16_t EP4S;
    stc_usb_ep4s_field_t EP4S_f;
  };
        uint8_t RESERVED22[2];
  union {
    volatile uint16_t EP5S;
    stc_usb_ep5s_field_t EP5S_f;
  };
        uint8_t RESERVED23[2];
  union {
    volatile uint16_t EP0DT;
    struct {
      volatile  uint8_t EP0DTL;
      volatile  uint8_t EP0DTH;
    };
  };
        uint8_t RESERVED24[2];
  union {
    volatile uint16_t EP1DT;
    struct {
      volatile  uint8_t EP1DTL;
      volatile  uint8_t EP1DTH;
    };
  };
        uint8_t RESERVED25[2];
  union {
    volatile uint16_t EP2DT;
    struct {
      volatile  uint8_t EP2DTL;
      volatile  uint8_t EP2DTH;
    };
  };
        uint8_t RESERVED26[2];
  union {
    volatile uint16_t EP3DT;
    struct {
      volatile  uint8_t EP3DTL;
      volatile  uint8_t EP3DTH;
    };
  };
        uint8_t RESERVED27[2];
  union {
    volatile uint16_t EP4DT;
    struct {
      volatile  uint8_t EP4DTL;
      volatile  uint8_t EP4DTH;
    };
  };
        uint8_t RESERVED28[2];
  union {
    volatile uint16_t EP5DT;
    struct {
      volatile  uint8_t EP5DTL;
      volatile  uint8_t EP5DTH;
    };
  };
}FM4_USB_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t DMACR;
    stc_dmac_dmacr_field_t DMACR_f;
  };
        uint8_t RESERVED0[12];
  union {
    volatile uint32_t DMACA0;
    stc_dmac_dmaca0_field_t DMACA0_f;
  };
  union {
    volatile uint32_t DMACB0;
    stc_dmac_dmacb0_field_t DMACB0_f;
  };
  volatile uint32_t DMACSA0;
  volatile uint32_t DMACDA0;
  union {
    volatile uint32_t DMACA1;
    stc_dmac_dmaca1_field_t DMACA1_f;
  };
  union {
    volatile uint32_t DMACB1;
    stc_dmac_dmacb1_field_t DMACB1_f;
  };
  volatile uint32_t DMACSA1;
  volatile uint32_t DMACDA1;
  union {
    volatile uint32_t DMACA2;
    stc_dmac_dmaca2_field_t DMACA2_f;
  };
  union {
    volatile uint32_t DMACB2;
    stc_dmac_dmacb2_field_t DMACB2_f;
  };
  volatile uint32_t DMACSA2;
  volatile uint32_t DMACDA2;
  union {
    volatile uint32_t DMACA3;
    stc_dmac_dmaca3_field_t DMACA3_f;
  };
  union {
    volatile uint32_t DMACB3;
    stc_dmac_dmacb3_field_t DMACB3_f;
  };
  volatile uint32_t DMACSA3;
  volatile uint32_t DMACDA3;
  union {
    volatile uint32_t DMACA4;
    stc_dmac_dmaca4_field_t DMACA4_f;
  };
  union {
    volatile uint32_t DMACB4;
    stc_dmac_dmacb4_field_t DMACB4_f;
  };
  volatile uint32_t DMACSA4;
  volatile uint32_t DMACDA4;
  union {
    volatile uint32_t DMACA5;
    stc_dmac_dmaca5_field_t DMACA5_f;
  };
  union {
    volatile uint32_t DMACB5;
    stc_dmac_dmacb5_field_t DMACB5_f;
  };
  volatile uint32_t DMACSA5;
  volatile uint32_t DMACDA5;
  union {
    volatile uint32_t DMACA6;
    stc_dmac_dmaca6_field_t DMACA6_f;
  };
  union {
    volatile uint32_t DMACB6;
    stc_dmac_dmacb6_field_t DMACB6_f;
  };
  volatile uint32_t DMACSA6;
  volatile uint32_t DMACDA6;
  union {
    volatile uint32_t DMACA7;
    stc_dmac_dmaca7_field_t DMACA7_f;
  };
  union {
    volatile uint32_t DMACB7;
    stc_dmac_dmacb7_field_t DMACB7_f;
  };
  volatile uint32_t DMACSA7;
  volatile uint32_t DMACDA7;
}FM4_DMAC_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint16_t CTRLR;
    stc_can_ctrlr_field_t CTRLR_f;
  };
  union {
    volatile uint16_t STATR;
    stc_can_statr_field_t STATR_f;
  };
  union {
    volatile uint16_t ERRCNT;
    stc_can_errcnt_field_t ERRCNT_f;
  };
  union {
    volatile uint16_t BTR;
    stc_can_btr_field_t BTR_f;
  };
  union {
    volatile uint16_t INTR;
    stc_can_intr_field_t INTR_f;
  };
  union {
    volatile uint16_t TESTR;
    stc_can_testr_field_t TESTR_f;
  };
  union {
    volatile uint16_t BRPER;
    stc_can_brper_field_t BRPER_f;
  };
        uint8_t RESERVED0[2];
  union {
    volatile uint16_t IF1CREQ;
    stc_can_if1creq_field_t IF1CREQ_f;
  };
  union {
    volatile uint16_t IF1CMSK;
    stc_can_if1cmsk_field_t IF1CMSK_f;
  };
  union {
    union {
      volatile uint32_t IF1MSK;
      stc_can_if1msk_field_t IF1MSK_f;
    };
    struct {
      volatile uint16_t IF1MSK1;
      union {
        volatile uint16_t IF1MSK2;
        stc_can_if1msk2_field_t IF1MSK2_f;
      };
    };
  };
  union {
    union {
      volatile uint32_t IF1ARB;
      stc_can_if1arb_field_t IF1ARB_f;
    };
    struct {
      volatile uint16_t IF1ARB1;
      union {
        volatile uint16_t IF1ARB2;
        stc_can_if1arb2_field_t IF1ARB2_f;
      };
    };
  };
  union {
    volatile uint16_t IF1MCTR;
    stc_can_if1mctr_field_t IF1MCTR_f;
  };
        uint8_t RESERVED1[2];
  union {
    volatile uint32_t IF1DTA_L;
    struct {
      volatile uint16_t IF1DTA1_L;
      volatile uint16_t IF1DTA2_L;
    };
  };
  union {
    volatile uint32_t IF1DTB_L;
    struct {
      volatile uint16_t IF1DTB1_L;
      volatile uint16_t IF1DTB2_L;
    };
  };
        uint8_t RESERVED2[8];
  union {
    volatile uint32_t IF1DTA_B;
    struct {
      volatile uint16_t IF1DTA2_B;
      volatile uint16_t IF1DTA1_B;
    };
  };
  union {
    volatile uint32_t IF1DTB_B;
    struct {
      volatile uint16_t IF1DTB2_B;
      volatile uint16_t IF1DTB1_B;
    };
  };
        uint8_t RESERVED3[8];
  union {
    volatile uint16_t IF2CREQ;
    stc_can_if2creq_field_t IF2CREQ_f;
  };
  union {
    volatile uint16_t IF2CMSK;
    stc_can_if2cmsk_field_t IF2CMSK_f;
  };
  union {
    union {
      volatile uint32_t IF2MSK;
      stc_can_if2msk_field_t IF2MSK_f;
    };
    struct {
      volatile uint16_t IF2MSK1;
      union {
        volatile uint16_t IF2MSK2;
        stc_can_if2msk2_field_t IF2MSK2_f;
      };
    };
  };
  union {
    volatile uint32_t IF2ARB;
    struct {
      volatile uint16_t IF2ARB1;
      union {
        volatile uint16_t IF2ARB2;
        stc_can_if2arb2_field_t IF2ARB2_f;
      };
    };
  };
  union {
    volatile uint16_t IF2MCTR;
    stc_can_if2mctr_field_t IF2MCTR_f;
  };
        uint8_t RESERVED4[2];
  union {
    volatile uint32_t IF2DTA_L;
    struct {
      volatile uint16_t IF2DTA1_L;
      volatile uint16_t IF2DTA2_L;
    };
  };
  union {
    volatile uint32_t IF2DTB_L;
    struct {
      volatile uint16_t IF2DTB1_L;
      volatile uint16_t IF2DTB2_L;
    };
  };
        uint8_t RESERVED5[8];
  union {
    volatile uint32_t IF2DTA_B;
    struct {
      volatile uint16_t IF2DTA2_B;
      volatile uint16_t IF2DTA1_B;
    };
  };
  union {
    volatile uint32_t IF2DTB_B;
    struct {
      volatile uint16_t IF2DTB2_B;
      volatile uint16_t IF2DTB1_B;
    };
  };
        uint8_t RESERVED6[24];
  union {
    union {
      volatile uint32_t TREQR;
      stc_can_treqr_field_t TREQR_f;
    };
    struct {
      union {
        volatile uint16_t TREQR1;
        stc_can_treqr1_field_t TREQR1_f;
      };
      union {
        volatile uint16_t TREQR2;
        stc_can_treqr2_field_t TREQR2_f;
      };
    };
  };
        uint8_t RESERVED7[12];
  union {
    union {
      volatile uint32_t NEWDT;
      stc_can_newdt_field_t NEWDT_f;
    };
    struct {
      union {
        volatile uint16_t NEWDT1;
        stc_can_newdt1_field_t NEWDT1_f;
      };
      volatile uint16_t NEWDT2;
    };
  };
        uint8_t RESERVED8[12];
  union {
    union {
      volatile uint32_t INTPND;
      stc_can_intpnd_field_t INTPND_f;
    };
    struct {
      union {
        volatile uint16_t INTPND1;
        stc_can_intpnd1_field_t INTPND1_f;
      };
      union {
        volatile uint16_t INTPND2;
        stc_can_intpnd2_field_t INTPND2_f;
      };
    };
  };
        uint8_t RESERVED9[12];
  union {
    union {
      volatile uint32_t MSGVAL;
      stc_can_msgval_field_t MSGVAL_f;
    };
    struct {
      union {
        volatile uint16_t MSGVAL1;
        stc_can_msgval1_field_t MSGVAL1_f;
      };
      union {
        volatile uint16_t MSGVAL2;
        stc_can_msgval2_field_t MSGVAL2_f;
      };
    };
  };
}FM4_CAN_TypeDef;



 
 
typedef struct
{
  union {
    volatile uint32_t SSA2;
    struct {
      volatile  uint16_t SSALA2;
      volatile  uint16_t SSAHA2;
    };
  };
  union {
    volatile  uint16_t SBSIZE;
    stc_sdif_sbsize_field_t SBSIZE_f;
  };
    volatile  uint16_t SBLCNT;
  union {
    volatile uint32_t SSA1;
    struct {
      volatile  uint16_t SSALA1;
      volatile  uint16_t SSAHA1;
    };
  };
  union {
    volatile  uint16_t STRSFMD;
    stc_sdif_strsfmd_field_t STRSFMD_f;
  };
  union {
    volatile  uint16_t SCMMD;
    stc_sdif_scmmd_field_t SCMMD_f;
  };
    volatile  uint16_t SRESP0;
    volatile  uint16_t SRESP1;
    volatile  uint16_t SRESP2;
    volatile  uint16_t SRESP3;
    volatile  uint16_t SRESP4;
    volatile  uint16_t SRESP5;
    volatile  uint16_t SRESP6;
    volatile  uint16_t SRESP7;
  union {
    volatile uint32_t SBUFDP;
    struct {
      volatile  uint16_t SBUFDP0;
      volatile  uint16_t SBUFDP1;
    };
  };
  union {
    volatile  uint32_t SPRSTAT;
    stc_sdif_sprstat_field_t SPRSTAT_f;
  };
  union {
    volatile  uint8_t SHCTL1;
    stc_sdif_shctl1_field_t SHCTL1_f;
  };
  union {
    volatile  uint8_t SPWRCTL;
    stc_sdif_spwrctl_field_t SPWRCTL_f;
  };
  union {
    volatile  uint8_t SBLKGPCTL;
    stc_sdif_sblkgpctl_field_t SBLKGPCTL_f;
  };
  union {
    volatile  uint8_t SWKUPCTL;
    stc_sdif_swkupctl_field_t SWKUPCTL_f;
  };
  union {
    volatile  uint16_t SCLKCTL;
    stc_sdif_sclkctl_field_t SCLKCTL_f;
  };
  union {
    volatile  uint8_t STOCTL;
    stc_sdif_stoctl_field_t STOCTL_f;
  };
  union {
    volatile  uint8_t SSRST;
    stc_sdif_ssrst_field_t SSRST_f;
  };
  union {
    volatile  uint16_t SNINTST;
    stc_sdif_snintst_field_t SNINTST_f;
  };
  union {
    volatile  uint16_t SEINTST;
    stc_sdif_seintst_field_t SEINTST_f;
  };
  union {
    volatile  uint16_t SNINTSTE;
    stc_sdif_snintste_field_t SNINTSTE_f;
  };
  union {
    volatile  uint16_t SEINTSTE;
    stc_sdif_seintste_field_t SEINTSTE_f;
  };
  union {
    volatile  uint16_t SNINTSGE;
    stc_sdif_snintsge_field_t SNINTSGE_f;
  };
  union {
    volatile  uint16_t SEINTSGE;
    stc_sdif_seintsge_field_t SEINTSGE_f;
  };
  union {
    volatile  uint16_t SACMDEST;
    stc_sdif_sacmdest_field_t SACMDEST_f;
  };
  union {
    volatile  uint16_t SHCTL2;
    stc_sdif_shctl2_field_t SHCTL2_f;
  };
  union {
    volatile  uint16_t CAPBLTY0;
    stc_sdif_capblty0_field_t CAPBLTY0_f;
  };
  union {
    volatile  uint16_t CAPBLTY1;
    stc_sdif_capblty1_field_t CAPBLTY1_f;
  };
  union {
    volatile  uint16_t CAPBLTY2;
    stc_sdif_capblty2_field_t CAPBLTY2_f;
  };
  union {
    volatile  uint16_t CAPBLTY3;
    stc_sdif_capblty3_field_t CAPBLTY3_f;
  };
  union {
    volatile  uint16_t MXCCAPY0;
    stc_sdif_mxccapy0_field_t MXCCAPY0_f;
  };
  union {
    volatile  uint16_t MXCCAPY1;
    stc_sdif_mxccapy1_field_t MXCCAPY1_f;
  };
  union {
    volatile  uint16_t MXCCAPY2;
    stc_sdif_mxccapy2_field_t MXCCAPY2_f;
  };
  union {
    volatile  uint16_t MXCCAPY3;
    stc_sdif_mxccapy3_field_t MXCCAPY3_f;
  };
  union {
    volatile  uint16_t FEACEST;
    stc_sdif_feacest_field_t FEACEST_f;
  };
  union {
    volatile  uint16_t SFEEIST;
    stc_sdif_sfeeist_field_t SFEEIST_f;
  };
  union {
    volatile  uint8_t ADMAEST;
    stc_sdif_admaest_field_t ADMAEST_f;
  };
        uint8_t RESERVED0[3];
  union {
    volatile  uint16_t SADSA0;
    stc_sdif_sadsa0_field_t SADSA0_f;
  };
  union {
    volatile  uint16_t SADSA1;
    stc_sdif_sadsa1_field_t SADSA1_f;
  };
  union {
    volatile  uint16_t SADSA2;
    stc_sdif_sadsa2_field_t SADSA2_f;
  };
  union {
    volatile  uint16_t SADSA3;
    stc_sdif_sadsa3_field_t SADSA3_f;
  };
  union {
    volatile  uint16_t SPRVAL0;
    stc_sdif_sprval0_field_t SPRVAL0_f;
  };
  union {
    volatile  uint16_t SPRVAL1;
    stc_sdif_sprval1_field_t SPRVAL1_f;
  };
  union {
    volatile  uint16_t SPRVAL2;
    stc_sdif_sprval2_field_t SPRVAL2_f;
  };
  union {
    volatile  uint16_t SPRVAL3;
    stc_sdif_sprval3_field_t SPRVAL3_f;
  };
  union {
    volatile  uint16_t SPRVAL4;
    stc_sdif_sprval4_field_t SPRVAL4_f;
  };
  union {
    volatile  uint16_t SPRVAL5;
    stc_sdif_sprval5_field_t SPRVAL5_f;
  };
  union {
    volatile  uint16_t SPRVAL6;
    stc_sdif_sprval6_field_t SPRVAL6_f;
  };
  union {
    volatile  uint16_t SPRVAL7;
    stc_sdif_sprval7_field_t SPRVAL7_f;
  };
        uint8_t RESERVED1[112];
  union {
    volatile  uint16_t SSHBCTLL;
    stc_sdif_sshbctll_field_t SSHBCTLL_f;
  };
  union {
    volatile  uint16_t SSHBCTLH;
    stc_sdif_sshbctlh_field_t SSHBCTLH_f;
  };
        uint8_t RESERVED2[24];
  union {
    volatile  uint16_t SSLIST;
    stc_sdif_sslist_field_t SSLIST_f;
  };
  union {
    volatile  uint16_t SHCTLV;
    stc_sdif_shctlv_field_t SHCTLV_f;
  };
  union {
    volatile  uint16_t AHBCFGL;
    stc_sdif_ahbcfgl_field_t AHBCFGL_f;
  };
  union {
    volatile  uint16_t AHBCFGH;
    stc_sdif_ahbcfgh_field_t AHBCFGH_f;
  };
  union {
    volatile  uint16_t SPWSWCL;
    stc_sdif_spwswcl_field_t SPWSWCL_f;
  };
  union {
    volatile  uint16_t SPWSWCH;
    stc_sdif_spwswch_field_t SPWSWCH_f;
  };
  union {
    volatile  uint16_t STUNSETL;
    stc_sdif_stunsetl_field_t STUNSETL_f;
  };
  union {
    volatile  uint16_t STUNSETH;
    stc_sdif_stunseth_field_t STUNSETH_f;
  };
  union {
    volatile  uint16_t STUNSTL;
    stc_sdif_stunstl_field_t STUNSTL_f;
  };
  union {
    volatile  uint16_t STUNSTH;
    stc_sdif_stunsth_field_t STUNSTH_f;
  };
        uint8_t RESERVED3[4];
  volatile  uint16_t SIOCTL2L;
  volatile  uint16_t SIOCTL2H;
  union {
    volatile  uint16_t PSWISTL;
    stc_sdif_pswistl_field_t PSWISTL_f;
  };
  union {
    volatile  uint16_t PSWISTH;
    stc_sdif_pswisth_field_t PSWISTH_f;
  };
  union {
    volatile  uint16_t PSWISTEL;
    stc_sdif_pswistel_field_t PSWISTEL_f;
  };
  union {
    volatile  uint16_t PSWISTEH;
    stc_sdif_pswisteh_field_t PSWISTEH_f;
  };
  union {
    volatile  uint16_t PSWISGEL;
    stc_sdif_pswisgel_field_t PSWISGEL_f;
  };
  union {
    volatile  uint16_t PSWISGEH;
    stc_sdif_pswisgeh_field_t PSWISGEH_f;
  };
  union {
    volatile  uint16_t MMCSDCL;
    stc_sdif_mmcsdcl_field_t MMCSDCL_f;
  };
  union {
    volatile  uint16_t MMCSDCH;
    stc_sdif_mmcsdch_field_t MMCSDCH_f;
  };
  union {
    volatile  uint16_t MCWIRQC0;
    stc_sdif_mcwirqc0_field_t MCWIRQC0_f;
  };
  union {
    volatile  uint16_t MCWIRQC1;
    stc_sdif_mcwirqc1_field_t MCWIRQC1_f;
  };
  union {
    volatile  uint16_t MCWIRQC2;
    stc_sdif_mcwirqc2_field_t MCWIRQC2_f;
  };
  union {
    volatile  uint16_t MCWIRQC3;
    stc_sdif_mcwirqc3_field_t MCWIRQC3_f;
  };
  union {
    volatile  uint16_t MCRPCKBL;
    stc_sdif_mcrpckbl_field_t MCRPCKBL_f;
  };
  union {
    volatile  uint16_t MCRPCKBH;
    stc_sdif_mcrpckbh_field_t MCRPCKBH_f;
  };
        uint8_t RESERVED4[32];
  union {
    volatile  uint16_t SCDETECS;
    stc_sdif_scdetecs_field_t SCDETECS_f;
  };
        uint8_t RESERVED5[2];
}FM4_SDIF_TypeDef;



 





#line 13717 ".\\common\\mb9abxxx.h"


 
#line 13864 ".\\common\\mb9abxxx.h"


 

 
#line 13875 ".\\common\\mb9abxxx.h"

 
#line 13913 ".\\common\\mb9abxxx.h"

 
#line 13956 ".\\common\\mb9abxxx.h"

 
#line 13981 ".\\common\\mb9abxxx.h"

 
#line 14066 ".\\common\\mb9abxxx.h"

 




 
#line 14080 ".\\common\\mb9abxxx.h"

 
#line 14100 ".\\common\\mb9abxxx.h"

 
#line 14159 ".\\common\\mb9abxxx.h"

 
#line 14221 ".\\common\\mb9abxxx.h"

 
#line 14277 ".\\common\\mb9abxxx.h"

 
#line 14315 ".\\common\\mb9abxxx.h"

 
#line 14353 ".\\common\\mb9abxxx.h"

 
#line 14412 ".\\common\\mb9abxxx.h"

 
#line 14474 ".\\common\\mb9abxxx.h"

 
#line 14530 ".\\common\\mb9abxxx.h"

 
#line 14568 ".\\common\\mb9abxxx.h"

 
#line 14606 ".\\common\\mb9abxxx.h"

 
#line 14665 ".\\common\\mb9abxxx.h"

 
#line 14727 ".\\common\\mb9abxxx.h"

 
#line 14783 ".\\common\\mb9abxxx.h"

 
#line 14821 ".\\common\\mb9abxxx.h"

 
#line 14859 ".\\common\\mb9abxxx.h"

 
#line 15101 ".\\common\\mb9abxxx.h"

 
#line 15122 ".\\common\\mb9abxxx.h"

 
#line 15145 ".\\common\\mb9abxxx.h"

 
#line 15165 ".\\common\\mb9abxxx.h"

 
#line 15185 ".\\common\\mb9abxxx.h"

 
#line 15206 ".\\common\\mb9abxxx.h"

 
#line 15229 ".\\common\\mb9abxxx.h"

 
#line 15249 ".\\common\\mb9abxxx.h"

 
#line 15269 ".\\common\\mb9abxxx.h"

 
#line 15290 ".\\common\\mb9abxxx.h"

 
#line 15313 ".\\common\\mb9abxxx.h"

 
#line 15333 ".\\common\\mb9abxxx.h"

 
#line 15353 ".\\common\\mb9abxxx.h"

 
#line 15374 ".\\common\\mb9abxxx.h"

 
#line 15397 ".\\common\\mb9abxxx.h"

 
#line 15417 ".\\common\\mb9abxxx.h"

 
#line 15437 ".\\common\\mb9abxxx.h"

 
#line 15458 ".\\common\\mb9abxxx.h"

 
#line 15481 ".\\common\\mb9abxxx.h"

 
#line 15501 ".\\common\\mb9abxxx.h"

 
#line 15521 ".\\common\\mb9abxxx.h"

 
#line 15542 ".\\common\\mb9abxxx.h"

 
#line 15565 ".\\common\\mb9abxxx.h"

 
#line 15585 ".\\common\\mb9abxxx.h"

 
#line 15605 ".\\common\\mb9abxxx.h"

 
#line 15626 ".\\common\\mb9abxxx.h"

 
#line 15649 ".\\common\\mb9abxxx.h"

 
#line 15669 ".\\common\\mb9abxxx.h"

 
#line 15689 ".\\common\\mb9abxxx.h"

 
#line 15710 ".\\common\\mb9abxxx.h"

 
#line 15733 ".\\common\\mb9abxxx.h"

 
#line 15753 ".\\common\\mb9abxxx.h"

 
#line 15773 ".\\common\\mb9abxxx.h"

 
#line 15783 ".\\common\\mb9abxxx.h"

 
#line 15793 ".\\common\\mb9abxxx.h"

 
#line 15811 ".\\common\\mb9abxxx.h"

 
#line 15831 ".\\common\\mb9abxxx.h"

 
#line 15848 ".\\common\\mb9abxxx.h"

 
#line 15865 ".\\common\\mb9abxxx.h"

 
#line 15883 ".\\common\\mb9abxxx.h"

 
#line 15903 ".\\common\\mb9abxxx.h"

 
#line 15920 ".\\common\\mb9abxxx.h"

 
#line 15937 ".\\common\\mb9abxxx.h"

 
#line 15955 ".\\common\\mb9abxxx.h"

 
#line 15975 ".\\common\\mb9abxxx.h"

 
#line 15992 ".\\common\\mb9abxxx.h"

 
#line 16009 ".\\common\\mb9abxxx.h"

 
#line 16027 ".\\common\\mb9abxxx.h"

 
#line 16047 ".\\common\\mb9abxxx.h"

 
#line 16064 ".\\common\\mb9abxxx.h"

 
#line 16081 ".\\common\\mb9abxxx.h"

 
#line 16099 ".\\common\\mb9abxxx.h"

 
#line 16119 ".\\common\\mb9abxxx.h"

 
#line 16136 ".\\common\\mb9abxxx.h"

 
#line 16153 ".\\common\\mb9abxxx.h"

 
#line 16171 ".\\common\\mb9abxxx.h"

 
#line 16191 ".\\common\\mb9abxxx.h"

 
#line 16208 ".\\common\\mb9abxxx.h"

 
#line 16225 ".\\common\\mb9abxxx.h"

 
#line 16243 ".\\common\\mb9abxxx.h"

 
#line 16263 ".\\common\\mb9abxxx.h"

 
#line 16280 ".\\common\\mb9abxxx.h"

 
#line 16297 ".\\common\\mb9abxxx.h"

 
#line 16315 ".\\common\\mb9abxxx.h"

 
#line 16335 ".\\common\\mb9abxxx.h"

 
#line 16352 ".\\common\\mb9abxxx.h"

 
#line 16369 ".\\common\\mb9abxxx.h"

 
#line 16379 ".\\common\\mb9abxxx.h"

 
#line 16389 ".\\common\\mb9abxxx.h"

 
#line 16407 ".\\common\\mb9abxxx.h"

 
#line 16472 ".\\common\\mb9abxxx.h"

 
#line 16537 ".\\common\\mb9abxxx.h"

 
#line 16602 ".\\common\\mb9abxxx.h"

 
#line 16637 ".\\common\\mb9abxxx.h"

 
#line 16645 ".\\common\\mb9abxxx.h"

 
#line 16653 ".\\common\\mb9abxxx.h"

 
#line 16661 ".\\common\\mb9abxxx.h"

 
#line 16669 ".\\common\\mb9abxxx.h"

 
#line 16987 ".\\common\\mb9abxxx.h"

 
#line 17305 ".\\common\\mb9abxxx.h"

 
#line 17623 ".\\common\\mb9abxxx.h"

 
#line 17675 ".\\common\\mb9abxxx.h"

 
#line 17839 ".\\common\\mb9abxxx.h"

 
#line 18344 ".\\common\\mb9abxxx.h"

 
#line 19502 ".\\common\\mb9abxxx.h"

 
#line 19512 ".\\common\\mb9abxxx.h"

 
#line 19540 ".\\common\\mb9abxxx.h"

 
#line 19564 ".\\common\\mb9abxxx.h"

 





 
#line 19660 ".\\common\\mb9abxxx.h"

 
#line 19828 ".\\common\\mb9abxxx.h"

 
#line 19915 ".\\common\\mb9abxxx.h"

 
#line 20019 ".\\common\\mb9abxxx.h"

 
#line 20109 ".\\common\\mb9abxxx.h"

 
#line 20277 ".\\common\\mb9abxxx.h"

 
#line 20364 ".\\common\\mb9abxxx.h"

 
#line 20468 ".\\common\\mb9abxxx.h"

 
#line 20558 ".\\common\\mb9abxxx.h"

 
#line 20726 ".\\common\\mb9abxxx.h"

 
#line 20813 ".\\common\\mb9abxxx.h"

 
#line 20917 ".\\common\\mb9abxxx.h"

 
#line 21007 ".\\common\\mb9abxxx.h"

 
#line 21175 ".\\common\\mb9abxxx.h"

 
#line 21262 ".\\common\\mb9abxxx.h"

 
#line 21366 ".\\common\\mb9abxxx.h"

 
#line 21456 ".\\common\\mb9abxxx.h"

 
#line 21624 ".\\common\\mb9abxxx.h"

 
#line 21711 ".\\common\\mb9abxxx.h"

 
#line 21815 ".\\common\\mb9abxxx.h"

 
#line 21905 ".\\common\\mb9abxxx.h"

 
#line 22073 ".\\common\\mb9abxxx.h"

 
#line 22160 ".\\common\\mb9abxxx.h"

 
#line 22264 ".\\common\\mb9abxxx.h"

 
#line 22354 ".\\common\\mb9abxxx.h"

 
#line 22522 ".\\common\\mb9abxxx.h"

 
#line 22609 ".\\common\\mb9abxxx.h"

 
#line 22713 ".\\common\\mb9abxxx.h"

 
#line 22803 ".\\common\\mb9abxxx.h"

 
#line 22971 ".\\common\\mb9abxxx.h"

 
#line 23058 ".\\common\\mb9abxxx.h"

 
#line 23162 ".\\common\\mb9abxxx.h"

 
#line 23252 ".\\common\\mb9abxxx.h"

 
#line 23420 ".\\common\\mb9abxxx.h"

 
#line 23507 ".\\common\\mb9abxxx.h"

 
#line 23611 ".\\common\\mb9abxxx.h"

 
#line 23701 ".\\common\\mb9abxxx.h"

 
#line 23869 ".\\common\\mb9abxxx.h"

 
#line 23956 ".\\common\\mb9abxxx.h"

 
#line 24060 ".\\common\\mb9abxxx.h"

 
#line 24150 ".\\common\\mb9abxxx.h"

 
#line 24318 ".\\common\\mb9abxxx.h"

 
#line 24405 ".\\common\\mb9abxxx.h"

 
#line 24509 ".\\common\\mb9abxxx.h"

 
#line 24599 ".\\common\\mb9abxxx.h"

 
#line 24767 ".\\common\\mb9abxxx.h"

 
#line 24854 ".\\common\\mb9abxxx.h"

 
#line 24958 ".\\common\\mb9abxxx.h"

 
#line 25048 ".\\common\\mb9abxxx.h"

 
#line 25216 ".\\common\\mb9abxxx.h"

 
#line 25303 ".\\common\\mb9abxxx.h"

 
#line 25407 ".\\common\\mb9abxxx.h"

 
#line 25497 ".\\common\\mb9abxxx.h"

 
#line 25665 ".\\common\\mb9abxxx.h"

 
#line 25752 ".\\common\\mb9abxxx.h"

 
#line 25856 ".\\common\\mb9abxxx.h"

 
#line 25946 ".\\common\\mb9abxxx.h"

 
#line 26114 ".\\common\\mb9abxxx.h"

 
#line 26201 ".\\common\\mb9abxxx.h"

 
#line 26305 ".\\common\\mb9abxxx.h"

 
#line 26395 ".\\common\\mb9abxxx.h"

 
#line 26563 ".\\common\\mb9abxxx.h"

 
#line 26650 ".\\common\\mb9abxxx.h"

 
#line 26754 ".\\common\\mb9abxxx.h"

 
#line 26763 ".\\common\\mb9abxxx.h"

 
#line 26787 ".\\common\\mb9abxxx.h"

 
#line 26970 ".\\common\\mb9abxxx.h"

#line 27006 ".\\common\\mb9abxxx.h"

 
#line 27014 ".\\common\\mb9abxxx.h"

 
#line 27095 ".\\common\\mb9abxxx.h"

 
#line 27362 ".\\common\\mb9abxxx.h"

 
#line 27710 ".\\common\\mb9abxxx.h"

 
#line 28071 ".\\common\\mb9abxxx.h"

 
#line 28467 ".\\common\\mb9abxxx.h"

 
#line 28863 ".\\common\\mb9abxxx.h"

 
#line 29073 ".\\common\\mb9abxxx.h"







#line 61 ".\\common\\mcu.h"






  




#line 60 ".\\common\\pdl.h"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 
extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 985 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdio.h"



 

#line 61 ".\\common\\pdl.h"

 




 
 
 


   



  
  








   
#line 97 ".\\common\\pdl.h"




 





  
#line 115 ".\\common\\pdl.h"

 
 
 
#line 1 ".\\common\\pdl_user.h"







































 
 











 



#line 1 ".\\common\\pdl_device.h"







































 

 









 









 










 



 
 
 
#line 58 ".\\common\\pdl_user.h"

 
 
 
  






 







#line 93 ".\\common\\pdl_user.h"
                                                



   


     


                                        








                                                

#line 122 ".\\common\\pdl_user.h"











#line 153 ".\\common\\pdl_user.h"



                                                






                                                


   







#line 190 ".\\common\\pdl_user.h"










                                                





                                                





                                                


                                                




























#line 251 ".\\common\\pdl_user.h"






                                                













 




                                               

#line 291 ".\\common\\pdl_user.h"
                                               



                                               


                                               


                                               


                                               

#line 314 ".\\common\\pdl_user.h"
                                               


                                               




#line 422 ".\\common\\pdl_user.h"



   


   


   




#line 452 ".\\common\\pdl_user.h"



















   



































 
 



                                        

#line 527 ".\\common\\pdl_user.h"












#line 547 ".\\common\\pdl_user.h"














#line 581 ".\\common\\pdl_user.h"





#line 618 ".\\common\\pdl_user.h"
                                        





                                        




                                        


















                                        









                                    









 

#line 676 ".\\common\\pdl_user.h"


#line 710 ".\\common\\pdl_user.h"


#line 744 ".\\common\\pdl_user.h"


#line 778 ".\\common\\pdl_user.h"


#line 837 ".\\common\\pdl_user.h"


#line 848 ".\\common\\pdl_user.h"


#line 874 ".\\common\\pdl_user.h"


#line 886 ".\\common\\pdl_user.h"













 






 

   






 


   


 





 





 




 
 
 
#line 120 ".\\common\\pdl.h"




 









 

#line 144 ".\\common\\pdl.h"









 









 



#line 173 ".\\common\\pdl.h"


#line 194 ".\\common\\pdl.h"












    















#line 1 ".\\lib\\inc\\clk.h"







































 
 









 




 
 
 
#line 1 ".\\common\\pdl.h"







































 
 








 

#line 787 ".\\common\\pdl.h"

 
 
 

#line 60 ".\\lib\\inc\\clk.h"



 




  


















































































 


 
 
 

   




#line 173 ".\\lib\\inc\\clk.h"





  


  


  


  




  




  




  


 












 
typedef enum en_clk_source
{
  ClkMain = 0,  
  ClkSub  = 1,  
  ClkHsCr = 2,  
  ClkLsCr = 3,  
  ClkPll     = 4,  
  ClkHsCrPll = 5   
} en_clk_source_t;










 
typedef enum en_clk_mode
{
  ClkRun      = 0,  
  ClkSleep    = 1,  
  ClkTimer    = 2,  
  ClkStop     = 3,  
  ClkRtc      = 4,  
  ClkDeepRtc  = 5,  
  ClkDeepStop = 6   
} en_clk_mode_t;






 
typedef enum en_clk_baseclkdiv
{
  BaseClkDiv1  = 0,  
  BaseClkDiv2  = 1,  
  BaseClkDiv3  = 2,  
  BaseClkDiv4  = 3,  
  BaseClkDiv6  = 4,  
  BaseClkDiv8  = 5,  
  BaseClkDiv16 = 6,  
  BaseClkErr   = 7   
} en_clk_baseclkdiv_t;






 
typedef enum en_clk_apb0div
{
  Apb0Div1  = 0,  
  Apb0Div2  = 1,  
  Apb0Div4  = 2,  
  Apb0Div8  = 3   
} en_clk_apb0div_t;






 
typedef enum en_clk_apb1div
{
  Apb1Div1  = 0,  
  Apb1Div2  = 1,  
  Apb1Div4  = 2,  
  Apb1Div8  = 3   
} en_clk_apb1div_t;






 
typedef enum en_clk_apb2div
{
  Apb2Div1  = 0,  
  Apb2Div2  = 1,  
  Apb2Div4  = 2,  
  Apb2Div8  = 3   
} en_clk_apb2div_t;






 
typedef enum en_clk_scowaittime
{
  ScoWaitExp10  =  0,  
  ScoWaitExp11  =  1,  
  ScoWaitExp12  =  2,  
  ScoWaitExp13  =  3,  
  ScoWaitExp14  =  4,  
  ScoWaitExp15  =  5,  
  ScoWaitExp16  =  6,  
  ScoWaitExp17  =  7,  
  ScoWaitExp18  =  8,  
  ScoWaitExp19  =  9,  
  ScoWaitExp20  = 10,  
  ScoWaitExp21  = 11,  
  ScoWaitErr    = 12   
} en_clk_scowaittime_t;






 
typedef enum en_clk_mcowaittime
{
  McoWaitExp11   = 0,   
  McoWaitExp15   = 1,   
  McoWaitExp16   = 2,   
  McoWaitExp17   = 3,   
  McoWaitExp18   = 4,   
  McoWaitExp19   = 5,   
  McoWaitExp110  = 6,   
  McoWaitExp111  = 7,   
  McoWaitExp112  = 8,   
  McoWaitExp113  = 9,   
  McoWaitExp114  = 10,  
  McoWaitExp115  = 11,  
  McoWaitExp117  = 12,  
  McoWaitExp119  = 13,  
  McoWaitExp121  = 14,  
  McoWaitExp123  = 15   
} en_clk_mcowaittime_t;






 
typedef enum en_clk_pllowaittime
{
  PlloWaitExp19   = 0,   
  PlloWaitExp110  = 1,   
  PlloWaitExp111  = 2,   
  PlloWaitExp112  = 3,   
  PlloWaitExp113  = 4,   
  PlloWaitExp114  = 5,   
  PlloWaitExp115  = 6,   
  PlloWaitExp116  = 7    
} en_clk_pllowaittime_t;










 
typedef enum en_clk_pll_src
{
  PllSrcClkMo = 0,   
  PllSrcClkHc = 123  
} en_clk_pll_src_t;




 
#line 405 ".\\lib\\inc\\clk.h"




 
typedef enum en_clk_current
{
  Clk0nA          = 0,  
  Clk135nA        = 1,  
  Clk195nA        = 2,  
  Clk385nA        = 3,  
  Clk445nA        = 4,  
  Clk510nA        = 5,  
  ClkErrorCurrent = 6   
} en_clk_current_t;




 
typedef enum en_clk_boost_time
{
  ClkBoost50ms  = 0,    
  ClkBoost63ms  = 1,    
  ClkBoost125ms = 2,    
  ClkBoost250ms = 3     
} en_clk_boost_time_t;




 
typedef enum en_clk_vbat_pins
{
  ClkVbatGpio    = 0,   
  ClkVbatOsc     = 1,   
  ClkVbatGpioOsc = 2    
} en_clk_vbat_pins_t;




 
typedef enum en_clk_vbat_pins_ddr
{
  ClkVbatInput   = 0,   
  ClkVbatOutputL = 1,   
  ClkVbatOutputH = 2    
} en_clk_vbat_pins_ddr_t;




 
typedef enum en_clk_gate_peripheral
{
  ClkGateGpio   = 0,    
  ClkGateExtif  = 1,    
  ClkGateDma    = 2,    
  ClkGateAdc0   = 3,    
  ClkGateAdc1   = 4,    
  ClkGateAdc2   = 5,    
  ClkGateAdc3   = 6,    
  ClkGateMfs0   = 7,    
  ClkGateMfs1   = 8,    
  ClkGateMfs2   = 9,    
  ClkGateMfs3   = 10,   
  ClkGateMfs4   = 11,   
  ClkGateMfs5   = 12,   
  ClkGateMfs6   = 13,   
  ClkGateMfs7   = 14,   
  ClkGateMfs8   = 15,   
  ClkGateMfs9   = 16,   
  ClkGateMfs10  = 17,   
  ClkGateMfs11  = 18,   
  ClkGateMfs12  = 19,   
  ClkGateMfs13  = 20,   
  ClkGateMfs14  = 21,   
  ClkGateMfs15  = 22,   
  ClkGateQprc0  = 23,   
  ClkGateQprc1  = 24,   
  ClkGateQprc2  = 25,   
  ClkGateQprc3  = 26,   
  ClkGateMft0   = 27,   
  ClkGateMft1   = 28,   
  ClkGateMft2   = 29,   
  ClkGateMft3   = 30,   
  ClkGateBt0    = 31,   
  ClkGateBt4    = 32,   
  ClkGateBt8    = 33,   
  ClkGateBt12   = 34,   
  ClkGateSdIf   = 35,   
  ClkGateCan0   = 36,   
  ClkGateCan1   = 37,   
  ClkGateUsb0   = 38,   
  ClkGateUsb1   = 39    
} en_clk_gate_peripheral_t;




 
typedef enum en_clk_reset_peripheral
{
  ClkResetExtif  = 1,    
  ClkResetDma    = 2,    
  ClkResetAdc0   = 3,    
  ClkResetAdc1   = 4,    
  ClkResetAdc2   = 5,    
  ClkResetAdc3   = 6,    
  ClkResetMfs0   = 7,    
  ClkResetMfs1   = 8,    
  ClkResetMfs2   = 9,    
  ClkResetMfs3   = 10,   
  ClkResetMfs4   = 11,   
  ClkResetMfs5   = 12,   
  ClkResetMfs6   = 13,   
  ClkResetMfs7   = 14,   
  ClkResetMfs8   = 15,   
  ClkResetMfs9   = 16,   
  ClkResetMfs10  = 17,   
  ClkResetMfs11  = 18,   
  ClkResetMfs12  = 19,   
  ClkResetMfs13  = 20,   
  ClkResetMfs14  = 21,   
  ClkResetMfs15  = 22,   
  ClkResetQprc0  = 23,   
  ClkResetQprc1  = 24,   
  ClkResetQprc2  = 25,   
  ClkResetQprc3  = 26,   
  ClkResetMft0   = 27,   
  ClkResetMft1   = 28,   
  ClkResetMft2   = 29,   
  ClkResetMft3   = 30,   
  ClkResetBt0    = 31,   
  ClkResetBt4    = 32,   
  ClkResetBt8    = 33,   
  ClkResetBt12   = 34,   
  ClkResetSdIf   = 35,   
  ClkResetCan0   = 36,   
  ClkResetCan1   = 37,   
  ClkResetUsb0   = 38,   
  ClkResetUsb1   = 39    
} en_clk_reset_peripheral_t;






 
typedef struct stc_clk_main_config
{
  en_clk_source_t       enSource;         
  boolean_t             bEnablePll;       
  boolean_t             bEnableMainClock; 
  en_clk_mode_t         enMode;           
  boolean_t             bLpmPortHiZState; 
                                          
                                          
  en_clk_baseclkdiv_t   enBaseClkDiv;     
  en_clk_apb0div_t      enAPB0Div;        
  en_clk_apb1div_t      enAPB1Div;        
  en_clk_apb2div_t      enAPB2Div;        
  boolean_t             bAPB1Disable;     
  boolean_t             bAPB2Disable;     
  en_clk_mcowaittime_t  enMCOWaitTime;    
  en_clk_pllowaittime_t enPLLOWaitTime;   
  uint8_t               u8PllK;           
  uint8_t               u8PllM;           
  uint8_t               u8PllN;           
  en_clk_pll_src_t      enPllSource;      
#line 583 ".\\lib\\inc\\clk.h"
  func_ptr_t            pfnHook;          
} stc_clk_main_config_t;






 
typedef struct stc_clk_sub_config
{
  boolean_t             bEnableSubClock;  
  en_clk_scowaittime_t  enSCOWaitTime;    




} stc_clk_sub_config_t;






 
typedef struct stc_clk_vbat_config
{
  boolean_t              bLinkClock;            
                                                
  uint8_t                u8VbClockDiv;          
  en_clk_current_t       enClkSustainCurrent;   
  en_clk_current_t       enClkBoostCurrent;     
  en_clk_boost_time_t    enClkBoostTime;        
  en_clk_vbat_pins_t     enVbatPins;            
  boolean_t              bVbP48Peripheral;      
  boolean_t              bVbP49Peripheral;      
  boolean_t              bVbP47Peripheral;      
  boolean_t              bVbP46Peripheral;      
  boolean_t              bVbP48PullUp;          
  boolean_t              bVbP49PullUp;          
  boolean_t              bVbP47PullUp;          
  boolean_t              bVbP46PullUp;          
  en_clk_vbat_pins_ddr_t enVbP48InOut;          
  en_clk_vbat_pins_ddr_t enVbP49InOut;          
  en_clk_vbat_pins_ddr_t enVbP47InOut;          
  en_clk_vbat_pins_ddr_t enVbP46InOut;          
  boolean_t              bVbP48OpenDrain;       
  boolean_t              bVbP49OpenDrain;       
} stc_clk_vbat_config_t;

 
 
 




 
 
 





extern en_result_t Clk_MainGetParameters(stc_clk_main_config_t* pstcConfig) ;
extern en_result_t Clk_SubGetParameters(stc_clk_sub_config_t* pstcConfig) ;
extern en_result_t Clk_VbatGetParameters(stc_clk_vbat_config_t* pstcConfig) ;

extern en_result_t Clk_SetDividers(stc_clk_main_config_t* pstcConfig) ;

extern en_result_t Clk_MainSetStabilizationWaitTime(stc_clk_main_config_t* pstcConfig) ;
extern en_result_t Clk_SubSetStabilizationWaitTime(stc_clk_sub_config_t* pstcConfig) ;

extern en_result_t Clk_WaitForMainOscillator(uint32_t u32MaxTimeOut) ;
extern en_result_t Clk_WaitForSubOscillator(uint32_t u32MaxTimeOut) ;

extern en_result_t Clk_WaitForPllOscillator(uint32_t u32MaxTimeOut) ;

extern en_result_t Clk_MainOscillatorReady(void) ;
extern en_result_t Clk_SubOscillatorReady(void) ;

extern en_result_t Clk_PllOscillatorReady(void) ;

extern en_result_t Clk_SetSource(stc_clk_main_config_t* pstcConfigMain,
                                 stc_clk_sub_config_t*  pstcConfigSub) ;

extern en_result_t Clk_SetPllSource(stc_clk_main_config_t* pstcConfig) ;

extern en_result_t Clk_SetMode(stc_clk_main_config_t* pstcConfig) ;

extern en_result_t Clk_EnableMainClock(void) ;
extern en_result_t Clk_EnablePllClock(stc_clk_main_config_t* pstcConfigMain) ;
extern en_result_t Clk_EnableSubClock(void) ;

extern en_result_t Clk_DisableMainClock(void) ;
extern en_result_t Clk_DisablePllClock(void) ;
extern en_result_t Clk_DisableSubClock(void) ;

extern en_result_t Clk_WaitForClockSourceReady(en_clk_source_t enSource,
                                        uint32_t        u32MaxTimeOut) ;

#line 691 ".\\lib\\inc\\clk.h"

extern en_result_t Clk_ClockVbatInit(stc_clk_vbat_config_t* pstcConfig) ;

extern en_result_t Clk_RequestVccPowerDown(void) ;

extern en_result_t Clk_PeripheralClockEnable(en_clk_gate_peripheral_t enPeripheral) ;

extern boolean_t Clk_PeripheralGetClockState(en_clk_gate_peripheral_t enPeripheral) ;

extern en_result_t Clk_PeripheralClockDisable(en_clk_gate_peripheral_t enPeripheral) ;

extern en_result_t Clk_PeripheralSetReset(en_clk_reset_peripheral_t enPeripheral) ;

extern en_result_t Clk_PeripheralClearReset(en_clk_reset_peripheral_t enPeripheral) ;

extern en_result_t Clk_SwitchToMainClock(void) ;

extern en_result_t Clk_SwitchToMainPllClock(void) ;

extern en_result_t Clk_SwitchToSubClock(void) ;

extern en_result_t Clk_SwitchToLsCrClock(void) ;

extern en_result_t Clk_SwitchToHsCrClock(void) ;

extern en_result_t Clk_SwitchToHsCrPllClock(void) ;











 
 
 
#line 225 ".\\common\\pdl.h"





















#line 257 ".\\common\\pdl.h"














#line 277 ".\\common\\pdl.h"


#line 1 ".\\common\\exint.h"







































 
 








 




 
 
 
#line 59 ".\\common\\exint.h"




 




  































 

  
 
 
 
#line 126 ".\\common\\exint.h"
  
#line 159 ".\\common\\exint.h"

#line 192 ".\\common\\exint.h"

 
 
 
  
typedef enum en_exint_level
{
  ExIntLowLevel     = 0,  
  ExIntHighLevel    = 1,  
  ExIntRisingEdge   = 2,  
  ExIntFallingEdge  = 3   
} en_exint_level_t;




 






 
typedef struct stc_exint_config
{
  boolean_t         abEnable[32u];           
  en_exint_level_t  aenLevel[32u];           
  func_ptr_t        apfnExintCallback[32u];  
} stc_exint_config_t;






 
typedef struct stc_exint_nmi_config
{
  boolean_t         bTouchNVIC;
  func_ptr_t        pfnNMICallback;   
} stc_exint_nmi_config_t;




 
typedef struct stc_exint_intern_data
{
  func_ptr_t    apfnExintCallback[(uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(1u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(1u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(1u == 1u) + (uint8_t)(0u == 1u) + (uint8_t)(4u*(0u == 1u)) + (uint8_t)(4u*(0u == 1u)) + (uint8_t)(4u*(0u == 1u)) + (uint8_t)(4u*(0u == 1u))];  
} stc_exint_intern_data_t ;




 
typedef struct stc_exint_nmi_intern_data
{
  func_ptr_t    pfnNMICallback;  
} stc_exint_nmi_intern_data_t ;


 
 
 
extern stc_exint_intern_data_t stcExintInternData;
extern stc_exint_nmi_intern_data_t stcExintNMIInternData;

 
 
 
 
extern void Exint_IrqHandler(uint8_t u8Channel) ;

extern void ExintNMIrqHandler(void) ;

en_result_t Exint_Init(stc_exint_config_t* pstcConfig) ;

en_result_t Exint_DeInit(void) ;

en_result_t Exint_EnableChannel(uint8_t u8Channel) ;

en_result_t Exint_DisableChannel(uint8_t u8Channel) ;

en_result_t Exint_Nmi_Init(stc_exint_nmi_config_t* pstcConfig) ;

en_result_t Exint_Nmi_DeInit(stc_exint_nmi_config_t* pstcConfig) ;
  









 
 
 
#line 301 ".\\common\\pdl.h"
















#line 1 ".\\common\\gpio.h"







































 
 









 

#line 167 ".\\common\\gpio.h"

 
 
 
#line 320 ".\\common\\pdl.h"

      





 





 







#line 1 ".\\common\\mfs.h"







































 
 








 




 
 
 
#line 59 ".\\common\\mfs.h"



 







































































































































































 




 
typedef FM4_MFS_TypeDef stc_mfsn_t;




 
typedef enum en_mfs_uart_mode
{
    MfsUartNormal = 0,          
    MfsUartMulti  = 1           
} en_mfs_uart_mode_t;




 
typedef enum en_mfs_csio_mode
{
    MfsCsioMaster = 0,          
    MfsCsioSlave  = 1           
} en_mfs_csio_mode_t;




 
typedef enum en_mfs_csio_act_mode
{
    MfsCsioActNormalMode = 0,   
    MfsCsioActSpiMode    = 1    
} en_mfs_csio_act_mode_t;




 
typedef enum en_mfs_i2c_mode
{
    MfsI2cMaster = 0,           
    MfsI2cSlave  = 1            
} en_mfs_i2c_mode_t;




 
typedef enum en_mfs_i2c_fast_mode
{
    MfsI2cDisableFastModePlus = 0,  
    MfsI2cEnableFastModePlus  = 1   
} en_mfs_i2c_fast_mode_t;




 
typedef enum en_mfs_lin_mode
{
    MfsLinMaster = 0,           
    MfsLinSlave  = 1            
} en_mfs_lin_mode_t;




 
typedef enum en_mfs_parity
{
    MfsParityNone  = 0,         
    MfsParityEven  = 2,         
    MfsParityOdd   = 3          
} en_mfs_parity_t;




 
typedef enum en_mfs_characterlength
{
    MfsFiveBits       = 0,      
    MfsSixBits        = 1,      
    MfsSevenBits      = 2,      
    MfsEightBits      = 3,      
    MfsNineBits       = 4,      
    MfsTenBits        = 5,      
    MfsElevenBits     = 6,      
    MfsTwelveBits     = 7,      
    MfsThirteenBits   = 8,      
    MfsFourteenBits   = 9,      
    MfsFifteenBits    = 10,     
    MfsSixteenBits    = 11,     
    MfsTwentyBits     = 12,     
    MfsTwentyFourBits = 13,     
    MfsThirtyTwoBits  = 14      
} en_mfs_characterlength_t;




 
typedef enum en_mfs_stopbit
{
    MfsOneStopBit    = 0,       
    MfsTwoStopBits   = 1,       
    MfsThreeStopBits = 2,       
    MfsFourStopBits  = 3        
} en_mfs_stopbit_t;




 
typedef enum en_mfs_csio_sync_wait_time
{
    MfsSyncWaitZero  = 0,           
    MfsSyncWaitOne   = 1,           
    MfsSyncWaitTwo   = 2,           
    MfsSyncWaitThree = 3            
} en_mfs_csio_sync_wait_time_t;




 
typedef enum en_mfs_i2c_noize_filter
{
    MfsI2cNoizeFilterLess40M  = 0x00,   
    MfsI2cNoizeFilterLess60M  = 0x01,   
    MfsI2cNoizeFilterLess80M  = 0x02,   
    MfsI2cNoizeFilterLess100M = 0x03,   
    MfsI2cNoizeFilterLess120M = 0x04,   
    MfsI2cNoizeFilterLess140M = 0x05,   
    MfsI2cNoizeFilterLess160M = 0x06,   
    MfsI2cNoizeFilterLess180M = 0x07,   
    MfsI2cNoizeFilterLess200M = 0x08,   
    MfsI2cNoizeFilterLess220M = 0x09,   
    MfsI2cNoizeFilterLess240M = 0x0A,   
    MfsI2cNoizeFilterLess260M = 0x0B,   
    MfsI2cNoizeFilterLess280M = 0x0C,   
    MfsI2cNoizeFilterLess300M = 0x0D,   
    MfsI2cNoizeFilterLess320M = 0x0E,   
    MfsI2cNoizeFilterLess340M = 0x0F,   
    MfsI2cNoizeFilterLess360M = 0x10,   
    MfsI2cNoizeFilterLess380M = 0x11,   
    MfsI2cNoizeFilterLess400M = 0x12    
} en_mfs_i2c_noize_filter_t;




 
typedef enum en_mfs_i2c_datadirection
{
    MfsI2cWrite = 0x00,         
    MfsI2cRead  = 0x01          
} en_mfs_i2c_datadirection_t ;




 
typedef enum en_mfs_i2c_wait_sel
{
    MfsI2cWaitSelAfterAck = 0,  
    MfsI2cWaitSelDataTxRx = 1   
} en_mfs_i2c_wait_sel_t;




 
typedef enum en_mfs_fifo_available
{
    MfsHasNoFifo = 0,               
    MfsHasFifo   = 1                
} en_mfs_fifo_available_t;




 
typedef enum en_mfs_fifo
{
    MfsFifo1 = 0,                   
    MfsFifo2 = 1                    
} en_mfs_fifo_t;




 
typedef enum en_mfs_fifo_select
{
    MfsTxFifo1RxFifo2 = 0,          
    MfsTxFifo2RxFifo1 = 1           
} en_mfs_fifo_select_t;




 
typedef enum en_mfs_lin_stop_bit_length
{
    MfsLinOneStopBit    = 0,        
    MfsLinTwoStopBits   = 1,        
    MfsLinThreeStopBits = 2,        
    MfsLinFourStopBits  = 3         
} en_mfs_lin_stop_bit_length_t;




 
typedef enum en_mfs_lin_break_length
{
    MfsLinBreakLength13 = 0,        
    MfsLinBreakLength14 = 1,        
    MfsLinBreakLength15 = 2,        
    MfsLinBreakLength16 = 3         
} en_mfs_lin_break_length_t;




 
typedef enum en_mfs_lin_delimiter_length
{
    MfsLinDelimiterLength1 = 0,     
    MfsLinDelimiterLength2 = 1,     
    MfsLinDelimiterLength3 = 2,     
    MfsLinDelimiterLength4 = 3      
} en_mfs_lin_delimiter_length_t;




 
typedef enum en_mfs_bus_clk_divider
{
    MfsClkDiv0 = 0,                 
    MfsClkDiv1 = 1,                 
    MfsClkDiv2 = 2,                 
    MfsClkDiv3 = 3                  
} en_mfs_bus_clk_divider_t;






 
 
typedef struct stc_mfs_uart_config
{
    uint32_t  u32DataRate;          
    uint8_t   u8UartMode;           
    uint8_t   u8Parity;             
    uint8_t   u8StopBit;            
    uint8_t   u8CharLength;         
    boolean_t bBitDirection;        
    boolean_t bSignalSystem;        
    boolean_t bHwFlow;              
} stc_mfs_uart_config_t;

 
typedef struct stc_mfs_csio_config
{
    uint32_t  u32DataRate;          
    uint8_t   u8CsioMode;           
    uint8_t   u8CsioActMode;        
    uint8_t   u8SyncWaitTime;       
    uint8_t   u8CharLength;         
    boolean_t bBitDirection;        
    boolean_t bSignalSystem;        
} stc_mfs_csio_config_t;

 
typedef struct stc_mfs_i2c_config
{
    uint32_t u32DataRate;           
    uint8_t  u8I2cMode;             
    uint8_t  u8NoizeFilter;         
    uint8_t  u8SlvAddr;             
    uint8_t  u8FastMode;            
} stc_mfs_i2c_config_t;

 
typedef struct stc_mfs_lin_config
{
    uint32_t  u32DataRate;          
    boolean_t bExtWakeUp;           
    boolean_t bLinBreakIrqEnable;   
    uint8_t   u8LinMode;            
    uint8_t   u8StopBits;           
    uint8_t   u8BreakLength;        
    uint8_t   u8DelimiterLength;    
} stc_mfs_lin_config_t;




 
typedef struct stc_mfs_csio_cs_timing
{
    uint8_t  u8CsSetupDelay;        
    uint8_t  u8CsHoldDelay;         
    uint16_t u16CsDeSelect;         
} stc_mfs_csio_cs_timing_t;




 
typedef struct stc_mfs_fifo_config
{
    uint8_t u8FifoSel;              
    uint8_t u8ByteCount1;           
    uint8_t u8ByteCount2;           
} stc_mfs_fifo_config_t;




 
typedef void (*mfs_tx_cb_func_ptr_t)(volatile stc_mfsn_t* pstcMfs, void* pvHandle);
typedef void (*mfs_rx_cb_func_ptr_t)(volatile stc_mfsn_t* pstcMfs, void* pvHandle);
typedef void (*mfs_sts_cb_func_ptr_t)(volatile stc_mfsn_t* pstcMfs, void* pvHandle);

 
 
 
#line 583 ".\\common\\mfs.h"

#line 591 ".\\common\\mfs.h"












 




 






 






 
#line 633 ".\\common\\mfs.h"

 





 





 





 




 
#line 665 ".\\common\\mfs.h"

 






 






 
#line 688 ".\\common\\mfs.h"

 




 
#line 704 ".\\common\\mfs.h"

 
#line 713 ".\\common\\mfs.h"

 


 
#line 737 ".\\common\\mfs.h"

 
#line 755 ".\\common\\mfs.h"

 
#line 773 ".\\common\\mfs.h"

















 
 
 


typedef enum en_mfs_instance_index
{
#line 810 ".\\common\\mfs.h"
    MfsInstanceIndexMfs4,
#line 819 ".\\common\\mfs.h"
    MfsInstanceIndexMfs7,
#line 845 ".\\common\\mfs.h"
    MfsInstanceIndexMax
} en_mfs_instance_index_t;


typedef struct stc_mfs_intern_data
{
    mfs_tx_cb_func_ptr_t        pfnTransmitCbFunction;  
    mfs_rx_cb_func_ptr_t        pfnReceiveCbFunction;   
    mfs_sts_cb_func_ptr_t       pfnStatusCbFunction;    
    void*                       pvUpperLayerHandle;     
} stc_mfs_intern_data_t;


typedef struct stc_mfs_instance_data
{
    volatile stc_mfsn_t*  pstcInstance;  
    stc_mfs_intern_data_t stcInternData; 
} stc_mfs_instance_data_t;

 
 
 


extern stc_mfs_instance_data_t m_astcMfsInstanceDataLut[MfsInstanceIndexMax];

 
 
 
extern void MfsIrqHandlerTx(volatile stc_mfsn_t*   pstcMfs, 
                            stc_mfs_intern_data_t* pstcMfsInternData
                           );

extern void MfsIrqHandlerRx(volatile stc_mfsn_t*   pstcMfs, 
                            stc_mfs_intern_data_t* pstcMfsInternData
                           );

extern void MfsIrqHandlerStatus(volatile stc_mfsn_t*   pstcMfs, 
                                stc_mfs_intern_data_t* pstcMfsInternData
                               );

 
extern en_result_t Mfs_Uart_Init(volatile stc_mfsn_t*         pstcUart,
                                 const stc_mfs_uart_config_t* pstcConfig
                                );

extern en_result_t Mfs_Uart_DeInit(volatile stc_mfsn_t* pstcUart);

extern en_result_t Mfs_Uart_SetBaudRate(volatile stc_mfsn_t* pstcUart,
                                        uint32_t             u32BaudRate
                                       );

extern en_result_t Mfs_Csio_Init(volatile stc_mfsn_t*         pstcCsio, 
                                 const stc_mfs_csio_config_t* pstcConfig
                                );

extern en_result_t Mfs_Csio_DeInit(volatile stc_mfsn_t* pstcCsio);

extern en_result_t Mfs_Csio_SetSckOutEnable(volatile stc_mfsn_t* pstcCsio,
                                            boolean_t            bEnable
                                           );

extern en_result_t Mfs_Csio_SetChipSelectErrEnable(volatile stc_mfsn_t* pstcCsio,
                                                   boolean_t            bEnable
                                                  );

extern en_result_t Mfs_Csio_SetChipSelectErrIntEnable(volatile stc_mfsn_t* pstcCsio,
                                                      boolean_t            bEnable
                                                     );

extern en_result_t Mfs_Csio_ClrChipSelectErr(volatile stc_mfsn_t* pstcCsio);

extern en_result_t Mfs_Csio_ClrTimerIntReq(volatile stc_mfsn_t* pstcCsio);

extern en_result_t Mfs_Csio_SetSerialTimerIntEnable(volatile stc_mfsn_t* pstcCsio,
                                                    boolean_t            bEnable
                                                   );

extern en_result_t Mfs_Csio_SetSyncTransEnable(volatile stc_mfsn_t* pstcCsio,
                                               boolean_t            bEnable
                                              );

extern en_result_t Mfs_Csio_SetTimerPrescale(volatile stc_mfsn_t* pstcCsio,
                                             uint8_t              u8Prescale
                                            );

extern en_result_t Mfs_Csio_SetSerialTimerEnable(volatile stc_mfsn_t* pstcCsio,
                                                 boolean_t            bEnable
                                                );

extern en_result_t Mfs_Csio_SetCmpVal4SerialTimer(volatile stc_mfsn_t* pstcCsio,
                                                  uint16_t             u16CompareValue
                                                 );

extern en_result_t Mfs_Csio_SetCsHold(volatile stc_mfsn_t* pstcCsio,
                                      boolean_t            bHold
                                     );

extern en_result_t Mfs_Csio_SetCsTimingPrescale(volatile stc_mfsn_t* pstcCsio,
                                                uint8_t              u8Prescale
                                               );

extern en_result_t Mfs_Csio_SetCsInActiveLevel(volatile stc_mfsn_t* pstcCsio,
                                               boolean_t            bLevel
                                              );

extern en_result_t Mfs_Csio_SetChipSelectEnable(volatile stc_mfsn_t* pstcCsio,
                                                boolean_t            bEnable
                                               );

extern en_result_t Mfs_Csio_SetChipSelectOutEnable(volatile stc_mfsn_t* pstcCsio,
                                                   boolean_t            bEnable
                                                  );

extern en_result_t Mfs_Csio_SetCsTimingConfig(volatile stc_mfsn_t*      pstcCsio,
                                              stc_mfs_csio_cs_timing_t* pstcCsTimingCfg
                                             );

extern en_result_t Mfs_Csio_SetTxLength(volatile stc_mfsn_t* pstcCsio,
                                        uint8_t              u8TxBytes
                                       );

extern en_result_t Mfs_Csio_SetBaudRate(volatile stc_mfsn_t* pstcCsio,
                                        uint32_t             u32BaudRate
                                       );

extern en_result_t Mfs_I2c_Init(volatile stc_mfsn_t*        pstcI2c, 
                                const stc_mfs_i2c_config_t* pstcConfig
                               );

extern en_result_t Mfs_I2c_DeInit(volatile stc_mfsn_t* pstcI2c );

extern en_result_t Mfs_I2c_SetTxIntEnable(volatile stc_mfsn_t* pstcI2c,
                                          boolean_t            bEnable
                                         );

extern en_result_t Mfs_I2c_SetRxIntEnable(volatile stc_mfsn_t* pstcI2c,
                                          boolean_t            bEnable
                                         );

extern en_result_t Mfs_I2c_SetAckEnable(volatile stc_mfsn_t* pstcI2c,
                                        boolean_t            bEnable
                                       );

extern en_result_t Mfs_I2c_SetWaitSelect(volatile stc_mfsn_t* pstcI2c,
                                         uint8_t              u8WaitSelect
                                        );

extern en_result_t Mfs_I2c_SetCondDetIntEnable(volatile stc_mfsn_t* pstcI2c,
                                               boolean_t            bEnable
                                              );

extern en_result_t Mfs_I2c_SetIntEnable(volatile stc_mfsn_t* pstcI2c,
                                        boolean_t            bEnable
                                       );

extern en_result_t Mfs_I2c_ClearIntStatus(volatile stc_mfsn_t* pstcI2c);

extern en_result_t Mfs_I2c_SetTransmitEmpty(volatile stc_mfsn_t* pstcI2c);

extern en_result_t Mfs_I2c_SetDmaModeEnable(volatile stc_mfsn_t* pstcI2c,
                                            boolean_t            bEnable
                                           );

extern en_result_t Mfs_I2c_SetNoizeFilter(volatile stc_mfsn_t* pstcI2c,
                                          uint8_t              u8NzFilter
                                         );

extern en_result_t Mfs_I2c_SetSdaOutLevel(volatile stc_mfsn_t* pstcI2c,
                                          boolean_t            bLevel
                                         );

extern en_result_t Mfs_I2c_SetSclOutLevel(volatile stc_mfsn_t* pstcI2c,
                                          boolean_t            bLevel
                                         );

extern en_result_t Mfs_I2c_SetSerlalOutEnable(volatile stc_mfsn_t* pstcI2c,
                                              boolean_t            bEnable
                                             );

extern en_result_t Mfs_I2c_SetBusErrorControlEnable(volatile stc_mfsn_t* pstcI2c,
                                                    boolean_t            bEnable
                                                   );

extern en_result_t Mfs_I2c_SetI2cEnable(volatile stc_mfsn_t* pstcI2c,
                                        boolean_t            bEnable,
                                        uint8_t              u8AddrMask
                                       );

extern en_result_t Mfs_I2c_SetSlvAddrEnable(volatile stc_mfsn_t* pstcI2c,
                                            boolean_t            bEnable,
                                            uint8_t              u8SlvAdr
                                           );

extern en_result_t Mfs_I2c_SetBaudRate(volatile stc_mfsn_t* pstcI2c, 
                                       uint32_t             u32BaudRate
                                      );

extern en_result_t Mfs_Lin_Init(volatile stc_mfsn_t*        pstcLin,
                                const stc_mfs_lin_config_t* pstcConfig
                               );

extern en_result_t Mfs_Lin_DeInit(volatile stc_mfsn_t* pstcLin);

extern en_result_t Mfs_Lin_SetBreak(volatile stc_mfsn_t* pstcLin);

extern en_result_t Mfs_Lin_ClearBreakDetFlag(volatile stc_mfsn_t* pstcLin);

extern en_result_t Mfs_Lin_SetBreakDetIntEnable(volatile stc_mfsn_t* pstcLin,
                                                boolean_t            bEnable
                                               );

extern en_result_t Mfs_Lin_SetBreakConfig(volatile stc_mfsn_t* pstcLin,
                                          uint8_t              u8BreakLen,
                                          uint8_t              u8DelimiterLen
                                         );

extern en_result_t Mfs_Lin_SetBaudRate(volatile stc_mfsn_t* pstcLin,
                                       uint32_t             u32BaudRate
                                      );

extern en_result_t Mfs_SetSerialOutputEnable(volatile stc_mfsn_t* pstcMfs,
                                             boolean_t            bEnable
                                            );

extern en_result_t Mfs_SetWakeUpControlEnable(volatile stc_mfsn_t* pstcMfs,
                                              boolean_t            bEnable
                                             );

extern en_result_t Mfs_SoftwareReset(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetRxIntEnable(volatile stc_mfsn_t* pstcMfs,
                                      boolean_t            bEnable
                                     );
extern en_result_t Mfs_SetTxIntEnable(volatile stc_mfsn_t* pstcMfs,
                                      boolean_t            bEnable
                                     );
extern en_result_t Mfs_SetTxBusIdleIntEnable(volatile stc_mfsn_t* pstcMfs,
                                             boolean_t            bEnable
                                            );
extern en_result_t Mfs_SetTxFifoIntEnable(volatile stc_mfsn_t* pstcMfs,
                                          boolean_t            bEnable
                                         );

extern en_result_t Mfs_SetRxEnable(volatile stc_mfsn_t* pstcMfs,
                                   boolean_t            bEnable
                                  );
extern en_result_t Mfs_SetTxEnable(volatile stc_mfsn_t* pstcMfs,
                                   boolean_t            bEnable
                                  );

extern en_result_t Mfs_ErrorClear(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_ConfigFifo(volatile stc_mfsn_t*   pstcMfs,
                                  stc_mfs_fifo_config_t* pstcFifoConfig
                                 );

extern en_result_t Mfs_ClrTxFifoReqStatus(volatile stc_mfsn_t* pstcMfs);
extern en_result_t Mfs_ResetFifo(volatile stc_mfsn_t* pstcMfs,
                                 uint8_t              u8FifoNumber
                                );
extern en_result_t Mfs_SetFifoEnable(volatile stc_mfsn_t* pstcMfs,
                                     uint8_t              u8FifoNumber,
                                     boolean_t            bEnable
                                    );

 
extern uint16_t Mfs_ReadData(volatile stc_mfsn_t* pstcMfs);
extern en_result_t Mfs_WriteData(volatile stc_mfsn_t* pstcMfs,
                                 const uint16_t       u16Data
                                );

extern uint32_t Mfs_Csio_ReadData32(volatile stc_mfsn_t* pstcCsio);
extern en_result_t Mfs_Csio_WriteData32(volatile stc_mfsn_t* pstcCsio,
                                        const uint32_t       u32Data
                                       );

 
extern uint16_t Mfs_Csio_GetSerialTimer(volatile stc_mfsn_t* pstcCsio);
extern uint16_t Mfs_Csio_GetStatus(volatile stc_mfsn_t* pstcCsio,
                                   uint16_t             u16StatusMask
                                  );

extern boolean_t Mfs_I2c_GetBusErrStatus(volatile stc_mfsn_t* pstcI2c);
extern boolean_t Mfs_I2c_GetIntStatus(volatile stc_mfsn_t* pstcI2c);

extern uint8_t Mfs_GetStatus(volatile stc_mfsn_t* pstcMfs,
                             uint8_t              u8StatusMask
                            );

extern boolean_t Mfs_GetTxFifoReqStatus(volatile stc_mfsn_t* pstcMfs);
extern uint8_t Mfs_GetFifoBytes(volatile stc_mfsn_t* pstcMfs,
                                uint8_t              u8FifoNumber
                               );

extern uint32_t Mfs_GetBusClock(void);
extern uint32_t Mfs_GetReloadValue(uint32_t u32BaudRate);
extern uint32_t Mfs_I2c_GetReloadValue(uint32_t u32BaudRate);

 
extern en_result_t Mfs_SetSMR(volatile stc_mfsn_t* pstcMfs,
                              uint8_t              u8SMR
                             );
extern uint8_t Mfs_GetSMR(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetSCR(volatile stc_mfsn_t* pstcMfs,
                              uint8_t              u8SCR
                             );
extern uint8_t Mfs_GetSCR(volatile stc_mfsn_t* pstcMfs);



extern en_result_t Mfs_SetESCR(volatile stc_mfsn_t* pstcMfs,
                               uint8_t               u8ESCR
                              );
extern uint8_t Mfs_GetESCR(volatile stc_mfsn_t* pstcMfs);








extern en_result_t Mfs_SetBGR(volatile stc_mfsn_t* pstcMfs,
                              uint16_t             u16BGR
                             );

extern uint16_t Mfs_GetBGR(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetFCR1(volatile stc_mfsn_t* pstcMfs,
                               uint8_t              u8FCR1
                              );
extern uint8_t Mfs_GetFCR1(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetFCR0(volatile stc_mfsn_t* pstcMfs,
                               uint8_t              u8FCR0
                              );
extern uint8_t Mfs_GetFCR0(volatile stc_mfsn_t* pstcMfs);



extern en_result_t Mfs_SetSCSTR10(volatile stc_mfsn_t* pstcMfs,
                                  uint16_t             u16SCSTR10
                                 );
extern uint16_t Mfs_GetSCSTR10(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetSCSTR32(volatile stc_mfsn_t* pstcMfs,
                                  uint16_t             u16SCSTR32
                                 );
extern uint16_t Mfs_GetSCSTR32(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetSACSR(volatile stc_mfsn_t* pstcMfs,
                                uint16_t             u16SACSR
                               );
extern uint16_t Mfs_GetSACSR(volatile stc_mfsn_t* pstcMfs);

extern uint16_t Mfs_GetSTMCR(volatile stc_mfsn_t* pstcMfs);





extern en_result_t Mfs_SetSCSCR(volatile stc_mfsn_t* pstcMfs,
                                uint16_t             u16SCSCR
                               );
extern uint16_t Mfs_GetSCSCR(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetTBYTE0(volatile stc_mfsn_t* pstcMfs,
                                 uint8_t              u8TBYTE0
                                );
extern uint8_t Mfs_GetTBYTE0(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetISBA(volatile stc_mfsn_t* pstcMfs,
                               uint8_t              u8ISBA
                              );
extern uint8_t Mfs_GetISBA(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetISMK(volatile stc_mfsn_t* pstcMfs,
                               uint8_t              u8ISMK
                              );
extern uint8_t Mfs_GetISMK(volatile stc_mfsn_t* pstcMfs);


extern uint8_t Mfs_GetNFCR(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetEIBCR(volatile stc_mfsn_t* pstcMfs,
                                uint8_t              u8EIBCR
                               );
extern uint8_t Mfs_GetEIBCR(volatile stc_mfsn_t* pstcMfs);

 
extern en_result_t Mfs_InitTxIrq(volatile stc_mfsn_t* pstcMfs);
extern en_result_t Mfs_InitRxIrq(volatile stc_mfsn_t* pstcMfs);
extern en_result_t Mfs_DeInitIrq(volatile stc_mfsn_t* pstcMfs);

extern en_result_t Mfs_SetRxIntCallBack(volatile stc_mfsn_t* pstcMfs,
                                        mfs_rx_cb_func_ptr_t pfnRxCbFunc
                                       );

extern en_result_t Mfs_SetTxIntCallBack(volatile stc_mfsn_t* pstcMfs,
                                        mfs_tx_cb_func_ptr_t pfnTxCbFunc
                                       );

extern en_result_t Mfs_SetStsIntCallBack(volatile stc_mfsn_t*  pstcMfs,
                                         mfs_sts_cb_func_ptr_t pfnStsCbFunc
                                        );

extern en_result_t Mfs_SetUpperLayerHandle(volatile stc_mfsn_t* pstcMfs,
                                           void*                pvHandle
                                          );










 
 
 
#line 359 ".\\common\\pdl.h"



#line 368 ".\\common\\pdl.h"


#line 376 ".\\common\\pdl.h"


#line 384 ".\\common\\pdl.h"


#line 392 ".\\common\\pdl.h"
      

#line 400 ".\\common\\pdl.h"
      







#line 415 ".\\common\\pdl.h"


#line 1 ".\\lib\\inc\\reset.h"







































 
 







 




 
 
 
#line 58 ".\\lib\\inc\\reset.h"



 























 


 
 
 
 


 
  



 
typedef struct stc_reset_result
{
  boolean_t    bPowerOn;              
  boolean_t    bInitx;                
  boolean_t    bLowVoltageDetection;  
  boolean_t    bSoftwareWatchdog;     
  boolean_t    bHardwareWatchdog;     
  boolean_t    bClockSupervisor;      
  boolean_t    bAnomalousFrequency;   
  boolean_t    bSoftware;             
} stc_reset_result_t ;

 
 
 

 
 
 

extern en_result_t Reset_GetCause( stc_reset_result_t* pstcResult ) ;
extern en_result_t Reset_GetStoredCause( stc_reset_result_t* pstcResult );










 
 
 
#line 420 ".\\common\\pdl.h"













      




























#line 468 ".\\common\\pdl.h"



  
 






































            





			























 















 
 
 











 
 
 











 
#line 592 ".\\common\\pdl.h"






 







#line 621 ".\\common\\pdl.h"




 
#line 701 ".\\common\\pdl.h"
 
 
#line 739 ".\\common\\pdl.h"






#line 758 ".\\common\\pdl.h"

 
 
 

 
 
 

 
 
 



 
extern void pdl_memclr(uint8_t* pu32Address, uint32_t u32Count);




 
extern void PDL_WAIT_LOOP_HOOK(void);







 
 
 

#line 60 ".\\common\\gpio.h"

 
















 

  
 
 
 










                                      









		




  




 
 
 











            
 
 
 

#line 1 ".\\common\\gpio_mb9bf56xr.h"







































 
 







 




#line 55 ".\\common\\gpio_mb9bf56xr.h"




 



 

 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 




















 



















 

















 
















 




















 



















 




















 



















 




















 



















 




















 



















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 
















 

















 



















 

 




 




 




 



 



 



 



 



 



 



 



 



 



 



 



 




 




 




 



 



 



 



 



 



 



 



 



 



 



 



 



 




 



 



 



 



 



 




 



 




 



 



 




 



 



 




 



 



 



 




 




 



 



 



 




 




 



 




 




 



 




 




 



 




 




 



 



 



 



 



 



 



 



 



 



 



 



 




 



 



 




 



 



 




 



 



 



 



 




 




 



 




 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 




 



 



 



 



 



 



 



 



 



 



 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 




 



 



 




 




 




 




 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 




 



 



 




 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 




 



 



 



 



 



 



 




 




 




 




 




 



 



 




 



 



 



 




 



 



 



 



 



 



 




 



 



 



 




 




 



 




 



 



 




 



 



 



 




 



 



 



 



 



 



 




 



 




 




 




 




 



 



 




 



 



 



 




 



 



 



 



 



 



 




 



 



 




 



 



 



 



 



 



 




 



 



 



 




 



 



 



 



 



 



 



 



 



 



 



 



 



 




 




 



 



 



 



 



 



 



 



 



 



 



 



 



 



 




 




 



 



 



 



 




 



 



 



 



 



 



 



 



 




 



 



 



 



 



 



 



 



 



 



 




 



 




 




 




 




 




 



 



 



 



 



 




 



 



 



 



 




 







 
 
 

#line 140 ".\\common\\gpio.h"
#line 146 ".\\common\\gpio.h"


 
 
 

typedef struct stc_gpio1pin_init
{
    boolean_t bOutput;
    boolean_t bInitVal;
    boolean_t bPullup; 
} stc_gpio1pin_init_t;










 
 
 
#line 43 ".\\WyzBee_gpio\\WyzBee_gpio.h"






 


											 




											             




											             




											             



											             



											             



											             





											             



														 



										    			 




														 





















 









 









 


#line 37 "WyzBee_gpio\\WyzBee_gpio.c"






 






 







 





 






 





 







 






