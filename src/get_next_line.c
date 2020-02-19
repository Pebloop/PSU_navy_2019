/*
** EPITECH PROJECT, 2019
** get nextline
** File description:
** get next line
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int len_buffer(buffer_t buff, int i)
{
    if (buff.buffer[i] == '\0' || buff.buffer[i] == '\n' || i >= buff.size)
        return 1;
    return 0;
}

int update_buffer(buffer_t *buffer, int len)
{
    int new_len = buffer->size - len + 1;

    if (len == buffer->size) {
        buffer->size = 0;
        return 0;
    }
    if (len == buffer->size - 1)
        if (buffer->buffer[len] == '\0' || buffer->buffer[len] == '\n') {
        buffer->size = 0;
        return 1;
    }
    for (int i = len + 1; i < buffer->size; i++)
        buffer->buffer[i - len - 1] = buffer->buffer[i];
    buffer->size = buffer->size - len - 1;
    return 1;
}

int update_line(buffer_t *buffer, char **line)
{
    char *new_line = 0;
    int len[2] = {0, 0};

    if (buffer->size == 0)
        return 0;
    for (len[0] = 0; (*line)[len[0]] != '\0'; len[0]++) {}
    for (len[1] = 0; !len_buffer(*buffer, len[1]); len[1]++) {}
    new_line = malloc(sizeof(char) * (len[0] + len[1] + 1));
    for (int i = 0; i < len[0]; i++)
        new_line[i] = (*line)[i];
    for (int i = 0; i < len[1]; i++)
        new_line[len[0] + i] = buffer->buffer[i];
    new_line[len[0] + len[1]] = '\0';
    free(*line);
    *line = new_line;
    return update_buffer(buffer, len[1]);
}

char *get_next_line(int fd)
{
    static buffer_t buffer = {{0}, 0};
    char *line = malloc(sizeof(char));
    int test = 0;
    int end_of_file = 0;

    if (!line || fd == -1)
        return 0;
    line[0] = '\0';
    while (!test) {
        test = update_line(&buffer, &line);
        if (!test)
            buffer.size = read(fd, buffer.buffer, READ_SIZE);
        if (!test && buffer.size == 0) {
            free(line);
            return 0;
        }
    }
    return line;
}
