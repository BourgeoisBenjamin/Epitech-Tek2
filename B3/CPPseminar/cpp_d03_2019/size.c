/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

int size(string_t *this)
{
    if (!this->str) return (-1);
    return (strlen(this->str));
}