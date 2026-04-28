#include <stdbool.h>
#include <stddef.h>

struct desc_struct {
    unsigned long a, b;
};

struct desc_ptr {
    unsigned short size;
    unsigned long address;
};

struct ldt_struct {
    unsigned int nr_entries;
    struct desc_struct *entries;
};

struct mm_struct {
    struct {
        struct ldt_struct *ldt;
        void *lock;
    } context;
};

struct task_struct {
    struct mm_struct *active_mm;
};

extern struct task_struct *current;
extern void native_store_gdt(struct desc_ptr *);
extern void mutex_lock(void *);
extern void mutex_unlock(void *);

#define CONFIG_MODIFY_LDT_SYSCALL
#define SEGMENT_TI_MASK 0x4
#define SEGMENT_LDT 0x4
#define SEGMENT_RPL_MASK 0x3