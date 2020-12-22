/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this->str == NULL)
        return (1);
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}