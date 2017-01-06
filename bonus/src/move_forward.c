/*
** move_forward.c for bswolf3d in /home/benji_epitech/C_Graph_Prog/bswolf3d
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Dec 16 14:21:12 2016 Benjamin Viguier
** Last update Tue Jan  3 16:52:31 2017 Benjamin Viguier
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  direction = GET_RADIAN(direction);
  pos.x += (cos(direction) * distance);
  pos.y += (sin(direction) * distance);
  return (pos);
}
