#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

typedef uint64_t ut64;
#define UT64_MAX UINT64_MAX

typedef struct RBinInfo {
    char *arch;
} RBinInfo;

typedef struct RBinSymbol {
    char *name;
    ut64 paddr;
    ut64 vaddr;
    int size;
    int ordinal;
    char *bind;
    char *type;
} RBinSymbol;

typedef struct RBinAddr {
    // dummy definition
} RBinAddr;

typedef struct RListIter {
    void *p;
    struct RListIter *n;
} RListIter;

typedef struct RList {
    RListIter *head;
} RList;

typedef struct RFlagItem {
    char *comment;
    char *realname;
    ut64 offset;
    bool demangled;
} RFlagItem;

typedef struct RFlagSpace {
    ut64 base;
} RFlagSpace;

typedef struct RFlags {
    RFlagSpace *space;
    ut64 base;
} RFlags;

typedef struct RConfig {
    // dummy definition
} RConfig;

typedef struct RBin {
    char *prefix;
} RBin;

typedef struct RAnal {
    void *meta_spaces;
} RAnal;

typedef struct RCore {
    RBin *bin;
    RConfig *config;
    RFlags *flags;
    RAnal *anal;
    ut64 offset;
} RCore;

typedef struct SymName {
    char *demname;
    char *nameflag;
    char *demflag;
    char *classname;
    char *methname;
    char *methflag;
    char *name;
} SymName;

typedef struct RBinFile {
    // dummy definition
} RBinFile;

typedef struct RBinPlugin {
    char *name;
} RBinPlugin;

#define IS_MODE_JSON(mode) (0)
#define IS_MODE_SET(mode) (0)
#define IS_MODE_RAD(mode) (0)
#define IS_MODE_NORMAL(mode) (0)
#define IS_MODE_SIMPLE(mode) (0)
#define IS_MODE_SIMPLEST(mode) (0)
#define R_FREE(x) free(x)
#define PFMT64x PRIx64
#define PFMT64d PRId64
#define MAXFLAG_LEN_DEFAULT 256
#define R_META_TYPE_COMMENT 0
#define R_FLAGS_FS_SYMBOLS 0

#define r_list_foreach(list, iter, item) \
    for ((iter) = (list)->head; (iter) && ((item) = (iter)->p); (iter) = (iter)->n)

static void eprintf(const char *fmt, ...) {}

static void r_cons_printf(const char *fmt, ...) {}
static void r_spaces_push(void *spaces, const char *name) {}
static void r_spaces_pop(void *spaces) {}
static void r_flag_space_set(void *flags, int fs) {}
static void r_flag_space_pop(void *flags) {}
static void r_meta_add(void *anal, int type, ut64 addr, int size, const char *str) {}
static void r_name_filter(char *str, int len) {}
static void r_flag_item_set_realname(void *fi, const char *name) {}
static void r_flag_item_set_comment(void *fi, const char *comment) {}
static void r_flag_unset(void *flags, void *fi) {}
static void *r_flag_set(void *flags, const char *name, ut64 addr, int size) { return NULL; }
static void *r_flag_get(void *flags, const char *name) { return NULL; }
static char *r_str_escape_utf8(const char *str, bool b, bool c) { return NULL; }
static char *r_str_escape_utf8_for_json(const char *str, int len) { return NULL; }
static char *r_str_newf(const char *fmt, ...) { return NULL; }
static char *r_str_replace(char *str, const char *a, const char *b, int c) { return NULL; }
static char *r_str_get(const char *str) { return NULL; }
static bool r_str_startswith(const char *str, const char *prefix) { return false; }
static ut64 compute_addr(void *bin, ut64 paddr, ut64 vaddr, int va) { return 0; }
static bool isAnExport(RBinSymbol *sym) { return false; }
static bool is_in_range(ut64 addr, ut64 start, int size) { return false; }
static void snInit(void *r, SymName *sn, RBinSymbol *sym, const char *lang) {}
static void snFini(SymName *sn) {}
static bool is_section_symbol(RBinSymbol *sym) { return false; }
static bool is_file_symbol(RBinSymbol *sym) { return false; }
static bool is_special_symbol(RBinSymbol *sym) { return false; }
static void handle_arm_special_symbol(void *r, RBinSymbol *sym, int va) {}
static void handle_arm_symbol(void *r, RBinSymbol *sym, RBinInfo *info, int va) {}
static void select_flag_space(void *r, RBinSymbol *sym) {}
static void handle_arm_entry(void *r, RBinAddr *entry, RBinInfo *info, int va) {}
static char *construct_symbol_flagname(const char *prefix, const char *name, int len) { return NULL; }
static char *__filterShell(const char *str) { return NULL; }
static RBinInfo *r_bin_get_info(void *bin) { return NULL; }
static RList *r_bin_get_entries(void *bin) { return NULL; }
static RList *r_bin_get_symbols(void *bin) { return NULL; }
static void *r_bin_cur(void *bin) { return NULL; }
static void *r_bin_file_cur_plugin(void *binfile) { return NULL; }
static int r_config_get_i(void *config, const char *key) { return 0; }
static const char *r_config_get(void *config, const char *key) { return NULL; }