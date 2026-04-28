#include <stdint.h>
#include <stdbool.h>

enum x86_segment {
    x86_seg_cs,
    x86_seg_ds,
    x86_seg_es,
    x86_seg_fs,
    x86_seg_gs,
    x86_seg_ss,
    x86_seg_tr,
    x86_seg_ldtr,
    x86_seg_gdtr,
    x86_seg_idtr
};

struct segment_attr {
    union {
        uint16_t bytes;
        struct {
            uint16_t type:4;
            uint16_t s:1;
            uint16_t dpl:2;
            uint16_t p:1;
            uint16_t avl:1;
            uint16_t l:1;
            uint16_t db:1;
            uint16_t g:1;
            uint16_t unused:4;
        } fields;
    };
};

struct segment_register {
    uint16_t sel;
    struct segment_attr attr;
    uint32_t limit;
    uint64_t base;
};

struct hvm_domain {
    uint64_t params[256];
};

struct arch_domain {
    struct hvm_domain hvm_domain;
};

struct domain {
    struct arch_domain arch;
};

struct hvm_vmx {
    bool vmx_realmode;
    uint32_t vm86_segment_mask;
    struct segment_register vm86_saved_seg[8];
};

struct arch_vcpu {
    struct hvm_vmx hvm_vmx;
};

struct vcpu {
    struct arch_vcpu arch;
    struct domain *domain;
};

#define HVM_PARAM_VM86_TSS 0
#define vm86_tr_attr 0
#define vm86_ds_attr 0

#define __vmwrite(a, b) 
#define vmx_vmcs_enter(v) 
#define vmx_vmcs_exit(v) 
#define BUG() 

#define GUEST_CS_SELECTOR 0
#define GUEST_CS_LIMIT 0
#define GUEST_CS_BASE 0
#define GUEST_CS_AR_BYTES 0
#define GUEST_DS_SELECTOR 0
#define GUEST_DS_LIMIT 0
#define GUEST_DS_BASE 0
#define GUEST_DS_AR_BYTES 0
#define GUEST_ES_SELECTOR 0
#define GUEST_ES_LIMIT 0
#define GUEST_ES_BASE 0
#define GUEST_ES_AR_BYTES 0
#define GUEST_FS_SELECTOR 0
#define GUEST_FS_LIMIT 0
#define GUEST_FS_BASE 0
#define GUEST_FS_AR_BYTES 0
#define GUEST_GS_SELECTOR 0
#define GUEST_GS_LIMIT 0
#define GUEST_GS_BASE 0
#define GUEST_GS_AR_BYTES 0
#define GUEST_SS_SELECTOR 0
#define GUEST_SS_LIMIT 0
#define GUEST_SS_BASE 0
#define GUEST_SS_AR_BYTES 0
#define GUEST_TR_SELECTOR 0
#define GUEST_TR_LIMIT 0
#define GUEST_TR_BASE 0
#define GUEST_TR_AR_BYTES 0
#define GUEST_GDTR_LIMIT 0
#define GUEST_GDTR_BASE 0
#define GUEST_IDTR_LIMIT 0
#define GUEST_IDTR_BASE 0
#define GUEST_LDTR_SELECTOR 0
#define GUEST_LDTR_LIMIT 0
#define GUEST_LDTR_BASE 0
#define GUEST_LDTR_AR_BYTES 0