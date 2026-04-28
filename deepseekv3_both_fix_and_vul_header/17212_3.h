#include <stddef.h>

#define smp_processor_id() 0
#define get_stack_bottom() 0UL
#define STACK_SIZE 8192
#define FIRST_RESERVED_GDT_ENTRY 0
#define LAST_RESERVED_GDT_BYTE 0xFFFF
#define IDT_ENTRIES 256
#define TSS_ENTRY 0
#define SYS_DESC_tss_avail 0x89
#define SYS_DESC_tss_busy 0x8B
#define IST_MCE 1
#define IST_DF 2
#define IST_NMI 3
#define IST_DB 4
#define IST_MAX 4
#define IOBMP_INVALID_OFFSET 0xFFFF
#define PAGE_SIZE 4096
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define BUILD_BUG_ON(cond) ((void)0)
#define BUG_ON(cond) do { if (cond) { volatile int x = *(int *)0; } } while(0)
#define SYS_STATE_early_boot 0

struct tss_struct {
    unsigned long rsp0;
    unsigned long rsp1;
    unsigned long rsp2;
    unsigned long ist[8];
    unsigned long bitmap;
    unsigned long __cacheline_filler;
};

struct desc_struct {
    unsigned long a, b;
};

struct desc_ptr {
    unsigned long base;
    unsigned short limit;
};

typedef struct {
    unsigned long a, b;
} idt_entry_t;

struct guest_cpu_user_regs {
    unsigned short es;
    unsigned short pad[7];
};

struct cpu_info {
    struct guest_cpu_user_regs guest_cpu_user_regs;
    char padding[16 - (sizeof(struct guest_cpu_user_regs) % 16)];
};

extern struct tss_struct init_tss;
extern struct desc_struct gdt_table[];
extern struct desc_struct compat_gdt_table[];
extern idt_entry_t *idt_tables[];
extern unsigned int system_state;

#define this_cpu(var) (var)

void _set_tssldt_desc(struct desc_struct *d, unsigned long addr, unsigned int size, unsigned int type);
void lgdt(const struct desc_ptr *dtr);
void lidt(const struct desc_ptr *dtr);
void ltr(unsigned short sel);
void lldt(unsigned short sel);
void enable_each_ist(idt_entry_t *idt);