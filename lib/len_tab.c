/*
** EPITECH PROJECT, 2019
** lib
** File description:
** len tab
*/

#include <stdio.h>

int len_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return (i);
}
