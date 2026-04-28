#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define ENOMEM 12
#define EIO 5
#define GFP_KERNEL 0
#define PAGE_SIZE 4096
#define __init
#define MSR_EFER 0xC0000080
#define X86_FEATURE_NX (1<<20)
#define EFER_NX (1<<11)
#define VMX_EPT_ACCESS_BIT (1ull)
#define VMX_EPT_DIRTY_BIT (1ull<<1)
#define VMX_EPT_EXECUTABLE_MASK (1ull<<2)
#define KVM_VMX_TSC_MULTIPLIER_MAX 0xFFFFFFFFFFFFull
#define MSR_FS_BASE 0xC0000100
#define MSR_GS_BASE 0xC0000101
#define MSR_KERNEL_GS_BASE 0xC0000102
#define MSR_IA32_SYSENTER_CS 0x174
#define MSR_IA32_SYSENTER_ESP 0x175
#define MSR_IA32_SYSENTER_EIP 0x176
#define MSR_IA32_BNDCFGS 0x00000D90

extern unsigned long host_efer;
extern unsigned long *vmx_io_bitmap_a;
extern unsigned long *vmx_io_bitmap_b;
extern unsigned long *vmx_msr_bitmap_legacy;
extern unsigned long *vmx_msr_bitmap_legacy_x2apic;
extern unsigned long *vmx_msr_bitmap_longmode;
extern unsigned long *vmx_msr_bitmap_longmode_x2apic;
extern unsigned long *vmx_msr_bitmap_nested;
extern unsigned long *vmx_vmread_bitmap;
extern unsigned long *vmx_vmwrite_bitmap;
extern int nested;
extern int enable_vpid;
extern int enable_shadow_vmcs;
extern int enable_ept;
extern int enable_unrestricted_guest;
extern int enable_ept_ad_bits;
extern int flexpriority_enabled;
extern int enable_apicv;
extern int ple_gap;
extern int enable_pml;
extern unsigned long vmx_vpid_bitmap[1];
extern bool kvm_has_tsc_control;
extern unsigned long long kvm_max_tsc_scaling_ratio;
extern unsigned int kvm_tsc_scaling_ratio_frac_bits;
extern int vmx_msr_index[];

struct vmcs_config {
    unsigned int revision_id;
    unsigned int size;
};

extern struct vmcs_config vmcs_config;

struct kvm_x86_ops {
    void (*set_apic_access_page_addr)(void *);
    void (*update_cr8_intercept)(void *);
    void (*slot_enable_log_dirty)(void *);
    void (*slot_disable_log_dirty)(void *);
    void (*flush_log_dirty)(void *);
    void (*enable_log_dirty_pt_masked)(void *);
};

extern struct kvm_x86_ops *kvm_x86_ops;
extern void *wakeup_handler;