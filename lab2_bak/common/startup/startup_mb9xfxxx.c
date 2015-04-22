/**
 ******************************************************************************
 * @file      startup_Cortex_M4.c
 * @author    Coocox
 * @version   V1.0
 * @date      03/16/2013
 * @brief     Cortex M4 Devices Startup code.
 *            This module performs:
 *                - Set the initial SP
 *                - Set the vector table entries with the exceptions ISR address
 *                - Initialize data and bss
 *                - Call the application's entry point.
 *            After Reset the Cortex-M4 processor is in Thread mode,
 *            priority is Privileged, and the Stack is set to Main.
 *******************************************************************************
 */
 

/*----------Stack Configuration-----------------------------------------------*/  
#define STACK_SIZE       0x00000100      /*!< Stack size (in Words)           */
__attribute__ ((section(".co_stack")))
unsigned long pulStack[STACK_SIZE];      


/*----------Macro definition--------------------------------------------------*/  
#define WEAK __attribute__ ((weak))           


/*----------Declaration of the default fault handlers-------------------------*/  
/* System exception vector handler */
__attribute__ ((used))
void WEAK  Reset_Handler(void);   
void WEAK  NMI_Handler(void);       
void WEAK  HardFault_Handler(void); 
void WEAK  MemManage_Handler(void); 
void WEAK  BusFault_Handler(void);  
void WEAK  UsageFault_Handler(void);
void WEAK  SVC_Handler(void);       
void WEAK  DebugMon_Handler(void);  
void WEAK  PendSV_Handler(void);    
void WEAK  SysTick_Handler(void);  
 
