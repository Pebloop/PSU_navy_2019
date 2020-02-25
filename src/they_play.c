/*
** EPITECH PROJECT, 2019
** navy
** File description:
** they_play
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "fae.h"
#include "navy.h"

int they_play(cell_t (*your_board)[8], int second_pid)
{
    char *coordinates = 0;
    int hit = 0;

    fae_put("waiting for enemy's attack...\n");
    coordinates = get_coordinate();
    hit = detect_hit(your_board, coordinates);
    update_board(your_board, coordinates, hit);
    send_result_of_strike(hit, second_pid);
    free(coordinates);
    return 0;
}

int detect_hit(cell_t (*board)[8], char *coordinates)
{
    cell_t cell = N_A;

    cell = board[coordinates[1] - '1'][coordinates[0] - 'A'];
    if (cell == N_A || cell == MISS)
        return (0);
    return (1);
}

void send_result_of_strike(int hit, int second_pid)
{
    usleep(100);
    if (hit) {
        kill(second_pid, SIGUSR2);
        while(second_pid != *detect_signal2())
            pause();
    } else {
        kill(second_pid, SIGUSR1);
        while(second_pid != *detect_signal1())
            pause();
    }
}
