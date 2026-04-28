#include <stddef.h>

#define ModuleExport

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo MagickInfo;
struct _MagickInfo {
    const char *name;
    const char *description;
    DecodeImageHandler *decoder;
    EncodeImageHandler *encoder;
    IsImageFormatHandler *magick;
    unsigned int flags;
    const char *mime_type;
};

extern MagickInfo *AcquireMagickInfo(const char *, const char *, const char *);
extern void RegisterMagickInfo(MagickInfo *);
extern const char *ConstantString(const char *);
extern size_t ReadPSImage(void);
extern size_t WritePSImage(void);
extern size_t IsPS(void);
extern size_t MagickImageCoderSignature;

#define CoderDecoderSeekableStreamFlag (1 << 0)
#define CoderAdjoinFlag (1 << 1)
#define CoderBlobSupportFlag (1 << 2)