/*
** EPITECH PROJECT, 2020
** signal_handler
** File description:
** signal_handler
*/

#include "ftrace.h"
#include <signal.h>
#include <stdlib.h>

pid_t wrap_traced_pid(bool stock, pid_t pid)
{
    static pid_t wrapped = 0;

    if (stock)
        wrapped = pid;
    return (wrapped);
}

void strace_sig_handler(int sig)
{
    pid_t pid = wrap_traced_pid(false, 0);
    (void)sig;
    if (pid) {
        ptrace(PTRACE_DETACH, pid, NULL, NULL);
        dprintf(2, "ftrace: Process %d detached\n", pid);
    }
    exit(0);
}
