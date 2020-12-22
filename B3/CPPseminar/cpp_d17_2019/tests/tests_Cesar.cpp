/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** redirect unit test
*/

#include "unittest.hpp"

void encryptString(IEncryptionMethod& encryptionMethod,
                          std::string const& toEncrypt)
{
    size_t len = toEncrypt.size();
    encryptionMethod.reset();
    for (size_t i = 0; i < len; ++i)
    {
        encryptionMethod.encryptChar(toEncrypt[i]);
    }
    std::cout << std::endl;
}

void decryptString(IEncryptionMethod& encryptionMethod,
                          std::string const& toDecrypt)
{
    size_t len = toDecrypt.size();
    encryptionMethod.reset();
    for (size_t i = 0; i < len; ++i)
    {
        encryptionMethod.decryptChar(toDecrypt[i]);
    }
    std::cout << std::endl;
}

Test(Cesar, test00, .init=redirect_all_std)
{
    Cesar c;
    encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
    decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
    encryptString(c, "KIKOO");
    encryptString(c, "LULZ XD");
    decryptString(c, "Ziqivun ea Ndcsg.Wji !");
    cr_assert_stdout_eq_str("Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !\n"
                            "Je clair Luc, ne pas ? Ze woudrai un kekos !\n"
                            "NMPUV\n"
                            "OYQF FM\n"
                            "Welcome to Zombo.Com !\n");
}
