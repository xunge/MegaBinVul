#include <stddef.h>

typedef int gboolean;
typedef void* gpointer;

#define G_SOURCE_REMOVE 0
#define TRUE 1
#define g_clear_pointer(ptr, func) if (*(ptr)) { func(*(ptr)); *(ptr) = NULL; }

typedef struct {
    void* data;
    void* timeout_source;
} ConnectionAttempt;

void enumerator_next_async(void* data, ...);
void g_source_unref(void* source);