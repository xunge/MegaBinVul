#include <stdlib.h>
#include <string.h>

typedef unsigned short ut16;
typedef unsigned int ut32;
typedef unsigned long long ut64;
typedef unsigned char ut8;

typedef struct r_buf_t {
    size_t (*read_at)(struct r_buf_t *buf, ut64 addr, ut8 *data, size_t len);
    size_t (*read_le16_at)(struct r_buf_t *buf, ut64 addr);
    size_t (*size)(struct r_buf_t *buf);
} r_buf_t;

typedef struct RList {
    void *head;
    void (*free)(void *ptr);
} RList;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
} RListIter;

typedef struct RBinSection {
    char *name;
    ut32 paddr;
    ut32 size;
} RBinSection;

typedef struct RBinReloc {
    ut32 paddr;
    int type;
    ut32 addend;
    int additive;
    void *import;
    void *symbol;
} RBinReloc;

typedef struct RBinImport {
    char *name;
    int ordinal;
} RBinImport;

typedef struct RBinAddr {
    ut32 paddr;
} RBinAddr;

typedef struct RBinSymbol {
    ut32 paddr;
} RBinSymbol;

typedef struct NE_image_reloc_item {
    ut8 type;
    ut8 flags;
    ut16 segnum;
    ut16 offset;
    ut16 segoff;
    ut16 entry_ordinal;
    ut16 func_ord;
    ut16 name_off;
    ut16 index;
} NE_image_reloc_item;

typedef struct NE_header {
    ut16 ModRefs;
    ut16 ModRefTable;
    ut16 ImportNameTable;
} NE_header;

typedef struct r_bin_ne_obj_t {
    RList *segments;
    RList *entries;
    RList *symbols;
    NE_header *ne_header;
    r_buf_t *buf;
    ut32 header_offset;
    struct {
        int flags;
    } *segment_entries;
} r_bin_ne_obj_t;

enum {
    LOBYTE,
    SEL_16,
    OFF_16,
    POI_32,
    OFF_32,
    POI_48
};

enum {
    IMPORTED_ORD = 1,
    IMPORTED_NAME = 2,
    OSFIXUP = 4,
    ADDITIVE = 8,
    RELOCINFO = 1
};

enum {
    R_BIN_RELOC_8,
    R_BIN_RELOC_16,
    R_BIN_RELOC_32,
    R_BIN_RELOC_64
};

#define R_NEW0(x) calloc(1, sizeof(x))

static size_t r_buf_read_at(r_buf_t *buf, ut64 addr, ut8 *data, size_t len) {
    return buf->read_at(buf, addr, data, len);
}

static size_t r_buf_read_le16_at(r_buf_t *buf, ut64 addr) {
    return buf->read_le16_at(buf, addr);
}

static size_t r_buf_size(r_buf_t *buf) {
    return buf->size(buf);
}

static RList *r_list_newf(void (*free)(void *)) {
    RList *list = malloc(sizeof(RList));
    if (list) {
        list->head = NULL;
        list->free = free;
    }
    return list;
}

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data, 1); (it) = (it)->n)