#include <iostream>
#include <dlfcn.h>
#include "../lib1/library.h"

typedef lib1 *(*maker_lib1)();

int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;
    void *hndl;
    maker_lib1 pMaker;

    // Ouverture de la librairie
    hndl = dlopen(argv[1], RTLD_LAZY);
    if(hndl == NULL)
    {
        std::cerr << "dlopen : "<< dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Chargement du créateur
    void *mkr = dlsym(hndl, "make_lib1");
    if (mkr == NULL)
    {
        std::cerr << "dlsym : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }
    pMaker = (maker_lib1)mkr;


    // Création, affichagedu cercle
    lib1 *my_lib1 = pMaker();
    my_lib1->init();
    my_lib1->stop();
    dlclose(hndl);

    return EXIT_SUCCESS;
}
