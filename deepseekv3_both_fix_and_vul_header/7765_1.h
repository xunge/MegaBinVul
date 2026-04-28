#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

typedef uint64_t ut64;
#define UT64_MAX UINT64_MAX

typedef struct RVTableContext {
    void *anal;
    bool (*read_addr)(void *anal, ut64 addr, ut64 *value);
} RVTableContext;

bool vtable_addr_in_text_section(RVTableContext *context, ut64 addr);