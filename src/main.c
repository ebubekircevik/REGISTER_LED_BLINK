#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void CLK_Config()
{
	RCC->CR |= 0x00030000; // HSEON and HSEONRDY enable
	RCC->CR |= 0x00080000; //CSS enable
	RCC->PLLCFGR |= 0x00040000; // PLL e HSE sectik
	RCC->PLLCFGR |= 0x00000004; // PLL M=4
	RCC->PLLCFGR |= 0x00005A00; // PLL N = 168
	RCC->PLLCFGR |= 0x00000000; // PLL P =2
	RCC->CFGR |= 0x00000000;    //AHB Prescaler =1
	RCC->CFGR |= 0x00080000;    //AHB Prescaler =2
	RCC->CFGR |= 0x00001400;    //AHB Prescaler =4
	RCC->CIR |= 0x00080000;     //HSERDY Flag clear
	RCC->CIR |= 0x00800000;     //CSS Flag clear
}

void GPIO_Config()
{
	RCC->AHB1ENR = 0x00000008; //GPIOD Portu Aktif Edildi !
	GPIOD->MODER = 0x55000000; //PD15, PD14, PD13, PD12 P�NLER� AKT�F ED�LD� !
	GPIOD->OTYPER = 0x00000000; //PD15, PD14, PD13, PD12 P�NLER� output push-pull OLARAK AYARLANDI
	GPIOD->OSPEEDR = 0xFF000000; //PD15, PD14, PD13, PD12 P�NLER�NIN CALI�MA HIZI Very high speed OLARAK AYARLANDI
	GPIOD->PUPDR = 0x00000000; //PD15, PD14, PD13, PD12 P�NLER� No pull-up, pull-down OLARAK AYARLANDI


}

void delay(uint32_t time){
	while(time--);
}

int main(void)
{
	CLK_Config();
	GPIO_Config();

  while (1)
  {
	  GPIOD->ODR = 0x0000F000; //PD15, PD14, PD13, PD12 PINLER� LOJ�K 1 YAPILDI.
	  delay(16800000);
	  GPIOD->ODR = 0x00000000; //PD15, PD14, PD13, PD12 PINLER� LOJ�K 0 YAPILDI.
	  delay(16800000);
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
