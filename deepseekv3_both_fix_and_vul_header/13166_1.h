#include <stdint.h>
#include <stdio.h>

#define GF_EXPORT

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;

typedef enum {
    GF_BITSTREAM_READ,
    GF_BITSTREAM_FILE_READ,
    GF_BITSTREAM_FILE_WRITE
} GF_BitStreamMode;

typedef struct GF_BitStream {
    GF_BitStreamMode bsmode;
    FILE *stream;
    u64 position;
    u64 size;
    u8 *cache_write;
    u8 *cache_read;
    u32 cache_read_size;
    u32 cache_read_pos;
    u8 remove_emul_prevention_byte;
    u8 overflow_state;
} GF_BitStream;

void gf_bs_align(GF_BitStream *bs);
void bs_flush_write_cache(GF_BitStream *bs);
u8 gf_bs_read_u8(GF_BitStream *bs);
void gf_bs_write_int(GF_BitStream *bs, int value, int nbBits);
int gf_fseek(FILE *stream, long int offset, int whence);