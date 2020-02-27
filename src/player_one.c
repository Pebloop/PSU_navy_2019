/*
** EPITECH PROJECT, 2020
** navy
** File description:
** launch player one
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "fae.h"
#include "navy.h"
#include <time.h>

int player_one(void)
{
    int second_pid = 0;
    int *signal1 = detect_signal1();

    fae_put("waiting for enemy connection...\n");
    while (!second_pid) {
        pause();
        second_pid = *signal1;
    }
    *signal1 = 0;
    usleep(100);
    kill(second_pid, SIGUSR1);
    while (second_pid != *detect_signal1())
        pause();
    *signal1 = 0;
    fae_put("\nenemy connected\n\n");
    return second_pid;
}
