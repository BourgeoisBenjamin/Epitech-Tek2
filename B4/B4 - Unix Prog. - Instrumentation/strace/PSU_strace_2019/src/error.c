/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include "strace.h"
#include <stdlib.h>
#include <stdio.h>

int strace_error(strace_info_t *info)
{
    if (!info->cmd[0] && !info->flag_p) {
        help(info->argv[0]);
        free_strace(info);
        exit(0);
    }
    if (info->flag_p && info->child_pid < 1) {
        fprintf(stderr, "%s: Invalid process id: '%d'\n", info->argv[0],
        info->child_pid);
        free_strace(info);
        exit(84);
    }
    return (0);
}