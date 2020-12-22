/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** TODO: add description
*/

#include "ex00.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void cthulhu_initializer(cthulhu_t *this)
{
    if (this->m_name)
        free(this->m_name);
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("----\nBuilding %s\n", this->m_name);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));
    if (!new)
        return (NULL);
    cthulhu_initializer(new);
    return (new);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    cthulhu_initializer(&this->m_parent);
    this->m_is_a_legend = _is_A_Legend;
    if (this->m_parent.m_name)
        free(this->m_parent.m_name);
    this->m_parent.m_name = strdup(_name);
    if (!_is_A_Legend)
        this->m_parent.m_power = 0;
    printf("Building %s\n", this->m_parent.m_name);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %i\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));
    if (!new)
        return (NULL);
    koala_initializer(new, name, is_a_legend);
    return (new);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42000;
    printf("%s eats\n", this->m_parent.m_name);
}