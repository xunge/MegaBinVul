#include <stddef.h>
#include <string.h>

#define METHODDEF(type) static type
#define LOCAL(type) static type

#define JDIMENSION unsigned int
#define JSAMPLE unsigned char
#define JSAMPROW JSAMPLE *
#define JSAMPARRAY JSAMPROW *
#define JERR_BAD_PARAM 1
#define GETJSAMPLE(x) (x)
#define ODITHER_MASK 7
#define MAXJSAMPLE 255

struct jpeg_error_mgr {
  void (*error_exit) (void *);
};

struct jpeg_decompress_struct {
  struct my_cquantizer *cquantize;
  int out_color_components;
  JDIMENSION output_width;
  struct jpeg_error_mgr *err;
};

typedef struct jpeg_decompress_struct *j_decompress_ptr;

typedef struct my_cquantizer {
  int row_index;
  JSAMPROW *colorindex;
  int **odither[4];
} *my_cquantize_ptr;

#define ERREXIT(cinfo,code) ((cinfo)->err->error_exit((cinfo)))
#define jzero_far(ptr, size) memset(ptr, 0, size)