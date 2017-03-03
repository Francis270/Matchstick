/*
** my_wordtab_lib.c for wordtab_lib in /home/francis/Documents/LIB/libc/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Jan 26 02:03:15 2017 Francois Caicedo
** Last update Mon Feb 13 10:35:14 2017 Francois Caicedo
*/

#include "matchstick.h"

void	my_show_wordtab(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab[i])
    {
      my_putstr(wordtab[i]);
      my_putchar('\n');
      i++;
    }
}

void	my_free_wordtab(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab[i])
    {
      free(wordtab[i]);
      i++;
    }
  free(wordtab);
}

int	count_word(char *str, char n)
{
  int	nb;
  int	i;

  i = 0;
  nb = 1;
  while (str[i])
    {
      if (str[i] == n)
	nb++;
      i++;
    }
  return (nb);
}

int	word_len(char *str, char n, int i)
{
  int	nb;

  nb = 0;
  while (str[i] != n && str[i])
    {
      nb++;
      i++;
    }
  return (nb);
}

char	**my_str_to_wordtab(char *s, char n)
{
  char	**wordtab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((wordtab = malloc(sizeof(char *) * ((count_word(s, n) + 1)))) == NULL)
    return (NULL);
  while (s[i] == n)
    i++;
  while (s[i])
    {
      k = 0;
      if ((wordtab[j] = malloc(sizeof(char) * word_len(s, n, i) + 1)) == NULL)
	return (NULL);
      while (s[i] != n && s[i])
	wordtab[j][k++] = s[i++];
      wordtab[j++][k] = '\0';
      while (s[i] == n)
	i++;
    }
  wordtab[j] = '\0';
  return (wordtab);
}
