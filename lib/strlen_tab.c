/*
** EPITECH PROJECT, 2019
** lib
** File description:
** strlentab
*/

#include "lib.h"

int strlen_tab(char **tab)
{
    int i = 0;
    int len = 0;

    while (tab[i] != NULL)
        len += my_strlen(tab[i++]);
    return (len);
}
