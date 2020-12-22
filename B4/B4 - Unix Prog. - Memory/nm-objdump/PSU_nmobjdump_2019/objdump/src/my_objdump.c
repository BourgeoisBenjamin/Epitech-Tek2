/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/objdump.h"

int my_objdump(char **argv)
{
    objdump_t *info = init_objdump(argv);
    int error = 0;
    if (!info) {
        fprintf(stderr, "%s: Error!", argv[0]);
        return (84);
    }
    if (!info->files[0]) {
        error += objdump_process(info, "a.out");
    } else {
        for (int i = 0; info->files[i]; i++)
            error += objdump_process(info, info->files[i]);
    }
    error = (error != 0) ? 84 : 0;
    free(info);
    return (error);
}