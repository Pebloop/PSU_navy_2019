/*
** EPITECH PROJECT, 2020
** navy
** File description:
** navy
*/

#include "fae.h"
#include "navy.h"

int navy(cell_t (*player)[8], int turn, int second_pid)
{
    cell_t ennemy[8][8] = {N_A};
    int winner = 0;

    while (!winner) {
        display_board(player, ennemy);
        if (turn) {
            you_play(ennemy, second_pid);
            winner = detect_victory(ennemy);
        } else {
            they_play(player, second_pid);
            winner = detect_victory(player);
            winner != 0 ? winner + 1 : winner;
        }
        turn = !turn;
    }
    display_board(player, ennemy);
    display_winner(winner);
    return winner - 1;
}

int detect_victory(cell_t (*player)[8])
{
    int hits = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            hits += (player[i][j] == HIT);
    }
    if (hits < 14)
        return (0);
    return (1);
}

void display_winner(int status)
{
    if (status == 1)
        fae_putstr("I won\n");
    if (status == 2)
        fae_putstr("Enemy won\n");
}