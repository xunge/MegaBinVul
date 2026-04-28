#include <math.h>
#include <stddef.h>
#include <sys/types.h>

typedef unsigned int Quantum;
typedef unsigned int MagickSizeType;
typedef int MagickOffsetType;
typedef unsigned char MagickBooleanType;

#define MagickTrue 1
#define MagickFalse 0
#define LoadImageTag "LoadImage"

typedef struct _Image {
    size_t rows;
    size_t columns;
    struct _Image *previous;
    struct _ColormapEntry *colormap;
} Image;

typedef struct _ColormapEntry {
    Quantum red;
    Quantum green;
    Quantum blue;
} ColormapEntry;

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _DCMInfo {
    int samples_per_pixel;
    int bytes_per_pixel;
    int bits_allocated;
    int significant_bits;
    int signed_data;
    int polarity;
    int max_value;
    double rescale_slope;
    double rescale_intercept;
    int window_width;
    double window_center;
    unsigned int mask;
    size_t depth;
    Quantum *scale;
} DCMInfo;

typedef struct _DCMStreamInfo DCMStreamInfo;

typedef struct _PixelPacket {
    Quantum red;
    Quantum green;
    Quantum blue;
} PixelPacket;

typedef struct _IndexPacket {
    unsigned int index;
} IndexPacket;

typedef struct _LongPixelPacket {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
} LongPixelPacket;

PixelPacket *QueueAuthenticPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
IndexPacket *GetAuthenticIndexQueue(Image *);
MagickBooleanType SyncAuthenticPixels(Image *,ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *,const char *,MagickOffsetType,MagickOffsetType);
unsigned char ReadDCMByte(DCMStreamInfo *,Image *);
unsigned short ReadDCMShort(DCMStreamInfo *,Image *);
short ReadDCMSignedShort(DCMStreamInfo *,Image *);
size_t ConstrainColormapIndex(Image *,size_t);
Quantum GetQuantumRange(size_t);
void SetPixelIndex(IndexPacket *,size_t);
size_t GetPixelIndex(IndexPacket *);
void SetPixelRed(PixelPacket *,Quantum);
void SetPixelGreen(PixelPacket *,Quantum);
void SetPixelBlue(PixelPacket *,Quantum);
Quantum GetPixelRed(PixelPacket *);
Quantum GetPixelGreen(PixelPacket *);
Quantum GetPixelBlue(PixelPacket *);