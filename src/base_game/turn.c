/*
** turn.c for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 14 19:42:09 2017 Francois Caicedo
** Last update Sat Feb 25 02:43:52 2017 Francois Caicedo
*/

#include "matchstick.h"

int		game_is_won(t_game *game)
{
  int	nb;
  int	i;
  int	j;

  nb = 0;
  i = 0;
  while (i < game->y)
    {
      j = 0;
      while (j < game->x)
	{
	  if (game->plan[i][j] == '|')
	    nb++;
	  j++;
	}
      i++;
    }
  if (nb == 0)
    return (0);
  return (-1);
}

void		display(t_game *game)
{
  my_putstr("Player removed ");
  my_put_nbr(game->nb_alum);
  my_putstr(" match(es) from line ");
  my_put_nbr(game->nb_line);
  my_putchar('\n');
}

t_game		*remove_alum(t_game *game)
{
  int	i;
  int	j;

  i = 0;
  while (i < game->nb_alum)
    {
      j = game->x;
      while (game->plan[game->nb_line][j] != '|')
	j--;
      game->plan[game->nb_line][j] = ' ';
      i++;
    }
  return (game);
}

t_bot		*init_bot(t_bot *bot)
{
  if ((bot = malloc(sizeof *bot)) == NULL)
    return (NULL);
  bot->nb_line = 0;
  bot->nb_alum = 0;
  bot->tab = NULL;
  return (bot);
}

int		BOT_turn(t_game *game)
{
  t_bot		*bot;
  bot = NULL;
  if ((bot = init_bot(bot)) == NULL)
    return (-1);
  my_putstr("AI's turn...\n");
  my_putstr("AI removed ");
  if ((bot = bot_main(bot, game)) == NULL)
    return (-1);
  game->nb_line = bot->nb_line;
  game->nb_alum = bot->nb_alum;
  game = remove_alum(game);
  my_put_nbr(game->nb_alum);
  my_putstr(" match(es) from line ");
  my_put_nbr(game->nb_line);
  my_putchar('\n');
  free(bot->tab);
  free(bot);
  return (0);
}
