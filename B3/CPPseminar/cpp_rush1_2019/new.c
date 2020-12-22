/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** TODO: add description
*/

#include "new.h"
#include "player.h"

Object  *va_new(const Class *class, va_list *ap)
{
    Object *new = NULL;

    if ((new = malloc(class->__size__)) == NULL)
        raise("Error with constructor.");

    if ((memcpy(new, class, class->__size__)) == NULL)
        raise("Error with constructor.");
    if (class->__ctor__)
        class->__ctor__(new, ap);
    return (new);
}

Object *new(const Class *class, ...)
{
    Object *new = NULL;
    va_list ap;

    va_start(ap, class);
    new = va_new(class, &ap);
    va_end(ap);

    return (new);
}

void delete(Object *ptr)
{
    if (((Class*)ptr)->__dtor__)
        ((Class*)ptr)->__dtor__(ptr);
    free(ptr);
}