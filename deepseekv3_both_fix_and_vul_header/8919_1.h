#include <stdint.h>
#include <stdbool.h>
#include <stdnoreturn.h>

typedef unsigned int bool_t;

struct vcpu {
    struct {
        struct {
            struct vmcb_struct *vmcb;
            int launch_core;
        } hvm_svm;
        struct {
            bool_t debug_state_latch;
        } hvm_vcpu;
    } arch;
    struct domain *domain;
};

struct domain {
    bool_t debugger_attached;
};

struct vmcb_struct;

uint32_t vmcb_get_exception_intercepts(struct vmcb_struct *vmcb);
void vmcb_set_exception_intercepts(struct vmcb_struct *vmcb, uint32_t intercepts);

typedef struct {
    struct {
        uint8_t tpr;
    } fields;
} vintr_t;

vintr_t vmcb_get_vintr(struct vmcb_struct *vmcb);
void vmcb_set_vintr(struct vmcb_struct *vmcb, vintr_t intr);

int smp_processor_id(void);
void hvm_migrate_timers(struct vcpu *v);
void hvm_migrate_pirqs(struct vcpu *v);
void hvm_asid_flush_vcpu(struct vcpu *v);
noreturn void hvm_do_resume(struct vcpu *v);
noreturn void reset_stack_and_jump(void (*func)(void));

bool_t nestedhvm_enabled(struct domain *d);
bool_t nestedhvm_vcpu_in_guestmode(struct vcpu *v);

#define TRAP_debug 1
#define TRAP_int3 3

void *vcpu_vlapic(struct vcpu *v);
uint32_t vlapic_get_reg(void *vlapic, int reg);

#define APIC_TASKPRI 0

noreturn void svm_asm_do_resume(void);