#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiff TIFF;

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

typedef enum {
    TIFF_SETGET_UNDEFINED = 0,
    TIFF_SETGET_C32_UINT8,
    TIFF_SETGET_C32_ASCII,
    TIFF_SETGET_C32_UINT16,
    TIFF_SETGET_C32_UINT32,
    TIFF_SETGET_C32_FLOAT,
    TIFF_SETGET_C32_SINT8,
    TIFF_SETGET_C32_SINT16,
    TIFF_SETGET_C32_SINT32,
    TIFF_SETGET_C32_DOUBLE,
    TIFF_SETGET_C32_IFD8,
    TIFF_SETGET_C32_UINT64,
    TIFF_SETGET_C32_SINT64
} TIFFSetGetFieldType;

typedef struct {
    uint32_t field_tag;
    short field_readcount;
    short field_writecount;
    TIFFDataType field_type;
    TIFFSetGetFieldType set_field_type;
    TIFFSetGetFieldType get_field_type;
    unsigned short field_bit;
    unsigned char field_oktochange;
    unsigned char field_passcount;
    unsigned char field_anonymous;
    unsigned char reserved;
    char *field_name;
    void *field_subfields;
} TIFFField;

#define TIFF_VARIABLE2 (-2)
#define FIELD_CUSTOM 65
#define TRUE 1

extern void *_TIFFmalloc(size_t size);
extern void _TIFFfree(void *ptr);
extern void _TIFFmemset(void *ptr, int val, size_t size);