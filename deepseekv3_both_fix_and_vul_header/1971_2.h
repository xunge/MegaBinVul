#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct rb_node {
    unsigned long  __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

#define RB_ROOT (struct rb_root) { NULL }

struct mm_struct {
    unsigned long flags;
    void *mmap_sem;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    struct vm_area_struct *vm_next;
    void *anon_vma;
};

struct page {
    unsigned long flags;
};

struct rmap_item {
    struct list_head rmap_list;
};

struct mm_slot {
    struct hlist_node link;
    struct list_head mm_list;
    struct rmap_item *rmap_list;
    struct mm_struct *mm;
};

struct ksm_scan {
    struct mm_slot *mm_slot;
    unsigned long address;
    struct rmap_item **rmap_list;
    unsigned long seqnr;
};

extern struct mm_slot ksm_mm_head;
extern struct ksm_scan ksm_scan;
extern struct rb_root root_unstable_tree;
extern int ksm_mmlist_lock;

#define VM_MERGEABLE 0x10000000
#define PAGE_SIZE 4096
#define FOLL_GET 0x01
#define MMF_VM_MERGEABLE 0x80000000

static inline int list_empty(const struct list_head *head) { return head->next == head; }
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}
static inline void cond_resched() {}
static inline void lru_add_drain_all() {}
static inline int ksm_test_exit(struct mm_struct *mm) { return 0; }
static inline struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) { return NULL; }
static inline struct page *follow_page(struct vm_area_struct *vma, unsigned long address, int flags) { return NULL; }
static inline int PageAnon(struct page *page) { return 0; }
static inline int page_trans_compound_anon(struct page *page) { return 0; }
static inline void flush_anon_page(struct vm_area_struct *vma, struct page *page, unsigned long vmaddr) {}
static inline void flush_dcache_page(struct page *page) {}
static inline void put_page(struct page *page) {}
static inline void clear_bit(int nr, volatile unsigned long *addr) {}
static inline void mmdrop(struct mm_struct *mm) {}
static inline int IS_ERR_OR_NULL(const void *ptr) { return !ptr; }

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

static inline void hlist_del(struct hlist_node *n) {}
static inline void list_del(struct list_head *entry) {}

static inline struct rmap_item *get_next_rmap_item(struct mm_slot *slot, 
                                                 struct rmap_item **rmap_list,
                                                 unsigned long addr) { return NULL; }
static inline void remove_trailing_rmap_items(struct mm_slot *slot,
                                            struct rmap_item **rmap_list) {}
static inline void free_mm_slot(struct mm_slot *slot) {}