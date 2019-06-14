/*
** EPITECH PROJECT, 2018
** navy
** File description:
** main file
*/

#include "my.h"

navy_t navy;

void initiate_navy(void)
{
    NAVY.pid_enemy = 0;
    NAVY.command_x = 0;
    NAVY.command_y = 0;
    NAVY.touch = 0;
    NAVY.end = 0;
    NAVY.pl_boat = 0;
    NAVY.en_boat = 0;
}

int player_one(char **av)
{
    char *final_str = NULL;
    char **pos_file = NULL;
    char **player_map = NULL;
    char **enemy_map = NULL;
    int check = 0;

    if ((final_str = read_pos_file(av[1])) == NULL ||
        (check_pos_file(final_str) == -1) ||
        (pos_file = strtoword_array(final_str, '\n')) == NULL ||
        (player_map = create_player_map(pos_file)) == NULL ||
        (enemy_map = create_enemy_map()) == NULL)
        return (84);
    free(final_str);
    connexion_player_one();
    if ((check = set_loop_one(player_map, enemy_map)) == 84) {
        free_all(pos_file, player_map, enemy_map);
        return (84);
    } else {
        free_all(pos_file, player_map, enemy_map);
        return (check);
    }
    free_all(pos_file, player_map, enemy_map);
    return (0);
}

int player_two(char **av)
{
    char *final_str = NULL;
    char **pos_file = NULL;
    char **player_map = NULL;
    char **enemy_map = NULL;
    int check = 0;

    if ((final_str = read_pos_file(av[2])) == NULL ||
        (check_pos_file(final_str) == -1) ||
        (pos_file = strtoword_array(final_str, '\n')) == NULL ||
        (player_map = create_player_map(pos_file)) == NULL ||
        (enemy_map = create_enemy_map()) == NULL) {
        if (final_str != NULL)
            free(final_str);
        free_all(pos_file, player_map, enemy_map);
        return (84);
    }
    connexion_player_two(av[1]);
    if ((check = set_loop_two(player_map, enemy_map)) == 84) {
        free_all(pos_file, player_map, enemy_map);
        return (84);
    } else {
        free_all(pos_file, player_map, enemy_map);
        return (check);
    }
    free_all(pos_file, player_map, enemy_map);
    return (0);
}

int main(int ac, char **av)
{
    int check = 0;

    if (all_error(ac, av) == 1)
        return (84);
    if (my_strcomp(av[1], "-h") && helper())
        return (0);
    initiate_navy();
    if (ac == 2) {
        if ((check = player_one(av)) == 84)
            return (84);
        else
            return (check);
    }
    if (ac == 3) {
        if ((check = player_two(av)) == 84)
            return (84);
        else
            return (check);
    }
    return (0);
}
