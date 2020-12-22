/*
** EPITECH PROJECT, 2019
** UNIT TEST
** File description:
** header UNIT TEST
*/

#ifndef UNITTEST_H
#define UNITTEST_H

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>
#include <iostream>
#include <list>

#include "../ex00/find.hpp"
#include "../ex01/MyAlgorithms.hpp"
#include "../ex02/IEncryptionMethod.hpp"
#include "../ex02/Cesar.hpp"
#include "../ex02/OneTime.hpp"

void encryptString(IEncryptionMethod& encryptionMethod,
                   std::string const& toEncrypt);
void decryptString(IEncryptionMethod& encryptionMethod,
                   std::string const& toDecrypt);
void redirect_all_std(void);

#endif
