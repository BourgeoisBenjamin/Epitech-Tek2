/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH2_2019_GIFTPAPER_HPP
#define CPP_RUSH2_2019_GIFTPAPER_HPP

#include "Wrap.hpp"
#include "Box.hpp"

class GiftPaper : virtual public Wrap {
    public :
        GiftPaper();
        ~GiftPaper();
    protected:
        Box *_box;
};

#endif //CPP_RUSH2_2019_GIFTPAPER_HPP
