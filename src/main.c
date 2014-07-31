#include "stm32f30x.h"

/* Private variables ---------------------------------------------------------*/
RCC_ClocksTypeDef RCC_Clocks;
uint32_t sysTickFlag = 0;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	sysTickFlag = 1;
}

void init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;

	//Provide clock to GPIO
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
	//Initialize GPIO
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  // Output
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // Push Pull
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
int main(void)
{  
  /* SysTick end of count event each 100ms */
  RCC_GetClocksFreq(&RCC_Clocks);
  SysTick_Config(RCC_Clocks.HCLK_Frequency / 10);
  
  /* Initialize LEDs and User Button available on STM32F3-Discovery board */
  
  init();


  /* Infinite loop */
  while (1)
  { 
	if(sysTickFlag == 1){
		sysTickFlag = 0;
		GPIOE->ODR ^= 0xFFFF;
	}
  }
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
