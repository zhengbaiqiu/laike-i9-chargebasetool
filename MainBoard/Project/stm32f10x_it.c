/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 
#include "maindef.h"
#include "apiLib.h"
#include "Display.h"
extern u8 mDigitalTubeShow[];

 
void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

 
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
//void SVC_Handler(void)
//{
//}
 
void DebugMon_Handler(void)
{
}
 
//void PendSV_Handler(void)
//{
//}
 
//void SysTick_Handler(void)
//{
//}

/**
  * @brief  This function handles External lines 9 to 5 interrupt request.
  * @param  None
  * @retval None
  */
// void EXTI9_5_IRQHandler(void)
// {
// 	if(EXTI_GetITStatus(EXTI_Line9) != RESET)
// 	{
// 		if(mMaininf.mWork.mWorkGuideReceiveFlag == 1)
// 		{
// 			if(mMaininf.mWork.mWorkGuideFirstReceiveFlag == 0)
// 			{
// 				mMaininf.mSystem.mGuideReceiveTime = api_GetCurrentSystemTime();
// 				mMaininf.mWork.mWorkGuideFirstReceiveFlag = 1;
// 			}
// 			else
// 			{
// 				if((api_GetSystemTimePeriod(mMaininf.mSystem.mGuideReceiveTime) >= 8) && 
// 				   (api_GetSystemTimePeriod(mMaininf.mSystem.mGuideReceiveTime) <= 12))
// 				{
// 					mMaininf.mWork.mWorkGuideReceiveSuccessFlag = 1;
// 				}
// 				
// 				mMaininf.mSystem.mGuideReceiveTime = api_GetCurrentSystemTime();
// 			}
// 		}

// 		/* Clear the  EXTI line 9 pending bit */
// 		EXTI_ClearITPendingBit(EXTI_Line9);
// 	}
// 	
// 	if(EXTI_GetITStatus(EXTI_Line8) != RESET)
// 	{
// 		if(mMaininf.mWork.mWorkGuideReceiveFlag == 2)
// 		{
// 			if(mMaininf.mWork.mWorkGuideFirstReceiveFlag == 0)
// 			{
// 				mMaininf.mSystem.mGuideReceiveTime = api_GetCurrentSystemTime();
// 				mMaininf.mWork.mWorkGuideFirstReceiveFlag = 1;
// 			}
// 			else
// 			{
// 				if((api_GetSystemTimePeriod(mMaininf.mSystem.mGuideReceiveTime) >= 8) && 
// 				   (api_GetSystemTimePeriod(mMaininf.mSystem.mGuideReceiveTime) <= 12))
// 				{
// 					mMaininf.mWork.mWorkGuideReceiveSuccessFlag = 1;
// 				}
// 				
// 				mMaininf.mSystem.mGuideReceiveTime = api_GetCurrentSystemTime();
// 			}
// 		}

// 		/* Clear the  EXTI line 8 pending bit */
// 		EXTI_ClearITPendingBit(EXTI_Line8);
// 	}
// }

void EXTI15_10_IRQHandler(void)
{
 	if(EXTI_GetITStatus(EXTI_Line11) != RESET)//A
	{
		if(mMaininf.mWork.mWorkCheckGuideReceiveFlag == 1)//检测引导接收
		{
			api_GetAnalyzeGuideSignal(ENUM_GUIDE_LEFT);
			if(mMaininf.mWork.mGuideReceive[ENUM_GUIDE_LEFT].mGuideReceiveOkFlag == 1)
			{
				api_JudgeGuideSignal(ENUM_GUIDE_LEFT);
			}
		}

		/* Clear the  EXTI line 11 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line11);
	}
	if(EXTI_GetITStatus(EXTI_Line12) != RESET)//B
	{
		if(mMaininf.mWork.mWorkCheckGuideReceiveFlag == 1)//检测引导接收
		{
			api_GetAnalyzeGuideSignal(ENUM_GUIDE_RIGHT);
			if(mMaininf.mWork.mGuideReceive[ENUM_GUIDE_RIGHT].mGuideReceiveOkFlag == 1)
			{
				api_JudgeGuideSignal(ENUM_GUIDE_RIGHT);
			}
		}

		/* Clear the  EXTI line 11 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
	if(EXTI_GetITStatus(EXTI_Line15) != RESET)//TOP
	{
		if(mMaininf.mWork.mWorkCheckGuideReceiveFlag == 1)//检测引导接收
		{
			api_GetAnalyzeGuideSignal(ENUM_GUIDE_FRONT);
			if(mMaininf.mWork.mGuideReceive[ENUM_GUIDE_FRONT].mGuideReceiveOkFlag == 1)
			{
				api_JudgeGuideSignal(ENUM_GUIDE_FRONT);
			}
		}

		/* Clear the  EXTI line 11 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}

void TIM2_IRQHandler(void)        //1ms interrupt
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
	{
		/*        用于生成1ms滴答定时器          */
		mMaininf.mSystem.mSystemTick ++;
		if(mMaininf.mSystem.mSystemTick >= SYSTEMTIMEMAX) mMaininf.mSystem.mSystemTick = 0;
		
 		
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
}

void TIM3_IRQHandler(void)        //200us interrupt
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
	{
		mMaininf.mSystem.mSystem200usTick ++;
		if(mMaininf.mSystem.mSystem200usTick >= SYSTEMTIMEMAX) mMaininf.mSystem.mSystem200usTick = 0;
		

		if(mMaininf.mWork.mWorkCheckGuideReceiveFlag == 1)//检测引导接收
		{
			for(mMaininf.mWork.mWorkInitCont = 0;mMaininf.mWork.mWorkInitCont < 5;mMaininf.mWork.mWorkInitCont++)
			{
				//A信号
				if(mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalACountDownFlag == 1)
				{
					if(mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalACountDownTime > 0)
					{
						mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalACountDownTime --;
					}
					else
					{
						mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalACountDownFlag = 0;
					}
				}
				
				//B信号
				if(mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalBCountDownFlag == 1)
				{
					if(mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalBCountDownTime > 0)
					{
						mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalBCountDownTime --;
					}
					else
					{
						mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalBCountDownFlag = 0;
					}
				}
				
				//C信号
				if(mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalCCountDownFlag == 1)
				{
					if(mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalCCountDownTime > 0)
					{
						mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalCCountDownTime --;
					}
					else
					{
						mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mSignalCCountDownFlag = 0;
					}
				}
				
				//计时
				if(mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mTimeContLast > 0)
				{
					mMaininf.mWork.mGuideReceive[mMaininf.mWork.mWorkInitCont].mTimeContLast --;
				}
			}
		}
	}
	
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
}

