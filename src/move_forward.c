/*
** move_forward.c for bswolf3d in /home/benji_epitech/C_Graph_Prog/bswolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Dec 16 14:21:12 2016 Benjamin Viguier
** Last update Mon Dec 19 10:51:24 2016 Benjamin Viguier
*/

#include <math.h>

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  direction = (direction * M_PI) / 180;
  pos.x += (sin(direction) * distance);
  pos.y += (cos(direction) * distance);
  return (pos);
}
