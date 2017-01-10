/*
** main.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 14:16:05 2016 Benjamin Viguier
** Last update Tue Jan 10 15:05:42 2017 Benjamin Viguier
*/

#include "wolf.h"

int	print_usage(void)
{
  my_printf("Usage :\n"
	    "\t./wolf3d map\n\n"
	    "\tAn exemple of map (cat map) :\n"
	    "\t\t1111\n"
	    "\t\t1001\n"
	    "\t\t1001\n"
	    "\t\t1111\n");
  return (0);
}

int		main(int ac, char **av)
{
  int		open_res;
  t_map		map;
  t_wolf	wol;

  if (ac < 2 || my_strcmp(av[1], "-h") == 0)
    return (print_usage());
  open_res = open_map(av[1], &map);
  if (open_res < 0 && open_res == -2)
    on_error(open_res, av[1]);
  else if (open_res < 0)
    on_error(open_res, NULL);
  wol.map = &map;
  wol.player = (sfVector2f){(float) map.w / 2.0, (float) map.h / 2.0};
  wol.a_dir = 90.0;
  wol.dep_vec = (sfVector2f){0};
  wol.fov = 66;
  wolf(&wol);
  return (0);
}
