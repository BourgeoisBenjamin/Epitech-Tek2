/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D15_2019_EX01_HPP
#define CPP_D15_2019_EX01_HPP

#include <cstring>

template<typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return 0;
    if (a < b)
        return -1;
    return 1;
}

template<>
int compare(const char *const &a, const char * const &b)
{
    if (std::strcmp(a, b) < 0)
        return -1;
    if (std::strcmp(a, b))
        return 1;
    return 0;
}

#endif //CPP_D15_2019_EX01_HPP
