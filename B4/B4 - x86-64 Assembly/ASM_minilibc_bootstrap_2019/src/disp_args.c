/*
** EPITECH PROJECT, 2020
** ASM_minilibc_bootstrap_2019
** File description:
** TODO: add description
*/

#include <stdio.h>

void disp_args(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        printf("%s: %i\n", argv[i], my_strlen(argv[i]));
    }
}