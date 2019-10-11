/*
 * sensor.c
 *
 *  Created on: Sep 17, 2019
 *      Author: Alatif
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "sensor.h"
#include "device.h"

uint64_t timeMax=1000000;
uint64_t timeLoop;

uint8_t sensorDetected(void){
	uint8_t FlagDetect=0;
	timeLoop=0;
	if(HAL_GPIO_ReadPin(pbLeft_GPIO_Port,pbLeft_Pin)== GPIO_PIN_RESET) {
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(pbLeft_GPIO_Port,pbLeft_Pin)== GPIO_PIN_RESET) {
			while(HAL_GPIO_ReadPin(pbLeft_GPIO_Port,pbLeft_Pin)== GPIO_PIN_RESET && timeLoop++<=timeMax);
			if (timeLoop>timeMax){
				HAL_GPIO_WritePin(LED3_GPIO_PORT,led3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
				HAL_Delay(100);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
				HAL_Delay(100);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
				HAL_Delay(100);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
				HAL_Delay(100);
				HAL_GPIO_WritePin(LED3_GPIO_PORT,led3_Pin, GPIO_PIN_RESET);
			}

			else FlagDetect=1;


		}
	}
	return FlagDetect;
}

uint8_t counterReset(void){
	uint8_t FlagDetect=0;
	timeLoop=0;
	if(HAL_GPIO_ReadPin(pbCancel_GPIO_Port,pbCancel_Pin)== GPIO_PIN_RESET) {
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(pbCancel_GPIO_Port,pbCancel_Pin)== GPIO_PIN_RESET) {
			while(HAL_GPIO_ReadPin(pbCancel_GPIO_Port,pbCancel_Pin)== GPIO_PIN_RESET && timeLoop++<=timeMax);
			if (timeLoop>timeMax){
				HAL_GPIO_WritePin(LED4_GPIO_PORT, LED4_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
				HAL_Delay(1000);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
				HAL_Delay(100);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_SET);
				HAL_Delay(1000);
				HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin, GPIO_PIN_RESET);
				HAL_Delay(100);
				HAL_GPIO_WritePin(LED4_GPIO_PORT,LED4_PIN, GPIO_PIN_RESET);

			}

			else FlagDetect=1;

		}
	}
	return FlagDetect;
}
