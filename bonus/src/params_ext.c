/*
** params_ext.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Jan 11 16:35:36 2017 Benjamin Viguier
** Last update Wed Jan 11 16:55:42 2017 Benjamin Viguier
*/

#include "params.h"
#include "libmy.h"

int	set_map_file(t_params *parms, char *data)
{
  if (data)
    {
      parms->map_file = my_strdup(data);
      if (!(parms->map_file))
	return (-1);
    }
  return (0);
}

int	print_usage(t_params *parms, char *data)
{
  parms = (void*) parms;
  data = (void*) data;
  my_printf("Usage :\n"
	    "\t./wolf3d map=file_name\n\n"
	    "\tAn exemple of map (cat map) :\n"
	    "\t\t1111111\n"
	    "\t\t1000001\n"
	    "\t\t1002001\n"
	    "\t\t1111111\n");
  exit(0);
  return (0);
}
