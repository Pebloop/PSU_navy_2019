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

int you_play(cell_t (*their_board)[8], int second_pid)
{
    char *input = NULL;
    int hit = 0;

    if (get_input(&input) == 84)
        return (84);
    send_coordinates(input, *ennemy_pid());
    hit = receive_result_of_strike(second_pid);
    update_board(their_board, input, hit);
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

int receive_result_of_strike(int second_pid)
{
    int *signal0 = NULL;
    int *signal1 = NULL;
    int hit = 0;

    signal0 = detect_signal1();
    signal1 = detect_signal2();
    *signal0 = 0;
    *signal1 = 0;
    while(!(*signal0) && !(*signal1))
        pause();
    usleep(100);
    if (*signal0) {
        hit = 0;
        kill(second_pid, SIGUSR1);
    } else {
        hit = 1;
        kill(second_pid, SIGUSR2);
    }
    return (hit);
}

void update_board(cell_t (*board)[8], char *input, int hit)
{
    if (hit)
        board[input[0] - 'A'][input[1] - '1'] = HIT;
    else
        board[input[0] - 'A'][input[1] - '1'] = MISS;
}