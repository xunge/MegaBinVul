#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef unsigned int JDIMENSION;
typedef int boolean;

typedef struct jpeg_common_struct *j_common_ptr;
typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef struct jpeg_destination_mgr *djpeg_dest_ptr;
typedef struct cd_progress_mgr {
    int total_extra_passes;
} *cd_progress_ptr;
typedef struct bmp_dest_struct bmp_dest_struct;
typedef bmp_dest_struct *bmp_dest_ptr;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

struct jpeg_memory_mgr {
    void *(*alloc_small)(j_common_ptr, int, size_t);
    JSAMPARRAY (*alloc_sarray)(j_common_ptr, int, JDIMENSION, JDIMENSION);
    JSAMPARRAY (*request_virt_sarray)(j_common_ptr, int, boolean, JDIMENSION, JDIMENSION, JDIMENSION);
};

struct jpeg_decompress_struct {
    struct jpeg_memory_mgr *mem;
    int out_color_space;
    boolean quantize_colors;
    JDIMENSION output_width;
    JDIMENSION output_height;
    int output_components;
    struct cd_progress_mgr *progress;
};

struct bmp_dest_struct {
    struct {
        void (*start_output)(j_decompress_ptr, bmp_dest_ptr);
        void (*finish_output)(j_decompress_ptr, bmp_dest_ptr);
        void (*calc_buffer_dimensions)(j_decompress_ptr, bmp_dest_ptr);
        void (*put_pixel_rows)(j_decompress_ptr, bmp_dest_ptr, JDIMENSION);
        JSAMPARRAY buffer;
        int buffer_height;
    } pub;
    boolean is_os2;
    JDIMENSION row_width;
    JDIMENSION data_width;
    int pad_bytes;
    JSAMPARRAY whole_image;
    JDIMENSION cur_output_row;
    JSAMPLE *iobuffer;
    boolean use_inversion_array;
};

#define JPOOL_IMAGE 0
#define JCS_GRAYSCALE 1
#define JCS_RGB565 2
#define JCS_CMYK 3
#define JERR_BMP_COLORSPACE 4
#define FALSE 0

#define GLOBAL(type) type
#define ERREXIT(cinfo,code) return NULL
#define IsExtRGB(cs) ((cs) >= 5)

void start_output_bmp(j_decompress_ptr, bmp_dest_ptr);
void finish_output_bmp(j_decompress_ptr, bmp_dest_ptr);
void put_gray_rows(j_decompress_ptr, bmp_dest_ptr, JDIMENSION);
void put_pixel_rows(j_decompress_ptr, bmp_dest_ptr, JDIMENSION);
void jpeg_calc_output_dimensions(j_decompress_ptr);