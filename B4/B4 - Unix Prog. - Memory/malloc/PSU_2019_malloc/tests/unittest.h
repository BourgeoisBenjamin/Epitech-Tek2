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
#include "../include/malloc.h"
#include "../include/calloc.h"
#include "../include/realloc.h"
#include "../include/reallocarray.h"
#include "../include/free.h"

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void redirect_all_std(void);

#endif
