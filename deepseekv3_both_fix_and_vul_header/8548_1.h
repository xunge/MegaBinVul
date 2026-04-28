#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef uint64_t dma_addr_t;
typedef unsigned int gfp_t;

#define GFP_DMA 0x01
#define __GFP_WAIT 0x10
#define __GFP_ZERO 0x20

#define PAGE_SHIFT 12
#define PAGE_ALIGN(size) (((size) + (1 << PAGE_SHIFT) - 1) & ~((1 << PAGE_SHIFT) - 1))

#define IS_ENABLED(x) 0
#define CONFIG_ZONE_DMA 0
#define CONFIG_DMA_CMA 0
#define DMA_BIT_MASK(n) ((1ULL << (n)) - 1)

#define WARN_ONCE(cond, msg) do { if (cond) {} } while (0)

struct device {
    unsigned long coherent_dma_mask;
};

struct dma_attrs {};

struct page {};

static inline int get_order(size_t size) { return 0; }
static inline struct page *dma_alloc_from_contiguous(struct device *dev, int count, int order) { return NULL; }
static inline dma_addr_t phys_to_dma(struct device *dev, unsigned long phys) { return 0; }
static inline unsigned long page_to_phys(struct page *page) { return 0; }
static inline void *page_address(struct page *page) { return NULL; }
static inline void *swiotlb_alloc_coherent(struct device *dev, size_t size, dma_addr_t *dma_handle, gfp_t flags) { return NULL; }