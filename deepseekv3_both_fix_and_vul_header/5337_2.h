#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

typedef long long MagickSizeType;
typedef long long MagickOffsetType;

typedef struct _CINInfo {
    struct {
        unsigned long image_offset;
        unsigned long generic_length;
        unsigned long industry_length;
        unsigned long user_length;
        unsigned long file_size;
        char version[8];
        char filename[100];
        char create_date[12];
        char create_time[12];
        char reserve[36];
    } file;
    struct {
        unsigned char orientation;
        unsigned char number_channels;
        char reserve1[2];
        struct {
            unsigned char designator[2];
            unsigned char bits_per_pixel;
            unsigned char reserve;
            unsigned long pixels_per_line;
            unsigned long lines_per_image;
            float min_data;
            float min_quantity;
            float max_data;
            float max_quantity;
        } channel[8];
        float white_point[2];
        float red_primary_chromaticity[2];
        float green_primary_chromaticity[2];
        float blue_primary_chromaticity[2];
        char label[200];
        char reserve[28];
    } image;
    struct {
        unsigned char interleave;
        unsigned char packing;
        unsigned char sign;
        unsigned char sense;
        unsigned long line_pad;
        unsigned long channel_pad;
        char reserve[20];
    } data_format;
    struct {
        ssize_t x_offset;
        ssize_t y_offset;
        char filename[100];
        char create_date[12];
        char create_time[12];
        char device[32];
        char model[32];
        char serial[32];
        float x_pitch;
        float y_pitch;
        float gamma;
        char reserve[40];
    } origination;
    struct {
        unsigned char id;
        unsigned char type;
        unsigned char offset;
        unsigned char reserve1;
        unsigned long prefix;
        unsigned long count;
        char format[32];
        unsigned long frame_position;
        float frame_rate;
        char frame_id[32];
        char slate_info[100];
        char reserve[56];
    } film;
} CINInfo;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _Point {
    float x;
    float y;
} Point;

typedef struct _Chromaticity {
    Point white_point;
    Point red_primary;
    Point green_primary;
    Point blue_primary;
} Chromaticity;

typedef struct _Image {
    unsigned long signature;
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    struct _Image *previous;
    struct _Image *next;
    char *filename;
    Chromaticity chromaticity;
    float gamma;
    unsigned long endian;
    unsigned long orientation;
} Image;

typedef struct _QuantumInfo {
    unsigned long quantum;
    MagickBooleanType pack;
    unsigned char *pixels;
} QuantumInfo;

typedef enum {
    RGBQuantum,
    GrayQuantum
} QuantumType;

typedef unsigned char Quantum;

typedef struct _StringInfo {
    unsigned char *datum;
    size_t length;
} StringInfo;

typedef void *CacheView;

#define MagickCoreSignature 0xabacadabUL
#define MagickPathExtent 4096
#define MSBEndian 1
#define LSBEndian 2
#define TopLeftOrientation 1
#define TopRightOrientation 2
#define BottomLeftOrientation 3
#define BottomRightOrientation 4
#define LeftTopOrientation 5
#define RightTopOrientation 6
#define LeftBottomOrientation 7
#define RightBottomOrientation 8
#define LogColorspace 1
#define ReadBinaryBlobMode 1
#define TraceEvent 1
#define LoadImageTag 1
#define CorruptImageError 1
#define ResourceLimitError 1

Image *AcquireImage(const ImageInfo *, ExceptionInfo *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
Image *DestroyImageList(Image *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
int LocaleNCompare(const char *, const char *, size_t);
void ThrowReaderException(int, const char *);
unsigned long ReadBlobLong(Image *);
void CopyMagickString(char *, const char *, size_t);
void SetImageProperty(Image *, const char *, const char *, ExceptionInfo *);
int ReadBlobByte(Image *);
void FormatImageProperty(Image *, const char *, const char *, ...);
float ReadBlobFloat(Image *);
MagickBooleanType IsFloatDefined(float);
ssize_t ReadBlobSignedLong(Image *);
size_t GetBlobSize(Image *);
StringInfo *BlobToStringInfo(const unsigned char *, size_t);
void *GetStringInfoDatum(StringInfo *);
size_t GetStringInfoLength(StringInfo *);
void SetImageProfile(Image *, const char *, StringInfo *, ExceptionInfo *);
StringInfo *DestroyStringInfo(StringInfo *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long, ExceptionInfo *);
void SetImageBackgroundColor(Image *, ExceptionInfo *);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
size_t GetQuantumExtent(Image *, QuantumInfo *, QuantumType);
size_t GetBytesPerRow(unsigned long, int, unsigned long, MagickBooleanType);
Quantum *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
const unsigned char *ReadBlobStream(Image *, size_t, unsigned char *, ssize_t *);
unsigned char *GetQuantumPixels(QuantumInfo *);
void ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, QuantumType, const unsigned char *, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, int, MagickOffsetType, size_t);
void SetQuantumImageType(Image *, QuantumType);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
int EOFBlob(Image *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
void SetImageColorspace(Image *, int, ExceptionInfo *);
Image *GetFirstImageInList(Image *);
void *LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);