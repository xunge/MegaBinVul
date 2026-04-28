#include <stdlib.h>

typedef struct TidyAllocator TidyAllocator;
#define TIDY_CALL
static void* defaultAlloc(TidyAllocator* allocator, size_t size);
static void defaultPanic(TidyAllocator* allocator, const char* msg);
static void* (*g_realloc)(void*, size_t);