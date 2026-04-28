#include <signal.h>
#include <stddef.h>

#define VM_READ        0x00000001
#define VM_WRITE       0x00000002
#define VM_EXEC        0x00000004

#define VM_FAULT_MAJOR     0x0001
#define VM_FAULT_MINOR     0x0002
#define VM_FAULT_RETRY     0x0004
#define VM_FAULT_ERROR     0x0008
#define VM_FAULT_BADMAP    0x0010
#define VM_FAULT_BADACCESS 0x0020
#define VM_FAULT_OOM       0x0040
#define VM_FAULT_SIGBUS    0x0080

#define FAULT_FLAG_ALLOW_RETRY 0x01
#define FAULT_FLAG_KILLABLE    0x02
#define FAULT_FLAG_USER        0x04
#define FAULT_FLAG_WRITE       0x08

#define ESR_LNX_EXEC  0x08000000
#define ESR_EL1_WRITE 0x04000000
#define ESR_EL1_CM    0x00000080

#define PERF_COUNT_SW_PAGE_FAULTS      0
#define PERF_COUNT_SW_PAGE_FAULTS_MAJ  1
#define PERF_COUNT_SW_PAGE_FAULTS_MIN  2

struct task_struct {
    struct mm_struct *mm;
    unsigned long maj_flt;
    unsigned long min_flt;
};

struct mm_struct {
    void *mmap_sem;
};

struct pt_regs {
    unsigned long pc;
};

#define current ((struct task_struct *)0)
#define __kprobes

static inline int interrupts_enabled(struct pt_regs *regs) { return 0; }
static inline void local_irq_enable(void) {}
static inline int in_atomic(void) { return 0; }
static inline int user_mode(struct pt_regs *regs) { return 0; }
static inline int search_exception_tables(unsigned long addr) { return 0; }
static inline int down_read_trylock(void *sem) { return 0; }
static inline void down_read(void *sem) {}
static inline void might_sleep(void) {}
static inline int fatal_signal_pending(struct task_struct *tsk) { return 0; }
static inline void perf_sw_event(int event, int nr, struct pt_regs *regs, unsigned long addr) {}
static inline void up_read(void *sem) {}
static inline void pagefault_out_of_memory(void) {}
static inline void __do_user_fault(struct task_struct *tsk, unsigned long addr,
                                 unsigned int esr, int sig, int code,
                                 struct pt_regs *regs) {}
static inline void __do_kernel_fault(struct mm_struct *mm, unsigned long addr,
                                   unsigned int esr, struct pt_regs *regs) {}