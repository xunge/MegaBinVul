#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define UT64_MAX UINT64_MAX
#define VTABLE_BUFF_SIZE 32
#define R_ANAL_OP_MASK_BASIC 0
#define R_ANAL_OP_TYPE_MOV 1
#define R_ANAL_OP_TYPE_LEA 2

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct RAnalRef {
    ut64 addr;
} RAnalRef;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
    struct RListIter *p;
} RListIter;

typedef struct RList {
    RListIter *head;
    RListIter *tail;
    unsigned int length;
} RList;

typedef struct RIOBind {
    int (*read_at)(void *io, ut64 addr, ut8 *buf, int len);
    void *io;
} RIOBind;

typedef struct RAnal {
    RIOBind iob;
    void *anal;
} RAnal;

typedef struct RVTableContext {
    RAnal *anal;
} RVTableContext;

typedef struct RAnalOp {
    int type;
} RAnalOp;

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data, 1); (it) = (it)->n)

bool vtable_is_value_in_text_section(RVTableContext *context, ut64 curAddress, void *unused);
bool vtable_addr_in_text_section(RVTableContext *context, ut64 addr);
RList *r_anal_xrefs_get(void *anal, ut64 addr);
bool r_list_empty(RList *list);
void r_list_free(RList *list);
void r_anal_op_fini(RAnalOp *op);
int r_anal_op(void *anal, RAnalOp *op, ut64 addr, ut8 *buf, int len, int mask);