#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_ERR
} GF_Err;

typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_PropertyMap GF_PropertyMap;
typedef struct GF_FilterPidInst GF_FilterPidInst;
typedef void (*gf_filter_prop_filter)(void);

#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 1
#define GF_LOG_FILTER 0
#define GF_FALSE false

#define PID_IS_INPUT(pid) (0)

typedef bool Bool;

struct GF_FilterPid {
    struct {
        char *name;
        void *tasks_mx;
    } *filter;
    struct {
        char *name;
        struct {
            char *name;
        } *filter;
        void *properties;
    } *pid;
    void *properties;
    char *name;
};

struct GF_FilterPidInst {
    GF_PropertyMap *props;
};

struct GF_PropertyMap {
    int reference_count;
};

static void GF_LOG(int level, int category, const char *fmt, ...);
static void gf_mx_p(void *mx);
static void gf_mx_v(void *mx);
static GF_PropertyMap *check_new_pid_props(GF_FilterPid *pid, Bool create);
static void safe_int_inc(int *count);
static void gf_props_reset(GF_PropertyMap *props);
static GF_Err gf_props_merge_property(GF_PropertyMap *dst, GF_PropertyMap *src, gf_filter_prop_filter filter, void *cbk);
static void gf_filter_pid_set_name(GF_FilterPid *pid, const char *name);
static GF_PropertyMap *gf_list_last(void *list);
static GF_PropertyMap *gf_list_get(void *list, int index);