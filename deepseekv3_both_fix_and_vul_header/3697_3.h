#include <stdint.h>
#include <string.h>

typedef union VALUETYPE {
    char s[256];
    int8_t b;
    uint8_t ub;
    int16_t h;
    uint16_t uh;
    int32_t l;
    uint32_t ul;
    int64_t q;
    uint64_t uq;
    uint8_t hs[2];
    uint8_t hl[4];
    uint8_t hq[8];
    float f;
    double d;
} VALUETYPE;

struct magic_set {
    VALUETYPE ms_value;
};

struct magic {
    int type;
};

#define FILE_BYTE 0
#define FILE_SHORT 1
#define FILE_LONG 2
#define FILE_DATE 3
#define FILE_LDATE 4
#define FILE_QUAD 5
#define FILE_QDATE 6
#define FILE_QLDATE 7
#define FILE_QWDATE 8
#define FILE_STRING 9
#define FILE_BESTRING16 10
#define FILE_LESTRING16 11
#define FILE_PSTRING 12
#define FILE_BESHORT 13
#define FILE_BELONG 14
#define FILE_BEDATE 15
#define FILE_BELDATE 16
#define FILE_BEQUAD 17
#define FILE_BEQDATE 18
#define FILE_BEQLDATE 19
#define FILE_BEQWDATE 20
#define FILE_LESHORT 21
#define FILE_LELONG 22
#define FILE_LEDATE 23
#define FILE_LELDATE 24
#define FILE_LEQUAD 25
#define FILE_LEQDATE 26
#define FILE_LEQLDATE 27
#define FILE_LEQWDATE 28
#define FILE_MELONG 29
#define FILE_MEDATE 30
#define FILE_MELDATE 31
#define FILE_FLOAT 32
#define FILE_BEFLOAT 33
#define FILE_LEFLOAT 34
#define FILE_DOUBLE 35
#define FILE_BEDOUBLE 36
#define FILE_LEDOUBLE 37
#define FILE_REGEX 38
#define FILE_SEARCH 39
#define FILE_DEFAULT 40
#define FILE_CLEAR 41
#define FILE_NAME 42
#define FILE_USE 43

static int cvt_flip(int type, int flip) { return type; }
static void cvt_8(VALUETYPE *p, struct magic *m) {}
static void cvt_16(VALUETYPE *p, struct magic *m) {}
static void cvt_32(VALUETYPE *p, struct magic *m) {}
static void cvt_64(VALUETYPE *p, struct magic *m) {}
static void cvt_float(VALUETYPE *p, struct magic *m) {}
static void cvt_double(VALUETYPE *p, struct magic *m) {}
static size_t file_pstring_length_size(struct magic *m) { return 0; }
static size_t file_pstring_get_length(struct magic *m, char *ptr) { return 0; }
static void file_magerror(struct magic_set *ms, const char *fmt, ...) {}

#define private static