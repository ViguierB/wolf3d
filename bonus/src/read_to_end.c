/*
** read_to_end.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Jan 11 17:02:14 2017 Benjamin Viguier
** Last update Wed Jan 11 17:06:49 2017 Benjamin Viguier
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

int	return_empty(char **res)
{
  *res = my_strdup("");
  if (!(*res))
    return (-1);
  return (0);
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
  if (!len)
    return (return_empty(res));
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
