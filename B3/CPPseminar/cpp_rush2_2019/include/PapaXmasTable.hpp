/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_PAPAXMASTABLE_HPP
#define CPP_RUSH2_2019_PAPAXMASTABLE_HPP

#include "ITable.hpp"

class PapaXmasTable : public ITable
{
    public:
        PapaXmasTable();
        ~PapaXmasTable();
        std::string* look() const;
};

#endif //CPP_RUSH2_2019_PAPAXMASTABLE_HPP
