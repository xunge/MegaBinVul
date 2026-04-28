#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BGID_ARRAY 64
#define IOU_PBUF_RING_MMAP (1 << 0)
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE - 1))
#define GFP_KERNEL 0

#define EFAULT 14
#define EINVAL 22
#define EEXIST 17
#define ENOMEM 12

struct list_head {
    struct list_head *next, *prev;
};

struct io_ring_ctx {
    struct io_buffer_list *io_bl;
};

struct io_uring_buf_reg {
    uint32_t ring_addr;
    uint32_t ring_entries;
    uint16_t bgid;
    uint16_t pad;
    uint64_t resv[3];
    uint32_t flags;
};

struct io_buffer_list {
    bool is_mapped;
    unsigned int nr_entries;
    unsigned int mask;
    struct list_head buf_list;
};

#define __user

static inline bool is_power_of_2(unsigned long n)
{
    return (n != 0 && ((n & (n - 1)) == 0));
}

static inline int copy_from_user(void *to, const void *from, size_t n)
{
    memcpy(to, from, n);
    return 0;
}

static inline void *kzalloc(size_t size, int flags)
{
    return calloc(1, size);
}

static inline void kfree(void *ptr)
{
    free(ptr);
}

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}