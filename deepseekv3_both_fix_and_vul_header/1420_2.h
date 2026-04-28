#include <stdint.h>
#include <string.h>

typedef struct tiff_field {
    char* field_name;
    uint32_t field_bit;
} TIFFField;

typedef struct tiff {
    TIFFField** tif_fields;
    uint32_t tif_nfields;
    void* tif_clientdata;
} TIFF;

typedef struct tiff_field_array {
    TIFFField* fields;
    uint32_t count;
} TIFFFieldArray;

#define FIELD_CUSTOM 0

extern void _TIFFfree(void *ptr);
extern int _TIFFMergeFields(TIFF *tif, const TIFFField *fields, uint32_t count);
extern void TIFFErrorExt(void *clientdata, const char *module, const char *fmt, ...);