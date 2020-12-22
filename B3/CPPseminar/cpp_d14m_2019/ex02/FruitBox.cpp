/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** TODO: add description
*/

#include "FruitBox.hpp"
#include <iostream>

FruitBox::FruitBox(int size) : _size(size), _fruitNb(0), _head(nullptr)
{
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return _fruitNb;
}

FruitNode* FruitBox::head() const
{
    return _head;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *temp = _head;

    if (_fruitNb == _size || !f || _size < 1)
        return false;
    if (_head == nullptr) {
        _head = new FruitNode();
        _head->next = nullptr;
        _head->fruit = f;
        _fruitNb++;
        return true;
    }
    while (temp->next) {
        if (temp->fruit == f)
            return false;
        temp = temp->next;
    }
    if (temp->fruit == f)
        return false;
    temp->next = new FruitNode();
    temp->next->next = nullptr;
    temp->next->fruit = f;
    _fruitNb++;
    return true;
}

Fruit* FruitBox::pickFruit()
{
    Fruit *pickFruit = nullptr;
    FruitNode *temp = nullptr;
    if (_head == nullptr)
        return nullptr;
    pickFruit = _head->fruit;
    temp = _head->next;
    delete _head;
    _head = temp;
    _fruitNb--;
    return pickFruit;
}