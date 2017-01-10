/*
** evt_fcts.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Jan 10 16:01:46 2017 Benjamin Viguier
** Last update Tue Jan 10 17:31:10 2017 Benjamin Viguier
*/

#include "wolf.h"

void	calculate_pp(t_win_dep *win, t_wolf *wolf)
{
  wolf->dpp = (win->w / 2) / tan(GET_RADIAN(wolf->fov / 2));
}

int	run_keypressed(t_win_dep *win, t_wolf *wolf)
{
  win = (void*) win;
  wolf->dep_vec.x *= 2.0;
  wolf->dep_vec.y *= 2.0;
  return (0);
}

int	incr_fov(t_win_dep *win, t_wolf *wolf)
{
  wolf->fov = MAX(MIN(wolf->fov + 1, MAX_FOV), MIN_FOV);
  calculate_pp(win, wolf);
  return (0);
}

int	decr_fov(t_win_dep *win, t_wolf *wolf)
{
  wolf->fov = MAX(MIN(wolf->fov - 1, MAX_FOV), MIN_FOV);
  calculate_pp(win, wolf);
  return (0);
}

int	close_evt(t_win_dep *win, t_wolf *wolf)
{
  wolf = (void*) wolf;
  win->close = 1;
  return (0);
}
