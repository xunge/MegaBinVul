#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;

struct desc_ptr {
    unsigned long address;
    unsigned short size;
};

struct vcpu_vmx {
    unsigned long host_idt_base;
    struct {
        unsigned long vmcs_host_cr4;
    } host_state;
};

#define X86_CR0_TS (1UL << 3)
#define GDT_ENTRY_TSS 0x0C
#define __KERNEL_CS 0x10
#define __KERNEL_DS 0x18
#define VM_EXIT_LOAD_IA32_PAT (1UL << 15)

#define HOST_CR0 0x6000
#define HOST_CR3 0x6002
#define HOST_CR4 0x6004
#define HOST_CS_SELECTOR 0x0C00
#define HOST_DS_SELECTOR 0x0C02
#define HOST_ES_SELECTOR 0x0C04
#define HOST_SS_SELECTOR 0x0C06
#define HOST_TR_SELECTOR 0x0C08
#define HOST_IDTR_BASE 0x0C0A
#define HOST_RIP 0x0C0C
#define HOST_IA32_SYSENTER_CS 0x0C0E
#define HOST_IA32_SYSENTER_EIP 0x0C10
#define HOST_IA32_PAT 0x0C12

#define MSR_IA32_SYSENTER_CS 0x174
#define MSR_IA32_SYSENTER_EIP 0x176
#define MSR_IA32_CR_PAT 0x277

extern unsigned long read_cr0(void);
extern unsigned long read_cr3(void);
extern unsigned long read_cr4(void);
extern void native_store_idt(struct desc_ptr *dt);
extern void rdmsr(unsigned int msr, u32 *low, u32 *high);
extern void rdmsrl(unsigned int msr, unsigned long *val);
extern void vmcs_writel(unsigned long field, unsigned long value);
extern void vmcs_write16(unsigned long field, u16 value);
extern void vmcs_write32(unsigned long field, u32 value);
extern void vmcs_write64(unsigned long field, u64 value);

extern unsigned long vmx_return;
extern struct {
    unsigned long vmexit_ctrl;
} vmcs_config;