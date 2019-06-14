/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** put_tab
*/

#include <unistd.h>
#include "lib.h"

void put_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i++]);
        write(1, "\n", 1);
    }
}
