/*
** EPITECH PROJECT, 2019
** navy
** File description:
** handle input
*/

#include "my.h"

navy_t navy;

void send_error(void)
{
    NAVY.command_x = 'I' - 'A';
    NAVY.command_y = '9' - '0';
    send_signal();
}

int input_error(char *input)
{
    if (input[0] == '\n'
    || (input[2] != '\0' && input[2] != '\n')
    || (input[0] < 'A' || input[0] > 'H')
    || (input[1] < '1' || input[1] > '8'))
        return (1);
    else
        return (0);
}

char *take_input(void)
{
    char *input = NULL;
    size_t size = 0;

    my_putstr("attack: ");
    if (getline(&input, &size, stdin) == -1) {
        free(input);
        send_error();
        return (NULL);
    }
    while (input_error(input) == 1) {
        write(1, "wrong position\nattack: ", 24);
        if (getline(&input, &size, stdin) == -1) {
            free(input);
            send_error();
            return (NULL);
        }
    }
    return (input);
}

