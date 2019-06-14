/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** helper
*/

#include "my.h"

int helper(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid :  only for the 2nd player.  ");
    my_putstr("pid of the first player\n");
    my_putstr("\tnavy_positions: file representing the positions");
    my_putstr("of the ships.\n");
    return (1);
}
