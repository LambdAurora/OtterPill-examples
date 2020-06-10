set(STM32CUBEF0_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../lib/STM32CubeF0")
get_filename_component(STM32CUBEF0_ROOT ${STM32CUBEF0_ROOT} ABSOLUTE)
set(HAL_DRIVER_ROOT "${STM32CUBEF0_ROOT}/Drivers/STM32F0xx_HAL_Driver")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Wall -fdata-sections -ffunction-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdata-sections -ffunction-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdata-sections -ffunction-sections")

set_linker_script(${CMAKE_CURRENT_SOURCE_DIR}/STM32F072C8Tx_FLASH.ld)

include_directories(include
    ${HAL_DRIVER_ROOT}/Inc
    ${HAL_DRIVER_ROOT}/Inc/Legacy
    ${STM32CUBEF0_ROOT}/Drivers/CMSIS/Device/ST/STM32F0xx/Include
    ${STM32CUBEF0_ROOT}/Drivers/CMSIS/Include)

# Sources
set(DRIVER_SOURCES ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_tim.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_tim_ex.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_rcc.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_rcc_ex.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_i2c.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_i2c_ex.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_gpio.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_dma.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_cortex.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_pwr.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_pwr_ex.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_flash.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_flash_ex.c
    ${HAL_DRIVER_ROOT}/Src/stm32f0xx_hal_exti.c)

set(COMMON_SOURCES src/startup_stm32f072xb.s
    src/stm32f0xx_hal_msp.c
    src/stm32f0xx_it.c
    src/system_stm32f0xx.c)

add_otterpill_executable(hal_blink ${DRIVER_SOURCES} ${COMMON_SOURCES} src/blink.c)
