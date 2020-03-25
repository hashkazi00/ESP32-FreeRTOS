#include <stdio.h>
#include <stdlib.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED1 5

void setup()
{
gpio_set_direction(LED1, GPIO_MODE_OUTPUT);
}

void loop()
{
    gpio_set_level(LED1,1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(LED1,0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

}

void app_main(void)
{
  setup();
  while (1)
  {
    loop();
  }
}
