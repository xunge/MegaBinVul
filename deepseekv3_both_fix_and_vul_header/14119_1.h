#include <stddef.h>
#include <errno.h>

#define PAGE_SHIFT 12
#define EINVAL 22
#define EAGAIN 11

struct file {
    void *private_data;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    unsigned long vm_page_prot;
};

typedef unsigned long pgprot_t;

struct aspeed_lpc_ctrl {
    unsigned long mem_base;
    unsigned long mem_size;
};

static inline struct aspeed_lpc_ctrl *file_aspeed_lpc_ctrl(struct file *file)
{
    return file->private_data;
}

static pgprot_t pgprot_noncached(pgprot_t prot)
{
    return prot;
}

static int remap_pfn_range(struct vm_area_struct *vma, unsigned long start,
                          unsigned long pfn, unsigned long size, pgprot_t prot)
{
    return 0;
}