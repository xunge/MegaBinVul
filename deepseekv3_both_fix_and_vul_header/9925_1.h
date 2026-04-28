#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>

#define PAGE_SIZE 4096
#define EINVAL 22
#define EBUSY 16

struct agp_memory {
    struct agp_bridge_data *bridge;
    unsigned long page_count;
    int type;
    bool is_flushed;
    struct page **pages;
};

struct agp_bridge_data {
    void *current_size;
    struct agp_driver *driver;
    void *gatt_table;
};

struct agp_driver {
    int size_type;
    int (*agp_type_to_mask_type)(struct agp_bridge_data *, int);
    void (*cache_flush)(void);
    unsigned long (*mask_memory)(struct agp_bridge_data *, unsigned long, int);
    void (*tlb_flush)(struct agp_memory *);
};

struct agp_aperture_size_8 {
    int num_entries;
};

struct agp_aperture_size_16 {
    int num_entries;
};

struct agp_aperture_size_32 {
    int num_entries;
};

struct agp_aperture_size_fixed {
    int num_entries;
};

#define A_SIZE_8(x) ((struct agp_aperture_size_8 *)x)
#define A_SIZE_16(x) ((struct agp_aperture_size_16 *)x)
#define A_SIZE_32(x) ((struct agp_aperture_size_32 *)x)
#define A_SIZE_FIX(x) ((struct agp_aperture_size_fixed *)x)

enum {
    U8_APER_SIZE,
    U16_APER_SIZE,
    U32_APER_SIZE,
    FIXED_APER_SIZE,
    LVL2_APER_SIZE
};

#define PGE_EMPTY(bridge, entry) ((entry) == 0)

extern unsigned long agp_memory_reserved;
extern unsigned long page_to_phys(struct page *page);
extern void writel(unsigned long val, void *addr);
extern unsigned long readl(void *addr);