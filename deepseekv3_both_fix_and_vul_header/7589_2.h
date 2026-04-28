#include <stddef.h>
#include <stdlib.h>

struct device {
    // minimal device struct definition
    int dummy;
};

struct mutex {
    // minimal mutex struct definition
    int dummy;
};

struct rtrs_clt_sess {
    struct device dev;
    struct mutex paths_ev_mutex;
    struct mutex paths_mutex;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define kfree free
#define mutex_destroy(ptr) ((void)0)