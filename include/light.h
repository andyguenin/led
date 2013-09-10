#ifndef __LED_LIGHT_H__
#define __LED_LIGHT_H__

#include <color.h>

typedef struct led_light {
    int address;
    led_color* current;
} led_light;

led_light * led_light_alloc();
void led_light_free(led_light* light);
void led_light_change_color(led_light* light, led_color* color);

#endif
