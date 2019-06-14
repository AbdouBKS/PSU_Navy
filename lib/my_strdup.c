/*
** EPITECH PROJECT, 2018
** MY_STRDUP
** File description:
** My_strdup
*/

#include "lib.h"

char *my_strdup(char const *src)
{
    char *str = NULL;
    int count = 0;
    int index = 0;

    if (src == NULL)
        return (str);
    count = my_strlen(src);
    if ((str = malloc(sizeof(char) * (count + 1))) == NULL)
        return (NULL);
    while (index < count) {
        str[index] = src[index];
        ++index;
    }
    str[index] = '\0';
    return (str);
}
