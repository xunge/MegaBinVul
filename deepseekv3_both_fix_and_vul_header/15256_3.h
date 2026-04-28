#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define KVM_MAX_CPUID_ENTRIES 80
#define E2BIG 7
#define ENOMEM 12
#define EFAULT 14

struct kvm_cpuid2 {
    unsigned int nent;
    unsigned int padding;
};

struct kvm_cpuid_entry2 {
    uint32_t function;
    uint32_t index;
    uint32_t flags;
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
    uint32_t padding[3];
};

typedef uint32_t u32;

#define __user

static inline void *vmalloc(size_t size) {
    return malloc(size);
}

static inline void vfree(void *addr) {
    free(addr);
}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

extern void do_cpuid_ent(struct kvm_cpuid_entry2 *entry, u32 func, u32 idx, int *nent, int maxnent);