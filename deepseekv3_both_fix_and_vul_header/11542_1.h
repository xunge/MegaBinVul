#include <stdint.h>

typedef unsigned int uint;

typedef struct ref_s {
    int type;
    union {
        int intval;
        void *ptr;
    } value;
} ref;

typedef struct i_ctx_s {
    ref error_object;
    int LockFilePermissions;
} i_ctx_t;

typedef struct gs_lib_ctx_s {
    int gcsignal;
} gs_lib_ctx_t;

typedef struct gs_memory_system_s {
    gs_lib_ctx_t *gs_lib_ctx;
} gs_memory_system_t;

typedef struct gs_gc_root_s {
    void *dummy;
} gs_gc_root_t;

typedef struct ref_stack_s {
    int requested;
    ref *p;
    ref *bot;
    ref *top;
} ref_stack_t;

extern gs_memory_system_t *imemory_system;
extern ref_stack_t o_stack;
extern ref_stack_t e_stack;
extern ref_stack_t d_stack;
extern ref *systemdict;
extern ref *osp;
extern ref *osbot;
extern ref *ostop;
extern ref *esp;
extern ref *esbot;
extern int min_dstack_size;
extern int avm_global;
extern int avm_local;
extern int ES_HEADROOM;
extern int MIN_BLOCK_ESTACK;
extern int idmemory;
extern void *zpop;

#define GS_ERROR_IS_INTERRUPT(code) 0
#define t__invalid 0
#define t_null 0
#define a_executable 0
#define t_operator 0
#define gs_error_Fatal (-1)
#define gs_error_Quit (-2)
#define gs_error_InterpreterExit (-3)
#define gs_error_ExecStackUnderflow (-4)
#define gs_error_VMreclaim (-5)
#define gs_error_NeedInput (-6)
#define gs_error_interrupt (-7)
#define gs_error_dictstackoverflow (-8)
#define gs_error_dictstackunderflow (-9)
#define gs_error_execstackoverflow (-10)
#define gs_error_stackoverflow (-11)
#define gs_error_stackunderflow (-12)

static void make_null(ref *);
static void make_t(ref *, int);
static void make_oper(ref *, int, void *);
static void make_null_proc(ref *);
static int interp_reclaim(i_ctx_t **, int);
static int interp(i_ctx_t **, ref *, ref *);
static void set_gc_signal(i_ctx_t *, int);
static void gs_register_ref_root(gs_memory_system_t *, gs_gc_root_t *, void **, const char *);
static void gs_unregister_root(gs_memory_system_t *, gs_gc_root_t *, const char *);
static int ref_stack_extend(ref_stack_t *, int);
static int ref_stack_pop_block(ref_stack_t *);
static int ref_stack_count(ref_stack_t *);
static uint ref_stack_max_count(ref_stack_t *);
static const ref *ref_stack_index(ref_stack_t *, int);
static void ref_stack_clear(ref_stack_t *);
static void ref_stack_pop_to(ref_stack_t *, int);
static int copy_stack(i_ctx_t *, ref_stack_t *, int, ref *);
static void dict_set_top(void);
static void pop_estack(i_ctx_t *, int);
static int gs_errorname(i_ctx_t *, int, ref *);
static int dict_find_string(ref *, const char *, ref **);
static int dict_find(ref *, ref *, ref **);
static void errorexec_find(i_ctx_t *, ref *);
static int r_has_type(const ref *, int);
static int r_has_type_attrs(const ref *, int, int);
static int r_is_proc(const ref *);
static void return_error(int);
static void ialloc_reset_requested(int);