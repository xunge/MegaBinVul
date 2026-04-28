#include <stdint.h>
#include <string.h>

#define O_RDONLY 0
#define FIELD_CUSTOM 0

typedef unsigned long toff_t;

typedef struct tiff {
    int tif_mode;
    void (*tif_cleanup)(struct tiff *);
    void *tif_dirlist;
    struct TIFFClientInfoLink *tif_clientinfo;
    unsigned char *tif_rawdata;
    long tif_flags;
    #define TIFF_MYBUFFER 0
    void *tif_base;
    toff_t tif_size;
    struct TIFFField **tif_fields;
    uint32_t tif_nfields;
    struct {
        void *fields;
        uint32_t allocated_size;
    } *tif_fieldscompat;
    uint32_t tif_nfieldscompat;
} TIFF;

typedef struct TIFFClientInfoLink {
    struct TIFFClientInfoLink *next;
    char *name;
} TIFFClientInfoLink;

typedef struct TIFFField {
    char *field_name;
    int field_bit;
} TIFFField;

void TIFFFlush(TIFF *);
void TIFFFreeDirectory(TIFF *);
void _TIFFfree(void *);
int isMapped(TIFF *);
void TIFFUnmapFileContents(TIFF *, void *, toff_t);