/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_void_e
*/

#include "strace.h"
#include <stdio.h>
#include <sys/ptrace.h>
#include <ctype.h>

static void print_string(char *str)
{
    for (size_t i = 0; i < 8; i++) {
        if (isprint(str[i])) {
            fprintf(stderr, "%c", str[i]);
            continue;
        }
        if (str[i] >= 0)
            fprintf(stderr, "\\%o", str[i]);
        else
            fprintf(stderr, "\\%o", str[i] & 0x000000ff);
    }
}

static void print_str(pid_t child, unsigned long addr)
{
    long tmp;
    size_t i = 0;

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

void print_void_e(pid_t child, unsigned long addr, \
struct user_regs_struct regs)
{
    const long long unsigned int raxs[] = {
        0, 1
    };

    if (addr == 0) {
        fprintf(stderr, "NULL");
        return;
    }

    for (size_t i = 0; i < 2; i++) {
        if (raxs[i] == regs.orig_rax) {
            print_str(child, addr);
            return;
        }
    }
    fprintf(stderr, "0x%lx", addr);
}