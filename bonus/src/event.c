/*
** event.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 26 15:54:58 2016 Benjamin Viguier
** Last update Tue Jan 10 17:29:14 2017 Benjamin Viguier
*/

#include <stdio.h>
#include "wolf.h"

const t_move_event const	fct_tab[] =
  {
    {sfKeyEscape, 0.f, 0.f, 0.f, &close_evt},
    {sfKeyZ, 0.f, 0.1, 0.f, NULL},
    {sfKeyS, 0.f, -0.1, 0.f, NULL},
    {sfKeyD, 0.1, 0.f, 0.f, NULL},
    {sfKeyQ, -0.1, 0.f, 0.f, NULL},
    {sfKeyLShift, 0.f, 0.f, 0.f, &run_keypressed},
    {sfKeyRight, 0.f, 0.f, 3.f, NULL},
    {sfKeyLeft, 0.f, 0.f, -3.f, NULL},
    {sfKeyPageUp, 0.f, 0.f, 0.f, &incr_fov},
    {sfKeyPageDown, 0.f, 0.f, 0.f, &decr_fov},
    {sfKeyUnknown, 0.f, 0.f, 0.f, NULL}
  };

void		sf_event(t_win_dep *win, t_wolf *wolf)
{
  sfEvent	ev;

  wolf = (void*) wolf;
  if (sfRenderWindow_pollEvent(win->win, &ev))
    {
      if (ev.type == sfEvtClosed)
	win->close = 1;
    }
}

void		event(t_win_dep *win, t_wolf *wolf)
{
  t_move_event	*cur;

  cur = (t_move_event*) fct_tab;
  while (cur->key != sfKeyUnknown)
    {
      if (sfKeyboard_isKeyPressed(cur->key))
	{
	  wolf->dep_vec.x += cur->x_axis;
	  wolf->dep_vec.y += cur->y_axis;
	  wolf->a_dir += cur->angle;
	  if (cur->fct)
	    (cur->fct)(win, wolf);
	}
      cur += 1;
    }
  sf_event(win, wolf);
}
