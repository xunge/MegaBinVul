#include <assert.h>
#include <string.h>
#include <math.h>

typedef unsigned char Quantum;
typedef unsigned int MagickBooleanType;
typedef long long MagickOffsetType;
typedef size_t ssize_t;

#define MagickFalse 0
#define MagickTrue 1

typedef enum {
    UndefinedPixelTrait,
    OpaqueAlpha
} PixelTrait;

typedef enum {
    UndefinedColorspace,
    RGBColorspace,
    GRAYColorspace,
    CMYKColorspace,
    LabColorspace
} ColorspaceType;

typedef enum {
    NoCompliance,
    SVGCompliance
} ComplianceType;

typedef enum {
    GrayPixelChannel,
    RedPixelChannel,
    GreenPixelChannel,
    BluePixelChannel,
    BlackPixelChannel,
    AlphaPixelChannel
} PixelChannel;

typedef struct {
    ColorspaceType colorspace;
    PixelTrait alpha_trait;
    Quantum red;
    Quantum green;
    Quantum blue;
    Quantum black;
    Quantum alpha;
} PixelInfo;

typedef struct {
    unsigned long signature;
    char *filename;
    MagickBooleanType debug;
    size_t columns;
    size_t rows;
    size_t depth;
    ColorspaceType colorspace;
    PixelTrait alpha_trait;
    char *magick;
    MagickBooleanType adjoin;
} Image;

typedef struct {
    unsigned long signature;
    char *magick;
    MagickBooleanType adjoin;
} ImageInfo;

typedef struct {
} ExceptionInfo;

#define MagickCoreSignature 0x12345678
#define MagickPathExtent 4096
#define MAGICKCORE_QUANTUM_DEPTH 16
#define QuantumRange ((1UL << MAGICKCORE_QUANTUM_DEPTH) - 1)
#define WriteBlobMode 1

extern const void *MagickColorspaceOptions;
extern const void *MagickComplianceOptions;

MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
void CloseBlob(Image *);
MagickBooleanType WriteBlobString(Image *, const char *);
const Quantum *GetVirtualPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, size_t);
Image *GetNextImageInList(Image *);
Image *SyncNextImageInList(Image *);
size_t GetImageListLength(Image *);
size_t GetPixelChannels(Image *);
Quantum GetPixelAlpha(Image *, const Quantum *);
void GetPixelInfoPixel(Image *, const Quantum *, PixelInfo *);
void GetPixelInfo(Image *, PixelInfo *);
size_t GetImageQuantumDepth(Image *, MagickBooleanType);
void *GetImageOption(const ImageInfo *, const char *);
int ParseCommandOption(const void *, MagickBooleanType, const char *);
int LocaleCompare(const char *, const char *);
void LocaleLower(char *);
char *CommandOptionToMnemonic(const void *, ssize_t);
char *CopyMagickString(char *, const char *, size_t);
char *ConcatenateMagickString(char *, const char *, size_t);
void ConcatenateColorComponent(PixelInfo *, PixelChannel, ComplianceType, char *);
void GetColorTuple(PixelInfo *, MagickBooleanType, char *);
char *QueryColorname(Image *, PixelInfo *, ComplianceType, char *, ExceptionInfo *);
char *FormatLocaleString(char *, size_t, const char *, ...);
size_t GetQuantumRange(size_t);
void *LogMagickEvent(int, const char *, const char *, const char *);
const char *GetMagickModule(void);

#define TraceEvent 0
#define SaveImageTag "SaveImage"
#define SaveImagesTag "SaveImages"