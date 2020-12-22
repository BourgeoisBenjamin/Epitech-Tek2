/*
** EPITECH PROJECT, 2020
** strace
** File description:
** read from pid
*/

#include "ftrace.h"

int read_from_pid(pid_t pid, void *addr, size_t size, void *to_fill)
{
    unsigned long data = 0;

    for (size_t i = 0; i < size; i += 8) {
        data = ptrace(PTRACE_PEEKDATA, pid, addr + i, 0);
        if ((long){data} == -1)
            return (-1);
        for (int j = 0; j < 8 && i + j < size; j++) {
            (char *){to_fill}[i + j] = data & 0xff;
            data >>= 8;
        }
    }
    return (0);
}
