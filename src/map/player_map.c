/*
** EPITECH PROJECT, 2019
** navy
** File description:
** print map for player
*/

#include "my.h"

void print_map(char **map)
{
    int i = 0;

    while (i < 10) {
        my_putstr(map[i++]);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

char **initiate_player_map(void)
{
    char **player_map = malloc(sizeof(char *) * 11);

    if (player_map == NULL)
        return (NULL);
    if ((player_map[0] = my_strdup(" |A B C D E F G H")) == NULL ||
        (player_map[1] = my_strdup("-+---------------")) == NULL ||
        (player_map[2] = my_strdup("1|. . . . . . . .")) == NULL ||
        (player_map[3] = my_strdup("2|. . . . . . . .")) == NULL ||
        (player_map[4] = my_strdup("3|. . . . . . . .")) == NULL ||
        (player_map[5] = my_strdup("4|. . . . . . . .")) == NULL ||
        (player_map[6] = my_strdup("5|. . . . . . . .")) == NULL ||
        (player_map[7] = my_strdup("6|. . . . . . . .")) == NULL ||
        (player_map[8] = my_strdup("7|. . . . . . . .")) == NULL ||
        (player_map[9] = my_strdup("8|. . . . . . . .")) == NULL)
        return (NULL);
    player_map[10] = NULL;
    return (player_map);
}

int isit_horizontal(char *pos_boat)
{
    if (pos_boat[3] == pos_boat[6])
        return (1);
    return (0);
}

char **create_boat(char *pos_boat, char **player_map)
{
    int len = pos_boat[0] - '0';
    int pos_x = ((pos_boat[2] - 'A') + 1) * 2;
    int pos_y = (pos_boat[3] - '0') + 1;
    int i = 0;

    while (i < len) {
        if (isit_horizontal(pos_boat)) {
            if (player_map[pos_y][pos_x] != '.')
                return (NULL);
            player_map[pos_y][pos_x] = pos_boat[0];
            pos_x += 2;
        } else {
            if (player_map[pos_y][pos_x] != '.')
                return (NULL);
            player_map[pos_y++][pos_x] = pos_boat[0];
        }
        i++;
    }
    return (player_map);
}

char **create_player_map(char **pos_file)
{
    char **player_map = initiate_player_map();
    int i = 0;

    if (player_map == NULL)
        return (NULL);
    while (i < 4) {
        player_map = create_boat(pos_file[i++], player_map);
        if (player_map == NULL)
            return (NULL);
    }
    return (player_map);
}
