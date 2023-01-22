
#include "main.h"
#include "stm32f7xx_hal.h"
#include "stm32f769xx.h"



void SystemClock_Config(void);

int main(void){

	HAL_Init();
	
	
	SystemClock_Config();
	
	return 0;
}






void SystemClock_Config(void){
	
	
	RCC->CR |= RCC_CR_HSEON_Msk;
	while(!(RCC->CR & (1 << 17)));
	
	RCC->AHB1ENR |= RCC_APB1ENR_PWREN_Msk;
	PWR->CR1 |= PWR_CR1_VOS_Msk;
	
	FLASH->ACR |= FLASH_ACR_PRFTEN_Msk | FLASH_ACR_LATENCY_5WS;
	
	
	
	RCC->CFGR |= (RCC_CFGR_HPRE_DIV1) | (RCC_CFGR_PPRE1_DIV1) | (RCC_CFGR_PPRE2_DIV1);
	RCC->PLLCFGR |= (16 << 0) | (192 << 6) | RCC_PLLCFGR_PLLP_0;
	

}