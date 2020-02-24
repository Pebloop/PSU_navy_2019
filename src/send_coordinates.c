/*
** EPITECH PROJECT, 2020
** send_coordinates.c
** File description:
** Converts the coordinates to binary and sends them to the enemy.
*/

#include <stddef.h>
#include <unistd.h>
#include "navy.h"

void send_coordinates(char *input, int second_pid)
{
    char binary[7] = {0};

    convert_to_binary(input, binary);
    for (int i = 0; i < 7; i++)
        send_bit(binary[i], second_pid);
}

void convert_to_binary(char *input, char binary[])
{
    char letter_dec[2] = {0};
    char number_dec[2] = {0};
    char *letter_bin = NULL;
    char *number_bin = NULL;

    letter_dec[1] = input[0] - 65;
    letter_bin = deci_to_base(2, letter_dec);
    number_dec[1] = input[1] - 49;
    number_bin = deci_to_base(2, number_dec);
    for (int i = 0; i < 3; i++)
        binary[i] = letter_bin[i];
    for (int i = 0; i < 3; i++)
        binary[i + 3] = number_bin[i];
    binary[6] = 0;
}

void send_bit(char bit, int second_pid)
{
    usleep(100);
    if (bit == 0) {
        kill(second_pid, SIGUSR1);
        while(second_pid != *detect_signal1())
            pause();
    } else {
        kill(second_pid, SIGUSR2);
        while(second_pid != *detect_signal2())
            pause();
    }
}