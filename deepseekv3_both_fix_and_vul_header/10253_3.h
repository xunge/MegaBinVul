#include <stddef.h>
#include <string.h>

typedef struct SF_PRIVATE {
    void *codec_data;
} SF_PRIVATE;

typedef struct FLAC_FRAME_HEADER {
    unsigned blocksize;
} FLAC_FRAME_HEADER;

typedef struct FLAC_FRAME {
    FLAC_FRAME_HEADER header;
} FLAC_FRAME;

typedef unsigned FLAC__StreamDecoderState;

#define FLAC__STREAM_DECODER_END_OF_STREAM 0
static const char *FLAC__StreamDecoderStateString[] = {""};

typedef struct FLAC_PRIVATE {
    unsigned pos;
    unsigned len;
    unsigned remain;
    void* fsd;
    FLAC_FRAME* frame;
    size_t bufferpos;
    void* ptr;
} FLAC_PRIVATE;

extern void psf_log_printf(SF_PRIVATE *psf, const char *format, ...);
extern void flac_buffer_copy(SF_PRIVATE *psf);
extern FLAC__StreamDecoderState FLAC__stream_decoder_get_state(void* fsd);
extern int FLAC__stream_decoder_process_single(void* fsd);