/*
** EPITECH PROJECT, 2020
** navy
** File description:
** get coordinate send by ennemy
*/

#include <unistd.h>
#include <stdlib.h>
#include "navy.h"

static char binary_to_char(char *binary_string, int to_number)
{
    int data = my_getnbr_base(binary_string, "01");

    if (to_number)
        return data + '1';
    return data + 'A';
}

static char *receive_coordinate_in_deci(void)
{
    char *binary_number = malloc(sizeof(char) * 4);
    int *signal0 = detect_signal1();
    int *signal1 = detect_signal2();

    binary_number[3] = '\0';
    *signal0 = 0;
    *signal1 = 0;
    for (int i = 0; i < 3; i++) {
        while(!(*signal0) && !(*signal1))
            pause();
        if (*signal0)
            binary_number[i] = '0';
        else
            binary_number[i] = '1';
    }
    return binary_number;
}

char *get_coordinate(void)
{
    char *coordinate = malloc(sizeof(char) * 3);
    char *data = 0;

    coordinate[2] = '\0';
    for (int i = 0; i < 2; i++) {
        data = receive_coordinate_in_deci();
        coordinate[i] = binary_to_char(data, i);
        free(data);
    }
    return coordinate;
}
