#ifndef FREERTOS_TEST_H
#define FREERTOS_TEST_H

#include <stdio.h>
#include "sdkconfig.h"

enum led_status{

    LED_ON = 0x1UL,
    LED_OFF = 0X02UL,
};

struct messenger {
    uint8_t id;
    char message_data[20];
    unsigned long status;
};

#endif // FREERTOS_TEST_H