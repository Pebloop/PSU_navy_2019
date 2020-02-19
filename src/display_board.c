/*
** EPITECH PROJECT, 2019
** navy
** File description:
** display the board game
*/

#include "navy.h"
#include "fae.h"

void display_board(cell_t (*player)[8], cell_t (*ennemy)[8])
{
    fae_putstr("my positions:\n");
    display_grid(player);
    fae_putstr("\nenemy's positions:\n");
    display_grid(player);
    fae_putchar('\n');
}
