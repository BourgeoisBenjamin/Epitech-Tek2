/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <sys/ptrace.h>
#include "strace.h"

void print_unsigned_long_e(pid_t child, unsigned long addr, struct
user_regs_struct regs)
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
    while ((unsigned long)(tmp = ptrace(PTRACE_PEEKDATA, child, addr + i,
    NULL))
    != 0) {
        if (i == 0)
            fprintf(stderr, "%lu", (unsigned long)tmp);
        else
            fprintf(stderr, ", %lu", (unsigned long)tmp);
        i += 4;
    }
    fprintf(stderr, "]");
}