#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef uint64_t ut64;

typedef struct RCoreIO {
    bool va;
    bool debug;
} RCoreIO;

typedef struct RCorePrint {
    bool cur_enabled;
    ut64 cur;
} RCorePrint;

typedef struct RCore {
    void *config;
    void *bin;
    struct RCoreFile *file;
    RCoreIO *io;
    void *num;
    void *flags;
    RCorePrint *print;
    ut64 offset;
} RCore;

typedef struct RCoreFileDesc {
    const char *name;
} RCoreFileDesc;

typedef struct RCoreFile {
    RCoreFileDesc *desc;
} RCoreFile;

typedef struct RBinObject {
    void *kv;
    void *sections;
    void *libs;
    void *symbols;
    void *imports;
    void *classes;
    void *strings;
} RBinObject;

typedef struct Sdb Sdb;

typedef struct RFlagItem {
    const char *name;
    ut64 offset;
} RFlagItem;

typedef struct RBinClass {
    const char *name;
    void *methods;
} RBinClass;

typedef struct RBinSymbol {
    const char *name;
    ut64 vaddr;
    void *method_flags;
} RBinSymbol;

typedef struct RList {
    struct RListIter *head;
} RList;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
    void *p;
} RListIter;

#define R_CORE_BIN_ACC_CLASSES 0
#define R_CORE_BIN_ACC_DWARF 0
#define R_CORE_BIN_ACC_ENTRIES 0
#define R_CORE_BIN_ACC_EXPORTS 0
#define R_CORE_BIN_ACC_FIELDS 0
#define R_CORE_BIN_ACC_HEADER 0
#define R_CORE_BIN_ACC_IMPORTS 0
#define R_CORE_BIN_ACC_INFO 0
#define R_CORE_BIN_ACC_LIBS 0
#define R_CORE_BIN_ACC_MAIN 0
#define R_CORE_BIN_ACC_MEM 0
#define R_CORE_BIN_ACC_RAW_STRINGS 0
#define R_CORE_BIN_ACC_RELOCS 0
#define R_CORE_BIN_ACC_RESOURCES 0
#define R_CORE_BIN_ACC_SECTIONS 0
#define R_CORE_BIN_ACC_SIGNATURE 0
#define R_CORE_BIN_ACC_SIZE 0
#define R_CORE_BIN_ACC_STRINGS 0
#define R_CORE_BIN_ACC_SYMBOLS 0
#define R_CORE_BIN_ACC_VERSIONINFO 0

#define R_CORE_BIN_JSON 1
#define R_CORE_BIN_PRINT 2
#define R_CORE_BIN_RADARE 3
#define R_CORE_BIN_SIMPLE 4
#define R_CORE_BIN_SIMPLEST 5
#define R_CORE_BIN_ARRAY 6

#define PFMT64x "llx"
#define PFMT64d "lld"

#define R_FREE(x) free(x)

static void cmd_info_bin(RCore *core, int va, int mode) {}
static void r_cons_printf(const char *fmt, ...) {}
static void r_cons_print(const char *str) {}
static void r_cons_newline(void) {}
static void eprintf(const char *fmt, ...) {}
static void r_core_cmd_help(RCore *core, const char **help_message) {}
static void r_core_bin_export_info_rad(RCore *core) {}
static void r_core_bin_reload(RCore *core, const char *file, ut64 baddr) {}
static void r_core_block_read(RCore *core) {}
static void r_core_bin_load(RCore *core, const char *file, ut64 baddr) {}
static void r_bin_list_archs(void *bin, int mode) {}
static void r_bin_list_plugin(void *bin, const char *plugin, int json) {}
static void r_bin_list(void *bin, int json) {}
static void playMsg(RCore *core, const char *name, int count) {}
static bool demangle(RCore *core, const char *input) { return false; }
static char *r_core_bin_method_flags_str(RBinSymbol *sym, int mode) { return NULL; }
static void r_core_bin_info(RCore *core, int x, int mode, int va, void *null, const char *y) {}

static int r_config_get_i(void *config, const char *key) { return 0; }
static ut64 r_num_math(void *num, const char *str) { return 0; }
static bool r_num_is_valid_input(void *num, const char *str) { return false; }
static RFlagItem *r_flag_get_at(void *flags, ut64 addr, bool closest) { return NULL; }
static RBinObject *r_bin_cur_object(void *bin) { return NULL; }
static char *sdb_querys(Sdb *db, void *unused, int unused2, const char *cmd) { return NULL; }
static int r_list_length(void *list) { return 0; }
static bool r_list_empty(void *list) { return true; }

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)? ((RList*)(list))->head : NULL; \
         (it) && ((pos) = (it)->data, 1); \
         (it) = (it)->n)