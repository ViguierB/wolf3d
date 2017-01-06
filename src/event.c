/*
** event.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 26 15:54:58 2016 Benjamin Viguier
** Last update Fri Jan  6 17:17:20 2017 Benjamin Viguier
*/

#include "wolf.h"

const t_event_fct const	fct_tab[] =
  {
    {sfEvtClosed, &close_evt},
    {sfEvtKeyPressed, &keypress_evt},
    {0, NULL}
  };

int		event(t_win_dep *win, int *first)
{
  t_event_fct	*cur;

  if (*first)
    {
      *first = 0;
      return (1);
    }
  while (sfRenderWindow_pollEvent(win->win, &(win->ev)))
    {
      cur = (t_event_fct *) fct_tab;
      while (cur->fct != NULL)
	{
	  if (win->ev.type == cur->type)
	    if (!((cur->fct)(win)))
	      return (0);
	  cur += 1;
	}
    }
  return (1);
}

int	close_evt(t_win_dep *win)
{
  win = (void*) win;
  return (0);
}

int	keypress_evt(t_win_dep *win)
{
  if (win->ev.key.code == sfKeyEscape)
    return (0);
  if (win->ev.key.code == sfKeyZ)
    win->dep_vec.y = 0.2;
  else if (win->ev.key.code == sfKeyS)
    win->dep_vec.y = -0.2;
  if (win->ev.key.code == sfKeyD)
    win->a_dir += 5.0;
  else if (win->ev.key.code == sfKeyQ)
    win->a_dir += -5.0;
  return (1);
}
