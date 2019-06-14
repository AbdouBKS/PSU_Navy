/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** signals
*/

#include "my.h"

navy_t navy;

int send_signal(void)
{
    int i = 0;
    int j = 0;

    while (i != NAVY.command_x) {
        kill(NAVY.pid_enemy, 10);
        usleep(5000);
        ++i;
    }
    kill(NAVY.pid_enemy, 12);
    usleep(5000);
    while (j != NAVY.command_y) {
        kill(NAVY.pid_enemy, 10);
        usleep(5000);
        ++j;
    }
    kill(NAVY.pid_enemy, 12);
    usleep(5000);
    return (0);
}

void game_sig_one(int res_signal)
{
    if (res_signal == 10) {
        NAVY.touch = 2;
        ++NAVY.en_boat;
    }else if (res_signal == 12)
        NAVY.touch = 1;
    usleep(25000);
}

void game_sig_two(int res_signal)
{
    static int got_12 = 0;

    if (res_signal == 10) {
        if (got_12 == 0)
            ++NAVY.command_x;
        else if (got_12 == 1)
            ++NAVY.command_y;
    } else if (res_signal == 12) {
        ++got_12;
        if (got_12 == 2) {
            got_12 = 0;
        }
    }
    usleep(25000);
}

int get_game_signal_usr1(void)
{
    struct sigaction prepa_signal;

    prepa_signal.sa_handler = &game_sig_one;
    prepa_signal.sa_flags = SA_NODEFER;
    sigemptyset(&prepa_signal.sa_mask);
    sigaction(SIGUSR2, &prepa_signal, 0);
    sigaction(SIGUSR1, &prepa_signal, 0);
    pause();
    return (0);
}

int get_game_signal_usr2(void)
{
    struct sigaction prepa_signal;

    prepa_signal.sa_handler = &game_sig_two;
    prepa_signal.sa_flags = SA_NODEFER;
    sigemptyset(&prepa_signal.sa_mask);
    sigaction(SIGUSR2, &prepa_signal, 0);
    sigaction(SIGUSR1, &prepa_signal, 0);
    pause();
    return (0);
}