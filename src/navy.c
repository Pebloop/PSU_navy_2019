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
    int status = 0;

    while (!status) {
        display_board(player, ennemy);
        if (turn) {
            you_play(ennemy, second_pid);
            status = detect_victory(ennemy);
        } else {
            they_play(player, second_pid);
            status = detect_victory(player) + 1;
        }
        turn = !turn;
    }
    display_board(player, ennemy);
    display_winner(status);
    return status - 1;
}

int detect_victory()
{
    // TODO
}

void display_winner(int status)
{
    if (status == 1)
        fae_putstr("I won\n");
    if (status == 2)
        fae_putstr("Enemy won\n");
}