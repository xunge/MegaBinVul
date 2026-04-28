#include <stddef.h>

#define ModuleExport

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(const unsigned char *,const size_t);

typedef struct _MagickInfo {
    DecodeImageHandler *decoder;
    IsImageFormatHandler *magick;
    unsigned int flags;
} MagickInfo;

#define CoderBlobSupportFlag (1 << 0)
#define CoderAdjoinFlag (1 << 1)

extern MagickInfo *AcquireMagickInfo(const char *,const char *,const char *);
extern size_t RegisterMagickInfo(MagickInfo *);
extern size_t ReadRLEImage(void);
extern size_t IsRLE(const unsigned char *,const size_t);
extern size_t MagickImageCoderSignature;