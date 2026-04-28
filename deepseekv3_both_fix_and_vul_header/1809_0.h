#include <stdio.h>

typedef unsigned int u32;
typedef int GF_Err;
typedef struct GF_Box GF_Box;
typedef struct GF_ItemReferenceTypeBox GF_ItemReferenceTypeBox;

#define GF_OK 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 1
#define GF_ISOM_BOX_TYPE_REFI 2

#define GF_4CC(a,b,c,d) ((a << 24) | (b << 16) | (c << 8) | d)

struct GF_ItemReferenceTypeBox {
    u32 type;
    u32 reference_type;
    u32 from_item_id;
    u32 reference_count;
    u32 *to_item_IDs;
    u32 size;
};

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
int gf_fprintf(FILE *trace, const char *format, ...);