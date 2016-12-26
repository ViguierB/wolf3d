/*
** wolf.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Dec 20 16:18:08 2016 Benjamin Viguier
** Last update Wed Dec 21 14:20:45 2016 Benjamin Viguier
*/

#include <SFML/Window/Event.h>
#include "wolf.h"

int		wolf(t_wolf *map)
{
  t_win_dep	win;

  win.sprite = sfSprite_create();
  win.tex = sfTexture_create(w, h);
  win.buffer = init_fb(w, h);
  win.win = create_window("Wolf3d", w, h);
  if (!win || !buffer || !tex || !sprite)
    return (-1);
  sfSprite_setTexture(sprite, tex, sfTrue);
  while (event(win))
    {
      on_loop(win);
      sfRenderWindow_clear(win.win, sfBlack);
      sfTexture_updateFromPixels(win.tex, win.buffer->pixels, w, h, 0, 0);
      sfRenderWindow_drawSprite(win.win, sprite, NULL);
      sfRenderWindow_display(win);
    }
  return (0);
}
