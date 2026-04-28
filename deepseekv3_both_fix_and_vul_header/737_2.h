#include <stdlib.h>
#include <stddef.h>

#define GFP_KERNEL 0
#define ENOMEM 12
#define ERR_PTR(err) ((void *)(long)(err))
#define HNS_ROCE_CAP_FLAG_RECORD_DB (1 << 0)

struct ib_ucontext {};
struct ib_device {};
struct ib_udata {};

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {
    int lock;
};

struct hns_roce_uar {
    unsigned long pfn;
    void *map;
};

struct hns_roce_ucontext {
    struct ib_ucontext ibucontext;
    struct hns_roce_uar uar;
    struct list_head page_list;
    struct mutex page_mutex;
};

struct hns_roce_ib_alloc_ucontext_resp {
    unsigned int qp_tab_size;
};

struct hns_roce_dev {
    struct ib_device ib_dev;
    struct {
        unsigned int num_qps;
        unsigned int flags;
    } caps;
};

static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

static inline void mutex_init(struct mutex *lock)
{
    lock->lock = 0;
}

static inline void *kmalloc(size_t size, int flags)
{
    (void)flags;
    return malloc(size);
}

static inline void kfree(void *ptr)
{
    free(ptr);
}

static inline struct hns_roce_dev *to_hr_dev(struct ib_device *ib_dev)
{
    return (struct hns_roce_dev *)ib_dev;
}

static inline int ib_copy_to_udata(struct ib_udata *udata, void *src, size_t len)
{
    (void)udata;
    (void)src;
    (void)len;
    return 0;
}

static inline int hns_roce_uar_alloc(struct hns_roce_dev *dev, struct hns_roce_uar *uar)
{
    (void)dev;
    (void)uar;
    return 0;
}

static inline void hns_roce_uar_free(struct hns_roce_dev *dev, struct hns_roce_uar *uar)
{
    (void)dev;
    (void)uar;
}