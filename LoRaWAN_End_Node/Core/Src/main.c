#include "main.h"
#include "app_lorawan.h"
#include "usart.h"
#include <stdio.h>
#include "string.h"

UART_HandleTypeDef huart1;
TIM_HandleTypeDef htim2;
char buffer[50];

uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2, Presence = 0;
uint16_t SUM, RH, TEMP;

typedef struct
{
	float Temperature;
	float Humidity;
}DHT_DataTypedef;

DHT_DataTypedef DHT11_Data;

void SystemClock_Config(void);
static void MX_TIM2_Init(void);
static void MX_GPIO_Init(void);
void DHT11_GetData(DHT_DataTypedef *DHT_Data);

uint32_t DWT_Delay_Init(void)
{
	/* Disable TRC */
	CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk; // ~0x01000000;
	/* Enable TRC */
	CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk; // 0x01000000;

	/* Disable clock cycle counter */
	DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk; //~0x00000001;
	/* Enable  clock cycle counter */
	DWT->CTRL |=  DWT_CTRL_CYCCNTENA_Msk; //0x00000001;

	/* Reset the clock cycle counter value */
	DWT->CYCCNT = 0;

	/* 3 NO OPERATION instructions */
	__ASM volatile ("NOP");
	__ASM volatile ("NOP");
	__ASM volatile ("NOP");

	/* Check if clock cycle counter has started */
	if(DWT->CYCCNT)
	{
		return 0; /*clock cycle counter started*/
	}
	else
	{
		return 1; /*clock cycle counter not started*/
	}
}

__STATIC_INLINE void delay(volatile uint32_t microseconds)
{
	uint32_t clk_cycle_start = DWT->CYCCNT;

	/* Go to number of cycles for system */
	microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);

	/* Delay till end */
	while ((DWT->CYCCNT - clk_cycle_start) < microseconds);
}

void Set_Pin_Output(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	// or it could be PULLDOWN if dosent work with PULLUP------------------------- note
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void DHT11_Start(void)
{
	DWT_Delay_Init();
	//SIG connected to PB10 (Digital)
	Set_Pin_Output(GPIOB, GPIO_PIN_10);           // set the pin as output
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);    // pull the pin low
	delay(18000);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);   // pull the pin high
	delay(20);
	Set_Pin_Input(GPIOB, GPIO_PIN_10);            // set as input

	sprintf(buffer,"Start done\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

uint8_t DHT11_Check_Response(void)
{
	uint8_t response = 0;
	delay(40);
	if (!(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)))
	{
		delay(80);
		if ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10))) response = 1;
		else response = -1;                         // 255
	}
	while ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)));   // wait for the pin to go low

	sprintf(buffer,"Received response\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

	return response;
}

uint8_t DHT11_Read(void)
{
	uint8_t i, j;					   // "i" is our desiered value = one bit of DHT11 payload in each time the function will be called

	for (j = 0; j < 8; j++)                                  //Loop executes 8 times to receive 8 bits payload so each time function called 8 bit of data will be read
	{
		while (!(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)));   // wait for the pin to go high
		delay (50);   // wait for 40 us
		if (!(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)))       // if the pin is low
		{
			i&= ~(1<<(7-j));                             // write 0    (These are bitwise operators. Means write left bit of "j" to right bit of "i")
		}
		else {
			i|= (1<<(7-j));                                 // if the pin is high, write 1
		}
	}

	return i;
}

void DHT11_GetData (DHT_DataTypedef *DHT_Data)
{
	DHT11_Start();
	Presence = DHT11_Check_Response();
	Rh_byte1 = DHT11_Read ();
	Rh_byte2 = DHT11_Read ();
	Temp_byte1 = DHT11_Read ();
	Temp_byte2 = DHT11_Read ();
	SUM = DHT11_Read();

	sprintf(buffer,"Completed read\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);


	sprintf(buffer,"Values are %d %d %d %d\r\n", Temp_byte1, Temp_byte2, Rh_byte1, Rh_byte2);
	HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

	if (SUM == (Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2))
	{
		DHT_Data->Temperature = Temp_byte1;
		DHT_Data->Humidity = Rh_byte1;
	}
}

/*
 * radio_board_if.c, originally ctrl3
#elif defined(MX_NUCLEO_WL55JC1)
  RF_SW_CTRL1_GPIO_CLK_ENABLE();
  ctrl3
 */

int main(void)
{
	HAL_Init();

	SystemClock_Config();

	MX_GPIO_Init();
	//MX_LoRaWAN_Init();
	MX_USART1_UART_Init();
	MX_TIM2_Init();
	HAL_TIM_Base_Start(&htim2);

	sprintf(buffer,"Initialization complete\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

	while (1)
	{
		/*
		 * LoRaWan works only via STM32CubeProgrammer, otherwise cannot debug via IDE
		 * */
		//MX_LoRaWAN_Process();

		//red LED
		//HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);

		DHT11_GetData(&DHT11_Data);

		sprintf(buffer,"Temperature: %f \r\n Humidity: %f\n\r", DHT11_Data.Temperature, DHT11_Data.Humidity);
		HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

		delay(3000000);
	}
}

static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);

	/*Configure GPIO pin : Button_Pin */
	GPIO_InitStruct.Pin = BUT1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(BUT1_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : LED_Pin PB5 */
	GPIO_InitStruct.Pin = GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin : PB10 */
	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

static void MX_TIM2_Init(void)
{

	TIM_SlaveConfigTypeDef sSlaveConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 80-1;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 4294967295;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
	sSlaveConfig.SlaveMode = TIM_SLAVEMODE_DISABLE;
	sSlaveConfig.InputTrigger = TIM_TS_ITR0;
	if (HAL_TIM_SlaveConfigSynchro(&htim2, &sSlaveConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}

}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure LSE Drive Capability
	 */
	__HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
	/** Configure the main internal regulator output voltage
	 */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	RCC_OscInitStruct.MSIState = RCC_MSI_ON;
	RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK3|RCC_CLOCKTYPE_HCLK
			|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
			|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.AHBCLK3Divider = RCC_SYSCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
}

void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
	while (1)
	{
	}
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
