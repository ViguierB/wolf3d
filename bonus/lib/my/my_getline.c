/*
** my_getline.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Dec 22 12:46:31 2016 Benjamin Viguier
** Last update Thu Dec 22 22:42:36 2016 Benjamin Viguier
*/

#include <unistd.h>
#include "libmy.h"

int	extract_line(char *buffer, 

int		my_getline(t_my_fd *mfd, char **result, int *nb_char)
{
  ssize_t	r_len;

  *result = NULL;
  nb_lines = 0;
  if (mfd->index)
    {
      
    }
  r_len = read(mdf->fd, mfd->buffer, MY_FD_BUFF_LEN)
}
