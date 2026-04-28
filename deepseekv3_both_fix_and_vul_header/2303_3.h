#include <stddef.h>

#define METHODDEF(return_type) static return_type

typedef unsigned int JDIMENSION;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef struct my_post_struct *my_post_ptr;

struct my_post_struct {
    int strip_height;
    JSAMPARRAY buffer;
};

struct jpeg_decompress_struct {
    struct {
        void (*upsample)(j_decompress_ptr, JSAMPIMAGE, JDIMENSION*, JDIMENSION, JSAMPARRAY, JDIMENSION*, JDIMENSION);
    } *upsample;
    struct {
        void (*color_quantize)(j_decompress_ptr, JSAMPARRAY, JSAMPARRAY, int);
    } *cquantize;
    my_post_ptr post;
};