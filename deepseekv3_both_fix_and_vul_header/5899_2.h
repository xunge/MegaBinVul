#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct mddev {
    int lock;
    struct {
        void *file;
    } bitmap_info;
};

typedef struct mdu_bitmap_file_t {
    char pathname[4096];
} mdu_bitmap_file_t;

#define GFP_NOIO 0
#define __user
#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int copy_to_user(void *to, const void *from, size_t n) { return 0; }
static inline char *file_path(void *file, char *buf, int len) { return NULL; }