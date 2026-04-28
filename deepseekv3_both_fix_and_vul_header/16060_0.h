#include <stddef.h>

struct range {
    unsigned long first;
    unsigned long last;
};

struct arch_msix {
    int used_entries;
    struct range table;
    struct range pba;
};

extern struct rangeset *mmio_ro_ranges;

void WARN(void);
int rangeset_remove_range(struct rangeset *r, unsigned long s, unsigned long e);