#include <stddef.h>

#define ModuleExport

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo {
    DecodeImageHandler *decoder;
    EncodeImageHandler *encoder;
    IsImageFormatHandler *magick;
    unsigned int flags;
} MagickInfo;

#define CoderDecoderSeekableStreamFlag (1 << 0)

MagickInfo *AcquireMagickInfo(const char *, const char *, const char *);
size_t RegisterMagickInfo(MagickInfo *);
size_t ReadVIFFImage(void);
size_t WriteVIFFImage(void);
size_t IsVIFF(void);

extern size_t MagickImageCoderSignature;