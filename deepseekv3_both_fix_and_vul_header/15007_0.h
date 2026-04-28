#include <stddef.h>

#define BUG() 
#define REMOVE_LINKS(x) 
#define SET_LINKS(x) 

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

static inline void list_del_init(struct list_head *entry) {}
static inline int list_empty(const struct list_head *head) { return 0; }

typedef struct task_struct {
    int ptrace;
    struct list_head ptrace_list;
    struct task_struct *parent;
    struct task_struct *real_parent;
} task_t;

void ptrace_untrace(task_t *child);