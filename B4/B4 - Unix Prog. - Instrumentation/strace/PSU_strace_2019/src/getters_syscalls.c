/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** getters_syscalls
*/

#include "strace.h"

int get_nb_args(int id)
{
    int nb = 0;
    const sys_type types[] = {
        syscalls[id].p1, syscalls[id].p2, syscalls[id].p3, syscalls[id].p4,
        syscalls[id].p5, syscalls[id].p6
    };

    for (size_t i = 0; i < 6; i++) {
        if (types[i] != UNKNOWN)
            nb++;
    }
    return (nb);
}