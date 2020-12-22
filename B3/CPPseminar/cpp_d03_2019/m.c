#include "string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string_t s;
    char *result = strdup("xxxxxx");
    int ret;

    string_init(&s, "Hello World");
    ret = s.copy(&s, result, 2, 3);
    printf("is:\t'%s':[%d]\nshould:\t'%s':[%d]\n", result, ret, "loxxxx", 2);
    free(result);

    result = strdup("xxxxxx");
    ret = s.copy(&s, result, 3, 9);
    printf("is:\t'%s':[%d]\nshould:\t'%s':[%d]\n", result, ret, "ld", 3);
    free(result);

    result = strdup("xxxxxx");
    ret = s.copy(&s, result, 4, 9);
    printf("is:\t'%s':[%d]\nshould:\t'%s':[%d]\n", result, ret, "ld", 3);
    free(result);
    string_destroy(&s);
    return (0);
}
