// Copyright 2020 the public domain. All rights reserved.

#include "serial_print.h"

int main(void) {
    HAL_Init();
    setup_system_clock();

    init_uart1_console();

    print_console("Initialized!\r\n");

    static char* RANDOM_MESSAGES[] = { "Hello world!\r\n", 
        "Serial print through the Otterpill!\r\n",
        "Baud rate: 115200\r\n",
        "The maximum buffer size is 512.\r\n",
        "TX -> PA9 | RX -> PA10\r\n"};

    int i = 0;
    while (1) {
        print_console(RANDOM_MESSAGES[i]);

        HAL_Delay(500);

        i++;
        if (i >= 5)
            i = 0;
    }

    return 0;
}
