#ifndef BLUE_LED_TASK_H
#define BLUE_LED_TASK_H

#include "C:\Espressif\frameworks\esp-idf-v5.0.1\components\driver\include\driver\gpio.h"
#include "C:\Espressif\frameworks\esp-idf-v5.0.1\components\freertos\FreeRTOS-Kernel\include\freertos\FreeRTOS.h"
#include "freertos/queue.h"
#include <stdio.h>
#include <stdbool.h>
#include "C:\Espressif\frameworks\esp-idf-v5.0.1\workspace\freeRTOS_tests\freeRTOS_test\main\freeRTOS_test.h"

void blink_blue_led(void * arg);

#endif // BLUE_LED_TASK_H