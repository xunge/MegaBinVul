#include <stddef.h>
#include <sys/types.h>

struct ctl_table {
    void *data;
    size_t maxlen;
};

struct hstate {
    unsigned long nr_overcommit_huge_pages;
};

extern struct hstate default_hstate;
extern int hugepages_supported(void);
extern int hstate_is_gigantic(struct hstate *h);
extern int proc_doulongvec_minmax(struct ctl_table *, int, void *, size_t *, loff_t *);

typedef int spinlock_t;
extern spinlock_t hugetlb_lock;

#define EOPNOTSUPP 95
#define EINVAL 22

#define spin_lock(lock) ((void)0)
#define spin_unlock(lock) ((void)0)