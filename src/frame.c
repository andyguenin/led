#include <frame.h>
#include <stdlib.h>

int led_frame_init(led_frame* f, int rows, int cols)
{
  f = (led_frame*)(malloc(sizeof(led_frame)));
  led_lights** = (led_lights**)(malloc(rows*cols*sizeof(led_light)));

  return !f;
}

void led_frame_cleanup(led_frame* f)
{
  free(f);
}

 led_light led_get_pixel(led_frame* f, int row, int col)
{
  return f->lights[row][col];
}
