/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/malloc.h"
#include "../include/error.h"

/* GLOBAL VARIABLE : MAP OF THE MEMORY ALLOCATED */
memmap_t *memmapsession;

void *init_malloc_session(void)
{
    void *oldbreak = sbrk(0);
    if ((memmapsession = sbrk(2 * getpagesize())) == ((void *) - 1))
        return (what());
    memmapsession->memsession = NULL;
    memmapsession->endmemsession = NULL;
    memmapsession->memblocknb = 0;
    memmapsession->freeheap = 2 * getpagesize() - sizeof(memmap_t);
    memmapsession->freeheapptr = (void*)(oldbreak + sizeof(memmap_t));
    memmapsession->breakptr = sbrk(0);
    return (&memmapsession);
}