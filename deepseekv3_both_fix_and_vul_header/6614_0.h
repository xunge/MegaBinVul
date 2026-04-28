#include <stdlib.h>

struct domain;
struct vcpu {
    struct arch {
        void *vm_event;
        void *msr;
    } arch;
    struct domain *domain;
};

void xfree(void *ptr);
void vcpu_destroy_fpu(struct vcpu *v);
int is_idle_domain(struct domain *d);
void vpmu_destroy(struct vcpu *v);
int is_hvm_vcpu(struct vcpu *v);
void hvm_vcpu_destroy(struct vcpu *v);
void pv_vcpu_destroy(struct vcpu *v);