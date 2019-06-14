/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check input error
*/

#include "my.h"

int input_error(char *input)
{
    if ((input[0] < 'A' && input[0] > 'H') ||
        (input[1] < '1' && input[1] > '8') ||
        input[2] != '\n')
        return (1);
    return (0);
}