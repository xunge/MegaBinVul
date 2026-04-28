#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

typedef unsigned char Quantum;
typedef unsigned int MagickBooleanType;
typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;
typedef double MagickRealType;

#define MagickCoreSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define RLECompression 1
#define FaxCompression 2
#define PALM_HAS_COLORMAP_FLAG 0x0001
#define PALM_IS_DIRECT_COLOR 0x0002
#define PALM_IS_COMPRESSED_FLAG 0x0004
#define PALM_HAS_TRANSPARENCY_FLAG 0x0008
#define PALM_COMPRESSION_RLE 1
#define PALM_COMPRESSION_SCANLINE 2
#define PALM_COMPRESSION_NONE 0
#define TransparentAlpha 0
#define sRGBColorspace 1
#define GRAYColorspace 2
#define PaletteType 3
#define DirectClass 4
#define PseudoClass 5
#define RiemersmaDitherMethod 1
#define NoDitherMethod 2
#define ResourceLimitError 1
#define SaveImagesTag 1
#define WriteBinaryBlobMode 1
#define SEEK_SET 0
#define TraceEvent 1
#define CharPixel 1
#define QuantumRange ((Quantum) 65535)

typedef struct _PixelInfo {
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
    MagickRealType alpha;
} PixelInfo;

typedef struct _ImageInfo {
    unsigned long signature;
    int compression;
    MagickBooleanType adjoin;
} ImageInfo;

typedef struct _Image {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    size_t columns;
    size_t rows;
    size_t colors;
    int storage_class;
    int colorspace;
    int type;
    PixelInfo *colormap;
} Image;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _QuantizeInfo {
    int dither_method;
    size_t number_colors;
} QuantizeInfo;

extern unsigned char PalmPalette[];
extern void *AcquireQuantumMemory(size_t,size_t);
extern void *RelinquishMagickMemory(void *);
extern void CopyMagickMemory(void *,const void *,size_t);
extern void ResetMagickMemory(void *,int,size_t);
extern MagickBooleanType LogMagickEvent(int,const char *,const char *,...);
extern MagickBooleanType OpenBlob(const ImageInfo *,Image *,int,ExceptionInfo *);
extern MagickBooleanType QuantizeImage(QuantizeInfo *,Image *,ExceptionInfo *);
extern MagickBooleanType RemapImage(QuantizeInfo *,Image *,Image *,ExceptionInfo *);
extern MagickBooleanType SetImageProgress(Image *,int,MagickOffsetType,size_t);
extern MagickBooleanType SetImageStorageClass(Image *,int,ExceptionInfo *);
extern MagickBooleanType SetImageType(Image *,int,ExceptionInfo *);
extern MagickBooleanType SortColormapByIntensity(Image *,ExceptionInfo *);
extern MagickBooleanType TransformImageColorspace(Image *,int,ExceptionInfo *);
extern MagickOffsetType SeekBlob(Image *,MagickOffsetType,int);
extern Quantum *GetAuthenticPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
extern const Quantum *GetVirtualPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
extern QuantizeInfo *AcquireQuantizeInfo(const ImageInfo *);
extern QuantizeInfo *DestroyQuantizeInfo(QuantizeInfo *);
extern Image *ConstituteImage(size_t,size_t,const char *,int,const void *,ExceptionInfo *);
extern Image *DestroyImage(Image *);
extern Image *GetNextImageInList(Image *);
extern Image *SyncNextImageInList(Image *);
extern size_t GetBlobSize(Image *);
extern size_t GetImageListLength(Image *);
extern size_t GetNumberColors(Image *,void *,ExceptionInfo *);
extern unsigned char ScaleQuantumToChar(Quantum);
extern unsigned char ClampToQuantum(double);
extern unsigned short WriteBlobMSBShort(Image *,unsigned short);
extern unsigned char WriteBlobByte(Image *,unsigned char);
extern size_t WriteBlob(Image *,size_t,const unsigned char *);
extern unsigned int WriteBlobMSBLong(Image *,unsigned int);
extern void CloseBlob(Image *);
extern void ThrowWriterException(int,const char *);
extern const char *GetMagickModule(void);
extern int IdentifyPaletteImage(Image *,ExceptionInfo *);
extern Quantum GetPixelRed(const Image *,const Quantum *);
extern Quantum GetPixelGreen(const Image *,const Quantum *);
extern Quantum GetPixelBlue(const Image *,const Quantum *);
extern Quantum GetPixelAlpha(const Image *,const Quantum *);
extern Quantum GetPixelIndex(const Image *,const Quantum *);
extern void SetPixelIndex(Image *,Quantum,Quantum *);
extern size_t GetPixelChannels(const Image *);
extern size_t MagickMax(size_t,size_t);
extern size_t MagickMin(size_t,size_t);
extern int FindColor(const PixelInfo *);