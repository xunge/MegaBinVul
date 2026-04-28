#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MSR_GS_BASE 0xc0000101
#define MSR_KERNEL_GS_BASE 0xc0000102
#define HOST_GS_BASE 0xc0000103
#define TS_USEDFPU 0x0008

struct kvm_vcpu_stat {
    int host_state_reload;
};

struct kvm_vcpu {
    struct kvm_vcpu_stat stat;
};

struct host_state {
    bool loaded;
    bool fs_reload_needed;
    bool gs_ldt_reload_needed;
    unsigned short fs_sel;
    unsigned short gs_sel;
    unsigned short ldt_sel;
};

struct vcpu_vmx {
    struct kvm_vcpu vcpu;
    struct host_state host_state;
    unsigned long msr_guest_kernel_gs_base;
    unsigned long msr_host_kernel_gs_base;
};

struct thread_info {
    unsigned int status;
};

struct desc_ptr {
    unsigned short size;
    unsigned long address;
};

struct host_gdt {
    struct desc_ptr gdt;
};

extern struct host_gdt host_gdt;
extern struct host_gdt *__get_cpu_var_host_gdt(void);
#define __get_cpu_var(var) (*__get_cpu_var_host_gdt())

extern void kvm_load_fs(unsigned short sel);
extern void kvm_load_gs(unsigned short sel);
extern void kvm_load_ldt(unsigned short sel);
extern void local_irq_save(unsigned long flags);
extern void local_irq_restore(unsigned long flags);
extern void reload_tss(void);
extern void clts(void);
extern unsigned long vmcs_readl(unsigned long field);
extern struct thread_info *current_thread_info(void);
extern void load_gdt(const struct desc_ptr *dtr);
extern void wrmsrl(unsigned int msr, unsigned long val);
extern void rdmsrl(unsigned int msr, unsigned long *val);
extern int is_long_mode(struct kvm_vcpu *vcpu);