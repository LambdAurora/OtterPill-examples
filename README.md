# OtterPill examples

This repository hosts some examples code for the OtterPill.

The examples include using CMake instead of make, examples with the [HAL drivers](https://github.com/STMicroelectronics/STM32CubeF0) and [libopencm3](https://github.com/libopencm3/libopencm3).

# Requirements

You need to have the GCC arm-none-eabi toolchain somewhere in your `PATH` or clang with a custom CMake toolchain file.
Don't forget to initialize the Git submodules.

# Compilation

Launch the setup script, it will create a new build directory and setup all the CMake stuff, cd into it and execute `make`.

# Flash

Using DFU, you can either flash the `.bin` files with `dfu-util` or you can use the corresponding `make` target.
Don't forget to put the OtterPill DFU mode.
