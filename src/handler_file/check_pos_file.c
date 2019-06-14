/*
** EPITECH PROJECT, 2019
** navy
** File description:
** error handling of pos file
*/

#include "my.h"

int check_lenght(char *pos_file)
{
    int i = 0;
    int nb_line = 0;
    int len_line = 0;

    while (pos_file[i] != '\0') {
        if (pos_file[i] == '\n') {
            ++nb_line;
            if ((i == 7 && len_line != 7) || (i != 7 && len_line != 8))
                return (1);
            len_line = 0;
        }
        ++i;
        ++len_line;
    }
    if (nb_line != 3)
        return (1);
    return (0);
}

int check_signs(char *pos_file)
{
    int i = 0;

    if (pos_file[i + 1] != ':' || pos_file[i + 4] != ':')
        return (1);
    while (pos_file[i] != '\0') {
        if (pos_file[i] == '\n') {
            if (pos_file[i + 2] != ':' ||
                pos_file[i + 5] != ':')
                return (1);
        }
        ++i;
    }
    return (0);
}

int check_letters(char *pos_file)
{
    int i = 0;

    if ((pos_file[2] < 'A' && pos_file[2] > 'H') ||
        (pos_file[5] < 'A' && pos_file[5] > 'H'))
        return (1);
    while (pos_file[i] != '\0') {
        if (pos_file[i] == '\n') {
            if ((pos_file[i + 3] < 'A' && pos_file[i + 3] > 'H') ||
                (pos_file[i + 6] < 'A' && pos_file[i + 6] > 'H'))
                return (1);
        }
        ++i;
    }
    return (0);
}

int check_numbers(char *pos_file)
{
    int i = 0;
    int turn = 0;

    while (turn < 4) {
        if ((pos_file[i + 3] < '1' && pos_file[i + 3] > '9') ||
            (pos_file[i + 6] < '1' && pos_file[i + 6] > '9'))
            return (1);
        i += 8;
        ++turn;
    }
    return (0);
}

int check_diff_lenght(char *pos_file)
{
    int i = 0;
    int turn = 0;
    int total_size = 0;

    while (turn < 4) {
        total_size = total_size + (pos_file[i] - '0');
        i += 8;
        ++turn;
    }
    if (total_size != 14)
        return (1);
    return (0);
}