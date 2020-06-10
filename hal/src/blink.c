// This example is from https://github.com/Jan--Henrik/OtterPill/tree/master/Blink
// The differences are: some function names (I dislike PascalCase), CMake, HAL drivers are a Git submodule.
// And for some reasons, the ELF of this example has a text section a little bit larger??
#include "main.h"
#include <stdbool.h>

#define LED_PIN GPIO_PIN_13

/**
 * Setup the system clock.
 */
void setup_system_clock(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK
        | RCC_CLOCKTYPE_SYSCLK
        | RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
}

/**
 * Setup the GPIO.
 */
static void setup_gpio() {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // Let's initialize the blinking LED pin.
    HAL_GPIO_WritePin(GPIOB, LED_PIN, GPIO_PIN_RESET);

    // HAL GPIO initialization is a bit long honestly.
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

int main(void) {
    HAL_Init();
    setup_system_clock();

    setup_gpio();

    // Let the LED blinks forever every seconds.
    while (true) {
        HAL_GPIO_WritePin(GPIOB, LED_PIN, true);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOB, LED_PIN, false);
        HAL_Delay(1000);
    }
    return 0;
}
