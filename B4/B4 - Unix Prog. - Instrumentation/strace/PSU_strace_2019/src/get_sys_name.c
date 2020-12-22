/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include "strace.h"

char *get_sys_name(unsigned long long int id)
{
    for (int i = 0; syscalls[i].id != -1; i++) {
        if (syscalls[i].id == (int)id)
            return syscalls[i].name;
    }
    return ("UNKNOWN");
}