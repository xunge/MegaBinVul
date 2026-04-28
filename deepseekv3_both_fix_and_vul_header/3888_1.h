#include <stdbool.h>
#include <stdint.h>

#define __always_inline inline
#define lockdep_assert_irqs_disabled()
#define IS_ENABLED(x) 0
#define CONFIG_SMP 0
#define TIF_SSBD 0
#define TIF_SPEC_IB 0
#define _TIF_SSBD (1 << TIF_SSBD)
#define _TIF_SPEC_IB (1 << TIF_SPEC_IB)
#define X86_FEATURE_VIRT_SSBD 0
#define X86_FEATURE_LS_CFG_SSBD 0
#define X86_FEATURE_SPEC_CTRL_SSBD 0
#define X86_FEATURE_AMD_SSBD 0
#define MSR_IA32_SPEC_CTRL 0

typedef uint64_t u64;

extern u64 x86_spec_ctrl_base;
extern struct static_key_false switch_to_cond_stibp;

static inline bool static_cpu_has(int feature) { return false; }
static inline bool amd_set_ssb_virt_state(unsigned long tifn) { return false; }
static inline bool amd_set_core_ssb_state(unsigned long tifn) { return false; }
static inline u64 ssbd_tif_to_spec_ctrl(unsigned long tifn) { return 0; }
static inline u64 stibp_tif_to_spec_ctrl(unsigned long tifn) { return 0; }
static inline void wrmsrl(unsigned int msr, u64 val) {}