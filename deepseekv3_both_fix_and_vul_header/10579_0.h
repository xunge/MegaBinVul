#include <stdlib.h>

typedef unsigned int OnigCodePoint;

typedef struct {
    int* bs;
    void* mbuf;
} CClassNode;

typedef struct {
    // dummy definition since actual contents are not used in the function
} ScanEnv;

enum CCVALTYPE {
    CCV_CLASS,
    CCV_SB,
    CCV_CODE_POINT
};

enum CCSTATE {
    CCS_START,
    CCS_VALUE,
    CCS_RANGE
};

#define ONIGERR_CHAR_CLASS_VALUE_AT_END_OF_RANGE -1

#define BITSET_SET_BIT(bs, pos) ((bs)[(pos) / 8] |= (1 << ((pos) % 8)))

static int add_code_range(void** mbuf, ScanEnv* env, OnigCodePoint from, OnigCodePoint to);