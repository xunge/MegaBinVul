#include <stddef.h>

#define MPOL_F_NODE (1 << 0)
#define MPOL_F_ADDR (1 << 1)
#define MPOL_F_MEMS_ALLOWED (1 << 2)

#define MPOL_DEFAULT 0
#define MPOL_INTERLEAVE 1

#define MPOL_MODE_FLAGS 0x0F

#define EINVAL 22
#define EFAULT 14

typedef struct {
    unsigned long bits[1];
} nodemask_t;

struct vm_operations_struct {
    struct mempolicy *(*get_policy)(struct vm_area_struct *vma, unsigned long addr);
};

struct mm_struct {
    void *mmap_sem;
};

struct vm_area_struct {
    struct vm_operations_struct *vm_ops;
    struct mempolicy *vm_policy;
};

struct mempolicy {
    int mode;
    int flags;
    struct {
        nodemask_t nodes;
    } v;
    struct {
        nodemask_t user_nodemask;
    } w;
};

extern struct mempolicy default_policy;
extern nodemask_t cpuset_current_mems_allowed;
extern struct task_struct *current;

struct task_struct {
    struct mm_struct *mm;
    struct mempolicy *mempolicy;
    int il_prev;
};

static inline void task_lock(struct task_struct *task) {}
static inline void task_unlock(struct task_struct *task) {}
static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}
static inline int lookup_node(unsigned long addr) { return 0; }
static inline int mpol_store_user_nodemask(struct mempolicy *pol) { return 0; }
static inline void get_policy_nodemask(struct mempolicy *pol, nodemask_t *nmask) {}
static inline void mpol_cond_put(struct mempolicy *pol) {}
static inline struct vm_area_struct *find_vma_intersection(struct mm_struct *mm, unsigned long start_addr, unsigned long end_addr) { return NULL; }
static inline int next_node_in(int node, nodemask_t nodes) { return 0; }