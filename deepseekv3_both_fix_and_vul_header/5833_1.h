#include <stdint.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef const char *client_name_t;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef struct gs_malloc_block_s gs_malloc_block_t;
typedef struct gs_malloc_memory_s gs_malloc_memory_t;
typedef struct gs_memory_s gs_memory_t;
typedef struct gx_monitor_s gx_monitor_t;

struct gs_malloc_block_s {
    gs_malloc_block_t *next;
    gs_malloc_block_t *prev;
    uint size;
    const void *type;
    client_name_t cname;
};

struct gs_malloc_memory_s {
    gs_memory_t *stable_memory;
    gx_monitor_t *monitor;
    gs_malloc_block_t *allocated;
    ulong limit;
    ulong used;
    ulong max_used;
};

#define DO_NOTHING ((void)0)
#define gs_alloc_fill_alloc 0

extern void gx_monitor_enter(gx_monitor_t *);
extern void gx_monitor_leave(gx_monitor_t *);
extern void *Memento_label(void *, client_name_t);
extern void gs_alloc_fill(void *, int, uint);
extern const void *st_bytes;