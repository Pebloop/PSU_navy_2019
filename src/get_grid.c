/*
** EPITECH PROJECT, 2020
** ger_grid.c
** File description:
** Initializes the grid from the file given as argument
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "navy.h"
#include "fae.h"
#include "get_next_line.h"

int get_grid(cell_t (*grid)[8][8], char *filepath)
{
    int file_descr = 0;
    char *line = NULL;

    file_descr = open(filepath, O_RDONLY);
    if (file_descr == -1)
        return (84);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            (*grid)[i][j] = N_A;
    }
    for (int i = 0; i < 4; i++) {
        if (add_boat_to_grid(grid, file_descr) == 84)
            return (84);
    }
    close(file_descr);
    return (0);
}

int add_boat_to_grid(cell_t (*grid)[8][8], int file_descr)
{
    char *str = NULL;
    int line = -1;
    int col = -1;

    str = get_next_line(file_descr);
    if (str == NULL)
        return (84);
    if (str[2] == str[5]) {
        if (add_boat_to_col(str[2] - 65, str[0] - 48, grid, str) == 84)
            return (84);
    } else {
        if (add_boat_to_line(str[3] - 48 - 1, str[0] - 48, grid, str) == 84)
            return (84);
    }
    free(str);
    return (0);
}

int add_boat_to_col(int col, int length, cell_t (*grid)[8][8], char *str)
{
    int start = 0;

    start = my_min(str[3], str[6]) - 48 - 1;
    for (int i = 0; i < length; i++) {
        if ((*grid)[i + start][col] != N_A)
            return (84);
        (*grid)[i + start][col] = length + 1;
    }
    return (0);
}

int add_boat_to_line(int line, int length, cell_t (*grid)[8][8], char *str)
{
    int start = 0;

    start = my_min(str[2], str[5]) - 65;
    for (int i = 0; i < length; i++) {
        if ((*grid)[line][i + start] != N_A)
            return (84);
        (*grid)[line][i + start] = length + 1;
    }
    return (0);
}
