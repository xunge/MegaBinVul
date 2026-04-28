#include <stddef.h>
#include <stdbool.h>

#define ENODEV 19
#define ENOMEM 12
#define O_RDWR 02
#define O_CLOEXEC 02000000
#define KVM_CREATE_DEVICE_TEST 1
#define GFP_KERNEL 0
#define KVM_DEVICE_MAX 256  // Assuming a maximum number of device types

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

struct kvm_device;

struct kvm_device_ops {
    int (*create)(struct kvm_device *dev, int type);
    void (*destroy)(struct kvm_device *dev);
    void (*init)(struct kvm_device *dev);
    const char *name;
};

struct kvm_device {
    struct kvm_device_ops *ops;
    struct kvm *kvm;
    struct list_head vm_node;
};

struct kvm {
    struct mutex lock;
    struct list_head devices;
};

struct kvm_create_device {
    unsigned int type;
    unsigned int flags;
    int fd;
};

struct file_operations;

extern struct kvm_device_ops *kvm_device_ops_table[KVM_DEVICE_MAX];
extern const struct file_operations kvm_device_fops;

void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void *kzalloc(size_t size, int flags);
void kfree(const void *objp);
void list_add(struct list_head *new, struct list_head *head);
void list_del(struct list_head *entry);
int anon_inode_getfd(const char *name, const struct file_operations *fops, void *priv, int flags);
void kvm_get_kvm(struct kvm *kvm);