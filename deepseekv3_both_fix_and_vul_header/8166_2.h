#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t dma_addr_t;
typedef unsigned int gfp_t;
typedef struct device device;
typedef struct dma_attrs dma_attrs;
typedef unsigned long pgprot_t;

#define PAGE_KERNEL 0
#define __get_dma_pgprot(attrs, flags) (0)
#define dma_alloc_from_coherent(dev, size, handle, memory) (0)
#define __dma_alloc(dev, size, handle, gfp, prot, flag, ret) (NULL)