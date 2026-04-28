#include <stdint.h>

#define UNUSED
#define SF_FALSE 0

typedef struct SF_PRIVATE {
    void *codec_data;
} SF_PRIVATE;

typedef struct FLAC__StreamDecoder FLAC__StreamDecoder;
typedef struct FLAC__Frame FLAC__Frame;

typedef struct FLAC_PRIVATE {
    const FLAC__Frame *frame;
    int bufferpos;
    int bufferbackup;
    const int32_t * const *wbuffer;
} FLAC_PRIVATE;

typedef enum {
    FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE
} FLAC__StreamDecoderWriteStatus;

void flac_buffer_copy(SF_PRIVATE *psf);