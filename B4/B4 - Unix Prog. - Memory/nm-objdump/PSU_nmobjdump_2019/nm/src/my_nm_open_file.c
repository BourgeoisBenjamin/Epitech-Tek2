/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../include/nm.h"

int nm_open_file(const char *file)
{
    int fd = -1;
    if (access(file, F_OK) == -1)
        return (-1);
    if ((fd = open(file, O_RDONLY)) == -1)
        return (-1);
    return (fd);
}