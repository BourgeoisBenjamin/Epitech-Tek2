#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

void *loadLibrary(char *libraryPath)
{
    void *libPtr = NULL;
    libPtr = dlopen(libraryPath, RTLD_LAZY);
    if (!libPtr) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();
    return (libPtr);
}

void entryPointLibrary(void *libPtr)
{
    void (*ftPtr)(void);
    char *error = NULL;

    *(void **) (&ftPtr) = dlsym(libPtr, "entryPoint_ft");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    ftPtr();
    dlerror();
}

void unloadLibrary(void *libPtr)
{
    if (dlclose(libPtr)) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();
}

int main(int argc, char **argv)
{
    void *libPtr = NULL;
    for (int i = 1; i < argc; i++) {
        libPtr = loadLibrary(argv[i]);
        entryPointLibrary(libPtr);
        unloadLibrary(libPtr);
    }
    return 0;
}
