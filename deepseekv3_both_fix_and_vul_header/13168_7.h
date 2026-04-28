#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef unsigned int u32;
typedef int s32;
typedef bool Bool;
#define GF_FALSE false
#define GF_TRUE true

typedef struct GF_FSTask GF_FSTask;
typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_FilterPidInst GF_FilterPidInst;
typedef struct GF_List GF_List;
typedef struct GF_FilterRegister GF_FilterRegister;
typedef struct GF_PropertyValue {
    u32 reference_count;
} GF_PropertyValue;

#define GF_LOG_INFO 0
#define GF_LOG_ERROR 1
#define GF_LOG_FILTER 2

#define TASK_REQUEUE(task) do { (void)(task); } while(0);
#define GF_LOG(level, category, msg) do { (void)(level); (void)(category); (void)(msg); } while(0);

struct GF_FSTask {
    GF_Filter *filter;
    struct {
        GF_FilterPid *pid;
    } *pid;
    void *udta;
};

struct GF_FilterPidInst {
    GF_Filter *filter;
    GF_FilterPid *pid;
    GF_PropertyValue *props;
    GF_List *packets;
    Bool force_flush;
};

struct GF_FilterPid {
    char *name;
    GF_Filter *filter;
    GF_List *destinations;
    GF_List *properties;
    u32 num_destinations;
    u32 detach_pid_tasks_pending;
    Bool stream_reset_pending;
};

struct GF_FilterRegister {
    void (*configure_pid)(void);
};

struct GF_Filter {
    char *name;
    GF_FilterRegister *freg;
    GF_List *input_pids;
    GF_List *detached_pid_inst;
    u32 num_input_pids;
    GF_Filter *single_source;
    Bool in_process;
    Bool in_force_flush;
    u32 pending_packets;
    Bool in_pid_connection_pending;
    Bool swap_needs_init;
    GF_FilterPidInst *swap_pidinst_src;
    GF_FilterPidInst *swap_pidinst_dst;
    u32 detach_pid_tasks_pending;
    void *tasks_mx;
    Bool stream_reset_pending;
};

static inline s32 safe_int_dec(u32 *val) { return --(*val); }
static inline void safe_int_sub(u32 *val, s32 sub) { *val -= sub; }
static inline void gf_mx_p(void *mx) {}
static inline void gf_mx_v(void *mx) {}
static inline void gf_list_del_item(GF_List *list, void *item) {}
static inline u32 gf_list_count(GF_List *list) { return 0; }
static inline void *gf_list_get(GF_List *list, u32 idx) { return NULL; }
static inline s32 gf_list_find(GF_List *list, void *item) { return -1; }
static inline void gf_list_add(GF_List *list, void *item) {}
static inline GF_List *gf_list_new() { return NULL; }
static inline void gf_filter_process_inline(GF_Filter *filter) {}
static inline void gf_filter_pid_inst_reset(GF_FilterPidInst *pidinst) {}
static inline void gf_props_del(GF_PropertyValue *props) {}
static inline u32 gf_fq_count(GF_List *q) { return 0; }