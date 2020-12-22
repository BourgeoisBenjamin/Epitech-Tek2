/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;
    for (i = 0; i < n && this->str[pos + i]; i++)
        s[i] = this->str[pos + i];
    if (!this->str[pos + i] && i != n) {
        s[i] = '\0';
        i++;
    }
    return (i);
}