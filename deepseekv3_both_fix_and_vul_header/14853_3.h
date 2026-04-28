#include <stddef.h>
#include <string.h>
#include <stdatomic.h>

#define __cpuinit
#define NR_CPUS 8
#define N_EXCEPTION_STACKS 4
#define EXCEPTION_STACK_ORDER 0
#define DEBUG_STACK 1
#define DEBUG_STACK_ORDER 0
#define GDT_SIZE 256
#define GDT_ENTRY_TLS_ENTRIES 3
#define IO_BITMAP_LONGS 32
#define PAGE_SIZE 4096
#define GFP_ATOMIC 0
#define MSR_FS_BASE 0xc0000100
#define MSR_KERNEL_GS_BASE 0xc0000101
#define X86_CR4_VME 0x00000001
#define X86_CR4_PVI 0x00000002
#define X86_CR4_TSD 0x00000004
#define X86_CR4_DE 0x00000008

struct tss_struct {
    unsigned long io_bitmap_base;
    unsigned long io_bitmap[IO_BITMAP_LONGS + 1];
    unsigned long ist[N_EXCEPTION_STACKS];
};

struct orig_ist {
    unsigned long ist[N_EXCEPTION_STACKS];
};

struct desc_ptr {
    unsigned short size;
    unsigned long address;
};

struct mm_context {
    void *ldt;
};

struct mm_struct {
    _Atomic int mm_count;
    struct mm_context context;
};

struct task_struct {
    struct mm_struct *mm;
    struct mm_struct *active_mm;
    struct {
        unsigned long tls_array[GDT_ENTRY_TLS_ENTRIES];
    } thread;
};

extern struct tss_struct init_tss[NR_CPUS];
extern struct orig_ist orig_ist[NR_CPUS];
extern char *boot_exception_stacks;
extern struct task_struct *current;
extern struct desc_ptr cpu_gdt_descr[NR_CPUS];
extern struct desc_ptr idt_descr;
extern unsigned long cpu_gdt_table[GDT_SIZE];
extern struct mm_struct init_mm;
extern unsigned long kernel_eflags;
extern unsigned long cpu_initialized;

#define per_cpu(var, cpu) (var[cpu])
#define cpu_gdt(cpu) ((void *)&cpu_gdt_table)

static inline void atomic_inc(_Atomic int *v) {
    (*v)++;
}

int stack_smp_processor_id(void);
void pda_init(int cpu);
void zap_low_mappings(int cpu);
int cpu_test_and_set(int cpu, unsigned long *mask);
void clear_in_cr4(unsigned long mask);
void syscall_init(void);
void check_efer(void);
void set_tss_desc(int cpu, struct tss_struct *t);
void load_TR_desc(void);
void load_LDT(struct mm_context *context);
void fpu_init(void);
void raw_local_save_flags(unsigned long flags);
void panic(const char *fmt, ...);
void printk(const char *fmt, ...);
void *__get_free_pages(unsigned int gfp_mask, unsigned int order);
void barrier(void);
void BUG(void);
void enter_lazy_tlb(struct mm_struct *mm, struct task_struct *tsk);
void set_debugreg(unsigned long value, int reg);
void wrmsrl(unsigned int msr, unsigned long val);