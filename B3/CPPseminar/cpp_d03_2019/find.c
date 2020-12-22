/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return (find_c(this, str->str, pos));
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *find = NULL;

    if (!this->str) return (-1);
    if (pos >= strlen(this->str)) return (-1);
    find = strstr(&this->str[pos], str);
    if (!find) return (-1);

    return (find - this->str);
}