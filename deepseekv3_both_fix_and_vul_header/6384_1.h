#include <assert.h>
#include <stdint.h>
#include <stddef.h>

typedef struct Bit_Chain Bit_Chain;
typedef struct Dwg_Object Dwg_Object;

typedef int32_t BITCODE_RL;
typedef int16_t BITCODE_RS;
typedef unsigned char BITCODE_B;

struct Bit_Chain {
    unsigned char *chain;
    size_t size;
    size_t byte;
    unsigned bit;
};

struct Dwg_Object {
    BITCODE_RL bitsize;
    BITCODE_B has_strings;
    BITCODE_RL stringstream_size;
    int fixedtype;
};

#define DWG_ERR_VALUEOUTOFBOUNDS 1
#define DWG_ERR_NOTYETSUPPORTED 2
#define DWG_TYPE_SCALE 1

#define LOG_WARN(...)
#define LOG_HANDLE(...)
#define LOG_TRACE(...)

void bit_advance_position(Bit_Chain *chain, int bits);
BITCODE_B bit_read_B(Bit_Chain *chain);
BITCODE_RS bit_read_RS(Bit_Chain *chain);
size_t bit_position(Bit_Chain *chain);
void bit_reset_chain(Bit_Chain *chain);