#include <stdlib.h>

typedef struct ut8_t {
    unsigned char value;
} ut8;

typedef unsigned int ut32;

typedef struct RASN1Object_t {
    ut8 *sector;
    ut32 length;
    struct {
        struct RASN1Object_t **objects;
        ut32 length;
    } list;
} RASN1Object;

typedef struct RCMS_t {
    char *contentType;
    void *signedData;
} RCMS;

RASN1Object *r_asn1_create_object(const ut8 *buffer, ut32 length);
void r_asn1_free_object(RASN1Object *object);
char *r_asn1_stringify_oid(const ut8 *sector, ut32 length);
void r_pkcs7_parse_signeddata(void **signedData, RASN1Object *object);
#define R_NEW0(type) ((type *)calloc(1, sizeof(type)))