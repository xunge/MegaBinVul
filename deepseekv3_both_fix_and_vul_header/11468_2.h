#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct gs_memory_s gs_memory_t;

typedef struct gs_dual_memory_s {
    int reclaim;
} gs_dual_memory_t;

typedef struct ref_s {
    struct {
        const unsigned char *const_bytes;
    } value;
    int size;
} ref;

typedef struct gx_device_s {
    const char *dname;
} gx_device;

typedef struct gs_gstate_s {
    gx_device *device;
} gs_gstate;

typedef struct i_plugin_holder_s {
    // placeholder for plugin holder
} i_plugin_holder;

typedef struct i_ctx_s {
    struct {
        struct {
            gs_memory_t *non_gc_memory;
        } *current;
    } memory;
    gs_gstate *pgs;
    i_plugin_holder *plugin_list;
} i_ctx_t;

typedef struct gs_lib_ctx_s {
    FILE *fstdout;
    FILE *fstderr;
    FILE *fstdout2;
    int stdout_is_redirected;
    int stdout_to_stderr;
} gs_lib_ctx;

typedef struct gs_main_instance_s {
    i_ctx_t *i_ctx_p;
    int init_done;
    struct {
        gs_lib_ctx *gs_lib_ctx;
    } *heap;
    void *readline_data;
    struct {
        struct {
            struct {
                void *refs;
            } value;
        } container;
    } lib_path;
} gs_main_instance;

extern gs_dual_memory_t *idmemory;
extern gs_memory_t *imemory;
extern gs_memory_t *gs_imemory;
extern int avm_global;

#define gs_error_Quit (-101)
#define gs_error_VMerror (-20)
#define gs_error_Fatal (-100)

int gs_main_tempnames(gs_main_instance *minst);
void gs_finit_push_systemdict(i_ctx_t *i_ctx_p);
int gs_main_run_string(gs_main_instance *minst, const char *str, int user_errors, int *pexit_code, ref *perror_object);
int interp_reclaim(i_ctx_t **pi_ctx_p, int avm_global);
int gs_errorname(i_ctx_t *i_ctx_p, int code, ref *perror_name);
int name_string_ref(gs_memory_t *mem, ref *pnref, ref *psref);
void emprintf1(gs_memory_t *mem, const char *fmt, int arg1);
void emprintf2(gs_memory_t *mem, const char *fmt, const char *arg1, int arg2);
void emprintf3(gs_memory_t *mem, const char *fmt, const char *arg1, int arg2, const char *arg3);
int gs_closedevice(gx_device *pdev);
void rc_adjust(gx_device *pdev, int delta, const char *cname);
void rc_decrement(gx_device *pdev, const char *cname);
void gp_readline_finit(void *readline_data);
void print_resource_usage(gs_main_instance *minst, gs_memory_t *mem, const char *msg);
void dmprintf1(gs_memory_t *heap, const char *fmt, void *arg1);
int alloc_restore_all(i_ctx_t *i_ctx_p);
void i_iodev_finit(gs_dual_memory_t *dmem);
void i_plugin_finit(gs_memory_t *mem, i_plugin_holder *h);
void gs_lib_finit(int exit_status, int code, gs_memory_t *heap);
void gs_free_object(gs_memory_t *mem, void *ptr, const char *cname);
void ialloc_finit(gs_dual_memory_t *dmem);
int gs_debug_c(char c);
size_t r_size(ref *r);