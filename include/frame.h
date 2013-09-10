#ifndef __LED_FRAME_H__
#define __LED_FRAME_H__

#include <light.h>
#include <color.h>

typedef struct 
{
  led_light*** lights;
  int rows;
  int cols;
} led_frame;

int led_frame_init(led_frame* f, int rows, int cols);
void led_frame_cleanup(led_frame* f);
led_light led_get_pixel(led_frame* f, int row, int col);

#endif
  
