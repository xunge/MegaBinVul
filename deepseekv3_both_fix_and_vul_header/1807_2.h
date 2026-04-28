#include <stdio.h>
#include <ctype.h>

typedef unsigned int GF_4CC;
typedef int GF_Err;
#define GF_OK 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 1
#define GF_ISOM_BOX_TYPE_GNRV 2

#define GF_4CC(a,b,c,d) (((GF_4CC)(a)<<24)|((GF_4CC)(b)<<16)|((GF_4CC)(c)<<8)|((GF_4CC)(d)))

typedef struct {
    GF_4CC type;
} GF_Box;

typedef struct {
    GF_Box box;
    GF_4CC EntryType;
    unsigned int dataReferenceIndex;
    unsigned int version;
    unsigned int revision;
    unsigned int vendor;
    unsigned int temporal_quality;
    unsigned int spatial_quality;
    unsigned int Width;
    unsigned int Height;
    unsigned int horiz_res;
    unsigned int vert_res;
    char compressor_name[32];
    unsigned int bit_depth;
    void *data;
    unsigned int data_size;
} GF_GenericVisualSampleEntryBox;

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
int gf_fprintf(FILE *trace, const char *format, ...);
void gnr_dump_exts(void *data, unsigned int data_size, FILE *trace);