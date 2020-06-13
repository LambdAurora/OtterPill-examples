// Copyright 2020 the public domain. All rights reserved.

#ifndef __MAIN_H
#define __MAIN_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Definition for USARTx Pins */
// TX -> PA9
// RX -> PA10
#define USART1_TX_PIN                    GPIO_PIN_9
#define USART1_TX_GPIO_PORT              GPIOA
#define USART1_TX_AF                     GPIO_AF1_USART1
#define USART1_RX_PIN                    GPIO_PIN_10
#define USART1_RX_GPIO_PORT              GPIOA
#define USART1_RX_AF                     GPIO_AF1_USART1

/* Exported functions prototypes */
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
