#include <stddef.h>
#include <stdlib.h>

typedef unsigned char UChar;
typedef unsigned int OnigCodePoint;

typedef struct Node Node;
typedef struct PToken PToken;
typedef struct ScanEnv ScanEnv;
typedef struct CClassNode CClassNode;
typedef struct BBuf BBuf;
typedef struct OnigEncodingType OnigEncodingType;
typedef struct OnigSyntaxType OnigSyntaxType;

enum CCSTATE {
    CCS_START,
    CCS_VALUE,
    CCS_RANGE,
    CCS_COMPLETE
};

enum CCVALTYPE {
    CCV_SB,
    CCV_CODE_POINT,
    CCV_CLASS
};

struct PToken {
    int type;
    int escaped;
    int base;
    union {
        OnigCodePoint c;
        OnigCodePoint code;
        struct {
            int ctype;
            int not;
        } prop;
    } u;
    UChar* backp;
};

struct CClassNode {
    BBuf* mbuf;
    unsigned char bs[32];
    int not;
};

struct ScanEnv {
    int parse_depth;
    UChar* pattern_end;
    OnigEncodingType* enc;
    OnigSyntaxType* syntax;
};

#define NULL_NODE NULL
#define ParseDepthLimit 1000
#define ONIGERR_PARSE_DEPTH_LIMIT_OVER 1
#define ONIGERR_EMPTY_CHAR_CLASS 2
#define ONIGERR_TOO_SHORT_MULTI_BYTE_STRING 3
#define ONIGERR_UNMATCHED_RANGE_SPECIFIER_IN_CHAR_CLASS 4
#define ONIGERR_PREMATURE_END_OF_CHAR_CLASS 5
#define ONIGERR_PARSER_BUG 6
#define ONIGENC_CODE_TO_MBC_MAXLEN 16
#define ONIGENC_MBC_MAXLEN(enc) 16
#define ONIGENC_MBC_MINLEN(enc) 1
#define NEWLINE_CODE 0x0a

#define TK_CHAR 0
#define TK_RAW_BYTE 1
#define TK_CODE_POINT 2
#define TK_POSIX_BRACKET_OPEN 3
#define TK_CHAR_TYPE 4
#define TK_CHAR_PROPERTY 5
#define TK_CC_RANGE 6
#define TK_CC_CC_OPEN 7
#define TK_CC_AND 8
#define TK_EOT 9
#define TK_CC_CLOSE 10

#define CCLASS_(n) ((CClassNode*)(n))
#define NCCLASS_SET_NOT(cc) ((cc)->not = 1)
#define NCCLASS_CLEAR_NOT(cc) ((cc)->not = 0)
#define IS_NCCLASS_NOT(cc) ((cc)->not)
#define BITSET_IS_EMPTY(bs, empty) ((empty) = 1)
#define BITSET_SET_BIT(bs, c) ((bs)[(c)/8] |= (1 << ((c)%8)))
#define IS_SYNTAX_BV(syn, flag) (1)
#define ONIG_SYN_NOT_NEWLINE_IN_NEGATIVE_CC 0
#define ONIG_SYN_ALLOW_DOUBLE_RANGE_OP_IN_CC 0
#define IS_NOT_NULL(p) ((p) != NULL)
#define IS_NULL(p) ((p) == NULL)

#define CC_ESC_WARN(env, s) 
#define CHECK_NULL_RETURN_MEMERR(p) if ((p) == NULL) return ONIGERR_PARSER_BUG

static int ONIGENC_CODE_TO_MBCLEN(OnigEncodingType* enc, OnigCodePoint code) { return 1; }
static int ONIGENC_IS_SINGLEBYTE(OnigEncodingType* enc) { return 1; }
static OnigCodePoint ONIGENC_MBC_TO_CODE(OnigEncodingType* enc, const UChar* p, const UChar* end) { return *p; }
static int ONIGENC_IS_CODE_NEWLINE(OnigEncodingType* enc, OnigCodePoint code) { return code == '\n'; }
static int enclen(OnigEncodingType* enc, UChar* buf) { return 1; }