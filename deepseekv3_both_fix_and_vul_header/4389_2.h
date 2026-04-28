#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct mm_struct {
    struct {
        unsigned long asce_limit;
        int list_lock;
        struct list_head pgtable_list;
        struct list_head gmap_list;
    } context;
};

typedef unsigned long pgd_t;

static inline void spin_lock_init(int *lock) {}
static inline void INIT_LIST_HEAD(struct list_head *list) {}
static inline unsigned long *crst_table_alloc(struct mm_struct *mm) { return NULL; }
static inline void crst_table_free(struct mm_struct *mm, unsigned long *table) {}
static inline int pgtable_pmd_page_ctor(void *page) { return 0; }
static inline void *virt_to_page(unsigned long *addr) { return NULL; }