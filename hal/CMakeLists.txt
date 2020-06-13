find_package(STM32CubeF0 REQUIRED)

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Wall -fdata-sections -ffunction-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdata-sections -ffunction-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdata-sections -ffunction-sections")

set_linker_script(${CMAKE_CURRENT_SOURCE_DIR}/STM32F072C8Tx_FLASH.ld)

include_directories(include ${STM32CubeF0_INCLUDE_DIRS})

# Sources
set(COMMON_SOURCES src/startup_stm32f072xb.s
    src/stm32f0xx_hal_msp.c
    src/stm32f0xx_it.c
    src/system_stm32f0xx.c
    src/common.c
    src/serial_print.c)

add_otterpill_executable(hal_blink ${STM32CubeF0_SOURCES} ${COMMON_SOURCES} src/blink.c)

add_otterpill_executable(hal_serial_print ${STM32CubeF0_SOURCES} ${COMMON_SOURCES} src/serial_print_main.c)
