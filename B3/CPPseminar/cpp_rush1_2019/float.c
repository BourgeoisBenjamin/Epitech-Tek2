/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** TODO: add description
*/

#include "new.h"
#include "float.h"

typedef struct
{
    Class   base;
    float    nbr;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->nbr = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static Object *Float_add(const Object *self, const Object *other)
{
    Object *newFloat = NULL;
    if (!self || !other)
        raise("Float must be initialised");
    newFloat = new(Float, ((FloatClass *)self)->nbr +
    ((FloatClass *)other)->nbr);
    return (newFloat);
}

static Object *Float_sub(const Object *self, const Object *other)
{
    Object *newFloat = NULL;
    if (!self || !other)
        raise("Float must be initialised");
    newFloat = new(Float, ((FloatClass *)self)->nbr -
    ((FloatClass *)other)->nbr);
    return (newFloat);
}

static Object *Float_mul(const Object *self, const Object *other)
{
    Object *newFloat = NULL;
    if (!self || !other)
        raise("Float must be initialised");
    newFloat = new(Float, ((FloatClass *)self)->nbr *
    ((FloatClass *)other)->nbr);
    return (newFloat);
}

static Object *Float_div(const Object *self, const Object *other)
{
    Object *newFloat = NULL;
    if (!self || !other || ((FloatClass *)other)->nbr == 0)
        raise("Float must be initialised");
    newFloat = new(Float, ((FloatClass *)self)->nbr /
    ((FloatClass *)other)->nbr);
    return (newFloat);
}

bool Float_eq(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Float must be initialised");
    if (((FloatClass *)self)->nbr == ((FloatClass *)other)->nbr) {
        return (true);
    }
    return (false);
}

bool Float_lt(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Float must be initialised");
    if (((FloatClass *)self)->nbr < ((FloatClass *)other)->nbr) {
        return (true);
    }
    return (false);
}

bool Float_gt(const Object *self, const Object *other)
{
    if (!self || !other)
        raise("Float must be initialised");
    if (((FloatClass *)self)->nbr > ((FloatClass *)other)->nbr) {
        return (true);
    }
    return (false);
}

static char *Float_to_str(Object *this)
{
    char *str = calloc(100, sizeof(float));
    if (!str) raise("Error with malloc\n");

    snprintf(str, 100, "<Float (%f)>", ((FloatClass *)this)->nbr);
    return (str);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = &Float_to_str,    /* Implement this method for exercice 02 */
        .__add__ = &Float_add,    /* Implement this method for exercice 03 */
        .__sub__ = &Float_sub,    /* Implement this method for exercice 03 */
        .__mul__ = &Float_mul,
        .__div__ = &Float_div,
        .__eq__ = &Float_eq,
        .__gt__ = &Float_gt,
        .__lt__ = &Float_lt
    },
    .nbr = 0
};

const Class   *Float = (const Class *)&_description;