#include <stdint.h>
#include <string.h>
#include <limits.h>

#define BOOL int
#define FALSE 0
#define TRUE 1
#define LINK_SIZE 2
#define REQ_UNSET (-1)
#define REQ_NONE (-2)
#define REQ_VARY 0x4000
#define OP_CBRA 0x90
#define OP_REVERSE 0x91
#define OP_ALT 0x92
#define OP_KET 0x93
#define OP_END 0x94
#define OP_ONCE 0x95
#define PCRE_UTF8 0x80000000
#define ERR20 20
#define ERR25 25
#define ERR36 36
#define ERR70 70
#define OFLOW_MAX INT_MAX
#define CHAR_VERTICAL_LINE '|'
#define IN_UCHARS(x) (x)
#define GET(ptr, offset) (*(ptr + offset))
#define PUT(ptr, offset, value) (*(ptr + offset) = value)
#define PUTINC(ptr, offset, value) (*(ptr + offset) = value, ptr += offset + 1)
#define GET2(ptr, offset) (*(uint16_t*)(ptr + offset))
#define DPRINTF(x)

typedef unsigned char pcre_uchar;
typedef uint32_t pcre_uint32;
typedef int32_t pcre_int32;

typedef struct branch_chain {
    struct branch_chain *outer;
    pcre_uchar *current_branch;
} branch_chain;

typedef struct open_capitem {
    int number;
    struct open_capitem *next;
    BOOL flag;
} open_capitem;

typedef struct compile_data {
    unsigned int bracount;
    unsigned int max_lookbehind;
    BOOL check_lookbehind;
    open_capitem *open_caps;
} compile_data;