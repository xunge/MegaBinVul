#include <stddef.h>
#include <sys/types.h>

typedef enum
{
  LSBEndian,
  MSBEndian
} EndianType;

typedef unsigned char MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

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

#define GetStringInfoLength(profile) ((profile)->length)
#define GetStringInfoDatum(profile) ((profile)->datum)

unsigned char ReadProfileByte(unsigned char **data, size_t *length);
unsigned short ReadProfileShort(EndianType endian, unsigned char *data);
unsigned int ReadProfileLong(EndianType endian, unsigned char *data);
void WriteProfileShort(EndianType endian, unsigned short value, unsigned char *data);
void WriteProfileLong(EndianType endian, size_t value, unsigned char *data);