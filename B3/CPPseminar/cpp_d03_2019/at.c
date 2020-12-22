/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (!this->str) return (-1);
    if (strlen(this->str) <= pos) return (-1);
    return (this->str[pos]);
}