/*
** EPITECH PROJECT, 2019
** UNIT TEST
** File description:
** header UNIT TEST
*/

#ifndef UNITTEST_H
#define UNITTEST_H

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>

void redirect_all_std(void);
void add_mul_4param(int first, int second, int *sum, int *product);
void add_mul_2param(int *first, int *second);

#endif
