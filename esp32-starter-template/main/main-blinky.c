#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN 5 //define the pin


void app_main(void)
{
  gpio_pad_select_gpio(PIN);  // optional, select the fact that your pin is an gpio and not a adc,etc
  gpio_set_direction(PIN, GPIO_MODE_OUTPUT); //input or outputb setting direction

  int isOn=0;

  while(true)
  {
    isOn =!isOn;
    gpio_set_level(PIN,isOn);
    vTaskDelay(1000/portTICK_PERIOD_MS);

  }

}
