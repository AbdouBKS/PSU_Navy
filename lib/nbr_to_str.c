/*
** EPITECH PROJECT, 2019
** sysfun
** File description:
** nbr_to_str
*/

#include <stdio.h>
#include <stdlib.h>

int get_nb_digit(int nb)
{
    int nb_digit = 1;

    while (nb > 10) {
        nb = nb / 10;
        ++nb_digit;
    }
    return (nb_digit);
}

char *alloc_nbr(int nb)
{
    int nb_digit = get_nb_digit(nb);
    char *dest = NULL;
    int i = 0;

    if ((dest = malloc(sizeof(char) * nb_digit + 1)) == NULL)
        return (NULL);
    while (i < nb_digit + 1)
        dest[i++] = '\0';
    return (dest);
}

char *get_nbr(int nb)
{
    char *dest = NULL;
    int i = get_nb_digit(nb) - 1;

    if ((dest = alloc_nbr(nb)) == NULL)
        return (NULL);
    while (nb > 0) {
        dest[i--] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (dest);
}
