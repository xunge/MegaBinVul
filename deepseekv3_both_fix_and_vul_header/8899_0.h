#include <stddef.h>
#include <string.h>

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
    unsigned short limit;
    union {
        struct {
            unsigned short type:4;
            unsigned short s:1;
            unsigned short dpl:2;
            unsigned short p:1;
            unsigned short avl:1;
            unsigned short l:1;
            unsigned short db:1;
            unsigned short g:1;
            unsigned short unused:3;
        } fields;
        unsigned short bytes;
    } attr;
};

struct vmcb_struct {
    struct segment_register cs;
    struct segment_register ds;
    struct segment_register es;
    struct segment_register fs;
    struct segment_register gs;
    struct segment_register ss;
    struct segment_register tr;
    struct segment_register gdtr;
    struct segment_register idtr;
    struct segment_register ldtr;
    unsigned int _cpl;
};

struct vcpu {
    struct {
        struct {
            struct vmcb_struct *vmcb;
        } hvm_svm;
    } arch;
};

extern struct vcpu *current;
extern void ASSERT(int condition);
extern int vcpu_runnable(struct vcpu *v);
extern void svm_sync_vmcb(struct vcpu *v);
extern void BUG(void);