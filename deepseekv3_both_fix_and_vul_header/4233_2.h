#include <stdint.h>
#include <string.h>

#define LITERALROW 0x00
#define LITERALSPAN 0x01

typedef int32_t tmsize_t;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

typedef struct {
    uint32_t td_imagewidth;
    uint32_t td_tilewidth;
} TIFFDirectory;

typedef struct {
    uint8* tif_rawcp;
    tmsize_t tif_rawcc;
    tmsize_t tif_scanlinesize;
    uint32_t tif_row;
    void* tif_clientdata;
    TIFFDirectory tif_dir;
} TIFF;

#define _TIFFmemcpy(dest, src, size) memcpy(dest, src, size)
#define SETPIXEL(op, grey) (*(op)++ = (grey))

extern void TIFFErrorExt(void*, const char*, const char*, ...);
extern int isTiled(TIFF*);