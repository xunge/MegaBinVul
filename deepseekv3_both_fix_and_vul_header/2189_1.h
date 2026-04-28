#include <stddef.h>

#define MB (1024 * 1024)
#define KB 1024
#define PAGE_SIZE 4096

struct mm_struct {
    unsigned long hiwater_rss;
    unsigned long hiwater_vm;
};

struct task_struct {
    unsigned long acct_rss_mem1;
    unsigned long acct_vm_mem1;
    struct mm_struct *mm;
    unsigned long rchar;
    unsigned long wchar;
    unsigned long syscr;
    unsigned long syscw;
};

struct taskstats {
    unsigned long coremem;
    unsigned long virtmem;
    unsigned long hiwater_rss;
    unsigned long hiwater_vm;
    unsigned long read_char;
    unsigned long write_char;
    unsigned long read_syscalls;
    unsigned long write_syscalls;
};

static inline unsigned long jiffies_to_usecs(unsigned long j) {
    return j * 10000; // Simplified conversion for compilation
}