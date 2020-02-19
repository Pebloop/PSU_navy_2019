/*
** EPITECH PROJECT, 2019
** navy
** File description:
** include navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <signal.h>

// display_usage.c
void display_usage(void);

// error_detection.c
int detect_errors(int argc, char **argv);
int is_incorrect_pid(char *arg);
int errors_in_file(char *filepath);

// display_usage.c
int *detect_signal1(void);
int *detect_signal2(void);
void receive_usr1(int sig, siginfo_t *siginfo, void *context);
void receive_usr2(int sig, siginfo_t *siginfo, void *context);

//player_one.c
int player_one(void);

//player_two.c
int player_two(int first_pid);

//navy.c
int navy(void);

//display_grid.c
void display_grid(cell_t **grid);

//display_board
display_board(cell_t **player, cell_t **ennemy);

#endif /*NAVY_H*/
