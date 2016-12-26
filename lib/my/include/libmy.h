/*
** libmy.h for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_sokoban
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 12 13:19:11 2016 Benjamin Viguier
** Last update Thu Dec 22 17:11:15 2016 Benjamin Viguier
*/

#ifndef LIBMY_H_
# define LIBMY_H_

# include <stdlib.h>

# define S_IN 0
# define S_OUT 1
# define S_ERR 2
# define MY_FD_BUFF_LEN 512

typedef struct	s_my_fd
{
  int		fd;
  char		buffer[MY_FD_BUFF_LEN];
  int		index;
}		t_my_fd;

typedef struct		s_clist
{
  void			*ptr;
  struct s_clist	*next;
  struct s_clist	*prev;
}			t_clist;
typedef t_clist		t_clist_elm;
typedef unsigned	t_uint;

/*
** Circular Linked List
*/
t_clist	*clist_push(t_clist *l, void *ptr);
void	clist_swap_val(t_clist_elm *elm1, t_clist_elm *elm2);
void	clist_free(t_clist *l);
void	clist_free_data(t_clist *l, void (*myfree)(void*));

/*
** Basics Functs
** Notes :
**	- nb_lines for my_split is optionnal,
**		use NULL if u don't want to use it.
*/
int	my_printf(char *fmt, ...);
int	my_fprintf(int fd, char *fmt, ...);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_puterror(char *error_str);
int	my_strlen(char *str);
int	my_malloc(void *ptr, size_t len);
char	*my_strconca(char *str1, char *str2);
char	*my_strcpy(char *dest, char *from);
char	*my_strncpy(char *dest, char *from, int n);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *str);
char	**my_split(char *inp, char sep, int *nb_lines);

/*
** my_fd functions
*/
t_my_fd	*my_fopen(char *path, int flags);
void	my_fclose(t_my_fd *to_free);

#endif /* !LIBMY_H_ */
