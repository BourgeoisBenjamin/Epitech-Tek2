/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** TODO: add description
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action) : _action(&action)
{
}

DomesticKoala::DomesticKoala(const DomesticKoala &copy) : _action(copy
._action), _learnAction(copy._learnAction), _associateChar(copy._associateChar)
{
}

DomesticKoala::~DomesticKoala()
{
    _learnAction.clear();
    _associateChar.clear();
}

DomesticKoala& DomesticKoala::operator=(const DomesticKoala &copy)
{
    _learnAction.clear();
    _associateChar.clear();
    _action = copy._action;
    _learnAction = copy._learnAction;
    _associateChar = copy._associateChar;
    return *this;
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    _learnAction.clear();
    _associateChar.clear();
    _action = &action;
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    unsigned int i = 0;
    while (i < _associateChar.size()) {
        if (_associateChar[i] == command) {
            ((*_action).*_learnAction[i])(param);
            break;
        }
        i++;
    }
}

const std::vector<methodPointer_t> * DomesticKoala::getActions() const
{
    return &_learnAction;
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _associateChar.push_back(command);
    _learnAction.push_back(action);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    unsigned int i = 0;
    while (i < _associateChar.size()) {
        if (_associateChar[i] == command) {
            _learnAction.erase(_learnAction.begin() + i);
            _associateChar.erase(_associateChar.begin() + i);
            break;
        }
        i++;
    }
}