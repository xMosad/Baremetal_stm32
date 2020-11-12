#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"


#define PORTA_CRL *((u32 *) 0x40010800)
#define PORTA_ODR *((u32 *) 0x4001080C)
#define SYSTEMCORECLOCK 8000000

void delay_ms(u32 ms)
{
	u32 i;

	for(i = 0; i < (SYSTEMCORECLOCK/(12000)) * ms; i++){
		__asm ("NOP");
	}
}

const u32 var1 = 1 ; 
const u8 var2 = 4 ;
const u8 var3 = 100 ;
u8 i = 0 ;
u8 x2 ;


void main (void){
	/* Enable RCC */
	RCC_voidInitSysClock();

	/* Enable PORTA clock */
	RCC_voidEnableClock(RCC_APB2 , IOPA_PERIPHERAL);



	PORTA_CRL = 0x00000002 ;

	PORTA_ODR = 0 ;

	while(1){
		PORTA_ODR = 1 ; 
		delay_ms(500);
		PORTA_ODR = 0 ;
		delay_ms(500);
	}
}


