#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define R_API
#define R_MAX(a,b) ((a)>(b)?(a):(b))
#define R_MIN(a,b) ((a)<(b)?(a):(b))

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;

typedef struct RAsmPlugin {
    int (*disassemble)(void *a, void *op, const ut8 *buf, int len);
} RAsmPlugin;

typedef struct {
    char *data;
} RStrBuf;

typedef struct {
    int size;
    int bitsize;
    int payload;
    RStrBuf buf_asm;
} RAsmOp;

typedef struct {
    int pc;
    int pcalign;
    int bitshift;
    int bits;
    int invhex;
    RAsmPlugin *cur;
    void *ofilter;
} RAsm;

int r_asm_op_init(RAsmOp *op);
int r_return_val_if_fail(int condition, int retval);
void r_asm_op_set_asm(RAsmOp *op, const char *asm_str);
void r_strbuf_set(RStrBuf *buf, const char *str);
char *r_strbuf_get(RStrBuf *buf);
void r_mem_copybits_delta(void *dst, int dst_delta, const void *src, int src_delta, int len);
ut16 r_read_le16(const ut8 *buf);
ut32 r_read_le32(const ut8 *buf);
char *sdb_fmt(const char *fmt, ...);
void r_parse_parse(void *filter, const char *input, char *output);
void r_asm_op_set_buf(RAsmOp *op, const ut8 *buf, int len);
int isInvalid(RAsmOp *op);