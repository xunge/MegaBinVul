#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char ut8;
typedef unsigned short ut16;
typedef unsigned int ut32;

#define R_ASM_BUFSIZE 32
#define R_MIN(x, y) ((x) < (y) ? (x) : (y))

struct r_io_t {
    int addrbytes;
};
typedef struct r_io_t RIO;

struct r_core_t {
    RIO *io;
};
typedef struct r_core_t RCore;

struct r_parse_t {
    void (*parse)(struct r_parse_t *, char *, char *);
};
typedef struct r_parse_t RParse;

struct r_asm_op_t {
    int size;
    int bitsize;
    int payload;
    char buf_asm[32];
    char buf_hex[64];
    ut8 buf[R_ASM_BUFSIZE];
};
typedef struct r_asm_op_t RAsmOp;

struct r_asm_t {
    int pcalign;
    int pc;
    int bitshift;
    int bits;
    int invhex;
    struct r_asm_plugin_t *cur;
    RParse *ofilter;
    void *user;
};
typedef struct r_asm_t RAsm;

struct r_asm_plugin_t {
    int (*disassemble)(RAsm *, RAsmOp *, const ut8 *, int);
};
typedef struct r_asm_plugin_t RAsmPlugin;

int r_asm_op_get_size(RAsmOp *op);
void r_hex_bin2str(const ut8 *in, int len, char *out);
void r_mem_copybits_delta(ut8 *dst, int doff, const ut8 *src, int soff, int bits);
ut16 r_read_le16(const ut8 *buf);
ut32 r_read_le32(const ut8 *buf);
void r_parse_parse(RParse *p, char *str, char *out);

#define R_API