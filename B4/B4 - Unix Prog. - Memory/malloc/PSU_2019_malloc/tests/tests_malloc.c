/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** TODO: add description
*/

#include "unittest.h"

Test(Malloc, size_zero, .init=redirect_all_std)
{
    void *handle = NULL;
    void *(*malloc)(size_t);
    char *error = NULL;
    char *memory = NULL;

    handle = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    *(void **) (&malloc) = dlsym(handle, "malloc");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    memory = (*malloc)(0);
    cr_assume_null(memory);
    dlclose(handle);
}

Test(Malloc, test01, .init=redirect_all_std)
{
    void *handle = NULL;
    void *(*malloc)(size_t);
    char *error = NULL;
    char *memory = NULL;

    handle = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    *(void **) (&malloc) = dlsym(handle, "malloc");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    memory = (*malloc)(10);
    cr_assume_not_null(memory);
    dlclose(handle);
}