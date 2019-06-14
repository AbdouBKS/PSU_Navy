/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check pos file
*/

#include "my.h"

int check_diff_ship_lenght(char *pos_file)
{
    int i = 0;
    int turn = 0;

    while (turn < 4) {
        if ((pos_file[i + 6] - pos_file[i + 3]) != (pos_file[i] - '0' - 1)) {
            if ((pos_file[i + 5] - 'A' + 1) - (pos_file[i + 2] - 'A' + 1)
            != pos_file[i] - '0' - 1)
                return (1);
        }
        i += 8;
        ++turn;
    }
    return (0);
}

int check_pos_file(char *pos_file)
{
    if ((check_lenght(pos_file)) ||
        (check_signs(pos_file)) ||
        (check_letters(pos_file)) ||
        (check_numbers(pos_file)) ||
        (check_diff_lenght(pos_file)) ||
        (check_diff_ship_lenght(pos_file))) {
        free(pos_file);
        return (-1);
    }
    return (0);
}