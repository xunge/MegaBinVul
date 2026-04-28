#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char ut8;
typedef unsigned short ut16;
typedef unsigned long long ut64;

typedef struct r_buf_t RBuffer;
typedef struct r_list_t RList;
typedef struct r_list_iter_t RListIter;
typedef struct r_bin_symbol_t RBinSymbol;
typedef struct r_bin_addr_t RBinAddr;
typedef struct ne_header_t ne_header_t;

typedef struct r_bin_ne_obj_t {
    RBuffer *buf;
    ne_header_t *ne_header;
    size_t header_offset;
    RList *symbols;
} r_bin_ne_obj_t;

struct ne_header_t {
    ut16 ResidNamTable;
    ut16 OffStartNonResTab;
};

struct r_bin_symbol_t {
    char *name;
    int paddr;
    const char *bind;
    int ordinal;
};

struct r_bin_addr_t {
    int paddr;
};

RList *r_list_newf(void (*f)(void *));
void r_list_append(RList *list, void *data);
void *r_list_get_n(RList *list, int n);
#define r_list_foreach(list, it, data) \
    for((it) = r_list_iterator(list); (it) && ((data) = r_list_iter_get_data(it)); r_list_iter_next(it))
RListIter *r_list_iterator(RList *list);
void *r_list_iter_get_data(RListIter *iter);
void r_list_iter_next(RListIter *iter);
void *r_list_find(RList *list, const void *user, int (*cmp)(const void *, const void *));

RList *r_bin_ne_get_entrypoints(r_bin_ne_obj_t *bin);
ut8 r_buf_read8_at(RBuffer *buf, ut64 addr);
ut16 r_buf_read_le16_at(RBuffer *buf, ut64 addr);
void r_buf_read_at(RBuffer *buf, ut64 addr, ut8 *buf_out, int len);

#define R_NEW0(x) calloc(1, sizeof(x))
#define R_BIN_BIND_GLOBAL_STR "global"

char *r_str_newf(const char *fmt, ...);
int __find_symbol_by_paddr(const void *a, const void *b);