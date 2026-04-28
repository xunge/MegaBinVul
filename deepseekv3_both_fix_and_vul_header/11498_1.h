#include <string.h>

struct kvm_vcpu {
    struct {
        void *emulate_ctxt;
    } arch;
};

struct x86_exception {
    // Minimal definition to make it compile
    int dummy;
};

enum emulation_result {
    EMULATE_USER_EXIT,
    EMULATE_DONE
};

#define EMULTYPE_TRAP_UD 0
#define UD_VECTOR 0

extern int force_emulation_prefix;
extern unsigned long kvm_get_linear_rip(struct kvm_vcpu *);
extern int kvm_read_guest_virt(void *, unsigned long, void *, unsigned int, struct x86_exception *);
extern void kvm_rip_write(struct kvm_vcpu *, unsigned long);
extern unsigned long kvm_rip_read(struct kvm_vcpu *);
extern enum emulation_result emulate_instruction(struct kvm_vcpu *, int);
extern void kvm_queue_exception(struct kvm_vcpu *, int);