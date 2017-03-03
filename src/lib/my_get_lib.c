/*
** my_get_lib.c for get_lib in /home/francis/Documents/LIB/libc/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Jan 26 02:02:13 2017 Francois Caicedo
** Last update Thu Feb 23 16:50:50 2017 Francois Caicedo
*/

#include "matchstick.h"

char 	last_char_from_buffer(const int fd)
{
  static char buf[READ_SIZE];
  static char *save;
  static int 	rd = 0;
  char 	c;

  if (rd == 0)
    {
      rd = read(fd, buf, READ_SIZE);
      save = (char*)&buf;
      if (rd == 0)
	return (0);
    }
  rd--;
  return (c = *save++);
}

char 	*get_next_line(const int fd)
{
  char* str;
  int	alloc;
  int 	i;
  char 	c;

  alloc = 0;
  i = 0;
  if ((str = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  c = last_char_from_buffer(fd);
  if (c == '\0')
    return ("exit");
  while (c != '\n' && c)
    {
      str[i++] = c;
      c = last_char_from_buffer(fd);
      alloc++;
      if (alloc == READ_SIZE)
	{
	  str = my_realloc(str, i + READ_SIZE + 1);
	  alloc = 0;
	}
    }
  str[i] = '\0';
  return (str);
}

int	my_getnbr(const char *str)
{
  int	i;
  int	sign;
  int	final;

  i = 0;
  sign = 1;
  final = 0;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	sign = - sign;
      i++;
    }
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      final = (final * 10 - '0' + str[i]);
      i++;
    }
  return (sign * final);
}
