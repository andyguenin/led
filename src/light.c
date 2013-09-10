#include <light.h>
#include <stdlib.h>

led_light* led_light_alloc()
{
  return (led_light*)(malloc(sizeof(led_color)));
}

void led_light_free(led_light* light)
{
  free(light);
}

void led_light_change_color(led_light* light, led_color* color)
{
  light->current = color;
  
}
