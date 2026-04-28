#include <stddef.h>
#include <stdbool.h>
#include <fcntl.h>

#define ENODEV 19
#define ENOMEM 12
#define GFP_KERNEL 0
#define O_RDWR 02
#define O_CLOEXEC 02000000
#define KVM_CREATE_DEVICE_TEST 1

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct kvm_device_ops {
    int (*create)(struct kvm_device *dev, unsigned int type);
    void (*destroy)(struct kvm_device *dev);
    void (*init)(struct kvm_device *dev);
    const char *name;
};

struct kvm_device {
    struct list_head vm_node;
    struct kvm_device_ops *ops;
    struct kvm *kvm;
};

struct kvm_create_device {
    unsigned int type;
    unsigned int flags;
    unsigned int fd;
};

struct kvm {
    struct mutex lock;
    struct list_head devices;
};

extern struct kvm_device_ops *kvm_device_ops_table[];
extern const struct file_operations kvm_device_fops;

static inline void mutex_lock(struct mutex *lock) { (void)lock; }
static inline void mutex_unlock(struct mutex *lock) { (void)lock; }
static inline void list_add(struct list_head *new, struct list_head *head) { (void)new; (void)head; }
static inline void list_del(struct list_head *entry) { (void)entry; }
static inline void *kzalloc(size_t size, int flags) { (void)size; (void)flags; return NULL; }
static inline void kfree(void *ptr) { (void)ptr; }
static inline int anon_inode_getfd(const char *name, const struct file_operations *fops, void *priv, int flags) { (void)name; (void)fops; (void)priv; (void)flags; return 0; }
static inline void kvm_get_kvm(struct kvm *kvm) { (void)kvm; }