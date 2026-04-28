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
#define _SEGMENT_P 0x80
#define _SEGMENT_TYPE 0x1F00

typedef unsigned char u8;
typedef int bool_t;

struct segment_register {
    uint16_t sel;
    uint32_t base;
    uint32_t limit;
    union {
        struct {
            uint16_t p:1;
            uint16_t g:1;
            uint16_t bytes:14;
        } fields;
        uint16_t bytes;
    } attr;
};

struct desc_struct {
    uint32_t a;
    uint32_t b;
};

struct cpu_user_regs {
    uint32_t eflags;
};

struct vcpu {
};

static struct cpu_user_regs* guest_cpu_user_regs(void) { return 0; }
static struct vcpu* current = 0;
static void hvm_set_segment_register(struct vcpu*, enum x86_segment, struct segment_register*) {}
static void hvm_get_segment_register(struct vcpu*, enum x86_segment, struct segment_register*) {}
static struct desc_struct* hvm_map_entry(uint32_t, bool_t*) { return 0; }
static void hvm_unmap_entry(struct desc_struct*) {}
static uint32_t cmpxchg(uint32_t*, uint32_t, uint32_t) { return 0; }
static void hvm_inject_hw_exception(int, uint16_t) {}