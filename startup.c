/*****************************************************/
 /* Author      : mosad                              */
 /* Version     : v01                                */
 /* date        : 13/11/2020                         */
/*****************************************************/
#include "STD_TYPES.h"

#define   SRAM_START   0x20000000 
#define   SRAM_SIZE    (20 * 1024)
#define   SRAM_END      (SRAM_START + SRAM_SIZE)
#define   STACK_START   SRAM_END


extern u32 _etext;
extern u32 _sdata;
extern u32 _edata;

extern u32 _sbss;
extern u32 _ebss;


/* Functions prototypes */
void Reset_Handler(void);

void main (void); 

/* Weak functions */
void NMI_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler             (void) __attribute__ ((weak, alias("Default_Handler")));
void SVCall_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void Debug_Monitor_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));
void TAMPER_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_Handler                    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel1_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel2_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel3_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel4_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel5_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel6_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel7_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1_2_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_HP_CAN_TX_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_LP_CAN_RX0_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_RX1_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_SCE_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM4_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI2_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void USART2_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void USART3_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void RTCAlarm_Handler               (void) __attribute__ ((weak, alias("Default_Handler")));
void USBWakeup_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));

/* Initialize vector table */
// Make a new section .isr_vector so this array wont be in .bss or .data
u32 vectors[] __attribute__((section(".isr_vector")))   = {
	STACK_START,
	// core level
	(u32)Reset_Handler,
	(u32)NMI_Handler,
	(u32)HardFault_Handler ,    
	(u32)MemManage_Handler ,    
	(u32)BusFault_Handler ,     
	(u32)UsageFault_Handler ,
	0,
	(u32)SVCall_Handler,        
	(u32)Debug_Monitor_Handler,
	0,
	0,
	0,
	0,
	(u32)PendSV_Handler,        
	(u32)SysTick_Handler,
	
	// chip level
	(u32)WWDG_Handler ,         
	(u32)PVD_Handler  ,        
	(u32)TAMPER_Handler,        
	(u32)RTC_Handler,           
	(u32)FLASH_Handler,         
	(u32)RCC_Handler,           
	(u32)EXTI0_Handler,         
	(u32)EXTI1_Handler,         
	(u32)EXTI2_Handler,         
	(u32)EXTI3_Handler,         
	(u32)EXTI4_Handler,         
	(u32)DMA1_Channel1_Handler, 
	(u32)DMA1_Channel2_Handler, 
	(u32)DMA1_Channel3_Handler, 
	(u32)DMA1_Channel4_Handler, 
    (u32)DMA1_Channel5_Handler, 
    (u32)DMA1_Channel6_Handler, 
    (u32)DMA1_Channel7_Handler, 
    (u32)ADC1_2_Handler, 
	(u32)USB_HP_CAN_TX_Handler,
	(u32)USB_LP_CAN_RX0_Handler,
	(u32)CAN_RX1_Handler    ,
	(u32)CAN_SCE_Handler    ,
	(u32)EXTI9_5_Handler    ,
	(u32)TIM1_BRK_Handler   ,
	(u32)TIM1_UP_Handler    ,
	(u32)TIM1_TRG_COM_Handler,
	(u32)TIM1_CC_Handler    ,
	(u32)TIM2_Handler       ,
	(u32)TIM3_Handler       ,
	(u32)TIM4_Handler       ,
	(u32)I2C1_EV_Handler    ,
	(u32)I2C1_ER_Handler    ,
	(u32)I2C2_EV_Handler    ,
	(u32)I2C2_ER_Handler    ,
	(u32)SPI1_Handler       ,
	(u32)SPI2_Handler       ,
	(u32)USART1_Handler     ,
	(u32)USART2_Handler     ,
	(u32)USART3_Handler     ,
	(u32)EXTI15_10_Handler  ,
	(u32)RTCAlarm_Handler   ,
	(u32)USBWakeup_Handler  
        
};

void Default_Handler(void)
{
	while(1);
}

void Reset_Handler(void)
{
	/* Initialize .data section */	
	u32 DataSize = (u32)&_edata -  (u32)&_sdata ;
	u8 *DataDist = (u8 *) &_sdata ;
	u8 *DataSrc  = (u8 *) &_etext ;
	
	for (u32 i = 0 ; i < DataSize; i++){
		*DataDist++ = *DataSrc++ ;
	}
	
	/* Initialize .bss section */
	u32 BssSize = (u32)&_ebss -  (u32)&_sbss ;
	u8 *BssDist = (u8 *) &_sbss ;
	
	for (u32 i = 0 ; i < BssSize; i++){
		*DataDist++ = 0 ;
	}
	
	main();
}
