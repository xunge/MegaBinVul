#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef bool FLAC__bool;
typedef uint32_t FLAC__uint32;

typedef struct FLAC__StreamDecoder FLAC__StreamDecoder;
typedef struct FLAC__StreamMetadata_VorbisComment FLAC__StreamMetadata_VorbisComment;

typedef enum {
    FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR
} FLAC__StreamDecoderState;

typedef struct {
    FLAC__StreamDecoderState state;
} FLAC__StreamDecoderProtected;

typedef struct {
    void *input;
} FLAC__StreamDecoderPrivate;

typedef struct {
    FLAC__uint32 length;
    char *entry;
} FLAC__StreamMetadata_VorbisComment_Entry;

struct FLAC__StreamMetadata_VorbisComment {
    FLAC__StreamMetadata_VorbisComment_Entry vendor_string;
    FLAC__uint32 num_comments;
    FLAC__StreamMetadata_VorbisComment_Entry *comments;
};

struct FLAC__StreamDecoder {
    FLAC__StreamDecoderProtected *protected_;
    FLAC__StreamDecoderPrivate *private_;
};

#define FLAC__STREAM_METADATA_VORBIS_COMMENT_ENTRY_LENGTH_LEN 32
#define FLAC__STREAM_METADATA_VORBIS_COMMENT_NUM_COMMENTS_LEN 32

#define FLAC__ASSERT(x) (void)(x)

static inline void *safe_malloc_add_2op_(size_t size1, size_t size2) {
    return malloc(size1 + size2);
}

static inline void *safe_malloc_mul_2op_p(size_t size1, size_t size2) {
    return malloc(size1 * size2);
}

bool FLAC__bitreader_is_consumed_byte_aligned(void *input);
bool FLAC__bitreader_read_uint32_little_endian(void *input, uint32_t *val);
bool FLAC__bitreader_read_byte_block_aligned_no_crc(void *input, void *data, unsigned bytes);
bool FLAC__bitreader_skip_byte_block_aligned_no_crc(void *input, unsigned bytes);