void TIM4_IRQHandler(void)        //300ms interrupt
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)!=RESET)
	{
		if(mMaininf.mWork.mWorkLedTestFlag == 1)
		{
			mMaininf.mWork.mWorkLedFlag = ~mMaininf.mWork.mWorkLedFlag;
			
			if(mMaininf.mWork.mWorkLedFlag == 0)
			{
				api_Display_Data(mDigitalTubeShow[27],mDigitalTubeShow[21],mDigitalTubeShow[18],mDigitalTubeShow[26]);
			}
			else
			{
				api_Display_Data(mDigitalTubeShow[28],mDigitalTubeShow[18],mDigitalTubeShow[21],mDigitalTubeShow[25]);
			}
		}
		else
		{
			mMaininf.mWork.mWorkLedFlag = 0;
		}
	}
	
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}

void TIM5_IRQHandler(void)        //250us interrupt
{
//	float temp;
	
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)!=RESET)
	{
		
	}
	
	TIM_ClearITPendingBit(TIM5,TIM_IT_Update);
}

// void USART1_IRQHandler(void)
// {
// 	if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)     /*   接收数据   */
// 	{
// 		api_UART1_ReceiveData(USART_ReceiveData(USART1));
// 		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
// 	}
// 	if(USART_GetITStatus(USART1,USART_IT_TC)!=RESET)      /*   发送数据   */
// 	{
// 		if(mMaininf.mUart1.mSendSize > 0)
// 		{
// 			USART_SendData(USART1,mMaininf.mUart1.TxBuffer[mMaininf.mUart1.mSendCont ++]);
// 			if(mMaininf.mUart1.mSendCont == mMaininf.mUart1.mSendSize)
// 			{
// 				mMaininf.mUart1.mSendSize = 0;
// 				mMaininf.mUart1.mSendCont = 0;
// 				USART_ITConfig(USART1,USART_IT_TC,DISABLE);
// 				USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
// 			}
// 		}
// 		else
// 		{
// 			mMaininf.mUart1.mSendSize = 0;
// 			mMaininf.mUart1.mSendCont = 0;
// 			USART_ITConfig(USART1,USART_IT_TC,DISABLE);
// 			USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
// 		}
// 		USART_ClearITPendingBit(USART1,USART_IT_TC);
// 	}
// }

void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)     /*   接收数据   */
	{
		api_UART1_ReceiveData(USART_ReceiveData(USART1));
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
	if(USART_GetITStatus(USART1,USART_IT_TC)!=RESET)      /*   发送数据   */
	{
		if(mMaininf.mUart1.mSendSize > 0)
		{
			USART_SendData(USART1,mMaininf.mUart1.TxBuffer[mMaininf.mUart1.mSendCont ++]);
			if(mMaininf.mUart1.mSendCont == mMaininf.mUart1.mSendSize)
			{
				mMaininf.mUart1.mSendSize = 0;
				mMaininf.mUart1.mSendCont = 0;
				USART_ITConfig(USART1,USART_IT_TC,DISABLE);
				USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
			}
		}
		else
		{
			mMaininf.mUart1.mSendSize = 0;
			mMaininf.mUart1.mSendCont = 0;
			USART_ITConfig(USART1,USART_IT_TC,DISABLE);
			USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
		}
		USART_ClearITPendingBit(USART1,USART_IT_TC);
	}
}

