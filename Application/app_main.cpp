#include "app_main.h"
#include <stdio.h>

int app_main(void) {
	int q = 0;
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
		HAL_Delay(100);
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		printf("\033[38;5;206;52mHello\033[0m");
		printf("\033[1m LD1: \033[0m %d  %d \r\n", HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13),q++);
	}
}

/*
 * The primitives __putchar and __getchar are defined as weak in the system startup
 * Defining versions here lets you connect STDIO functions like gets and printf
 * to a specific device
 */

extern "C" {

// these two are needed
int __io_putchar(int ch) {
	// Code to write character 'ch' on the UART
	return HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, 0xFFFF);
}

int __io_getchar() {
	// Code to read a character from the UART
	uint8_t in;
	HAL_UART_Receive(&huart1, &in, 1, 1000);
	return in;
}

// not so sure about these
int __putchar(int ch) {
	return __io_putchar(ch);
}

int __getchar() {
	return __io_getchar();
}


}
