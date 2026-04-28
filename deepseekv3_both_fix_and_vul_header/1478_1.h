#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

#define PXA3XX_GCU_BATCH_WORDS 1024
#define E2BIG 7
#define EFAULT 14

typedef int64_t loff_t;
typedef size_t ssize_t;

struct file {
    void *private_data;
};

struct pxa3xx_gcu_batch {
    struct pxa3xx_gcu_batch *next;
    uint32_t *ptr;
    int length;
};

struct pxa3xx_gcu_shared {
    unsigned int num_writes;
    unsigned int num_words;
    int hw_running;
};

struct pxa3xx_gcu_priv {
    unsigned long spinlock;
    struct pxa3xx_gcu_batch *free;
    struct pxa3xx_gcu_batch *ready;
    struct pxa3xx_gcu_batch *ready_last;
    struct pxa3xx_gcu_shared *shared;
};

static inline struct pxa3xx_gcu_priv *to_pxa3xx_gcu_priv(struct file *file)
{
    return file->private_data;
}

static int pxa3xx_gcu_wait_free(struct pxa3xx_gcu_priv *priv);
static void run_ready(struct pxa3xx_gcu_priv *priv);

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define BUG_ON(cond) ((void)0)

static inline unsigned long copy_from_user(void *to, const void *from, unsigned long n)
{
    memcpy(to, from, n);
    return 0;
}