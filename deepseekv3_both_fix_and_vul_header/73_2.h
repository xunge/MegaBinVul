#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef int GF_Err;

#define GF_EXPORT
#define GF_TRUE 1
#define GF_FALSE 0
#define GF_EOS 1
#define GF_OK 0
#define GF_BAD_PARAM 2
#define GF_FILTER_NOT_FOUND 3
#define GF_LOG_ERROR 1
#define GF_LOG_DEBUG 2
#define GF_LOG_FILTER 3
#define GF_MAX_PATH 260
#define GF_FS_REG_REQUIRES_RESOLVER (1 << 0)
#define GF_FS_REG_ACT_AS_SOURCE (1 << 1)

enum {
    GF_FILTER_ARG_EXPLICIT = 0,
    GF_FILTER_ARG_EXPLICIT_SOURCE = 1
};
typedef int GF_FilterArgType;

struct GF_List;

typedef struct GF_FilterSession {
    struct GF_List *registry;
    u32 max_resolve_chain_len;
    char sep_name;
    char sep_args;
} GF_FilterSession;

typedef struct GF_Filter {
    const struct GF_FilterArgs *instance_args;
    u32 num_output_pids;
} GF_Filter;

typedef struct GF_FilterArgs {
    const char *arg_name;
} GF_FilterArgs;

typedef struct GF_FilterRegister {
    const char *name;
    u32 flags;
    const GF_FilterArgs *args;
} GF_FilterRegister;

extern u32 gf_list_count(struct GF_List *list);
extern void *gf_list_get(struct GF_List *list, u32 index);
extern const char *gf_fs_path_escape_colon(GF_FilterSession *fsess, const char *name);
extern GF_Filter *gf_fs_load_encoder(GF_FilterSession *fsess, const char *args);
extern GF_Filter *gf_filter_new(GF_FilterSession *fsess, const GF_FilterRegister *f_reg, const char *args, void *unused, GF_FilterArgType argtype, GF_Err *err_code, void *unused2, Bool unused3);
extern void GF_LOG(int level, int category, const char *fmt, ...);
extern const char *gf_file_ext_start(const char *name);
extern Bool gf_file_exists(const char *path);
extern Bool gf_fs_solve_js_script(char *path, const char *name, const char *ext);
extern void gf_filter_post_process_task(GF_Filter *filter);