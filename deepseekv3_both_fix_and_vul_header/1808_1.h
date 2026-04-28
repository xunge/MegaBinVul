#include <stdio.h>

typedef int GF_Err;
#define GF_OK 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 1
#define GF_ISOM_BOX_TYPE_GNRM 2

typedef struct GF_Box {
    unsigned int type;
} GF_Box;

typedef struct GF_GenericSampleEntryBox {
    unsigned int EntryType;
    int dataReferenceIndex;
    unsigned int data_size;
    void *data;
} GF_GenericSampleEntryBox;

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
int gf_fprintf(FILE *stream, const char *format, ...);
void gnr_dump_exts(void *data, unsigned int size, FILE *trace);