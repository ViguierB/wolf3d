/*
** my_strncpy.c for my_strncpy.c in /home/benji_epitech/workdir/d6
** 
** Made by Benjamin Viguier
** Login   <benji_epitech@epitech.net>
** 
** Started on  Mon Oct 10 09:25:24 2016 Benjamin Viguier
** Last update Mon Oct 10 09:34:39 2016 Benjamin Viguier
*/

char *my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && (src[i] != '\0'))
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}
