#include <stddef.h>

#define ModuleExport
typedef unsigned int MagickBooleanType;
#define MagickTrue 1
#define MagickFalse 0

typedef size_t (*DecodeImageHandler)(const char *);
typedef size_t (*EncodeImageHandler)(const char *);
typedef MagickBooleanType (*IsImageFormatHandler)(const unsigned char *,const size_t);

struct _MagickInfo {
    const char *description;
    const char *module;
    MagickBooleanType seekable_stream;
    MagickBooleanType stealth;
    DecodeImageHandler *decoder;
    EncodeImageHandler *encoder;
    IsImageFormatHandler *magick;
};
typedef struct _MagickInfo MagickInfo;

extern MagickInfo *SetMagickInfo(const char *);
extern const char *ConstantString(const char *);
extern size_t RegisterMagickInfo(MagickInfo *);
extern size_t ReadMPCImage(const char *);
extern size_t WriteMPCImage(const char *);
extern MagickBooleanType IsMPC(const unsigned char *,const size_t);
extern size_t MagickImageCoderSignature;