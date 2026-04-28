#include <stddef.h>
#include <string.h>

#define MaxTextExtent 2048
#define MagickTrue 1
#define MagickFalse 0
#define MAGICKCORE_PNG_DELEGATE
#define JNG_SUPPORTED
#define IMPNG_SETJMP_NOT_THREAD_SAFE

typedef struct _MagickInfo {
    void *decoder;
    void *encoder;
    void *magick;
    int adjoin;
    int seekable_stream;
    const char *description;
    const char *version;
    const char *mime_type;
    const char *module;
    const char *note;
} MagickInfo;

typedef size_t (*DecodeImageHandler)(void);
typedef size_t (*EncodeImageHandler)(void);
typedef unsigned int (*IsImageFormatHandler)(void);

extern char *png_get_header_ver(void *);
extern char *png_get_libpng_ver(void *);
extern char *zlib_version;
extern MagickInfo *SetMagickInfo(const char *);
extern char *ConcatenateMagickString(char *,const char *,size_t);
extern int LocaleCompare(const char *,const char *);
extern char *ConstantString(const char *);
extern size_t RegisterMagickInfo(MagickInfo *);
extern void *AllocateSemaphoreInfo(void);
extern size_t MagickImageCoderSignature;

extern size_t ReadMNGImage(void);
extern size_t WriteMNGImage(void);
extern unsigned int IsMNG(void);
extern size_t ReadPNGImage(void);
extern size_t WritePNGImage(void);
extern unsigned int IsPNG(void);
extern size_t ReadJNGImage(void);
extern size_t WriteJNGImage(void);
extern unsigned int IsJNG(void);

#ifdef IMPNG_SETJMP_NOT_THREAD_SAFE
static void *ping_semaphore;
#endif

#define ModuleExport