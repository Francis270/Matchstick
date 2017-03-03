/*
** game.c for game in /home/francis/Documents/CPE/CPE_2016_matchstick/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 14 17:42:15 2017 Francois Caicedo
** Last update Sat Feb 25 02:43:55 2017 Francois Caicedo
*/

#include "matchstick.h"

int		get_alum_dispo(t_game *game)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  if (game->nb_line > game->size || game->nb_line <= 0)
    return (0);
  while (i < game->x)
    {
      if (game->plan[game->nb_line][i] == '|')
	nb++;
      i++;
    }
  return (nb);
}

t_game		*get_line(t_game *game)
{
  game->nb_line = 0;
  game->nb_alum_max = get_alum_dispo(game);
  my_putstr("Line: ");
  if ((game->line = get_next_line(0)) == NULL)
    return (NULL);
  if (my_strcmp(game->line, "exit") == 0)
    {
      game->end_game = 3;
      return (game);
    }
  game->nb_line = my_getnbr(game->line);
  if (my_str_is_num(game->line) == -1)
    game->nb_line = -10;
  if (game->nb_line < 0)
    my_putstr("Error: invalid input (positive number expected)\n");
  else if (game->nb_line == 0 || game->nb_line > game->size)
    my_putstr("Error: this line is out of range\n");
  return (game);
}

t_game		*get_matches(t_game *game)
{
  my_putstr("Matches: ");
  if ((game->alum = get_next_line(0)) == NULL)
    return (NULL);
  if (my_strcmp(game->alum, "exit") == 0)
    {
      game->end_game = 3;
      return (game);
    }
  game->nb_alum = my_getnbr(game->alum);
  if (my_str_is_num(game->alum) == -1)
    game->nb_alum = -10;
  if (game->nb_alum > game->matches_max)
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(game->matches_max);
      my_putstr(" matches per turn\n");
      game->nb_alum = 0;
    }
  else if (game->nb_alum < 0 || my_str_is_num(game->alum) == -1)
    my_putstr("Error: invalid input (positive number expected)\n");
  else if (game->nb_alum == 0)
    my_putstr("Error: you have to remove at least one match\n");
  else if (game->nb_alum > game->nb_alum_max)
    my_putstr("Error: not enough matches on this line\n");
  return (game);
}

int		player_turn(t_game *game, int i)
{
  while (i != 2)
    {
      game->nb_line = 0;
      if (i == 1)
	{
	  while ((game->nb_line > game->size || game->nb_line < 1) &&
		 game->end_game != 3)
	      if ((game = get_line(game)) == NULL)
		return (-1);
	  i++;
	  if (game->end_game == 3)
	    return (0);
	}
      if (i == 2)
	{
	  game->nb_alum_max = get_alum_dispo(game);
	  if ((game = get_matches(game)) == NULL)
	    return (-1);
	  if (game->end_game == 3)
	    return (0);
	  i = (game->nb_alum > game->nb_alum_max || game->nb_alum < 1 ||
	       game->nb_alum_max < 1) ? 1 : 2;
	}
    }
  return (0);
}

int		play(t_game *game)
{
  while (1)
    {
      my_putstr("Your turn:\n");
      if ((player_turn(game, 1)) == -1)
	return (-1);
      if (game->end_game == 3)
	return (0);
      game = remove_alum(game);
      display(game);
      my_show_wordtab(game->plan);
      if ((game_is_won(game)) == 0)
	return (game->end_game = 2);
      my_putchar('\n');
      if ((BOT_turn(game)) == -1)
	return (-1);
      my_show_wordtab(game->plan);
      if ((game_is_won(game)) == 0)
	return (game->end_game = 1);
      my_putchar('\n');
    }
  return (0);
}
