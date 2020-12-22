/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

void string_destroy(string_t *this)
{
    if (this->str)
        free(this->str);
    memset(this, 0, sizeof(string_t));
}