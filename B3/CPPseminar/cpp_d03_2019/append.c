/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    this->append_c(this, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    if (!ap) return;

    this->str = realloc(this->str, sizeof(char) * (strlen(ap) + strlen
    (this->str)) + 1);
    if (!this->str) return;
    strcat(this->str, ap);
}