#include <stddef.h>
#include <sys/types.h>

typedef enum
{
  LSBEndian,
  MSBEndian
} EndianType;

typedef struct _ResolutionInfo
{
  double x;
  double y;
} ResolutionInfo;

typedef struct _Image
{
  ResolutionInfo resolution;
  unsigned int orientation;
  unsigned int units;
} Image;

typedef struct _StringInfo
{
  unsigned char *datum;
  size_t length;
} StringInfo;

typedef enum
{
  MagickFalse,
  MagickTrue
} MagickBooleanType;

unsigned char ReadProfileByte(unsigned char **, size_t *);
unsigned short ReadProfileShort(EndianType, const unsigned char *);
unsigned int ReadProfileLong(EndianType, const unsigned char *);
void WriteProfileShort(EndianType, unsigned short, unsigned char *);
void WriteProfileLong(EndianType, size_t, unsigned char *);
size_t GetStringInfoLength(const StringInfo *);
unsigned char *GetStringInfoDatum(const StringInfo *);