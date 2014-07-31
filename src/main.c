#include "stm32f30x.h"
#include "stm32f3_discovery.h"

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

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
int main(void)
{  
  uint32_t ledStatus = 0;
  /* SysTick end of count event each 100ms */
  RCC_GetClocksFreq(&RCC_Clocks);
  SysTick_Config(RCC_Clocks.HCLK_Frequency / 10);
  
  /* Initialize LEDs and User Button available on STM32F3-Discovery board */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  STM_EVAL_LEDInit(LED7);
  STM_EVAL_LEDInit(LED8);
  STM_EVAL_LEDInit(LED9);
  STM_EVAL_LEDInit(LED10);
   
  /* Infinite loop */
  while (1)
  { 
	if(sysTickFlag == 1){
		sysTickFlag = 0;
		if(ledStatus == 1) {
			/* LEDs Off */
			STM_EVAL_LEDOff(LED3);
			STM_EVAL_LEDOff(LED6);
			STM_EVAL_LEDOff(LED7);
			STM_EVAL_LEDOff(LED4);
			STM_EVAL_LEDOff(LED10);
			STM_EVAL_LEDOff(LED8);
			STM_EVAL_LEDOff(LED9);
			STM_EVAL_LEDOff(LED5);
			ledStatus = 0;
		}else{
			/* LEDs Off */
			STM_EVAL_LEDOn(LED3);
			STM_EVAL_LEDOn(LED6);
			STM_EVAL_LEDOn(LED7);
			STM_EVAL_LEDOn(LED4);
			STM_EVAL_LEDOn(LED10);
			STM_EVAL_LEDOn(LED8);
			STM_EVAL_LEDOn(LED9);
			STM_EVAL_LEDOn(LED5);
			ledStatus = 1;
		}
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
