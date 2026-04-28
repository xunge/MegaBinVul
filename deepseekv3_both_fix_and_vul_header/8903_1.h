#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef bool bool_t;

enum x86_segment {
    x86_seg_cs,
    x86_seg_ds,
    x86_seg_es,
    x86_seg_fs,
    x86_seg_gs,
    x86_seg_ss,
    x86_seg_tr,
    x86_seg_gdtr,
    x86_seg_idtr,
    x86_seg_ldtr
};

struct segment_register {
    unsigned long base;
    unsigned long sel;
    unsigned long limit;
    union {
        unsigned short bytes;
        struct {
            unsigned short p:1;
            unsigned short dpl:2;
            unsigned short s:1;
            unsigned short type:4;
            unsigned short g:1;
            unsigned short db:1;
            unsigned short l:1;
            unsigned short avl:1;
            unsigned short :4;
        } fields;
    } attr;
};

struct vcpu {
    struct {
        struct {
            bool vmx_realmode;
            unsigned int vm86_segment_mask;
            struct segment_register vm86_saved_seg[8];
        } hvm_vmx;
    } arch;
};

#define unlikely(x) (x)
#define BUG() abort()
#define XENLOG_WARNING ""
#define printk(...)
#define __vmread(a, b)
#define vmx_vmcs_try_enter(v) true
#define vmx_vmcs_exit(v)
#define rm_cs_attr 0
#define rm_ds_attr 0
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