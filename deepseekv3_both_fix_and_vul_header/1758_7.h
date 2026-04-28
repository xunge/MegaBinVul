#include <stddef.h>

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

#define list_first_entry(ptr, type, member) \
    container_of((ptr)->next, type, member)

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    unsigned long data;
};

struct kref {
    int refcount;
};

struct spinlock {
    int lock;
};

struct mutex {
    int lock;
};

struct dma_fence {
    struct list_head head;
};

struct mm_struct {
    int dummy;
};

struct svm_range;
struct svm_range_list;

struct svm_range_bo_fence {
    struct dma_fence base;
    struct mm_struct *mm;
};

struct svm_range_bo {
    struct work_struct eviction_work;
    struct kref kref;
    struct spinlock list_lock;
    struct list_head range_list;
    struct svm_range_bo_fence *eviction_fence;
};

struct svm_range {
    struct svm_range_list *svms;
    unsigned long start;
    unsigned long last;
    struct mutex migrate_mutex;
    struct mutex lock;
    struct list_head svm_bo_list;
    int actual_loc;
    struct svm_range_bo *svm_bo;
};

struct svm_range_list {
    int dummy;
};

enum KFD_MIGRATE_TRIGGER {
    KFD_MIGRATE_TRIGGER_TTM_EVICTION
};

static inline int mmget_not_zero(struct mm_struct *mm) { return 1; }
static inline void mmap_read_lock(struct mm_struct *mm) {}
static inline void mmap_read_unlock(struct mm_struct *mm) {}
static inline void mmput(struct mm_struct *mm) {}
static inline void spin_lock(struct spinlock *lock) {}
static inline void spin_unlock(struct spinlock *lock) {}
static inline int list_empty(const struct list_head *head) { return 1; }
static inline void list_del_init(struct list_head *entry) {}
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void dma_fence_signal(struct dma_fence *fence) {}
static inline long kref_read(struct kref *kref) { return 0; }
static inline void WARN_ONCE(int condition, const char *msg) {}
static inline void pr_debug(const char *fmt, ...) {}
static inline void pr_info_once(const char *fmt, ...) {}

int svm_bo_ref_unless_zero(struct svm_range_bo *svm_bo);
void svm_range_bo_unref(struct svm_range_bo *svm_bo);
int svm_migrate_vram_to_ram(struct svm_range *prange, struct mm_struct *mm,
                           enum KFD_MIGRATE_TRIGGER trigger, ...);