#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int dummy;
};

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

struct kvm {
    struct mutex lock;
};

struct kvm_sev_info {
    unsigned int handle;
    unsigned int asid;
    struct list_head regions_list;
};

struct enc_region {
    struct list_head list;
};

struct kvm_svm {
    struct kvm_sev_info sev_info;
};

static inline struct kvm_svm *to_kvm_svm(struct kvm *kvm)
{
    return (struct kvm_svm *)kvm;
}

static inline bool sev_guest(struct kvm *kvm)
{
    return false;
}

static void __unregister_enc_region_locked(struct kvm *kvm, struct enc_region *region)
{
}

static void sev_unbind_asid(struct kvm *kvm, unsigned int handle)
{
}

static void sev_asid_free(unsigned int asid)
{
}

static inline void wbinvd_on_all_cpus(void)
{
}

#define list_empty(head) ((head)->next == (head))
#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))