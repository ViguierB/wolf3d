/*
** openfile.c for wireframe in /home/benji_epitech/C_Graph_Prog/wireframe
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Dec  7 09:53:54 2016 Benjamin Viguier
** Last update Tue Jan 10 17:37:22 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "wolf.h"

char		*conca_buffer(char *inp, size_t cur_size,
			      char *buf, size_t b_len)
{
  char		*res;
  t_uint	i;

  res = malloc(sizeof(char) * (b_len + cur_size + 1));
  if (!res)
    return (NULL);
  i = 0;
  my_strncpy(res, inp, cur_size);
  while (i < b_len)
    {
      res[i + cur_size] = buf[i];
      i += 1;
    }
  if (inp)
    free(inp);
  return (res);
}

int	read_to_end(char *file, char **res)
{
  int		fd;
  char		buffer[BUF_SIZE];
  size_t	len;
  size_t	cur_len;

  fd = open(file, O_RDONLY);
  if (fd < 0)
    return (-2);
  cur_len = 0;
  *res = NULL;
  len = read(fd, buffer, BUF_SIZE);
  while (len)
    {
      *res = conca_buffer(*res, cur_len, buffer, len);
      if (!(*res))
	return (-1);
      cur_len += len;
      len = read(fd, buffer, BUF_SIZE);
    }
  (*res)[cur_len] = '\0';
  return (0);
}

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
