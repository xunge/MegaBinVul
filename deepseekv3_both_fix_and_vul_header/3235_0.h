#include <stdint.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size, table_allocated;
} VLC;

typedef struct HYuvContext {
    uint8_t len[3][256];
    uint16_t bits[3][256];
    VLC vlc[3];
} HYuvContext;

#define VLC_BITS 9

void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
int read_len_table(uint8_t *dst, GetBitContext *gb);
int ff_huffyuv_generate_bits_table(uint16_t *dst, const uint8_t *len);
void ff_free_vlc(VLC *vlc);
int init_vlc(VLC *vlc, int nb_bits, int nb_codes,
             const uint8_t *bits, int bits_wrap, int bits_size,
             const void *codes, int codes_wrap, int codes_size,
             int flags);
void generate_joint_tables(HYuvContext *s);
int get_bits_count(GetBitContext *s);