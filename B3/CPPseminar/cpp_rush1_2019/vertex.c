/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static Object *Vertex_add(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other)
        raise("Points must be initialised");
    newPoint = new(Vertex, ((VertexClass *)self)->x + ((VertexClass *)other)
    ->x, ((VertexClass *)self)->y + ((VertexClass *)other)->y, ((VertexClass*)self)->z + ((VertexClass *)other)->z);
    return (newPoint);
}

static Object *Vertex_sub(const Object *self, const Object *other)
{
    Object *newPoint = NULL;
    if (!self || !other)
        raise("Points must be initialised");
    newPoint = new(Vertex, ((VertexClass *)self)->x - ((VertexClass *)other)
    ->x, ((VertexClass *)self)->y - ((VertexClass *)other)->y, ((VertexClass*)self)->z - ((VertexClass *)other)->z);
    return (newPoint);
}

static char *Vertex_to_str(Object *this)
{
    char *str = calloc(100, sizeof(char));
    if (!str) raise("Error with malloc\n");

    snprintf(str, 100, "<Vertex (%i, %i, %i)>", ((VertexClass *)this)->x, (
        (VertexClass *)this)->y, ((VertexClass *)this)->z);
    return (str);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = &Vertex_to_str,    /* Implement this method for exercice 02 */
        .__add__ = &Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = &Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0,
};

const Class   *Vertex = (const Class *)&_description;
