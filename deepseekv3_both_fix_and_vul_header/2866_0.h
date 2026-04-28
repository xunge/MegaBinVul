#include <stdint.h>
#include <stdlib.h>

typedef char *sds;

sds sdsnewlen(const void *init, size_t initlen);