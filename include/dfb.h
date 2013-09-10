#ifndef __DFB_H__
#define __DFB_H__

#include <frame.h>

typedef struct led_dfb
{
  led_frame* active;
  led_frame* behind;
  int time_switch;
} led_dfb;


int led_dfb_init(led_dfb* dfb, int rows, int cols);
int led_dfb_cleanup(led_dfb* dfb);
void led_frame_copy_active(led_dfb* dfb);
void led_frame_switch(led_dfb* dfb);


#endif
