#include <stddef.h>

typedef int MagickBooleanType;
#define MagickTrue 1
#define MagickFalse 0

#define ResourceLimitError 1
#define CoderError 2

typedef struct {
    int verbose;
} ImageInfo;

typedef struct {
    struct Image *next;
    char *filename;
    unsigned int delay;
    unsigned int ticks_per_second;
    struct {
        unsigned int width;
        unsigned int height;
    } page;
} Image;

typedef struct {
} ExceptionInfo;

typedef struct {
} WebPConfig;

typedef struct {
} WebPData;

typedef struct {
    int verbose;
} WebPAnimEncoderOptions;

typedef struct {
} WebPPicture;

typedef struct {
} WebPAnimEncoder;

Image *CoalesceImages(Image *, ExceptionInfo *);
Image *GetNextImageInList(Image *);
void DestroyImageList(Image *);
void *ThrowMagickException(ExceptionInfo *, const void *, int, const char *, const char *, ...);
const void *GetMagickModule(void);
MagickBooleanType WriteSingleWEBPPicture(const ImageInfo *, Image *, WebPConfig *, WebPPicture *, ExceptionInfo *);
void WebPAnimEncoderOptionsInit(WebPAnimEncoderOptions *);
WebPAnimEncoder *WebPAnimEncoderNew(int, int, const WebPAnimEncoderOptions *);
int WebPPictureInit(WebPPicture *);
int WebPAnimEncoderAdd(WebPAnimEncoder *, const WebPPicture *, int, const WebPConfig *);
void WebPPictureFree(WebPPicture *);
const char *WebPAnimEncoderGetError(WebPAnimEncoder *);
int WebPAnimEncoderAssemble(WebPAnimEncoder *, WebPData *);
void WebPAnimEncoderDelete(WebPAnimEncoder *);