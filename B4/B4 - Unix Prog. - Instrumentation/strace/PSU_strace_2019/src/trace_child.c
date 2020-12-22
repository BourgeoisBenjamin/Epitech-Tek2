/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "strace.h"

static pid_t child_pid;

static void sig_handler(int sig)
{
    (void)sig;
    ptrace(PTRACE_DETACH, child_pid, NULL, NULL);
    ptrace(PTRACE_CONT, child_pid, NULL, NULL);
    fprintf(stderr, "strace: Process %d detached\n", child_pid);
    exit(0);
}

int trace_child(strace_info_t *info)
{
    child_pid = info->child_pid;

    signal(SIGINT, &sig_handler);
    signal(SIGTERM, &sig_handler);
    if (ptrace(PTRACE_ATTACH, child_pid, NULL, NULL) == -1) {
        fprintf(stderr, "%s: attach: ptrace(PTRACE_ATTACH, %d): No such "
        "process\n", info->argv[0], info->child_pid);
        free_strace(info);
        exit(84);
    }
    fprintf(stderr, "%s: Process %d attached\n", info->argv[0],
    info->child_pid);
    return (trace_pid(info));
}