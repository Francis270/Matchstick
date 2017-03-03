/*
** my_str_lib2.c for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/CPE_2016_matchstick/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 18:24:17 2017 Francois Caicedo
** Last update Thu Feb 16 15:56:07 2017 Francois Caicedo
*/

#include "matchstick.h"

int	my_str_is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 48 || str[i] > 57)
	return (-1);
      i++;
    }
  return (0);
}
