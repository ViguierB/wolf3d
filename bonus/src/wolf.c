/*
** wolf.c for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Dec 20 16:18:08 2016 Benjamin Viguier
** Last update Tue Jan 10 16:16:48 2017 Benjamin Viguier
*/

#include <SFML/Window/Event.h>
#include "wolf.h"
#include "colors.h"

int	init_win_dep(t_win_dep *win, char *win_title, int w, int h)
{
  win->w = w;
  win->h = h;
  win->close = 0;
  win->sprite = sfSprite_create();
  win->tex = sfTexture_create(w, h);
  win->buffer = init_fb(w, h);
  win->win = create_window(win_title, w, h);
  win->ray_buffer = malloc(sizeof(t_ray) * w);
  if (!(win->win) || !(win->buffer) ||
      !(win->tex) || !(win->sprite) ||
      !(win->ray_buffer))
    return (-1);
  sfSprite_setTexture(win->sprite, win->tex, sfTrue);
  return (0);
}

void	draw_floor(t_fb *fb)
{
  int	x;
  int	y;

  y = 0; 
  while (y < fb->height)
    {
      x = 0;
      while (x < fb->width)
	{
	  if (y / (fb->height / 2))
	    my_put_pixel(fb, x, y, SKY_COLOR);
	  else
	    my_put_pixel(fb, x, y, FLOOR_COLOR);
	  x += 1;
	}
      y += 1;
    }
}

void	on_loop(t_win_dep *win, t_wolf *map)
{
  int		i;
  sfVector2f	tmp;

  if (map->dep_vec.x != 0.f || map->dep_vec.y != 0.f)
    {
      tmp = map->player;
      map->player = move_forward(map->player, map->a_dir, map->dep_vec.y);
      map->player = move_forward(map->player, map->a_dir + 90.0, map->dep_vec.x);
      if (map->map->map[(int) map->player.y][(int) map->player.x] > 0)
	map->player = tmp;
      map->dep_vec = (sfVector2f) {0};
    }
  draw_floor(win->buffer);
  get_ray_projections(map, win->ray_buffer, win);
  i = 0;
  while (i < win->w)
    {
      my_draw_vertical_line(win->buffer,
			    (sfVector2i){i, win->ray_buffer[i].line.y},
			    win->ray_buffer[i].line.len,
			    get_color_by_ray(win->ray_buffer + i));
      i += 1;
    }
}

int		wolf(t_wolf *map)
{
  t_win_dep	win;

  if (init_win_dep(&win, "Wolf3d", 1280, 720) < 0)
    return (-1);
  calculate_pp(&win, map);
  while (!win.close)
    {
      clear_fb(win.buffer);
      event(&win, map);
      on_loop(&win, map);
      sfRenderWindow_clear(win.win, sfBlack);
      sfTexture_updateFromPixels(win.tex, win.buffer->pixels,
				 win.w, win.h, 0, 0);
      sfRenderWindow_drawSprite(win.win, win.sprite, NULL);
      sfRenderWindow_display(win.win);
    }
  return (0);
}
