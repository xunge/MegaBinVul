#include <stdbool.h>
#include <stdint.h>

typedef enum {
    DE265_OK,
    DE265_ERROR_CODED_PARAMETER_OUT_OF_RANGE
} de265_error;

typedef struct error_queue error_queue;
typedef struct bitreader bitreader;
typedef struct seq_parameter_set {
    int sps_max_sub_layers;
} seq_parameter_set;

#define READ_VLC_OFFSET(var, vlc, offset) var = get_bits(br, vlc) + offset
#define uvlc 0

struct video_usability_information {
    bool nal_hrd_parameters_present_flag;
    bool vcl_hrd_parameters_present_flag;
    bool sub_pic_hrd_params_present_flag;
    bool sub_pic_cpb_params_in_pic_timing_sei_flag;
    uint8_t tick_divisor_minus2;
    uint8_t du_cpb_removal_delay_increment_length_minus1;
    uint8_t dpb_output_delay_du_length_minus1;
    uint8_t bit_rate_scale;
    uint8_t cpb_size_scale;
    uint8_t cpb_size_du_scale;
    uint8_t initial_cpb_removal_delay_length_minus1;
    uint8_t au_cpb_removal_delay_length_minus1;
    uint8_t dpb_output_delay_length_minus1;
    bool fixed_pic_rate_general_flag[8];
    bool fixed_pic_rate_within_cvs_flag[8];
    bool low_delay_hrd_flag[8];
    uint8_t cpb_cnt_minus1[8];
    uint32_t elemental_duration_in_tc_minus1[8];
    uint32_t bit_rate_value_minus1[8][32][2];
    uint32_t cpb_size_value_minus1[8][32][2];
    uint32_t cpb_size_du_value_minus1[8][32][2];
    uint32_t bit_rate_du_value_minus1[8][32][2];
    bool cbr_flag[8][32][2];

    de265_error hrd_parameters(error_queue* errqueue, bitreader* br, const seq_parameter_set* sps);
};

static inline uint32_t get_bits(bitreader* br, int n) { return 0; }