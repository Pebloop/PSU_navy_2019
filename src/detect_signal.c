/*
** EPITECH PROJECT, 2019
** navy
** File description:
** detect a signal
*/

#include <signal.h>

int *detect_signal1(void)
{
    static int usr1 = 0;

    return &usr1;
}

int *detect_signal2(void)
{
    static int usr2 = 0;

    return &usr2;
}

void receive_usr1(int sig, siginfo_t *siginfo, void *context)
{
    int *usr1 = detect_signal1();

    *usr1 = siginfo->si_pid;
}

void receive_usr2(int sig, siginfo_t *siginfo, void *context)
{
    int *usr2 = detect_signal2();

    *usr2 = siginfo->si_pid;
}
