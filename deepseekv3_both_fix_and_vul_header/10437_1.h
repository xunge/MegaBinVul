#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef unsigned char MagickBooleanType;
typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;

typedef struct _ImageInfo ImageInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _Image Image;
typedef struct _PixelPacket PixelPacket;

#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define ReadBinaryBlobMode 0
#define ResourceLimitError 0
#define CorruptImageError 0
#define TraceEvent 0
#define YCCColorspace 0
#define sRGBColorspace 0
#define LoadImageTag 0
#define MaxTextExtent 1024
#define SEEK_SET 0

#define ScaleCharToQuantum(c) ((c) * 257)
#define MagickMin(a,b) ((a) < (b) ? (a) : (b))

struct _ExceptionInfo {
    char signature;
};

struct _PixelPacket {
    unsigned long red;
    unsigned long green;
    unsigned long blue;
};

struct _Image {
    size_t columns;
    size_t rows;
    unsigned depth;
    char *filename;
    char *magick_filename;
    size_t scene;
    struct _ExceptionInfo exception;
    Image *previous;
    Image *next;
    unsigned colorspace;
    double gamma;
    struct {
        struct {
            double x;
            double y;
        } red_primary;
        struct {
            double x;
            double y;
        } green_primary;
        struct {
            double x;
            double y;
        } blue_primary;
        struct {
            double x;
            double y;
        } white_point;
    } chromaticity;
    void *client_data;
    unsigned debug;
    char signature;
};

struct _ImageInfo {
    char signature;
    unsigned debug;
    char *filename;
    size_t number_scenes;
    size_t scene;
    char *magick;
    unsigned ping;
};

typedef void (*MagickProgressMonitor)(const char *,const MagickOffsetType,const MagickSizeType,void *);

Image *AcquireImage(const ImageInfo *);
MagickBooleanType OpenBlob(const ImageInfo *,Image *,int,ExceptionInfo *);
Image *DestroyImageList(Image *);
void *AcquireQuantumMemory(size_t,size_t);
void ThrowReaderException(unsigned,const char *);
ssize_t ReadBlob(Image *,size_t,void *);
int LocaleNCompare(const char *,const char *,size_t);
void *RelinquishMagickMemory(void *);
MagickBooleanType SetImageExtent(Image *,size_t,size_t);
void InheritException(ExceptionInfo *,ExceptionInfo *);
void Upsample(size_t,size_t,size_t,unsigned char *);
PixelPacket *QueueAuthenticPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *,ExceptionInfo *);
void SetPixelRed(PixelPacket *,unsigned long);
void SetPixelGreen(PixelPacket *,unsigned long);
void SetPixelBlue(PixelPacket *,unsigned long);
void SetImageColorspace(Image *,unsigned);
char *FormatLocaleString(char *,size_t,const char *,...);
void AcquireNextImage(const ImageInfo *,Image *);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
MagickProgressMonitor SetImageProgressMonitor(Image *,MagickProgressMonitor,void *);
MagickBooleanType SetImageProgress(Image *,unsigned,MagickOffsetType,MagickSizeType);
Image *GetFirstImageInList(Image *);
Image *OverviewImage(const ImageInfo *,Image *,ExceptionInfo *);
int EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *,unsigned,const char *,const char *);
int CloseBlob(Image *);
Image *RotateImage(Image *,double,ExceptionInfo *);
Image *DestroyImage(Image *);
int LocaleCompare(const char *,const char *);
const char *GetMagickModule(void);
void LogMagickEvent(unsigned,const char *,const char *,...);
MagickOffsetType TellBlob(Image *);
MagickOffsetType SeekBlob(Image *,MagickOffsetType,int);
MagickBooleanType DecodeImage(Image *,unsigned char *,unsigned char *,unsigned char *);
int ReadBlobByte(Image *);