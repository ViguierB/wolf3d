/*
** my_strcmp.c for my_strcmp.c in /home/benji_epitech/workdir/d6
** 
** Made by Benjamin Viguier
** Login   <benji_epitech@epitech.net>
** 
** Started on  Mon Oct 10 10:28:02 2016 Benjamin Viguier
** Last update Tue Oct 18 10:32:57 2016 Benjamin Viguier
*/

int my_strcmp(char *s1, char *s2)
{
  while (*s1 != '\0' && (*s1 == *s2))
    {
      s1 += 1;
      s2 += 1;
    }
  if (*((unsigned char*) s1) < *((unsigned char*) s2))
    return (-1);
  else if (*((unsigned char*) s1) > *((unsigned char*) s2))
    return (1);
  else
    return (0);
}
