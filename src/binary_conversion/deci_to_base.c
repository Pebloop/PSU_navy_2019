/*
** EPITECH PROJECT, 2019
** deci_to_base.c
** File description:
** return a int from a base.
*/

#include <stdlib.h>
#include "fae.h"

char *deci_to_base_zero(char const *base)
{
    char *result;

    result = malloc(sizeof(char) * 2);
    result[0] = base[0];
    result[1] = '\0';
    return result;
}

char *dtb_conversion(int nbr, char const *base, char *nb, int nbr_base)
{
    int index = 0;

    while (nbr != 0) {
        if (nbr < 0)
            nb[index] = base[- (nbr % nbr_base)];
        else
            nb[index] = base[(nbr % nbr_base)];
        nbr /= nbr_base;
        index++;
    }
    nb[index] = '\0';
    fae_revstr(nb);
    return nb;
}

char *dtb_tr(char const *base, int nbr, int nbr_base, int size)
{
    int sign = 1;
    char *result;
    char *nb;
    int index = 0;

    result = malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 0 : 1)));
    nb = malloc(sizeof(char) * (size + 1));
    if (nbr < 0) {
        result[0] = '-';
        sign = -1;
    }
    nb = dtb_conversion(nbr, base, nb, nbr_base);
    if (sign < 0)
        for (int i = 1; i <= size; i++)
            result[i] = nb[i - 1];
    else
        for (int i = 0; i <= size; i++)
            result[i] = nb[i];
    free(nb);
    return result;
}

char *deci_to_base(int nbr, char const *base)
{
    int nbr_base = 0;
    int size = 0;
    int sign = 1;

    if (nbr == 0)
        return deci_to_base_zero(base);
    for (nbr_base = 0; base[nbr_base] != '\0'; nbr_base++) {}
    if (nbr_base < 2)
        return 0;
    for (int i = nbr; i != 0; i /= nbr_base)
        size++;
    return dtb_tr(base, nbr, nbr_base, size);
}
