/*
** my_alloc_lib.c for alloc_lib in /home/francis/Documents/LIB/libc/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Jan 26 02:04:42 2017 Francois Caicedo
** Last update Mon Feb 13 10:34:56 2017 Francois Caicedo
*/

#include "matchstick.h"

void		*my_memcpy(void	*dest, const void *src, int n)
{
  char		*ptr_dest;
  int		i;
  const	char	*ptr_src;

  ptr_dest = (char*)dest;
  ptr_src = (char*)src;
  i = 0;
  while (i < n)
    {
      ptr_dest[i] = ptr_src[i];
      i++;
    }
  ptr_dest[i] = '\0';
  return (dest);
}

void	*my_realloc(char *ptr, int size)
{
  void	*newmem;

  if (size == 0 && ptr != NULL)
    {
      free(ptr);
      return (NULL);
    }
  if (ptr == NULL)
    return (malloc(size));
  if ((newmem = malloc(size)) == NULL)
    return (NULL);
  my_strcpy(newmem, ptr);
  free(ptr);
  return (newmem);
}
