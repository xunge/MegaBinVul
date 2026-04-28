#include <stdlib.h>
#include <stdint.h>

typedef uint8_t ut8;
typedef uint32_t ut32;

typedef struct RList RList;
typedef void (*RListFree)(void *);

typedef struct RBinWasmObj RBinWasmObj;
typedef struct RBinWasmSection RBinWasmSection;
typedef struct RBinWasmElementEntry RBinWasmElementEntry;

struct RBinWasmObj {
    struct {
        ut8 *buf;
        int length;
    } *buf;
};

struct RBinWasmSection {
    ut32 payload_data;
    ut32 payload_len;
    ut32 count;
};

struct RBinWasmElementEntry {
    ut32 index;
    ut32 num_elem;
};

#define R_NEW0(x) calloc(1, sizeof(x))
#define R_BIN_WASM_END_OF_CODE 0x0B

RList *r_list_newf(RListFree);
void r_list_append(RList *, void *);
int consume_u32(ut8 *, ut8 *, ut32 *, ut32 *);
int consume_init_expr(ut8 *, ut8 *, ut32, void *, ut32 *);