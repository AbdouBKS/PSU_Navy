/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** check_boat
*/

#include "my.h"

navy_t navy;

int still_boat(char **map)
{
    int i = 0;
    int j = 0;
    int nb_x = 0;

    while (i < 9) {
        while (j < 18) {
            if (map[i][j] == 'x')
                ++nb_x;
            ++j;
        }
        j = 0;
        ++i;
    }
    if (nb_x == 14)
        return (1);
    else
        return (0);
}