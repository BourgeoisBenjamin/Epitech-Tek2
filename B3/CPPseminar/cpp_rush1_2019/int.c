/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** Exercice 04
*/

#include <stdio.h>
#include <stdbool.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int nb;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->nb = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
    return;
}

static Object *Int_add(const Object *self, const Object *other)
{
    Object *newInt = NULL;
    if (!self || !other)
        raise("Int must be initialised");
    newInt = new(Int, ((IntClass *)self)->nb + ((IntClass *)other)->nb);
    return (newInt);
}

static Object *Int_sub(const Object *self, const Object *other)
{
    Object *newInt = NULL;
    if (!self || !other)
        raise("Int must be initialised");
    newInt = new(Int, ((IntClass *)self)->nb - ((IntClass *)other)->nb);
    return (newInt);
}

static Object *Int_mul(const Object *self, const Object *other)
{
    Object *newInt = NULL;
    if (!self || !other)
        raise("Int must be initialised");
    newInt = new(Int, ((IntClass *)self)->nb * ((IntClass *)other)->nb);
    return (newInt);
}

static Object *Int_div(const Object *self, const Object *other)
{
    Object *newInt = NULL;
    if (!self || !other)
        raise("Int must be initialised");
    if (((IntClass *)other)->nb == 0)
        raise("Division with 0");
    newInt = new(Int, ((IntClass *)self)->nb / ((IntClass *)other)->nb);
    return (newInt);
}

bool Int_eq(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Int must be initialised");
    if (((IntClass *)self)->nb == ((IntClass *)other)->nb)
        return (true);
    return (false);
}

bool Int_lt(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Int must be initialised");
    if (((IntClass *)self)->nb < ((IntClass *)other)->nb)
        return (true);
    return (false);
}

bool Int_gt(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Int must be initialised");
    if (((IntClass *)self)->nb > ((IntClass *)other)->nb)
        return (true);
    return (false);
}

// Create additional functions here

static char *Int_to_str(Object *this)
{
    char *str = calloc(100, sizeof(char));
    if (!str) raise("Error with malloc\n");

    snprintf(str, 100, "<Int (%d)>", ((IntClass *)this)->nb);
    return (str);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = &Int_to_str,    /* Implement this method for exercice 02 */
        .__add__ = &Int_add,    /* Implement this method for exercice 03 */
        .__sub__ = &Int_sub,    /* Implement this method for exercice 03 */
        .__mul__ = &Int_mul,
        .__div__ = &Int_div,
        .__eq__ = &Int_eq,
        .__gt__ = &Int_gt,
        .__lt__ = &Int_lt
    },
    .nb = 0
};

const Class   *Int = (const Class *)&_description;