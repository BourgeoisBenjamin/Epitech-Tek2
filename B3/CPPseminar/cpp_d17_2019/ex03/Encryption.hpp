/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D17_2019_ENCRYPTION_HPP
#define CPP_D17_2019_ENCRYPTION_HPP

#include "IEncryptionMethod.hpp"

using EncryptionMethod_t = void (IEncryptionMethod::*)(char);

class Encryption : public IEncryptionMethod
{
    public:
        Encryption(IEncryptionMethod &, EncryptionMethod_t method);
        ~Encryption();

        void operator=()(char);
    private:
        IEncryptionMethod *_encryptionInstance;
        EncryptionMethod_t _method;
};

#endif //CPP_D17_2019_ENCRYPTION_HPP
