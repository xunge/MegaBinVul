#include <stdint.h>

#define fs 0
#define gs 1

struct kvm_vcpu {
    // dummy definition
};

struct vcpu_vmx {
    struct kvm_vcpu vcpu;
    struct {
        int loaded;
        uint16_t ldt_sel;
        uint16_t fs_sel;
        uint16_t gs_sel;
        int fs_reload_needed;
        int gs_ldt_reload_needed;
    } host_state;
    int save_nmsrs;
    struct {
        uint32_t index;
        uint64_t data;
        uint64_t mask;
    } guest_msrs[0];
    uint64_t msr_host_kernel_gs_base;
    uint64_t msr_guest_kernel_gs_base;
};

#define to_vmx(vcpu) ((struct vcpu_vmx *)(vcpu))
#define HOST_FS_SELECTOR 0
#define HOST_GS_SELECTOR 0
#define HOST_FS_BASE 0
#define HOST_GS_BASE 0
#define MSR_FS_BASE 0
#define MSR_GS_BASE 0
#define MSR_KERNEL_GS_BASE 0
#define CONFIG_X86_64 1

static inline uint16_t kvm_read_ldt(void) { return 0; }
static inline void savesegment(int seg, uint16_t *sel) { *sel = 0; }
static inline void vmcs_write16(uint32_t field, uint16_t val) {}
static inline void vmcs_writel(uint32_t field, uint64_t val) {}
static inline uint64_t read_msr(uint32_t msr) { return 0; }
static inline uint64_t segment_base(uint16_t sel) { return 0; }
static inline void rdmsrl(uint32_t msr, uint64_t *val) { *val = 0; }
static inline void wrmsrl(uint32_t msr, uint64_t val) {}
static inline int is_long_mode(struct kvm_vcpu *vcpu) { return 0; }
static inline void kvm_set_shared_msr(uint32_t index, uint64_t data, uint64_t mask) {}