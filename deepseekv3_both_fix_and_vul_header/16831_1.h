#include <stdbool.h>

#define __init
#define X86_FEATURE_IBRSB        0
#define X86_FEATURE_IBPB         0
#define X86_FEATURE_IBPB_RET     0
#define X86_FEATURE_BTC_NO       0
#define X86_FEATURE_SRSO_NO      0
#define X86_FEATURE_IBPB_BRTYPE  0
#define X86_FEATURE_IBPB_ENTRY_PV 0
#define X86_FEATURE_IBPB_ENTRY_HVM 0
#define X86_BUG_IBPB_NO_RET      0

#define CONFIG_PV                0
#define CONFIG_HVM               0

#define SCF_ist_ibpb             0

#define IS_ENABLED(x)            (x)

struct cpuinfo_x86 {
    int x86_vendor;
};

#define X86_VENDOR_AMD           0
#define X86_VENDOR_HYGON         0

extern struct cpuinfo_x86 boot_cpu_data;
extern int opt_ibpb_entry_pv;
extern int opt_ibpb_entry_hvm;
extern int opt_ibpb_ctxt_switch;
extern bool opt_ibpb_entry_dom0;
extern unsigned int default_spec_ctrl_flags;

static inline bool boot_cpu_has(int feature) { return false; }
static inline void setup_force_cpu_cap(int feature) {}