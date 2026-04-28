#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int uint;

typedef struct ref {
    int requested;
    struct {
        int intval;
    } value;
    int type;
    int attrs;
    struct ref *next;
} ref;

typedef struct i_ctx_t {
    ref error_object;
    int LockFilePermissions;
} i_ctx_t;

typedef struct gs_gc_root_t {
    void *ptr;
    char *desc;
} gs_gc_root_t;

typedef struct gs_memory_s {
    struct gs_lib_ctx_s *gs_lib_ctx;
} gs_memory_s;

typedef struct gs_lib_ctx_s {
    int gcsignal;
} gs_lib_ctx_s;

extern gs_memory_s *imemory_system;
extern gs_memory_s *imemory;
extern ref o_stack;
extern ref e_stack;
extern ref d_stack;
extern ref *osp;
extern ref *osbot;
extern ref *ostop;
extern ref *esp;
extern ref *esbot;
extern ref *systemdict;
extern int min_dstack_size;
extern int avm_global;
extern int avm_local;
extern int ES_HEADROOM;
extern int MIN_BLOCK_ESTACK;
extern int idmemory;
extern int zpop;

#define t__invalid 0
#define t_null 1
#define t_string 2
#define t_name 3
#define t_oper 4
#define a_executable 1
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

#define GS_ERROR_IS_INTERRUPT(code) ((code) == gs_error_interrupt)

static void make_null(ref *r) { r->type = t_null; }
static void make_t(ref *r, int t) { r->type = t; }
static void make_null_proc(ref *r) { r->type = t_null; r->attrs = a_executable; }
static void make_oper(ref *r, int op, int proc) { r->type = t_oper; r->value.intval = op; }
static int interp_reclaim(i_ctx_t **ctx, int mode) { return 0; }
static int interp(i_ctx_t **ctx, ref *proc, ref *perror) { return 0; }
static void set_gc_signal(i_ctx_t *ctx, int sig) {}
static int ref_stack_pop_block(ref *stack) { return 0; }
static int ref_stack_extend(ref *stack, int n) { return 0; }
static int copy_stack(i_ctx_t *ctx, ref *stack, int n, ref *result) { return 0; }
static void ref_stack_pop_to(ref *stack, int n) {}
static void dict_set_top(void) {}
static uint ref_stack_count(ref *stack) { return 0; }
static uint ref_stack_max_count(ref *stack) { return 0; }
static const ref *ref_stack_index(ref *stack, int i) { return NULL; }
static void pop_estack(i_ctx_t *ctx, int n) {}
static void ref_stack_clear(ref *stack) {}
static int gs_errorname(i_ctx_t *ctx, int code, ref *name) { return 0; }
static int dict_find_string(ref *dict, const char *key, ref **value) { return 0; }
static int dict_find(ref *dict, ref *key, ref **value) { return 0; }
static int obj_cvs(gs_memory_s *mem, ref *obj, byte *buf, int len, uint *rlen, const byte **ptr) { return 0; }
static int name_ref(gs_memory_s *mem, byte *str, uint len, ref *name, int permanent) { return 0; }
static void errorexec_find(i_ctx_t *ctx, ref *op) {}
static int r_has_type(const ref *r, int t) { return r->type == t; }
static int r_has_type_attrs(const ref *r, int t, int a) { return r->type == t && r->attrs == a; }
static int r_is_proc(const ref *r) { return r->type == t_oper && r->attrs == a_executable; }
static void ialloc_reset_requested(int id) {}
static void gs_register_ref_root(gs_memory_s *mem, gs_gc_root_t *root, void **pp, const char *cname) {}
static void gs_unregister_root(gs_memory_s *mem, gs_gc_root_t *root, const char *cname) {}
static void return_error(int code) {}

static byte buf[260];
static byte *bufptr;
static uint rlen;