#include <assert.h>
#include <math.h>
#include <stddef.h>

#define MagickExport
#define MagickFalse 0
#define MagickTrue 1
#define MagickSignature 0x12345678
#define MaxTextExtent 4096
#define TraceEvent 0
#define CorruptImageError 0
#define ResourceLimitError 0

typedef unsigned char MagickBooleanType;
typedef size_t ssize_t;

typedef struct _BlobInfo BlobInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _TimerInfo TimerInfo;

struct PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
};

struct _TimerInfo {
    int dummy;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    size_t storage_class;
    size_t channels;
    size_t colorspace;
    MagickBooleanType matte;
    MagickBooleanType dither;
    size_t colors;
    struct PixelPacket *colormap;
    struct _TimerInfo timer;
    struct _ExceptionInfo exception;
    void *ascii85;
    size_t magick_columns;
    size_t magick_rows;
    size_t type;
    char magick_filename[MaxTextExtent];
    char magick[MaxTextExtent];
    char local_filename[MaxTextExtent];
    void (*progress_monitor)(void);
    void *client_data;
    size_t reference_count;
    struct _Image *next;
    struct _Image *previous;
    struct _Image *list;
    struct _Image *clip_mask;
    struct _Image *mask;
    struct _BlobInfo *blob;
    MagickBooleanType ping;
    void *semaphore;
    char *montage;
    char *directory;
    void *cache;
    struct {
        size_t width;
        size_t height;
        ssize_t x;
        ssize_t y;
    } page;
    struct {
        ssize_t x;
        ssize_t y;
    } tile_offset;
};

typedef struct PixelPacket PixelPacket;

void *AcquireMagickMemory(size_t);
void *AcquireQuantumMemory(size_t, size_t);
void Ascii85Initialize(Image *);
void *CloneBlobInfo(BlobInfo *);
void CloneImageProfiles(Image *, const Image *);
void CloneImageProperties(Image *, const Image *);
void CloneImageArtifacts(Image *, const Image *);
void *ClonePixelCache(void *);
void *CloneString(char **, const char *);
void CopyMagickMemory(void *, const void *, size_t);
void CopyMagickString(char *, const char *, size_t);
Image *DestroyImage(Image *);
void FreeMagickMemory(void *);
const char *GetMagickModule(void);
void GetTimerInfo(TimerInfo *);
void InheritException(ExceptionInfo *, const ExceptionInfo *);
void InitializeExceptionInfo(ExceptionInfo *);
MagickBooleanType IsEventLogging(void);
void *LogMagickEvent(size_t, const char *, const char *, ...);
Image *NewImageList(void);
void *ReferenceBlob(BlobInfo *);
void *ReferencePixelCache(void *);
void ResetMagickMemory(void *, int, size_t);
MagickBooleanType SetImageExtent(Image *, size_t, size_t);
void *AllocateSemaphoreInfo(void);
void ThrowImageException(size_t, const char *);
void *ThrowMagickException(ExceptionInfo *, const char *, size_t, const char *, const char *, ...);