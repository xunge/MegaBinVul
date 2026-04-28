#include <stdint.h>
#include <string.h>

typedef union VALUETYPE {
    uint8_t b;
    int16_t h;
    uint16_t hs[2];
    int32_t l;
    uint32_t hl[4];
    int64_t q;
    uint64_t hq[8];
    float f;
    double d;
    char s[256];
} VALUETYPE;

struct magic_set {
    VALUETYPE ms_value;
};

struct magic {
    int type;
};

enum {
    FILE_BYTE,
    FILE_SHORT,
    FILE_LONG,
    FILE_DATE,
    FILE_LDATE,
    FILE_QUAD,
    FILE_QDATE,
    FILE_QLDATE,
    FILE_STRING,
    FILE_BESTRING16,
    FILE_LESTRING16,
    FILE_PSTRING,
    FILE_BESHORT,
    FILE_BELONG,
    FILE_BEDATE,
    FILE_BELDATE,
    FILE_BEQUAD,
    FILE_BEQDATE,
    FILE_BEQLDATE,
    FILE_LESHORT,
    FILE_LELONG,
    FILE_LEDATE,
    FILE_LELDATE,
    FILE_LEQUAD,
    FILE_LEQDATE,
    FILE_LEQLDATE,
    FILE_MELONG,
    FILE_MEDATE,
    FILE_MELDATE,
    FILE_FLOAT,
    FILE_BEFLOAT,
    FILE_LEFLOAT,
    FILE_DOUBLE,
    FILE_BEDOUBLE,
    FILE_LEDOUBLE,
    FILE_REGEX,
    FILE_SEARCH,
    FILE_DEFAULT
};

int cvt_8(VALUETYPE *p, struct magic *m);
int cvt_16(VALUETYPE *p, struct magic *m);
int cvt_32(VALUETYPE *p, struct magic *m);
int cvt_64(VALUETYPE *p, struct magic *m);
int cvt_float(VALUETYPE *p, struct magic *m);
int cvt_double(VALUETYPE *p, struct magic *m);
size_t file_pstring_length_size(struct magic *m);
size_t file_pstring_get_length(struct magic *m, char *ptr);
void file_magerror(struct magic_set *ms, const char *fmt, ...);

#define private static