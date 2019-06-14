/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** signals_boat
*/

#include "my.h"

navy_t navy;

void game_sig_boat(int res_signal)
{
    res_signal = res_signal;
    my_putstr("I won\n");
    NAVY.end = 1;
    usleep(5000);
}

int get_signals_boat(void)
{
    struct sigaction prepa_signal;

    prepa_signal.sa_handler = &game_sig_boat;
    prepa_signal.sa_flags = SA_NODEFER;
    sigemptyset(&prepa_signal.sa_mask);
    sigaction(SIGUSR2, &prepa_signal, 0);
    sigaction(SIGUSR1, &prepa_signal, 0);
    pause();
    return (0);
}