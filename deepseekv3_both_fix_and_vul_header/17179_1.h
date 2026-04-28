#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char ut8;
typedef unsigned short ut16;
typedef unsigned int ut32;

#define R_ASM_BUFSIZE 32
#define R_MIN(x, y) ((x) < (y) ? (x) : (y))
#define R_API

typedef struct r_asm_op_t {
    int size;
    int bitsize;
    char buf_asm[R_ASM_BUFSIZE];
    char buf_hex[R_ASM_BUFSIZE];
    char buf[R_ASM_BUFSIZE];
    int payload;
} RAsmOp;

typedef struct r_io_t {
    int addrbytes;
} RIO;

typedef struct r_core_t {
    RIO *io;
} RCore;

typedef struct r_asm_plugin_t {
    int (*disassemble)(struct r_asm_t *, RAsmOp *, const ut8 *, int);
} RAsmPlugin;

typedef struct r_asm_t {
    int pcalign;
    int pc;
    int bitshift;
    int bits;
    int invhex;
    void *user;
    RAsmPlugin *cur;
    void *ofilter;
} RAsm;

int r_asm_op_get_size(RAsmOp *op);
void r_hex_bin2str(const ut8 *in, int len, char *out);
void r_mem_copybits_delta(ut8 *dst, int dst_offset, const ut8 *src, int src_offset, int nbits);
ut16 r_read_le16(const ut8 *buf);
ut32 r_read_le32(const ut8 *buf);
void r_parse_parse(void *filter, const char *in, char *out);