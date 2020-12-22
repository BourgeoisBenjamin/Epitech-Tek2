/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** TODO: add description
*/

#include "Toy.hpp"
#include <ostream>

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
    if (_picture.getPictureFromFile(filename))
        return true;
    this->_error.type = Toy::Error::PICTURE;
    return false;
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

/* SPEAK */

bool Toy::speak(const std::string &statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
    return true;
}

/* OVERLOAD */

std::ostream & operator<<(std::ostream &os, Toy const &toy)
{
    return os << toy.getName() << std::endl << toy.getAscii() << std::endl;
}

Toy& Toy::operator<<(const std::string &data)
{
    _picture.data = data;
    return *this;
}

/* SPEAK_ES */
bool Toy::speak_es(const std::string &statement)
{
    (void)statement;
    this->_error.type = Toy::Error::SPEAK;
    return false;
}

/* ERROR HANDLING */
Toy::Error::Error() : type(UNKNOWN)
{
}

Toy::Error::~Error()
{
}

std::string Toy::Error::what() const
{
    if (type == PICTURE)
        return std::string("bad new illustration");
    if (type == SPEAK)
        return std::string("wrong mode");
    return std::string("");
}

std::string Toy::Error::where() const
{
    if (type == PICTURE)
        return std::string("setAscii");
    if (type == SPEAK)
        return std::string("speak_es");
    return std::string("");
}

Toy::Error const& Toy::getLastError()
{
    return _error;
}