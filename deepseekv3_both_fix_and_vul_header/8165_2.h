#include <stddef.h>
#include <stdbool.h>

typedef unsigned long dma_addr_t;
typedef unsigned int gfp_t;
typedef unsigned long pgprot_t;
struct device {};
struct dma_attrs {};

#define PAGE_KERNEL 0
#define pgprot_kernel 0

void *__dma_alloc(struct device *dev, size_t size, dma_addr_t *handle, gfp_t gfp, pgprot_t prot, bool coherent, void *caller);
pgprot_t __get_dma_pgprot(struct dma_attrs *attrs, pgprot_t prot);
bool dma_alloc_from_coherent(struct device *dev, size_t size, dma_addr_t *dma_handle, void **ret);