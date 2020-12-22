#include <iostream>
#include <dlfcn.h>

void *loadLibrary(char *libraryPath)
{
    void *libPtr = NULL;
    libPtr = dlopen(libraryPath, RTLD_LAZY);
    if (!libPtr) {
        std::cerr << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }
    dlerror();
    return (libPtr);
}

void entryPointLibrary(void *libPtr)
{
    void (*ftPtr)();

    *(void **) (&ftPtr) = dlsym(libPtr, "entryPoint_ft");

    if (ftPtr == NULL)  {
        std::cerr << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }
    ftPtr();
    dlerror();
}

void unloadLibrary(void *libPtr)
{
    if (dlclose(libPtr)) {
        std::cerr << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }
    dlerror();
}

int main(int argc, char **argv)
{
    void *libPtr = NULL;
    for (size_t i = 1; i < argc; i++)
    {
        libPtr = loadLibrary(argv[i]);
        entryPointLibrary(libPtr);
        unloadLibrary(libPtr);
    }
    return 0;
}
