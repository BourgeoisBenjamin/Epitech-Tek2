/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** TODO: add description
*/

#include "ftrace.h"

char *get_signal_name(int code)
{
    for (int i = 0; signals[i].code != -1; i++) {
        if (signals[i].code == code)
            return (signals[i].name);
    }
    return ("UNKNOWN");
}

int trace_signal(int pid)
{
    siginfo_t siginfo;
    if (ptrace(PTRACE_GETSIGINFO, pid, NULL, &siginfo) == -1)
        return (0);
    if (siginfo.si_code != SI_USER)
        return (0);
    dprintf(2, "Received signal %s\n", get_signal_name(siginfo.si_signo));
    return (0);
}

