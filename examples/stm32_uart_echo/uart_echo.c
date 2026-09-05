/* STM32 HAL UART echo snippet.
 * Add this to a CubeIDE-generated project after MX_USART2_UART_Init(). */
#include "main.h"
#include <string.h>

extern UART_HandleTypeDef huart2;

void App_UartEcho(void)
{
    uint8_t byte;
    const char banner[] = "STM32 UART ready\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t *)banner, strlen(banner), 100);
    while (1) {
        if (HAL_UART_Receive(&huart2, &byte, 1, HAL_MAX_DELAY) == HAL_OK) {
            HAL_UART_Transmit(&huart2, &byte, 1, 100);
        }
    }
}
