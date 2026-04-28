#include <stdbool.h>
#include <stdint.h>

typedef bool bool_t;

enum x86_segment {
    x86_seg_fs,
    x86_seg_gs
};

enum hvm_access_type {
    hvm_access_read,
    hvm_access_write
};

struct segment_attr_fields {
    unsigned int p : 1;
    unsigned int type : 4;
    unsigned int db : 1;
};

struct segment_register {
    unsigned long base;
    unsigned long limit;
    struct {
        struct segment_attr_fields fields;
    } attr;
};

#define X86_CR0_PE (1 << 0)

struct arch_hvm_vcpu {
    unsigned long guest_cr[8];
};

struct arch {
    struct arch_hvm_vcpu hvm_vcpu;
};

struct {
    struct arch arch;
} *current;

static inline bool is_canonical_address(unsigned long addr) {
    return true;
}