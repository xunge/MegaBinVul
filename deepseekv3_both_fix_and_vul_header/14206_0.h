#include <stddef.h>

typedef unsigned char ZyanU8;
typedef size_t ZyanUSize;

#define ZYAN_ASSERT(expr) ((void)0)
#define ZYAN_TRUE 1
#define ZYAN_STRING_HAS_FIXED_CAPACITY 0
#define ZYAN_NULL NULL
#define ZYDIS_TOKEN_INVALID 0

typedef struct ZydisFormatterToken {
    int type;
    struct ZydisFormatterToken* next;
} ZydisFormatterToken;

typedef struct {
    void* allocator;
    float growth_factor;
    unsigned shrink_threshold;
    void (*destructor)(void*);
    size_t element_size;
    size_t size;
    size_t capacity;
    void* data;
} ZyanVector;

typedef struct {
    unsigned flags;
    ZyanVector vector;
} ZyanString;

typedef struct {
    int is_token_list;
    ZyanUSize capacity;
    ZyanString string;
} ZydisFormatterBuffer;