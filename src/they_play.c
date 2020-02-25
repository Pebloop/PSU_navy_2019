/*
** EPITECH PROJECT, 2019
** navy
** File description:
** they_play
*/

#include <stdlib.h>
#include "fae.h"
#include "navy.h"

int they_play(void)
{
    char *coordinate = 0;

    fae_put("waiting for enemy's attack...\n");
    coordinate = get_coordinate();
    free(coordinate);
    return 0;
}
