
#include "red_led_task.h"

extern QueueHandle_t Global_Queue;

void blink_red_led(void * arg){

    bool red_led_toggle = true;

    struct messenger msg_sender = { };

    /* GPIO Init */
    gpio_config_t Red_LED = {
    .intr_type = 0,
    .mode = GPIO_MODE_OUTPUT,
    .pin_bit_mask = 1 << 0,
    .pull_down_en = 0,
    .pull_up_en = 0,
    
    };
    gpio_config(&Red_LED);

    while(1){

        red_led_toggle ^= 0x1;
        gpio_set_level(0x0, red_led_toggle);
        msg_sender.id += 1;
        sprintf(msg_sender.message_data, "Red LED %s", red_led_toggle == true ? "ON" : "OFF" );
        if(red_led_toggle == true){
            msg_sender.status |= LED_ON;
        }else{
            msg_sender.status &= ~LED_ON;
        }

        if(xQueueSend(Global_Queue, (void *)&msg_sender , (TickType_t)0)){
            
            printf("%s,",msg_sender.message_data);
            printf("status = %d\n\r",(int)msg_sender.status );
            vTaskDelay( 1000 / portTICK_PERIOD_MS);
        }
        
    }
    
}
