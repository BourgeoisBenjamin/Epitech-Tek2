/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (this->str)
        return (this->str);
    return (NULL);
}