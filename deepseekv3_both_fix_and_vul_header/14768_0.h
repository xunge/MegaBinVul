#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <unistd.h>

enum {
    LXC_AUTO_CGROUP_RO,
    LXC_AUTO_CGROUP_RW,
    LXC_AUTO_CGROUP_MIXED,
    LXC_AUTO_CGROUP_NOSPEC,
    LXC_AUTO_CGROUP_FULL_RO,
    LXC_AUTO_CGROUP_FULL_RW,
    LXC_AUTO_CGROUP_FULL_MIXED,
    LXC_AUTO_CGROUP_FULL_NOSPEC
};

struct cgroup_hierarchy {
    char **subsystems;
};

struct cgroup_mount_point {
    char *mount_point;
    char *mount_prefix;
};

struct cgroup_process_info {
    struct cgroup_hierarchy *hierarchy;
    char *cgroup_path;
    struct cgroup_mount_point *designated_mount_point;
    struct cgroup_process_info *next;
};

struct cgfs_data {
    struct cgroup_process_info *info;
};

#define MS_NOSUID 2
#define MS_NODEV 4
#define MS_NOEXEC 8
#define MS_RELATIME (1 << 21)
#define MS_BIND 4096
#define MS_RDONLY 1
#define MS_REMOUNT 32

#define ERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define SYSERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define WARN(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

static size_t lxc_array_len(void **array);
static char *lxc_string_join(const char *sep, const char **parts, bool escape);
static char *lxc_append_paths(const char *first, const char *second);
static int mkdir_p(const char *dir, mode_t mode);
static char *cgroup_to_absolute_path(struct cgroup_mount_point *mp, const char *cgroup_path, const char *suffix);
static struct cgroup_mount_point *lxc_cgroup_find_mount_point(struct cgroup_hierarchy *hierarchy, const char *cgroup_path, bool exact);