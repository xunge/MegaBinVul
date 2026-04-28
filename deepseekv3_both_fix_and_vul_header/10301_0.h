#include <stdlib.h>
#include <string.h>

#define IPC_TIMEOUT ((char *) -1)

extern void *emalloc(size_t size);
extern void *erealloc(void *ptr, size_t size);

#define D(x) 