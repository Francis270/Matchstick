/*
** matchstick.h for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/CPE_2016_matchstick/include/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 10:05:22 2017 Francois Caicedo
** Last update Sat Feb 25 13:44:00 2017 Francois Caicedo
*/

#ifndef MATCHSTICK_H_
# define MATCHSTICK_H_

#include "libc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

typedef	struct	s_bot
{
  int		nb_line;
  int		nb_alum;
  int		*tab;
}		t_bot;

typedef struct	s_game
{
  int		matches_max;
  int		size;
  int		x;
  int		y;
  int		nb_line;
  int		nb_alum;
  int		nb_alum_max;
  char		*line;
  char		*alum;
  char		**plan;
  int		end_game;
}		t_game;

int		main(int argc, char **argv);
int		matchstick(char **argv, t_game *game);
int		play(t_game *game);
int		get_alum_dispo(t_game *game);
t_game		*remove_alum(t_game *game);
void		display(t_game *game);
int		BOT_turn(t_game *game);
int		game_is_won(t_game *game);
t_bot		*init_bot(t_bot *bot);
int		get_alum_max(t_bot *bot, t_game *game, int i);
int		rand_x_y(int min, int max);
int		lines_without_0(t_bot *bot, t_game *game);
t_bot		*bot_main(t_bot *bot, t_game *game);
t_bot		*glados(t_bot *bot, t_game *game);

#endif /* MATCHSTICK_H_ */
