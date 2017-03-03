/*
** matchstick.c for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 14 17:15:40 2017 Francois Caicedo
** Last update Sat Feb 18 18:49:40 2017 Francois Caicedo
*/

#include "matchstick.h"

char	**setup_sticks(t_game *game)
{
  int	i;
  int	j;
  int	k;

  i = 1;
  while (i < game->size + 1)
    {
      j = (game->x - 1) / 2;
      k = j;
      if (i > 1)
	{
	  while (j < i + (game->x - 1) / 2)
	    {
	      game->plan[i][j++] = '|';
	      game->plan[i][k--] = '|';
	    }
	}
      game->plan[i++][(game->x - 1) / 2] = '|';
    }
  return (game->plan);
}

char	**setup_stars(t_game *game)
{
  int	i;

  i = 0;
  while (i < game->x)
    game->plan[0][i++] = '*';
  i = 0;
  while (i < game->x)
    game->plan[game->y - 1][i++] = '*';
  i = 0;
  while (i < game->y)
    game->plan[i++][0] = '*';
  i = 0;
  while (i < game->y)
    game->plan[i++][game->x - 1] = '*';
  return (game->plan);
}

char	**setup_plan(t_game *game)
{
  int	i;
  int	j;

  i = 0;
  if ((game->plan = malloc(sizeof(char *) * (game->y + 1))) == NULL)
    return (NULL);
  while (i < game->y)
    {
      j = 0;
      if ((game->plan[i] = malloc(sizeof(char) * (game->x + 1))) == NULL)
	return (NULL);
      while (j < game->x)
	game->plan[i][j++] = ' ';
      game->plan[i][j] = '\0';
      i++;
    }
  game->plan[game->y] = '\0';
  game->plan = setup_stars(game);
  game->plan = setup_sticks(game);
  return (game->plan);
}

int		matchstick(char **argv, t_game *game)
{
  game->matches_max = my_getnbr(argv[2]);
  game->size = my_getnbr(argv[1]);
  game->y = game->size + 2;
  game->x = (game->size * 2) + 1;
  if (game->size < 1 || game->size > 100 || my_str_is_num(argv[1]) == -1 ||
      my_str_is_num(argv[2]) == -1 || game->matches_max <= 0)
    return (-1);
  if ((game->plan = setup_plan(game)) == NULL)
    return (-1);
  my_show_wordtab(game->plan);
  my_putchar('\n');
  if (play(game) == -1)
    return (-1);
  my_free_wordtab(game->plan);
  return (0);
}
