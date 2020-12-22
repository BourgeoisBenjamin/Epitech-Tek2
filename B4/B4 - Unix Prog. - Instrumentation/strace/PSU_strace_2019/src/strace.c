/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include "strace.h"

int strace_process(strace_info_t *info)
{
    if (info->flag_p == true)
        return (trace_child(info));
    return (trace_prog(info));
}

int strace(int argc, char **argv, char **envp)
{
    strace_info_t *info = init_strace(argc, argv, envp);

    if (!info)
        return (84);
    parse_arg(info);
    strace_error(info);
    strace_process(info);
    free_strace(info);
    return (0);
}
