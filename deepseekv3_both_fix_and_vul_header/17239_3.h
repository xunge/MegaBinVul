#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define R_FLAG_NAME_SIZE 256
#define UT64_MAX UINT64_MAX
#define PFMT64x "llx"
#define PFMT64d "lld"

#define IS_MODE_RAD(mode) ((mode) == 1)
#define IS_MODE_JSON(mode) ((mode) == 2)
#define IS_MODE_NORMAL(mode) ((mode) == 3)
#define IS_MODE_SET(mode) ((mode) == 4)
#define IS_MODE_SIMPLE(mode) ((mode) == 5)

#define R_CORE_BIN_SET 0

typedef uint64_t ut64;

typedef struct RBinAddr {
    ut64 paddr;
    ut64 vaddr;
    ut64 haddr;
    int type;
} RBinAddr;

typedef struct RListIter {
    struct RListIter *n;
    void *p;
    RBinAddr *data;
} RListIter;

typedef struct RList {
    RListIter *head;
} RList;

typedef struct RBin {
    void *unused;
} RBin;

typedef struct RFlag {
    void *unused;
} RFlag;

typedef struct RIO {
    bool va;
    void *unused;
} RIO;

typedef struct RIOMap {
    struct {
        ut64 addr;
    } itv;
    ut64 delta;
} RIOMap;

typedef struct RCons {
    void *unused;
} RCons;

typedef struct RCore {
    RBin *bin;
    RFlag *flags;
    RIO *io;
    RCons *cons;
} RCore;

enum RBinEntryType {
    R_BIN_ENTRY_TYPE_PROGRAM,
    R_BIN_ENTRY_TYPE_INIT,
    R_BIN_ENTRY_TYPE_FINI,
    R_BIN_ENTRY_TYPE_PREINIT
};

static RList *r_bin_get_entries(RBin *bin) { return NULL; }
static ut64 r_bin_get_baddr(RBin *bin) { return 0; }
static void r_cons_printf(const char *fmt, ...) {}
static void r_cons_newline(void) {}
static void r_flag_space_set(RFlag *flags, const char *name) {}
static void r_flag_set(RFlag *flags, const char *name, ut64 addr, int size) {}
static RIOMap *r_io_map_get(RIO *io, ut64 addr) { return NULL; }
static void r_core_seek(RCore *core, ut64 addr, int type) {}
static char *r_str_newf(const char *fmt, ...) { return NULL; }
static const char *r_bin_entry_type_string(int type) { return NULL; }
static ut64 rva(RBin *bin, ut64 paddr, ut64 vaddr, int va) { return 0; }

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data); (it) = (it)->n)