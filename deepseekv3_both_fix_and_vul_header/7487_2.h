#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define ENODEV 19
#define EBUSY 16
#define EINVAL 22
#define EPERM 1

#define GFP_KERNEL 0
#define PAGE_SIZE 4096
#define BITS_PER_LONG (sizeof(long) * 8)
#define WATCH_QUEUE_NOTES_PER_PAGE 64

struct pipe_inode_info {
    struct watch_queue *watch_queue;
    unsigned int nr_accounted;
    unsigned int max_usage;
    void *user;
};

struct watch_queue {
    struct page **notes;
    unsigned long *notes_bitmap;
    unsigned int nr_pages;
    unsigned int nr_notes;
};

struct page {
    unsigned long index;
};

struct user_struct;

void *kcalloc(size_t n, size_t size, int flags);
void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
struct page *alloc_page(int flags);
void __free_page(struct page *page);

long account_pipe_buffers(struct user_struct *user, unsigned long old, unsigned long new);
bool too_many_pipe_buffers_hard(unsigned long user_bufs);
bool too_many_pipe_buffers_soft(unsigned long user_bufs);
bool pipe_is_unprivileged_user(void);
int pipe_resize_ring(struct pipe_inode_info *pipe, unsigned int nr_slots);