/*
** EPITECH PROJECT, 2018
** @@@
** File description:
** include proto and lib
*/

#ifndef LIB
#define LIB

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE (1000)

int strlen_tab(char **tab);
int len_tab(char **tab);
int my_getnbr(char *str);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char *str);
void my_put_nbr(int nb);
char *nbr_to_str(int nb);
int my_strcomp(char *src, char *dest);
char *my_strdup(char const *str);
void put_tab(char **tab);
void free_tab(char **array);
char *clean_malloc(int size);
char *get_next_line(int fd);
int howmany_array(char *str, char sep_c);
char **strtoword_array(char *str, char sep_c);
int isit_number(char *str);
int isit_alpha(char *str);
void put_tab(char **tab);

#endif
