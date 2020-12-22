/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_WRAP_HPP
#define CPP_RUSH2_2019_WRAP_HPP

#include "Object.hpp"

class Wrap : public Object
{
    public :
        Wrap();
        ~Wrap();
        virtual Object *openMe() override;
        bool getOpen() const;
        void setOpen(bool);
        Object *wrapMeThat(Object *object) override;
        void isTaken() override;
    protected:
        Object *_object;
        bool _open;
};

#endif //CPP_RUSH2_2019_WRAP_HPP
