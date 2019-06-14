/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** fil_zero
*/

#include <stdio.h>
#include <stdlib.h>

char *fil_zero(char *str, int size)
{
    int i = 0;

    while (i < size + 1)
        str[i++] = '\0';
    return (str);
}

char *clean_malloc(int size)
{
    char *dest = malloc(sizeof(char) * size + 1);

    if (dest == NULL)
        return (NULL);
    dest = fil_zero(dest, size);
    return (dest);
}