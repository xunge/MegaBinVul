#include <stdio.h>
#include <stddef.h>

#define TAB_SIZE 4
#define DECODE 0x1
#define EXT 0x2
#define STOP 0x4
#define OPEN 0x8

#define H323_ERROR_NONE 0
#define H323_ERROR_RANGE -1
#define H323_ERROR_STOP -2

#define BYTE_ALIGN(bs) ((bs)->bit = 0)
#define CHECK_BOUND(bs, len) \
    do { \
        if ((bs)->cur + (len) > (bs)->end) \
            return H323_ERROR_RANGE; \
    } while (0)

#define PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)

typedef struct bitstr {
    unsigned char *cur;
    unsigned char *end;
    unsigned bit;
} bitstr_t;

typedef struct field {
    char *name;
    unsigned attr;
    unsigned offset;
    unsigned lb;
    unsigned ub;
    unsigned sz;
    unsigned type;
    struct field *fields;
} field_t;

extern int (*Decoders[])(bitstr_t *, field_t *, char *, int);

static inline unsigned get_bit(bitstr_t *bs)
{
    unsigned bit = (*bs->cur >> (7 - bs->bit)) & 1;
    bs->bit++;
    if (bs->bit > 7) {
        bs->cur++;
        bs->bit = 0;
    }
    return bit;
}

static inline unsigned get_bits(bitstr_t *bs, unsigned n)
{
    unsigned value = 0;
    while (n--) {
        value = (value << 1) | get_bit(bs);
    }
    return value;
}

static inline unsigned get_len(bitstr_t *bs)
{
    unsigned len = 0;
    while (get_bit(bs)) {
        len = (len << 7) | get_bits(bs, 7);
    }
    len = (len << 7) | get_bits(bs, 7);
    return len;
}