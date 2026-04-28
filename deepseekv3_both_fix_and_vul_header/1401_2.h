#include <stdbool.h>

#define METHODDEF(type) static type
#define FALSE false

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef struct my_merged_upsample_struct *my_merged_upsample_ptr;
typedef struct my_upsample_struct *my_upsample_ptr;

struct jpeg_decompress_struct {
    void *upsample;
    int output_height;
};

struct my_merged_upsample_struct {
    bool spare_full;
    int rows_to_go;
};

struct my_upsample_struct {
    bool spare_full;
    int rows_to_go;
};