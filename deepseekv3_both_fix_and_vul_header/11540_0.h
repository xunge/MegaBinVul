#include <stdatomic.h>
#include <stddef.h>

struct mm_struct {
    void *mmap;
    int vmacache_seqnum;
    unsigned long task_size;
    void *get_unmapped_area;
    unsigned long mmap_base;
    unsigned long mmap_legacy_base;
    unsigned long highest_vm_end;
    void *pgd;
    atomic_int mm_users;
    atomic_int mm_count;
    unsigned long map_count;
    unsigned long hiwater_rss;
    unsigned long hiwater_vm;
    unsigned long total_vm;
    unsigned long locked_vm;
    unsigned long pinned_vm;
    unsigned long data_vm;
    unsigned long exec_vm;
    unsigned long stack_vm;
    unsigned long start_code;
    unsigned long end_code;
    unsigned long start_data;
    unsigned long end_data;
    unsigned long start_brk;
    unsigned long brk;
    unsigned long start_stack;
    unsigned long arg_start;
    unsigned long arg_end;
    unsigned long env_start;
    unsigned long env_end;
    void *binfmt;
    unsigned long flags;
    void *core_state;
    void *ioctx_table;
    void *owner;
    void *exe_file;
    void *mmu_notifier_mm;
    unsigned long numa_next_scan;
    unsigned long numa_scan_offset;
    int numa_scan_seq;
    atomic_int tlb_flush_pending;
    unsigned long def_flags;
};

unsigned long mm_pgtables_bytes(const struct mm_struct *mm);
void pr_emerg(const char *fmt, ...);