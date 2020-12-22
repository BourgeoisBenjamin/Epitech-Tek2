/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/
#ifndef CPP_D06_2019_SICKKOALA_HH
#define CPP_D06_2019_SICKKOALA_HH

#include <string>

class SickKoala
{
private:
    std::string _name;
public:
    SickKoala(std::string);
    ~SickKoala();

    void poke();
    bool takeDrug(std::string str);
    void overDrive(std::string str);
    std::string getName();
};

#endif //CPP_D06_2019_SICKKOALA_HH
