#include <assert.h>
#include <string.h>
#include <stdarg.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define QuantumRange 65535
#define OpaqueOpacity 0
#define TransparentOpacity QuantumRange
#define sRGBColorspace 1
#define PaletteType 1
#define PseudoClass 1
#define SaveImageTag 0
#define TraceEvent 0
#define ResourceLimitError 0
#define BasePath 0
#define WriteBinaryBlobMode 1

typedef unsigned long MagickSizeType;
typedef long MagickOffsetType;
typedef long ssize_t;
typedef unsigned long size_t;
typedef int MagickBooleanType;
typedef unsigned short Quantum;
typedef double MagickRealType;

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _MagickPixelPacket MagickPixelPacket;
typedef Quantum PixelPacket;
typedef Quantum IndexPacket;

struct _ExceptionInfo {
    int signature;
};

struct _ImageInfo {
    int signature;
    Image *image;
};

struct _Image {
    int signature;
    int debug;
    char *filename;
    ExceptionInfo exception;
    size_t columns;
    size_t rows;
    size_t colors;
    int storage_class;
    int matte;
    PixelPacket *colormap;
    int type;
};

struct _MagickPixelPacket {
    int colorspace;
    int depth;
    MagickRealType opacity;
};

static const char *GetMagickModule(void);
static void *AcquireQuantumMemory(size_t, size_t);
static void *RelinquishMagickMemory(void *);
static char *AcquireString(const char *);
static char *DestroyString(char *);
static void GetMagickPixelPacket(Image *, MagickPixelPacket *);
static void SetMagickPixelPacket(Image *, PixelPacket *, IndexPacket *, MagickPixelPacket *);
static void GetColorTuple(MagickPixelPacket *, MagickBooleanType, char *);
static void GetPathComponent(const char *, int, char *);
static int FormatLocaleString(char *, size_t, const char *, ...);
static int LocaleCompare(const char *, const char *);
static int SubstituteString(char **, const char *, const char *);
static int LogMagickEvent(int, const char *, const char *, const char *);
static int OpenBlob(ImageInfo *, Image *, int, ExceptionInfo *);
static int CloseBlob(Image *);
static int WriteBlobString(Image *, const char *);
static int TransformImageColorspace(Image *, int);
static int SetImageType(Image *, int);
static int SetImageProgress(Image *, int, MagickOffsetType, size_t);
static const PixelPacket *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static PixelPacket *GetAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
static const IndexPacket *GetVirtualIndexQueue(Image *);
static IndexPacket *GetAuthenticIndexQueue(Image *);
static Quantum GetPixelOpacity(const PixelPacket *);
static Quantum GetPixelIndex(const IndexPacket *);
static Quantum GetPixelLuma(Image *, const PixelPacket *);
static void SetPixelIndex(IndexPacket *, size_t);
static void ThrowWriterException(int, const char *);
static int CopyMagickString(char *, const char *, size_t);