/*
** my_str_lib.c for str_lib in /home/francis/Documents/LIB/libc/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Jan 26 01:56:20 2017 Francois Caicedo
** Last update Mon Feb 13 10:34:52 2017 Francois Caicedo
*/

#include "matchstick.h"

char	*my_strcat(char *dest, const char *src)
{
  int	len;
  int	i;

  len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
  return (dest);
}

int     my_strcmp(const char *s1, const char *s2)
{
  int   i;

  i = 0;
  if (s1 == NULL)
    return (2);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != '\0')
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
				return (1);
      i++;
    }
  return (0);
}

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(const char *str)
{
  char	*new;
  int	i;

  if ((new = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      new[i] = str[i];
      i++;
    }
  return (new);
}

char	*convert_int_to_str(int i)
{
  char	*str;
  char	*tmp;
  int	j;
  int	k;

  if ((str = malloc(sizeof(char) * 15)) == NULL)
    return (NULL);
  if ((tmp = malloc(sizeof(char) * 15)) == NULL)
    return (NULL);
  j = 0;
  k = 0;
  while (i != 0)
    {
      tmp[j++] = (i % 10) + '0';
      i /= 10;
    }
  tmp[j] = '\0';
  j = 0;
  while (tmp[j])
    str[my_strlen(tmp) -1 - k++] = tmp[j++];
  str[my_strlen(tmp)] = '\0';
  free(tmp);
  return (str);
}
