#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <wchar.h>
#include <stdbool.h>

#define NUM_FORMATS 12
#define TAG_TABLE_SIZE 100
#define MAX_COMMENT_SIZE 2000
#define MAX_DATE_COPIES 10

#define TAG_MAKER_NOTE 0x927C
#define TAG_MAKE 0x010F
#define TAG_MODEL 0x0110
#define TAG_SUBSEC_TIME 0x9290
#define TAG_SUBSEC_TIME_ORIG 0x9291
#define TAG_SUBSEC_TIME_DIG 0x9292
#define TAG_DATETIME_DIGITIZED 0x9004
#define TAG_DATETIME_ORIGINAL 0x9003
#define TAG_DATETIME 0x0132
#define TAG_WINXP_COMMENT 0x9C9C
#define TAG_USERCOMMENT 0x9286
#define TAG_FNUMBER 0x829D
#define TAG_APERTURE 0x9202
#define TAG_MAXAPERTURE 0x9205
#define TAG_FOCALLENGTH 0x920A
#define TAG_SUBJECT_DISTANCE 0x9206
#define TAG_EXPOSURETIME 0x829A
#define TAG_SHUTTERSPEED 0x9201
#define TAG_FLASH 0x9209
#define TAG_ORIENTATION 0x0112
#define TAG_EXIF_IMAGELENGTH 0xA003
#define TAG_EXIF_IMAGEWIDTH 0xA002
#define TAG_FOCAL_PLANE_XRES 0xA20E
#define TAG_FOCAL_PLANE_UNITS 0xA210
#define TAG_EXPOSURE_BIAS 0x9204
#define TAG_WHITEBALANCE 0xA403
#define TAG_LIGHT_SOURCE 0x9208
#define TAG_METERING_MODE 0x9207
#define TAG_EXPOSURE_PROGRAM 0x8822
#define TAG_EXPOSURE_INDEX 0x8821
#define TAG_EXPOSURE_MODE 0xA402
#define TAG_ISO_EQUIVALENT 0x8827
#define TAG_DIGITALZOOMRATIO 0xA404
#define TAG_THUMBNAIL_OFFSET 0x0201
#define TAG_THUMBNAIL_LENGTH 0x0202
#define TAG_EXIF_OFFSET 0x8769
#define TAG_INTEROP_OFFSET 0xA005
#define TAG_GPSINFO 0x8825
#define TAG_FOCALLENGTH_35MM 0xA405
#define TAG_DISTANCE_RANGE 0xA40C

#define FMT_BYTE 1
#define FMT_STRING 2
#define FMT_UNDEFINED 7

#define FALSE 0
#define TRUE 1

typedef struct {
    unsigned Tag;
    const char *Desc;
} TagTable_t;

typedef struct {
    int num;
    int denom;
} Fraction_t;

typedef struct {
    char CameraMake[32];
    char CameraModel[40];
    char SubSecTime[32];
    char SubSecTimeOrig[32];
    char SubSecTimeDig[32];
    char DigitizedTime[32];
    char DateTime[32];
    char Comments[MAX_COMMENT_SIZE];
    float ApertureFNumber;
    Fraction_t FocalLength;
    float Distance;
    float ExposureTime;
    int FlashUsed;
    int Orientation;
    int ISOequivalent;
    float ExposureBias;
    int Whitebalance;
    int LightSource;
    int MeteringMode;
    int ExposureProgram;
    int ExposureMode;
    float DigitalZoomRatio;
    unsigned LargestExifOffset;
    unsigned ThumbnailOffset;
    unsigned ThumbnailSize;
    unsigned ThumbnailSizeOffset;
    bool ThumbnailAtEnd;
    int FocalLength35mmEquiv;
    int DistanceRange;
    int CommentWidchars;
    int numDateTimeTags;
    int DateTimeOffsets[MAX_DATE_COPIES];
} ImageInfo_t;

extern TagTable_t TagTable[TAG_TABLE_SIZE];
extern ImageInfo_t ImageInfo;
extern int ShowTags;
extern int DumpExifMap;
extern int NumOrientations;
extern unsigned char *OrientationPtr[2];
extern int OrientationNumFormat[2];
extern int ExifImageWidth;
extern double FocalplaneXRes;
extern double FocalplaneUnits;
extern unsigned char *DirWithThumbnailPtrs;
extern int BytesPerFormat[NUM_FORMATS];

int Get16u(unsigned char *Short);
unsigned Get32u(unsigned char *Long);
float ConvertAnyFormat(void *ValuePtr, int Format);
void ErrNonfatal(const char *msg, int a1, int a2);
void PrintFormatNumber(void *ValuePtr, int Format, int ByteCount);
void ProcessMakerNote(unsigned char *ValuePtr, int ByteCount, unsigned char *OffsetBase, unsigned ExifLength);
void ProcessGpsInfo(unsigned char *SubdirStart, int ByteCount, unsigned char *OffsetBase, unsigned ExifLength);

static inline size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t ret = strlen(src);
    if (size) {
        size_t len = (ret >= size) ? size - 1 : ret;
        memcpy(dst, src, len);
        dst[len] = '\0';
    }
    return ret;
}