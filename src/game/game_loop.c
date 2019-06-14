/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** game_loop
*/

#include "my.h"

navy_t navy;

void reset_pos(void)
{
    NAVY.command_x = 0;
    NAVY.command_y = 0;
    NAVY.touch = 0;
}

int take_command(void)
{
    char *input = NULL;
    int x = 0;
    int y = 0;

    if ((input = take_input()) == NULL)
        return (84);
    if (input != NULL) {
        x = input[0] - 'A';
        y = input[1] - '0';
    }
    NAVY.command_x = x;
    NAVY.command_y = y;
    free(input);
    return (0);
}

int check_game_status(char **player_map, char **enemy_map)
{
    if (NAVY.pl_boat == 14) {
        my_putstr("my positions:\n");
        print_map(player_map);
        my_putstr("enemy's positions:\n");
        print_map(enemy_map);
        write(1, "Enemy won\n", 11);
        return (1);
    } else if (NAVY.en_boat == 14) {
        my_putstr("my positions:\n");
        print_map(player_map);
        my_putstr("enemy's positions:\n");
        print_map(enemy_map);
        write(1, "I won\n", 7);
        return (0);
    }
    return (-1);
}

int set_loop_one(char **player_map, char **enemy_map)
{
    int end_game = -1;

    while (1) {
        reset_pos();
        print_game_map(player_map, enemy_map);
        if (take_command() == 84)
            return (84);
        send_signal();
        get_game_signal_usr1();
        enemy_map = update_map(enemy_map, NAVY.touch);
        reset_pos();
        if ((end_game = check_game_status(player_map, enemy_map)) != -1)
            return (end_game);
        my_putstr("waiting for enemy's attack...\n");
        get_game_signal_usr2();
        if ((player_map = thereis_boat(player_map)) == NULL)
            return (84);
        if ((end_game = check_game_status(player_map, enemy_map)) != -1)
            return (end_game);
    }
}

int set_loop_two(char **player_map, char **enemy_map)
{
    int end_game = -1;

    while (1) {
        reset_pos();
        print_game_map(player_map, enemy_map);
        my_putstr("waiting for enemy's attack...\n");
        get_game_signal_usr2();
        if ((player_map = thereis_boat(player_map)) == NULL)
            return (84);
        reset_pos();
        if ((end_game = check_game_status(player_map, enemy_map)) != -1)
            return (end_game);
        if (take_command() == 84)
            return (84);
        send_signal();
        get_game_signal_usr1();
        enemy_map = update_map(enemy_map, NAVY.touch);
        if ((end_game = check_game_status(player_map, enemy_map)) != -1)
            return (end_game);
    }
}
