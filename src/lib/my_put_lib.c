/*
** my_put_lib.c for put_lib in /home/francis/Documents/LIB/libc/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Jan 26 01:59:51 2017 Francois Caicedo
** Last update Mon Feb 13 10:35:19 2017 Francois Caicedo
*/

#include "matchstick.h"

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

int	my_put_error(char *str)
{
  return (write(2, str, my_strlen(str)));
}

int	my_put_nbr(int nb)
{
  int	pow;
  int	i;

  i = 0;
  if (nb < 0)
    {
      nb = -nb;
      i = i + my_putchar('-');
    }
  pow = 1;
  while (pow * 10 <= nb)
    {
      pow = pow * 10;
    }
  while (pow > 0)
    {
      i = i + my_putchar('0' + (nb / pow % 10));
      pow = pow / 10;
    }
  return (i);
}
