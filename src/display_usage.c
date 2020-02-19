/*
** EPITECH PROJECT, 2019
** navy
** File description:
** display usage (-h)
*/

#include "fae.h"

void display_usage(void)
{
    fae_put("USAGE\n");
    fae_put("   ./navy [first_player_pid] navy_positions\n");
    fae_put("DESCRIPTION\n");
    fae_put("   first_player_pid: only for the 2nd player. ");
    fae_put("pid of the first player.\n");
    fae_put("   navy_positions: file representing the positions ");
    fae_put("of the ships.\n");
}
