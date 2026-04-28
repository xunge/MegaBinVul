#include <stdio.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE 4096

extern struct mutex {
    int dummy;
} list_mutex;
extern struct list_head {
    struct list_head *next, *prev;
} mem_list_head;
extern long snd_allocated_pages;

struct snd_buffer {
    struct {
        int type;
    } dev;
    void *addr;
    size_t bytes;
};

struct snd_mem_list {
    struct list_head list;
    unsigned int id;
    struct snd_buffer buffer;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((char *)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(pos))((char *)pos->member.next - offsetof(typeof(*pos), member)))

static inline void mutex_lock(struct mutex *lock) { (void)lock; }
static inline void mutex_unlock(struct mutex *lock) { (void)lock; }