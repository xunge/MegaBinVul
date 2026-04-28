#include <stdio.h>
#include <stdint.h>

#define TAB_SIZE 4
#define DECODE 0x1
#define EXT 0x2
#define STOP 0x4
#define OPT 0x8
#define OPEN 0x10

#define H323_ERROR_STOP -1
#define H323_ERROR_NONE 0

#define PRINT(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define CHECK_BOUND(bs, n) 
#define BYTE_ALIGN(bs) 

typedef struct bitstr {
    unsigned char *cur;
    unsigned bit;
} bitstr_t;

typedef struct field {
    char *name;
    unsigned attr;
    unsigned offset;
    unsigned sz;
    unsigned lb;
    unsigned ub;
    unsigned type;
    struct field *fields;
} field_t;

extern int (*Decoders[])(bitstr_t *, field_t *, char *, int);

unsigned get_bit(bitstr_t *bs);
unsigned get_bitmap(bitstr_t *bs, unsigned n);
unsigned get_bits(bitstr_t *bs, unsigned n);
unsigned get_len(bitstr_t *bs);