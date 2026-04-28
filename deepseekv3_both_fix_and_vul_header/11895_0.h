#include <stddef.h>

#define PAGE_SHIFT 12
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

struct platform_bad_page {
    unsigned long mfn;
};

#define __init
#define __initconst
#define __initdata

typedef unsigned int u32;

#define IS_SNB_GFX(id) (0)

static inline u32 pci_conf_read32(int a, int b, int c, int d, int e) {
    return 0;
}