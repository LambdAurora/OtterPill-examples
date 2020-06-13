// Copyright 2020 the public domain. All rights reserved.

#ifndef __COMMON_H
#define __COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f0xx_hal.h>

/**
 * Setup the system clock.
 */
void setup_system_clock(void);

#ifdef __cplusplus
}
#endif

#endif // __COMMON_H
