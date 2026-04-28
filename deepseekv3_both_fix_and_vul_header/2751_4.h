#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct vorbis_codebook {
    int dimensions;
} vorbis_codebook;

typedef struct vorbis_floor_t0 {
    uint8_t order;
    uint16_t rate;
    uint16_t bark_map_size;
    uint8_t amplitude_bits;
    uint8_t amplitude_offset;
    uint8_t num_books;
    uint8_t *book_list;
    float *lsp;
} vorbis_floor_t0;

typedef struct vorbis_floor_t1_list {
    uint16_t x;
} vorbis_floor_t1_list;

typedef struct vorbis_floor_t1 {
    int partitions;
    uint8_t partition_class[31];
    uint8_t class_dimensions[16];
    uint8_t class_subclasses[16];
    uint8_t class_masterbook[16];
    int16_t subclass_books[16][8];
    int multiplier;
    int x_list_dim;
    vorbis_floor_t1_list *list;
} vorbis_floor_t1;

typedef struct vorbis_floor {
    int floor_type;
    void (*decode)(void);
    union {
        vorbis_floor_t0 t0;
        vorbis_floor_t1 t1;
    } data;
} vorbis_floor;

typedef struct vorbis_context {
    GetBitContext gb;
    int floor_count;
    vorbis_floor *floors;
    int codebook_count;
    vorbis_codebook *codebooks;
    uint32_t blocksize[2];
    void *avccontext;
} vorbis_context;

#define AVERROR_INVALIDDATA (-1)
#define AVERROR(ENOMEM) (-2)
#define AV_LOG_ERROR 0

#define GET_VALIDATED_INDEX(var, bits, max) \
    do { \
        (var) = get_bits(gb, bits); \
        if ((var) >= (max)) \
            return AVERROR_INVALIDDATA; \
    } while (0); 

#define VALIDATE_INDEX(var, max) \
    do { \
        if ((var) >= (max)) \
            return AVERROR_INVALIDDATA; \
    } while (0);

static inline int get_bits(GetBitContext *gb, int n) {
    return 0;
}

static inline void *av_mallocz(size_t size) {
    return calloc(1, size);
}

static inline void *av_malloc(size_t size) {
    return malloc(size);
}

static inline void av_dlog(void *avcl, const char *fmt, ...) {}

static inline void av_log(void *avcl, int level, const char *fmt, ...) {}

static inline int ff_vorbis_ready_floor1_list(void *avctx, void *list, int x_list_dim) {
    return 0;
}

static inline void vorbis_floor1_decode(void) {}

static inline void vorbis_floor0_decode(void) {}

static inline void create_map(vorbis_context *vc, int i) {}