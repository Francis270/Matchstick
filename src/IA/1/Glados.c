/*
** Glados.c for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/src/IA/1/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Sun Feb 19 14:51:06 2017 Francois Caicedo
** Last update Sat Feb 25 13:38:47 2017 Francois Caicedo
*/

#include "matchstick.h"

t_bot		*glados(t_bot *bot, t_game *game)
{
  srand(time(NULL));
  bot->nb_alum = 2;
  while (get_alum_max(bot, game, bot->nb_line) < 1)
    bot->nb_line = rand_x_y(1, game->size);
  if (lines_without_0(bot, game) == 1 &&
      get_alum_max(bot, game, bot->nb_line) > 1)
    {
      if (get_alum_max(bot, game, bot->nb_line) - 1 > game->matches_max)
	bot->nb_alum = game->matches_max;
      else if (get_alum_max(bot, game, bot->nb_line) - 1 <= game->matches_max)
	bot->nb_alum = get_alum_max(bot, game, bot->nb_line) - 1;
    }
  else
    {
      while ((bot->nb_alum % 2) == 0)
	{
	  if (get_alum_max(bot, game, bot->nb_line) > game->matches_max)
	    bot->nb_alum = rand_x_y(1, game->matches_max);
	  else if (get_alum_max(bot, game, bot->nb_line) <= game->matches_max)
	    bot->nb_alum = rand_x_y(1, get_alum_max(bot, game, bot->nb_line));
	}
    }
  return (bot);
}
