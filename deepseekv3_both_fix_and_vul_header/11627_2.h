#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdint.h>

struct pt_regs {
    unsigned long ip;
    unsigned long sp;
};

struct task_struct {
    char comm[16];
    pid_t pid;
};

#define KERN_EMERG ""
#define KERN_INFO ""
#define KERN_CONT ""
#define SIGSEGV 11

typedef uint8_t u8;

static inline pid_t task_pid_nr(struct task_struct *tsk) { return tsk->pid; }
static inline int unhandled_signal(struct task_struct *tsk, int sig) { return 1; }
static inline int printk_ratelimit(void) { return 1; }
static inline void printk(const char *fmt, ...) {}
static inline void print_vma_addr(const char *prefix, unsigned long ip) {}
static inline void show_opcodes(u8 *ip, const char *loglvl) {}