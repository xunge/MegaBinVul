#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

typedef struct TIFF TIFF;
typedef struct TIFFField {
    const char* field_name;
    int field_type;
} TIFFField;

#define TIFFTAG_INKSET 332
#define TIFFTAG_DOTRANGE 336
#define TIFFTAG_WHITEPOINT 318
#define TIFFTAG_XMLPACKET 700
#define TIFFTAG_RICHTIFFIPTC 33723
#define TIFFTAG_PHOTOSHOP 34377
#define TIFFTAG_ICCPROFILE 34675
#define TIFFTAG_STONITS 37439

#define TIFF_SHORT 3
#define TIFF_RATIONAL 5
#define TIFF_DOUBLE 12

#define INKSET_CMYK 1