#include <dfb.h>
#include <stdlib.h>

int led_dfb_init(led_dfb* dfb, int rows, int cols)
{
  dfb = (led_dfb*)(malloc(sizeof(led_dfb)));
  if(!dfb)
    return -1;
  led_frame *active, *behind;
  if(!led_frame_init(active, rows, cols) || !led_frame_init(behind, rows, cols))
    return -1;
  *dfb = (led_dfb){active, behind, 0};
  return 0;
}

int led_dfb_cleanup(led_dfb* dfb)
{
  led_frame_cleanup(dfb->active);
  led_frame_cleanup(dfb->behind);
}

void led_frame_copy_active(led_dfb* dfb)
{
  led_frame* active = dfb->active;
  led_frame* behind = dfb->behind;

  int r,c;
  for(r=0;r<active->rows&&r<behind->rows;++r)
    {
      for(c=0;c<active->cols&&r<behind->rows;++c)
	{
	  behind->lights[r][c] = active->lights[r][c];
	}
    }
}


void led_frame_switch(led_dfb* dfb)
{
  led_frame* temp = dfb->active;
  dfb->active = dfb->behind;
  dfb->behind = temp;  
}
