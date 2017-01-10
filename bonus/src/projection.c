/*
** projection.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 26 18:52:59 2016 Benjamin Viguier
** Last update Tue Jan 10 15:11:12 2017 Benjamin Viguier
*/

#include <math.h>
#include "wolf.h"

float	add_angles(float a, float b)
{
  float	new_angle;

  new_angle = a + b;
  if (new_angle > 360.0)
    new_angle = fmodf(new_angle, 360.0);
  else if (new_angle < 0.0)
    new_angle = 360.0 - fmodf(ABS(new_angle), 360.0);
  return (new_angle);
}

void		get_ray_projections(t_wolf *map, t_ray *buffer,
				      t_win_dep *win)
{
  int		i;
  float		dir;
  float		a_proj;

  i = 0;
  while (i < win->w)
    {
      a_proj = ((map->fov * i) / (float) win->w) - (map->fov / 2.0);
      dir = add_angles(map->a_dir, a_proj);
      raycast(buffer + i, map->player, dir, map->map->map);
      buffer[i].len *= cos(ABS(GET_RADIAN(a_proj)));
      buffer[i].line.x = i;
      if (buffer[i].len)
	buffer[i].line.len = (int) (FBLK / buffer[i].len * map->dpp);
      else
	buffer[i].line.len = win->h;
      buffer[i].line.y = (win->h - buffer[i].line.len) / 2;
      i += 1;
    }
}
