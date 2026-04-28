#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

typedef int gboolean;
typedef unsigned char guchar;
typedef int gint;
typedef unsigned int guint32;
typedef int gint32;
typedef unsigned int png_uint_32;
typedef void* png_structp;
typedef void* png_infop;
typedef void* png_bytepp;

#define FALSE 0
#define TRUE 1
#define D(x)
#define PNG_LIBPNG_VER_STRING "1.6.0"
#define PNG_FILLER_AFTER 1
#define PNG_INFO_tRNS 0x10
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COLOR_TYPE_GRAY_ALPHA 4
#define PNG_COLOR_TYPE_PALETTE 3
#define PNG_COLOR_TYPE_RGB 2
#define PNG_COLOR_TYPE_RGB_ALPHA 6

#define g_new(type, size) ((type*)malloc(sizeof(type) * (size)))
#define g_free(ptr) free(ptr)

static void* png_create_read_struct(const char*, void*, void*, void*) { return NULL; }
static void* png_create_info_struct(void*) { return NULL; }
static void png_destroy_read_struct(void**, void**, void**) {}
static jmp_buf* png_jmpbuf(void*) { return NULL; }
static void png_init_io(void*, FILE*) {}
static void png_set_sig_bytes(void*, int) {}
static void png_read_info(void*, void*) {}
static void png_get_IHDR(void*, void*, png_uint_32*, png_uint_32*, int*, int*, int*, int*, int*) {}
static void png_set_expand_gray_1_2_4_to_8(void*) {}
static void png_set_strip_16(void*) {}
static void png_set_gray_to_rgb(void*) {}
static void png_set_add_alpha(void*, int, int) {}
static void png_set_palette_to_rgb(void*) {}
static int png_get_valid(void*, void*, int) { return 0; }
static void png_set_tRNS_to_alpha(void*) {}
static void png_read_image(void*, png_bytepp) {}