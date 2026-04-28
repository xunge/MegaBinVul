#include <stdint.h>
#include <string.h>

#define BROTLI_INLINE
#define BROTLI_RESULT_SUCCESS 0
#define BROTLI_RESULT_NEEDS_MORE_INPUT 1
#define BROTLI_FAILURE() (-1)
#define BROTLI_STATE_COMMAND_BEGIN 0
#define BROTLI_STATE_COMMAND_INNER 1
#define BROTLI_STATE_COMMAND_POST_DECODE_LITERALS 2
#define BROTLI_STATE_COMMAND_POST_WRAP_COPY 3
#define BROTLI_STATE_METABLOCK_DONE 4
#define BROTLI_STATE_COMMAND_INNER_WRITE 5
#define BROTLI_STATE_COMMAND_POST_WRITE_1 6
#define BROTLI_STATE_COMMAND_POST_WRITE_2 7
#define PREDICT_FALSE(x) (x)
#define BROTLI_SAFE(x) if ((x) != BROTLI_RESULT_SUCCESS) return (x)
#define BROTLI_LOG_UINT(x)
#define BROTLI_LOG_ARRAY_INDEX(x, y)
#define BROTLI_LOG(x)

typedef int BrotliResult;

typedef struct {
    uint16_t bits;
    uint16_t value;
} HuffmanCode;

typedef struct BrotliBitReader {
    uint32_t val_;
    uint32_t bit_pos_;
    const uint8_t* next_in;
    size_t avail_in;
} BrotliBitReader;

typedef struct {
    int pos;
    int loop_counter;
    int state;
    int block_length[3];
    int copy_length;
    int distance_code;
    int meta_block_remaining_len;
    int max_distance;
    int max_backward_distance;
    int custom_dict_size;
    int max_backward_distance_minus_custom_dict_size;
    int dist_rb_idx;
    int dist_rb[4];
    int trivial_literal_context;
    int literal_htree_index;
    int context_map_slice[256];
    uint8_t context_lookup1[256];
    uint8_t context_lookup2[256];
    uint8_t ringbuffer[0];
    uint8_t* ringbuffer_end;
    int ringbuffer_size;
    int ringbuffer_mask;
    HuffmanCode* literal_htree;
    struct {
        HuffmanCode* htrees[0];
    } literal_hgroup;
    BrotliBitReader br;
} BrotliState;

#define kBrotliMinDictionaryWordLength 4
#define kBrotliMaxDictionaryWordLength 24
#define kBrotliDictionarySizeBitsByLength (int[]){0,0,0,0,10,10,11,11,10,10,10,10,10,9,9,8,7,7,8,7,7,6,6,5,5}
#define kBrotliDictionaryOffsetsByLength (int[]){0,0,0,0,0,4096,9216,21504,35840,44032,53248,63488,74752,87040,93696,100864,104448,106752,108928,113536,115968,118528,119872,121280,122016}
#define kNumTransforms 10
extern const uint8_t kBrotliDictionary[122784];

static inline uint32_t BitMask(uint32_t n) { return ~((0xFFFFFFFFu) << n); }
static inline void memmove16(void* dst, const void* src) { memmove(dst, src, 16); }