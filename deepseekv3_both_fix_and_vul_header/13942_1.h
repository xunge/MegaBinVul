#include <stddef.h>

#define ModuleExport

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo MagickInfo;
struct _MagickInfo {
    char *name;
    char *description;
    DecodeImageHandler *decoder;
    EncodeImageHandler *encoder;
    IsImageFormatHandler *magick;
    unsigned int flags;
};

extern MagickInfo *AcquireMagickInfo(const char *, const char *, const char *);
extern size_t RegisterMagickInfo(MagickInfo *);
extern size_t ReadSUNImage(void);
extern size_t WriteSUNImage(void);
extern size_t IsSUN(void);

#define CoderDecoderSeekableStreamFlag (1 << 0)
#define MagickImageCoderSignature 0xABACADAB