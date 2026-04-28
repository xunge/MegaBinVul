#include <stdio.h>
#include <stdlib.h>

typedef unsigned int JDIMENSION;

struct jpeg_decompress_struct {
    struct my_main_struct *main;
    struct my_coef_struct *coef;
    struct my_master_struct *master;
    int global_state;
    JDIMENSION output_scanline;
    JDIMENSION output_height;
    struct jpeg_input_controller *inputctl;
    struct jpeg_upsampler *upsample;
    JDIMENSION _min_DCT_scaled_size;
    int max_v_samp_factor;
    JDIMENSION output_iMCU_row;
    JDIMENSION input_iMCU_row;
    JDIMENSION total_iMCU_rows;
    JDIMENSION MCUs_per_row;
    struct jpeg_entropy_decoder *entropy;
};

struct jpeg_input_controller {
    void (*finish_input_pass)(struct jpeg_decompress_struct *);
    int eoi_reached;
    int has_multiple_scans;
};

struct jpeg_upsampler {
    int need_context_rows;
};

struct jpeg_entropy_decoder {
    void (*decode_mcu)(struct jpeg_decompress_struct *, void *);
};

struct my_main_struct {
    int buffer_full;
    int iMCU_row_ctr;
    int rowgroup_ctr;
    int context_state;
};

struct my_coef_struct {
    int MCU_rows_per_iMCU_row;
};

struct my_master_struct {
    int using_merged_upsample;
};

struct my_merged_upsample_struct {
    int spare_full;
    JDIMENSION rows_to_go;
};

struct my_upsample_struct {
    int next_row_out;
    JDIMENSION rows_to_go;
};

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef struct my_main_struct *my_main_ptr;
typedef struct my_coef_struct *my_coef_ptr;
typedef struct my_master_struct *my_master_ptr;
typedef struct my_merged_upsample_struct *my_merged_upsample_ptr;
typedef struct my_upsample_struct *my_upsample_ptr;

#define DSTATE_SCANNING 0
#define JERR_BAD_STATE 0
#define TRUE 1
#define FALSE 0
#define CTX_PREPARE_FOR_IMCU 0

#define ERREXIT1(cinfo, code, arg) exit(1)
#define GLOBAL(type) type

void read_and_discard_scanlines(j_decompress_ptr cinfo, JDIMENSION num_lines);
void set_wraparound_pointers(j_decompress_ptr cinfo);
void increment_simple_rowgroup_ctr(j_decompress_ptr cinfo, JDIMENSION num_lines);
void start_iMCU_row(j_decompress_ptr cinfo);