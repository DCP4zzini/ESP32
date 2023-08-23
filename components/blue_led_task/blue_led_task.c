#include "blue_led_task.h"

extern QueueHandle_t Global_Queue;

void blink_blue_led(void * arg){

    struct messenger rx_led_queue = {0};

    gpio_config_t Blue_LED = {
    .intr_type = 0,
    .mode = GPIO_MODE_OUTPUT,
    .pin_bit_mask = 1 << 2,
    .pull_down_en = 0,
    .pull_up_en = 0,
    
    };

    gpio_config(&Blue_LED) != ESP_OK ? printf("Blue_LED gpio config failure") : printf("Blue_LED gpio config successfull");

    while(1){

        if(xQueueReceive(Global_Queue, (void *)&rx_led_queue, 500)){

            //Toggle LED according to red LED status;
            gpio_set_level(0x2, rx_led_queue.status ^ LED_ON);
            printf("Blue led id received : %u , status = %d \n\r", rx_led_queue.id, (int)rx_led_queue.status );
            vTaskDelay( 1000 / portTICK_PERIOD_MS);
        }else{
            printf("Queue receive failure");
        }

    }

}
