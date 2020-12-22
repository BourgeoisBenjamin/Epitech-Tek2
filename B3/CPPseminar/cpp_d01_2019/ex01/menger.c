/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

int calcul_menger(int size, int level, int x, int y)
{
    if (level < 1) return (0);

    size /= 3;
    level--;

    printf("%.3d %.3d %.3d\n", size, x + size, y + size);

    for (int ord = 0; ord < 3; ord++) {
        for (int abs = 0; abs < 3; abs++) {
            if (!(ord == 1 && abs == 1)) {
                calcul_menger(size, level, ord * size + x, abs * size + y);
            }
        }
    }
    return (0);
}

int check_data(int ac, char **av)
{
    if (ac != 3)
        return (0);
    for (int i = 0; av[1][i]; i++) {
        if (isalpha(av[1][i]))
            return (0);
    }
    int test = (int)pow(3, atoi(av[2]));
    if ((atoi(av[1]) % test != 0))
        return (0);
    return (1);
}

int menger(int ac, char **av)
{
    int size = 0;
    int level = 0;

    if (!check_data(ac, av)) {
        fprintf(stderr, "%s", "Error with your arguments!\n");
        return (84);
    }
    size = atoi(av[1]);
    level = atoi(av[2]);
    return (calcul_menger(size, level, 0, 0));
}