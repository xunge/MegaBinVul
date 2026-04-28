#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef int duk_int_t;
typedef unsigned int duk_uint_t;
typedef int duk_idx_t;
typedef int duk_ret_t;
typedef unsigned char duk_small_uint_t;
typedef unsigned int duk_uint_fast8_t;
typedef unsigned int duk_size_t;
typedef uint8_t duk_uint8_t;
typedef uint32_t duk_instr_t;

#define DUK__CALL_HANDLING_REQUIRE_STACK 32

typedef struct duk_hthread duk_hthread;
typedef struct duk_heap duk_heap;
typedef struct duk_hobject duk_hobject;
typedef struct duk_hcompfunc duk_hcompfunc;
typedef struct duk_hnatfunc duk_hnatfunc;
typedef struct duk_activation duk_activation;
typedef struct duk_catcher duk_catcher;
typedef struct duk_tval duk_tval;
typedef duk_ret_t (*duk_c_function)(duk_hthread *);

struct duk_tval {
    int type;
};

struct duk_catcher {
    struct duk_catcher *parent;
    int type;
};

struct duk_activation {
    struct duk_activation *parent;
    struct duk_catcher *cat;
    struct duk_tval tv_func;
    duk_instr_t *curr_pc;
    duk_size_t reserve_byteoff;
    duk_small_uint_t flags;
};

struct duk_hobject {
    unsigned int flags;
};

struct duk_hcompfunc {
    duk_instr_t *code_base;
};

struct duk_hnatfunc {
    duk_c_function func;
};

struct duk_heap {
    duk_hthread *curr_thread;
    int call_recursion_depth;
    int call_recursion_limit;
    int stats_call_all;
    int stats_call_tailcall;
    int stats_call_ecmatoecma;
    int dbg_force_restart;
};

struct duk_hthread {
    duk_heap *heap;
    duk_tval *valstack;
    duk_tval *valstack_bottom;
    duk_tval *valstack_top;
    duk_tval *valstack_end;
    duk_tval *valstack_alloc_end;
    duk_activation *callstack_curr;
    duk_size_t callstack_top;
    duk_instr_t **ptr_curr_pc;
    duk_uint_fast8_t state;
    duk_uint_fast8_t callstack_preventcount;
    duk_uint_fast8_t interrupt_counter;
    duk_uint_fast8_t interrupt_init;
};

#define DUK_LOCAL
#define DUK_USE_ASSERTIONS
#define DUK_USE_TAILCALL
#define DUK_USE_ES6_PROXY
#define DUK_USE_DEBUGGER_SUPPORT
#define DUK_USE_INTERRUPT_COUNTER
#define DUK_USE_DEBUG
#define DUK_USE_FASTINT

#define DUK_CALL_FLAG_TAILCALL 0x01
#define DUK_CALL_FLAG_CONSTRUCT 0x02
#define DUK_CALL_FLAG_CONSTRUCT_PROXY 0x04
#define DUK_CALL_FLAG_ALLOW_ECMATOECMA 0x08

#define DUK_ACT_FLAG_PREVENT_YIELD 0x01

#define DUK_CAT_TYPE_LABEL 0x01

#define DUK_HTHREAD_STATE_INACTIVE 0
#define DUK_HTHREAD_STATE_RUNNING 1

#define DUK_LIKELY(x) (x)
#define DUK_UNLIKELY(x) (x)

#define DUK_ASSERT(x)
#define DUK_CTX_ASSERT_VALID(thr)
#define DUK_DD(x)
#define DUK_DDD(x)
#define DUK_DDPRINT(...)
#define DUK_DDDPRINT(...)
#define DUK_ERROR_TYPE(thr, msg)
#define DUK_HEAP_SWITCH_THREAD(heap, thread)
#define DUK_REFZERO_CHECK_FAST(thr)
#define DUK_STATS_INC(heap, field)
#define DUK_TVAL_CHKFAST_INPLACE_FAST(tv)
#define DUK_TVAL_GET_LIGHTFUNC_FUNCPTR(tv) NULL
#define DUK_TVAL_IS_LIGHTFUNC(tv) 0
#define DUK_TVAL_IS_UNDEFINED(tv) 0
#define DUK_TVAL_SET_TVAL_UPDREF(thr, tv1, tv2)
#define DUK_WO_NORETURN(expr) do { expr; } while (0)

