/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"
 
typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static Object *Point_add(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other)
        raise("Points must be initialised");
    newPoint = new(Point, ((PointClass *)self)->x + ((PointClass *)other)->x, (
        (PointClass *)self)->y + ((PointClass *)other)->y);
    return (newPoint);
}

static Object *Point_sub(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other)
        raise("Points must be initialised");
    newPoint = new(Point, ((PointClass *)self)->x - ((PointClass *)other)->x, (
        (PointClass *)self)->y - ((PointClass *)other)->y);
    return (newPoint);
}

// Create additional functions here

static char *Point_to_str(Object *this)
{
    char *str = calloc(100, sizeof(char));
    if (!str) raise("Error with malloc\n");

    snprintf(str, 100, "<Point (%i, %i)>", ((PointClass *)this)->x, (
        (PointClass *)this)->y);
    return (str);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = &Point_to_str,    /* Implement this method for exercice 02 */
        .__add__ = &Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = &Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
