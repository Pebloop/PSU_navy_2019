/*
** EPITECH PROJECT, 2020
** send_coordinates.c
** File description:
** Converts the coordinates to binary and sends them to the enemy.
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "navy.h"
#include "fae.h"

void send_coordinates(char *input, int second_pid)
{
    char binary[7] = {0};

    convert_to_binary(input, binary);
    for (int i = 0; i < 6; i++)
        send_bit(binary[i], second_pid);
    usleep(100);
}

char *set_to_format(char *str)
{
    char *new_format = malloc(sizeof(char) * 4);
    int len = fae_strlen(str);
    int str_i = len - 1;

    for (int i = 0; i < 2; i++)
        new_format[i] = '0';
    for (int i = 2; i >= 0 && str_i >= 0; i--) {
        new_format[i] = str[str_i];
        str_i--;
    }
    new_format[3] = '\0';
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
    int *signal0 = detect_signal1();
    int *signal1 = detect_signal2();

    usleep(50);
    if (bit == '0') {
        kill(second_pid, SIGUSR1);
        while(second_pid != *signal0)
            pause();
        *signal0 = 0;
    } else {
        kill(second_pid, SIGUSR2);
        while(second_pid != *signal1)
            pause();
        *signal1 = 0;
    }
}
