/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#ifndef PSU_2019_MALLOC_MALLOC_H
#define PSU_2019_MALLOC_MALLOC_H

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

/* ALIGN METADATA */
#define ALIGN(x) ((x - 1) / 2 * 2 + 2)

/* METADATA FOR EACH BLOCK OF MEMORY */
typedef struct memblock_s
{
    struct memblock_s *next;
    size_t size;
    bool freed;
    void *address;
} memblock_t;

typedef struct memmap_s
{
    memblock_t *memsession;
    memblock_t *endmemsession;
    size_t memblocknb;
    size_t freeheap;
    void *freeheapptr;
    void *breakptr;
} memmap_t;

/* METADATA FOR MY MALLOC */
extern memmap_t *memmapsession;

/* FUNCTION */
void *init_malloc_session(void);
void* prepare_this_chunk(memblock_t *chunk, size_t size);
memblock_t *is_junk_free(size_t size);
memblock_t *create_chunk(size_t size);
memmap_t *extend_heap(size_t size);
void *malloc(size_t size);
memblock_t *get_mem_block(void *address);

#endif //PSU_2019_MALLOC_MALLOC_H
