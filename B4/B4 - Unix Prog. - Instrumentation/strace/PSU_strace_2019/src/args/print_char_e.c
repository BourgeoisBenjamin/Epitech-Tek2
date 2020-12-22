/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_char_e
*/

#include "strace.h"
#include <stdio.h>
#include <sys/ptrace.h>
#include <ctype.h>

static void print_string(char *str)
{
    for (size_t i = 0; i != 8; i++) {
        if (isprint(str[i]))
            fprintf(stderr, "%c", str[i]);
    }
}

static void print_for_execve(void)
{
    fprintf(stderr, "\"\"");
}

void print_char_e(pid_t child, unsigned long addr, \
struct user_regs_struct regs)
{
    long tmp;
    size_t i = 0;

    if (regs.orig_rax == 59)
        return (print_for_execve());
    if (addr == 0) {
        fprintf(stderr, "NULL");
        return;
    }
    fprintf(stderr, "\"");
    for (; i < 32; i += 8) {
        tmp = ptrace(PTRACE_PEEKDATA, child, addr + i, NULL);
        print_string((char *)(&tmp));
    }
    tmp = ptrace(PTRACE_PEEKDATA, child, addr + i, NULL);
    if (tmp == 0) {
        fprintf(stderr, "\"");
        return;
    }
    fprintf(stderr, "\"...");
}