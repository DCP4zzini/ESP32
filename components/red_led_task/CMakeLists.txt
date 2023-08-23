idf_component_register(SRCS "red_led_task.c"
                    INCLUDE_DIRS "include")
target_include_directories(${COMPONENT_TARGET} PUBLIC C:/Espressif/frameworks/esp-idf-v5.0.1/components/driver/include/driver/gpio.h)
