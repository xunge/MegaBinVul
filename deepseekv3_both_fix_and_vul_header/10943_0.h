#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define unlikely(x) (x)
#define likely(x) (x)
#define BUG() abort()

#define _PGT_pinned 0
#define PGT_type_mask 0
#define PGT_validated 0
#define PGT_partial 0

#define ERESTART (-1)
#define EINTR (-2)

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

struct page_list_head {
    struct page_info *head;
    struct page_info *tail;
};

struct domain {
    struct {
        struct page_list_head relmem_list;
    } arch;
    struct page_list_head page_list;
    void *page_alloc_lock;
};

static void spin_lock_recursive(void *lock) {}
static void spin_unlock_recursive(void *lock) {}
static bool get_page(struct page_info *page, struct domain *d) { return false; }
static void page_list_add(struct page_info *page, struct page_list_head *list) {}
static void page_list_add_tail(struct page_info *page, struct page_list_head *list) {}
static struct page_info *page_list_remove_head(struct page_list_head *list) { return NULL; }
static void page_list_move(struct page_list_head *dst, struct page_list_head *src) {}
static int put_page_and_type_preemptible(struct page_info *page) { return 0; }
static void put_page(struct page_info *page) {}
static void put_page_alloc_ref(struct page_info *page) {}
static int free_page_type(struct page_info *page, unsigned long type, int flags) { return 0; }
static bool hypercall_preempt_check(void) { return false; }
static bool test_and_clear_bit(int nr, unsigned long *addr) { return false; }
static void set_bit(int nr, unsigned long *addr) {}
static unsigned long cmpxchg(unsigned long *ptr, unsigned long old, unsigned long new) { return 0; }