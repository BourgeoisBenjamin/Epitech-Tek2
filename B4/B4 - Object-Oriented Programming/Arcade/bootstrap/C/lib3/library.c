#include "library.h"

#include <stdio.h>

void constructor_ft(void) {
    printf("[libgra] Loading gra library...\n");
}

void destructor_ft(void) {
    printf("[libgra] Closing gra library...\n");
}

void entryPoint_ft(void) {
    printf("[libgra] Entry Point for gra library...\n");
}

