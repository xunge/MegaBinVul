#include <stdint.h>

typedef struct FLAC__StreamDecoder FLAC__StreamDecoder;

typedef enum {
    FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE
} FLAC__StreamDecoderWriteStatus;

typedef struct FLAC__FrameHeader {
    unsigned blocksize;
} FLAC__FrameHeader;

typedef struct FLAC__Frame {
    FLAC__FrameHeader header;
} FLAC__Frame;

typedef struct {
    int bufferpos;
    const FLAC__Frame *frame;
    const int32_t *const *wbuffer;
    unsigned wbuffer_size;
} FLAC_PRIVATE;

typedef struct {
    void *codec_data;
} SF_PRIVATE;

static void flac_buffer_copy(SF_PRIVATE *psf);