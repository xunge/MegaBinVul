#include <stdint.h>
#include <assert.h>

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
} VLC;

typedef struct vorbis_codebook {
    unsigned int dimensions;
    unsigned int entries;
    unsigned int nb_bits;
    VLC vlc;
} vorbis_codebook;

typedef struct vorbis_residue {
    unsigned int classifications;
    unsigned int classbook;
    unsigned int ptns_to_read;
    uint8_t *classifs;
} vorbis_residue;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
} GetBitContext;

typedef struct vorbis_context {
    vorbis_codebook *codebooks;
    GetBitContext gb;
} vorbis_context;

extern const uint32_t ff_inverse[];
extern int get_vlc2(GetBitContext *gb, const VLC *vlc, int bits, int max_depth);
#define av_always_inline inline
#define av_dlog(...)
#define av_assert0(cond) assert(cond)