void WEAK  IRQ000_Handler(void);
void WEAK  IRQ001_Handler(void);
void WEAK  IRQ002_Handler(void);
void WEAK  IRQ003_Handler(void);
void WEAK  IRQ004_Handler(void);
void WEAK  IRQ005_Handler(void);
void WEAK  IRQ006_Handler(void);
void WEAK  IRQ007_Handler(void);
void WEAK  IRQ008_Handler(void);
void WEAK  IRQ009_Handler(void);
void WEAK  IRQ010_Handler(void);
void WEAK  IRQ011_Handler(void);
void WEAK  IRQ012_Handler(void);
void WEAK  IRQ013_Handler(void);
void WEAK  IRQ014_Handler(void);
void WEAK  IRQ015_Handler(void);
void WEAK  IRQ016_Handler(void);
void WEAK  IRQ017_Handler(void);
void WEAK  IRQ018_Handler(void);
void WEAK  IRQ019_Handler(void);
void WEAK  IRQ020_Handler(void);
void WEAK  IRQ021_Handler(void);
void WEAK  IRQ022_Handler(void);
void WEAK  IRQ023_Handler(void);
void WEAK  IRQ024_Handler(void);
void WEAK  IRQ025_Handler(void);
void WEAK  IRQ026_Handler(void);
void WEAK  IRQ027_Handler(void);
void WEAK  IRQ028_Handler(void);
void WEAK  IRQ029_Handler(void);
void WEAK  IRQ030_Handler(void);
void WEAK  IRQ031_Handler(void);
void WEAK  IRQ032_Handler(void);
void WEAK  IRQ033_Handler(void);
void WEAK  IRQ034_Handler(void);
void WEAK  IRQ035_Handler(void);
void WEAK  IRQ036_Handler(void);
void WEAK  IRQ037_Handler(void);
void WEAK  IRQ038_Handler(void);
void WEAK  IRQ039_Handler(void);
void WEAK  IRQ040_Handler(void);
void WEAK  IRQ041_Handler(void);
void WEAK  IRQ042_Handler(void);
void WEAK  IRQ043_Handler(void);
void WEAK  IRQ044_Handler(void);
void WEAK  IRQ045_Handler(void);
void WEAK  IRQ046_Handler(void);
void WEAK  IRQ047_Handler(void);
void WEAK  IRQ048_Handler(void);
void WEAK  IRQ049_Handler(void);
void WEAK  IRQ050_Handler(void);
void WEAK  IRQ051_Handler(void);
void WEAK  IRQ052_Handler(void);
void WEAK  IRQ053_Handler(void);
void WEAK  IRQ054_Handler(void);
void WEAK  IRQ055_Handler(void);
void WEAK  IRQ056_Handler(void);
void WEAK  IRQ057_Handler(void);
void WEAK  IRQ058_Handler(void);
void WEAK  IRQ059_Handler(void);
void WEAK  IRQ060_Handler(void);
void WEAK  IRQ061_Handler(void);
void WEAK  IRQ062_Handler(void);
void WEAK  IRQ063_Handler(void);
void WEAK  IRQ064_Handler(void);
void WEAK  IRQ065_Handler(void);
void WEAK  IRQ066_Handler(void);
void WEAK  IRQ067_Handler(void);
void WEAK  IRQ068_Handler(void);
void WEAK  IRQ069_Handler(void);
void WEAK  IRQ070_Handler(void);
void WEAK  IRQ071_Handler(void);
void WEAK  IRQ072_Handler(void);
void WEAK  IRQ073_Handler(void);
void WEAK  IRQ074_Handler(void);
void WEAK  IRQ075_Handler(void);
void WEAK  IRQ076_Handler(void);
void WEAK  IRQ077_Handler(void);
void WEAK  IRQ078_Handler(void);
void WEAK  IRQ079_Handler(void);
void WEAK  IRQ080_Handler(void);
void WEAK  IRQ081_Handler(void);
void WEAK  IRQ082_Handler(void);
void WEAK  IRQ083_Handler(void);
void WEAK  IRQ084_Handler(void);
void WEAK  IRQ085_Handler(void);
void WEAK  IRQ086_Handler(void);
void WEAK  IRQ087_Handler(void);
void WEAK  IRQ088_Handler(void);
void WEAK  IRQ089_Handler(void);
void WEAK  IRQ090_Handler(void);
void WEAK  IRQ091_Handler(void);
void WEAK  IRQ092_Handler(void);
void WEAK  IRQ093_Handler(void);
void WEAK  IRQ094_Handler(void);
void WEAK  IRQ095_Handler(void);
void WEAK  IRQ096_Handler(void);
void WEAK  IRQ097_Handler(void);
void WEAK  IRQ098_Handler(void);
void WEAK  IRQ099_Handler(void);
void WEAK  IRQ100_Handler(void);
void WEAK  IRQ101_Handler(void);
void WEAK  IRQ102_Handler(void);
void WEAK  IRQ103_Handler(void);
void WEAK  IRQ104_Handler(void);
void WEAK  IRQ105_Handler(void);
void WEAK  IRQ106_Handler(void);
void WEAK  IRQ107_Handler(void);
void WEAK  IRQ108_Handler(void);
void WEAK  IRQ109_Handler(void);
void WEAK  IRQ110_Handler(void);
void WEAK  IRQ111_Handler(void);

void WEAK  IRQ113_Handler(void);
void WEAK  IRQ114_Handler(void);
void WEAK  IRQ118_Handler(void);
void WEAK  IRQ119_Handler(void);
void WEAK  IRQ120_Handler(void);
void WEAK  IRQ121_Handler(void);
void WEAK  IRQ122_Handler(void);
void WEAK  IRQ123_Handler(void);
void WEAK  IRQ124_Handler(void);
void WEAK  IRQ125_Handler(void);
void WEAK  IRQ126_Handler(void);
void WEAK  IRQ127_Handler(void);


/*----------Symbols defined in linker script----------------------------------*/  
extern unsigned long _sidata;    /*!< Start address for the initialization 
                                      values of the .data section.            */
