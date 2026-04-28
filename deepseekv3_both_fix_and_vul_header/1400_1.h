#include <stddef.h>
#include <stdbool.h>

typedef struct jpeg_decompress_struct {
    void *upsample;
    int out_color_space;
    unsigned int output_width;
} *j_decompress_ptr;

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef unsigned int JDIMENSION;

typedef void (*upsample_method_ptr)(j_decompress_ptr, JSAMPIMAGE,
                                  JDIMENSION, JSAMPROW *);

typedef struct my_upsample_struct {
    JDIMENSION out_row_width;
    JSAMPROW spare_row;
    JDIMENSION rows_to_go;
    bool spare_full;
    upsample_method_ptr upmethod;
} *my_upsample_ptr;

typedef struct my_merged_upsample_struct {
    JDIMENSION out_row_width;
    JSAMPROW spare_row;
    JDIMENSION rows_to_go;
    bool spare_full;
    upsample_method_ptr upmethod;
} *my_merged_upsample_ptr;

#define JCS_RGB565 7
#define METHODDEF(type) static type
#define FALSE false
#define TRUE true

extern void jcopy_sample_rows(JSAMPARRAY input_array, int source_row,
                            JSAMPARRAY output_array, int dest_row,
                            int num_rows, JDIMENSION num_cols);