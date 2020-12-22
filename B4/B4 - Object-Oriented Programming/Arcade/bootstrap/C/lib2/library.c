#include "library.h"

#include <stdio.h>

void constructor_ft(void) {
    printf("[libbar] Loading bar library...\n");
}

void destructor_ft(void) {
    printf("[libbar] Closing bar library...\n");
}

void entryPoint_ft(void) {
    printf("[libbar] Entry Point for bar library...\n");
}
