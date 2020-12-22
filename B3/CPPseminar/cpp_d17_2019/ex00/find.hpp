/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D17_2019_FIND_HPP
#define CPP_D17_2019_FIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator do_find(T &container, int pos)
{
    return (std::find(container.begin(), container.end(), pos));
}

#endif //CPP_D17_2019_FIND_HPP
