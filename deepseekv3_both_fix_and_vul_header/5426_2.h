#include <stdlib.h>
#include <setjmp.h>

typedef int FT_Int;
typedef unsigned char FT_Byte;
typedef unsigned int FT_UInt;
typedef int FT_Bool;
typedef long FT_Long;
typedef int FT_Error;

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

typedef struct TT_SBit_Metrics_ {
    FT_Int width;
    FT_Int height;
} *TT_SBit_Metrics;

typedef struct FT_MemoryRec_ *FT_Memory;
typedef struct FT_StreamRec_ {
    unsigned char* base;
    unsigned int size;
    unsigned int pos;
} FT_StreamRec;

typedef void* png_structp;
typedef void* png_infop;
typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte* png_bytep;
typedef png_byte** png_bytepp;

#define FT_LOCAL_DEF(x) x
#define FT_THROW(x) (x)
#define FT_Err_Ok 0
#define FT_PIXEL_MODE_BGRA 7
#define Invalid_Argument 1
#define Out_Of_Memory 2
#define Invalid_File_Format 3
#define Array_Too_Large 4

#define PNG_LIBPNG_VER_STRING "1.0.0"
#define PNG_COLOR_TYPE_PALETTE 1
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COLOR_TYPE_RGB 2
#define PNG_COLOR_TYPE_RGB_ALPHA 6
#define PNG_COLOR_TYPE_GRAY_ALPHA 4
#define PNG_INTERLACE_NONE 0
#define PNG_FILLER_AFTER 1
#define PNG_INFO_tRNS 0

#define FT_NEW_ARRAY(p, count) (p = malloc((count) * sizeof(*p)), p == NULL)
#define FT_FREE(p) free(p)

static void error_callback(png_structp png, const char* msg) {}
static void warning_callback(png_structp png, const char* msg) {}
static void read_data_from_FT_Stream(png_structp png, png_bytep data, size_t length) {}
static void premultiply_data(png_structp png, void* row_info, png_bytep data) {}
static void convert_bytes_to_data(png_structp png, void* row_info, png_bytep data) {}

FT_Error ft_glyphslot_alloc_bitmap(FT_GlyphSlot slot, FT_Long size);
void FT_Stream_OpenMemory(FT_StreamRec* stream, FT_Byte* data, FT_UInt len);
void FT_Stream_Close(FT_StreamRec* stream);

png_structp png_create_read_struct(const char*, void*, void (*)(png_structp, const char*), void (*)(png_structp, const char*));
png_infop png_create_info_struct(png_structp);
void png_destroy_read_struct(png_structp*, png_infop*, png_infop*);
void png_set_read_fn(png_structp, void*, void (*)(png_structp, png_bytep, size_t));
void png_read_info(png_structp, png_infop);
void png_get_IHDR(png_structp, png_infop, png_uint_32*, png_uint_32*, int*, int*, int*, int*, int*);
void png_set_palette_to_rgb(png_structp);
void png_set_expand_gray_1_2_4_to_8(png_structp);
void png_set_gray_1_2_4_to_8(png_structp);
void png_set_tRNS_to_alpha(png_structp);
void png_set_strip_16(png_structp);
void png_set_packing(png_structp);
void png_set_gray_to_rgb(png_structp);
void png_set_interlace_handling(png_structp);
void png_set_filler(png_structp, int, int);
void png_read_update_info(png_structp, png_infop);
void png_set_read_user_transform_fn(png_structp, void (*)(png_structp, void*, png_bytep));
void png_read_image(png_structp, png_bytepp);
void png_read_end(png_structp, png_infop);
int png_get_valid(png_structp, png_infop, int);
jmp_buf* png_jmpbuf(png_structp);
int ft_setjmp(jmp_buf);