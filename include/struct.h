/*
** EPITECH PROJECT, 2019
** navy
** File description:
** struct of pos
*/

#include "my.h"

#ifndef STRUCT_H
#define STRUCT_H

typedef struct navy_l
{
    int pid_enemy;
    int command_y;
    int command_x;
    int touch;
    int end;
    int pl_boat;
    int en_boat;
} navy_t;
#endif

#ifndef NAVY
    #define NAVY navy
#endif
