/*
** raycast.c for bswolf3d in /home/benji_epitech/C_Graph_Prog/bswolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 11:14:49 2016 Benjamin Viguier
** Last update Fri Jan  6 16:24:31 2017 Benjamin Viguier
*/

#include <SFML/Graphics.h>
#include <math.h>

int	inter(int x, int min, int max, int check_type)
{
  if (check_type == 0)
    return ((x >= min) && (x <= max));
  else if (check_type == 1)
    return ((x > min) && (x < max));
  else if (check_type == 2)
    return ((x > min) && (x <= max));
  else if (check_type == 3)
    return ((x >= min) && (x < max));
  else
    return ((x >= min) && (x <= max));
}

/*
** vectf[0] --> pos
** vectf[1] --> delta_dist
** vectf[2] --> ray_dir
** vectf[3] --> side_dist
*/

sfVector2i	init_side_and_step(sfVector2f *vectf[], sfVector2i *map_pos)
{
  sfVector2i	step;

  if (vectf[2]->x < 0)
    {
      step.x = -1;
      vectf[3]->x = (vectf[0]->x - map_pos->x) * vectf[1]->x;
    }
  else
    {
      step.x = 1;
      vectf[3]->x = (map_pos->x + 1.0 - vectf[0]->x) * vectf[1]->x;
    }
  if (vectf[2]->y < 0)
    {
      step.y = -1;
      vectf[3]->y = (vectf[0]->y - map_pos->y) * vectf[1]->y;
    }
  else
    {
      step.y = 1;
      vectf[3]->y = (map_pos->y + 1.0 - vectf[0]->y) * vectf[1]->y;
    }
  return (step);
}

int	casting(sfVector2f *dist[], sfVector2i *pos[],
		int **map, sfVector2i *mapSize)
{
  int	hit;
  int	side;

  hit = 0;
  while (!hit)
    {
      if (dist[0]->x < dist[0]->y)
	{
	  dist[0]->x += dist[1]->x;
	  pos[0]->x += pos[1]->x;
	  side = 0;
	}
      else
	{
	  dist[0]->y += dist[1]->y;
	  pos[0]->y += pos[1]->y;
	  side = 1;
	}
      if (!inter(pos[0]->x, 0, mapSize->x, 3) ||
	  !inter(pos[0]->y, 0, mapSize->y, 3) ||
	  map[pos[0]->y][pos[0]->x] > 0)
	hit = 1;
    }
  return (side);
}

float		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapSize)
{
  sfVector2f	delta_dist;
  sfVector2f	side_dist;
  sfVector2f	ray_dir;
  sfVector2i	step;
  sfVector2i	map_pos;
  int		side;

  direction = (direction * M_PI) / 180;
  map_pos = (sfVector2i){(int) pos.x, (int) pos.y};
  ray_dir = (sfVector2f){cos(direction), sin(direction)};
  delta_dist.x = sqrt(1.0 + (ray_dir.y * ray_dir.y) / (ray_dir.x * ray_dir.x));
  delta_dist.y = sqrt(1.0 + (ray_dir.x * ray_dir.x) / (ray_dir.y * ray_dir.y));
  step =
    init_side_and_step((sfVector2f*[])
		       {&pos, &delta_dist, &ray_dir, &side_dist},
		       &map_pos);
  side = casting((sfVector2f*[]) {&side_dist, &delta_dist},
		 (sfVector2i*[]) {&map_pos, &step},
		 map, &mapSize);
  if (!side)
    return (map_pos.x - pos.x + (1.0 - step.x) / 2.0) / ray_dir.x;
  return (map_pos.y - pos.y + (1.0 - step.y) / 2.0) / ray_dir.y;
}
