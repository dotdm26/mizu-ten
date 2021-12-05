/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Examples_LL/I2C/I2C_OneBoard_Communication_IT_Init/Src/stm32wlxx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32wlxx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */

  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32WLxx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32wlxx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI Line 0 Interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_0) != RESET)
  {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
    /* USER CODE BEGIN LL_EXTI_LINE_0 */

    UserButton_Callback();

    /* USER CODE END LL_EXTI_LINE_0 */
  }
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  /* USER CODE END EXTI0_IRQn 1 */
}

/* USER CODE BEGIN 1 */
/**
  * Brief   This function handles I2C2 (Slave) event interrupt request.
  * Param   None
  * Retval  None
  */
void I2C2_EV_IRQHandler(void)
{
  /* Check ADDR flag value in ISR register */
if (LL_I2C_IsActiveFlag_ADDR(I2C2))
{
  /* Verify the Address Match with the OWN Slave address */
  if (LL_I2C_GetAddressMatchCode(I2C2) == SLAVE_OWN_ADDRESS)
  {
    /* Verify the transfer direction, a read direction, Slave enters transmitter mode */
    if (LL_I2C_GetTransferDirection(I2C2) == LL_I2C_DIRECTION_READ)
    {
      /* Clear ADDR flag value in ISR register */
      LL_I2C_ClearFlag_ADDR(I2C2);

      /* Enable Transmit Interrupt */
      LL_I2C_EnableIT_TX(I2C2);
    }
    else
    {
      /* Clear ADDR flag value in ISR register */
      LL_I2C_ClearFlag_ADDR(I2C2);

      /* Call Error function */
      Error_Callback();
    }
  }
  else
  {
    /* Clear ADDR flag value in ISR register */
    LL_I2C_ClearFlag_ADDR(I2C2);

    /* Call Error function */
    Error_Callback();
  }
}
/* Check NACK flag value in ISR register */
else if (LL_I2C_IsActiveFlag_NACK(I2C2))
{
  /* End of Transfer */
  LL_I2C_ClearFlag_NACK(I2C2);
}
/* Check TXIS flag value in ISR register */
else if (LL_I2C_IsActiveFlag_TXIS(I2C2))
{
  /* Call function Slave Ready to Transmit Callback */
  Slave_Ready_To_Transmit_Callback();
}
/* Check STOP flag value in ISR register */
else if (LL_I2C_IsActiveFlag_STOP(I2C2))
{
  /* Clear STOP flag value in ISR register */
  LL_I2C_ClearFlag_STOP(I2C2);

  /* Check TXE flag value in ISR register */
  if (!LL_I2C_IsActiveFlag_TXE(I2C2))
  {
    /* Flush the TXDR register */
    LL_I2C_ClearFlag_TXE(I2C2);
  }
}
/* Check TXE flag value in ISR register */
else if (!LL_I2C_IsActiveFlag_TXE(I2C2))
{
  /* Do nothing */
  /* This Flag will be set by hardware when the TXDR register is empty */
  /* If needed, use LL_I2C_ClearFlag_TXE() interface to flush the TXDR register  */
}
else
{
  /* Call Error function */
  Error_Callback();
}
}

/**
  * Brief   This function handles I2C2 (Slave) error interrupt request.
  * Param   None
  * Retval  None
  */
void I2C2_ER_IRQHandler(void)
{
  /* Call Error function */
  Error_Callback();
}

/**
  * Brief   This function handles I2C3 (Master) interrupt request.
  * Param   None
  * Retval  None
  */
void I2C3_EV_IRQHandler(void)
{
  /* Check RXNE flag value in ISR register */
if (LL_I2C_IsActiveFlag_RXNE(I2C3))
{
  /* Call function Master Reception Callback */
  Master_Reception_Callback();
}
/* Check STOP flag value in ISR register */
else if (LL_I2C_IsActiveFlag_STOP(I2C3))
{
  /* End of Transfer */
  LL_I2C_ClearFlag_STOP(I2C3);

  /* Call function Master Complete Callback */
  Master_Complete_Callback();
}
else
{
  /* Call Error function */
  Error_Callback();
}
}

/**
  * Brief   This function handles I2C3 (Master) error interrupt request.
  * Param   None
  * Retval  None
  */
void I2C3_ER_IRQHandler(void)
{
  /* Call Error function */
  Error_Callback();
}


/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/