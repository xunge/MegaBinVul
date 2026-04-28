#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define R_STRING_SCAN_BUFFER_SIZE 1024
#define R_STRING_TYPE_DETECT -1
#define R_STRING_TYPE_ASCII 0
#define R_STRING_TYPE_UTF8 1
#define R_STRING_TYPE_WIDE 2
#define R_STRING_TYPE_WIDE32 3
#define R_STRING_MAX_UNI_BLOCKS 8
#define ST32_MAX 0x7FFFFFFF
#define UT64_MAX 0xFFFFFFFFFFFFFFFFULL
#define PFMT64x "lx"
#define PFMT64d "ld"
#define R_MODE_JSON 0

typedef uint64_t ut64;
typedef int64_t st64;
typedef uint32_t ut32;
typedef uint8_t ut8;

typedef struct RList {
    // minimal definition
} RList;

typedef struct RIO {
    void (*cb_printf)(const char *fmt, ...);
} RIO;

typedef struct RBinString {
    int type;
    int length;
    ut64 size;
    int ordinal;
    ut64 paddr;
    ut64 vaddr;
    char *string;
} RBinString;

typedef struct RBinSection {
    ut64 vaddr;
    ut64 paddr;
} RBinSection;

typedef struct RBuffer {
    // minimal definition
} RBuffer;

typedef struct RIOBind {
    RIO *io;
} RIOBind;

typedef struct RConsBind {
    bool (*is_breaked)(void);
} RConsBind;

typedef struct RBinObject {
    ut64 baddr;
    void *strings_db;
} RBinObject;

typedef struct RBin {
    RConsBind consb;
    RIOBind iob;
} RBin;

typedef struct RBinFile {
    RBin *rbin;
    RBuffer *buf;
    int strmode;
    RBinObject *o;
    ut64 loadaddr;
    ut64 size;
} RBinFile;

typedef struct PJ {
    // minimal definition
} PJ;

typedef struct RCharset {
    // minimal definition
} RCharset;

typedef ut32 RRune;

typedef bool (*RConsIsBreaked)(void);

#define r_return_val_if_fail(cond, ret) if (!(cond)) return (ret)
#define IS_PRINTABLE(c) (c >= 32 && c <= 126)
#define R_STR_ISEMPTY(s) (!(s) || !*(s))
#define r_isprint(c) ((c) >= 32 && (c) < 127)
#define R_NEW0(type) ((type *)calloc(1, sizeof(type)))

#define eprintf(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#define r_sys_getenv(name) getenv(name)

static ut32 r_read_le32(const ut8 *buf) {
    return buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
}

static int r_utf8_decode(const ut8 *ptr, int ptrlen, RRune *ch) {
    if (ptrlen < 1) return 0;
    if (ch) *ch = ptr[0];
    return 1;
}

static int r_utf16le_decode(const ut8 *ptr, int ptrlen, RRune *ch) {
    if (ptrlen < 2) return 0;
    if (ch) *ch = ptr[0] | (ptr[1] << 8);
    return 2;
}

static int r_utf32le_decode(const ut8 *ptr, int ptrlen, RRune *ch) {
    if (ptrlen < 4) return 0;
    if (ch) *ch = ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24);
    return 4;
}

static int r_utf8_encode(ut8 *ptr, RRune ch) {
    ptr[0] = ch;
    return 1;
}

static int *r_utf_block_list(const ut8 *str, int len, int **freq_list) {
    static int blocks[2] = {0, -1};
    if (freq_list) *freq_list = NULL;
    return blocks;
}

static RCharset *r_charset_new(void) {
    return calloc(1, sizeof(RCharset));
}

static void r_charset_free(RCharset *cs) {
    free(cs);
}

static bool r_charset_use(RCharset *cs, const char *charset) {
    return false;
}

static int r_charset_encode_str(RCharset *cs, ut8 *out, int outlen, const ut8 *in, int inlen) {
    return 0;
}

static char *r_str_ndup(const char *ptr, int len) {
    char *out = malloc(len + 1);
    if (out) {
        memcpy(out, ptr, len);
        out[len] = 0;
    }
    return out;
}

static void r_bin_string_free(RBinString *bs) {
    if (bs) {
        free(bs->string);
        free(bs);
    }
}

static void print_string(RBinFile *bf, RBinString *bs, int raw, PJ *pj) {
    // minimal implementation
}

static RBinSection *r_bin_get_section_at(RBinFile *bf, ut64 addr, bool vaddr) {
    return NULL;
}

static void ht_up_insert(void *ht, ut64 key, void *value) {
    // minimal implementation
}

static void r_list_append(RList *list, void *item) {
    // minimal implementation
}

static PJ *pj_new(void) {
    return calloc(1, sizeof(PJ));
}

static void pj_a(PJ *pj) {
    // minimal implementation
}

static void pj_end(PJ *pj) {
    // minimal implementation
}

static char *pj_string(PJ *pj) {
    return strdup("");
}

static void pj_free(PJ *pj) {
    free(pj);
}

static int r_buf_read_at(RBuffer *buf, ut64 addr, ut8 *data, int len) {
    return 0;
}