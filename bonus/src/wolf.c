/*
** wolf.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Dec 20 16:18:08 2016 Benjamin Viguier
** Last update Fri Jan  6 16:25:38 2017 Benjamin Viguier
*/

#include <SFML/Window/Event.h>
#include "wolf.h"

int	init_win_dep(t_win_dep *win, char *win_title, int w, int h)
{
  win->w = w;
  win->h = h;
  win->a_dir = 90.0;
  win->dep_vec = (sfVector2f){0};
  win->sprite = sfSprite_create();
  win->tex = sfTexture_create(w, h);
  win->buffer = init_fb(w, h);
  win->win = create_window(win_title, w, h);
  win->line_buffer = malloc(sizeof(t_h_line) * w);
  if (!(win->win) || !(win->buffer) ||
      !(win->tex) || !(win->sprite) ||
      !(win->line_buffer))
    return (-1);
  sfSprite_setTexture(win->sprite, win->tex, sfTrue);
  return (0);
}

void	on_loop(t_win_dep *win, t_wolf *map)
{
  int		i;
  sfVector2f	tmp;

  if (win->dep_vec.y != 0.0)
    {
      tmp = map->player;
      map->player = move_forward(map->player, win->a_dir, win->dep_vec.y);
      if (!IS_IN(map->player.x, 0, map->map->w - 1) ||
	  !IS_IN(map->player.y, 0, map->map->h - 1))
	map->player = tmp;
      win->dep_vec.y = 0.0;
    }
  get_lines_projections(map, win->line_buffer, win);
  i = 0;
  while (i < win->w)
    {
      my_draw_vertical_line(win->buffer,
			    (sfVector2i){i, win->line_buffer[i].y},
			    win->line_buffer[i].len, sfWhite);
      i += 1;
    }
}

int		wolf(t_wolf *map)
{
  t_win_dep	win;
  int		first;

  if (init_win_dep(&win, "Wolf3d", 1280, 720) < 0)
    return (-1);
  map->dpp = (win.w / 2) / tan(GET_RADIAN(map->fov / 2));
  first = 1;
  while (event(&win, &first))
    {
      clear_fb(win.buffer);
      on_loop(&win, map);
      sfRenderWindow_clear(win.win, sfBlack);
      sfTexture_updateFromPixels(win.tex, win.buffer->pixels,
				 win.w, win.h, 0, 0);
      sfRenderWindow_drawSprite(win.win, win.sprite, NULL);
      sfRenderWindow_display(win.win);
    }
  return (0);
}
