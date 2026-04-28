#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

typedef uint32_t u32;

struct page;
struct agp_bridge_data;
struct agp_memory;

#define AGP_USER_TYPES 1
#define ENTRIES_PER_PAGE 1024

struct agp_memory {
    struct agp_bridge_data *bridge;
    struct page **pages;
    size_t page_count;
};

struct agp_bridge_data {
    _Atomic int current_memory_agp;
    size_t max_memory_agp;
    struct {
        struct agp_memory *(*alloc_by_type)(size_t, u32);
        int (*agp_alloc_pages)(struct agp_bridge_data *, struct agp_memory *, size_t);
        struct page *(*agp_alloc_page)(struct agp_bridge_data *);
    } *driver;
};

extern struct agp_memory *agp_generic_alloc_user(size_t, u32);
extern struct agp_memory *agp_create_memory(int);
extern void agp_free_memory(struct agp_memory *);