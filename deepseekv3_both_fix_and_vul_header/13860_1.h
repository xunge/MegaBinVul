#include <stddef.h>

#define ModuleExport

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo
{
  const char *name;
  const char *description;
  DecodeImageHandler decoder;
  IsImageFormatHandler magick;
  unsigned int flags;
} MagickInfo;

#define CoderDecoderSeekableStreamFlag 0x01
#define CoderAdjoinFlag 0x02
#define CoderBlobSupportFlag 0x04

extern MagickInfo *AcquireMagickInfo(const char *, const char *, const char *);
extern size_t RegisterMagickInfo(MagickInfo *);
extern size_t ReadRLEImage(void);
extern size_t IsRLE(void);
extern size_t MagickImageCoderSignature;