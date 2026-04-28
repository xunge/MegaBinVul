#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef uint64_t ut64;

typedef struct RConfig {
    void *config;
} RConfig;

typedef struct RAnalOpt {
    bool noncode;
    int bb_max_size;
    bool searchstringrefs;
    bool followbrokenfcnsrefs;
} RAnalOpt;

typedef struct RAnalCur {
    char *arch;
} RAnalCur;

typedef struct RAnal {
    int bits;
    RAnalCur *cur;
    RAnalOpt opt;
    void *leaddrs;
    void *constpool;
    bool verbose;
} RAnal;

typedef struct RIO {
    void *io;
} RIO;

typedef struct RFlag {
    void *flags;
} RFlag;

typedef struct RCore {
    RConfig *config;
    RAnal *anal;
    RIO *io;
    RFlag *flags;
    void *bin;
} RCore;

typedef struct RAnalFunction {
    char *name;
    char *cc;
    int bits;
    ut64 addr;
    int type;
    bool bp_frame;
} RAnalFunction;

typedef struct RAnalHint {
    int bits;
} RAnalHint;

typedef struct RFlagItem {
    char *name;
} RFlagItem;

typedef struct RBinSymbol {
    char *name;
    char *type;
    ut64 paddr;
} RBinSymbol;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
} RListIter;

typedef struct RList {
    RListIter *head;
} RList;

typedef struct RIOMap {
    int perm;
} RIOMap;

typedef struct RAnalMetaItem {
    ut64 size;
} RAnalMetaItem;

#define PFMT64x "%" PRIx64
#define R_ANAL_RET_ERROR -1
#define R_ANAL_RET_NEW -2
#define R_ANAL_RET_DUP -3
#define R_ANAL_RET_END -4
#define R_PERM_X 1
#define R_META_TYPE_ANY 0
#define R_ANAL_VAR_KIND_BPV 0
#define R_FLAGS_FS_FUNCTIONS "functions"
#define R_BIN_TYPE_FUNC_STR "FUNC"
#define UT64_MAX UINT64_MAX

static char* get_function_name(RCore *core, ut64 at) { return NULL; }
static void r_warn_if_fail(void *p) {}
static void eprintf(const char *fmt, ...) {}
static void r_anal_fcn_invalidate_read_ahead_cache(void) {}
static bool r_io_is_valid_offset(RIO *io, ut64 offset, bool check_perm) { return false; }
static bool r_cons_is_breaked(void) { return false; }
static void set_fcn_name_from_flag(RAnalFunction *fcn, RFlagItem *f, const char *prefix) {}
static bool is_entry_flag(RFlagItem *f) { return false; }
static void autoname_imp_trampoline(RCore *core, RAnalFunction *fcn) {}
static void loganal(ut64 addr, ut64 at, int depth) {}
static ut64* next_append(ut64 *next, int *nexti, ut64 addr) { return NULL; }
static bool r_anal_analyze_fcn_refs(RCore *core, RAnalFunction *fcn, int depth) { return false; }
static void r_cons_clear_line(int n) {}
static char* r_str_newf(const char *fmt, ...) { return NULL; }
static char* r_str_constpool_get(void *pool, const char *str) { return NULL; }
static int r_config_get_i(RConfig *config, const char *key) { return 0; }
static char* r_config_get(RConfig *config, const char *key) { return NULL; }
static char* r_anal_cc_default(RAnal *anal) { return NULL; }
static bool r_anal_cc_once(RAnal *anal) { return false; }
static RAnalHint* r_anal_hint_get(RAnal *anal, ut64 addr) { return NULL; }
static void r_anal_hint_free(RAnalHint *hint) {}
static ut64 r_anal_function_linear_size(RAnalFunction *fcn) { return 0; }
static int r_anal_function(RAnal *anal, RAnalFunction *fcn, ut64 addr, int size, int type) { return 0; }
static void r_anal_set_stringrefs(RCore *core, RAnalFunction *fcn) {}
static ut64 r_anal_function_realsize(RAnalFunction *fcn) { return 0; }
static RFlagItem* r_core_flag_get_by_spaces(RFlag *flags, ut64 addr) { return NULL; }
static RList* r_bin_get_symbols(void *bin) { return NULL; }
static char* r_anal_fcntype_tostring(int type) { return NULL; }
static void r_flag_space_push(RFlag *flags, const char *name) {}
static void r_flag_set(RFlag *flags, const char *name, ut64 addr, ut64 size) {}
static void r_flag_space_pop(RFlag *flags) {}
static void r_anal_xrefs_set(RAnal *anal, ut64 from, ut64 to, int type) {}
static void r_anal_add_function(RAnal *anal, RAnalFunction *fcn) {}
static ut64 r_anal_function_max_addr(RAnalFunction *fcn) { return 0; }
static RIOMap* r_io_map_get_at(RIO *io, ut64 addr) { return NULL; }
static RAnalMetaItem* r_meta_get_at(RAnal *anal, ut64 addr, int type, ut64 *size) { return NULL; }
static void r_list_free(RList *list) {}
static bool r_anal_get_fcn_in(RAnal *anal, ut64 addr, int type) { return false; }
static void r_core_anal_fcn(RCore *core, ut64 addr, ut64 from, int type, int depth) {}
static void r_anal_function_check_bp_use(RAnalFunction *fcn) {}
static void r_anal_function_delete_vars_by_kind(RAnalFunction *fcn, int kind) {}
static void r_anal_function_free(RAnalFunction *fcn) {}
static RAnalFunction* r_anal_function_new(RAnal *anal) { return NULL; }
static void R_FREE(void *ptr) {}

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data, 1); (it) = (it)->n)