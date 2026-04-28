#include <stdbool.h>
#include <stdlib.h>

typedef unsigned long long u64;

#define ARMV8_PMU_COUNTER_MASK 0x1F
#define ARMV8_PMU_CYCLE_IDX 31
#define PMSELR_EL0 0x9CE
#define BUG() abort()

struct kvm_vcpu;

struct sys_reg_params {
    bool is_write;
    u64 regval;
};

struct sys_reg_desc {
    unsigned int CRn;
    unsigned int CRm;
    unsigned int Op2;
};

bool kvm_arm_pmu_v3_ready(struct kvm_vcpu *vcpu);
bool trap_raz_wi(struct kvm_vcpu *vcpu, struct sys_reg_params *p, const struct sys_reg_desc *r);
bool pmu_access_event_counter_el0_disabled(struct kvm_vcpu *vcpu);
u64 vcpu_sys_reg(struct kvm_vcpu *vcpu, int reg);
bool pmu_access_cycle_counter_el0_disabled(struct kvm_vcpu *vcpu);
bool pmu_counter_idx_valid(struct kvm_vcpu *vcpu, u64 idx);
bool pmu_access_el0_disabled(struct kvm_vcpu *vcpu);
void kvm_pmu_set_counter_value(struct kvm_vcpu *vcpu, u64 idx, u64 val);
u64 kvm_pmu_get_counter_value(struct kvm_vcpu *vcpu, u64 idx);