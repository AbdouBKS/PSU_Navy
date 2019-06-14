/*
** EPITECH PROJECT, 2019
** base_repo
** File description:
** my_getnbr
*/

int multiplacte_it(char *str, int i, int nb)
{
    if (str[i +1] != '\0')
        nb = nb * 10;
    return (nb);
}

int my_getnbr(char *str)
{
    int i = 0;
    int nb_minus = 0;
    int dest = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            dest = dest + str[i] - '0';
        else if (str[i] == '-')
            nb_minus++;
        dest = multiplacte_it(str, i, dest);
        i++;
    }
    if (nb_minus % 2 != 0 && nb_minus > 0)
        dest = dest * -1;
    return (dest);
}
