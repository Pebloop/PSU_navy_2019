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

int player_one(void)
{
    struct sigaction usr1;
    int second_pid = 0;

    usr1.sa_sigaction = &receive_usr1;
    fae_put("waiting for enemy connection...\n");
    sigaction(SIGUSR1, &usr1, NULL);
    while(!second_pid) {
        second_pid = *detect_signal1();
    }
    *detect_signal1() = 0;
    kill(second_pid, SIGUSR1);
    while(second_pid != *detect_signal1()) {
        fae_put("%d : %d\n", second_pid, *detect_signal1());
    }
    fae_put("\nenemy connected\n");
    return second_pid;
}
