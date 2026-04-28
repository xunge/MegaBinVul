#include <stdint.h>
#include <stddef.h>

#define ENOMEM 12
#define ENOENT 2
#define EEXIST 17

typedef uint32_t __u32;
typedef uint32_t u32;

struct fsnotify_group;
struct inode {
    void *i_fsnotify_marks;
    __u32 i_fsnotify_mask;
};

struct fsnotify_mark {
    __u32 mask;
    void *lock;
};

struct inotify_inode_mark {
    struct fsnotify_mark fsn_mark;
    int wd;
};

#define IN_MASK_ADD 0x20000000
#define IN_MASK_CREATE 0x10000000

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static __u32 inotify_arg_to_mask(__u32 arg) { return 0; }
static struct fsnotify_mark *fsnotify_find_mark(void *marks, struct fsnotify_group *group) { return NULL; }
static void fsnotify_recalc_mask(void *marks) {}
static void fsnotify_put_mark(struct fsnotify_mark *mark) {}
static void spin_lock(void *lock) {}
static void spin_unlock(void *lock) {}