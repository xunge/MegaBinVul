#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define CONFIG_HVM 1
#define X86_CR4_FSGSBASE (1 << 16)
#define DIRTY_DS (1 << 0)
#define DIRTY_ES (1 << 1)
#define DIRTY_FS (1 << 2)
#define DIRTY_GS (1 << 3)
#define DIRTY_FS_BASE (1 << 4)
#define DIRTY_GS_BASE (1 << 5)
#define TF_kernel_mode (1 << 0)
#define VGCF_failsafe_disables_events (1 << 0)
#define TRAP_syscall 0x80
#define X86_EFLAGS_IF (1 << 9)
#define X86_EFLAGS_IOPL (3 << 12)
#define X86_EFLAGS_VM (1 << 17)
#define X86_EFLAGS_RF (1 << 16)
#define X86_EFLAGS_NT (1 << 14)
#define X86_EFLAGS_TF (1 << 8)
#define X86_EFLAGS_AC (1 << 18)
#define FLAT_COMPAT_KERNEL_SS 0x10
#define FLAT_COMPAT_KERNEL_CS 0x18
#define FLAT_KERNEL_SS 0x10
#define FLAT_KERNEL_CS 0x08
#define XENLOG_ERR 1

struct cpu_user_regs {
    unsigned long rflags;
    unsigned long rsp;
    unsigned long rip;
    unsigned long cs;
    unsigned long ss;
    unsigned long ds;
    unsigned long es;
    unsigned long fs;
    unsigned long gs;
    unsigned long r11;
    unsigned long rcx;
    unsigned long eflags;
    unsigned long esp;
    unsigned long eip;
    unsigned long entry_vector;
};

struct pv_vcpu {
    unsigned long fs_base;
    unsigned long gs_base_user;
    unsigned long gs_base_kernel;
    unsigned long ldt_ents;
    unsigned long failsafe_callback_eip;
    unsigned long iopl;
    unsigned long kernel_sp;
};

struct vcpu_info {
    unsigned long evtchn_upcall_mask;
};

struct vcpu {
    struct {
        struct pv_vcpu pv;
        struct cpu_user_regs user_regs;
        unsigned long flags;
        unsigned long vgc_flags;
        struct vcpu_info info;
    } arch;
    unsigned long domain;
};

extern int svm_load_segs(unsigned long ldt_ents, unsigned long ldt_virt_start,
                        unsigned long fs, unsigned long fs_base,
                        unsigned long gs, unsigned long gsb, unsigned long gss);

#define per_cpu(var, cpu) (var)
#define smp_processor_id() 0
#define cpu_has_svm 1
#define cpu_has_fsgsbase 0
#define is_pv_32bit_vcpu(v) 0
#define read_cr4() 0
#define LDT_VIRT_START(v) 0
#define load_LDT(v) do {} while (0)
#define preload_segment(seg, val) do {} while (0)
#define loadsegment(seg, val) 1
#define wrfsbase(val) do {} while (0)
#define wrgsshadow(val) do {} while (0)
#define wrgsbase(val) do {} while (0)
#define guest_cpu_user_regs() ((struct cpu_user_regs *)0)
#define vcpu_info(v, field) ((v)->arch.info.field)
#define VM_ASSIST(d, f) 0
#define ring_1(regs) 0
#define put_user(val, ptr) 0
#define gprintk(level, fmt, ...) do {} while (0)
#define domain_crash(d) do {} while (0)
#define toggle_guest_mode(v) do {} while (0)
#define unlikely(x) (x)