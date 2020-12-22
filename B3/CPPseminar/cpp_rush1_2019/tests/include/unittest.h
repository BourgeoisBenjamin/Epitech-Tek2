/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** header UNIT TEST
*/

#ifndef UNITTEST_H
#define UNITTEST_H

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>
#include <criterion/assert.h>

#include "new.h"
#include "player.h"
#include "point.h"
#include "vertex.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

typedef struct
{
    Class   base;
    char    letter;
}   CharClass;

typedef struct
{
    Class base;
    int nb;
}   IntClass;

typedef struct
{
    Class   base;
    float    nbr;
}   FloatClass;

void redirect_all_std(void);

#endif
