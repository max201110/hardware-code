# STM32 UART Echo

适用于 STM32CubeIDE 生成的 HAL 工程。将 `uart_echo.c` 加入工程，并在初始化 USART2 后调用 `App_UartEcho()`，即可把串口收到的字符原样回传。

请根据实际开发板修改 `huart2` 和波特率配置。
