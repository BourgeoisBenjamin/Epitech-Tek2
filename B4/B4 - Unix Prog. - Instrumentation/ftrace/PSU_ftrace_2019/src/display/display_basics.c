/*
** EPITECH PROJECT, 2020
** strace
** File description:
** display basics
*/

#include "ftrace.h"

void display_int(unsigned long long arg, pid_t child)
{
    (void)child;
    dprintf(2, "%d", (int)arg);
}

void display_uint(unsigned long long arg, pid_t child)
{
    (void)child;
    dprintf(2, "%u", (unsigned int)arg);
}

void display_long(unsigned long long arg, pid_t child)
{
    (void)child;
    dprintf(2, "%lld", (long long){arg});
}

void display_ulong(unsigned long long arg, pid_t child)
{
    (void)child;
    dprintf(2, "%llu", arg);
}

void display_pointer(unsigned long long arg, pid_t child)
{
    (void)child;
    dprintf(2, "%p", (void *)arg);
}
