/*
** raycast.c for bswolf3d in /home/benji_epitech/C_Graph_Prog/bswolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 11:14:49 2016 Benjamin Viguier
** Last update Tue Jan  3 17:45:53 2017 Benjamin Viguier
*/

#include "wolf.h"
#include <math.h>

float	get_pyth(sfVector2f *a, sfVector2f *b)
{
  return (sqrtf(((a->x - b->x) * (a->x - b->x)) +
		((a->y - b->y) * (a->y - b->y))));
}

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
  direction = GET_RADIAN(direction);
  tan_dir = tan(direction);
  ha.x = BLK / tan_dir;
  va.y = BLK * tan_dir;
  hi.y = ((int) pos.x / BLK) * BLK + corh;
  hi.x = pos.x + (pos.y - hi.y) / tan_dir;
  vi.x = ((int) pos.y / BLK) * BLK + corv;
  vi.y = pos.y + (pos.x - vi.x) * tan_dir;
  //printf("ha = %f %f, va = %f %f, hi = %f %f, vi = %f %f\n", ha.x, ha.y, va.x, va.y, hi.x, hi.y, vi.x, vi.y);
  while (IS_IN((int) hi.y / BLK, 0, mapSize.y - 1) &&
	 IS_IN((int) hi.x / BLK, 0, mapSize.x - 1) &&
	 !map[(int) (hi.y / BLK)][(int) (hi.x / BLK)])
    {
      //printf("H ->\thi.x = %f, hi.y = %f\n\tx = %d, y = %d\n", hi.x, hi.y, (int) (hi.x / BLK), (int) (hi.y / BLK));
      hi.x += ha.x;
      hi.y += ha.y;
    }
  while (IS_IN((int) (vi.y / BLK), 0, mapSize.y - 1) &&
	 IS_IN((int) (vi.x / BLK), 0, mapSize.x - 1) &&
	 !map[(int) (vi.y / BLK)][(int) (vi.x / BLK)])
    {
      //printf("V ->\tvi.x = %f, vi.y = %f\n\tx = %d, y = %d\n", vi.x, vi.y, (int) (vi.x / BLK), (int) (vi.y / BLK));
      vi.x += va.x;
      vi.y += va.y;
    }
  //printf("After: hi = %f %f, vi = %f %f\n", hi.x, hi.y, vi.x, vi.y);
  //printf("H -> %f, V -> %f\n", ABS(hi.x - pos.x) / cos(direction), ABS(vi.x - pos.x) / cos(direction));
  return (MIN(ABS(ABS(hi.x - pos.x) / cos(direction)),
	      ABS(ABS(vi.x - pos.x) / cos(direction))));
}
