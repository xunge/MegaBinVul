#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct srcu_struct {
    int dummy;
};

struct kvm_io_device;

struct kvm_io_range {
    struct kvm_io_device *dev;
};

struct kvm_io_bus {
    int dev_count;
    struct kvm_io_range *range;
};

struct kvm {
    struct srcu_struct srcu;
    void *buses[];
};

enum kvm_bus {
    KVM_BUS_MAX
};

#define GFP_KERNEL_ACCOUNT 0
#define struct_size(ptr, member, count) \
    (sizeof(*(ptr)) + (count) * sizeof((ptr)->member[0]))

void *kmalloc(size_t size, int flags);
void kfree(const void *objp);
void rcu_assign_pointer(void *p, void *v);
void synchronize_srcu_expedited(struct srcu_struct *srcu);
struct kvm_io_bus *kvm_get_bus(struct kvm *kvm, enum kvm_bus bus_idx);
int pr_err(const char *fmt, ...);