#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct mm_struct;
struct task_struct;

#define __user

struct page_to_node {
    unsigned long addr;
    int node;
    int status;
};

typedef struct { unsigned long bits[1]; } nodemask_t;

#define MAX_NUMNODES 1
#define N_HIGH_MEMORY 1
#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define ENOMEM 1
#define ENODEV 2
#define EACCES 3
#define EFAULT 4
#define MPOL_MF_MOVE_ALL 0

static inline int get_user(const void **p, const void *addr) { return 0; }
static inline int put_user(int val, int *addr) { return 0; }
static inline bool node_isset(int node, nodemask_t mask) { return false; }
static inline bool node_state(int node, int state) { return false; }
static inline nodemask_t cpuset_mems_allowed(struct task_struct *task) { return (nodemask_t){0}; }
static inline void migrate_prep(void) {}
static inline int do_move_page_to_node_array(struct mm_struct *mm, struct page_to_node *pm, int flags) { return 0; }
static inline void free_page(unsigned long p) {}