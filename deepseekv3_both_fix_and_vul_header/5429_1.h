#include <limits.h>

typedef int FT_Error;
typedef struct FT_LibraryRec_ {
    void* memory;
} * FT_Library;
typedef struct FT_Bitmap_ {
    unsigned char* buffer;
    int width;
    int rows;
    int pitch;
    unsigned char pixel_mode;
    unsigned char num_grays;
} FT_Bitmap;
typedef long FT_Pos;
typedef int FT_Int;
typedef unsigned int FT_UInt;

#define FT_EXPORT_DEF(x) x
#define FT_THROW(x) (x)
#define FT_PIX_ROUND(x) (x)
#define FT_INT_MAX INT_MAX

#define FT_PIXEL_MODE_GRAY2 0
#define FT_PIXEL_MODE_GRAY4 1
#define FT_PIXEL_MODE_MONO 2
#define FT_PIXEL_MODE_LCD 3
#define FT_PIXEL_MODE_LCD_V 4
#define FT_PIXEL_MODE_BGRA 5

#define FT_Err_Ok 0
#define Invalid_Library_Handle 1
#define Invalid_Argument 2

void FT_Bitmap_New(FT_Bitmap* bitmap);
FT_Error FT_Bitmap_Convert(FT_Library library, FT_Bitmap* source, FT_Bitmap* target, int alignment);
void FT_Bitmap_Done(FT_Library library, FT_Bitmap* bitmap);
FT_Error ft_bitmap_assure_buffer(void* memory, FT_Bitmap* bitmap, FT_Int xstr, FT_Int ystr);