#include <stddef.h>

#define ModuleExport

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

#define MAGICKCORE_X11_DELEGATE
#define CoderDecoderSeekableStreamFlag 1
#define CoderAdjoinFlag 2

typedef struct _MagickInfo {
    DecodeImageHandler *decoder;
    EncodeImageHandler *encoder;
    IsImageFormatHandler *magick;
    unsigned int flags;
} MagickInfo;

extern MagickInfo *AcquireMagickInfo(const char *, const char *, const char *);
extern size_t RegisterMagickInfo(MagickInfo *);
extern size_t ReadXWDImage(void);
extern size_t WriteXWDImage(void);
extern size_t IsXWD(void);
extern size_t MagickImageCoderSignature;