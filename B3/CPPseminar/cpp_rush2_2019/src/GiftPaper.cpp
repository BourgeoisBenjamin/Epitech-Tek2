/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** TODO: add description
*/

#include "../include/GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap()
{
    _type = GIFTPAPER;
    std::cout << "Here a new GiftPaper" << std::endl;
}

GiftPaper::~GiftPaper()
{
    std::cout << "The GiftPaper is torn" << std::endl;
}