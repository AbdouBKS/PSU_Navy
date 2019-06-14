/*
** EPITECH PROJECT, 2019
** navy
** File description:
** strcomp
*/

#include "lib.h"

int my_strcomp(char *src, char *dest)
{
    int len_s = my_strlen(src);
    int len_b = my_strlen(dest);
    int i = 0;

    if (len_s != len_b)
        return (0);
    while (src[i] != '\0' && src[i] != '\n') {
        if (src[i] != dest[i])
            return (0);
        i++;
    }
    return (1);
}
