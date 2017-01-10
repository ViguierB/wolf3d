/*
** event.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 26 15:54:58 2016 Benjamin Viguier
** Last update Tue Jan 10 16:37:25 2017 Benjamin Viguier
*/

#include <stdio.h>
#include "wolf.h"

const t_move_event const	fct_tab[] =
  {
    {sfKeyEscape, 0.f, 0.f, 0.f, &close_evt},
    {sfKeyZ, 0.f, 0.2, 0.f, NULL},
    {sfKeyS, 0.f, -0.2, 0.f, NULL},
    {sfKeyD, 0.2, 0.f, 0.f, NULL},
    {sfKeyQ, -0.2, 0.f, 0.f, NULL},
    {sfKeyRight, 0.f, 0.f, 3.f, NULL},
    {sfKeyLeft, 0.f, 0.f, -3.f, NULL},
    {sfKeyUnknown, 0.f, 0.f, 0.f, NULL}
  };

void		sf_event(t_win_dep *win, t_wolf *wolf)
{
  sfEvent	ev;

  if (sfRenderWindow_pollEvent(win->win, &ev))
    {
      if (ev.type == sfEvtClosed)
	win->close = 1;
      else if (ev.type == sfEvtResized)
	if (resize_window(win, wolf, ev.size.width, ev.size.height) < 0)
	  {
	    perror("reSize");
	    exit(84);
	  }
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

int	close_evt(t_win_dep *win, t_wolf *wolf)
{
  wolf = (void*) wolf;
  win->close = 1;
  return (0);
}
