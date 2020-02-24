/*
** EPITECH PROJECT, 2020
** send_coordinates.c
** File description:
** Converts the coordinates to binary and sends them to the enemy.
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy.h"

void send_coordinates(char *input, int second_pid)
{
    char binary[7] = {0};

    convert_to_binary(input, binary);
    for (int i = 0; i < 7; i++)
        send_bit(binary[i], second_pid);
}

char *set_to_format(char *str)
{
    char *new_format = malloc(sizeof(char) * 4);

    new_format[3] = '\0';
    for (int i = 0; i < 3; i++)
        new_format[i] = '0';
    for (int i = 2; i >= 0 && str[2 - i]; i--)
        new_format[i] = str[2 - i];
    free(str);
    return new_format;
}

void convert_to_binary(char *input, char binary[])
{
    char letter_dec[2] = {0};
    char number_dec[2] = {0};
    char *letter_bin = NULL;
    char *number_bin = NULL;

    letter_bin = deci_to_base(input[0] - 'A', "01");
    number_bin = deci_to_base(input[1] - '1', "01");
    letter_bin = set_to_format(letter_bin);
    number_bin = set_to_format(number_bin);
    for (int i = 0; i < 3; i++)
        binary[i] = letter_bin[i];
    for (int i = 0; i < 3; i++)
        binary[i + 3] = number_bin[i];
    binary[6] = 0;
}

void send_bit(char bit, int second_pid)
{
    usleep(100);
    if (bit == '0') {
        kill(second_pid, SIGUSR1);
        printf("%c", bit);
        while(second_pid != *detect_signal1())
            pause();
    } else {
        kill(second_pid, SIGUSR2);
        printf("%c", bit);
        while(second_pid != *detect_signal2())
            pause();
    }
    printf("\n");
}
