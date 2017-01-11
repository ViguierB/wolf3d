/*
** open_config.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Jan 11 16:27:42 2017 Benjamin Viguier
** Last update Wed Jan 11 16:57:46 2017 Benjamin Viguier
*/

#include "wolf.h"

int	open_config(t_params *parms, char *data)
{
  int	res;
  char	*file_opened;
  char	**splited;
  int	count;

  res = read_to_end(data, &file_opened);
  if (res < 0)
    return (res);
  splited = my_split(file_opened, '\n', &count);
  if (count)
    count += 1;
  free(file_opened);
  verif_params(parms, count, splited);
  free(splited);
  return (0);
}
