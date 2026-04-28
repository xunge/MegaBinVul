#include <stdio.h>
#include <stdlib.h>

typedef int GF_Err;
#define GF_OK 0
#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 2
#define GF_ISOM_BOX_TYPE_DREF 3

typedef struct GF_BitStream GF_BitStream;

typedef struct GF_Box {
    // base box fields
} GF_Box;

typedef struct GF_DataReferenceBox {
    GF_Box box;
    // other fields
} GF_DataReferenceBox;

typedef struct GF_DataInformationBox {
    GF_Box box;
    GF_DataReferenceBox *dref;
    // other fields
} GF_DataInformationBox;

GF_Err gf_isom_box_array_read(GF_Box *s, GF_BitStream *bs, void (*dinf_AddBox)(GF_Box*, GF_Box*));
void GF_LOG(int level, int category, const char *format, ...);
GF_Box *gf_isom_box_new(int box_type);
void dinf_AddBox(GF_Box *parent, GF_Box *child);