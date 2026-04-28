#include <stddef.h>

typedef struct VTerm VTerm;
typedef struct VTermAllocatorFunctions VTermAllocatorFunctions;

struct VTermAllocatorFunctions {
    void *(*malloc)(size_t size, void *allocdata);
    void (*free)(void *ptr, void *allocdata);
};

enum ParserState {
    NORMAL
};

struct VTerm {
    VTermAllocatorFunctions *allocator;
    void *allocdata;
    int rows;
    int cols;
    struct {
        enum ParserState state;
        void *callbacks;
        void *cbdata;
        size_t strbuffer_len;
        size_t strbuffer_cur;
        char *strbuffer;
    } parser;
    size_t outbuffer_len;
    size_t outbuffer_cur;
    char *outbuffer;
};

void *vterm_allocator_malloc(VTerm *vt, size_t size);