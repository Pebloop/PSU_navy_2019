/*
** EPITECH PROJECT, 2020
** navy
** File description:
** launch player two
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "fae.h"
#include "navy.h"

int player_two(int first_pid)
{
    usleep(100);
    kill(first_pid, SIGUSR1);
    while (*detect_signal1() == 0) {
        pause();
    }
    usleep(100);
    kill(first_pid, SIGUSR1);
    fae_put("successfully connected\n\n");
    return first_pid;
}
