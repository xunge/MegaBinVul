#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct connection_s {
    char *memory;
    size_t size;
    bool memory_overflow;
} connection_t;

#define ogs_assert(expr) do { if (!(expr)) abort(); } while (0)
#define ogs_assert_if_reached() abort()
#define ogs_error(fmt, ...) 
#define ogs_fatal(fmt, ...) 
#define ogs_log_hexdump(level, data, size) 

static void *ogs_realloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}