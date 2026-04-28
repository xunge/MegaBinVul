#include <stdint.h>

#define MIN_BLOCK_SIZE 4
#define MAX_SB_SIZE 64

typedef struct {
    uint16_t width;
    uint16_t height;
    uint8_t log2_sb_size;
    uint8_t pb_split;
    uint8_t tb_split_enable;
    uint8_t max_num_ref;
    uint8_t interp_ref;
    uint8_t max_delta_qp;
    uint8_t deblocking;
    uint8_t clpf;
    uint8_t use_block_contexts;
    uint8_t bipred;
    uint8_t qmtx;
    int8_t qmtx_offset;
    uint8_t subsample;
    uint8_t num_reorder_pics;
    uint8_t cfl_intra;
    uint8_t cfl_inter;
    uint8_t bitdepth;
    uint8_t input_bitdepth;
} decoder_info_t;

typedef struct {
    // Define stream_t structure members as needed
    // This is a placeholder since the actual implementation isn't shown
} stream_t;

uint32_t get_flc(uint8_t n, stream_t *stream);
int log2i(int x);
int clip(int x, int min, int max);