#include <stdlib.h>
#include <stdint.h>

typedef struct RList RList;
typedef void (*RListFree)(void *);

typedef struct {
    uint8_t *buf;
    size_t length;
} RBinWasmBuffer;

typedef struct {
    uint32_t payload_data;
    uint32_t payload_len;
    uint32_t count;
} RBinWasmSection;

typedef struct {
    RBinWasmBuffer *buf;
} RBinWasmObj;

typedef struct {
    uint8_t content_type;
    uint8_t mutability;
    // Add other fields as needed
} RBinWasmGlobalEntry;

typedef uint8_t ut8;
typedef uint32_t ut32;

#define R_NEW0(x) calloc(1, sizeof(x))
#define R_BIN_WASM_END_OF_CODE 0

RList *r_list_newf(RListFree f);
void r_list_append(RList *list, void *data);

int consume_u8(ut8 *buf, ut8 *buf_end, ut8 *val, ut32 *i);
int consume_init_expr(ut8 *buf, ut8 *buf_end, ut8 end, void *res, ut32 *i);