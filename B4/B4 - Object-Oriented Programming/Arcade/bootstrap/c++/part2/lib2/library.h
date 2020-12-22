#ifndef LIB2_LIBRARY_H
#define LIB2_LIBRARY_H

extern "C" void __attribute__((constructor)) constructor_ft();
extern "C" void __attribute__((destructor)) destructor_ft();
extern "C" void entryPoint_ft();

#endif //LIB2_LIBRARY_H
