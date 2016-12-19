/*
** my_draw_line.c for bswireframe in /home/benji_epitech/C_Graph_Prog/bswireframe/tests
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Nov 18 10:52:40 2016 Benjamin Viguier
** Last update Thu Dec  8 03:03:10 2016 Benjamin Viguier
*/

#include "my.h"

void		my_draw_line(t_my_framebuffer *fb, sfVector2i f,
			     sfVector2i t, sfColor color)
{
  sfVector2i	d;
  sfVector2i	inc;
  sfVector2i    dp;

  d.x = ABS(t.x - f.x);
  d.y = ABS(t.y - f.y);
  inc.x = ISHIGHTER(t.x, f.x);
  inc.y = ISHIGHTER(t.y, f.y);
  dp.x = ((d.x > d.y) ? (d.x) : -(d.y)) / 2;
  my_put_pixel(fb, f.x, f.y, color);
  while (f.x != t.x || (f.y != t.y))
    {
      dp.y = dp.x;
      if (dp.y > -(d.x))
	{
	  dp.x -= d.y;
	  f.x += inc.x;
	}
      if (dp.y < d.y)
	{
	  dp.x += d.x;
	  f.y += inc.y;
	}
      my_put_pixel(fb, f.x, f.y, color);
    }
}
