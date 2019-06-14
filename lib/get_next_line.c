/*
** EPITECH PROJECT, 2018
** emacs
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib.h"
#include <stdio.h>
#include <string.h>

void my_memset(char *dest, int x, int y)
{
    char *str = NULL;
    int i = 0;

    if (dest != NULL) {
        str = dest;
        while (y != 0) {
            str[i] = x;
            y = y - 1;
            i = i + 1;
        }
    }
}

char *my_stcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_read_of_size(int fd, char *buf)
{
    int i = 0;
    int y = READ_SIZE;

    my_memset(buf, 0, y);
    i = read((fd), buf, READ_SIZE);
    return (i);
}

char *re_alloc(char *str, int y)
{
    char *buf = NULL;

    buf = malloc(y);
    my_memset(buf, 0, y);
    if (str) {
        my_stcpy(buf, str);
    }
    return (buf);
}

char *get_next_line(int fd)
{
    static char buf[READ_SIZE + 1];
    int i = 0;
    char *str = NULL;
    static int y;

    if (fd < 0)
        return (NULL);
    while (1) {
        if (buf[y] == '\0')
            y = 0;
        if (y == 0 && my_read_of_size(fd, buf) < 1)
            return (str);
        if ((buf[y] == '\n') && y++)
            return (str);
        if ((!(str = re_alloc(str, READ_SIZE + i + 1))))
            return (NULL);
        str[i] = buf[y];
        i++;
        y++;
    }
}
