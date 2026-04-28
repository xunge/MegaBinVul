#include <signal.h>
#include <stddef.h>
#include <stdio.h>

#define notrace __attribute__((no_instrument_function))

#define PSW_B 0x00000004
#define PSW_R 0x00000002
#define PSW_T 0x00000001
#define PSW_X 0x00000008

#define SPACEID_SHIFT 28

#define PDC_CHASSIS_DIRECT_HPMC  1
#define PDC_CHASSIS_DIRECT_LPMC  2
#define PDC_CHASSIS_DIRECT_PANIC 3

#define TRAP_TRACE   1
#define TRAP_HWBKPT  2
#define TRAP_BRANCH  3

#define PARISC_ITLB_TRAP 6
#define VM_EXEC 0x00000004

#define KERN_CRIT ""
#define KERN_DEBUG ""

#define fallthrough ((void)0)

#define __user

struct pt_regs {
    unsigned long gr[32];
    unsigned long sr[8];
    unsigned long iaoq[2];
    unsigned long iasq[2];
    unsigned long iir;
    unsigned long isr;
    unsigned long ior;
};

struct mm_struct;
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_flags;
};

struct task_struct {
    struct mm_struct *mm;
    char comm[16];
};

extern struct task_struct *current;
extern int printk(const char *fmt, ...);
extern int parisc_printk_ratelimited(int level, struct pt_regs *regs, const char *fmt, ...);
extern void pdc_console_restart(void);
extern void pdc_chassis_send_status(int);
extern void local_irq_enable(void);
extern void flush_cache_all(void);
extern void flush_tlb_all(void);
extern void cpu_lpmc(int, struct pt_regs *);
extern unsigned long mfctl(int);
extern int user_mode(struct pt_regs *);
extern int user_space(struct pt_regs *);
extern void handle_break(struct pt_regs *);
extern void handle_fpe(struct pt_regs *);
extern void handle_gdb_break(struct pt_regs *, int);
extern void handle_unaligned(struct pt_regs *);
extern int check_unaligned(struct pt_regs *);
extern int fixup_exception(struct pt_regs *);
extern void do_page_fault(struct pt_regs *, int, unsigned long);
extern void die_if_kernel(const char *, struct pt_regs *, int);
extern void parisc_terminate(const char *, struct pt_regs *, int, int);
extern int faulthandler_disabled(void);
extern void force_sig_fault(int, int, void *);
extern void mmap_read_lock(struct mm_struct *);
extern void mmap_read_unlock(struct mm_struct *);
extern struct vm_area_struct *find_vma(struct mm_struct *, unsigned long);
extern int task_pid_nr(struct task_struct *);
extern void __inc_irq_stat(unsigned long);

unsigned long irq_fpassist_count;