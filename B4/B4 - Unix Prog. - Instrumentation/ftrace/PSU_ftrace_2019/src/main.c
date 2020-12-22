/*
** EPITECH PROJECT, 2020
** strace
** File description:
** main
*/

#include "ftrace.h"

void display_usage(void)
{
    printf("USAGE: ftrace <command>\n");
}

int main(int ac, char **av)
{
    if (ac == 1 || (ac == 2 && !strcmp(av[1], "--help"))) {
        display_usage();
        return (84);
    }
    signal(SIGINT, strace_sig_handler);
    if (my_ftrace(&av[1]))
        return 84;
    return 0;
}
