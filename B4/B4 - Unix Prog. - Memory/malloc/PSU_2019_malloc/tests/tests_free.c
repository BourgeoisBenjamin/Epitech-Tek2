/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "unittest.h"

Test(Free, free_ptr_null, .init=redirect_all_std)
{
    void *handle = NULL;
    void *(*malloc)(size_t);
    void (*free)(void*);
    char *error = NULL;
    char *memory = NULL;

    handle = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    *(void **)(&malloc) = dlsym(handle, "malloc");
    *(void **)(&free) = dlsym(handle, "free");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    memory = (*malloc)(0);
    (*free)(memory);
    cr_assume_null(memory);
    dlclose(handle);
}

Test(Free, free_ptr, .init=redirect_all_std)
{
    void *handle = NULL;
    void *(*malloc)(size_t);
    void (*free)(void*);
    char *error = NULL;
    char *memory = NULL;
    void *memMap = NULL;

    handle = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    *(void **)(&malloc) = dlsym(handle, "malloc");
    *(void **)(&free) = dlsym(handle, "free");
    memMap = dlsym(handle, "memmapsession");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    memory = (*malloc)(100);
    (*free)(memory);
    cr_assert_eq(((memmap_t*)memMap)->memsession->next->freed, true);
    cr_assume_not_null(memory);
    dlclose(handle);
}