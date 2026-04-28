#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

struct page {};
struct vm_area_struct {};
struct mm_struct {
    struct vm_area_struct *mmap;
    void *mmap_sem;
};
struct page_to_node {
    unsigned long addr;
    int node;
    int status;
    struct page *page;
};

#define MAX_NUMNODES 1
#define ZERO_PAGE(x) ((void *)0)
#define FOLL_GET 0
#define PageReserved(x) 0
#define page_to_nid(x) 0
#define page_mapcount(x) 0
#define put_page(x) do {} while (0)
#define EFAULT 1
#define ENOENT 2
#define EACCES 3

static int (*new_page_node)(void);

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static int migrate_prep(void) { return 0; }
static int isolate_lru_page(struct page *page, struct list_head *list) { return 0; }
static int migrate_pages(struct list_head *list, int (*new_page_node)(void), unsigned long arg) { return 0; }
static struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) { return NULL; }
static int vma_migratable(struct vm_area_struct *vma) { return 0; }
static struct page *follow_page(struct vm_area_struct *vma, unsigned long addr, int flags) { return NULL; }
static void down_read(void *sem) {}
static void up_read(void *sem) {}