#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <stddef.h>

#define NUM_BUCKETS 64

struct file;  // Forward declaration

struct list_head {
    struct list_head *next, *prev;
};

struct hash_cell {
    struct list_head name_list;
    char *name;
    void *md;
};

struct gendisk {
    // minimal stub
};

struct dm_ioctl {
    uint32_t flags;
    uint32_t data_size;
    uint32_t data_start;
    // other fields omitted
};

struct dm_name_list {
    uint64_t dev;
    uint32_t next;
    char name[];
};

static struct list_head _name_buckets[NUM_BUCKETS];
static struct {
    int count;
} _hash_lock;

#define DM_BUFFER_FULL_FLAG (1 << 0)

#define down_write(lock) ((void)0)
#define up_write(lock) ((void)0)
#define BUG_ON(cond) ((void)0)

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (void*)(head); pos = NULL)

static inline size_t align_val(size_t val) { return (val + 7) & ~7; }
static inline void *align_ptr(void *ptr) { return (void *)align_val((size_t)ptr); }
static struct gendisk *dm_disk(void *md) { return NULL; }
static dev_t disk_devt(struct gendisk *disk) { return 0; }
static uint64_t huge_encode_dev(dev_t dev) { return 0; }
static uint32_t dm_get_event_nr(void *md) { return 0; }
static struct dm_name_list *get_result_buffer(struct dm_ioctl *param, size_t param_size, size_t *len) { return NULL; }