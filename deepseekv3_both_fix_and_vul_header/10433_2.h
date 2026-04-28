#include <assert.h>
#include <stdlib.h>

typedef struct _Image Image;
typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _ExrWindow ExrWindow;
typedef struct _ImfHeader ImfHeader;
typedef struct _ImfInputFile ImfInputFile;
typedef struct _ImfRgba ImfRgba;
typedef enum _MagickBooleanType { MagickFalse, MagickTrue } MagickBooleanType;
typedef unsigned long Quantum;
typedef double MagickRealType;

#define MagickCoreSignature 0xABACADABUL
#define BlendPixelTrait 1
#define RGBColorspace 1
#define ResourceLimitError 1
#define TraceEvent 1
#define BlobError 1
#define ReadBinaryBlobMode 1
#define QuantumRange 65535.0

struct _ExrWindow {
    int min_x;
    int min_y;
    int max_x;
    int max_y;
};

struct _ImfRgba {
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short a;
};

struct _PixelInfo {
    double red;
    double green;
    double blue;
    double alpha;
};

struct _Image {
    size_t columns;
    size_t rows;
    int alpha_trait;
    double gamma;
    struct _PixelInfo background_color;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
};

struct _ExceptionInfo {
    unsigned long signature;
};

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
ImageInfo *CloneImageInfo(const ImageInfo *);
MagickBooleanType IsPathAccessible(const char *);
char *AcquireUniqueFilename(char *);
MagickBooleanType ImageToFile(Image *, const char *, ExceptionInfo *);
ImfInputFile *ImfOpenInputFile(const char *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
int LocaleCompare(const char *, const char *);
MagickBooleanType RelinquishUniqueFileResource(const char *);
ImageInfo *DestroyImageInfo(ImageInfo *);
const ImfHeader *ImfInputHeader(ImfInputFile *);
void ImfHeaderDisplayWindow(const ImfHeader *, int *, int *, int *, int *);
void SetImageColorspace(Image *, int, ExceptionInfo *);
MagickBooleanType SetImageExtent(Image *, size_t, size_t, ExceptionInfo *);
void ImfHeaderDataWindow(const ImfHeader *, int *, int *, int *, int *);
void *AcquireQuantumMemory(size_t, size_t);
void ThrowReaderException(int, const char *);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
void SetPixelViaPixelInfo(Image *, const struct _PixelInfo *, Quantum *);
void ResetMagickMemory(void *, int, size_t);
void ImfInputSetFrameBuffer(ImfInputFile *, const ImfRgba *, int, int);
void ImfInputReadPixels(ImfInputFile *, int, int);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
void *RelinquishMagickMemory(void *);
void ImfCloseInputFile(ImfInputFile *);
Image *GetFirstImageInList(Image *);
MagickBooleanType CloseBlob(Image *);
void LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);
const char *ImfErrorMessage(void);
size_t GetPixelChannels(const Image *);
double ImfHalfToFloat(unsigned short);
Quantum ClampToQuantum(double);
void SetPixelRed(Image *, Quantum, Quantum *);
void SetPixelGreen(Image *, Quantum, Quantum *);
void SetPixelBlue(Image *, Quantum, Quantum *);
void SetPixelAlpha(Image *, Quantum, Quantum *);