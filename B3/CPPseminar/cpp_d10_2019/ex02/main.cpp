/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** TODO: add description
*/

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "memory"
#include "ISquad.hpp"
#include "Squad.hpp"

int main ()
{
    std::unique_ptr<ISquad> vlc(new Squad);
    vlc->push(new TacticalMarine);
    vlc->push(new AssaultTerminator);
    for (int i = 0; i < vlc->getCount(); ++i) {
        const auto cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    return 0;
}