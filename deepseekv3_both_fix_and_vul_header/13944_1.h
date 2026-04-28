#include <stddef.h>

#define ModuleExport
#define MagickTrue 1

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo MagickInfo;
struct _MagickInfo {
    const char *description;
    const char *module;
    DecodeImageHandler decoder;
    EncodeImageHandler encoder;
    IsImageFormatHandler magick;
    unsigned int seekable_stream;
};

extern MagickInfo *SetMagickInfo(const char *);
extern void *RegisterMagickInfo(MagickInfo *);
extern const char *ConstantString(const char *);
extern size_t ReadSUNImage(void);
extern size_t WriteSUNImage(void);
extern size_t IsSUN(void);
extern size_t MagickImageCoderSignature;