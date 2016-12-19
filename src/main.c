/*
** main.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 14:16:05 2016 Benjamin Viguier
** Last update Mon Dec 19 17:23:42 2016 Benjamin Viguier
*/

#include "wolf.h"

int	print_usage(void)
{
  my_printf("Usage :\n"
	    "\t./wolf3d map\n\n"
	    "\tAn exemple of map (cat map) :\n"
	    "\t\t1 1 1 1\n"
	    "\t\t1 0 0 1\n"
	    "\t\t1 0 0 1\n"
	    "\t\t1 1 1 1\n");
  return (0);
}

int main(int ac, char **av)
{
  int	open_res;
  t_map	map;
  
  if (ac < 2 || my_strcmp(av[1], "-h") == 0)
    return (print_usage());
  open_res = open_map(av[1], &map);
  if (open_res < 0 && open_res == -2)
    on_error(open_res, av[1]);
  else if (open_res < 0)
    on_error(open_res, NULL);
  return (0);
}
