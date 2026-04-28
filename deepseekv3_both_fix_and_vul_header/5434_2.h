#include <stdlib.h>
#include <setjmp.h>

typedef struct FT_Bitmap_ {
    int width;
    int rows;
    int pitch;
    int pixel_mode;
    int num_grays;
    unsigned char* buffer;
} FT_Bitmap;

typedef struct FT_GlyphSlotRec_ {
    FT_Bitmap bitmap;
} *FT_GlyphSlot;

typedef struct FT_MemoryRec_ *FT_Memory;
typedef struct TT_SBit_MetricsRec_ {
    int width;
    int height;
} *TT_SBit_Metrics;
typedef struct FT_StreamRec_ {
    unsigned char* base;
    unsigned long size;
    unsigned long pos;
} FT_StreamRec;

typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef unsigned int FT_UInt;
typedef int FT_Int;
typedef long FT_Long;
typedef int FT_Bool;

typedef void* png_structp;
typedef void* png_infop;
typedef unsigned long png_uint_32;
typedef unsigned char png_byte;
typedef png_byte* png_bytep;
typedef png_byte** png_bytepp;
typedef size_t png_size_t;

#define FT_LOCAL_DEF(x) x
#define FT_THROW(x) x
#define FT_Err_Ok 0
#define FT_PIXEL_MODE_BGRA 7
#define Invalid_Argument 1
#define Out_Of_Memory 2
#define Invalid_File_Format 3
#define Array_Too_Large 4

#define FT_NEW_ARRAY(p, count) (p = malloc((count) * sizeof(*p))) ? 0 : 1
#define FT_FREE(p) free(p)

#define PNG_LIBPNG_VER_STRING "1.0.0"
#define PNG_COLOR_TYPE_PALETTE 1
#define PNG_COLOR_TYPE_GRAY 2
#define PNG_COLOR_TYPE_RGB 3
#define PNG_COLOR_TYPE_RGB_ALPHA 4
#define PNG_COLOR_TYPE_GRAY_ALPHA 5
#define PNG_INTERLACE_NONE 0
#define PNG_FILLER_AFTER 1
#define PNG_INFO_tRNS 0x10

static void error_callback(png_structp png, const char* msg) {}
static void warning_callback(png_structp png, const char* msg) {}
static void read_data_from_FT_Stream(png_structp png, png_bytep data, png_size_t length) {}
static void premultiply_data(png_structp png, void* row_info, png_bytep data) {}
static void convert_bytes_to_data(png_structp png, void* row_info, png_bytep data) {}

static void FT_Stream_OpenMemory(FT_StreamRec* stream, FT_Byte* data, FT_UInt size) {}
static void FT_Stream_Close(FT_StreamRec* stream) {}
static FT_Error ft_glyphslot_alloc_bitmap(FT_GlyphSlot slot, FT_Long size) { return 0; }

static png_structp png_create_read_struct(const char* ver, void* error_ptr, void* error_fn, void* warn_fn) { return NULL; }
static png_infop png_create_info_struct(png_structp png_ptr) { return NULL; }
static void png_destroy_read_struct(png_structp* png_ptr, png_infop* info_ptr, void* end_ptr) {}
static void png_set_read_fn(png_structp png_ptr, void* io_ptr, void* read_data_fn) {}
static void png_read_info(png_structp png_ptr, png_infop info_ptr) {}
static void png_get_IHDR(png_structp png_ptr, png_infop info_ptr, png_uint_32* width, png_uint_32* height, int* bit_depth, int* color_type, int* interlace_type, void* unused1, void* unused2) {}
static void png_set_palette_to_rgb(png_structp png_ptr) {}
static void png_set_expand_gray_1_2_4_to_8(png_structp png_ptr) {}
static void png_set_gray_1_2_4_to_8(png_structp png_ptr) {}
static int png_get_valid(png_structp png_ptr, png_infop info_ptr, int flag) { return 0; }
static void png_set_tRNS_to_alpha(png_structp png_ptr) {}
static void png_set_strip_16(png_structp png_ptr) {}
static void png_set_packing(png_structp png_ptr) {}
static void png_set_gray_to_rgb(png_structp png_ptr) {}
static void png_set_interlace_handling(png_structp png_ptr) {}
static void png_set_filler(png_structp png_ptr, int filler, int filler_loc) {}
static void png_read_update_info(png_structp png_ptr, png_infop info_ptr) {}
static void png_set_read_user_transform_fn(png_structp png_ptr, void* read_user_transform_fn) {}
static void png_read_image(png_structp png_ptr, png_bytepp image) {}
static void png_read_end(png_structp png_ptr, png_infop info_ptr) {}
static void* png_jmpbuf(png_structp png_ptr) { return NULL; }
static int ft_setjmp(void* env) { return 0; }