/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** TODO: add description
*/

#include "Cesar.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>

Cesar::Cesar() : _shift(3)
{
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    if (!std::isalpha(plainchar)) {
        _shift++;
        std::cout << plainchar;
        return;
    }
    if (std::isupper(plainchar))
        plainchar = char(int(plainchar + _shift - 65) % 26 + 65);
    else
        plainchar = char(int(plainchar + _shift - 97) % 26 + 97);
    _shift++;
    std::cout << plainchar;
}

void Cesar::decryptChar(char cipherchar)
{
    if (!std::isalpha(cipherchar)) {
        _shift++;
        _shift %= 26;
        std::cout << cipherchar;
        return;
    }
    if (std::isupper(cipherchar))
        cipherchar = char(int(cipherchar + (26 -_shift) - 65) % 26 + 65);
    else
        cipherchar = char(int(cipherchar + (26 - _shift) - 97) % 26 + 97);
    _shift++;
    _shift %= 26;
    std::cout << cipherchar;
}

void Cesar::reset()
{
    _shift = 3;
}