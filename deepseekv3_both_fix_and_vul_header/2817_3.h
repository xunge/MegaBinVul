#include <stdint.h>
#include <string.h>

#define MAIN 0
#define LD 1
#define SSR 2
#define EIGHT_SHORT_SEQUENCE 3

typedef struct drc_info {
    int present;
    int *exclude_mask;
    int excluded_chns_present;
} drc_info;

typedef struct sbr_info {
    int maxAACLine;
} sbr_info;

typedef struct ics_info {
    int window_sequence;
    int max_sfb;
    int *swb_offset;
    int swb_offset_max;
} ics_info;

typedef struct ssr_info {
    // SSR specific fields
} ssr_info;

typedef struct NeAACDecStruct {
    int fr_ch_ele;
    int *element_output_channels;
    int *element_alloced;
    int fr_channels;
    int frameLength;
    int object_type;
    int64_t requant_cycles;
    int sf_index;
    void **pred_stat;
    void *fb;
    int *window_shape_prev;
    drc_info *drc;
    void **time_out;
    void **fb_intermed;
    void **ssr_overlap;
    void **ipqf_buffer;
    void **prev_fmd;
    int sbr_present_flag;
    int forceUpSampling;
    int *sbr_alloced;
    sbr_info **sbr;
    int *element_id;
    int downSampledSBR;
    int postSeekResetFlag;
    int *ps_used;
    void *__r1;
    void *__r2;
    void **lt_pred_stat;
    int *ltp_lag;
} NeAACDecStruct;

typedef struct ic_stream {
    struct {
        int data_present;
        int lag_update;
        int lag;
    } ltp;
    struct {
        void *data;
    } tns;
    int window_sequence;
    int window_shape;
    ics_info ics1;
    ssr_info ssr;
} ic_stream;

typedef struct element {
    int channel;
    ics_info ics1;
} element;

typedef int16_t real_t;
typedef int64_t int64_t;

#define ALIGN
#define PROFILE
#define DRM
#define DRM_PS
#define PS_DEC
#define MAIN_DEC
#define LTP_DEC
#define LD_DEC
#define SSR_DEC
#define SBR_DEC

static inline int min(int a, int b) { return a < b ? a : b; }
static inline int max(int a, int b) { return a > b ? a : b; }

int64_t faad_get_ts();
uint8_t allocate_single_channel(NeAACDecStruct *hDecoder, int channel, int output_channels);
uint8_t quant_to_spec(NeAACDecStruct *hDecoder, ic_stream *ics, int16_t *spec_data, real_t *spec_coef, int frameLength);
void pns_decode(ic_stream *ics, void *a, real_t *b, void *c, int d, int e, int f, void *g, void *h);
void ic_prediction(ic_stream *ics, real_t *spec_coef, void *pred_stat, int frameLength, int sf_index);
void pns_reset_pred_state(ic_stream *ics, void *pred_stat);
int is_ltp_ot(int object_type);
void lt_prediction(ic_stream *ics, void *ltp, real_t *spec_coef, void *lt_pred_stat, void *fb, int window_shape, int window_shape_prev, int sf_index, int object_type, int frameLength);
void tns_decode_frame(ic_stream *ics, void *tns, int sf_index, int object_type, real_t *spec_coef, int frameLength);
void drc_decode(drc_info *drc, real_t *spec_coef);
void ifilter_bank(void *fb, int window_sequence, int window_shape, int window_shape_prev, real_t *spec_coef, void *time_out, void *fb_intermed, int object_type, int frameLength);
void ssr_decode(ssr_info *ssr, void *fb, int window_sequence, int window_shape, int window_shape_prev, real_t *spec_coef, void *time_out, void *ssr_overlap, void *ipqf_buffer, void *prev_fmd, int frameLength);
void lt_update_state(void *lt_pred_stat, void *time_out, void *fb_intermed, int frameLength, int object_type);
sbr_info *sbrDecodeInit(int frameLength, int element_id, int sample_rate, int downSampledSBR, ...);
uint8_t sbrDecodeSingleFrame(sbr_info *sbr, void *time_out, int postSeekResetFlag, int downSampledSBR);
uint8_t sbrDecodeSingleFramePS(sbr_info *sbr, void *time_out1, void *time_out2, int postSeekResetFlag, int downSampledSBR);
int get_sample_rate(int sf_index);