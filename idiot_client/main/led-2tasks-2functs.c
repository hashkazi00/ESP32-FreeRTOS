#include <stdio.h>
#include <stdlib.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED1 5
#define LED2 2

void setup()
{
gpio_set_direction(LED1, GPIO_MODE_OUTPUT);
gpio_set_direction(LED2, GPIO_MODE_OUTPUT);
}

void task1(void *params)
{
    while(true)
    {
    gpio_set_level(LED1,1);
    vTaskDelay(1000 / portTICK_RATE_MS);
    gpio_set_level(LED1,0);
    vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void task2(void *params)
{
    while(true)
    {
    gpio_set_level(LED2,1);
    vTaskDelay(500 / portTICK_RATE_MS);
    gpio_set_level(LED2,0);
    vTaskDelay(500 / portTICK_RATE_MS);
    }
}


void app_main(void)
{
  setup();
  xTaskCreate(task1,"ledone",1024 * 2,NULL,2,NULL);
  xTaskCreate(task2,"ledone",1024 * 2,NULL,2,NULL);
}
