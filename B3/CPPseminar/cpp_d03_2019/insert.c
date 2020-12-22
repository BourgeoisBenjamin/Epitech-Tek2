/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** TODO: add description
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *temp = NULL;
    size_t pos_str = 0;
    if (strlen(this->str) <= pos) return (this->append_c(this, str));

    temp = strdup(this->str);
    this->str = realloc(this->str, sizeof(char) * (strlen(this->str) + strlen
    (str) + 1));
    memset(this->str, 0, strlen(this->str) + strlen(str) + 1);
    for (pos_str = 0; pos_str != pos; pos_str++)
        this->str[pos_str] = temp[pos_str];
    for (int i = 0; str[i]; i++)
        this->str[i + pos] = str[i];
    for (int i = strlen(this->str); temp[pos_str]; pos_str++, i++)
        this->str[i] = temp[pos_str];
    free(temp);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    insert_c(this, pos, str->str);
}