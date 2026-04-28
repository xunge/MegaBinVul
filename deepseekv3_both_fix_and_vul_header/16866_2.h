#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned long long ut64;
typedef unsigned char ut8;

typedef enum {
    R_ARCH_OP_MASK_DISASM = 1
} RArchDecodeMask;

typedef struct RArchSession {
    struct RArch *arch;
} RArchSession;

typedef struct RAnalOp {
    ut8 *bytes;
    int size;
    ut64 addr;
    ut64 jump;
    ut64 fail;
    int id;
    int type;
    struct {
        void (*init)(void *);
        void (*set)(void *, const char *);
        void (*setf)(void *, const char *, ...);
    } esil;
} RAnalOp;

typedef struct RArch {
    struct {
        struct RBin *bin;
    } binb;
} RArch;

typedef struct RBin {
    struct {
        void *io;
        size_t (*read_at)(void *io, ut64 addr, ut8 *buf, size_t len);
    } iob;
} RBin;

typedef size_t (*RIOReadAt)(void *io, ut64 addr, ut8 *buf, size_t len);

enum {
    R_ANAL_OP_TYPE_CJMP,
    R_ANAL_OP_TYPE_UJMP,
    R_ANAL_OP_TYPE_ADD,
    R_ANAL_OP_TYPE_SUB,
    R_ANAL_OP_TYPE_STORE,
    R_ANAL_OP_TYPE_LOAD,
    R_ANAL_OP_TYPE_TRAP,
    R_ANAL_OP_TYPE_NOP,
    R_ANAL_OP_TYPE_ILL
};

#define R_UNWRAP2(a, b) ((a)->b)
#define BUFSIZE_INC 256

static void r_strbuf_init(void *esil) {}
static void r_strbuf_set(void *esil, const char *str) {}
static void r_strbuf_setf(void *esil, const char *fmt, ...) {}
static int countChar(const ut8 *buf, int len, char c) { return 0; }
static int disassemble(RAnalOp *op, const ut8 *buf, int len) { return 0; }
static int getid(ut8 byte) { return 0; }