/*
** BOT_Georges.c for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 14 23:21:24 2017 Francois Caicedo
** Last update Tue Feb 21 19:13:04 2017 Francois Caicedo
*/

#include "matchstick.h"

int		lines_without_0(t_bot *bot, t_game *game)
{
  int		nb;
  int		i;

  nb = 0;
  i = 0;
  while (i < game->size + 1)
    {
      if (bot->tab[i] > 0)
	nb++;
      i++;
    }
  return (nb);
}

int		rand_x_y(int min, int max)
{
  double	is_rand;
  int		inter;

  is_rand = rand() / (1.0 + RAND_MAX);
  inter = max - min + 1;
  return ((is_rand * inter) + min);
}

int		get_alum_max(t_bot *bot, t_game *game, int i)
{
  int		nb;
  int		j;

  nb = 0;
  j = 0;
  while (j < game->x)
    {
      if (game->plan[i][j] == '|')
	nb++;
      j++;
    }
  return (nb);
}

t_bot		*alloc_tab(t_bot *bot, t_game *game)
{
  int		i;

  i = 1;
  if ((bot->tab = malloc(sizeof(int) * game->y + 1)) == NULL)
    return (NULL);
  bot->tab[0] = -1;
  while (i < game->size + 1)
    {
      bot->tab[i] = get_alum_max(bot, game, i);
      i++;
    }
  return (bot);
}

t_bot		*bot_main(t_bot *bot, t_game *game)
{
  if ((bot = alloc_tab(bot, game)) == NULL)
    return (NULL);
  bot = glados(bot, game);
  return (bot);
}
