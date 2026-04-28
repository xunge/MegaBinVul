#include <stdlib.h>

typedef void (*TidyFree)(void* mem);
static TidyFree g_free = NULL;

typedef struct TidyAllocator TidyAllocator;
#define TIDY_CALL
#define ARG_UNUSED(x) x __attribute__((unused))