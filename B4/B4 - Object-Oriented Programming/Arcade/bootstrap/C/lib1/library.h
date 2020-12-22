#ifndef LIB1_LIBRARY_H
#define LIB1_LIBRARY_H

void __attribute__((constructor)) constructor_ft(void);
void __attribute__((destructor)) destructor_ft(void);
void entryPoint_ft(void);

#endif //LIB1_LIBRARY_H
