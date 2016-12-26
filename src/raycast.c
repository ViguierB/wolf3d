/*
** raycast.c for bswolf3d in /home/benji_epitech/C_Graph_Prog/bswolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 11:14:49 2016 Benjamin Viguier
** Last update Tue Dec 20 17:39:51 2016 Benjamin Viguier
*/

#include "wolf.h"
#include <math.h>

float		raycast(sfVector2f pos, float direction, int **map, sfVector2i mapSize)
{
  sfVector2f	ha;
  sfVector2f	hi;
  sfVector2f	va;
  sfVector2f	vi;
  float		tan_dir;
  int		corh;
  int		corv;

  pos.x *= BLK;
  pos.y *= BLK;
  if (IS_IN(direction, 0, 180))
    {
      ha.y = BLK;
      corh = -1;
    }
  else
    {
      ha.y = -(BLK);
      corh = BLK;
    }
  if (IS_IN(direction, 90, 270))
    {
      va.x = BLK;
      corv = -1;
    }
  else
    {
      va.x = -(BLK);
      corv = BLK;
    }
  direction = (direction * M_PI) / 180;
  tan_dir = tan(direction);
  ha.x = BLK / tan_dir;
  va.y = BLK * tan_dir;
  hi.y = ((int) pos.x / BLK) * BLK + corh;
  hi.x = pos.x + (pos.y - hi.y) / tan_dir;
  vi.x = ((int) pos.y / BLK) * BLK + corv;
  vi.y = pos.y + (pos.x - vi.x) * tan_dir;
  while (IS_IN((int) hi.y / BLK, 0, mapSize.y - 1) &&
	 IS_IN((int) hi.x / BLK, 0, mapSize.x - 1) &&
	 !map[(int) hi.y / BLK][(int) hi.x / BLK])
    {
      hi.x += ha.x;
      hi.y += ha.y;
    }
  while (IS_IN((int) hi.y / BLK, 0, mapSize.y - 1) &&
	 IS_IN((int) hi.x / BLK, 0, mapSize.x - 1) &&
	 !map[(int) vi.y / BLK][(int) vi.x / BLK])
    {
      vi.x += va.x;
      vi.y += va.y;
    }
  return (MIN(ABS(pos.x * BLK - hi.x) / cos(direction),
	      ABS(pos.x * BLK - vi.x) / cos(direction)));
}
