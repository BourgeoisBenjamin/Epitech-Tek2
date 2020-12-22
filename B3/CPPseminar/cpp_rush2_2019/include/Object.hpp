/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_OBJECT_HPP
#define CPP_RUSH2_2019_OBJECT_HPP

#include <string>
#include <ostream>
#include <iostream>

enum ObjectType
{
    TOY,
    BOX,
    WRAP,
    GIFTPAPER,
    UNDEFINED
};

class Object
{
    public:
        virtual ~Object();
        virtual void isTaken() = 0;
        bool getIsTaken() const;
        void setIsTaken(bool);
        virtual Object *openMe();
        enum ObjectType getType() const;
        virtual Object *wrapMeThat(Object *object);
    protected:
        enum ObjectType _type;
        bool _isTaken;
};

#endif //CPP_RUSH2_2019_OBJECT_HPP
