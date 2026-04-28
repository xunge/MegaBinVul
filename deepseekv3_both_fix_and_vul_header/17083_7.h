#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint64_t mach0_ut;
typedef uint32_t ut32;
typedef uint8_t ut8;
typedef uint64_t ut64;

struct SIVarList {
    ut32 entsize;
    ut32 count;
};

struct SIVar {
    mach0_ut offset;
    mach0_ut name;
    mach0_ut type;
    ut32 alignment;
    ut32 size;
};

struct obj_t {
    bool has_crypto;
};

struct RBinFileInfo {
    bool big_endian;
};

struct RBinObject {
    struct obj_t *bin_obj;
    struct RBinFileInfo *info;
};

struct RBinFile {
    struct RBinObject *o;
    size_t size;
    void *buf;
};

struct RBinField {
    char *name;
    char *type;
    mach0_ut vaddr;
};

struct RBinClass {
    char *name;
    void *fields;
};

typedef struct RBinFile RBinFile;
typedef struct RBinClass RBinClass;
typedef struct RBinField RBinField;

#define MACH0_(x) x
#define eprintf(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define R_NEW0(type) calloc(1, sizeof(type))
#define R_FREE(ptr) free(ptr)
#define r_str_newf(fmt, ...) ({ \
    char *buf; \
    int len = asprintf(&buf, fmt, ##__VA_ARGS__); \
    (len == -1) ? NULL : buf; \
})

static mach0_ut get_pointer(mach0_ut p, ut32 *offset, ut32 *left, RBinFile *bf) { return 0; }
static int r_buf_read_at(void *buf, mach0_ut addr, ut8 *dst, size_t len) { return 0; }
static ut64 r_read_ble(const ut8 *buf, bool big_endian, int size) { return 0; }
static void r_bin_field_free(RBinField *field) { free(field->name); free(field->type); free(field); }
static void r_list_append(void *list, void *item) {}