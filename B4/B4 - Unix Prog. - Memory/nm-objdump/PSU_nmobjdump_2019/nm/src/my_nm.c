/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/nm.h"

int my_nm(int argc, char **argv)
{
    nm_t *info = init_nm(argc, argv);
    int error = 0;
    if (!info) {
        fprintf(stderr, "%s: Error!", argv[0]);
        return (84);
    }
    if (!info->files[0]) {
        error += nm_process(info, "a.out");
    } else {
        for (int i = 0; info->files[i]; i++)
            error += nm_process(info, info->files[i]);
    }
    error = (error != 0) ? 84 : 0;
    free(info);
    return (error);
}