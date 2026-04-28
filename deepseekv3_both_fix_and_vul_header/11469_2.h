#include <stdint.h>

typedef struct ref {
    int type;
    struct {
        int intval;
    } value;
} ref;

typedef struct i_ctx_t {
    ref error_object;
} i_ctx_t;

typedef struct gs_lib_ctx_s {
    int gcsignal;
} gs_lib_ctx_t;

typedef struct gs_memory_s {
    gs_lib_ctx_t *gs_lib_ctx;
} gs_memory_s;

typedef struct gs_gc_root_t {
    int dummy;
} gs_gc_root_t;

typedef struct ref_stack_t {
    int requested;
} ref_stack_t;

typedef unsigned int uint;

enum {
    t__invalid,
    t_null,
    a_executable,
    gs_error_Fatal = 1,
    gs_error_Quit = 2,
    gs_error_InterpreterExit = 3,
    gs_error_ExecStackUnderflow = 4,
    gs_error_VMreclaim = 5,
    gs_error_NeedInput = 6,
    gs_error_interrupt = 7,
    gs_error_dictstackoverflow = 8,
    gs_error_dictstackunderflow = 9,
    gs_error_execstackoverflow = 10,
    gs_error_stackoverflow = 11,
    gs_error_stackunderflow = 12,
    avm_global = 1,
    avm_local = 2,
    min_dstack_size = 0,
    ES_HEADROOM = 0,
    MIN_BLOCK_ESTACK = 0,
    zpop = 0
};

extern gs_memory_s *imemory_system;
extern int idmemory;
extern ref_stack_t o_stack, e_stack, d_stack;
extern ref *esp, *esbot, *osp, *osbot, *ostop;
extern ref *systemdict;

int interp_reclaim(i_ctx_t **pi_ctx_p, int reclaim);
int interp(i_ctx_t **pi_ctx_p, ref *epref, ref *perror_object);
void make_null(ref *r);
void make_t(ref *r, int type);
void set_gc_signal(i_ctx_t *i_ctx_p, int signal);
int ref_stack_pop_block(ref_stack_t *stack);
int ref_stack_extend(ref_stack_t *stack, int size);
int copy_stack(i_ctx_t *i_ctx_p, ref_stack_t *stack, int size, ref *saref);
void ref_stack_pop_to(ref_stack_t *stack, int size);
void dict_set_top(void);
void pop_estack(i_ctx_t *i_ctx_p, int skip);
void ref_stack_clear(ref_stack_t *stack);
int gs_errorname(i_ctx_t *i_ctx_p, int code, ref *error_name);
int dict_find_string(ref *dict, const char *str, ref **perrordict);
int dict_find(ref *dict, ref *key, ref **epref);
void errorexec_find(i_ctx_t *i_ctx_p, ref *osp);
void make_oper(ref *r, int val, int op);
void make_null_proc(ref *r);
int r_has_type(ref *r, int type);
int r_has_type_attrs(const ref *r, int type, int attrs);
int r_is_proc(ref *r);
int ref_stack_count(ref_stack_t *stack);
int ref_stack_max_count(ref_stack_t *stack);
const ref *ref_stack_index(ref_stack_t *stack, int index);
void ialloc_reset_requested(int idmemory);
void gs_register_ref_root(gs_memory_s *mem, gs_gc_root_t *root, void **pptr, const char *cname);
void gs_unregister_root(gs_memory_s *mem, gs_gc_root_t *root, const char *cname);
#define GS_ERROR_IS_INTERRUPT(code) 0