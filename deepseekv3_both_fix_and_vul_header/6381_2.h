#include <stdint.h>
#include <string.h>

typedef float real_t;
#define ALIGN
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct drc_info {
    int present;
    int *exclude_mask;
    int excluded_chns_present;
} drc_info;

typedef struct fb_info {
    // Filter bank info placeholder
} fb_info;

typedef struct sbr_info {
    int maxAACLine;
} sbr_info;

typedef struct NeAACDecStruct {
    int fr_ch_ele;
    int *element_output_channels;
    int *element_alloced;
    int *ps_used;
    real_t **time_out;
    int frameLength;
    int object_type;
    int sf_index;
    void **pred_stat;
    void **lt_pred_stat;
    int *ltp_lag;
    fb_info *fb;
    int *window_shape_prev;
    real_t **fb_intermed;
    drc_info *drc;
    int sbr_present_flag;
    int forceUpSampling;
    int *sbr_alloced;
    sbr_info **sbr;
    int *element_id;
    int downSampledSBR;
    int postSeekResetFlag;
    real_t **ssr_overlap;
    real_t **ipqf_buffer;
    real_t **prev_fmd;
    int64_t requant_cycles;
    void *__r1;
    void *__r2;
} NeAACDecStruct;

typedef struct element {
    int channel;
    struct {
        int window_sequence;
        int max_sfb;
        int *swb_offset;
        int swb_offset_max;
    } ics1;
} element;

typedef struct ic_stream {
    int window_sequence;
    int window_shape;
    struct {
        int data_present;
        int lag_update;
        int lag;
    } ltp;
    struct {
        // TNS data placeholder
    } tns;
    struct {
        // SSR data placeholder
    } ssr;
} ic_stream;

#ifdef PROFILE
int64_t faad_get_ts();
#endif

uint8_t allocate_single_channel(NeAACDecStruct *hDecoder, int channel, int output_channels);
uint8_t quant_to_spec(NeAACDecStruct *hDecoder, ic_stream *ics, int16_t *spec_data, real_t *spec_coef, int frameLength);
void pns_decode(ic_stream *ics, int16_t *sfb_offset, real_t *spec_coef1, real_t *spec_coef2, int frameLength, int channel, int object_type, void *r1, void *r2);
void ic_prediction(ic_stream *ics, real_t *spec_coef, void *pred_state, int frameLength, int sf_index);
void pns_reset_pred_state(ic_stream *ics, void *pred_state);
void lt_prediction(ic_stream *ics, void *ltp, real_t *spec_coef, void *lt_pred_stat, fb_info *fb, int window_shape, int window_shape_prev, int sf_index, int object_type, int frameLength);
void tns_decode_frame(ic_stream *ics, void *tns, int sf_index, int object_type, real_t *spec_coef, int frameLength);
void drc_decode(drc_info *drc, real_t *spec_coef);
void ifilter_bank(fb_info *fb, int window_sequence, int window_shape, int window_shape_prev, real_t *spec_coef, real_t *time_out, real_t *fb_intermed, int object_type, int frameLength);
void ssr_decode(void *ssr, fb_info *fb, int window_sequence, int window_shape, int window_shape_prev, real_t *spec_coef, real_t *time_out, real_t *overlap, real_t *ipqf_buffer, real_t *prev_fmd, int frameLength);
void lt_update_state(void *lt_pred_stat, real_t *time_out, real_t *overlap, int frameLength, int object_type);
sbr_info *sbrDecodeInit(int frameLength, int element_id, int sample_rate, int downSampledSBR);
uint8_t sbrDecodeSingleFrame(sbr_info *sbr, real_t *time_out, int postSeekResetFlag, int downSampledSBR);
uint8_t sbrDecodeSingleFramePS(sbr_info *sbr, real_t *time_out1, real_t *time_out2, int postSeekResetFlag, int downSampledSBR);
int get_sample_rate(int sf_index);
int is_ltp_ot(int object_type);