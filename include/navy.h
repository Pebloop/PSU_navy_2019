/*
** EPITECH PROJECT, 2019
** navy
** File description:
** include navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <signal.h>

typedef enum cell {
    N_A, HIT, MISS, TWO, THREE, FOUR, FIVE
} cell_t;

// maths_tools.c
int my_abs(int nb);
int my_min(int nb1, int nb2);

// display_usage.c
void display_usage(void);

// error_detection.c
int detect_errors(int argc, char **argv);
int is_incorrect_pid(char *arg);
int is_incorrect_file(char *filepath);
int is_incorrect_line(int file_descr, int line_nb);
int is_incorrect_coords(char *str);

// get_grid.c
int get_grid(cell_t (*grid)[8][8], char *filepath);
int add_boat_to_grid(cell_t (*grid)[8][8], int file_descr);
int add_boat_to_line(int line, int length, cell_t (*grid)[8][8], char *str);
int add_boat_to_col(int col, int length, cell_t (*grid)[8][8], char *str);

// display_usage.c
int *ennemy_pid(void);
int *detect_signal1(void);
int *detect_signal2(void);
void receive_usr1(int sig, siginfo_t *siginfo, void *context);
void receive_usr2(int sig, siginfo_t *siginfo, void *context);

// player_one.c
int player_one(void);

// player_two.c
int player_two(int first_pid);

// navy.c
int navy(cell_t (*player)[8], int turn);

// display_grid.c
void display_grid(cell_t (*grid)[8]);

// display_board
void display_board(cell_t (*player)[8], cell_t (*ennemy)[8]);

// you_play.c
int you_play(void);
int get_input(char **str);

// they_play.c
int they_play(void);

//binary conversion
char *deci_to_base(int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);

#endif /*NAVY_H*/
