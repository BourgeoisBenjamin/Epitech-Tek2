/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D15_2019_EX03_HPP
#define CPP_D15_2019_EX03_HPP

#include <iostream>
#include <ostream>

template<typename T>
void foreach(const T *tab, void (func)(const T &elem), int size)
{
    for (int i = 0; i < size; i++)
    {
        (*func)(tab[i]);
    }
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

#endif //CPP_D15_2019_EX03_HPP
