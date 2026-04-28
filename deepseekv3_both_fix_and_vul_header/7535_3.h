#include <stdlib.h>
#include <string.h>

typedef unsigned short ut16;
typedef unsigned int ut32;
typedef unsigned long long ut64;
typedef unsigned char ut8;

typedef struct r_buf_t {
    // minimal buffer implementation
    ut8 *buf;
    size_t length;
} RBuffer;

typedef struct r_list_iter_t {
    void *data;
    struct r_list_iter_t *n;
} RListIter;

typedef struct r_list_t {
    RListIter *head;
    RListIter *tail;
    size_t length;
} RList;

typedef struct r_bin_section_t {
    char *name;
    ut64 paddr;
    ut64 size;
} RBinSection;

typedef struct r_bin_reloc_t {
    ut64 paddr;
    int type;
    ut64 addend;
    int additive;
    void *import;
    void *symbol;
} RBinReloc;

typedef struct r_bin_import_t {
    char *name;
    ut16 ordinal;
} RBinImport;

typedef struct r_bin_addr_t {
    ut64 paddr;
} RBinAddr;

typedef struct r_bin_symbol_t {
    ut64 paddr;
    char *name;
} RBinSymbol;

typedef struct NE_image_header {
    ut16 ModRefs;
    ut16 ModRefTable;
    ut16 ImportNameTable;
} NE_image_header;

typedef struct NE_segment_entry {
    ut16 flags;
} NE_segment_entry;

typedef struct NE_image_reloc_item {
    ut8 type;
    ut8 flags;
    ut16 offset;
    ut16 segnum;
    ut16 segoff;
    ut16 index;
    ut16 func_ord;
    ut16 name_off;
    ut16 entry_ordinal;
} NE_image_reloc_item;

typedef struct r_bin_ne_obj_t {
    RList *segments;
    RList *entries;
    RList *symbols;
    RBuffer *buf;
    NE_image_header *ne_header;
    NE_segment_entry *segment_entries;
    ut64 header_offset;
} r_bin_ne_obj_t;

enum {
    RELOCINFO = 1,
    IMPORTED_ORD = 2,
    IMPORTED_NAME = 4,
    OSFIXUP = 8,
    ADDITIVE = 16
};

enum {
    LOBYTE,
    SEL_16,
    OFF_16,
    POI_32,
    OFF_32,
    POI_48
};

enum {
    R_BIN_RELOC_8,
    R_BIN_RELOC_16,
    R_BIN_RELOC_32,
    R_BIN_RELOC_64
};

#define R_NEW0(x) calloc(1, sizeof(x))
#define r_list_newf(x) ((RList*)calloc(1, sizeof(RList)))
#define r_list_append(x, y) 
#define r_list_get_n(x, y) NULL
#define r_buf_read_at(x, y, z, w) 
#define r_buf_read_le16_at(x, y) 0
#define __read_nonnull_str_at(x, y) strdup("")
#define __func_name_from_ord(x, y) strdup("")
#define r_str_newf(x, ...) strdup("")

#define r_list_foreach(list, it, ptr) \
    for ((it) = (list)->head; (it) && ((ptr) = (it)->data); (it) = (it)->n)