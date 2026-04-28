#include <stddef.h>

#define ModuleExport
#define MagickTrue 1
#define MagickFalse 0

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo MagickInfo;
struct _MagickInfo {
    const char *name;
    DecodeImageHandler *decoder;
    EncodeImageHandler *encoder;
    IsImageFormatHandler *magick;
    int seekable_stream;
    int adjoin;
    const char *description;
    const char *note;
    const char *module;
};

extern MagickInfo *SetMagickInfo(const char *);
extern const char *ConstantString(const char *);
extern void RegisterMagickInfo(MagickInfo *);
extern size_t MagickImageCoderSignature;
extern size_t ReadDPXImage(void);
extern size_t WriteDPXImage(void);
extern size_t IsDPX(void);