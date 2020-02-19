/*
** EPITECH PROJECT, 2019
** navy
** File description:
** include navy
*/

#ifndef NAVY_H_
#define NAVY_H_

// display_usage.c
void display_usage(void);

// error_detection.c
int detect_errors(int argc, char **argv);
int is_incorrect_pid(char *arg);
int errors_in_file(char *filepath);

#endif /*NAVY_H*/