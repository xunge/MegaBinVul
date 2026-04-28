#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef uint64_t ut64;

typedef struct RList RList;
typedef struct RListIter RListIter;
typedef struct RIOMap RIOMap;
typedef struct RIOMapRef RIOMapRef;
typedef struct RIOBank RIOBank;
typedef struct RIODesc RIODesc;
typedef struct RIO RIO;
typedef struct RBin RBin;
typedef struct RBinObject RBinObject;

struct r_bin_coff_obj {
    struct {
        unsigned int f_flags;
        int f_nsyms;
    } hdr;
    struct {
        int n_numaux;
    } *symbols;
};

struct RIO {
    unsigned int cached;
    int bank;
    RIODesc *desc;
    RIOBank* (*bank_get)(RIO*, int);
    RIOMap* (*map_get)(RIO*, int);
    RIOMap* (*map_get_at)(RIO*, ut64);
    RIODesc* (*open_at)(RIO*, const char*, int, int, ut64);
};

struct RIOBank {
    RList *maprefs;
};

struct RIOMap {
    char *name;
    ut64 (*end)(RIOMap*);
};

struct RIOMapRef {
    int id;
};

struct RListIter {
    void *data;
    RListIter *n;
};

struct RList {
    RListIter *head;
};

struct RBin {
    struct {
        RIO *io;
        RIOBank* (*bank_get)(RIO*, int);
        RIOMap* (*map_get)(RIO*, int);
        RIOMap* (*map_get_at)(RIO*, ut64);
        RIODesc* (*open_at)(RIO*, const char*, int, int, ut64);
    } iob;
};

struct RBinObject {
    void *bin_obj;
};

struct RIODesc {
    // dummy structure
};

#define COFF_FLAGS_TI_F_EXEC 0x0002
#define R_PERM_W 0x02
#define R_PERM_R 0x04
#define UT64_MAX UINT64_MAX
#define BYTES_PER_IMP_RELOC 8
#define PFMT64u "lu"
#define R_ROUND(x, y) (((x) + (y)-1) & ~((y)-1))

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define r_list_foreach(list, iter, mapref) for(iter = (list)->head; iter; iter = iter->n) { mapref = (RIOMapRef*)iter->data; }

static RIOBank* bank_get(RIO* io, int bank) { return NULL; }
static RIOMap* map_get(RIO* io, int id) { return NULL; }
static RIOMap* map_get_at(RIO* io, ut64 addr) { return NULL; }
static RIODesc* open_at(RIO* io, const char* uri, int perm, int mode, ut64 addr) { return NULL; }
static int is_imported_symbol(void *sym) { return 0; }
static RList *_relocs_list(RBin *b, struct r_bin_coff_obj *bin, bool flag, ut64 addr) { return NULL; }
static RBinObject *r_bin_cur_object(RBin *b) { return NULL; }
static char *r_str_newf(const char *fmt, ...) { return NULL; }
static ut64 r_io_map_end(RIOMap *map) { return 0; }