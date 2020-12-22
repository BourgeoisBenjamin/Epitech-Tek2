/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include "strace.h"
#include <stdlib.h>
#include <stdio.h>

void free_strace(strace_info_t *info)
{
    if (!info)
        return;
    if (info->cmd)
        free(info->cmd);
    free(info);
}

strace_info_t *init_strace(int argc, char **argv, char **envp)
{
    strace_info_t *new_strace = malloc(sizeof(strace_info_t));

    if (!new_strace) {
        fprintf(stderr, "strace: error, please retry\n");
        return (NULL);
    }
    new_strace->cmd = calloc(sizeof(char *), argc);
    if (!new_strace->cmd) {
        fprintf(stderr, "strace: error, please retry\n");
        return (NULL);
    }
    new_strace->flag_s = false;
    new_strace->flag_p = false;
    new_strace->child_pid = -1;
    new_strace->argc = argc;
    new_strace->argv = argv;
    new_strace->envp = envp;
    return (new_strace);
}