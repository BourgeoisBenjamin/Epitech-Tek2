/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/error.h"

void *what(void)
{
    fprintf(stderr, "Error : %s\n", strerror(errno));
    return (NULL);
}