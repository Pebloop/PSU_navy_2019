/*
** EPITECH PROJECT, 2019
** navy
** File description:
** display the board game
*/

void display_board(cell_t **player, cell_t **ennemy)
{
    fae_putstr("my positions:\n");
    display_grid(player);
    fae_putstr("\nenemy's positions:\n");
    display_grid(player);
    fae_putchar('\n');
}
