/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** TODO: add description
*/

#include "ex04.hpp"

template<typename T>
bool equal(const T &a, const T &b)
{
    return a == b;
}

template<typename T>
bool Tester<T>::equal(const T &a, const T &b)
{
    return a == b;
}

template<typename T>
Tester<T>::Tester()
{
}

template<typename T>
Tester<T>::~Tester()
{
}

template bool equal<int>(const int &a, const int &b);
template bool equal<float>(const float &a, const float &b);
template bool equal<double>(const double &a, const double &b);
template bool equal<std::string>(const std::string &a, const std::string &b);

template Tester<int>::Tester();
template Tester<float>::Tester();
template Tester<double>::Tester();
template Tester<std::string>::Tester();
template Tester<int>::~Tester();
template Tester<float>::~Tester();
template Tester<double>::~Tester();
template Tester<std::string>::~Tester();
template bool Tester<int>::equal(const int &a, const int &b);
template bool Tester<float>::equal(const float &a, const float &b);
template bool Tester<double>::equal(const double &a, const double &b);
template bool Tester<std::string>::equal(const std::string &a, const std::string &b);