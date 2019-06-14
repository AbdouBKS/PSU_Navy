/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** my_sleep
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_sleep(unsigned long int n)
{
    unsigned long int i = 0;
    unsigned long int max = n * 100000;

    while (i != max) {
        ++i;
    }
}