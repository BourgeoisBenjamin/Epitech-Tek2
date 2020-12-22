/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** TODO: add description
*/
#ifndef FUNC_PTR_H
#define FUNC_PTR_H

#include "func_ptr_enum.h"

typedef struct action_function_s
{
    action_t action;
    void (*function)(const char*);
} action_function_t;

#endif //FUNC_PTR_H
