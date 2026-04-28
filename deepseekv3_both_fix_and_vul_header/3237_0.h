#include <stdint.h>

#define VLC_BITS 11

typedef struct HYuvContext {
    int bitstream_bpp;
    int len[3][256];
    uint16_t bits[3][256];
    void *vlc[6];
    uint8_t pix_bgr_map[1 << VLC_BITS][4];
    int decorrelate;
} HYuvContext;

enum {
    G,
    B,
    R
};

void ff_free_vlc(void *vlc);
void ff_init_vlc_sparse(void *vlc, int bits, int size, const uint8_t *len, int len_size, int len_bits,
                       const void *bits_buf, int bits_size, int bits_bits,
                       const void *symbols, int symbols_size, int symbols_bits, int flags);
void init_vlc(void *vlc, int bits, int size, const uint8_t *len, int len_size, int len_bits,
             const void *bits_buf, int bits_size, int bits_bits, int flags);