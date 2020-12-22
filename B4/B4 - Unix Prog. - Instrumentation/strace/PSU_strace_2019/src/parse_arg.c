/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** TODO: add description
*/

#include "strace.h"
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void is_help_option(strace_info_t *info, int i)
{
    if (strcmp(info->argv[i], "--help") == 0) {
        help(info->argv[0]);
        free_strace(info);
        exit(0);
    }
}

int is_s_option(strace_info_t *info, int i)
{
    if (strcmp(info->argv[i], "-s") == 0) {
        info->flag_s = true;
        return (1);
    }
    return (0);
}

int is_p_option(strace_info_t *info, int i)
{
    char *end = NULL;
    if (strcmp(info->argv[i], "-p") == 0) {
        if (i + 1 >= info->argc) {
            help(info->argv[0]);
            free_strace(info);
            exit(84);
        }
        info->flag_p = true;
        info->child_pid = strtol(info->argv[i + 1], &end, 10);
        if (end == optarg) {
            help(info->argv[0]);
            free_strace(info);
            exit(84);
        }
        return (1);
    }
    return (0);
}

void add_cmd_arg(strace_info_t *info, char *cmd)
{
    int i = 0;
    while (info->cmd[i])
        i++;
    info->cmd[i] = cmd;
}

int parse_arg(strace_info_t *info)
{
    int i = 0;
    if (info->argc < 2) {
        help(info->argv[0]);
        free_strace(info);
        exit(84);
    }
    for (i = 1; info->argv[i]; i++) {
        is_help_option(info, i);
        if (is_s_option(info, i))
            continue;
        if (is_p_option(info, i)) {
            i++;
            continue;
        }
        break;
    }
    for (; info->argv[i]; i++)
        add_cmd_arg(info, info->argv[i]);
    return (0);
}