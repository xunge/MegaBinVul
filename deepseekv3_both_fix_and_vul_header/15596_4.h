#include <stdint.h>
#include <string.h>

#define EMSG_BUF_SIZE 1024

typedef struct TIFF TIFF;

struct TIFFRGBAImage {
    uint32_t width;
    uint32_t height;
    uint32_t row_offset;
    uint32_t col_offset;
};

extern int TIFFIsTiled(TIFF*);
extern void TIFFErrorExtR(TIFF*, const char*, const char*, ...);
extern const char* TIFFFileName(TIFF*);
extern void TIFFGetFieldDefaulted(TIFF*, int, uint32_t*);
extern int TIFFRGBAImageOK(TIFF*, char*);
extern int TIFFRGBAImageBegin(struct TIFFRGBAImage*, TIFF*, int, char*);
extern int TIFFRGBAImageGet(struct TIFFRGBAImage*, uint32_t*, uint32_t, uint32_t);
extern void TIFFRGBAImageEnd(struct TIFFRGBAImage*);
extern void _TIFFmemset(void*, int, size_t);

#define TIFFTAG_TILEWIDTH 322
#define TIFFTAG_TILELENGTH 323

typedef struct TIFFRGBAImage TIFFRGBAImage;