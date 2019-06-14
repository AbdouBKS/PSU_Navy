/*
** EPITECH PROJECT, 2019
** navy
** File description:
** update map
*/

#include "my.h"

navy_t navy;

void print_game_map(char **player_map, char **enemy_map)
{
    my_putstr("my positions:\n");
    print_map(player_map);
    my_putstr("enemy's positions:\n");
    print_map(enemy_map);
}

char **update_map(char **map, int touch)
{
    int pos_x = (NAVY.command_x + 1) * 2;
    int pos_y = NAVY.command_y + 1;

    my_putchar(NAVY.command_x + 'A');
    my_putchar(NAVY.command_y + '0');
    if (touch == 2) {
        my_putstr(": hit\n\n");
        map[pos_y][pos_x] = 'x';
    } else if (touch == 1) {
        my_putstr(": missed\n\n");
        if (map[pos_y][pos_x] != 'x')
            map[pos_y][pos_x] = 'o';
    }
    return (map);
}