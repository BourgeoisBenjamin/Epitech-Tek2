/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/ITable.hpp"

void ITable::addToy(Toy *toy)
{
    _list.push_back(toy);
    std::cout << "One object is put on the table" << std::endl;
}