/*
** params.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Jan 11 13:31:50 2017 Benjamin Viguier
** Last update Wed Jan 11 16:56:30 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include "params.h"
#include "libmy.h"

const t_parm_fct const	param_fct_tab[] =
  {
    {"size", &set_win_size},
    {"fov", &set_fov},
    {"dir", &set_dir},
    {"config", &open_config},
    {"map", &set_map_file},
    {"-h", &print_usage},
    {NULL, NULL}
  };

int	set_win_size(t_params *parms, char *data)
{
  char	**size;

  if (data)
    {
      size = my_split(data, ':', NULL);
      parms->win_w = atoi(size[0]);
      parms->win_h = atoi(size[1]);
      free(size);
    }
  return (0);
}

int	set_dir(t_params *parms, char *data)
{
  if (data)
    parms->a_dir = atof(data);
  return (0);
}

int	set_fov(t_params *parms, char *data)
{
  if (data)
    parms->fov = atoi(data);
  return (0);
}

int	init_params(t_params *params)
{
  params->win_w = BASIC_W;
  params->win_h = BASIC_H;
  params->fov = BASIC_FOV;
  params->a_dir = BASIC_A_DIR;
  return (0);
}

int		verif_params(t_params *parms, int ac, char **av)
{
  char		**tmp;
  t_parm_fct	*cur;
  int		i;
  int		found;

  i = 0;
  while (i < ac)
    {
      found = 0;
      cur = (t_parm_fct*) param_fct_tab;
      tmp = my_split(av[i], '=', NULL);
      while (!found && cur->flag != NULL && cur->fct != NULL)
	{
	  if (my_strcmp(tmp[0], cur->flag) == 0)
	    {
	      (cur->fct)(parms, tmp[1]);
	      found = 1;
	    }
	  cur += 1;
	}
      free(tmp);
      i += 1;
    }
  return (0);
}
