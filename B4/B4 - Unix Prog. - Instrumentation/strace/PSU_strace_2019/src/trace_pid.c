/*
** EPITECH PROJECT, 2020
** strace
** File description:
** trace_pid
*/

#include "strace.h"
#include <unistd.h>
#include <sys/ptrace.h>
#include <wait.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <syscall.h>
#include <sys/user.h>
#include <stdlib.h>

static int is_a_syscall(struct user_regs_struct regs, strace_info_t *info)
{
    (void)info;
    if (regs.orig_rax != (unsigned long long int)-1)
        return (true);
    return (false);
}

int trace_pid(strace_info_t *info)
{
    int status;
    bool first = true;

    while (1) {
        struct user_regs_struct regs;
        waitpid(info->child_pid, &status, 0);
        if (WIFEXITED(status))
            break;
        ptrace(PTRACE_GETREGS, info->child_pid, NULL, &regs);
        if (is_a_syscall(regs, info))
            print_syscall(regs, info);
        ptrace(PTRACE_SINGLESTEP, info->child_pid, NULL, NULL);
        first = false;
    }
    if (first) {
        free_strace(info);
        exit(84);
    }
    fprintf(stderr, "exit_group(%d) = ?\n+++ exited with %d +++\n",
    WEXITSTATUS(status), WEXITSTATUS(status));
    return (0);
}
