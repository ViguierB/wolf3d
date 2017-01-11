/*
** openfile.c for wireframe in /home/benji_epitech/C_Graph_Prog/wireframe
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Dec  7 09:53:54 2016 Benjamin Viguier
** Last update Wed Jan 11 17:02:29 2017 Benjamin Viguier
*/

#include "wolf.h"

int	fill_map(t_map *map, char **buffer)
{
  int	i;
  int	j;

  i = 1;
  while (i < map->h - 1)
    {
      j = 1;
      while (buffer[i - 1][j - 1])
	{
	  map->map[i][j] = buffer[i - 1][j - 1] - '0';
	  j += 1;
	}
      i += 1;
    }
  return (0);
}

int	open_map(char *file, t_map *map)
{
  char	*buffer;
  char	**sp_buffer;
  int	biggest_len;
  int	i;
  int	read_res;

  read_res = read_to_end(file, &buffer);
  if (read_res < 0)
    return (-1);
  sp_buffer = my_split(buffer, '\n', &(map->h));
  map->h += 1;
  free(buffer);
  if (!sp_buffer)
    return (-1);
  i = 1;
  biggest_len = my_strlen(sp_buffer[0]);
  while (i < map->h)
    {
      biggest_len = MAX(biggest_len, my_strlen(sp_buffer[i]));
      i += 1;
    }
  if (fill_init_map(map, biggest_len, map->h) < 0)
    return (-1);
  return (fill_map(map, sp_buffer));
}
