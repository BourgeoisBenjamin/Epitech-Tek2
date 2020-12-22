/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void display_adresses();

int main(void)
{
    int toto = 3;
    display_adresses(toto);
    return toto;
}

void display_adresses(int a)
{
    void *handle;
    void (*test)(char*);
    char *error;
    const char* str = "Bonjour";

    handle = dlopen("libmy.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();    /* Clear any existing error */

    *(void **) (&test) = dlsym(handle, "my_putstr");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    dlclose(handle);



    printf("%p\n", &main);
    printf("%p\n", &test);
    printf("%p\n", &printf);
    printf("%p\n", &a);
    printf("%p\n", &str);
}