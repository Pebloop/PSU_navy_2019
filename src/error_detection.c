/*
** EPITECH PROJECT, 2020
** error_detection.c
** File description:
** Detects errors in the arguments passed to the program
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "navy.h"
#include "fae.h"

int detect_errors(int argc, char **argv)
{
    if (argc != 3)
        return (1);
    if (is_incorrect_pid(argv[1]))
        return (1);
    if (errors_in_file(argv[2]))
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

int errors_in_file(char *filepath)
{
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (1);
    // check every line
    return (0);
}
