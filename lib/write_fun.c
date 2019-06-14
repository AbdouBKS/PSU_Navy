/*
** EPITECH PROJECT, 2019
** project
** File description:
** write_fun
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        ++i;
    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    nb = nb % 10;
    my_putchar(nb + '0');
}

