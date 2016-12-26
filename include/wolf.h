/*
** wolf.h for bswolf3d in /home/benji_epitech/C_Graph_Prog/bswolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 12:49:52 2016 Benjamin Viguier
** Last update Wed Dec 21 14:20:45 2016 Benjamin Viguier
*/

#ifndef WOLF_H_
# define WOLF_H_

# include <SFML/Graphics.h>
# include <unistd.h>
# include "libmy.h"

# define ABS(x) (((x) < 0) ? -(x) : (x))
# define IS_IN(nbr, x, y) (((nbr) >= (x)) && ((nbr) <= (y)))
# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define ISHIGHTER(x, y) (((x) > (y)) ? (1) : (-1))
# define BLK 64
# define BUF_SIZE 4096

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;
typedef t_my_framebuffer	t_fb;


typedef struct	s_map
{
  int		w;
  int		h;
  int		*buffer;
  int		**map;
}		t_map;

typedef struct		s_win_dep
{
  sfRenderWindow	*win;
  sfTexture		*tex;
  t_fb			*buffer;
  sfSprite		*sprite;
  sfEvent		ev;
}			t_win_dep;

typedef struct	s_wolf
{
  sfVector2f	player;
  int		dep_len;
  t_map		*map;
}		t_wolf;

/*
** Wolf functions
*/
int	wolf(t_wolf *map);

/*
** Map functions
*/
int	fill_init_map(t_map *map, int w, int h);
void	free_map(t_map *map);
int	open_map(char *file, t_map *map);
int	on_error(int error_code, char *more);

/*
** Draw functions
*/
void	my_put_pixel(t_my_framebuffer *framebuffer,
	     int x, int y, sfColor color);
sfRenderWindow
	*create_window(char *str, int w, int h);
t_my_framebuffer
	*init_fb(int w, int h);
void	clear_fb(t_my_framebuffer *fb);
void	my_draw_vertical_line(t_my_framebuffer *fb, sfVector2i f,
			      int len, sfColor color);
void	my_draw_line(t_my_framebuffer *fb, sfVector2i f,
		     sfVector2i t, sfColor color);

#endif /* !WOLF_H_ */
