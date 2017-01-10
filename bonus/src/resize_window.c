/*
** resize_window.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Jan 10 16:01:46 2017 Benjamin Viguier
** Last update Tue Jan 10 16:50:23 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "wolf.h"

void	calculate_pp(t_win_dep *win, t_wolf *wolf)
{
  wolf->dpp = (win->w / 2) / tan(GET_RADIAN(wolf->fov / 2));
}

int	resize_window(t_win_dep *win, t_wolf *wolf, int w, int h)
{
  free(win->buffer->pixels);
  free(win->buffer);
  free(win->ray_buffer);
  //win->w = w;
  //win->h = h;
  win->buffer = init_fb(w, h);
  win->ray_buffer = malloc(sizeof(t_ray) * win->w);
  calculate_pp(win, wolf);
  return (0);
}
