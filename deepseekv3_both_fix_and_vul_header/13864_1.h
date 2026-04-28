#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MaxTextExtent 4096
#define MagickSignature 0xabacadabUL
#define MagickFalse 0
#define MagickTrue 1
#define MaxNumberImageElements 8
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define LoadImageTag 0
#define SEEK_SET 0

typedef long ssize_t;
typedef long MagickOffsetType;
typedef int MagickBooleanType;

typedef enum
{
  UndefinedQuantum,
  IndexQuantum,
  GrayQuantum,
  CbYCrQuantum,
  CbYCrYQuantum,
  RGBQuantum,
  RGBAQuantum,
  CMYKQuantum
} QuantumType;

typedef enum
{
  UndefinedColorspace,
  RGBColorspace,
  GRAYColorspace,
  Rec709YCbCrColorspace,
  LogColorspace
} ColorspaceType;

typedef enum
{
  UndefinedOrientation,
  TopLeftOrientation,
  TopRightOrientation,
  BottomRightOrientation,
  BottomLeftOrientation,
  LeftTopOrientation,
  RightTopOrientation,
  RightBottomOrientation,
  LeftBottomOrientation
} OrientationType;

typedef enum
{
  UndefinedEndian,
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum
{
  CbYCrY422ComponentType,
  CbYACrYA4224ComponentType,
  CbYCr444ComponentType,
  RGBComponentType,
  ABGRComponentType,
  RGBAComponentType,
  LumaComponentType
} ComponentType;

typedef enum
{
  UndefinedTransferCharacteristic,
  PrintingDensityColorimetric,
  LogarithmicColorimetric
} DPXTransferCharacteristic;

typedef enum
{
  UndefinedColorimetric,
  PrintingDensity,
  Logarithmic
} DPXColorimetric;

typedef struct _ImageInfo
{
  unsigned long signature;
  int debug;
  const char *filename;
  int ping;
} ImageInfo;

typedef struct _ExceptionInfo
{
  unsigned long signature;
} ExceptionInfo;

typedef struct _Image
{
  unsigned long columns;
  unsigned long rows;
  unsigned long depth;
  ColorspaceType colorspace;
  OrientationType orientation;
  EndianType endian;
  int matte;
  const char *filename;
  struct _Image *previous;
  void *exception;
  void *progress_monitor;
  void *chromaticity;
} Image;

typedef struct _QuantumInfo
{
  size_t depth;
  int pack;
} QuantumInfo;

typedef struct _StringInfo
{
  unsigned char *datum;
  size_t length;
} StringInfo;

typedef struct _PixelPacket
{
} PixelPacket;

typedef struct _CacheView
{
} CacheView;

typedef void (*MagickProgressMonitor)(const char *,const MagickOffsetType,const MagickSizeType,void *);

typedef struct
{
  struct
  {
    unsigned long image_offset;
    char version[8];
    unsigned long file_size;
    unsigned long ditto_key;
    unsigned long generic_size;
    unsigned long industry_size;
    unsigned long user_size;
    char filename[100];
    char timestamp[24];
    char creator[100];
    char project[200];
    char copyright[200];
    unsigned long encrypt_key;
    char reserve[104];
  } file;
  struct
  {
    unsigned short orientation;
    unsigned short number_elements;
    unsigned long pixels_per_line;
    unsigned long lines_per_element;
    struct
    {
      unsigned long data_sign;
      unsigned long low_data;
      float low_quantity;
      unsigned long high_data;
      float high_quantity;
      unsigned char descriptor;
      unsigned char transfer_characteristic;
      unsigned char colorimetric;
      unsigned char bit_size;
      unsigned short packing;
      unsigned short encoding;
      unsigned long data_offset;
      unsigned long end_of_line_padding;
      unsigned long end_of_image_padding;
      char description[32];
    } image_element[8];
    char reserve[52];
  } image;
  struct
  {
    unsigned long x_offset;
    unsigned long y_offset;
    float x_center;
    float y_center;
    unsigned long x_size;
    unsigned long y_size;
    char filename[100];
    char timestamp[24];
    char device[32];
    char serial[32];
    unsigned short border[4];
    unsigned long aspect_ratio[2];
    char reserve[28];
  } orientation;
  struct
  {
    char id[2];
    char type[2];
    char offset[2];
    char prefix[6];
    char count[4];
    char format[4];
    unsigned long frame_position;
    unsigned long sequence_extent;
    unsigned long held_count;
    float frame_rate;
    float shutter_angle;
    char frame_id[32];
    char slate[100];
    char reserve[56];
  } film;
  struct
  {
    unsigned int time_code;
    unsigned int user_bits;
    unsigned char interlace;
    unsigned char field_number;
    unsigned char video_signal;
    unsigned char padding;
    float horizontal_sample_rate;
    float vertical_sample_rate;
    float frame_rate;
    float time_offset;
    float gamma;
    float black_level;
    float black_gain;
    float break_point;
    float white_level;
    float integration_times;
    char reserve[76];
  } television;
  struct
  {
    char id[32];
  } user;
} DPXInfo;

Image *AcquireImage(const ImageInfo *);
Image *DestroyImageList(Image *);
Image *GetFirstImageInList(Image *);
MagickBooleanType OpenBlob(const ImageInfo *, Image *, int, ExceptionInfo *);
ssize_t ReadBlob(Image *, size_t, unsigned char *);
unsigned long ReadBlobLong(Image *);
unsigned short ReadBlobShort(Image *);
unsigned char ReadBlobByte(Image *);
float ReadBlobFloat(Image *);
MagickBooleanType CloseBlob(Image *);
MagickBooleanType EOFBlob(Image *);
MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
void *ResetMagickMemory(void *, int, size_t);
int LocaleNCompare(const char *, const char *, size_t);
void FormatImageProperty(Image *, const char *, const char *, ...);
void SetImageProperty(Image *, const char *, const char *);
void SetImageColorspace(Image *, ColorspaceType);
MagickBooleanType SetImageExtent(Image *, unsigned long, unsigned long);
void InheritException(ExceptionInfo *, ExceptionInfo *);
void ThrowReaderException(int, const char *);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
char *GetMagickHomeURL(void);
char *DestroyString(char *);
StringInfo *BlobToStringInfo(const void *, size_t);
StringInfo *DestroyStringInfo(StringInfo *);
void SetImageProfile(Image *, const char *, StringInfo *);
void SetPrimaryChromaticity(DPXColorimetric, void *);
size_t GetBytesPerRow(unsigned long, size_t, unsigned long, MagickBooleanType);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *, Image *);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
void SetQuantumQuantum(QuantumInfo *, size_t);
void SetQuantumPack(QuantumInfo *, MagickBooleanType);
const unsigned char *ReadBlobStream(Image *, size_t, unsigned char *, ssize_t *);
size_t GetQuantumPixels(QuantumInfo *);
PixelPacket *QueueAuthenticPixels(Image *, ssize_t, ssize_t, size_t, size_t, ExceptionInfo *);
size_t ImportQuantumPixels(Image *, CacheView *, QuantumInfo *, QuantumType, const unsigned char *, ExceptionInfo *);
MagickBooleanType SyncAuthenticPixels(Image *, ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *, const char *, MagickOffsetType, unsigned long);
void SetQuantumImageType(Image *, QuantumType);
const char *GetImageTransferCharacteristic(DPXTransferCharacteristic);
void TimeCodeToString(unsigned int, char *);
MagickBooleanType IsFloatDefined(float);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
int FormatLocaleString(char *, size_t, const char *, ...);