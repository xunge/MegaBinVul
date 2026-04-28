#include <stdio.h>

typedef unsigned int GF_4CC;
typedef int GF_Err;
#define GF_OK 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 0
#define GF_ISOM_BOX_TYPE_GNRA 0

typedef struct GF_Box {
    GF_4CC type;
} GF_Box;

typedef struct GF_GenericAudioSampleEntryBox {
    GF_4CC EntryType;
    int dataReferenceIndex;
    int version;
    int revision;
    int vendor;
    int channel_count;
    int bitspersample;
    int samplerate_hi;
    void *data;
    unsigned int data_size;
} GF_GenericAudioSampleEntryBox;

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
void gnr_dump_exts(void *data, unsigned int data_size, FILE *trace);
int gf_fprintf(FILE *trace, const char *format, ...);

#define GF_4CC(a,b,c,d) ((a<<24)|(b<<16)|(c<<8)|d)