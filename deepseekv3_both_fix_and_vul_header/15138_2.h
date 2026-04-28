#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

struct device_node {
    // dummy definition
};

struct resource {
    const char *name;
    unsigned long start;
    unsigned long end;
    unsigned long flags;
};

struct pci_pbm_info {
    struct {
        struct device_node *node;
    } *op;
    struct resource mem_space;
};

#define GFP_KERNEL 0
#define IORESOURCE_BUSY 0x80000000

const u32 *of_get_property(const struct device_node *node, const char *name, int *lenp);
int request_resource(struct resource *root, struct resource *new);
void prom_printf(const char *fmt, ...);
void prom_halt(void);
void *kmalloc(size_t size, int flags);