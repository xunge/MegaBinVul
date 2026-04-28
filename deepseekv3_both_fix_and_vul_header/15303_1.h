#include <stddef.h>

struct file {
    int f_flags;
    void *f_lock;
};

struct fasync_struct {
    int magic;
    struct file *fa_file;
    int fa_fd;
    struct fasync_struct *fa_next;
};

#define FASYNC_MAGIC 0x4601
#define GFP_KERNEL 0
#define ENOMEM 12
#define FASYNC 0x2000

extern struct kmem_cache *fasync_cache;
extern void *fasync_lock;

void spin_lock(void *lock);
void spin_unlock(void *lock);
void write_lock_irq(void *lock);
void write_unlock_irq(void *lock);
void *kmem_cache_alloc(void *cache, int flags);
void kmem_cache_free(void *cache, void *obj);