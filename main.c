/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main
*/

#include "fae.h"
#include "navy.h"

int main(int argc, char **argv)
{
    if (argc > 1 && !fae_strcmp(argv[1], "-h")) {
        display_usage();
    }
}
