/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** free
*/

#include "my.h"

void free_all(char **pos_file, char **player_map, char **enemy_map)
{
    if (pos_file != NULL)
        free_tab(pos_file);
    if (player_map != NULL)
        free_tab(player_map);
    if (enemy_map != NULL)
        free_tab(enemy_map);
}