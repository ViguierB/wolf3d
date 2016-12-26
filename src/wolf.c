/*
** wolf.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Dec 20 16:18:08 2016 Benjamin Viguier
** Last update Mon Dec 26 23:05:26 2016 Benjamin Viguier
*/

#include <SFML/Window/Event.h>
#include "wolf.h"

int	init_win_dep(t_win_dep *win, char *win_title, int w, int h)
{
  win->sprite = sfSprite_create();
  win->tex = sfTexture_create(w, h);
  win->buffer = init_fb(w, h);
  win->win = create_window(win_title, w, h);
  if (!(win->win) || !(win->buffer) ||
      !(win->tex) || !(win->sprite))
    return (-1);
  sfSprite_setTexture(win->sprite, win->tex, sfTrue);
  return (0);
}

void		on_loop(t_win_dep *win)
{
  
}

int		wolf(t_wolf *map)
{
  t_win_dep	win;
 
  if (init_win_dep(&win, "Wolf3d", 1280, 720) < 0)
    return(-1);
  while (event(&win))
    {
      on_loop(&win);
      sfRenderWindow_clear(win.win, sfBlack);
      sfTexture_updateFromPixels(win.tex, win.buffer->pixels,
				 win.w, win.h, 0, 0);
      sfRenderWindow_drawSprite(win.win, win.sprite, NULL);
      sfRenderWindow_display(win.win);
    }
  return (0);
}
