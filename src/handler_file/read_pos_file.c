/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** check_file
*/

#include "my.h"

char *read_pos_file(char *filepath)
{
    int fd = 0;
    int buffer_size = 31;
    char *final_str = NULL;
    int lenght = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1 ||
        (final_str = malloc(sizeof(char) * (buffer_size + 1))) == NULL)
        return (NULL);
    if ((lenght = read(fd, final_str,  buffer_size + 1)) == -1)
        return (NULL);
    final_str[lenght] = '\0';
    close(fd);
    return (final_str);
}
