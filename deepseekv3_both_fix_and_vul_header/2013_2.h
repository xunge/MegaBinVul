#include <stdatomic.h>
#include <stdio.h>

struct inode;
struct file {
    void *private_data;
};
struct fsnotify_group {
    struct {
        struct user_struct *user;
    } inotify_data;
};
struct user_struct {
    atomic_int inotify_devs;
};

static void fsnotify_clear_marks_by_group(struct fsnotify_group *group) {}
static void fsnotify_put_group(struct fsnotify_group *group) {}
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)