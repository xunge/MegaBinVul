#include <assert.h>
#include <string.h>
#include <time.h>
#include <stddef.h>

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef long MagickOffsetType;
typedef unsigned long MagickStatusType;
typedef unsigned long MagickSizeType;

typedef struct _ImageInfo
{
  unsigned long signature;
  char *sampling_factor;
  int type;
  int debug;
} ImageInfo;

typedef struct _Image
{
  unsigned long signature;
  unsigned long columns;
  unsigned long rows;
  unsigned long magick_columns;
  unsigned long magick_rows;
  int depth;
  int alpha_trait;
  int colorspace;
  int orientation;
  char *filename;
  int debug;
} Image;

typedef struct _ExceptionInfo
{
  unsigned long signature;
} ExceptionInfo;

typedef struct _StringInfo
{
  size_t length;
  unsigned char *datum;
} StringInfo;

typedef struct _GeometryInfo
{
  double rho;
  double sigma;
  double xi;
  double psi;
} GeometryInfo;

typedef struct _QuantumInfo
{
  int quantum;
  int pack;
} QuantumInfo;

typedef enum
{
  UndefinedPixelTrait,
  BlendPixelTrait
} PixelTrait;

typedef enum
{
  UndefinedColorspace,
  RGBColorspace,
  GRAYColorspace,
  YCbCrColorspace,
  LogColorspace,
  Rec601YCbCrColorspace,
  Rec709YCbCrColorspace
} ColorspaceType;

typedef enum
{
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
  RGBComponentType,
  RGBAComponentType,
  LumaComponentType,
  CbYCr444ComponentType,
  CbYCrA4444ComponentType
} ComponentType;

typedef enum
{
  PrintingDensityColorimetric
} TransferCharacteristic;

typedef enum
{
  RGBQuantum,
  RGBAQuantum,
  GrayQuantum,
  CbYCrQuantum,
  CbYCrAQuantum,
  CbYCrYQuantum
} QuantumType;

typedef struct _DPXFileHeader
{
  unsigned int magic;
  unsigned int image_offset;
  char version[8];
  unsigned int file_size;
  unsigned int ditto_key;
  unsigned int generic_size;
  unsigned int industry_size;
  unsigned int user_size;
  char filename[100];
  char timestamp[24];
  char creator[100];
  char project[200];
  char copyright[200];
  unsigned int encrypt_key;
  char reserve[104];
} DPXFileHeader;

typedef struct _DPXImageElement
{
  unsigned int data_sign;
  unsigned int low_data;
  float low_quantity;
  unsigned int high_data;
  float high_quantity;
  unsigned char descriptor;
  unsigned char transfer_characteristic;
  unsigned char colorimetric;
  unsigned char bit_size;
  unsigned short packing;
  unsigned short encoding;
  unsigned int data_offset;
  unsigned int end_of_line_padding;
  unsigned int end_of_image_padding;
  char description[32];
} DPXImageElement;

typedef struct _DPXImageHeader
{
  unsigned short orientation;
  unsigned short number_elements;
  DPXImageElement image_element[8];
  char reserve[52];
} DPXImageHeader;

typedef struct _DPXOrientationHeader
{
  unsigned int x_offset;
  unsigned int y_offset;
  float x_center;
  float y_center;
  unsigned int x_size;
  unsigned int y_size;
  char filename[100];
  char timestamp[24];
  char device[32];
  char serial[32];
  unsigned short border[4];
  unsigned int aspect_ratio[2];
  char reserve[28];
} DPXOrientationHeader;

typedef struct _DPXFilmHeader
{
  char id[2];
  char type[2];
  char offset[2];
  char prefix[6];
  char count[4];
  char format[32];
  unsigned int frame_position;
  unsigned int sequence_extent;
  unsigned int held_count;
  float frame_rate;
  float shutter_angle;
  char frame_id[32];
  char slate[100];
  char reserve[56];
} DPXFilmHeader;

typedef struct _DPXTelevisionHeader
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
} DPXTelevisionHeader;

typedef struct _DPXUserHeader
{
  char id[32];
} DPXUserHeader;

typedef struct _DPXInfo
{
  DPXFileHeader file;
  DPXImageHeader image;
  DPXOrientationHeader orientation;
  DPXFilmHeader film;
  DPXTelevisionHeader television;
  DPXUserHeader user;
} DPXInfo;

#define MagickCoreSignature 0xabacadabUL
#define MagickAuthoritativeURL "http://www.imagemagick.org"
#define TrueColorType 1
#define SigmaValue 0x02
#define SaveImageTag 1
#define TraceEvent 1
#define CorruptImageError 1
#define ImageError 2
#define ResourceLimitError 3
#define FileOpenError 4
#define WriteBinaryBlobMode 1

typedef ptrdiff_t ssize_t;
typedef unsigned char Quantum;

typedef struct _CacheView CacheView;

/* Function prototypes */
MagickBooleanType LogMagickEvent(int,const char *,const char *,...);
const char *GetMagickModule(void);
MagickStatusType ParseGeometry(const char *,GeometryInfo *);
void ThrowWriterException(int,const char *);
MagickBooleanType OpenBlob(const ImageInfo *,Image *,int,ExceptionInfo *);
ssize_t WriteBlobLong(Image *,unsigned int);
const StringInfo *GetImageProfile(const Image *,const char *);
size_t GetStringInfoLength(const StringInfo *);
ssize_t WriteBlob(Image *,size_t,const unsigned char *);
MagickBooleanType IsImageGray(const Image *);
const char *GetDPXProperty(const Image *,const char *,ExceptionInfo *);
void FormatMagickTime(time_t,size_t,char *);
ssize_t WriteBlobShort(Image *,unsigned short);
ssize_t WriteBlobFloat(Image *,float);
ssize_t WriteBlobByte(Image *,unsigned char);
MagickBooleanType SetImageGray(Image *,ExceptionInfo *);
void DeleteImageProperty(Image *,const char *);
unsigned long StringToUnsignedLong(const char *);
double StringToDouble(const char *,char **);
unsigned int StringToTimeCode(const char *);
long StringToLong(const char *);
void ThrowFileException(ExceptionInfo *,int,const char *,const char *);
QuantumInfo *AcquireQuantumInfo(const ImageInfo *,Image *);
void SetQuantumQuantum(QuantumInfo *,int);
void SetQuantumPack(QuantumInfo *,MagickBooleanType);
size_t GetBytesPerRow(size_t,size_t,int,MagickBooleanType);
unsigned char *GetQuantumPixels(QuantumInfo *);
const Quantum *GetVirtualPixels(Image *,ssize_t,ssize_t,size_t,size_t,ExceptionInfo *);
size_t ExportQuantumPixels(Image *,CacheView *,QuantumInfo *,QuantumType,unsigned char *,ExceptionInfo *);
MagickBooleanType SetImageProgress(Image *,int,MagickOffsetType,size_t);
QuantumInfo *DestroyQuantumInfo(QuantumInfo *);
MagickBooleanType CloseBlob(Image *);