#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

#define MaxTextExtent 4096
#define MaxNumberImageElements 8

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef long long MagickOffsetType;
typedef size_t MagickSizeType;

typedef enum
{
  UndefinedQuantum,
  AlphaQuantum,
  BlackQuantum,
  BlueQuantum,
  CMYKQuantum,
  CbYCrQuantum,
  CbYCrYQuantum,
  GrayQuantum,
  GreenQuantum,
  IndexQuantum,
  RGBQuantum,
  RGBAQuantum,
  RedQuantum,
  YellowQuantum
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
  BottomLeftOrientation,
  BottomRightOrientation,
  LeftTopOrientation,
  RightTopOrientation,
  LeftBottomOrientation,
  RightBottomOrientation
} OrientationType;

typedef enum
{
  UndefinedEndian,
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum
{
  UndefinedTransferCharacteristic,
  PrintingDensityColorimetric,
  LogarithmicColorimetric
} DPXTransferCharacteristic;

typedef enum
{
  UndefinedColorimetric,
  UserDefinedColorimetric,
  PrintingDensityColorimetric_Colorimetric,
  LogarithmicColorimetric_Colorimetric
} DPXColorimetric;

typedef enum
{
  UndefinedComponentType,
  UserDefinedComponentType,
  RGBComponentType,
  RGBAComponentType,
  ABGRComponentType,
  LumaComponentType,
  CbYCrY422ComponentType,
  CbYACrYA4224ComponentType,
  CbYCr444ComponentType
} DPXComponentType;

typedef struct _ImageInfo ImageInfo;
typedef struct _Image Image;
typedef struct _ExceptionInfo ExceptionInfo;
typedef struct _QuantumInfo QuantumInfo;
typedef struct _StringInfo StringInfo;
typedef struct _PixelPacket PixelPacket;
typedef struct _CacheView CacheView;

typedef struct
{
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

typedef struct
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

typedef struct
{
  unsigned short orientation;
  unsigned short number_elements;
  unsigned int pixels_per_line;
  unsigned int lines_per_element;
  DPXImageElement image_element[8];
  char reserve[52];
} DPXImageHeader;

typedef struct
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

typedef struct
{
  char id[2];
  char type[2];
  char offset[2];
  char prefix[6];
  char count[4];
  char format[4];
  unsigned int frame_position;
  unsigned int sequence_extent;
  unsigned int held_count;
  float frame_rate;
  float shutter_angle;
  char frame_id[32];
  char slate[100];
  char reserve[56];
} DPXFilmHeader;

typedef struct
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

typedef struct
{
  char id[32];
  char reserve[32];
} DPXUserHeader;

typedef struct
{
  DPXFileHeader file;
  DPXImageHeader image;
  DPXOrientationHeader orientation;
  DPXFilmHeader film;
  DPXTelevisionHeader television;
  DPXUserHeader user;
} DPXInfo;

typedef long ssize_t;

#define MagickSignature 0xabacadabUL
#define TraceEvent 0
#define ReadBinaryBlobMode 0
#define CorruptImageError 0
#define ResourceLimitError 0
#define SEEK_SET 0
#define LoadImageTag 0

typedef void (*MagickProgressMonitor)(const char *,const MagickOffsetType,const MagickSizeType,void *);

struct _Image {
    unsigned long signature;
    unsigned long columns;
    unsigned long rows;
    unsigned long depth;
    MagickBooleanType matte;
    OrientationType orientation;
    EndianType endian;
    ColorspaceType colorspace;
    void *chromaticity;
    void *exception;
    char *filename;
    void *progress_monitor;
    void *previous;
};

struct _ImageInfo {
    unsigned long signature;
    MagickBooleanType debug;
    char *filename;
    MagickBooleanType ping;
};

struct _ExceptionInfo {
    unsigned long signature;
};

struct _QuantumInfo {
    size_t quantum;
    MagickBooleanType pack;
};

struct _StringInfo {
    size_t length;
    unsigned char *datum;
};

struct _PixelPacket {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char opacity;
};

struct _CacheView {
    void *data;
};