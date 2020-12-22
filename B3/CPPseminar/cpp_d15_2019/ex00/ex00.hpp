/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** TODO: add description
*/

#ifndef EX00_HPP
#define EX00_HPP

#include <algorithm>
#include <utility>

template <typename T>
void swap(T &a, T &b)
{
    std::swap(a, b);
}

template <typename T>
const T& min(const T &a, const T &b)
{
    if (a == b)
        return b;
    return std::min(a, b);
}

template <typename T>
const T& max(const T &a, const T &b)
{
    if (a == b)
        return b;
    return std::max(a, b);
}

template <typename T>
T add(const T &a, const T &b)
{
    return a + b;
}

#endif //EX00_HPP
