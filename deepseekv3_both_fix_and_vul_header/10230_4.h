#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#define UT32_MAX UINT32_MAX
#define BFLT_HDR_SIZE 0x40
#define FLAT_FLAG_GOTPIC 0x0002
#define R_BIN_RELOC_32 1

typedef uint32_t ut32;
typedef uint8_t ut8;

typedef struct RBinReloc {
    int type;
    ut32 paddr;
    ut32 vaddr;
} RBinReloc;

typedef struct reloc_struct_t {
    ut32 addr_to_patch;
    ut32 data_offset;
} reloc_struct_t;

typedef struct RList {
    void *head;
    void (*free)(void *);
} RList;

typedef void (*RListFree)(void *);

typedef struct RBinFile {
    struct {
        void *bin_obj;
    } *o;
} RBinFile;

typedef struct r_bin_bflt_hdr {
    ut32 flags;
    ut32 data_start;
    ut32 reloc_count;
    ut32 reloc_start;
    ut32 bss_end;
} r_bin_bflt_hdr;

typedef struct r_bin_bflt_obj {
    r_bin_bflt_hdr *hdr;
    ut32 size;
    void *b;
    int n_got;
    reloc_struct_t *got_table;
    reloc_struct_t *reloc_table;
} r_bin_bflt_obj;

#define VALID_GOT_ENTRY(x) ((x) != 0)

static RList *r_list_newf(RListFree free) {
    RList *list = calloc(1, sizeof(RList));
    if (list) list->free = free;
    return list;
}

static void r_list_free(RList *list) {
    if (list) free(list);
}

static int r_list_append(RList *list, void *data) {
    (void)list; (void)data;
    return 0;
}

static int r_buf_read_at(void *b, ut32 addr, ut8 *buf, int len) {
    (void)b; (void)addr; (void)buf;
    return len;
}

static ut32 r_swap_ut32(ut32 val) {
    return ((val >> 24) & 0xff) | ((val >> 8) & 0xff00) |
           ((val << 8) & 0xff0000) | ((val << 24) & 0xff000000);
}

static void *R_NEW0(size_t size) {
    return calloc(1, size);
}

static void eprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

static int get_ngot_entries(struct r_bin_bflt_obj *obj) {
    (void)obj;
    return 0;
}

#define R_NEW0(type) ((type*)calloc(1,sizeof(type)))