/*
** EPITECH PROJECT, 2020
** math_tools.c
** File description:
** Math functions
*/

#include "navy.h"

int my_abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

int my_min(int nb1, int nb2)
{
    if (nb1 < nb2)
        return (nb1);
    return (nb2);
}