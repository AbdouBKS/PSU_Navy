/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** systeme function
*/

#include "lib.h"

int start_str(char *str, char sep_c)
{
    int i = 0;

    while (str[i++] == sep_c);
    i--;
    return (i);
}

int end_str(char *str, char sep_c)
{
    int i = my_strlen(str) - 1;

    while (str[i] == sep_c || str[i] == '\0' ||
        (sep_c != '\n' && str[i] == '\n')) {
            i--;
    }
    return (i);
}

int howmany_array(char *str, char sep_c)
{
    int i = start_str(str, sep_c);
    int nb_array = 1;
    int end = end_str(str, sep_c);

    while (i < end) {
        if (str[i] == sep_c && str[i - 1] != sep_c)
            nb_array++;
        i++;
    }
    return (nb_array);
}

char **malloc_array(char *str, char sep_c)
{
    int nb_array = howmany_array(str, sep_c);
    char **dest = malloc(sizeof(char *) * (nb_array + 1));
    int i = start_str(str, sep_c);
    int array = 0;
    int size = 0;

    if (dest == NULL)
        return (NULL);
    while (array < nb_array) {
        while (str[i] == sep_c)
            i++;
        while (str[i++] != sep_c && str[i] != '\0')
            size++;
        dest[array] = clean_malloc(size + 1);
        if (dest[array++] == NULL)
            return (NULL);
        size = 0;
    }
    dest[array] = NULL;
    return (dest);
}

char **strtoword_array(char *str, char sep_c)
{
    int i = start_str(str, sep_c);
    int i_d = 0;
    int j_d = 0;
    char **dest = NULL;

    if (str[0] == '\n' || (dest = malloc_array(str, sep_c)) == NULL)
        return (NULL);
    while (i < end_str(str, sep_c) + 1 && str[i] != '\0') {
        if (str[i] == sep_c && !(str[i] == sep_c && str[i + 1] == sep_c)) {
            dest[i_d][j_d] = '\0';
            i_d++;
            j_d = 0;
            i++;
        } else if (str[i] != sep_c)
            dest[i_d][j_d++] = str[i++];
        else
            ++i;
    }
    return (dest);
}
