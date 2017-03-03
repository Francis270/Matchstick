##
## Makefile for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/CPE_2016_matchstick/
##
## Made by Francois Caicedo
## Login   <francois.caicedo@epitech.eu@epitech.eu>
##
## Started on  Mon Feb 13 10:05:29 2017 Francois Caicedo
## Last update Tue Feb 21 19:13:13 2017 Francois Caicedo
##

NAME	= matchstick

SRCS	= main.c						\
	  base_game/matchstick.c				\
	  base_game/game.c					\
	  base_game/turn.c					\
	  IA/BOT.c						\
	  IA/1/Glados.c						\
	  lib/my_str_lib.c					\
	  lib/my_str_lib2.c					\
	  lib/my_put_lib.c					\
	  lib/my_len_lib.c					\
	  lib/my_alloc_lib.c					\
	  lib/my_get_lib.c					\
	  lib/my_strn_lib.c					\
	  lib/my_wordtab_lib.c					\

OBJS		= $(addprefix src/, $(SRCS:.c=.o))

CC		= gcc

RM		= rm -f

CFLAGS		= -Iinclude/
CFLAGS		+= -W -Wall -Wextra -Werror
CFLAGS		+= -Wno-unused-parameter
CFLAGS		+= -ansi -pedantic
CFLAGS		+= $(LIBS)
CFLAGS		+= -g

LDFLAGS		= $(LIBS)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
