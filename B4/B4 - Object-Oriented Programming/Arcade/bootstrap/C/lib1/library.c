#include "library.h"

#include <stdio.h>

void constructor_ft(void) {
    printf("[libfoo] Loading foo library...\n");
}

void destructor_ft(void) {
    printf("[libfoo] Closing foo library...\n");
}

void entryPoint_ft(void) {
    printf("[libfoo] Entry Point for foo library...\n");
}
