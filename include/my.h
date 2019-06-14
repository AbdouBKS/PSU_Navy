/*
** EPITECH PROJECT, 2018
** @@@
** File description:
** include proto and lib
*/

#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>
#include "struct.h"
#include "lib.h"

int helper(void);

int all_error(int ac, char **av);

int get_width(char *final_str);
void my_sleep(unsigned long int n);

char *read_pos_file(char *filepath);
char **str_to_tab(char *final_str);

void print_map(char **map);
int isit_horizontal(char *pos_boat);
char **create_player_map(char **pos_file);
char **create_enemy_map(void);
char **initiate_player_map(void);
char **update_map(char **map, int touch);
void print_game_map(char **player_map, char **enemy_map);
char **thereis_boat(char **map);
int still_boat(char **map);

int check_lenght(char *pos_file);
int check_signs(char *pos_file);
int check_letters(char *pos_file);
int check_numbers(char *pos_file);
int check_diff_lenght(char *pos_file);
int check_pos_file(char *pos_file);

void free_pos_file(char **tab);
void free_map(char **map);
void free_all(char **pos_file, char **player_map, char **enemy_map);
int connexion_player_two(char *p1_pid);
int connexion_player_one(void);
int check_connection(void);
int get_signal_usr2(void);

int set_loop_one(char **player_map, char **enemy_map);
int set_loop_two(char **player_map, char **enemy_map);
char *take_input(void);
int input_error(char *input);
int take_command(void);

int get_game_signal_usr2(void);
int get_game_signal_usr1(void);
void game_sig_two(int res_signal);
void game_sig_one(int res_signal);
int send_signal(void);
int get_signals_boat(void);

#endif