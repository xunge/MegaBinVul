#include <stdio.h>

#define BITSTR_MEM 1
#define BITSTR_FILE 2

long mbitstr_tell(void *stream);
long fbitstr_tell(void *stream);