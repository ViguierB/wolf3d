/*
** my_split.c for  in /home/benji_epitech/C_Graph_Prog/wireframe
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Dec  7 11:25:33 2016 Benjamin Viguier
** Last update Mon Dec 19 15:01:46 2016 Benjamin Viguier
*/

#include "my.h"

char	**pass_two(char **res, char *tmp, char *inp, char sep)
{
  int	i;
  int	lines;

  i = 0;
  lines = 1;
  res[0] = tmp;
  while (inp[i])
    {
      if (inp[i] == sep)
	{
	  res[lines] = (tmp + i + 1);
	  tmp[i] = '\0';
	  lines += 1;
	}
      i += 1;
    }
  return (res);
}

char	**my_split(char *inp, char sep, int *nb_lines)
{
  char	**res;
  char	*tmp;
  int	i;
  int	lines;

  i = 0;
  lines = 1;
  while (inp[i])
    {
      if (inp[i] == sep)
	lines += 1;
      i += 1;
    }
  tmp = my_strdup(inp);
  res = malloc(sizeof(char*) * (lines + 1));
  if (!tmp || !res)
    return (NULL);
  res[lines] = NULL;
  if (nb_lines)
    *nb_lines = lines - 1;
  return (pass_two(res, tmp, inp, sep));
}
