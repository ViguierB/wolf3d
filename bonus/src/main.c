/*
** main.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 14:16:05 2016 Benjamin Viguier
** Last update Tue Jan 10 17:51:02 2017 Benjamin Viguier
*/

#include "wolf.h"

int	print_usage(void)
{
  my_printf("Usage :\n"
	    "\t./wolf3d map\n\n"
	    "\tAn exemple of map (cat map) :\n"
	    "\t\t1111111\n"
	    "\t\t1000001\n"
	    "\t\t1002001\n"
	    "\t\t1111111\n");
  return (0);
}

sfVector2f	get_player_pos(t_wolf *wolf)
{
  sfVector2f	res;
  int		i;
  int		j;

  i = 0;
  res = (sfVector2f) {(float) wolf->map->w / 2.0,
		      (float) wolf->map->h / 2.0};
  while (i < wolf->map->h)
    {
      j = 0;
      while (j < wolf->map->w)
	{
	  if (wolf->map->map[i][j] == 2)
	    {
	      wolf->map->map[i][j] = 0;
	      return ((sfVector2f) {(float) j + 0.5, (float) i + 0.5});
	    }
	  else if (wolf->map->map[i][j] == 0)
	    res = ((sfVector2f) {(float) j + 0.5, (float) i + 0.5});
	  j += 1;
	}
      i += 1;
    }
  return (res);
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
  wol.player = get_player_pos(&wol);
  wol.a_dir = 90.0;
  wol.dep_vec = (sfVector2f){0};
  wol.fov = 66;
  wolf(&wol);
  return (0);
}
