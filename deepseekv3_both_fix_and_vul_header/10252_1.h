#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FLAC__MAX_BLOCK_SIZE 65535
#define FLAC__MAX_CHANNELS 8
#define SF_TRUE 1
#define SF_FALSE 0
#define SFE_INTERNAL 1

typedef int64_t sf_count_t;

typedef struct {
    int error;
    int norm_float;
    int norm_double;
    void *codec_data;
} SF_PRIVATE;

typedef struct FLAC__FrameHeader {
    unsigned blocksize;
    unsigned channels;
    unsigned bits_per_sample;
} FLAC__FrameHeader;

typedef struct FLAC__Frame {
    FLAC__FrameHeader header;
} FLAC__Frame;

typedef struct {
    FLAC__Frame *frame;
    int32_t **rbuffer;
    const int32_t* const *wbuffer;
    void *ptr;
    unsigned len;
    unsigned remain;
    unsigned pos;
    unsigned bufferpos;
    int pcmtype;
    int bufferbackup;
} FLAC_PRIVATE;

enum {
    PFLAC_PCM_SHORT,
    PFLAC_PCM_INT,
    PFLAC_PCM_FLOAT,
    PFLAC_PCM_DOUBLE
};

#define SF_MIN(a, b) ((a) < (b) ? (a) : (b))

void psf_log_printf(SF_PRIVATE *psf, const char *format, ...);