#include <stddef.h>
#include <sys/types.h>

struct gru_thread_state {
    int ts_user_blade_id;
    int ts_user_chiplet_id;
    pid_t ts_tgid_owner;
    unsigned int ts_cch_req_slice;
};

struct gru_set_context_option_req {
    int op;
    unsigned long gseg;
    unsigned long val0;
    unsigned long val1;
};

struct task_struct {
    pid_t tgid;
};

void *gru_base[1];

#define GRU_CHIPLETS_PER_HUB 1
#define GRU_MAX_BLADES 1
#define sco_blade_chiplet 1
#define sco_gseg_owner 2
#define sco_cch_req_slice 3

#define STAT(x)
#define gru_dbg(x, ...)
#define gru_find_lock_gts(x) NULL
#define gru_alloc_locked_gts(x) NULL
#define gru_check_context_placement(x) 0
#define gru_unlock_gts(x)
#define gru_unload_context(x, y)
#define grudev NULL
#define current ((struct task_struct *)0)
#define copy_from_user(a, b, c) 0
#define EINVAL 1
#define EFAULT 2
#define IS_ERR(x) 0
#define PTR_ERR(x) 0