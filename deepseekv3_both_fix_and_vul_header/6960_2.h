#include <stdbool.h>

struct kvm_vcpu;
struct vmcs;

struct loaded_vmcs {
    struct vmcs *vmcs;
    int cpu;
    void *loaded_vmcss_on_cpu_link;
};

struct vcpu_vmx {
    struct loaded_vmcs *loaded_vmcs;
};

struct cpu_entry_area {
    struct {
        void *x86_tss;
    } tss;
};

extern struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu);
extern void loaded_vmcs_clear(struct loaded_vmcs *loaded_vmcs);
extern void local_irq_disable(void);
extern void local_irq_enable(void);
extern void smp_rmb(void);
extern void list_add(void *new, void *head);
extern void vmcs_load(struct vmcs *vmcs);
extern void indirect_branch_prediction_barrier(void);
extern void kvm_make_request(int req, struct kvm_vcpu *vcpu);
extern void vmcs_writel(unsigned long field, unsigned long value);
extern void *get_current_gdt_ro(void);
extern struct cpu_entry_area *get_cpu_entry_area(int cpu);
extern void *cpu_entry_stack(int cpu);

#define KVM_REQ_TLB_FLUSH 0
#define HOST_TR_BASE 0
#define HOST_GDTR_BASE 0
#define HOST_IA32_SYSENTER_ESP 0
#define IS_ENABLED(x) 0
#define WARN_ON_ONCE(x) (x)

extern struct vmcs *current_vmcs;
extern void *loaded_vmcss_on_cpu;

#define per_cpu(var, cpu) (var)