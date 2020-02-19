/*
** EPITECH PROJECT, 2020
** error_detection.c
** File description:
** Detects errors in the arguments passed to the program
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "navy.h"
#include "fae.h"
#include "get_next_line.h"

int detect_errors(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return (1);
    if (argc == 3 && is_incorrect_pid(argv[1]))
        return (1);
    if (is_incorrect_file(argv[argc - 1]))
        return (1);
    return (0);
}

int is_incorrect_pid(char *arg)
{
    char *end = 0;
    int pid = 0;

    pid = fae_stoi(arg, &end);
    if (*end != 0 || pid <= 0)
        return (1);
    return (0);
}

int is_incorrect_file(char *filepath)
{
    int file_descr = 0;
    char *line = NULL;

    file_descr = open(filepath, O_RDONLY);
    if (file_descr == -1)
        return (1);
    for (int i = 0; i < 4; i++) {
        if (is_incorrect_line(file_descr, i))
            return (1);
    }
    line = get_next_line(file_descr);
    if (line != NULL) {
        free(line);
        return (1);
    }
    close(file_descr);
    return (0);
}

int is_incorrect_line(int file_descr, int line_nb)
{
    char *line = NULL;

    line = get_next_line(file_descr);
    if (line == NULL || fae_strlen(line) != 7)
        return (1);
    if (line[0] - 48 != line_nb + 2 || line[1] != ':' || line[4] != ':')
        return (1);
    if (is_incorrect_coords(&(line[2])) || is_incorrect_coords(&(line[5])))
        return (1);
    if (line[2] != line[5] && line[3] != line[6])
        return (1);
    if (line[0] - 48 != my_abs(line[2] - line[5]) + 1 &&
        line[0] - 48 != my_abs(line[3] - line[6]) + 1)
        return (84);
    free(line);
    return (0);
}

int is_incorrect_coords(char *str)
{
    if (!('A' <= str[0] && str[0] <= 'H'))
        return (1);
    if (!('1' <= str[1] && str[1] <= '8'))
        return (1);
    return (0);
}