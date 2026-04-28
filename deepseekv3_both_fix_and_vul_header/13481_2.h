typedef unsigned char _JSAMPLE;
typedef _JSAMPLE* _JSAMPROW;
typedef int JDIMENSION;
typedef short* JDIFFROW;

struct jpeg_decompress_struct {
    int Al;
};
typedef struct jpeg_decompress_struct* j_decompress_ptr;

#define METHODDEF(type) static type