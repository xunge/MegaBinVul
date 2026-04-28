#include <stddef.h>
#include <errno.h>

struct fsnotify_group;
struct fsnotify_ops;

struct user_struct {
    int inotify_devs;
};

struct inotify_data {
    int idr_lock;
    int idr;
    int last_wd;
    void *fa;
    struct user_struct *user;
};

struct fsnotify_group {
    unsigned int max_events;
    struct inotify_data inotify_data;
};

extern const struct fsnotify_ops inotify_fsnotify_ops;
extern unsigned int inotify_max_user_instances;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define ERR_PTR(x) ((void *)(long)(x))

static inline struct user_struct *get_current_user(void) { return NULL; }
static inline void fsnotify_put_group(struct fsnotify_group *group) {}
static inline struct fsnotify_group *fsnotify_alloc_group(const struct fsnotify_ops *ops) { return NULL; }
static inline void spin_lock_init(int *lock) {}
static inline void idr_init(int *idr) {}
static inline int atomic_inc_return(int *v) { return *v + 1; }