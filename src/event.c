/*
** event.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 26 15:54:58 2016 Benjamin Viguier
** Last update Mon Dec 26 18:40:11 2016 Benjamin Viguier
*/

#include "wolf3d.h"

const t_event_fct const	fct_tab[] =
  {
    {sfEvtClosed, &close_evt},
    {sfEvtKeyPressed, &keypress_evt},
    {-1, NULL}
  };

int		event(t_win_dep *win)
{
  t_event_fct	*cur;
  
  sfRenderWindow_pollEvent(win->win, &(win->ev));
  cur = fct_tab;
  while (cur->fct != NULL)
    {
      if (win->ev.type == cur->type)
	return (cur->fct)(win);
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
  else if (win->ev.key.code == sfKeyZ)
    win->dep_vec.y = 1.0;
  else if (win->ev.key.code == sfKeyS)
    win->dep_vec.y = -1.0;
  else if (win->ev.key.code == sfKeyD)
    win->a_dir += 1.0;
  else if (win->ev.key.code == sfKeyQ)
    win->a_dir += -1.0;
  return (1);
}
