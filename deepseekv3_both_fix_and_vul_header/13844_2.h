#include <stddef.h>

#define MaxTextExtent 4096
#define MagickFalse 0
#define MagickTrue 1
#define NoThreadSupport 0
#define MAGICKCORE_JPEG_DELEGATE
#define MagickImageCoderSignature 0

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef size_t (*IsImageFormatHandler)(void);

typedef struct _MagickInfo MagickInfo;
struct _MagickInfo {
    const char *name;
    const char *description;
    const char *version;
    const char *mime_type;
    const char *module;
    size_t (*decoder)(void);
    size_t (*encoder)(void);
    size_t (*magick)(void);
    int adjoin;
    int seekable_stream;
    int thread_support;
};

#define ModuleExport

extern size_t ReadJPEGImage(void);
extern size_t WriteJPEGImage(void);
extern size_t IsJPEG(void);
extern MagickInfo *SetMagickInfo(const char *);
extern const char *ConstantString(const char *);
extern int RegisterMagickInfo(MagickInfo *);
extern int FormatLocaleString(char *, size_t, const char *, ...);