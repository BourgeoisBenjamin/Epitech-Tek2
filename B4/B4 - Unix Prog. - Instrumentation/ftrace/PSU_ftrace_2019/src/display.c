/*
** EPITECH PROJECT, 2020
** strace
** File description:
** display.c
*/

#include <stdint.h>
#include "ftrace.h"
#include <stdio.h>
#include <ctype.h>
#include <linux/aio_abi.h>
#include <signal.h>

static void display_basic_arg(unsigned long long arg)
{
    dprintf(2, "0x%llx", arg);
}

void display_syscall(struct user_regs_struct *regs)
{
    int syscode = regs->orig_rax;
    unsigned long long args[6] = {regs->rdi, regs->rsi, regs->rdx,
        regs->r10, regs->r8, regs->r9};

    dprintf(2, "Syscall %s(", syscalls[syscode].name);
    for (int i = 0; i < 6; i++) {
        if (syscalls[syscode].args[i] == NO_ARG)
            break;
        display_basic_arg(args[i]);
        if (i < 5 && syscalls[syscode].args[i + 1] != NO_ARG)
            dprintf(2, ", ");
    }
    dprintf(2, ") = 0x%llx\n", regs->rax);
}
