/*
** EPITECH PROJECT, 2020
** strace
** File description:
** my_strace
*/

#include "ftrace.h"

static void exec_program(const char *filepath, char **av)
{
    if (ptrace(PT_TRACE_ME) == -1)
        return;
    execvp(filepath, av);
    dprintf(2, "ftrace: could not execute %s\n", filepath);
}

static bool make_single_step(pid_t pid, bool *is_call, int *status,
ftrace_info_t *info)
{
    unsigned long long data;
    struct user_regs_struct regs;

    trace_signal(pid);
    if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
        return (false);
    data = ptrace(PTRACE_PEEKDATA, pid, regs.rip, 0);
    if (*is_call)
        display_call(&regs, info);
    *is_call = false;
    if (is_syscall(&regs))
        display_syscall(&regs);
    if (is_function_call(data))
        *is_call = true;
    if (is_ret(data))
        display_ret(info);
    ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    waitpid(pid, status, 0);
    return (true);
}

static int tracing(int pid, ftrace_info_t *info)
{
    int status = 0;
    bool is_call = false;

    wrap_traced_pid(true, pid);
    waitpid(pid, &status, 0);
    do {
        make_single_step(pid, &is_call, &status, info);
    } while (!WIFEXITED(status));
    dprintf(2, "+++ exited with %d +++\n", WEXITSTATUS(status));
    return (0);
}

int my_ftrace(char **av)
{
    pid_t pid = 0;
    ftrace_info_t *info = ftrace_info_init(av[0]);

    if (info == NULL)
        return (-1);
    pid = fork();
    info->child_pid = pid;
    if (pid == -1)
        return (-1);
    if (pid == 0) {
        exec_program(av[0], av);
        return (-1);
    }
    return (tracing(pid, info));
}
