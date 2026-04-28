#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define FANOTIFY_METADATA_VERSION 3
#define FAN_EVENT_METADATA_LEN (sizeof(struct fanotify_event_metadata))
#define FAN_NOPIDFD -1
#define FAN_EPIDFD -2
#define FAN_NOFD -1
#define PIDTYPE_TGID 0
#define EFAULT 14

struct fanotify_event_metadata {
    unsigned int event_len;
    unsigned int metadata_len;
    unsigned char vers;
    unsigned char reserved;
    uint32_t mask;
    int32_t fd;
    int32_t pid;
};

struct fsnotify_group {
    unsigned int flags;
};

struct fanotify_event {
    uint32_t mask;
    pid_t pid;
    struct fanotify_perm_event *perm;
};

struct fanotify_perm_event {
    int fd;
};

struct path {
    void *mnt;
    void *dentry;
};

struct fanotify_info;
struct file;

#define __user

#define FAN_GROUP_FLAG(group, flag) ((group)->flags & (flag))
#define FANOTIFY_INFO_MODES 1
#define FAN_REPORT_PIDFD 2
#define FANOTIFY_UNPRIV 4
#define FAN_REPORT_TID 8
#define FANOTIFY_OUTGOING_EVENTS 0xFFFF

static inline struct path *fanotify_event_path(struct fanotify_event *event) { return NULL; }
static inline struct fanotify_info *fanotify_event_info(struct fanotify_event *event) { return NULL; }
static inline unsigned int fanotify_event_len(unsigned int info_mode, struct fanotify_event *event) { return 0; }
static inline int create_fd(struct fsnotify_group *group, struct path *path, struct file **f) { return 0; }
static inline int fanotify_is_perm_event(uint32_t mask) { return 0; }
static inline int copy_info_records_to_user(struct fanotify_event *event, struct fanotify_info *info, unsigned int info_mode, int pidfd, char *buf, size_t count) { return 0; }
static inline void put_unused_fd(int fd) {}
static inline void fput(struct file *file) {}
static inline int pidfd_create(pid_t pid, unsigned int flags) { return 0; }
static inline int pid_has_task(pid_t pid, int type) { return 0; }
static inline void close_fd(int fd) {}
static inline pid_t pid_vnr(pid_t pid) { return pid; }
static inline void fd_install(int fd, struct file *file) {}

#define pr_debug(fmt, ...) 
#define WARN_ON_ONCE(condition) (condition)
#define task_tgid(task) getpid()
#define current ((void*)0)

#define FANOTIFY_PERM(event) ((struct fanotify_perm_event *)(event))

static inline int copy_to_user(void *dst, const void *src, size_t size) {
    memcpy(dst, src, size);
    return 0;
}