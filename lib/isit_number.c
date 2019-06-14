/*
** EPITECH PROJECT, 2019
** base_repo
** File description:
** isit_number
*/

#include "lib.h"

int isit_number(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}
