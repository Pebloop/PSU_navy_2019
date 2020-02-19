/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** include read size
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

    #ifndef READ_SIZE
    #define READ_SIZE 100
    #endif

typedef struct buffer {
    char buffer[READ_SIZE];
    unsigned int size;
} buffer_t;

char *get_next_line(int);

#endif /*GET_NEXT_LINE_H*/
