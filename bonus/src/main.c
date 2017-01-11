/*
** main.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 14:16:05 2016 Benjamin Viguier
** Last update Wed Jan 11 16:55:17 2017 Benjamin Viguier
*/

#include "wolf.h"
#include "params.h"

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

int	init_wolf_struct(t_wolf *wol, t_map *map, t_params *parms)
{
  wol->map = map;
  wol->player = get_player_pos(wol);
  wol->a_dir = parms->a_dir;
  wol->dep_vec = (sfVector2f){0};
  wol->fov = parms->fov;
  wol->parms = parms;
  return (0);
}

int		main(int ac, char **av)
{
  int		open_res;
  t_map		map;
  t_wolf	wol;
  t_win_dep	win;
  t_params	parms;

  if (ac < 2)
    return (print_usage(NULL, NULL));
  init_params(&parms);
  if (verif_params(&parms, ac - 1, av + 1) < 0)
    return (on_error(-1, NULL));
  open_res = open_map(parms.map_file, &map);
  if (open_res < 0 && open_res == -2)
    return (on_error(open_res, av[1]));
  else if (open_res < 0)
    return (on_error(open_res, NULL));
  init_wolf_struct(&wol, &map, &parms);
  if (init_win_dep(&win, "Wolf3d", parms.win_w, parms.win_h) < 0)
    return (on_error(-1, NULL));
  wolf(&win, &wol);
  return (0);
}
