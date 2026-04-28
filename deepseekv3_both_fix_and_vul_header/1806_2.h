#include <stdio.h>
#include <stdint.h>

typedef int GF_Err;
typedef uint32_t u32;
typedef uint32_t GF_4CC;

#define GF_OK 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 0
#define GF_ISOM_BOX_TYPE_REFT 0

#define GF_4CC(a,b,c,d) ((a<<24)|(b<<16)|(c<<8)|d)

typedef struct GF_Box GF_Box;
typedef struct GF_TrackReferenceTypeBox {
    GF_4CC type;
    GF_4CC reference_type;
    u32 trackIDCount;
    u32 *trackIDs;
    u32 size;
} GF_TrackReferenceTypeBox;

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
int gf_fprintf(FILE *trace, const char *format, ...);