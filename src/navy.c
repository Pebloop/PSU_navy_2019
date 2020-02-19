/*
** EPITECH PROJECT, 2020
** navy
** File description:
** navy
*/

int navy(int ennemy_pid, cell_t **player, int turn)
{
    cell_t ennemy[8][8] = {N_A};
    int status = 0;

    while (!status) {
        display_board(player, ennemy);
        if (turn)
            you_play();
        else
            they_play();
    }
    display_board(player, ennemy);
    if (status == 1)
        fae_putstr("I won\n");
    if (status == 2)
        fae_putstr("Enemy won\n");
    return status - 1;
}
