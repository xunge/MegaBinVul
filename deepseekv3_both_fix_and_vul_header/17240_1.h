#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint64_t ut64;
typedef uint16_t ut16;
typedef uint8_t ut8;

#define UT64_MAX UINT64_MAX

typedef struct r_strbuf_t {
    char *buf;
    void (*init)(struct r_strbuf_t *);
    void (*setf)(struct r_strbuf_t *, const char *, ...);
    void (*set)(struct r_strbuf_t *, const char *);
    char *(*get)(struct r_strbuf_t *);
} RStrBuf;

typedef struct {
    int cycles;
    int size;
    int type;
    int family;
    ut64 ptr;
    ut64 val;
    ut64 jump;
    ut64 fail;
    ut64 addr;
    int nopcode;
    RStrBuf esil;
} RAnalOp;

typedef struct {
    ut16 mask;
    ut16 selector;
    void (*handler)(void *, RAnalOp *, const ut8 *, int, int *, void *);
    const char *name;
    int cycles;
    int size;
    int type;
} OPCODE_DESC;

typedef struct {
    int dummy;
} RAnal;

typedef struct {
    int dummy;
} CPU_MODEL;

enum {
    R_ANAL_OP_TYPE_UNK,
    R_ANAL_OP_FAMILY_UNKNOWN
};

extern OPCODE_DESC opcodes[];

static void r_strbuf_init(RStrBuf *sb) { sb->buf = NULL; }
static void r_strbuf_setf(RStrBuf *sb, const char *fmt, ...) {}
static void r_strbuf_set(RStrBuf *sb, const char *s) {}
static char *r_strbuf_get(RStrBuf *sb) { return sb->buf; }