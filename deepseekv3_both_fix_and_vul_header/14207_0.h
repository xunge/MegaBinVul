#include <stddef.h>

#define ZYAN_ASSERT(expr) ((void)0)
#define ZYAN_FALSE 0
#define ZYAN_STRING_HAS_FIXED_CAPACITY 0
#define ZYAN_NULL NULL

typedef size_t ZyanUSize;

typedef struct ZyanVector {
    void* allocator;
    float growth_factor;
    float shrink_threshold;
    void (*destructor)(void*);
    size_t element_size;
    ZyanUSize size;
    ZyanUSize capacity;
    void* data;
} ZyanVector;

typedef struct ZyanString {
    unsigned int flags;
    ZyanVector vector;
} ZyanString;

typedef struct ZydisFormatterBuffer {
    int is_token_list;
    ZyanUSize capacity;
    ZyanString string;
} ZydisFormatterBuffer;