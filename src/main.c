#include <color.h>
#include <light.h>
#include <frame.h>
#include <dfb.h>

#define NUM_COLS 6
#define NUM_ROWS 12

int init(led_dfb* dfb, int rows, int cols)
{
  led_color_init();
  return led_dfb_init(dfb, rows, cols);
}


int main()
{
  led_dfb* dfb;
  if(init(dfb, NUM_COLS, NUM_ROWS))
    {
      return -1;
    }

  led_dfb_cleanup(dfb);

  return 0;

}
