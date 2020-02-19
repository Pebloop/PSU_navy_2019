
/*
** EPITECH PROJECT, 2019
** navy
** File description:
** display grid
*/

#include "fae.h"
#include "navy.h"

const char cell_to_char[7] = {'.', 'x', 'o', '2', '3', '4', '5'};

static void display_grid_line(int i, cell_t (*grid)[8])
{
    for (int y = 0; y < 8; y++) {
        if (y != 0)
            fae_put(" ");
        fae_putchar(cell_to_char[grid[i][y]]);
    }
    fae_putchar('\n');
}

void display_grid(cell_t (*grid)[8])
{
    fae_put(" |A B C D E F G H\n");
    fae_put("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        fae_put("%d|", i + 1);
        display_grid_line(i, grid);
    }
}
