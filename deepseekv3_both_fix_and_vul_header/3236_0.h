#include <stdint.h>
#include <string.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size, table_alloc;
} VLC;

typedef struct HYuvContext {
    uint8_t len[3][256];
    uint32_t bits[3][256];
    VLC vlc[3];
    int bitstream_bpp;
} HYuvContext;

extern const uint8_t classic_shift_luma[];
extern const uint8_t classic_shift_chroma[];
extern const uint32_t classic_add_luma[256];
extern const uint32_t classic_add_chroma[256];
extern const unsigned int classic_shift_luma_table_size;
extern const unsigned int classic_shift_chroma_table_size;

#define VLC_BITS 9

void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
int read_len_table(uint8_t *dst, GetBitContext *gb);
void ff_free_vlc(VLC *vlc);
int init_vlc(VLC *vlc, int nb_bits, int nb_codes,
             const uint8_t *bits, int bits_wrap, int bits_size,
             const void *codes, int codes_wrap, int codes_size,
             int flags);
void generate_joint_tables(HYuvContext *s);