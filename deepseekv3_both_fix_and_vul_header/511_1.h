#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef uint64_t ut64;

typedef struct RBinInfo {
    char *arch;
} RBinInfo;

typedef struct RBinSymbol {
    char *name;
    char *bind;
    char *type;
    ut64 paddr;
    ut64 vaddr;
    int size;
    int ordinal;
    char *forwarder;
} RBinSymbol;

typedef struct RBinAddr {
    ut64 vaddr;
    ut64 paddr;
} RBinAddr;

typedef struct RListIter {
    void *p;
    void *data;
    struct RListIter *n;
} RListIter;

typedef struct RList {
    RListIter *head;
    RListIter *tail;
} RList;

typedef struct RConfig {
    // dummy structure
} RConfig;

typedef struct RSpaces {
    // dummy structure
} RSpaces;

typedef struct RAnal {
    RSpaces meta_spaces;
} RAnal;

typedef struct RFlag {
    ut64 base;
    // dummy structure
} RFlag;

typedef struct RFlagItem {
    char *comment;
    ut64 offset;
    char *realname;
    bool demangled;
} RFlagItem;

typedef struct RBinFile {
    char *prefix;
    // dummy structure
} RBinFile;

typedef struct RBinPlugin {
    char *name;
} RBinPlugin;

typedef struct RCore {
    RBinFile *bin;
    RConfig *config;
    RAnal *anal;
    RFlag *flags;
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

#define IS_MODE_JSON(mode) (0)
#define IS_MODE_SET(mode) (0)
#define IS_MODE_RAD(mode) (0)
#define IS_MODE_NORMAL(mode) (0)
#define IS_MODE_SIMPLE(mode) (0)
#define IS_MODE_SIMPLEST(mode) (0)
#define R_FLAGS_FS_SYMBOLS NULL
#define R_META_TYPE_COMMENT 0
#define PFMT64x "llx"
#define PFMT64d "lld"
#define UT64_MAX UINT64_MAX
#define R_FREE(x) free(x)

static RBinInfo *r_bin_get_info(void *bin) { return NULL; }
static RList *r_bin_get_entries(void *bin) { return NULL; }
static RList *r_bin_get_symbols(void *bin) { return NULL; }
static int r_config_get_i(RConfig *config, const char *key) { return 0; }
static const char *r_config_get(RConfig *config, const char *key) { return NULL; }
static void r_spaces_push(RSpaces *spaces, const char *name) {}
static void r_spaces_pop(RSpaces *spaces) {}
static void r_cons_printf(const char *fmt, ...) {}
static void r_flag_space_set(RFlag *flags, const char *space) {}
static char *r_str_escape_utf8(const char *str, bool show_asciidot, bool esc_bslash) { return NULL; }
static ut64 compute_addr(void *bin, ut64 paddr, ut64 vaddr, int va) { return 0; }
static bool isAnExport(RBinSymbol *symbol) { return false; }
static bool is_in_range(ut64 addr, ut64 start, int size) { return false; }
static void snInit(RCore *r, SymName *sn, RBinSymbol *symbol, const char *lang) {}
static bool is_section_symbol(RBinSymbol *symbol) { return false; }
static bool is_file_symbol(RBinSymbol *symbol) { return false; }
static bool is_special_symbol(RBinSymbol *symbol) { return false; }
static void handle_arm_special_symbol(RCore *r, RBinSymbol *symbol, int va) {}
static void handle_arm_symbol(RCore *r, RBinSymbol *symbol, RBinInfo *info, int va) {}
static void select_flag_space(RCore *r, RBinSymbol *symbol) {}
static RFlagItem *r_flag_get(RFlag *flags, const char *name) { return NULL; }
static void r_name_filter(char *name, int len) {}
static RFlagItem *r_flag_set(RFlag *flags, const char *name, ut64 addr, int size) { return NULL; }
static void r_flag_item_set_realname(RFlagItem *fi, const char *name) {}
static void r_flag_item_set_comment(RFlagItem *fi, const char *comment) {}
static void r_flag_unset(RFlag *flags, RFlagItem *fi) {}
static void r_meta_add(RAnal *anal, int type, ut64 addr, int size, const char *name) {}
static char *r_str_escape_utf8_for_json(const char *str, int len) { return NULL; }
static char *r_str_newf(const char *fmt, ...) { return NULL; }
static void snFini(SymName *sn) {}
static RBinFile *r_bin_cur(void *bin) { return NULL; }
static RBinPlugin *r_bin_file_cur_plugin(RBinFile *binfile) { return NULL; }
static bool r_str_startswith(const char *str, const char *prefix) { return false; }
static const char *r_str_get(const char *str) { return str; }
static void handle_arm_entry(RCore *r, RBinAddr *entry, RBinInfo *info, int va) {}
static const char *r_bin_symbol_name(RBinSymbol *symbol) { return symbol->name; }
static void r_flag_space_pop(RFlag *flags) {}

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data, 1); (it) = (it)->n)