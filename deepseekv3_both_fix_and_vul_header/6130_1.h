#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define AV_LOG_ERROR 0
#define AV_LOG_VERBOSE 0
#define DNXHD_VLC_BITS 0
#define DNXHD_DC_VLC_BITS 0
#define DNXHD_VARIABLE 0
#define AVERROR(e) (-(e))
#define ENOSYS 0
#define AVERROR_INVALIDDATA 0

typedef struct AVCodecContext AVCodecContext;

typedef struct VLC {
    int16_t table[1024][2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct CIDEntry {
    int bit_depth;
    const uint8_t *ac_bits;
    const uint16_t *ac_codes;
    const uint8_t *dc_bits;
    const uint16_t *dc_codes;
    const uint8_t *run_bits;
    const uint16_t *run_codes;
} CIDEntry;

typedef struct DNXHDContext {
    AVCodecContext *avctx;
    uint32_t cid;
    const CIDEntry *cid_table;
    VLC ac_vlc;
    VLC dc_vlc;
    VLC run_vlc;
} DNXHDContext;

const CIDEntry *ff_dnxhd_get_cid_table(uint32_t cid);
void ff_free_vlc(VLC *vlc);
int init_vlc(VLC *vlc, int nb_bits, int nb_codes,
             const void *bits, int bits_wrap, int bits_size,
             const void *codes, int codes_wrap, int codes_size,
             int flags);
void av_log(void *avctx, int level, const char *fmt, ...);