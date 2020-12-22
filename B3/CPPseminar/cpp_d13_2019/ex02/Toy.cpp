/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy")
{

}

Toy::Toy(enum ToyType type, const std::string name, const std::string
    filename) :
    _type(type), _name(name), _picture(Picture(filename))
{
}

Toy::~Toy()
{
}

std::string Toy::getName() const
{
    return _name;
}

std::string Toy::getAscii() const
{
    return _picture.data;
}

enum Toy::ToyType Toy::getType() const
{
    return _type;
}

bool Toy::setAscii(const std::string &filename)
{
    return _picture.getPictureFromFile(filename);
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

Picture Toy::getPicture() const
{
    return _picture;
}

/* CANONICAL FORM */

Toy::Toy(Toy const &old) : _type(old.getType()), _name(old.getName()),
_picture(old.getPicture())
{
}

Toy& Toy::operator=(Toy const &toy)
{
    _type = toy.getType();
    _name = toy.getName();
    _picture = toy.getPicture();
    return *this;
}

