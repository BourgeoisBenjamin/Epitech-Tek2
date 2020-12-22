/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

void clear(string_t *this)
{
    if (this->str)
        free(this->str);
    this->str = NULL;
}