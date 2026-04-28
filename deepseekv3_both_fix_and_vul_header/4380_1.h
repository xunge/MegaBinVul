#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

struct mm_struct {
    struct {
        struct list_head crst_list;
        struct list_head pgtable_list;
    } context;
};

typedef unsigned long pgd_t;

extern unsigned long *crst_table_alloc(struct mm_struct *mm, int s390_noexec);
extern void crst_table_init(unsigned long *crst, unsigned long type);
extern unsigned long pgd_entry_type(struct mm_struct *mm);
extern int s390_noexec;