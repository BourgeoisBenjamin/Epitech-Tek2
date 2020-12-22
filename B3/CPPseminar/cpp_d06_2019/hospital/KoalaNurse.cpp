/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** TODO: add description
*/

#include "KoalaNurse.hpp"
#include <iostream>
#include <ostream>
#include <fstream>

KoalaNurse::KoalaNurse(int id) : _id(id), _work(false)
{
}

KoalaNurse::~KoalaNurse(void)
{
    std::cout << "Nurse "<< this->_id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *SickKoala)
{
    if (SickKoala) SickKoala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string report)
{
    std::string koala = "";
    std::string drug = "";
    std::ifstream file;

    if (report.find(".report") == std::string::npos)
        return (std::string());

    file.open(report.c_str(), std::ios::in);
    if (!file.is_open()) {
        return (std::string());
    }
    if (!getline(file, drug)) {
        file.close();
        return (std::string());
    }
    koala = report.substr(0, report.find(".report"));
    std::cout << "Nurse " << this->_id << ": Kreog! Mr." << koala << " needs a "
    << drug << "!" << std::endl;
    file.close();
    return (drug);
}

void KoalaNurse::timeCheck(void)
{
    if (!this->_work) {
        std::cout << "Nurse " << this->_id << ": Time to get to work!" <<
        std::endl;
        this->_work = true;
    } else if (this->_work) {
        std::cout << "Nurse " << this->_id << ": Time to go home to my "
        "eucalyptus forest!" << std::endl;
        this->_work = false;
    }
}

int KoalaNurse::getID(void)
{
    return (_id);
}
