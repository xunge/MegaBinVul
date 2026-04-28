#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define VMWARE_PORT_VMPORT 0x5658
#define VMWARE_PORT_VMRPC 0x5659
#define VCPU_SREG_TR 6
#define X86EMUL_CONTINUE 0
#define CONFIG_X86_64

struct desc_struct {
    unsigned long a, b;
    bool p;
};

struct x86_emulate_ctxt {
    const struct x86_emulate_ops *ops;
};

struct x86_emulate_ops {
    int (*get_segment)(struct x86_emulate_ctxt *, u16 *, struct desc_struct *, u32 *, int);
    int (*read_std)(struct x86_emulate_ctxt *, unsigned long, void *, unsigned, void *, ...);
};

extern bool enable_vmware_backdoor;

static inline unsigned long get_desc_base(const struct desc_struct *desc) {
    return desc->a >> 16;
}

static inline unsigned desc_limit_scaled(const struct desc_struct *desc) {
    return (desc->a & 0xffff) | ((desc->b & 0xf) << 16);
}