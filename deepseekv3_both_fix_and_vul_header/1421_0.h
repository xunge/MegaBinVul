#include <stdint.h>
#include <stdlib.h>

typedef struct TIFF TIFF;
typedef struct TIFFField TIFFField;
typedef struct TIFFFieldArray TIFFFieldArray;
typedef struct TIFFFieldInfo TIFFFieldInfo;

enum {
    tfiatOther
};

struct TIFFFieldInfo {
    uint32_t field_tag;
    int field_readcount;
    int field_writecount;
    int field_type;
    int field_bit;
    int field_oktochange;
    int field_passcount;
    char* field_name;
};

struct TIFFField {
    uint32_t field_tag;
    int field_readcount;
    int field_writecount;
    int field_type;
    int field_anonymous;
    int (*set_field_type)(void);
    int (*get_field_type)(void);
    int field_bit;
    int field_oktochange;
    int field_passcount;
    char* field_name;
    void* field_subfields;
    int reserved;
};

struct TIFFFieldArray {
    int type;
    size_t allocated_size;
    size_t count;
    TIFFField* fields;
};

struct TIFF {
    TIFFFieldArray* tif_fieldscompat;
    size_t tif_nfieldscompat;
    void* tif_clientdata;
};

void* _TIFFCheckMalloc(TIFF* tif, size_t nmemb, size_t size, const char* what);
void* _TIFFCheckRealloc(TIFF* tif, void* ptr, size_t nmemb, size_t size, const char* what);
int _TIFFSetGetType(int type, int readcount, int passcount);
int _TIFFMergeFields(TIFF* tif, TIFFField* fields, uint32_t n);
void TIFFErrorExt(void* clientdata, const char* module, const char* fmt, ...);