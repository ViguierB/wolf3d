/*
** wolf.h for bswolf3d in /home/benji_epitech/C_Graph_Prog/bswolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 12:49:52 2016 Benjamin Viguier
** Last update Wed Jan 11 16:42:28 2017 Benjamin Viguier
*/

#ifndef WOLF_H_
# define WOLF_H_

# include <SFML/Graphics.h>
# include <unistd.h>
# include <math.h>
# include "libmy.h"
# include "params.h"

# define ABS(x) (((x) < 0) ? -(x) : (x))
# define IS_IN(nbr, x, y) (((nbr) >= (x)) && ((nbr) <= (y)))
# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define ISHIGHTER(x, y) (((x) > (y)) ? (1) : (-1))
# define GET_RADIAN(x) (((x) * M_PI) / 180.0)
# define IDEB(x) my_printf("%d\n", x);
# define BLK (1)
# define FBLK ((float) BLK)
# define BUF_SIZE (4096)
# define RENDER_DIST (50.f)
# define MINI_MAP_PRATIO (10)
# define MIN_FOV (5)
# define MAX_FOV (160)

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

typedef struct	s_h_line
{
  int		x;
  int		y;
  int		len;
}		t_h_line;

typedef struct	s_ray
{
  float		len;
  int		val;
  int		side;
  sfVector2f	delta_dist;
  t_h_line	line;
}		t_ray;

typedef struct		s_win_dep
{
  int			w;
  int			h;
  sfRenderWindow	*win;
  sfTexture		*tex;
  t_fb			*buffer;
  sfSprite		*sprite;
  t_ray			*ray_buffer;
  int			close;
}			t_win_dep;

typedef struct	s_wolf
{
  sfVector2f	player;
  float		a_dir;
  sfVector2f	dep_vec;
  float		dir;
  int		fov;
  float		dpp;
  t_map		*map;
  t_params	*parms;
}		t_wolf;

typedef	struct	s_move_event
{
  sfKeyCode	key;
  float		x_axis;
  float		y_axis;
  float		angle;
  int		(*fct)(t_win_dep *, t_wolf *); 
}		t_move_event;

/*
** Wolf functions
*/
int	wolf(t_win_dep *win, t_wolf *map);
int	init_win_dep(t_win_dep *win, char *win_title,
		     int w, int h);

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
void	free_fb(t_my_framebuffer *to_free);
void	clear_fb(t_my_framebuffer *fb);
void	my_draw_vertical_line(t_my_framebuffer *fb, sfVector2i f,
			      int len, sfColor color);
void	my_draw_line(t_my_framebuffer *fb, sfVector2i f,
		     sfVector2i t, sfColor color);

/*
** Projections
*/
void		raycast(t_ray *ray, sfVector2f pos,
			float direction, int **map);
sfVector2f	move_forward(sfVector2f pos, float direction,
			     float distance);
void		get_ray_projections(t_wolf *map, t_ray *buffer,
				      t_win_dep *win);
/*
** Event Functions
*/
void	event(t_win_dep *win, t_wolf *wolf);
int	run_keypressed(t_win_dep *win, t_wolf *wolf);
int	close_evt(t_win_dep *win, t_wolf *wolf);
int	decr_fov(t_win_dep *win, t_wolf *wolf);
int	incr_fov(t_win_dep *win, t_wolf *wolf);
void	calculate_pp(t_win_dep *win, t_wolf *wolf);

/*
** Utils
*/
sfColor	get_color_by_ray(t_ray *ray);
int	inter(int x, int min, int max, int check_type);
int	read_to_end(char *file, char **res);

#endif /* !WOLF_H_ */
