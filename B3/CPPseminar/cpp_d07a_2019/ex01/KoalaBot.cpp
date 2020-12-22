/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** TODO: add description
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) : _serial(serial)
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    std::swap(_arms, arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    std::swap(_legs, legs);
}

void KoalaBot::swapParts(Head &head)
{
    std::swap(_head, head);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_arms.isFunctionnal() && _legs.isFunctionnal() && _head.isFunctionnal())
        return (true);
    return (false);
}