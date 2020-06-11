cmake_minimum_required(VERSION 3.12)
project(OtterPillExamples C CXX ASM)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(embedded/Otterpill)
include(utils/CompileUtility)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Generate compile flags.
generate_flags(COMPILE_FLAGS "native" 2 true)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}${COMPILE_FLAGS} -Wall -mcpu=cortex-m0 -lc -lm -lnosys -MMD -MP")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${COMPILE_FLAGS} -Wall -mcpu=cortex-m0")

set(STM32CubeF0_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/lib/STM32CubeF0")
set(libopencm3_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/lib/libopencm3")

add_subdirectory(hal)
