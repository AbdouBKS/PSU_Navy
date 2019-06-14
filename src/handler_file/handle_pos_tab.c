/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** handle_pos_tab
*/

#include "my.h"

int get_width(char *final_str)
{
    int width = 0;
    int i = 0;

    while (final_str[i] != '\n') {
        ++width;
        ++i;
    }
    return (width);
}

char **alloc_pos_file(char **pos_file, int size)
{
    int i = 0;
    pos_file = malloc(sizeof(*pos_file) * (size + 1));
    if (pos_file == NULL)
        return (NULL);
    while (i != size) {
        pos_file[i] = malloc(sizeof(pos_file) * size);
        if (pos_file[i] == NULL)
            return (NULL);
        ++i;
    }
    return (pos_file);
}

char **fill_zero(char **pos_file, int size)
{
    int i = 0;
    int j = 0;

    while (i != size) {
        while (j != size) {
            pos_file[i][j] = '\0';
            ++j;
        }
        j = 0;
        ++i;
    }
    return (pos_file);
}

char **handle_pos_file(char **pos_file, int size)
{
    if ((pos_file = alloc_pos_file(pos_file, size)) == NULL)
        return (NULL);
    pos_file = fill_zero(pos_file, size);
    return (pos_file);
}

char **str_to_tab(char *final_str)
{
    char **pos_file = NULL;
    int width = get_width(final_str);
    int i = 0;
    int j = 0;
    int index = 0;

    if ((pos_file = handle_pos_file(pos_file, width)) == NULL)
        return (NULL);
    while (final_str[index] != '\0') {
        if (final_str[index] == '\n') {
            pos_file[i][j] = '\0';
            ++i;
            j = 0;
            ++index;
        }
        pos_file[i][j++] = final_str[index++];
    }
    pos_file[i][width] = '\0';
    pos_file[++i] = NULL;
    return (pos_file);
}
