
#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "esp_task_wdt.h"
#include "blue_led_task.h"
#include "red_led_task.h"
#include "freeRTOS_test.h"

QueueHandle_t Global_Queue = NULL;

void app_main(void){

    // Global Queue creation
    Global_Queue = xQueueCreate(10, sizeof(struct messenger));

    // Tasks creation
    xTaskCreate(&blink_red_led, "blink_red_led", 2048 , NULL , 2, NULL);
    xTaskCreate(&blink_blue_led, "blink_blue_led", 2048 , NULL , 2, NULL);

    for(;;);
}
