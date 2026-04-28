#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define H264_MAX_PICTURE_COUNT 16
#define H264_MAX_THREADS 16

typedef struct H264Picture H264Picture;
typedef struct H264ERContext H264ERContext;
typedef struct H264Context H264Context;

struct H264ERContext {
    int *mb_index2xy;
    int *error_status_table;
    uint8_t *er_temp_buffer;
    uint8_t *mbintra_table;
    uint8_t *mbskip_table;
};

struct H264Picture {
    int needs_realloc;
};

struct H264Context {
    int *intra4x4_pred_mode;
    uint8_t *chroma_pred_mode_table;
    uint8_t *cbp_table;
    uint8_t *mvd_table[2];
    uint8_t *direct_table;
    uint8_t *non_zero_count;
    uint8_t *slice_table_base;
    uint8_t *slice_table;
    int *list_counts;
    uint16_t *mb2b_xy;
    uint16_t *mb2br_xy;
    void *qscale_table_pool;
    void *mb_type_pool;
    void *motion_val_pool;
    void *ref_index_pool;
    H264Picture *DPB;
    H264Picture *cur_pic_ptr;
    H264Picture delayed_pic[H264_MAX_PICTURE_COUNT];
    H264Context *thread_context[H264_MAX_THREADS];
    uint8_t *top_borders[2];
    uint8_t *bipred_scratchpad;
    uint8_t *edge_emu_buffer;
    int16_t *dc_val_base;
    H264ERContext er;
    uint8_t *rbsp_buffer[2];
    int rbsp_buffer_size[2];
};

void av_freep(void *ptr);
void av_buffer_pool_uninit(void *pool);
void ff_h264_unref_picture(H264Context *h, H264Picture *pic);