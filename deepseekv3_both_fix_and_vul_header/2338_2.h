#include <stddef.h>
#include <stdint.h>

#define smp_processor_id() 0
#define get_stack_bottom() 0UL
#define STACK_SIZE 8192
#define FIRST_RESERVED_GDT_ENTRY 0
#define LAST_RESERVED_GDT_BYTE 0xFFFF
#define IDT_ENTRIES 256
#define TSS_ENTRY 32
#define IST_MCE 1
#define IST_DF 2
#define IST_NMI 3
#define IST_MAX 4
#define PAGE_SIZE 4096
#define IOBMP_INVALID_OFFSET 0xFFFF
#define SYS_DESC_tss_avail 0x89
#define SYS_DESC_tss_busy 0x8B
#define TRAP_double_fault 8
#define TRAP_nmi 2
#define TRAP_machine_check 18
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define BUILD_BUG_ON(condition) ((void)0)
#define BUG_ON(condition) do { if (condition) {} } while (0)

enum {
    SYS_STATE_early_boot = 0
};

struct desc_struct {
    uint64_t a, b;
};

struct desc_ptr {
    unsigned long base;
    unsigned short limit;
};

struct tss_struct {
    unsigned long rsp0;
    unsigned long rsp1;
    unsigned long rsp2;
    unsigned long ist[8];
    unsigned long bitmap;
    char __cacheline_filler[64];
};

struct cpu_info {
    struct {
        uint64_t es;
        uint64_t pad[15];
    } guest_cpu_user_regs;
};

typedef struct {
    uint64_t low;
    uint64_t high;
} idt_entry_t;

extern unsigned int system_state;
extern struct tss_struct init_tss;
extern struct desc_struct gdt_table[];
extern struct desc_struct compat_gdt_table[];
extern idt_entry_t idt_tables[][256];

static inline void _set_tssldt_desc(void *d, unsigned long addr, unsigned int size, unsigned int type) {}
static inline void set_ist(idt_entry_t *entry, unsigned int ist) {}

#define this_cpu(var) var