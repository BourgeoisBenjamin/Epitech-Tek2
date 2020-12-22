/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <sys/ptrace.h>
#include "strace.h"

void print_size_t_e(pid_t child, unsigned long addr, struct user_regs_struct
regs)
{
    (void)child;
    (void)regs;
    long tmp;
    int i = 0;
    if (addr == 0) {
        fprintf(stderr, "NULL");
        return;
    }
    fprintf(stderr, "[");
    while ((size_t)(tmp = ptrace(PTRACE_PEEKDATA, child, addr + i, NULL)) !=
    0) {
        if (i == 0)
            fprintf(stderr, "%zu", (size_t)tmp);
        else
            fprintf(stderr, ", %zu", (size_t)tmp);
        i += 4;
    }
    fprintf(stderr, "]");
}