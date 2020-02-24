/*
** EPITECH PROJECT, 2019
** navy
** File description:
** you_play
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "fae.h"
#include "navy.h"
#include "get_next_line.h"

int you_play(void)
{
    char *input = NULL;

    if (get_input(&input) == 84)
        return (84);
    send_coordinates(input, *ennemy_pid());
    free(input);
    return (0);
}

int get_input(char **str)
{
    int correct_input = 0;

    while (!correct_input) {
        fae_put("\nattack: ");
        *str = get_next_line(0);
        if (*str == NULL)
            return (84);
        if (!is_incorrect_coords(*str) && ((*str)[2] == ' ' || (*str)[2] == 0))
            correct_input = 1;
        else {
            fae_put("wrong position\n");
            free(*str);
        }
    }
    return (0);
}
