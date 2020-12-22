/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D15_2019_EX04_HPP
#define CPP_D15_2019_EX04_HPP

#include <string>

template<typename T>
bool equal(const T &a, const T &b);

template<typename T>
class Tester
{
    public:
        Tester();
        ~Tester();
        bool equal(const T &a, const T &b);
};
#endif //CPP_D15_2019_EX04_HPP
