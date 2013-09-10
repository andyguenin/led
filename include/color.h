#ifndef __LED_COLOR_H__
#define __LED_COLOR_H__

typedef unsigned char level;
typedef struct led_color 
{
  char red;
  char green;
  char blue;
} led_color;

int led_color_init();
void led_color_destroy();
led_color * led_get_color(level r, level g, level b);
led_color * led_delta_color(led_color* c, level r, level g, level b);

#endif
