/*
** EPITECH PROJECT, 2019
** lib
** File description:
** is it alpha
*/

int isit_alpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}
