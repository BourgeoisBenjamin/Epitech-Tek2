/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** TODO: add description
*/

#ifndef DRAWING_H
#define DRAWING_H

#include <stddef.h>
#include <stdint.h>

typedef struct point_s
{
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin, size_t size, uint32_t
color);

#endif //DRAWING_H
