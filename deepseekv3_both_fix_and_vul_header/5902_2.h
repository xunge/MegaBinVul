#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

typedef uint16_t u16;

struct se_wwn {
    // minimal definition
};
struct se_portal_group {
    // minimal definition
};
struct config_group {
    // minimal definition
};
struct mutex {
    // minimal definition
};
struct list_head {
    // minimal definition
};

struct vhost_scsi_tport {
    struct se_wwn tport_wwn;
};
struct vhost_scsi_tpg {
    struct mutex tv_tpg_mutex;
    struct list_head tv_tpg_list;
    struct vhost_scsi_tport *tport;
    unsigned long tport_tpgt;
    struct se_portal_group se_tpg;
};
struct vhost_scsi_fabric_configfs {
    void *tf_ops;
};

#define VHOST_SCSI_MAX_TARGET 256
#define GFP_KERNEL 0
#define ERR_PTR(x) ((void*)(long)(x))
#define ENOMEM 12
#define EINVAL 22
#define TRANSPORT_TPG_TYPE_NORMAL 0

extern struct vhost_scsi_fabric_configfs *vhost_scsi_fabric_configfs;
extern struct mutex vhost_scsi_mutex;
extern struct list_head vhost_scsi_list;

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *p) { free(p); }
static inline void mutex_init(struct mutex *lock) {}
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void INIT_LIST_HEAD(struct list_head *list) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
static inline void pr_err(const char *fmt, ...) {}

int core_tpg_register(void *ops, struct se_wwn *wwn, struct se_portal_group *se_tpg, void *tpg, int type);
int kstrtou16(const char *s, unsigned int base, u16 *res);
int kstrtoul(const char *s, unsigned int base, unsigned long *res);