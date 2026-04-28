#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define XDP_UMEM_MIN_CHUNK_SIZE 2048
#define XDP_UMEM_UNALIGNED_CHUNK_FLAG (1 << 0)
#define XDP_UMEM_USES_NEED_WAKEUP (1 << 1)
#define XSK_UNALIGNED_BUF_ADDR_MASK ((1ULL << 48) - 1)
#define XDP_PACKET_HEADROOM 256
#define PAGE_SIZE 4096
#define PAGE_ALIGNED(addr) (((uintptr_t)(addr) & (PAGE_SIZE - 1)) == 0)
#define GFP_KERNEL_ACCOUNT 0
#define EINVAL 22
#define ENOMEM 12

typedef uint32_t u32;
typedef uint64_t u64;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

typedef struct {
    int refs;
} refcount_t;

typedef struct {
    int lock;
} spinlock_t;

struct xdp_umem {
    unsigned long address;
    u64 chunk_mask;
    u64 size;
    u32 headroom;
    u32 chunk_size_nohr;
    unsigned int npgs;
    void *pgs;
    void *user;
    u32 flags;
    struct list_head xsk_list;
    spinlock_t xsk_list_lock;
    refcount_t users;
    void *pages;
};

struct xdp_umem_reg {
    u64 addr;
    u64 len;
    u32 chunk_size;
    u32 headroom;
    u32 flags;
};

static inline bool is_power_of_2(unsigned long n)
{
    return (n != 0) && ((n & (n - 1)) == 0);
}

static inline u64 div_u64(u64 dividend, u32 divisor)
{
    return dividend / divisor;
}

static void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

static void spin_lock_init(spinlock_t *lock)
{
    lock->lock = 0;
}

static void refcount_set(refcount_t *r, int n)
{
    r->refs = n;
}

static void *kvcalloc(size_t n, size_t size, int flags)
{
    return calloc(n, size);
}

static void kvfree(void *addr)
{
    free(addr);
}

static int xdp_umem_account_pages(struct xdp_umem *umem) { return 0; }
static int xdp_umem_pin_pages(struct xdp_umem *umem) { return 0; }
static int xdp_umem_map_pages(struct xdp_umem *umem) { return 0; }
static void xdp_umem_unpin_pages(struct xdp_umem *umem) {}
static void xdp_umem_unaccount_pages(struct xdp_umem *umem) {}