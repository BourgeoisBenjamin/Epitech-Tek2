/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** TODO: add description
*/

#include "drawing.h"
#include "bitmap.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size, uint32_t
color)
{
    for (uint32_t i = 0; i < size; i++) {
        for (uint32_t j = 0; j < size; j++) {
            img[i][j] = color;
        }
    }
}