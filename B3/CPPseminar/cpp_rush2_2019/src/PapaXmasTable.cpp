/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
    std::cout << "Table created" << std::endl;
}

PapaXmasTable::~PapaXmasTable()
{
    std::cout << "Table destroyed" << std::endl;
}

std::string* PapaXmasTable::look() const
{
    std::string *titleArray = new std::string[_list.size() + 1];
    int i = 0;
    for (std::list<Toy*>::const_iterator iterator = _list.begin(), end =
        _list.end(); iterator != end; iterator++) {
        titleArray[i] = std::string((*iterator)->getTitle());
        i++;
    }
    return titleArray;
}