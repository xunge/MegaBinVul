#include <stddef.h>

#define _ASCE_TABLE_LENGTH 0
#define _ASCE_USER_BITS 0
#define _ASCE_TYPE_REGION3 0
#define _ASCE_TYPE_REGION2 0
#define CONFIG_64BIT 1
#define STACK_TOP_MAX 0

struct task_struct;
struct mm_struct {
    void *pgd;
    struct {
        unsigned long asce_bits;
        int noexec;
        unsigned long asce_limit;
    } context;
};

extern int s390_noexec;
extern void crst_table_init(unsigned long *, int);
extern int pgd_entry_type(struct mm_struct *);