#include <stddef.h>
#include <stdio.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct {
  unsigned long flags;
  unsigned long fourcc;
  unsigned long rgb_bitcount;
  unsigned long r_bitmask;
  unsigned long g_bitmask;
  unsigned long b_bitmask;
  unsigned long alpha_bitmask;
} DDSPixelFormat;

typedef struct {
  unsigned long flags;
  unsigned long height;
  unsigned long width;
  unsigned long pitchOrLinearSize;
  unsigned long depth;
  unsigned long mipmapcount;
  DDSPixelFormat pixelformat;
  unsigned long ddscaps1;
  unsigned long ddscaps2;
} DDSInfo;

typedef struct Image Image;

#define DDSD_WIDTH 0x00000004
#define DDSD_HEIGHT 0x00000002
#define DDSD_PIXELFORMAT 0x00001000

extern void SeekBlob(Image *, long, int);
extern unsigned long ReadBlobLSBLong(Image *);