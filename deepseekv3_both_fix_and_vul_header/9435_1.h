#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint64_t u64;

struct vcpu_svm {
    struct {
        struct {
            u64 regs[16];
            u64 rip;
        } arch;
    } vcpu;
    u64 next_rip;
};

struct msr_data {
    u64 data;
    u32 index;
    bool host_initiated;
};

#define VCPU_REGS_RCX 1
#define VCPU_REGS_RAX 0
#define VCPU_REGS_RDX 2

extern u64 kvm_rip_read(struct vcpu_svm *svm);
extern int svm_set_msr(struct vcpu_svm *svm, struct msr_data *msr);
extern void trace_kvm_msr_write_ex(u32 ecx, u64 data);
extern void trace_kvm_msr_write(u32 ecx, u64 data);
extern void kvm_inject_gp(struct vcpu_svm *svm, int val);
extern void skip_emulated_instruction(struct vcpu_svm *svm);