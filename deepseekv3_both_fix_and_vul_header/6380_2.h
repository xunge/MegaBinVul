#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define ALIGN
#define PROFILE
#define MAIN_DEC
#define LTP_DEC
#define LD_DEC
#define SSR_DEC
#define SBR_DEC
#define DRM

#define MAIN 0
#define LD 1
#define SSR 2
#define EIGHT_SHORT_SEQUENCE 3

typedef float real_t;

typedef struct {
    int maxAACLine;
} sbr_info;

typedef struct {
    int channel;
    int paired_channel;
    int common_window;
    struct {
        int window_sequence;
        int max_sfb;
        int *swb_offset;
        int swb_offset_max;
        int ms_mask_present;
        struct {
            int data_present;
            int lag_update;
            int lag;
        } ltp;
        struct {
            int data_present;
            int lag_update;
            int lag;
        } ltp2;
        int window_shape;
        void *tns;
        void *ssr;
    } ics1;
} element;

typedef struct {
    int ms_mask_present;
    int frameLength;
    int window_sequence;
    int window_shape;
    int max_sfb;
    int *swb_offset;
    int swb_offset_max;
    struct {
        int data_present;
        int lag_update;
        int lag;
    } ltp;
    struct {
        int data_present;
        int lag_update;
        int lag;
    } ltp2;
    void *tns;
    void *ssr;
} ic_stream;

typedef struct {
    int element_alloced[16];
    int fr_ch_ele;
    void *time_out[16];
    int frameLength;
    int object_type;
    int64_t requant_cycles;
    int __r1;
    int __r2;
    void *pred_stat[16];
    int sf_index;
    void *lt_pred_stat[16];
    void *fb;
    int window_shape_prev[16];
    void *fb_intermed[16];
    void *ssr_overlap[16];
    void *ipqf_buffer[16];
    void *prev_fmd[16];
    struct {
        int present;
        int *exclude_mask;
        int excluded_chns_present;
    } *drc;
    int sbr_present_flag;
    int forceUpSampling;
    int sbr_alloced[16];
    sbr_info *sbr[16];
    int element_id[16];
    int downSampledSBR;
    int postSeekResetFlag;
    int ltp_lag[16];
} NeAACDecStruct;

typedef struct {
    int data_present;
    int lag_update;
    int lag;
} ltp_info;

static inline int min(int a, int b) { return a < b ? a : b; }
static inline int max(int a, int b) { return a > b ? a : b; }

int64_t faad_get_ts();
uint8_t allocate_channel_pair(NeAACDecStruct *hDecoder, int channel, uint8_t paired_channel);
uint8_t quant_to_spec(NeAACDecStruct *hDecoder, ic_stream *ics, int16_t *spec_data, real_t *spec_coef, int frameLength);
void pns_decode(ic_stream *ics1, ic_stream *ics2, real_t *spec_coef1, real_t *spec_coef2, int frameLength, int ms_present, int object_type, void *r1, void *r2);
void ms_decode(ic_stream *ics1, ic_stream *ics2, real_t *spec_coef1, real_t *spec_coef2, int frameLength);
void is_decode(ic_stream *ics1, ic_stream *ics2, real_t *spec_coef1, real_t *spec_coef2, int frameLength);
void ic_prediction(ic_stream *ics, real_t *spec_coef, void *pred_stat, int frameLength, int sf_index);
void pns_reset_pred_state(ic_stream *ics, void *pred_stat);
int is_ltp_ot(int object_type);
void lt_prediction(ic_stream *ics, ltp_info *ltp, real_t *spec_coef, void *lt_pred_stat, void *fb, int window_shape, int window_shape_prev, int sf_index, int object_type, int frameLength);
void tns_decode_frame(ic_stream *ics, void *tns, int sf_index, int object_type, real_t *spec_coef, int frameLength);
void drc_decode(void *drc, real_t *spec_coef);
void ifilter_bank(void *fb, int window_sequence, int window_shape, int window_shape_prev, real_t *spec_coef, void *time_out, void *fb_intermed, int object_type, int frameLength);
void ssr_decode(void *ssr, void *fb, int window_sequence, int window_shape, int window_shape_prev, real_t *spec_coef, void *time_out, void *ssr_overlap, void *ipqf_buffer, void *prev_fmd, int frameLength);
void lt_update_state(void *lt_pred_stat, void *time_out, void *fb_intermed, int frameLength, int object_type);
sbr_info *sbrDecodeInit(int frameLength, int element_id, int sample_rate, int downSampledSBR, ...);
int get_sample_rate(int sf_index);
uint8_t sbrDecodeCoupleFrame(sbr_info *sbr, void *time_out1, void *time_out2, int postSeekResetFlag, int downSampledSBR);