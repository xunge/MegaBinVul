#include <stdlib.h>

typedef struct VTerm VTerm;

typedef struct VTermScreen {
    VTerm *vt;
    void **buffers;
    void *sb_buffer;
} VTermScreen;

typedef struct VTermAllocator {
    void *(*malloc)(size_t size);
    void (*free)(void *ptr);
} VTermAllocator;

#define INTERNAL static

void vterm_allocator_free(VTerm *vt, void *ptr);