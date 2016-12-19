/*
** my_strcpy.c for my_strcpy.c in /home/benji_epitech/workdir/d6
** 
** Made by Benjamin Viguier
** Login   <benji_epitech@epitech.net>
** 
** Started on  Mon Oct 10 09:12:34 2016 Benjamin Viguier
** Last update Tue Oct 11 09:30:27 2016 Benjamin Viguier
*/

char *my_strcpy(char *dest, char *src)
{
  if (src[0] == '\0')
    dest[0] = '\0';
  else
    {
      my_strcpy(dest + 1, src + 1);
      dest[0] = src[0];
    }
  return (dest);
}