void USART2_IRQHandler(void)
{
	if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)     /*   接收数据   */
	{
		api_UART2_ReceiveData(USART_ReceiveData(USART2));
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
	}
	if(USART_GetITStatus(USART2,USART_IT_TC)!=RESET)      /*   发送数据   */
	{
		if(mMaininf.mUart2.mSendSize > 0)
		{
			USART_SendData(USART2,mMaininf.mUart2.TxBuffer[mMaininf.mUart2.mSendCont ++]);
			if(mMaininf.mUart2.mSendCont == mMaininf.mUart2.mSendSize)
			{
				mMaininf.mUart2.mSendSize = 0;
				mMaininf.mUart2.mSendCont = 0;
				USART_ITConfig(USART2,USART_IT_TC,DISABLE);
				USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
			}
		}
		else
		{
			mMaininf.mUart2.mSendSize = 0;
			mMaininf.mUart2.mSendCont = 0;
			USART_ITConfig(USART2,USART_IT_TC,DISABLE);
			USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
		}
		USART_ClearITPendingBit(USART2,USART_IT_TC);
	}
}

// void USART3_IRQHandler(void)
// {
// 	if(USART_GetITStatus(USART3,USART_IT_RXNE)!=RESET)     /*   接收数据   */
// 	{
// 		//mMaininf.mWork.mWorkBigUartFlag = 1;
// 		USART_ClearITPendingBit(USART3,USART_IT_RXNE);
// 	}
// 	if(USART_GetITStatus(USART3,USART_IT_TC)!=RESET)      /*   发送数据   */
// 	{
// 		USART_ClearITPendingBit(USART1,USART_IT_TC);
// 	}
// }

// void UART4_IRQHandler(void)
// {
// 	if(USART_GetITStatus(UART4,USART_IT_RXNE)!=RESET)     /*   接收数据   */
// 	{
// 		api_UART4_ReceiveData(USART_ReceiveData(UART4));
// 		USART_ClearITPendingBit(UART4,USART_IT_RXNE);
// 	}
// 	if(USART_GetITStatus(UART4,USART_IT_TC)!=RESET)      /*   发送数据   */
// 	{
// 		if(mMaininf.mUart4.mSendSize > 0)
// 		{
// 			USART_SendData(UART4,mMaininf.mUart4.TxBuffer[mMaininf.mUart4.mSendCont ++]);
// 			if(mMaininf.mUart4.mSendCont == mMaininf.mUart4.mSendSize)
// 			{
// 				mMaininf.mUart4.mSendSize = 0;
// 				mMaininf.mUart4.mSendCont = 0;
// 				USART_ITConfig(UART4,USART_IT_TC,DISABLE);
// 				USART_ITConfig(UART4,USART_IT_RXNE,ENABLE);
// 			}
// 		}
// 		else
// 		{
// 			mMaininf.mUart4.mSendSize = 0;
// 			mMaininf.mUart4.mSendCont = 0;
// 			USART_ITConfig(UART4,USART_IT_TC,DISABLE);
// 			USART_ITConfig(UART4,USART_IT_RXNE,ENABLE);
// 		}
// 		USART_ClearITPendingBit(UART4,USART_IT_TC);
// 	}
// }

// void UART5_IRQHandler(void)
// {
// 	if(USART_GetITStatus(UART5,USART_IT_RXNE)!=RESET)     /*   接收数据   */
// 	{
// 		api_UART5_ReceiveData(USART_ReceiveData(UART5));
// 		USART_ClearITPendingBit(UART5,USART_IT_RXNE);
// 	}
// 	if(USART_GetITStatus(UART5,USART_IT_TC)!=RESET)      /*   发送数据   */
// 	{
// 		if(mMaininf.mUart5.mSendSize > 0)
// 		{
// 			USART_SendData(UART5,mMaininf.mUart5.TxBuffer[mMaininf.mUart5.mSendCont ++]);
// 			if(mMaininf.mUart5.mSendCont == mMaininf.mUart5.mSendSize)
// 			{
// 				mMaininf.mUart5.mSendSize = 0;
// 				mMaininf.mUart5.mSendCont = 0;
// 				USART_ITConfig(UART5,USART_IT_TC,DISABLE);
// 				USART_ITConfig(UART5,USART_IT_RXNE,ENABLE);
// 			}
// 		}
// 		else
// 		{
// 			mMaininf.mUart5.mSendSize = 0;
// 			mMaininf.mUart5.mSendCont = 0;
// 			USART_ITConfig(UART5,USART_IT_TC,DISABLE);
// 			USART_ITConfig(UART5,USART_IT_RXNE,ENABLE);
// 		}
// 		USART_ClearITPendingBit(UART5,USART_IT_TC);
// 	}
// }

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
