#include <stddef.h>
#include <stdint.h>

typedef int64_t ssize_t;
typedef int64_t MagickOffsetType;
typedef unsigned char Quantum;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    ZipCompression,
    RLECompression
} CompressionType;

typedef enum {
    UndefinedQuantum,
    AlphaQuantum,
    BlackQuantum,
    BlueQuantum,
    CyanQuantum,
    GrayQuantum,
    GreenQuantum,
    IndexQuantum,
    MagentaQuantum,
    OpacityQuantum,
    RedQuantum,
    YellowQuantum,
    RGBQuantum,
    RGBAQuantum,
    CMYKQuantum,
    CMYKAQuantum,
    LabQuantum,
    XYZQuantum,
    HSLQuantum,
    HWBQuantum,
    YUVQuantum,
    YIQQuantum,
    YPbPrQuantum,
    YCbCrQuantum,
    LuvQuantum,
    sRGBQuantum,
    HSBQuantum,
    HCLQuantum,
    LCHQuantum,
    LMSQuantum,
    LCHabQuantum,
    LCHuvQuantum,
    scRGBQuantum,
    HSIQuantum,
    HCLpQuantum,
    YDbDrQuantum,
    Rec601YCbCrQuantum,
    Rec709YCbCrQuantum,
    LogQuantum,
    CMYQuantum,
    LabAQuantum,
    XYZAQuantum,
    LinearGRAYQuantum,
    OHTAQuantum,
    Rec601LumaQuantum,
    Rec709LumaQuantum,
    Rec601YQuantum,
    Rec709YQuantum,
    TransparentQuantum,
    SyncQuantum,
    DefaultQuantum,
    AllQuantum
} QuantumType;

typedef struct _PSDInfo PSDInfo;
typedef struct _ImageInfo ImageInfo;
typedef struct _Image {
    int depth;
    int rows;
    int columns;
    CompressionType compression;
} Image;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _CacheView CacheView;

#ifdef MAGICKCORE_ZLIB_DELEGATE
typedef struct {
    void *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    void *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char *msg;
    void *state;
    void *(*zalloc)(void *, unsigned int, unsigned int);
    void (*zfree)(void *, void *);
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

#define Z_NO_FLUSH 0
#define Z_FINISH 4
#define Z_STREAM_ERROR (-2)
#define Z_OK 0
#define Z_BINARY 0
#define Z_DEFAULT_COMPRESSION (-1)
#endif