extern unsigned long _sdata;     /*!< Start address for the .data section     */    
extern unsigned long _edata;     /*!< End address for the .data section       */    
extern unsigned long _sbss;      /*!< Start address for the .bss section      */
extern unsigned long _ebss;      /*!< End address for the .bss section        */      
extern void _eram;               /*!< End address for ram                     */


/*----------Function prototypes-----------------------------------------------*/  
extern int main(void);           /*!< The entry point for the application.    */
void Default_Reset_Handler(void);   /*!< Default reset handler                */
static void Default_Handler(void);  /*!< Default exception handler            */


/**
  *@brief The minimal vector table for a Cortex M4.  Note that the proper constructs
  *       must be placed on this to ensure that it ends up at physical address
  *       0x00000000.  
  */
__attribute__ ((used,section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{	
  /*----------Core Exceptions------------------------------------------------ */
  (void *)&pulStack[STACK_SIZE-1],     /*!< The initial stack pointer         */
  Reset_Handler,             /*!< Reset Handler                               */
  NMI_Handler,               /*!< NMI Handler                                 */
  HardFault_Handler,         /*!< Hard Fault Handler                          */
  MemManage_Handler,         /*!< MPU Fault Handler                           */
  BusFault_Handler,          /*!< Bus Fault Handler                           */
  UsageFault_Handler,        /*!< Usage Fault Handler                         */
  0,0,0,0,                   /*!< Reserved                                    */
  SVC_Handler,               /*!< SVCall Handler                              */
  DebugMon_Handler,          /*!< Debug Monitor Handler                       */
  0,                         /*!< Reserved                                    */
  PendSV_Handler,            /*!< PendSV Handler                              */
  SysTick_Handler,           /*!< SysTick Handler                             */
  
  /*----------External Exceptions---------------------------------------------*/
  IRQ000_Handler,
  IRQ001_Handler,
  IRQ002_Handler,
  IRQ003_Handler,
  IRQ004_Handler,
  IRQ005_Handler,
  IRQ006_Handler,
  IRQ007_Handler,
  IRQ008_Handler,
  IRQ009_Handler,
  IRQ010_Handler,
  IRQ011_Handler,
  IRQ012_Handler,
  IRQ013_Handler,
  IRQ014_Handler,
  IRQ015_Handler,
  IRQ016_Handler,
  IRQ017_Handler,
  IRQ018_Handler,
  IRQ019_Handler,
  IRQ020_Handler,
  IRQ021_Handler,
  IRQ022_Handler,
  IRQ023_Handler,
  IRQ024_Handler,
  IRQ025_Handler,
  IRQ026_Handler,
  IRQ027_Handler,
  IRQ028_Handler,
  IRQ029_Handler,
  IRQ030_Handler,
  IRQ031_Handler,
  IRQ032_Handler,
  IRQ033_Handler,
  IRQ034_Handler,
  IRQ035_Handler,
  IRQ036_Handler,
  IRQ037_Handler,
  IRQ038_Handler,
  IRQ039_Handler,
  IRQ040_Handler,
  IRQ041_Handler,
  IRQ042_Handler,
  IRQ043_Handler,
  IRQ044_Handler,
  IRQ045_Handler,
  IRQ046_Handler,
  IRQ047_Handler,
  IRQ048_Handler,
  IRQ049_Handler,
  IRQ050_Handler,
  IRQ051_Handler,
  IRQ052_Handler,
  IRQ053_Handler,
  IRQ054_Handler,
  IRQ055_Handler,
  IRQ056_Handler,
  IRQ057_Handler,
  IRQ058_Handler,
  IRQ059_Handler,
  IRQ060_Handler,
  IRQ061_Handler,
  IRQ062_Handler,
  IRQ063_Handler,
  IRQ064_Handler,
  IRQ065_Handler,
  IRQ066_Handler,
  IRQ067_Handler,
  IRQ068_Handler,
  IRQ069_Handler,
  IRQ070_Handler,
  IRQ071_Handler,
  IRQ072_Handler,
  IRQ073_Handler,
  IRQ074_Handler,
  IRQ075_Handler,
  IRQ076_Handler,
  IRQ077_Handler,
  IRQ078_Handler,
  IRQ079_Handler,
  IRQ080_Handler,
  IRQ081_Handler,
  IRQ082_Handler,
  IRQ083_Handler,
  IRQ084_Handler,
  IRQ085_Handler,
  IRQ086_Handler,
  IRQ087_Handler,
  IRQ088_Handler,
  IRQ089_Handler,
  IRQ090_Handler,
  IRQ091_Handler,
  IRQ092_Handler,
  IRQ093_Handler,
  IRQ094_Handler,
  IRQ095_Handler,
  IRQ096_Handler,
  IRQ097_Handler,
  IRQ098_Handler,
  IRQ099_Handler,
  IRQ100_Handler,
  IRQ101_Handler,
  IRQ102_Handler,
  IRQ103_Handler,
  IRQ104_Handler,
  IRQ105_Handler,
  IRQ106_Handler,
  IRQ107_Handler,
  IRQ108_Handler,
  IRQ109_Handler,
  IRQ110_Handler,
  IRQ111_Handler,
  0,
  IRQ113_Handler,
  IRQ114_Handler,
  0,
  0,
  0,
  IRQ118_Handler,
  IRQ119_Handler,
  IRQ120_Handler,
  IRQ121_Handler,
  IRQ122_Handler,
  IRQ123_Handler,
  IRQ124_Handler,
  IRQ125_Handler,
  IRQ126_Handler,
  IRQ127_Handler,
};


/**
  * @brief  This is the code that gets called when the processor first
  *         starts execution following a reset event. Only the absolutely
  *         necessary set is performed, after which the application
  *         supplied main() routine is called. 
  * @param  None
  * @retval None
  */
void Default_Reset_Handler(void)
{
  /* Initialize data and bss */
  unsigned long *pulSrc, *pulDest;

  /* Copy the data segment initializers from flash to SRAM */
  pulSrc = &_sidata;

  for(pulDest = &_sdata; pulDest < &_edata; )
  {
    *(pulDest++) = *(pulSrc++);
  }
  
  /* Zero fill the bss segment.  This is done with inline assembly since this
     will clear the value of pulDest if it is not kept in a register. */
  __asm("  ldr     r0, =_sbss\n"
        "  ldr     r1, =_ebss\n"
        "  mov     r2, #0\n"
        "  .thumb_func\n"
        "zero_loop:\n"
        "    cmp     r0, r1\n"
        "    it      lt\n"
        "    strlt   r2, [r0], #4\n"
        "    blt     zero_loop");
#ifdef SUPPORT_CPLUSPLUS
  extern void __libc_init_array(void);
  __libc_init_array ();
#endif

  SystemInit();

  /* Call the application's entry point.*/
  main();
}


/**
  *@brief Provide weak aliases for each Exception handler to the Default_Handler. 
  *       As they are weak aliases, any function with the same name will override 
  *       this definition.
  */
#pragma weak Reset_Handler = Default_Reset_Handler
#pragma weak NMI_Handler = Default_Handler     
#pragma weak HardFault_Handler = Default_Handler     
#pragma weak MemManage_Handler = Default_Handler     
#pragma weak BusFault_Handler = Default_Handler      
#pragma weak UsageFault_Handler = Default_Handler    
#pragma weak SVC_Handler = Default_Handler           
#pragma weak DebugMon_Handler = Default_Handler      
#pragma weak PendSV_Handler = Default_Handler        
#pragma weak SysTick_Handler = Default_Handler       
      
#pragma weak  IRQ000_Handler = Default_Handler
#pragma weak  IRQ001_Handler = Default_Handler
#pragma weak  IRQ002_Handler = Default_Handler
#pragma weak  IRQ003_Handler = Default_Handler
#pragma weak  IRQ004_Handler = Default_Handler
#pragma weak  IRQ005_Handler = Default_Handler
#pragma weak  IRQ006_Handler = Default_Handler
#pragma weak  IRQ007_Handler = Default_Handler
#pragma weak  IRQ008_Handler = Default_Handler
#pragma weak  IRQ009_Handler = Default_Handler
#pragma weak  IRQ010_Handler = Default_Handler
#pragma weak  IRQ011_Handler = Default_Handler
#pragma weak  IRQ012_Handler = Default_Handler
#pragma weak  IRQ013_Handler = Default_Handler
#pragma weak  IRQ014_Handler = Default_Handler
#pragma weak  IRQ015_Handler = Default_Handler
#pragma weak  IRQ016_Handler = Default_Handler
#pragma weak  IRQ017_Handler = Default_Handler
#pragma weak  IRQ018_Handler = Default_Handler
#pragma weak  IRQ019_Handler = Default_Handler
#pragma weak  IRQ020_Handler = Default_Handler
#pragma weak  WFG0_DTIF0_IRQHandle = Default_Handler
#pragma weak  IRQ022_Handler = Default_Handler
#pragma weak  IRQ023_Handler = Default_Handler
#pragma weak  IRQ024_Handler = Default_Handler
#pragma weak  IRQ025_Handler = Default_Handler
#pragma weak  IRQ026_Handler = Default_Handler
#pragma weak  IRQ027_Handler = Default_Handler
#pragma weak  IRQ028_Handler = Default_Handler
#pragma weak  IRQ029_Handler = Default_Handler
#pragma weak  IRQ030_Handler = Default_Handler
#pragma weak  IRQ031_Handler = Default_Handler
#pragma weak  IRQ032_Handler = Default_Handler
#pragma weak  IRQ033_Handler = Default_Handler
#pragma weak  IRQ034_Handler = Default_Handler
#pragma weak  IRQ035_Handler = Default_Handler
#pragma weak  IRQ036_Handler = Default_Handler
#pragma weak  IRQ037_Handler = Default_Handler
#pragma weak  IRQ038_Handler = Default_Handler
#pragma weak  IRQ039_Handler = Default_Handler
#pragma weak  IRQ040_Handler = Default_Handler
#pragma weak  IRQ041_Handler = Default_Handler
#pragma weak  IRQ042_Handler = Default_Handler
#pragma weak  IRQ043_Handler = Default_Handler
#pragma weak  IRQ044_Handler = Default_Handler
#pragma weak  IRQ045_Handler = Default_Handler
#pragma weak  IRQ046_Handler = Default_Handler
#pragma weak  IRQ047_Handler = Default_Handler
#pragma weak  IRQ048_Handler = Default_Handler
#pragma weak  IRQ049_Handler = Default_Handler
#pragma weak  IRQ050_Handler = Default_Handler
#pragma weak  IRQ051_Handler = Default_Handler
#pragma weak  IRQ052_Handler = Default_Handler
#pragma weak  IRQ053_Handler = Default_Handler
#pragma weak  IRQ054_Handler = Default_Handler
#pragma weak  IRQ055_Handler = Default_Handler
#pragma weak  IRQ056_Handler = Default_Handler
#pragma weak  IRQ057_Handler = Default_Handler
#pragma weak  IRQ058_Handler = Default_Handler
#pragma weak  IRQ059_Handler = Default_Handler
#pragma weak  IRQ060_Handler = Default_Handler
#pragma weak  IRQ061_Handler = Default_Handler
#pragma weak  IRQ062_Handler = Default_Handler
#pragma weak  IRQ063_Handler = Default_Handler
#pragma weak  IRQ064_Handler = Default_Handler
#pragma weak  IRQ065_Handler = Default_Handler
#pragma weak  IRQ066_Handler = Default_Handler
#pragma weak  IRQ067_Handler = Default_Handler
#pragma weak  IRQ068_Handler = Default_Handler
#pragma weak  IRQ069_Handler = Default_Handler
#pragma weak  IRQ070_Handler = Default_Handler
#pragma weak  IRQ071_Handler = Default_Handler
#pragma weak  IRQ072_Handler = Default_Handler
#pragma weak  IRQ073_Handler = Default_Handler
#pragma weak  IRQ074_Handler = Default_Handler
#pragma weak  IRQ075_Handler = Default_Handler
#pragma weak  IRQ076_Handler = Default_Handler
#pragma weak  IRQ077_Handler = Default_Handler
#pragma weak  IRQ078_Handler = Default_Handler
#pragma weak  IRQ079_Handler = Default_Handler
#pragma weak  IRQ080_Handler = Default_Handler
#pragma weak  IRQ081_Handler = Default_Handler
#pragma weak  IRQ082_Handler = Default_Handler
#pragma weak  IRQ083_Handler = Default_Handler
#pragma weak  IRQ084_Handler = Default_Handler
#pragma weak  IRQ085_Handler = Default_Handler
#pragma weak  IRQ086_Handler = Default_Handler
#pragma weak  IRQ087_Handler = Default_Handler
#pragma weak  IRQ088_Handler = Default_Handler
#pragma weak  IRQ089_Handler = Default_Handler
#pragma weak  IRQ090_Handler = Default_Handler
#pragma weak  IRQ091_Handler = Default_Handler
#pragma weak  IRQ092_Handler = Default_Handler
#pragma weak  IRQ093_Handler = Default_Handler
#pragma weak  IRQ094_Handler = Default_Handler
#pragma weak  IRQ095_Handler = Default_Handler
#pragma weak  IRQ096_Handler = Default_Handler
#pragma weak  IRQ097_Handler = Default_Handler
#pragma weak  IRQ098_Handler = Default_Handler
#pragma weak  IRQ099_Handler = Default_Handler
#pragma weak  IRQ100_Handler = Default_Handler
#pragma weak  IRQ101_Handler = Default_Handler
#pragma weak  IRQ102_Handler = Default_Handler
#pragma weak  IRQ103_Handler = Default_Handler
#pragma weak  IRQ104_Handler = Default_Handler
#pragma weak  IRQ105_Handler = Default_Handler
#pragma weak  IRQ106_Handler = Default_Handler
#pragma weak  IRQ107_Handler = Default_Handler
#pragma weak  IRQ108_Handler = Default_Handler
#pragma weak  IRQ109_Handler = Default_Handler
#pragma weak  IRQ110_Handler = Default_Handler
#pragma weak  IRQ111_Handler = Default_Handler
#pragma weak  IRQ113_Handler = Default_Handler
#pragma weak  IRQ114_Handler = Default_Handler
#pragma weak  IRQ118_Handler = Default_Handler
#pragma weak  IRQ119_Handler = Default_Handler
#pragma weak  IRQ120_Handler = Default_Handler
#pragma weak  IRQ121_Handler = Default_Handler
#pragma weak  IRQ122_Handler = Default_Handler
#pragma weak  IRQ123_Handler = Default_Handler
#pragma weak  IRQ124_Handler = Default_Handler
#pragma weak  IRQ125_Handler = Default_Handler
#pragma weak  IRQ126_Handler = Default_Handler
#pragma weak  IRQ127_Handler = Default_Handler

/**
  * @brief  This is the code that gets called when the processor receives an 
  *         unexpected interrupt.  This simply enters an infinite loop, 
  *         preserving the system state for examination by a debugger.
  * @param  None
  * @retval None  
  */
static void Default_Handler(void) 
{
	/* Go into an infinite loop. */
	while (1) 
	{
	}
}

/*********************** (C) COPYRIGHT 2009 Coocox ************END OF FILE*****/
