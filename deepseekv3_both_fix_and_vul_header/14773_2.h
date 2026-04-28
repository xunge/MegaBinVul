#include <stddef.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <errno.h>

struct lxc_conf {
    struct {
        char *path;
        char *mount;
    } rootfs;
    struct lxc_list {
        struct lxc_list *next;
        struct lxc_list *prev;
    } keepcaps;
    struct lxc_list caps;
};

struct lxc_handler;

#define LXC_AUTO_PROC_MASK 0
#define LXC_AUTO_PROC_MIXED 0
#define LXC_AUTO_PROC_RW 0
#define LXC_AUTO_SYS_MASK 0
#define LXC_AUTO_SYS_RW 0
#define LXC_AUTO_SYS_RO 0
#define LXC_AUTO_SYS_MIXED 0
#define LXC_AUTO_CGROUP_MASK 0
#define LXC_AUTO_CGROUP_NOSPEC 0
#define LXC_AUTO_CGROUP_FULL_NOSPEC 0
#define LXC_AUTO_CGROUP_RW 0
#define LXC_AUTO_CGROUP_MIXED 0
#define LXC_AUTO_CGROUP_FULL_RW 0
#define LXC_AUTO_CGROUP_FULL_MIXED 0
#define CAP_SYS_ADMIN 0

#define SYSERROR(fmt, ...)
#define INFO(fmt, ...)

static char *lxc_string_replace(const char *pattern, const char *replacement, const char *original) { return NULL; }
static int in_caplist(int cap, struct lxc_list *list) { return 0; }
static int cgroup_mount(const char *path, struct lxc_handler *handler, int flags) { return 0; }
static unsigned long add_required_remount_flags(const char *source, const char *destination, unsigned long flags) { return 0; }
static int lxc_list_empty(struct lxc_list *list) { return 0; }