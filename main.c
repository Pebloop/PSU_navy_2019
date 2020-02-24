/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main
*/

#include "fae.h"
#include "navy.h"
#include <sys/types.h>
#include <unistd.h>

void set_receiver(void)
{
    struct sigaction usr1;
    struct sigaction usr2;

    usr1.sa_sigaction = &receive_usr1;
    usr2.sa_sigaction = &receive_usr2;
    usr1.sa_flags = SA_SIGINFO;
    usr2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &usr1, NULL);
    sigaction(SIGUSR2, &usr2, NULL);
}

int main(int argc, char **argv)
{
    cell_t grid[8][8];
    int *pid = ennemy_pid();

    set_receiver();
    if (argc > 1 && !fae_strcmp(argv[1], "-h")) {
        display_usage();
        return 0;
    }
    if (detect_errors(argc, argv))
        return 84;
    if (get_grid(&grid, argv[argc - 1]) == 84)
        return 84;
    fae_put("my_pid: %d\n", getpid());
    *pid = (argc == 2) ? player_one() : *pid ;
    *pid  = (argc == 3) ? player_two(fae_stoi(argv[1], 0)) : *pid;
    if (!(*pid))
        return 84;
    return navy(grid, (argc == 2) ? 1 : 0);
}
