/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include <stdio.h>

void help(char *exec_name)
{
    fprintf(stderr, "USAGE: %s [-s] [-p <pid>|<command>]\n", exec_name);
}