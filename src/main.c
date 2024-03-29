/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"


//=========================================================================================//
//====================================== Private Variables ================================//
//=========================================================================================//
//some macros
#define TRUE 1
#define FALSE 0
#define AVAILABLE TRUE
#define NOT_AVAILABLE FALSE
uint8_t UART_ACCESS_KEY = AVAILABLE;

TaskHandle_t xTaskHandle1, xTaskHandle2;


//=========================================================================================//
//====================================== Private Functions ================================//
//=========================================================================================//
void vTask1_handler(void *params);
void vTask2_handler(void *params);
static void prvSetupHardware(void);
static void prvSetupUart(void);
void printmsg(char *msg);



int main(void)
{

	prvSetupHardware();


	xTaskCreate(
				vTask1_handler,
				"Task-1",
				configMINIMAL_STACK_SIZE,
				NULL,
				2,
				&xTaskHandle1);

	xTaskCreate(
				vTask2_handler,
				"Task-1",
				configMINIMAL_STACK_SIZE,
				NULL,
				2,
				&xTaskHandle2);

	vTaskStartScheduler();

	for(;;);
}


void vTask1_handler(void *params)
{
	//traceTASK_SWITCHED_IN();
	while(1)
	{
		if(UART_ACCESS_KEY == AVAILABLE)
		{
			UART_ACCESS_KEY = NOT_AVAILABLE;
			printmsg("Hello-world: From Task-1\r\n");
			UART_ACCESS_KEY = AVAILABLE;
			taskYIELD();
		}

	}

}



void vTask2_handler(void *params)
{
	while(1)
	{
		if(UART_ACCESS_KEY == AVAILABLE)
		{
			UART_ACCESS_KEY = NOT_AVAILABLE;
			printmsg("Hello-world: From Task-2\r\n");
			UART_ACCESS_KEY = AVAILABLE;
			taskYIELD();
		}
	}
}

static void prvSetupUart(void)
{
	GPIO_InitTypeDef gpio_uart_pins;
	USART_InitTypeDef uart2_init;

	//1. Enable the UART2  and GPIOA Peripheral clock
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	//PA2 is UART2_TX, PA3 is UART2_RX

	//2. Alternate function configuration of MCU pins to behave as UART2 TX and RX

	//zeroing each and every member element of the structure
	memset(&gpio_uart_pins,0,sizeof(gpio_uart_pins));

	gpio_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	gpio_uart_pins.GPIO_Mode = GPIO_Mode_AF;
	gpio_uart_pins.GPIO_PuPd = GPIO_PuPd_UP;
	gpio_uart_pins.GPIO_OType= GPIO_OType_PP;
	gpio_uart_pins.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOA, &gpio_uart_pins);


	//3. AF mode settings for the pins
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); //PA2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); //PA3

	//4. UART parameter initializations
	//zeroing each and every member element of the structure
	memset(&uart2_init,0,sizeof(uart2_init));

	uart2_init.USART_BaudRate = 115200;
	uart2_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	uart2_init.USART_Mode =  USART_Mode_Tx | USART_Mode_Rx;
	uart2_init.USART_Parity = USART_Parity_No;
	uart2_init.USART_StopBits = USART_StopBits_1;
	uart2_init.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2,&uart2_init);


	//5. Enable the UART2 peripheral
	USART_Cmd(USART2,ENABLE);

}

static void prvSetupHardware(void)
{
	//setup UART2
	prvSetupUart();
}

void printmsg(char *msg)
{
	for(uint32_t i=0; i < strlen(msg); i++)
	{
		while ( USART_GetFlagStatus(USART2,USART_FLAG_TXE) != SET);
		USART_SendData(USART2,msg[i]);
	}

	while ( USART_GetFlagStatus(USART2,USART_FLAG_TC) != SET);

}
