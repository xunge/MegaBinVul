#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define EFAULT 14

typedef uint16_t u16;

struct file;
struct file_dedupe_range_info {
    int64_t dest_fd;
    uint64_t dest_offset;
    uint64_t bytes_deduped;
    int32_t status;
    uint32_t reserved;
};

struct file_dedupe_range {
    u16 dest_count;
    struct file_dedupe_range_info info[];
};

static inline int get_user(u16 *val, const u16 __user *addr) {
    *val = *addr;
    return 0;
}

void *memdup_user(const void __user *src, size_t len);
long copy_to_user(void __user *dst, const void *src, size_t len);
int vfs_dedupe_file_range(struct file *file, struct file_dedupe_range *same);
void kfree(const void *objp);