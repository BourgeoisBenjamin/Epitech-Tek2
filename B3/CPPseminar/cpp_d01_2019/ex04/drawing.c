/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** TODO: add description
*/

#include "bitmap.h"
#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size, uint32_t
color)
{
    for (uint32_t i = origin->y; i < size + origin->y; i++) {
        for (uint32_t j = origin->x; j < size + origin->x; j++) {
            img[i][j] = color;
        }
    }
}