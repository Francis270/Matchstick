/*
** my_len_lib.c for len_lib in /home/francis/Documents/LIB/libc/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Jan 26 02:05:42 2017 Francois Caicedo
** Last update Thu Feb 16 14:29:29 2017 Francois Caicedo
*/

#include "matchstick.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_intlen(int *nb)
{
  int	i;

  i = 0;
  while (nb[i] != -1)
    i++;
  return (i);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
