#include <stdint.h>

#define TS_USEDFPU 0x0001
#define MSR_GS_BASE 0xc0000101
#define MSR_KERNEL_GS_BASE 0xc0000102
#define HOST_GS_BASE 0x1234

enum {
    fs,
    gs
};

struct kvm_vcpu {
    struct {
        int host_state_reload;
    } stat;
};

struct vcpu_vmx {
    struct kvm_vcpu vcpu;
    struct {
        int loaded;
        int fs_reload_needed;
        int gs_ldt_reload_needed;
        uint16_t fs_sel;
        uint16_t ldt_sel;
        uint16_t gs_sel;
    } host_state;
    uint64_t msr_guest_kernel_gs_base;
    uint64_t msr_host_kernel_gs_base;
};

struct desc_ptr {
    unsigned short size;
    unsigned long address;
};

extern struct desc_ptr host_gdt;

struct thread_struct {
    uint64_t gs;
};

struct task_struct {
    struct thread_struct thread;
};

extern struct task_struct *current;

void kvm_load_fs(uint16_t sel);
void kvm_load_ldt(uint16_t sel);
void kvm_load_gs(uint16_t sel);
uint64_t vmcs_readl(uint64_t field);
void reload_tss(void);
void load_gdt(const struct desc_ptr *dtr);
void local_irq_save(unsigned long flags);
void local_irq_restore(unsigned long flags);
void wrmsrl(uint32_t msr, uint64_t val);
void rdmsrl(uint32_t msr, uint64_t *val);
int is_long_mode(struct kvm_vcpu *vcpu);
void clts(void);
void loadsegment(int seg, uint16_t sel);
void load_gs_index(uint16_t sel);
struct thread_info {
    unsigned int status;
};
struct thread_info *current_thread_info(void);

static inline struct desc_ptr *get_host_gdt_ptr(void)
{
    extern struct desc_ptr host_gdt;
    return &host_gdt;
}

#define __get_cpu_var(var) (*get_host_gdt_ptr())