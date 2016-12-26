/*
** my_fd.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Dec 22 16:23:15 2016 Benjamin Viguier
** Last update Thu Dec 22 22:42:48 2016 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libmy.h"

t_my_fd		*my_fopen(char *path, int flags)
{
  t_my_fd	*res;
  int		i;

  res = malloc(sizeof(t_my_fd));
  if (!res)
    return(NULL);
  res->index = 0;
  res->r_len = 0;
  res->fd = open(path, flags);
  if (res->fd < 0)
    return (NULL);
  i = 0;
  while (i < MY_FD_BUFF_LEN)
    {
      res->buffer[i] = 0;
      i += 1;
    }
  return (res);
}

void	my_fclose(t_my_fd *to_free)
{
  if (to_free)
    {
      close(to_free->fd);
      free(to_free);
    }
}
