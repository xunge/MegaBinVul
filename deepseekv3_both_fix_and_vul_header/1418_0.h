#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

typedef enum {
    TIFF_BYTE,
    TIFF_ASCII,
    TIFF_SHORT,
    TIFF_LONG,
    TIFF_RATIONAL,
    TIFF_SBYTE,
    TIFF_UNDEFINED,
    TIFF_SSHORT,
    TIFF_SLONG,
    TIFF_SRATIONAL,
    TIFF_FLOAT,
    TIFF_DOUBLE,
    TIFF_IFD,
    TIFF_LONG8,
    TIFF_SLONG8,
    TIFF_IFD8
} TIFFDataType;

typedef struct {
    uint32_t tag;
    const char* name;
} TIFFTagName;

typedef struct {
    const char* field_name;
    uint32_t field_tag;
    TIFFDataType field_type;
    TIFFDataType set_field_type;
} TIFFField;

#define NTAGS 0
static TIFFTagName tagnames[NTAGS];

static int _TIFFSetGetFieldSize(TIFFDataType type);