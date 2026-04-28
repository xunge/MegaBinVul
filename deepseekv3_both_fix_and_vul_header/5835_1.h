#include <stdlib.h>

#define TIDY_CALL

static void* (*g_malloc)(size_t) = NULL;
typedef struct TidyAllocator TidyAllocator;
static void defaultPanic(TidyAllocator* allocator, const char* message);