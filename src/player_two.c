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
    struct sigaction usr1;

    usr1.sa_sigaction = &receive_usr1;
    kill(first_pid, SIGUSR1);
    sigaction(SIGUSR1, &usr1, NULL);
    while(*detect_signal1() == 0) {
    }
    usleep(100);
    kill(first_pid, SIGUSR1);
    fae_put("\nsuccessfully connected\n");
    return first_pid;
}
