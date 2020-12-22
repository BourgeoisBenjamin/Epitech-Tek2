/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D17_2019_ONETIME_HPP
#define CPP_D17_2019_ONETIME_HPP

#include "IEncryptionMethod.hpp"
#include <iostream>
#include <ostream>
#include <string>

class OneTime : public IEncryptionMethod
{
    public:
        OneTime(const std::string &key);
        ~OneTime();

        void encryptChar(char);
        void decryptChar(char);
        void reset();
    private:
        std::string _key;
        int _index;
};

#endif //CPP_D17_2019_ONETIME_HPP
