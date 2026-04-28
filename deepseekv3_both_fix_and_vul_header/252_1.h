#include <stdlib.h>
#include <string.h>

#define R_API 

typedef unsigned long long ut64;
typedef unsigned char ut8;

typedef struct RStrBuf RStrBuf;
typedef struct RCore RCore;
typedef struct RAsm RAsm;
typedef struct RAsmOp RAsmOp;
typedef struct RAsmCode RAsmCode;

#define r_return_val_if_fail(cond, val) if (cond) {} else return val

struct RAsm {
    ut64 pc;
    void *user;
    void *ofilter;
};

struct RAsmCode {
    char *assembly;
    ut8 *bytes;
    int len;
};

struct RStrBuf {
    char *buf;
};

struct RAsmOp {
    RStrBuf buf_asm;
};

struct RCore {
    struct {
        int addrbytes;
    } *io;
};

RAsmCode* r_asm_code_new(void);
void* r_asm_code_free(RAsmCode*);
RStrBuf* r_strbuf_new(const char*);
char* r_strbuf_get(RStrBuf*);
void r_strbuf_append(RStrBuf*, const char*);
char* r_strbuf_drain(RStrBuf*);
void r_asm_set_pc(RAsm*, ut64);
int r_asm_disassemble(RAsm*, RAsmOp*, const ut8*, int);
void r_parse_parse(void*, char*, char*);