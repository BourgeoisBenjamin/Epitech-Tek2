/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include <ostream>
#include <iostream>
#include <string>
#include <fstream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : _name(name), _work(false)
{
    std::cout << "Dr." << _name << ": I'm Dr."<< _name << "! How do you "
                                                         "kreog?" <<
    std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *SickKoala)
{
    std::string report;
    std::ofstream file;
    std::string drug[] = {"Mars", "Buronzand", "Viagra",
                          "Extasy", "Eucalyptus leaf"};

    std::cout << "Dr." << _name << ": So what's goerking you Mr." <<
    SickKoala->getName() << "?" << std::endl;
    SickKoala->poke();

    report = SickKoala->getName() + ".report";
    file.open(report.c_str(), std::ios::out);
    if (!file.is_open()) return;
    file << drug[rand() % 5] << std::endl;
    file.close();
}

void KoalaDoctor::timeCheck(void)
{
    if (!_work) {
        std::cout << "Dr."<< _name << ": Time to get to work!" <<
        std::endl;
        _work = true;
    } else if (_work) {
        std::cout << "Dr."<< _name << ": Time to go home to my "
                                           "eucalyptus forest!" << std::endl;
        _work = false;
    }
}

std::string KoalaDoctor::getName(void)
{
    return (_name);
}