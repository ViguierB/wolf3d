/*
** map.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 15:49:47 2016 Benjamin Viguier
** Last update Mon Dec 19 15:56:53 2016 Benjamin Viguier
*/

#include "wolf.h"

int	fill_init_map(t_map *map, int w, int h)
{
  int	i;
  int	j;
  int	*tmp;

  map->w = w + 2;
  map->h = h + 2;
  map->buffer = malloc(sizeof(int) * map->w * map->h);
  map->map = malloc(sizeof(int *) * map->h);
  if (!(map->map) || !(map->buffer))
    return (-1);
  i = 0;
  tmp = map->buffer;
  while (i < map->h)
    {
      j = 0;
      map->map[i] = tmp;
      while (j < map->w)
	{
	  *tmp = 1;
	  tmp += 1;
	  j += 1;
	}
      i += 1;
    }
  return (0);
}

void	free_map(t_map *map)
{
  if (map)
    {
      if (map->buffer)
	free(map->buffer);
      if (map->map)
	free(map->map);
      free(map);
    }
}
