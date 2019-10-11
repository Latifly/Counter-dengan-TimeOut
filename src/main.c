
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "device.h"
#include "hardwareinit.h"
#include "sensor.h"
#include "counter.h"
			
UART_HandleTypeDef huart2;
uint16_t count;
//void beep1(void);
//void beep2(void);


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	while(1){
        counterShow();
        if(sensorDetected()){
        	CounterUpdate();
        }



        if(counterReset()){
        	count=0;
        }

	}
}

//
//void beep1(void){
//	HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
//	HAL_Delay(100);
//	HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
//	HAL_Delay(100);
//	HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
//	HAL_Delay(100);
//	HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
//	HAL_Delay(100);
//}
//
//void beep2(void){
//	HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
//		HAL_Delay(1000);
//		HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
//		HAL_Delay(100);
//		HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
//		HAL_Delay(1000);
//		HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
//		HAL_Delay(100);
//
//}
