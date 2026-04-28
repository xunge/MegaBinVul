#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int FT_Error;
typedef unsigned int FT_UInt;
typedef int FT_Int;
typedef unsigned char FT_Byte;
typedef struct FT_Memory_  *FT_Memory;

typedef enum  FT_Pixel_Mode_
{
  FT_PIXEL_MODE_NONE = 0,
  FT_PIXEL_MODE_MONO,
  FT_PIXEL_MODE_GRAY,
  FT_PIXEL_MODE_GRAY2,
  FT_PIXEL_MODE_GRAY4,
  FT_PIXEL_MODE_LCD,
  FT_PIXEL_MODE_LCD_V,
  FT_PIXEL_MODE_BGRA,
  FT_PIXEL_MODE_MAX
} FT_Pixel_Mode;

typedef struct  FT_Bitmap_
{
  unsigned int   rows;
  unsigned int   width;
  int            pitch;
  unsigned char* buffer;
  unsigned short num_grays;
  unsigned char  pixel_mode;
  unsigned char  palette_mode;
  void*          palette;
} FT_Bitmap;

#define FT_THROW(e)  (-(e))
#define FT_Err_Ok 0
#define Invalid_Glyph_Format 1

#define FT_QALLOC_MULT(ptr, count, mult) \
  ( (ptr) = malloc( (count) * (mult) ), (ptr) == NULL ? 1 : 0 )

#define FT_FREE(ptr) free(ptr)
#define FT_MEM_ZERO(dest, count) memset((dest), 0, (count))
#define FT_MEM_COPY(dest, source, count) memcpy((dest), (source), (count))