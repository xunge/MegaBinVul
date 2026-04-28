#include <stddef.h>

typedef unsigned int OnigCodePoint;

typedef struct {
    int syntax;
} ScanEnv;

typedef struct {
    unsigned char* bs;
    void* mbuf;
} CClassNode;

enum CCVALTYPE {
    CCV_SB,
    CCV_CODE_POINT
};

enum CCSTATE {
    CCS_VALUE,
    CCS_RANGE,
    CCS_COMPLETE,
    CCS_START
};

#define BITSET_SET_BIT(bs, pos) ((bs)[(pos) / 8] |= (1 << ((pos) % 8)))
#define IS_SYNTAX_BV(syn, opt) ((syn) & (opt))
#define ONIG_SYN_ALLOW_EMPTY_RANGE_IN_CC (1<<0)

#define ONIGERR_INVALID_CODE_POINT_VALUE 1
#define ONIGERR_EMPTY_RANGE_IN_CHAR_CLASS 2
#define ONIGERR_MISMATCH_CODE_LENGTH_IN_CLASS_RANGE 3

static int add_code_range(void** mbuf, ScanEnv* env, OnigCodePoint from, OnigCodePoint to);
static void bitset_set_range(unsigned char* bs, int from, int to);