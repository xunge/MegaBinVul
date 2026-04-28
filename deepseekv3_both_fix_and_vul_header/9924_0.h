#include <sys/types.h>
#include <stddef.h>
#include <errno.h>

struct agp_memory {
    struct agp_bridge_data *bridge;
    size_t page_count;
    int type;
};

struct agp_bridge_data {
    struct agp_bridge_driver *driver;
    unsigned long scratch_page;
    void *gatt_table;
};

struct agp_bridge_driver {
    int (*agp_type_to_mask_type)(struct agp_bridge_data *, int);
    void (*tlb_flush)(struct agp_memory *);
};