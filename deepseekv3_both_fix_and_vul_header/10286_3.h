#include <stdlib.h>
#include <stddef.h>

typedef unsigned int ut32;
typedef unsigned char ut8;

typedef struct RList RList;
typedef void (*RListFree)(void *);

struct RList {
    void *head;
    void *tail;
    RListFree free;
};

struct RBinWasmBuffer {
    ut8 *buf;
    ut32 length;
};

struct RBinWasmSection {
    ut32 payload_len;
    ut32 payload_data;
    ut32 count;
};

struct RBinWasmDataEntry {
    ut32 index;
    ut32 size;
    struct {
        size_t len;
    } offset;
    ut8 *data;
};

struct RBinWasmObj {
    struct RBinWasmBuffer *buf;
};

typedef struct RBinWasmObj RBinWasmObj;
typedef struct RBinWasmSection RBinWasmSection;
typedef struct RBinWasmDataEntry RBinWasmDataEntry;

#define R_NEW0(x) calloc(1, sizeof(x))
#define R_BIN_WASM_END_OF_CODE 0x0B

RList *r_list_newf(RListFree f);
void r_list_append(RList *list, void *data);
int consume_u32(ut8 *buf, ut8 *buf_end, ut32 *val, ut32 *i);
size_t consume_init_expr(ut8 *buf, ut8 *buf_end, ut32 end, void *null, ut32 *i);