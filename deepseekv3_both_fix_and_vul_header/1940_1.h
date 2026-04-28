#include <string.h>
#include <stdlib.h>

#define TOMOYO_MOUNT_REMOUNT_KEYWORD "remount"
#define TOMOYO_MOUNT_MAKE_UNBINDABLE_KEYWORD "make_unbindable"
#define TOMOYO_MOUNT_MAKE_PRIVATE_KEYWORD "make_private"
#define TOMOYO_MOUNT_MAKE_SLAVE_KEYWORD "make_slave"
#define TOMOYO_MOUNT_MAKE_SHARED_KEYWORD "make_shared"
#define TOMOYO_MOUNT_BIND_KEYWORD "bind"
#define TOMOYO_MOUNT_MOVE_KEYWORD "move"

#define TOMOYO_TYPE_MOUNT_ACL 0
#define TOMOYO_RETRY_REQUEST 0
#define ENOMEM 12
#define ENODEV 19
#define ENOENT 2

struct path {
    // dummy definition
};

struct file_system_type {
    int fs_flags;
    // other members omitted
};

struct tomoyo_path_info {
    const char *name;
    // other members omitted
};

struct tomoyo_mount_acl {
    int need_dev;
    struct tomoyo_path_info *dev;
    struct tomoyo_path_info *dir;
    struct tomoyo_path_info *type;
    unsigned long flags;
};

struct tomoyo_request_info {
    int param_type;
    union {
        struct tomoyo_mount_acl mount;
    } param;
};

#define FS_REQUIRES_DEV 0x0001
#define LOOKUP_FOLLOW 0x0001

static inline void path_put(struct path *path) {}
static inline int kern_path(const char *name, unsigned flags, struct path *path) { return 0; }
static inline struct file_system_type *get_fs_type(const char *name) { return NULL; }
static inline void put_filesystem(struct file_system_type *fs) {}

static char *tomoyo_encode(const char *str) { return NULL; }
static char *tomoyo_realpath_from_path(const struct path *path) { return NULL; }
static void tomoyo_fill_path_info(struct tomoyo_path_info *info) {}
static void tomoyo_check_acl(struct tomoyo_request_info *r, void (*func)(struct tomoyo_request_info *)) {}
static int tomoyo_audit_mount_log(struct tomoyo_request_info *r) { return 0; }
static void tomoyo_check_mount_acl(struct tomoyo_request_info *r) {}