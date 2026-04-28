#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;

#define FEATURE_CONTROL_LOCKED (1 << 0)
#define FEATURE_CONTROL_VMXON_ENABLED_OUTSIDE_SMX (1 << 1)
#define FEATURE_CONTROL_VMXON_ENABLED_INSIDE_SMX (1 << 2)
#define X86_CR4_VMXE (1 << 13)
#define MSR_IA32_FEATURE_CONTROL 0x0000003a
#define EBUSY 16

struct list_head {
    struct list_head *next, *prev;
};
struct desc_ptr {
    unsigned short size;
    unsigned long address;
};

void *vmxarea;
struct list_head vcpus_on_cpu;
struct desc_ptr host_gdt;

extern int raw_smp_processor_id(void);
extern u64 __pa(const void *);
extern unsigned long read_cr4(void);
extern void write_cr4(unsigned long);
extern void rdmsrl(unsigned int msr, u64 *val);
extern void wrmsrl(unsigned int msr, u64 val);
extern void INIT_LIST_HEAD(struct list_head *list);
extern int tboot_enabled(void);
extern void kvm_cpu_vmxon(u64 phys_addr);
extern void ept_sync_global(void);
extern void store_gdt(struct desc_ptr *dtr);
extern bool vmm_exclusive;

#define per_cpu(var, cpu) var
#define __get_cpu_var(var) var