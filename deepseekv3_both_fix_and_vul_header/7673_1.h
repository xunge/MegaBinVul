#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char MagickBooleanType;
typedef long long MagickOffsetType;
typedef unsigned long long MagickSizeType;
typedef long ssize_t;
typedef unsigned long size_t;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanEnum;

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
  MSBEndian,
  LSBEndian
} EndianType;

typedef enum {
  TraceEvent
} LogEventType;

typedef enum {
  ReadBinaryBlobMode
} BlobMode;

typedef enum {
  RGBQuantum,
  GrayQuantum
} QuantumType;

typedef enum {
  CorruptImageError,
  ResourceLimitError
} ExceptionType;

typedef enum {
  LogColorspace
} ColorspaceType;

typedef struct _Image {
  unsigned long signature;
  EndianType endian;
  OrientationType orientation;
  unsigned long columns;
  unsigned long rows;
  unsigned short depth;
  struct _Image *previous;
  struct _Image *next;
  struct _ExceptionInfo *exception;
  char *filename;
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
  float gamma;
} Image;

typedef struct _ImageInfo {
  unsigned long signature;
  MagickBooleanType debug;
  MagickBooleanType ping;
  char *filename;
} ImageInfo;

typedef struct _ExceptionInfo {
  unsigned long signature;
} ExceptionInfo;

typedef struct _QuantumInfo {
  unsigned long signature;
} QuantumInfo;

typedef struct _StringInfo {
  unsigned char *datum;
  size_t length;
} StringInfo;

typedef struct _CacheView {
  unsigned long signature;
} CacheView;

typedef struct _PixelPacket {
  unsigned long signature;
} PixelPacket;

typedef struct {
  unsigned char version[8];
  char filename[100];
  char create_date[12];
  char create_time[12];
  char reserve[36];
  unsigned long image_offset;
  unsigned long generic_length;
  unsigned long industry_length;
  unsigned long user_length;
  unsigned long file_size;
} CINFileInfo;

typedef struct {
  unsigned char designator[2];
  unsigned char bits_per_pixel;
  unsigned char reserve;
  unsigned long pixels_per_line;
  unsigned long lines_per_image;
  float min_data;
  float min_quantity;
  float max_data;
  float max_quantity;
} CINChannelInfo;

typedef struct {
  unsigned char orientation;
  unsigned char number_channels;
  unsigned char reserve1[2];
  CINChannelInfo channel[8];
  float white_point[2];
  float red_primary_chromaticity[2];
  float green_primary_chromaticity[2];
  float blue_primary_chromaticity[2];
  char label[100];
  char reserve[24];
} CINImageInfo;

typedef struct {
  unsigned char interleave;
  unsigned char packing;
  unsigned char sign;
  unsigned char sense;
  unsigned long line_pad;
  unsigned long channel_pad;
  char reserve[20];
} CINDataFormatInfo;

typedef struct {
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
} CINOriginationInfo;

typedef struct {
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
} CINFilmInfo;

typedef struct {
  CINFileInfo file;
  CINImageInfo image;
  CINDataFormatInfo data_format;
  CINOriginationInfo origination;
  CINFilmInfo film;
} CINInfo;

#define MaxTextExtent 2048
#define MagickCoreSignature 0xabacadabUL
#define LoadImageTag 0xabcd1234