#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int64_t sf_count_t;

#define SF_MIN(a, b) ((a) < (b) ? (a) : (b))
#define FLAC__MAX_BLOCK_SIZE 65535
#define FLAC__MAX_CHANNELS 8
#define SF_TRUE 1
#define SF_FALSE 0

typedef struct {
    int channels;
} SF_INFO;

typedef struct {
    SF_INFO sf;
    int error;
    int norm_float;
    int norm_double;
    void* codec_data;
} SF_PRIVATE;

typedef struct {
    struct {
        unsigned channels;
        unsigned blocksize;
        unsigned bits_per_sample;
    } header;
} FLAC__Frame;

typedef enum {
    PFLAC_PCM_SHORT,
    PFLAC_PCM_INT,
    PFLAC_PCM_FLOAT,
    PFLAC_PCM_DOUBLE
} PFLAC_PCM_TYPE;

typedef struct {
    FLAC__Frame* frame;
    const int32_t* const* wbuffer;
    int32_t** rbuffer;
    unsigned wbuffer_size;
    void* ptr;
    unsigned len;
    unsigned remain;
    unsigned pos;
    unsigned bufferpos;
    PFLAC_PCM_TYPE pcmtype;
} FLAC_PRIVATE;

enum {
    SFE_FLAC_CHANNEL_COUNT_CHANGED,
    SFE_INTERNAL
};

void psf_log_printf(SF_PRIVATE* psf, const char* format, ...);