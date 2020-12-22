/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D16_2019_DOMESTICKOALA_HPP
#define CPP_D16_2019_DOMESTICKOALA_HPP

#include "KoalaAction.hpp"
#include <vector>

using methodPointer_t = void (KoalaAction::*)(const std::string&);

class DomesticKoala
{
    public:
        DomesticKoala(KoalaAction &);
        ~DomesticKoala();
        DomesticKoala(const DomesticKoala &);
        DomesticKoala &operator=(const DomesticKoala &);

        const std::vector<methodPointer_t> *getActions() const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);
    private:
        KoalaAction *_action;
        std::vector<methodPointer_t> _learnAction;
        std::vector<char> _associateChar;
};

#endif //CPP_D16_2019_DOMESTICKOALA_HPP
