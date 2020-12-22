/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <string.h>

int get_min(int a, int b)
{
    return ((a <= b ? a : b));
}

int get_line_size(const int *line)
{
    int i = 0;

    while (line[i]) {
        i++;
    }
    return (i);
}

int pyramid_path(int size, const int **map)
{
    int prevLine[size];
    memset(prevLine, 0, size);

    for (int i = 0; i < get_line_size(map[size - 1]); i++) {
        prevLine[i] = map[size - 1][i];
    }

    for (int i = size - 2; i >= 0; i--) {
        for (int j = 0; j < get_line_size(map[i + 1]); j++) {
            prevLine[j] = map[i][j] + get_min(prevLine[j], prevLine[j + 1]);
        }
    }
    return (prevLine[0]);
}