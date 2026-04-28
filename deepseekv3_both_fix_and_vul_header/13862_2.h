#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef long ssize_t;
typedef long long MagickOffsetType;
typedef unsigned char Quantum;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    MSBEndian,
    LSBEndian
} EndianType;

typedef enum {
    TopLeftOrientation,
    TopRightOrientation,
    BottomLeftOrientation,
    BottomRightOrientation,
    LeftTopOrientation,
    RightTopOrientation,
    LeftBottomOrientation,
    RightBottomOrientation
} OrientationType;

typedef enum {
    RGBQuantum,
    GrayQuantum
} QuantumType;

typedef enum {
    ReadBinaryBlobMode
} BlobMode;

typedef enum {
    TraceEvent
} LogEventType;

typedef enum {
    CorruptImageError,
    ResourceLimitError
} ExceptionType;

typedef enum {
    LogColorspace
} ColorspaceType;

typedef struct _CacheView CacheView;

typedef struct _Image {
    unsigned long signature;
    EndianType endian;
    OrientationType orientation;
    struct {
        struct {
            float x;
            float y;
        } white_point;
        struct {
            float x;
            float y;
        } red_primary;
        struct {
            float x;
            float y;
        } green_primary;
        struct {
            float x;
            float y;
        } blue_primary;
    } chromaticity;
    size_t depth;
    size_t columns;
    size_t rows;
    float gamma;
    char *filename;
    struct _Image *previous;
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    const char *filename;
    MagickBooleanType ping;
} ImageInfo;

typedef struct _ExceptionInfo {
    unsigned long signature;
} ExceptionInfo;

typedef struct _QuantumInfo {
    size_t quantum;
    MagickBooleanType pack;
} QuantumInfo;

typedef struct _StringInfo {
    unsigned char *datum;
    size_t length;
} StringInfo;

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
        char label[100];
        char reserve[24];
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
        long x_offset;
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

#define MagickPathExtent 4096
#define MagickCoreSignature 0xabacadabUL
#define LoadImageTag "LoadImage"