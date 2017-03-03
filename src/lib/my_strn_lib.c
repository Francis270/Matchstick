/*
** my_strn_lib.c for strn_lib in /home/francis/Documents/LIB/libc/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Jan 26 01:58:43 2017 Francois Caicedo
** Last update Mon Feb 13 10:35:17 2017 Francois Caicedo
*/

#include "matchstick.h"

char	*my_strncat(char *dest, const char *src, int n)
{
  int	len;
  int	i;

  len = my_strlen(dest);
  i = 0;
  while (src[i] && i < n)
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
  return (dest);
}

int	my_strncmp(const char *s1, const char *s2, int n)
{
  int   i;

  i = 0;
  if (s1 == NULL)
    return (2);
  while (s2[i] && i < n)
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
	return (1);
      i++;
    }
  return (0);
}

char	*my_strncpy(char *dest, const char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strndup(const char *str, int n)
{
  char	*new;
  int	i;

  if ((new = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] && i < n)
    {
      new[i] = str[i];
      i++;
    }
  return (new);
}
