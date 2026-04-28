#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

#define PAGE_SIZE 4096
#define UID_GID_MAP_MAX_BASE_EXTENTS 5
#define UID_GID_MAP_MAX_EXTENTS 340
#define CAP_SYS_ADMIN 0
#define EINVAL 22
#define EPERM 1

typedef long ssize_t;
typedef long loff_t;
typedef unsigned int u32;

struct file {
    void *private_data;
};

struct seq_file {
    void *private;
};

struct user_namespace {
    // dummy structure
};

struct uid_gid_extent {
    u32 first;
    u32 lower_first;
    u32 count;
};

struct uid_gid_map {
    unsigned int nr_extents;
    union {
        struct uid_gid_extent extent[UID_GID_MAP_MAX_BASE_EXTENTS];
        struct {
            struct uid_gid_extent *forward;
            struct uid_gid_extent *reverse;
        };
    };
};

extern struct {
    int nr_extents;
} userns_state_mutex;

#define __user