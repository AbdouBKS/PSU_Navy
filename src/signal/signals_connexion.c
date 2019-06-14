/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** signals_connexion
*/

#include "my.h"

navy_t navy;

void sig_handler(int res_signal, siginfo_t *info)
{
    res_signal = res_signal;
    my_putstr("\nenemy connected\n\n");
    NAVY.pid_enemy = info->si_pid;
    usleep(5000);
    kill(NAVY.pid_enemy, 12);
    usleep(5000);
}

void sig_connection(int res_signal)
{
    res_signal = res_signal;
    my_putstr("successfully connected\n\n");
    usleep(5000);
}


int get_signal_usr2(void)
{
    struct sigaction prepa_signal;

    prepa_signal.sa_handler = (void*)sig_handler;
    prepa_signal.sa_flags = SA_SIGINFO;
    sigemptyset(&prepa_signal.sa_mask);
    sigaction(SIGUSR2, &prepa_signal, 0);
    pause();
    return (0);
}

int check_connection(void)
{
    struct sigaction prepa_signal;

    prepa_signal.sa_handler = &sig_connection;
    prepa_signal.sa_flags = SA_NODEFER;
    sigemptyset(&prepa_signal.sa_mask);
    sigaction(SIGUSR2, &prepa_signal, 0);
    pause();
    return (0);
}