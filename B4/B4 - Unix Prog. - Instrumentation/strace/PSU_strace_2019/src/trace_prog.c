/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include "strace.h"
#include <unistd.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

static pid_t child_pid;

static void sig_handler(int sig)
{
    (void)sig;
    ptrace(PTRACE_DETACH, child_pid, NULL, NULL);
    ptrace(PTRACE_CONT, child_pid, NULL, NULL);
    fprintf(stderr, "strace: Process %d detached\n", child_pid);
    exit(0);
}

int trace_prog(strace_info_t *info)
{
    signal(SIGINT, &sig_handler);
    signal(SIGTERM, &sig_handler);
    if ((info->child_pid = fork()) == -1) {
        fprintf(stderr, "%s: fork() failed\n", info->argv[0]);
        free_strace(info);
        exit(84);
    } else if (info->child_pid == 0) {
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
            kill(getpid(), SIGSTOP);
        if (execvp(info->cmd[0], info->cmd) == -1) {
            fprintf(stderr, "%s: Can't stat '%s': %s\n", info->argv[0],
            info->cmd[0], strerror(errno));
            free_strace(info);
            exit(84);
        }
    } else {
        return (trace_pid(info));
    }
    return (0);
}