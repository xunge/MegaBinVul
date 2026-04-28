#include <stddef.h>
#include <stdint.h>

#define GFP_ATOMIC (1 << 0)
#define __GFP_COMP (1 << 1)
#define __GFP_NOWARN (1 << 2)
#define GFP_DMA (1 << 3)
#define __GFP_ZERO (1 << 4)
#define PAGE_SHIFT 12
#define PAGE_SIZE (1 << PAGE_SHIFT)
#define SG_SECTOR_SZ 512
#define KERN_INFO 0
#define EFAULT 1
#define ENOMEM 2
#define CAP_SYS_ADMIN 1
#define CAP_SYS_RAWIO 2

typedef unsigned int gfp_t;

struct page {
    // Minimal page structure definition
};

struct Scsi_Host {
    int unchecked_isa_dma;
};

struct scsi_device {
    struct Scsi_Host *host;
};

struct sg_device {
    int sg_tablesize;
    struct scsi_device *device;
    struct sg_device *parentdp;
};

typedef struct Sg_scatter_hold {
    struct page **pages;
    int page_order;
    int k_use_sg;
    int bufflen;
} Sg_scatter_hold;

typedef struct Sg_fd {
    struct sg_device *parentdp;
} Sg_fd;

extern int scatter_elem_sz;
extern int scatter_elem_sz_prev;
extern int sg_build_sgat(Sg_scatter_hold *schp, Sg_fd *sfp, int sg_tablesize);
extern int SCSI_LOG_TIMEOUT(int level, int printk_result);
extern int sg_printk(int level, struct sg_device *sdp, const char *fmt, ...);
extern int capable(int cap);
extern void __free_pages(struct page *page, unsigned int order);
extern struct page *alloc_pages(gfp_t gfp_mask, unsigned int order);
extern unsigned int get_order(unsigned long size);

#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
#define unlikely(x) (x)