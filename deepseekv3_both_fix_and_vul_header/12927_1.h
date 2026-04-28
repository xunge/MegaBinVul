#include <stdint.h>
#include <stddef.h>

typedef uint32_t grant_ref_t;

typedef struct gnttab_cache_flush {
    uint64_t dev_bus_addr;
    uint64_t offset;
    grant_ref_t ref;
    uint16_t length;
    uint16_t op;
} gnttab_cache_flush_t;

#define XEN_GUEST_HANDLE_PARAM(type) void*
#define unlikely(x) (x)
#define __copy_from_guest(dst, src, size) 0
#define EFAULT 14
#define guest_handle_add_offset(hnd, off) ((void)0)

static int hypercall_preempt_check(void) { return 0; }
static int cache_flush(gnttab_cache_flush_t *op, grant_ref_t *ref) { return 0; }