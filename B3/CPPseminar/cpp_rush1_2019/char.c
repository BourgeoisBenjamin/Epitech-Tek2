/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char    letter;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->letter = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static Object *Char_add(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other)
        raise("Char must be initialised");
    newPoint = new(Char, ((CharClass *)self)->letter + ((CharClass *)other)->letter);
    return (newPoint);
}

static Object *Char_sub(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other)
        raise("Char must be initialised");
    newPoint = new(Char, ((CharClass *)self)->letter - ((CharClass *)other)->letter);
    return (newPoint);
}

static Object *Char_div(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other || ((CharClass *)other)->letter == '\0')
        raise("Char must be initialised");
    newPoint = new(Char, ((CharClass *)self)->letter / ((CharClass *)other)->letter);
    return (newPoint);
}

static Object *Char_mul(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other)
        raise("Char must be initialised");
    newPoint = new(Char, ((CharClass *)self)->letter * ((CharClass *)other)->letter);
    return (newPoint);
}

static char *Char_to_str(Object *this)
{
    char *str = calloc(100, sizeof(char));
    if (!str)
        raise("Error with malloc\n");
    snprintf(str, 100, "<Char (%c)>", ((CharClass *)this)->letter);
    return (str);
}

bool Char_eq(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Char must be initialised");
    if (((CharClass *)self)->letter == ((CharClass *)other)->letter)
        return true;
    return false;
}

bool Char_lt(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Char must be initialised");
    if (((CharClass *)self)->letter < ((CharClass *)other)->letter)
        return true;
    return false;
}

bool Char_gt(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Char must be initialised");
    if (((CharClass *)self)->letter > ((CharClass *)other)->letter)
        return true;
    return false;
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = &Char_to_str,    /* Implement this method for exercice 02 */
        .__add__ = &Char_add,    /* Implement this method for exercice 03 */
        .__sub__ = &Char_sub,    /* Implement this method for exercice 03 */
        .__mul__ = &Char_mul,
        .__div__ = &Char_div,
        .__eq__ = &Char_eq,
        .__gt__ = &Char_gt,
        .__lt__ = &Char_lt
    },
    .letter = 0
};

const Class   *Char = (const Class *)&_description;