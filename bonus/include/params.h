/*
** params.h for wolf3d in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Jan 11 13:33:27 2017 Benjamin Viguier
** Last update Wed Jan 11 16:55:51 2017 Benjamin Viguier
*/


#ifndef PARAMS_H_
# define PARAMS_H_

# define BASIC_W (1280)
# define BASIC_H (720)
# define BASIC_FOV (66)
# define BASIC_A_DIR (90.f)

typedef struct	s_params
{
  int		win_w;
  int		win_h;
  int		fov;
  float		a_dir;
  char		*map_file;
}		t_params;

typedef struct	s_parm_fct
{
  char		*flag;
  int		(*fct)(t_params *, char *);
}		t_parm_fct;

int	verif_params(t_params *parms, int ac, char **av);
int	init_params(t_params *params);
int	set_fov(t_params *parms, char *data);
int	set_win_size(t_params *parms, char *data);
int	set_dir(t_params *parms, char *data);
int	open_config(t_params *parms, char *data);
int	set_map_file(t_params *parms, char *data);
int	print_usage(t_params *parms, char *data);

#endif /* !PARAMS_H_ */
