#include <stdio.h>
#include <stdlib.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED1 5
#define LED2 2

typedef struct {
  int led;
  int time;
 
} LEDParams;

void setup()
{
gpio_set_direction(LED1, GPIO_MODE_OUTPUT);
gpio_set_direction(LED2, GPIO_MODE_OUTPUT);
}

void BlinkLED1(void *params)
{
  LEDParams *l = (LEDParams*) params;

    while(true)
    {
    gpio_set_level(l->led,1);
    vTaskDelay(l->time / portTICK_RATE_MS);
    gpio_set_level(l->led,0);
    vTaskDelay(l->time / portTICK_RATE_MS);
    }
}


void app_main(void)
{ 
  LEDParams ledparams1 ={
    .led=LED1,
    .time = 1000
  };

  LEDParams ledparams2 ={
    .led=LED2,
    .time = 100
  };


  setup();
  xTaskCreate(BlinkLED1,"ledone",1024 * 2,&ledparams1,2,NULL);
  xTaskCreate(BlinkLED1,"ledtwo",1024 * 2,&ledparams2,1,NULL);

  while (true)
  {
    vTaskDelay(1000 / portTICK_RATE_MS);
  }
  

}
