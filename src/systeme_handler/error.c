/*
** EPITECH PROJECT, 2019
** navy
** File description:
** error handling
*/

#include "my.h"

int argc_error(int ac)
{
    if (ac != 3 && ac != 2)
        return (1);
    return (0);
}

int argv_error(int ac, char **av)
{
    if (ac == 3) {
        if (isit_number(av[1]) == 1 || kill(my_getnbr(av[1]), 0) == -1)
            return (1);
    }
    return (0);
}

int all_error(int ac, char **av)
{
    if (argc_error(ac) || argv_error(ac, av))
        return (1);
    return (0);
}
