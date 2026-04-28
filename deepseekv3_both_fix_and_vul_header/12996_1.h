#include <stdlib.h>
#include <stddef.h>

struct device_node;
struct tegra_xusb_padctl {
    struct {
        struct device_node *of_node;
    } *dev;
};

#define GFP_KERNEL 0
#define ENOMEM 12
#define ERR_PTR(ptr) ((void*)(ptr))