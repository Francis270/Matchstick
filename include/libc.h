/*
** libc.h for matchstick in /home/francis/Documents/CPE/CPE_2016_matchstick/CPE_2016_matchstick/include/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 10:05:42 2017 Francois Caicedo
** Last update Sat Feb 18 19:17:40 2017 Francois Caicedo
*/

#ifndef LIBC_H_
# define LIBC_H_

#include <unistd.h>
#include <stdlib.h>
#define READ_SIZE (1024)

void	*my_memset(void	*dest, const char src, int n);
void	*my_memcpy(void	*dest, const void *src, int n);
void	*my_realloc(char *ptr, int size);

char 	last_char_from_buffer(const int fd);
char 	*get_next_line(const int fd);
int	my_getnbr(const char *str);

int	my_strlen(const char *str);
int	my_intlen(int *nb);
int	my_tablen(char **tab);

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_put_error(char *str);
int	my_put_nbr(int nb);

char	*my_strcat(char *dest, const char *src);
int     my_strcmp(const char *s1, const char *s2);
char	*my_strcpy(char *dest, const char *src);
char	*my_strdup(const char *str);
char	*convert_int_to_str(int i);

int	my_str_is_num(char *str);

char	*my_strncat(char *dest, const char *src, int nb);
int	my_strncmp(const char *s1, const char *s2, int n);
char	*my_strncpy(char *dest, const char *src, int n);
char	*my_strndup(const char *str, int n);

void	my_show_wordtab(char **wordtab);
void	my_free_wordtab(char **wordtab);
int	count_word(char *str, char n);
int	word_len(char *str, char n, int i);
char	**my_str_to_wordtab(char *s, char n);

#endif /* LIBC_H_ */
