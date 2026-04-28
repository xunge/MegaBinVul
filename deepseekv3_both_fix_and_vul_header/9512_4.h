#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define CONFIG_EISA 1
#define CONFIG_X86_32 1
#define CONFIG_IA32_EMULATION 1
#define CONFIG_X86_MCE 1

#define X86_TRAP_DE 0
#define X86_TRAP_NMI 2
#define X86_TRAP_OF 4
#define X86_TRAP_BR 5
#define X86_TRAP_UD 6
#define X86_TRAP_NM 7
#define X86_TRAP_DF 8
#define X86_TRAP_OLD_MF 9
#define X86_TRAP_TS 10
#define X86_TRAP_NP 11
#define X86_TRAP_SS 12
#define X86_TRAP_GP 13
#define X86_TRAP_SPURIOUS 15
#define X86_TRAP_MF 16
#define X86_TRAP_AC 17
#define X86_TRAP_MC 18
#define X86_TRAP_XF 19
#define X86_TRAP_DB 1
#define X86_TRAP_BP 3

#define NMI_STACK 0
#define DOUBLEFAULT_STACK 1
#define STACKFAULT_STACK 2
#define MCE_STACK 3

#define FIRST_EXTERNAL_VECTOR 32
#define IA32_SYSCALL_VECTOR 128
#define SYSCALL_VECTOR 0x80
#define GDT_ENTRY_DOUBLEFAULT_TSS 0
#define IDT_ENTRIES 256
#define FIX_RO_IDT 0
#define PAGE_KERNEL_RO 0

typedef uint32_t *__iomem;

int EISA_bus;
unsigned long used_vectors[1024];
char idt_table[4096];

struct desc_ptr {
    unsigned short size;
    unsigned long address;
} idt_descr;

struct debug_idt_table {
    char entries[4096];
};

__iomem early_ioremap(unsigned long, size_t);
void early_iounmap(__iomem, size_t);
uint32_t readl(__iomem);
void set_intr_gate(int, void *);
void set_intr_gate_ist(int, void *, int);
void set_system_intr_gate(int, void *);
void set_task_gate(int, int);
void set_system_trap_gate(int, void *);
void set_bit(int, unsigned long *);
void __set_fixmap(int, unsigned long, int);
unsigned long __pa_symbol(const void *);
unsigned long fix_to_virt(int);
void cpu_init(void);
void set_nmi_gate(int, void *);

void divide_error(void);
void nmi(void);
void overflow(void);
void bounds(void);
void invalid_op(void);
void device_not_available(void);
void double_fault(void);
void coprocessor_segment_overrun(void);
void invalid_TSS(void);
void segment_not_present(void);
void stack_segment(void);
void general_protection(void);
void spurious_interrupt_bug(void);
void coprocessor_error(void);
void alignment_check(void);
void machine_check(void);
void simd_coprocessor_error(void);
void ia32_syscall(void);
void system_call(void);
void debug(void);
void int3(void);

struct x86_init_ops {
    struct {
        void (*trap_init)(void);
    } irqs;
} x86_init;

#define __init
#define __iomem