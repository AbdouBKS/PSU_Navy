/*
** EPITECH PROJECT, 2019
** stumper
** File description:
** free tab
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        free(tab[i++]);
    free(tab);
}
