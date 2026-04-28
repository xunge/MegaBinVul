#include <stddef.h>

#define KVM_USER_MEM_SLOTS 512
#define KVM_MAX_VCPUS 256

struct kvm {
    struct {
        int emul_smt_mode;
        int smt_mode;
    } arch;
};

extern struct kvmppc_hv_ops *kvmppc_hv_ops;
extern int threads_per_subcore;
extern int num_present_cpus(void);
extern int num_online_cpus(void);
extern int is_kvmppc_hv_enabled(struct kvm *kvm);
extern int kvmppc_hwrng_present(void);
extern int radix_enabled(void);
extern int cpu_has_feature(unsigned long feature);

enum {
    KVM_CAP_PPC_BOOKE_SREGS,
    KVM_CAP_PPC_BOOKE_WATCHDOG,
    KVM_CAP_PPC_EPR,
    KVM_CAP_PPC_SEGSTATE,
    KVM_CAP_PPC_HIOR,
    KVM_CAP_PPC_PAPR,
    KVM_CAP_PPC_UNSET_IRQ,
    KVM_CAP_PPC_IRQ_LEVEL,
    KVM_CAP_ENABLE_CAP,
    KVM_CAP_ENABLE_CAP_VM,
    KVM_CAP_ONE_REG,
    KVM_CAP_IOEVENTFD,
    KVM_CAP_DEVICE_CTRL,
    KVM_CAP_IMMEDIATE_EXIT,
    KVM_CAP_PPC_PAIRED_SINGLES,
    KVM_CAP_PPC_OSI,
    KVM_CAP_PPC_GET_PVINFO,
    KVM_CAP_SW_TLB,
    KVM_CAP_IRQ_MPIC,
    KVM_CAP_SPAPR_TCE,
    KVM_CAP_SPAPR_TCE_64,
    KVM_CAP_SPAPR_TCE_VFIO,
    KVM_CAP_PPC_RTAS,
    KVM_CAP_PPC_FIXUP_HCALL,
    KVM_CAP_PPC_ENABLE_HCALL,
    KVM_CAP_IRQ_XICS,
    KVM_CAP_PPC_ALLOC_HTAB,
    KVM_CAP_PPC_SMT,
    KVM_CAP_PPC_SMT_POSSIBLE,
    KVM_CAP_PPC_RMA,
    KVM_CAP_PPC_HWRNG,
    KVM_CAP_PPC_MMU_RADIX,
    KVM_CAP_PPC_MMU_HASH_V3,
    KVM_CAP_SYNC_MMU,
    KVM_CAP_PPC_HTAB_FD,
    KVM_CAP_NR_VCPUS,
    KVM_CAP_NR_MEMSLOTS,
    KVM_CAP_MAX_VCPUS,
    KVM_CAP_PPC_GET_SMMU_INFO,
    KVM_CAP_SPAPR_MULTITCE,
    KVM_CAP_SPAPR_RESIZE_HPT,
    KVM_CAP_PPC_FWNMI,
    KVM_CAP_PPC_HTM
};

#define CPU_FTR_ARCH_300 0x10000000
#define CPU_FTR_TM_COMP 0x20000000