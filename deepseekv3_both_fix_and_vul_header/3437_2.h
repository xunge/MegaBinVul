#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define private static

typedef union VALUETYPE {
    uint8_t b;
    int16_t h;
    uint8_t hs[2];
    int32_t l;
    uint8_t hl[4];
} VALUETYPE;

struct magic_set {
    uint32_t offset;
    VALUETYPE ms_value;
    unsigned int flags;
    struct {
        char *buf;
    } o;
    struct {
        struct {
            uint32_t off;
        } li[20];
    } c;
};

struct magic {
    uint32_t str_range;
    int type;
    unsigned int flag;
    int in_offset;
    int in_op;
    int in_type;
    char *desc;
    union {
        char *s;
    } value;
    size_t vallen;
};

struct mlist {
    struct magic *magic;
    size_t nmagic;
};

#define INDIR 0x01
#define INDIROFFADD 0x02
#define NOSPACE 0x04

#define FILE_OPINDIRECT 0x01
#define FILE_OPINVERSE 0x02
#define FILE_OPS_MASK 0x0F

#define FILE_OPAND 1
#define FILE_OPOR 2
#define FILE_OPXOR 3
#define FILE_OPADD 4
#define FILE_OPMINUS 5
#define FILE_OPMULTIPLY 6
#define FILE_OPDIVIDE 7
#define FILE_OPMODULO 8

#define FILE_BYTE 1
#define FILE_SHORT 2
#define FILE_BESHORT 3
#define FILE_LESHORT 4
#define FILE_LONG 5
#define FILE_BELONG 6
#define FILE_LELONG 7
#define FILE_MELONG 8
#define FILE_BEID3 9
#define FILE_LEID3 10
#define FILE_INDIRECT 11
#define FILE_USE 12
#define FILE_NAME 13
#define FILE_DEFAULT 14
#define FILE_CLEAR 15
#define FILE_STRING 16
#define FILE_PSTRING 17
#define FILE_SEARCH 18
#define FILE_REGEX 19
#define FILE_DATE 20
#define FILE_BEDATE 21
#define FILE_LEDATE 22
#define FILE_MEDATE 23
#define FILE_LDATE 24
#define FILE_BELDATE 25
#define FILE_LELDATE 26
#define FILE_MELDATE 27
#define FILE_FLOAT 28
#define FILE_BEFLOAT 29
#define FILE_LEFLOAT 30
#define FILE_DOUBLE 31
#define FILE_BEDOUBLE 32
#define FILE_LEDOUBLE 33

#define MAGIC_DEBUG 0x01
#define MAGIC_MIME 0x02
#define MAGIC_APPLE 0x04

#define BINTEST 0

#define F(a,b) a

#define CAST(type, value) ((type)(value))

int file_error(struct magic_set *, int, const char *, ...);
int mcopy(struct magic_set *, VALUETYPE *, int, int, const unsigned char *, uint32_t, uint32_t, uint32_t);
void mdebug(uint32_t, char *, size_t);
void file_mdump(struct magic *);
int cvt_flip(int, int);
int file_printf(struct magic_set *, const char *, ...);
int file_softmagic(struct magic_set *, const unsigned char *, size_t, int, int);
int file_magicfind(struct magic_set *, const char *, struct mlist *);
int match(struct magic_set *, struct magic *, size_t, const unsigned char *, size_t, size_t, int, int, int, int, int *, int *, int *);
int mconvert(struct magic_set *, struct magic *, int);