#define DUK_HOBJECT_IS_COMPFUNC(obj) 0
#define DUK_HOBJECT_IS_NATFUNC(obj) 0
#define DUK_HOBJECT_HAS_BOUNDFUNC(obj) 0
#define DUK_HOBJECT_HAS_COMPFUNC(obj) 0
#define DUK_ACT_GET_FUNC(act) NULL
#define DUK_CAT_GET_TYPE(cat) 0
#define DUK_HCOMPFUNC_GET_CODE_BASE(heap, func) NULL
#define DUK_ASSERT_LJSTATE_UNSET(heap)

DUK_LOCAL void duk_hthread_sync_and_null_currpc(duk_hthread *thr) {}
DUK_LOCAL void duk__call_thread_state_update(duk_hthread *thr) {}
DUK_LOCAL void duk__call_c_recursion_limit_check(duk_hthread *thr) {}
DUK_LOCAL duk_small_uint_t duk__resolve_target_fastpath_check(duk_hthread *thr, duk_idx_t idx, duk_hobject **func, duk_small_uint_t flags) { return 0; }
DUK_LOCAL duk_hobject *duk__resolve_target_func_and_this_binding(duk_hthread *thr, duk_idx_t idx, duk_small_uint_t *flags) { return NULL; }
DUK_LOCAL duk_small_uint_t duk__call_setup_act_attempt_tailcall(duk_hthread *thr, duk_small_uint_t flags, duk_idx_t idx, duk_hobject *func, duk_size_t b1, duk_size_t b2, duk_idx_t *nargs, duk_idx_t *nregs, duk_size_t *vs_bytes, duk_activation **act) { return 0; }
DUK_LOCAL void duk__call_setup_act_not_tailcall(duk_hthread *thr, duk_small_uint_t flags, duk_idx_t idx, duk_hobject *func, duk_size_t b1, duk_size_t b2, duk_idx_t *nargs, duk_idx_t *nregs, duk_size_t *vs_bytes, duk_activation **act) {}
DUK_LOCAL void duk__call_env_setup(duk_hthread *thr, duk_hobject *func, duk_activation *act, duk_idx_t idx) {}
DUK_LOCAL void duk_valstack_grow_check_throw(duk_hthread *thr, duk_size_t bytes) {}
DUK_LOCAL void duk_set_top_and_wipe(duk_hthread *thr, duk_idx_t top, duk_idx_t wipe) {}
DUK_LOCAL void duk_js_execute_bytecode(duk_hthread *thr) {}
DUK_LOCAL void duk_error_throw_from_negative_rc(duk_hthread *thr, duk_ret_t rc) {}
DUK_LOCAL void duk_call_construct_postprocess(duk_hthread *thr, int proxy) {}
DUK_LOCAL void duk_hthread_activation_unwind_norz(duk_hthread *thr) {}
DUK_LOCAL void duk_set_top_unsafe(duk_hthread *thr, duk_idx_t idx) {}
DUK_LOCAL int duk_debug_is_attached(duk_heap *heap) { return 0; }
DUK_LOCAL void duk__interrupt_fixup(duk_hthread *thr, duk_hthread *entry) {}
DUK_LOCAL duk_idx_t duk_get_top(duk_hthread *thr) { return 0; }
DUK_LOCAL int duk_is_valid_index(duk_hthread *thr, duk_idx_t idx) { return 0; }
DUK_LOCAL void duk_require_stack(duk_hthread *thr, int size) {}