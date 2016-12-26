/*
** projection.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 26 18:52:59 2016 Benjamin Viguier
** Last update Mon Dec 26 22:31:54 2016 Benjamin Viguier
*/

#include "wolf.h"
#include <math.h>

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

void		get_lines_projections(t_wolf *map, t_h_line *buffer, t_win_dep *win)
{
  int		i;
  float		raycast_res;
  float		dir;
  float		a_proj;

  i = 0;
  while (i < win->w)
    {
      a_proj = ((map->fov * i) / win->w) - (map->fov / 2);
      dir = add_angles(map->dir, a_proj);
      raycast_res = raycast(map->player, dir, map->map->map,
			    (sfVector2i){map->map->w, map->map->h});
      raycast_res *= cos(ABS(a_proj));
      buffer[i].x = i;
      buffer[i].len = (1 / raycast_res) * map->dpp;
      buffer[i].y = (win->h + buffer[i].len) / 2;
      i += 1;
    }
}
