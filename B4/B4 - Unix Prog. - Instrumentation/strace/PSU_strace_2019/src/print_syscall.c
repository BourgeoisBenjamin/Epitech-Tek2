/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_syscall
*/

#include "strace.h"
#include <sys/user.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void print_args(struct user_regs_struct regs, strace_info_t *info)
{
    int nb_args = get_nb_args(regs.orig_rax);
    const unsigned long long int registers[] = {
        regs.rdi, regs.rsi, regs.rdx, regs.r10, regs.r8, regs.r9
    };

    for (int i = 0; i < nb_args; i++) {
        if (i != 0)
            fprintf(stderr, ", ");
        if (info->flag_s)
            print_arg_details(info, registers, i, regs);
        else
            fprintf(stderr, "0x%llx", registers[i]);
    }
}

static void print_return_value(struct user_regs_struct regs)
{
    const sys_type values[] = {
        INT, UNSIGNED_INT, SSIZE_T, SIZE_T, LONG, UNSIGNED_LONG,
        PID_T, GID_T, UID_T, U64, U32, OFF64_T, UINT64_T, UNKNOWN
    };

    if (regs.orig_rax == 12) {
        fprintf(stderr, ") = 0x%llx\n", regs.rax);
        return;
    }
    for (size_t i = 0; values[i] != UNKNOWN; i++) {
        if (values[i] == syscalls[regs.orig_rax].return_type) {
            fprintf(stderr, ") = %lld\n", regs.rax);
            return;
        }
    }
    fprintf(stderr, ") = 0x%llx\n", regs.rax);
}

void print_syscall(struct user_regs_struct regs, strace_info_t *info)
{
    if (regs.orig_rax > 335)
        return;
    fprintf(stderr, "%s(", syscalls[regs.orig_rax].name);
    print_args(regs, info);
    if (info->flag_s)
        print_return_value(regs);
    else
        fprintf(stderr, ") = 0x%llx\n", regs.rax);
}