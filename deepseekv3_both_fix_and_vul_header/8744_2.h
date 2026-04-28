#include <stdint.h>
#include <setjmp.h>
#include <stddef.h>

typedef int vpx_codec_err_t;

#define VPX_CODEC_OK 0
#define VPX_CODEC_UNSUP_BITSTREAM 1
#define VPX_CODEC_CORRUPT_FRAME 2
#define VPX_CODEC_MEM_ERROR 3
#define VPX_CODEC_USE_ERROR_CONCEALMENT 4
#define VPX_CODEC_USE_POSTPROC 5

#define VP8_DEBLOCK 1
#define VP8_DEMACROBLOCK 2
#define VP8_MFQE 4

#define CONFIG_MULTITHREAD 1
#define CONFIG_ERROR_CONCEALMENT 1

typedef struct {
    int w;
    int h;
    int is_kf;
} vp8_si_t;

typedef struct {
    void *buf;
} yv12_buffer_t;

typedef struct {
    int enabled;
    void *ptrs[1];
    unsigned int sizes[1];
    int count;
} fragment_data_t;

typedef struct {
    jmp_buf jmp;
    int setjmp;
} vp8_error_info_t;

typedef struct MACROBLOCKD {
    yv12_buffer_t pre;
    yv12_buffer_t dst;
} MACROBLOCKD;

typedef struct MODE_INFO {
    int dummy;
} MODE_INFO;

typedef struct VP8_COMMON {
    int Width;
    int Height;
    int mb_rows;
    int mb_cols;
    int mode_info_stride;
    vp8_error_info_t error;
    int lst_fb_idx;
    int new_fb_idx;
    yv12_buffer_t *yv12_fb;
    MODE_INFO *prev_mip;
    MODE_INFO *prev_mi;
    int fb_idx_ref_cnt[1];
} VP8_COMMON;

typedef struct {
    MACROBLOCKD mbd;
} mb_row_decoding_info_t;

typedef struct VP8D_COMP {
    VP8_COMMON common;
    MACROBLOCKD mb;
    int allocated_decoding_thread_count;
    mb_row_decoding_info_t *mb_row_di;
    int b_multithreaded_rd;
    int ec_enabled;
    fragment_data_t fragments;
    int decrypt_cb;
    void *decrypt_state;
} VP8D_COMP;

typedef struct {
    int Width;
    int Height;
    int Version;
    int postprocess;
    int max_threads;
    int error_concealment;
} VP8D_CONFIG;

typedef struct {
    VP8D_COMP *pbi[1];
} yv12_frame_buffers_t;

typedef struct {
    unsigned int init_flags;
} vpx_codec_base_t;

typedef struct {
    int post_proc_flag;
    int deblocking_level;
    int noise_level;
} vp8_postproc_cfg_t;

typedef struct vpx_codec_alg_priv_t {
    fragment_data_t fragments;
    vp8_si_t si;
    int decrypt_cb;
    void *decrypt_state;
    int decoder_init;
    struct {
        int threads;
    } cfg;
    vpx_codec_base_t base;
    int postproc_cfg_set;
    vp8_postproc_cfg_t postproc_cfg;
    yv12_frame_buffers_t yv12_frame_buffers;
    void *user_priv;
} vpx_codec_alg_priv_t;

static int update_fragments(vpx_codec_alg_priv_t *ctx, const uint8_t *data, unsigned int data_sz, vpx_codec_err_t *res) { return 0; }
static vpx_codec_err_t vp8_peek_si_internal(void *ptr, unsigned int size, void *si, int decrypt_cb, void *decrypt_state) { return 0; }
static vpx_codec_err_t vp8_create_decoder_instances(void *buffers, VP8D_CONFIG *oxcf) { return 0; }
static void vp8_clear_system_state(void) {}
static int vp8_alloc_frame_buffers(VP8_COMMON *pc, int width, int height) { return 0; }
static void vp8_build_block_doffsets(MACROBLOCKD *mbd) {}
static void vp8_de_alloc_frame_buffers(VP8_COMMON *pc) {}
static void *vpx_calloc(size_t nmemb, size_t size) { return NULL; }
static int vp8_alloc_overlap_lists(VP8D_COMP *pbi) { return 0; }
static void vp8mt_alloc_temp_buffers(VP8D_COMP *pbi, int width, int prev_mb_rows) {}
static int vp8dx_receive_compressed_data(VP8D_COMP *pbi, unsigned int data_sz, const uint8_t *data, long deadline) { return 0; }
static vpx_codec_err_t update_error_state(vpx_codec_alg_priv_t *ctx, void *error) { return 0; }
static void vpx_internal_error(void *error, int code, const char *msg) {}