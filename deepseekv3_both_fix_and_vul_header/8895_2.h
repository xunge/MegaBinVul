#include <stdint.h>
#include <string.h>

enum x86_segment {
    x86_seg_cs,
    x86_seg_ss,
    x86_seg_ldtr,
    x86_seg_gdtr
};

#define TRAP_invalid_tss 0
#define TRAP_no_segment 0
#define TRAP_stack_error 0

#define X86_EFLAGS_VM 0x00020000

#define _SEGMENT_CODE 0x18
#define _SEGMENT_WR 0x02
#define _SEGMENT_EC 0x04
#define _SEGMENT_TYPE 0x1F00
#define _SEGMENT_P 0x80

typedef unsigned char u8;
typedef int bool_t;

struct segment_attr {
    union {
        struct {
            u8 p:1;
            u8 dpl:2;
            u8 s:1;
            u8 type:4;
            u8 g:1;
            u8 db:1;
            u8 l:1;
            u8 avl:1;
            u8 unused:4;
        } fields;
        uint16_t bytes;
    };
};

struct segment_register {
    uint16_t sel;
    uint32_t base;
    uint32_t limit;
    struct segment_attr attr;
};

struct desc_struct {
    uint32_t a;
    uint32_t b;
};

struct cpu_user_regs {
    uint32_t eflags;
};

struct vcpu;

extern struct vcpu *current;
extern struct cpu_user_regs *guest_cpu_user_regs(void);
extern void hvm_set_segment_register(struct vcpu *v, enum x86_segment seg, struct segment_register *segr);
extern void hvm_get_segment_register(struct vcpu *v, enum x86_segment seg, struct segment_register *segr);
extern struct desc_struct *hvm_map_entry(uint32_t addr, bool_t *writable);
extern void hvm_unmap_entry(struct desc_struct *pdesc);
extern void hvm_inject_hw_exception(int fault_type, uint16_t sel);
extern uint32_t cmpxchg(uint32_t *ptr, uint32_t old, uint32_t new);