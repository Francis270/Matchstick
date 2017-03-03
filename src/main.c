/*
** main.c for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/CPE_2016_matchstick/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 10:05:15 2017 Francois Caicedo
** Last update Tue Feb 21 19:16:50 2017 Francois Caicedo
*/

#include "matchstick.h"

void		end(int return_value)
{
  if (return_value == 1)
    my_putstr("I lost... snif... but I’ll get you next time!!\n");
  else if (return_value == 2)
    my_putstr("You lost, too bad...\n");
  else if (return_value == 3)
    my_putchar('\n');
}

t_game		*init_game(t_game *game)
{
  if ((game = malloc(sizeof *game)) == NULL)
    return (NULL);
  game->end_game = 0;
  game->matches_max = 0;
  game->size = 0;
  game->x = 0;
  game->y = 0;
  game->nb_line = 0;
  game->nb_alum = 0;
  game->nb_alum_max = 0;
  game->line = NULL;
  game->alum = NULL;
  game->plan = NULL;
  return (game);
}

int		main(int argc, char **argv)
{
  t_game	*game;
  int		return_value;

  game = NULL;
  if ((game = init_game(game)) == NULL)
    return (84);
  if ((argc == 3) && (matchstick(argv, game)) == 0)
    {
      return_value = game->end_game;
      end(return_value);
      free(game);
      if (return_value == 0)
	return (0);
      else if (return_value == 1)
	return (1);
      else if (return_value == 2)
	return (2);
    }
  else
    return (84);
  return (0);
}
