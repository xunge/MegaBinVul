#include <assert.h>
#include <stdlib.h>

struct jv_parser {
    char* tokenbuf;
    int tokenpos;
    int tokenlen;
};

void* jv_mem_realloc(void*, size_t);