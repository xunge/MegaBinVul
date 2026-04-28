#include <stdint.h>
#include <assert.h>

typedef uint8_t u8;
typedef int Bool;

#define GF_BITSTREAM_READ 1
#define GF_FALSE 0
#define GF_TRUE 1
#define GF_LOG_ERROR 1
#define GF_LOG_CORE 1

typedef struct {
    int bsmode;
    unsigned long position;
    unsigned long size;
    void (*EndOfStream)(void*);
    void* par;
    int overflow_state;
    u8* original;
    Bool remove_emul_prevention_byte;
    unsigned int nb_zeros;
    void* stream;
    Bool cache_write;
    Bool cache_read;
    unsigned long cache_read_pos;
    unsigned long cache_read_size;
} GF_BitStream;

void bs_flush_write_cache(GF_BitStream *bs);
Bool gf_feof(void* stream);
u8 gf_bs_load_byte(GF_BitStream *bs, Bool *loc_eos);
void gf_bs_seek(GF_BitStream *bs, unsigned long position);
void GF_LOG(int level, int category, const char* fmt, ...);