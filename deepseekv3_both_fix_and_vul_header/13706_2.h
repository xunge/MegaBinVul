#include <stddef.h>

#define SINGLE_BYTE_SIZE 256
#define ONIG_NO_SUPPORT_CONFIG (-1)
#define ONIGERR_PARSER_BUG (-2)

typedef unsigned int OnigCodePoint;
typedef int OnigEncoding;

typedef struct {
    int *bs;
    void *mbuf;
} CClassNode;

typedef struct {
    OnigEncoding enc;
    int options;
} ScanEnv;

#define BITSET_SET_BIT(bs, c) ((bs)[(c)/8] |= (1 << ((c)%8)))
#define ADD_ALL_MULTI_BYTE_RANGE(enc, mbuf)
#define IS_ASCII_MODE_CTYPE_OPTION(ctype, options) (0)
#define ONIGENC_IS_SINGLEBYTE(enc) (1)
#define ONIGENC_CODE_TO_MBCLEN(enc, c) (1)
#define ONIGENC_IS_CODE_CTYPE(enc, c, ctype) (0)
#define ONIGENC_GET_CTYPE_CODE_RANGE(enc, ctype, sb_out, ranges) (0)

enum {
    ONIGENC_CTYPE_ALPHA,
    ONIGENC_CTYPE_BLANK,
    ONIGENC_CTYPE_CNTRL,
    ONIGENC_CTYPE_DIGIT,
    ONIGENC_CTYPE_LOWER,
    ONIGENC_CTYPE_PUNCT,
    ONIGENC_CTYPE_SPACE,
    ONIGENC_CTYPE_UPPER,
    ONIGENC_CTYPE_XDIGIT,
    ONIGENC_CTYPE_ASCII,
    ONIGENC_CTYPE_ALNUM,
    ONIGENC_CTYPE_GRAPH,
    ONIGENC_CTYPE_PRINT,
    ONIGENC_CTYPE_WORD
};

extern int add_ctype_to_cc_by_range(CClassNode*, int, int, OnigEncoding, OnigCodePoint, const OnigCodePoint*);
extern int add_ctype_to_cc_by_range_limit(CClassNode*, int, int, OnigEncoding, OnigCodePoint, const OnigCodePoint*, int);