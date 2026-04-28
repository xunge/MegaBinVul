#include <stdint.h>
#include <assert.h>

#define VLC_BITS 11
#define G 1
#define B 2
#define R 0

typedef struct HYuvContext {
    int bitstream_bpp;
    int len[3][256];
    uint16_t bits[3][256];
    void *vlc[6];
    uint8_t pix_bgr_map[1 << VLC_BITS][4];
    int decorrelate;
} HYuvContext;

void ff_free_vlc(void *vlc);
void ff_init_vlc_sparse(void *vlc, int bits, int num, uint8_t *len, int skip, int skip_bits,
                       uint16_t *bits_buf, int bits_size, int bits_wrap,
                       uint16_t *symbols, int symbols_size, int symbols_wrap, int flags);
void init_vlc(void *vlc, int bits, int num, uint8_t *len, int skip, int skip_bits,
              uint16_t *bits_buf, int bits_size, int bits_wrap, int flags);