#include <stddef.h>
#include <stdint.h>

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define EINVAL 22
#define EOPNOTSUPP 95
#define EPERM 1

#define GNTTAB_CACHE_INVAL (1<<0)
#define GNTTAB_CACHE_CLEAN (1<<1)
#define GNTTAB_CACHE_SOURCE_GREF (1<<2)

typedef struct domain {
    void *grant_table;
} domain;

typedef struct page_info {
    domain *owner;
} page_info;

typedef struct gnttab_cache_flush_t {
    union {
        uint64_t dev_bus_addr;
        struct {
            uint32_t domid;
            uint32_t ref;
        } gref;
    } a;
    uint16_t offset;
    uint16_t length;
    uint16_t op;
    uint16_t flags;
} gnttab_cache_flush_t;

typedef uint32_t grant_ref_t;

static inline unsigned long _mfn(unsigned long mfn) { return mfn; }