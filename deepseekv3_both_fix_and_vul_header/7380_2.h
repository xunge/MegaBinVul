#include <stddef.h>
#include <errno.h>
#include <string.h>

#define __user

struct kvm_vcpu {
    struct {
        struct sie_block *sie_block;
    } arch;
};
struct kvm_s390_mem_op {
    unsigned long buf;
    unsigned long size;
    unsigned long sida_offset;
    unsigned long flags;
    unsigned long op;
};
struct sie_block;

#define KVM_S390_MEMOP_SIDA_READ 0
#define KVM_S390_MEMOP_SIDA_WRITE 1
#define EINVAL 22
#define E2BIG 7
#define EFAULT 14

static inline unsigned long sida_origin(struct sie_block *sb) { return 0; }
static inline unsigned long sida_size(struct sie_block *sb) { return 0; }

static inline int copy_to_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}