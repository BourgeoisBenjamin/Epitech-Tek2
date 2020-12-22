/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/

#include <stddef.h>
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    *res = calloc(length + 1, sizeof(int *));

    if (*res == NULL)
        return;

    for (int i = 0; i < length; i++) {
        (*res)[i] = calloc(width + 1, sizeof(int));
        if ((*res)[i] == NULL) {
            free(*res);
            return;
        }
        for (int j = 0; j < width; j++) {
            (*res)[i][j] = tab[i * width + j];
        }
    }
}