#include <stddef.h>

struct domain;

struct mm_rwlock {
    int dummy;
};

struct mm_lock {
    int dummy;
};

struct list_head {
    int dummy;
};

struct page_list_head {
    int dummy;
};

enum p2m_access {
    p2m_access_rwx
};

enum p2m_class {
    p2m_host
};

struct p2m_pod_mrp {
    unsigned long list[1];
};

struct p2m_pod {
    struct mm_lock lock;
    struct p2m_pod_mrp mrp;
    struct page_list_head super;
    struct page_list_head single;
};

struct p2m_domain {
    struct mm_rwlock lock;
    struct list_head np2m_list;
    struct page_list_head pages;
    struct p2m_pod pod;
    struct domain *domain;
    enum p2m_access default_access;
    enum p2m_class p2m_class;
    unsigned long np2m_base;
};

#define P2M_BASE_EADDR 0
#define INVALID_GFN 0
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

void mm_rwlock_init(struct mm_rwlock *lock);
void mm_lock_init(struct mm_lock *lock);
void INIT_LIST_HEAD(struct list_head *list);
void INIT_PAGE_LIST_HEAD(struct page_list_head *list);
int hap_enabled(struct domain *d);
extern int cpu_has_vmx;
int ept_p2m_init(struct p2m_domain *p2m);
void p2m_pt_init(struct p2m_domain *p2m);