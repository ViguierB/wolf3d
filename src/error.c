/*
** error.c for wold3d in /home/benji_epitech/C_Graph_Prog/wolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Dec 19 16:27:19 2016 Benjamin Viguier
** Last update Mon Dec 26 18:47:28 2016 Benjamin Viguier
*/

#include "error.h"

const t_err_msg const	msg_tab[] =
  {
    {-1, "No more memory avaible"},
    {-2, "Cannot open : "},
    {-3, "Invalide char in map"},
    {0, NULL}
  };

int	on_error(int error_code, char *more)
{
  int	i;

  i = 0;
  while (msg_tab[i].code)
    {
      if (error_code == msg_tab[i].code)
	{
	  my_fprintf(S_ERR, "%s%s\n", msg_tab[i].msg, more);
	  return (84);
	}
    }
  my_fprintf(S_ERR, "Unknow error\n");
  return (84);
}
