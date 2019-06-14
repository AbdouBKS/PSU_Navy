/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** ennemy_map
*/

#include "my.h"

navy_t navy;

char **create_enemy_map(void)
{
    char **enemy_map = initiate_player_map();

    if (enemy_map == NULL)
        return (NULL);
    return (enemy_map);
}

char **thereis_boat(char **map)
{
    int pos_x = (NAVY.command_x + 1) * 2;
    int pos_y = NAVY.command_y + 1;

    if (NAVY.command_x == 'I' - 'A' &&
        NAVY.command_y == '9' - '0')
        return (NULL);
    if (map[pos_y][pos_x] >= '2' && map[pos_y][pos_x] <= '5') {
        ++NAVY.pl_boat;
        map = update_map(map, 2);
        kill(NAVY.pid_enemy, 10);
        usleep(5000);
    }
    else {
        if (map[pos_y][pos_x] != 'x') {
            map = update_map(map, 1);
        }
        kill(NAVY.pid_enemy, 12);
        usleep(5000);
    }
    return (map);
}