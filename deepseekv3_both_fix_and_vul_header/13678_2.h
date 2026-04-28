#include <stddef.h>
#include <stdint.h>

struct sg_table {
    struct scatterlist *sgl;
    unsigned int nents;
    unsigned int orig_nents;
};

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    long lock;
};

struct device {
    const char *name;
};

struct dma_buf {
    void *priv;
};

struct dma_buf_attachment {
    struct device *dev;
    void *priv;
};

struct fastrpc_dma_buf_attachment {
    struct device *dev;
    struct sg_table sgt;
    struct list_head node;
};

struct fastrpc_buf {
    struct device *dev;
    void *virt;
    uintptr_t phys;
    size_t size;
    struct mutex lock;
    struct list_head attachments;
};

#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2
#define FASTRPC_PHYS(phys) (phys)

void *kzalloc(size_t size, int flags);
int dma_get_sgtable(struct device *dev, struct sg_table *sgt, void *cpu_addr, uintptr_t dma_addr, size_t size);
void dev_err(struct device *dev, const char *fmt, ...);
void INIT_LIST_HEAD(struct list_head *list);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void list_add(struct list_head *new, struct list_head *head);