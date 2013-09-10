#include <color.h>
#include <stdlib.h>

led_color* cache[256][256][256];

int led_color_init()
{
  int i,j,k;
  for(i=0;i<256;++i)
    {
      for(j=0;j<256;++j)
	{
	  for(k=0;k<256;++k)
	    {
	      led_color* col = (led_color*)(malloc(sizeof(led_color)));
	      if(!col)
		return -1;
	      *col = (led_color){i,j,k};
	      cache[i][j][k] = col;
	    }
	}
    }
  return 0;
}

void led_color_destroy()
{
  int i,j,k;
  for(i=0;i<256;++i)
    {
      for(j=0;j<256;++j)
	{
	  for(k=0;k<256;++k)
	    {
	      free(cache[i][j][k]);
	    }
	}
    }
}

led_color * led_get_color(level r, level g, level b)
{
  return cache[r][g][b];
}

led_color * led_delta_color(led_color* c, level r, level g, level b)
{
  return cache[c->red+r][c->green+g][c->blue+b];
}
