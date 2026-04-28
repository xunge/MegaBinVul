#include <stddef.h>
#include <stdint.h>

#define BITS_PER_XA_VALUE (sizeof(unsigned long) * 8)
#define IDA_BITMAP_BITS (BITS_PER_XA_VALUE * 2)
#define XA_FREE_MARK 0

struct xarray {
    void *root;
    unsigned long xa_flags;
};

struct ida_bitmap {
    unsigned long bitmap[IDA_BITMAP_BITS / BITS_PER_XA_VALUE];
};

struct ida {
    struct xarray xa;
};

struct XA_STATE {
    struct xarray *xa;
    unsigned long index;
    void *entry;
};

#define XA_STATE(name, xa_ptr, idx) struct XA_STATE name = { (xa_ptr), (idx), NULL }

#define xa_is_value(ptr) ((uintptr_t)(ptr) & 1)
#define xa_to_value(ptr) ((uintptr_t)(ptr) >> 1)
#define xa_mk_value(val) ((void *)((val) << 1 | 1))

static inline int test_bit(unsigned int nr, const unsigned long *addr) {
    return (addr[nr / BITS_PER_XA_VALUE] & (1UL << (nr % BITS_PER_XA_VALUE))) != 0;
}

static inline void __clear_bit(unsigned int nr, unsigned long *addr) {
    addr[nr / BITS_PER_XA_VALUE] &= ~(1UL << (nr % BITS_PER_XA_VALUE));
}

static inline int bitmap_empty(const unsigned long *addr, unsigned int bits) {
    for (unsigned int i = 0; i < bits / BITS_PER_XA_VALUE; i++) {
        if (addr[i]) return 0;
    }
    return 1;
}

void xas_lock_irqsave(struct XA_STATE *xas, unsigned long flags);
void xas_unlock_irqrestore(struct XA_STATE *xas, unsigned long flags);
void *xas_load(struct XA_STATE *xas);
void xas_store(struct XA_STATE *xas, void *entry);
void xas_set_mark(struct XA_STATE *xas, unsigned int mark);
void kfree(void *ptr);
void WARN(int condition, const char *fmt, ...);