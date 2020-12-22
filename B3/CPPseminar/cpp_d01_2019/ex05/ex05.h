/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** TODO: add description
*/

#ifndef EX05_H
#define EX05_H

#include <stdint.h>

union bar {
    uint16_t bar;
    uint16_t foo;
};

struct foo
{
    uint16_t foo;
    union bar bar;
};

typedef union foo_s
{
    struct foo foo;
    uint32_t bar;
} foo_t;

#endif //EX05_H
