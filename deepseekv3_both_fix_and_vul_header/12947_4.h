#include <stdatomic.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint64_t u64;
#define HARDIRQ_SHIFT 8
#define MSEC_PER_SEC 1000
#define CONFIG_KGDB_KDB 1
#define CONFIG_SMP 1

struct pt_regs {
    // dummy definition
};

struct task_struct {
    int pid;
};

struct kgdb_state {
    int cpu;
    int ex_vector;
    struct pt_regs *linux_regs;
    atomic_int *send_ready;
};

struct kgdb_io_ops {
    void (*pre_exception)(void);
    void (*post_exception)(void);
};

struct kgdb_arch {
    void (*disable_hw_break)(struct pt_regs *);
    void (*correct_hw_break)(void);
};

static struct kgdb_arch arch_kgdb_ops;
static struct kgdb_io_ops *dbg_io_ops;
static atomic_int kgdb_active = -1;
static atomic_int masters_in_kgdb;
static atomic_int slaves_in_kgdb;
static atomic_int kgdb_cpu_doing_single_step = -1;
static atomic_int ignore_console_lock_warning;
static int dbg_master_lock;
static int dbg_slave_lock;
static int kgdb_single_step;
static int kgdb_connected;
static int dbg_kdb_mode;
static int kgdb_do_roundup;
static int exception_level;
static int kgdb_sstep_pid;
static int dbg_switch_cpu;
static struct task_struct *current;
static struct task_struct *kgdb_contthread;

struct kgdb_info {
    int enter_kgdb;
    int exception_state;
    struct pt_regs *debuggerinfo;
    struct task_struct *task;
    int ret_state;
    int irq_depth;
};
static struct kgdb_info kgdb_info[32];

#define DCPU_WANT_MASTER 0x1
#define DCPU_IS_SLAVE 0x2
#define DCPU_WANT_BT 0x4
#define DCPU_NEXT_MASTER 0x8
#define DBG_PASS_EVENT 0x1000
#define DBG_SWITCH_CPU_EVENT 0x2000
#define LOCKDOWN_DBG_WRITE_KERNEL 0

static inline int num_online_cpus(void) { return 1; }
static inline void atomic_inc(atomic_int *v) { (*v)++; }
static inline void atomic_dec(atomic_int *v) { (*v)--; }
static inline int atomic_xchg(atomic_int *v, int i) { int old = *v; *v = i; return old; }
static inline int atomic_read(atomic_int *v) { return *v; }
static inline void atomic_set(atomic_int *v, int i) { *v = i; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline void local_irq_save(unsigned long flags) {}
static inline void local_irq_restore(unsigned long flags) {}
static inline int raw_spin_trylock(int *lock) { return 1; }
static inline int raw_spin_is_locked(int *lock) { return 0; }
static inline void raw_spin_lock(int *lock) {}
static inline void raw_spin_unlock(int *lock) {}
static inline void dump_stack(void) {}
static inline void tracing_on(void) {}
static inline void tracing_off(void) {}
static inline int tracing_is_on(void) { return 0; }
static inline void smp_mb(void) {}
static inline void smp_mb__before_atomic(void) {}
static inline void cpu_relax(void) {}
static inline void dbg_touch_watchdogs(void) {}
static inline int hardirq_count(void) { return 0; }
static inline void udelay(unsigned long usecs) {}
static inline int kgdb_io_ready(int ready) { return 1; }
static inline int kgdb_skipexception(int vector, struct pt_regs *regs) { return 0; }
static inline void kgdb_roundup_cpus(void) {}
static inline void pr_crit(const char *fmt, ...) {}
static inline void dbg_deactivate_sw_breakpoints(void) {}
static inline void dbg_activate_sw_breakpoints(void) {}
static inline int kdb_stub(struct kgdb_state *ks) { return 0; }
static inline int security_locked_down(int lock) { return 0; }
static inline int IS_ENABLED(int config) { return 1; }
static inline int gdb_serial_stub(struct kgdb_state *ks) { return 0; }