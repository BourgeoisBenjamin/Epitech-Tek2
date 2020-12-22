/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D15_2019_EX02_HPP
#define CPP_D15_2019_EX02_HPP

#include <iostream>
#include <ostream>

template<typename T>
const T &min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (a > b)
        return b;
    return a;
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a > b)
        return b;
    return a;
}

template<typename T>
const T &templateMin(const T *array, int size)
{
    T &minimum = const_cast<T&>(array[0]);
    for (int i = 1; i < size; i++) {
        minimum = min<T>(minimum, array[i]);
    }
    return minimum;
}

const int &nonTemplateMin(const int *array, int size)
{
    int &minimum = const_cast<int&>(array[0]);
    for (int i = 1; i < size; i++) {
        minimum = min(minimum, array[i]);
    }
    return minimum;
}

#endif //CPP_D15_2019_EX02_HPP
