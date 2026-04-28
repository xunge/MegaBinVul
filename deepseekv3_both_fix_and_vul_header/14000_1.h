#include <stddef.h>

#define ModuleExport

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo MagickInfo;
struct _MagickInfo {
    DecodeImageHandler *decoder;
    IsImageFormatHandler *magick;
    unsigned int seekable_stream;
    unsigned int adjoin;
    const char *description;
    const char *module;
};

extern MagickInfo *SetMagickInfo(const char *);
extern size_t RegisterMagickInfo(MagickInfo *);
extern size_t ReadSFWImage(void);
extern size_t IsSFW(void);
extern const char *ConstantString(const char *);
extern size_t MagickImageCoderSignature;

#define MagickTrue 1
#define MagickFalse 0