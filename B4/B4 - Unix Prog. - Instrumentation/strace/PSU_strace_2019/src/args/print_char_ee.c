/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_char_ee
*/

#include "strace.h"
#include <stdio.h>
#include <sys/ptrace.h>
#include <ctype.h>

static void print_for_execve(void)
{
    fprintf(stderr, "\"\"");
}

void print_char_ee(pid_t child, unsigned long addr, \
struct user_regs_struct regs)
{
    (void)child;
    if (regs.orig_rax == 59)
        return (print_for_execve());
    fprintf(stderr, "0x%lx", addr);
}