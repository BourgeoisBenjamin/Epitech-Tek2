/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D17_2019_CESAR_HPP
#define CPP_D17_2019_CESAR_HPP

#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod
{
    public:
        Cesar();
        ~Cesar();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();
    private:
        int _shift;
};

#endif //CPP_D17_2019_CESAR_HPP
