/*
** my_strlen.c for my_strlen.c in /home/benji_epitech/workdir/d4
** 
** Made by Benjamin Viguier
** Login   <benji_epitech@epitech.net>
** 
** Started on  Thu Oct  6 11:28:01 2016 Benjamin Viguier
** Last update Fri Nov 25 18:07:24 2016 Benjamin Viguier
*/

int my_strlen(char *str)
{
  int	count;

  count = 0;
  if (str == (void*) 0)
    return (0);
  while (*(str + count) != '\0')
    count += 1;
  return (count);
}
