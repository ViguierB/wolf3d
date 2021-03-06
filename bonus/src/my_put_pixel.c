/*
** my_put_pixel.c for bswireframe in /home/benji_epitech/C_Graph_Prog/bswireframe/tests
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Nov 18 11:16:08 2016 Benjamin Viguier
** Last update Tue Jan 10 17:04:44 2017 Benjamin Viguier
*/

#include "wolf.h"

void		my_put_pixel(t_my_framebuffer *framebuffer,
			     int x, int y, sfColor color)
{
  sfUint8	*cur;

  if (x >= 0 && y >= 0 && x < framebuffer->width &&
      y < framebuffer->height)
    {
      y = framebuffer->height - y;
      cur = (framebuffer->pixels + ((y * framebuffer->width + x) * 4));
      cur[0] = color.r;
      cur[1] = color.g;
      cur[2] = color.b;
      cur[3] = color.a;
    }
}

sfRenderWindow		*create_window(char *str, int w, int h)
{
  sfRenderWindow	*res;
  sfVideoMode		m;

  m.width = w;
  m.height = h;
  m.bitsPerPixel = 32;
  res = sfRenderWindow_create(m, str, sfResize | sfClose, NULL);
  if (!res)
    return (NULL);
  return (res);
}

void	free_fb(t_my_framebuffer *to_free)
{
  free(to_free->pixels);
  free(to_free);
}

t_my_framebuffer	*init_fb(int w, int h)
{
  int			i;
  int			array_len;
  sfUint8		*res;
  t_my_framebuffer	*fb;

  array_len = 4 * w * h + 1;
  res = malloc(sizeof(sfUint8) * array_len);
  fb = malloc(sizeof(t_my_framebuffer));
  if (!res || !fb)
    return ((void*) 0);
  i = 0;
  while (i < array_len)
    {
      res[i] = 0;
      i += 1;
    }
  fb->pixels = res;
  fb->width = w;
  fb->height = h;
  return (fb);
}

void	clear_fb(t_my_framebuffer *fb)
{
  int			i;
  int			array_len;

  array_len = fb->width * fb->height * 4;
  i = 0;
  while (i < array_len)
    {
      fb->pixels[i] = 0;
      i += 1;
    }
}
