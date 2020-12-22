/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** TODO: add description
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key) : _key(key), _index(0)
{
}

OneTime::~OneTime()
{
}

void OneTime::encryptChar(char plainchar)
{
    if (std::isalpha(plainchar)) {
        int base = _key[_index] > 96 ? 97 : 65;
        if (plainchar > 96) {
            plainchar = (plainchar - 97 + (_key[_index] - base)) % 26 + 97;
        } else {
            plainchar = (plainchar - 65 + (_key[_index] - base)) % 26 + 65;
        }
    }
    std::cout << plainchar;
    _index++;
    _index %= _key.size();
}

void OneTime::decryptChar(char cipherchar)
{
    if (std::isalpha(cipherchar)) {
        int base = _key[_index] > 96 ? 97 : 65;
        if (cipherchar > 96) {
            cipherchar = (cipherchar - 122 - (_key[_index] - base)) % 26 + 122;
        } else {
            cipherchar = (cipherchar - 90 - (_key[_index] - base)) % 26 + 90;
        }
    }
    std::cout << cipherchar;
    _index++;
    _index %= _key.size();
}

void OneTime::reset()
{
    _index = 0;
}