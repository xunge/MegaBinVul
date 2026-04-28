#include <stdio.h>

#define METHODDEF(return_type) return_type

typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef unsigned int JDIMENSION;
typedef unsigned char *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;

typedef struct my_merged_upsample_struct *my_merged_upsample_ptr;
typedef struct my_upsample_struct *my_upsample_ptr;

struct my_merged_upsample_struct {
  void (*upmethod)(j_decompress_ptr, JSAMPIMAGE, JDIMENSION, JSAMPARRAY);
};

struct my_upsample_struct {
  void (*upmethod)(j_decompress_ptr, JSAMPIMAGE, JDIMENSION, JSAMPARRAY);
};

struct jpeg_decompress_struct {
  void *upsample;
};