// Copyright 2020 the public domain. All rights reserved.

#ifndef SERIAL_PRINT_H
#define SERIAL_PRINT_H

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Prints to the console through UART.
 * 
 * Replacement for printf.
 */
void print_console(const char* format, ... );

/**
 * Initializes the UART1 for the console.
 */
void init_uart1_console();

#ifdef __cplusplus
}
#endif

#endif // SERIAL_PRINT_H
