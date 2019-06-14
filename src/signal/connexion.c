/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** connexion
*/

#include "my.h"

navy_t navy;

int connexion_player_one(void)
{
    pid_t pid = getpid();

    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n");
    get_signal_usr2();
    return (0);
}

int connexion_player_two(char *p1_pid)
{
    pid_t pid = getpid();

    NAVY.pid_enemy = my_getnbr(p1_pid);
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    kill(NAVY.pid_enemy, 12);
    usleep(5000);
    check_connection();
    return (0);
}
