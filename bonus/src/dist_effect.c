/*
** dist_effect.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat Jan  7 13:09:44 2017 Benjamin Viguier
** Last update Sat Jan  7 13:45:18 2017 Benjamin Viguier
*/

#include "wolf.h"
#include "colors.h"

sfColor		get_color_by_ray(t_ray *ray)
{
  sfColor	res;
  float		pourcent;

  res = sfWhite;
  if (ray->side == 0)
    res = LIGHT_GRAY;
  pourcent = MIN(ray->len * 100.0 / RENDER_DIST, 100.0);
  pourcent = 100 - pourcent;
  res.r = MAX(MIN(res.r * pourcent / 100, 255), 0);
  res.g = MAX(MIN(res.g * pourcent / 100, 255), 0);
  res.b = MAX(MIN(res.b * pourcent / 100, 255), 0);
  return (res);
}
