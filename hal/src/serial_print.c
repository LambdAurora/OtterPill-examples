// Copyright 2020 the public domain. All rights reserved.

#include "serial_print.h"
#include <stdarg.h>
#include <stdio.h>

static UART_HandleTypeDef console_uart1h = {0};

// You could also modify the putchar function so you can use printf.
void print_console(const char* format, ... ) {
    va_list ap;
    uint8_t buffer[512]; // Maybe you wanna increase the length of that buffer.
    int n;
    va_start(ap, format);
    n = vsnprintf((char*) buffer, 512, format, ap);
    va_end(ap);
    if (HAL_UART_Transmit(&console_uart1h, (uint8_t*) buffer, n, 300) != HAL_OK) {
        //Error_Handler();
        // Using the error handler would be the best thing to do but it doesn't really matter in those examples.
    }
}

void init_uart1_console()
{
    console_uart1h.Instance        = USART1;
    console_uart1h.Init.BaudRate   = 115200;
    console_uart1h.Init.WordLength = UART_WORDLENGTH_8B;
    console_uart1h.Init.StopBits   = UART_STOPBITS_1;
    console_uart1h.Init.Parity     = UART_PARITY_NONE;
    console_uart1h.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
    console_uart1h.Init.Mode       = UART_MODE_TX_RX;

    HAL_UART_Init(&console_uart1h);
}
