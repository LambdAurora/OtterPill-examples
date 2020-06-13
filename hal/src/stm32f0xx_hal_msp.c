// Copyright 2020 the public domain. All rights reserved.

#include "main.h"

/**
 * Initializes the Global MSP.
 */
void HAL_MspInit(void)
{
    // Activates clocks.
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();
}

/**
 * Initializes the UART MSP.
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
    GPIO_InitTypeDef gpio_init_struct;

    // Part1: enable clocks.
    /* Enable GPIO TX/RX clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* Enable USART 1 clock */
    __HAL_RCC_USART1_CLK_ENABLE(); 

    // Part 2: configure GPIO.

    /* UART TX GPIO pin configuration  */
    gpio_init_struct.Pin       = USART1_TX_PIN;
    gpio_init_struct.Mode      = GPIO_MODE_AF_PP;
    gpio_init_struct.Pull      = GPIO_PULLUP;
    gpio_init_struct.Speed     = GPIO_SPEED_FREQ_HIGH;
    gpio_init_struct.Alternate = USART1_TX_AF;

    HAL_GPIO_Init(USART1_TX_GPIO_PORT, &gpio_init_struct);
    
    /* UART RX GPIO pin configuration  */
    gpio_init_struct.Pin = USART1_RX_PIN;
    gpio_init_struct.Alternate = USART1_RX_AF;

    HAL_GPIO_Init(USART1_RX_GPIO_PORT, &gpio_init_struct);
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart) {
    // Part 1: Reset peripherals.
    __HAL_RCC_USART1_FORCE_RESET();
    __HAL_RCC_USART1_RELEASE_RESET();

    // Part 2: disable peripherals and clocks.
    HAL_GPIO_DeInit(USART1_TX_GPIO_PORT, USART1_TX_PIN);
    HAL_GPIO_DeInit(USART1_RX_GPIO_PORT, USART1_RX_PIN);
}
