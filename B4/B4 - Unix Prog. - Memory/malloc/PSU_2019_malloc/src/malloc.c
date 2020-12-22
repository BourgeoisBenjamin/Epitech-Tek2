/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "../include/malloc.h"
#include "../include/error.h"

void* prepare_this_chunk(memblock_t *chunk, size_t size)
{
    chunk->size = size;
    chunk->freed = false;
    return (chunk->address);
}

memblock_t *is_junk_free(size_t size)
{
    memblock_t *tmp = memmapsession->memsession;
    memblock_t *find = NULL;
    size_t min_size = 0;
    while (tmp != NULL) {
        if (tmp->freed && tmp->size >= size && min_size == 0) {
            min_size = tmp->size;
            find = tmp;
        }
        if (tmp->freed && tmp->size >= size && tmp->size < min_size)
            find = tmp;
        tmp = tmp->next;
    }
    return (find);
}

memblock_t *create_chunk(size_t size)
{
    memblock_t *tmp = memmapsession->memsession;
    memblock_t *ret = NULL;
    if (!memmapsession->memsession) {
        memmapsession->memsession = memmapsession->freeheapptr;
        memmapsession->memsession->next = NULL;
        memmapsession->memsession->address = (void*)
            (memmapsession->freeheapptr + sizeof(memblock_t));
        ret = memmapsession->memsession;
    } else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = memmapsession->freeheapptr;
        tmp->next->next = NULL;
        tmp->next->address = memmapsession->freeheapptr + sizeof(memblock_t);
        ret = tmp->next;
    }
    memmapsession->memblocknb += 1;
    memmapsession->freeheapptr += sizeof(memblock_t) + size;
    memmapsession->freeheap -= sizeof(memblock_t) + size;
    return (ret);
}

memmap_t *extend_heap(size_t size)
{
    while (size + sizeof(memmap_t) >= memmapsession->freeheap) {
        if ((memmapsession->breakptr = sbrk(2 * getpagesize())) == ((void *)
        - 1))
            return (what());
        memmapsession->freeheap += 2 * getpagesize();
    }
    return (memmapsession);
}

void *malloc(size_t size)
{
    memblock_t *chunk = NULL;
    if (!memmapsession) {
        if (init_malloc_session() == NULL)
            return (NULL);
    }
    if (!size)
        return (NULL);
    size = ALIGN(size);
    if ((chunk = is_junk_free(size)) != NULL)
        return (prepare_this_chunk(chunk, size));
    if (size + sizeof(memblock_t) >= memmapsession->freeheap) {
        if (extend_heap(size) == NULL)
            return (NULL);
    }
    if ((chunk = create_chunk(size)) != NULL)
        return (prepare_this_chunk(chunk, size));
    return (NULL);
}