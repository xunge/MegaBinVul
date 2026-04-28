#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct GF_Box GF_Box;
typedef struct GF_SampleEntryBox GF_SampleEntryBox;
typedef struct GF_MPEGSampleEntryBox GF_MPEGSampleEntryBox;

struct GF_Box {
    uint32_t type;
};

struct GF_SampleEntryBox {
    GF_Box box;
};

struct GF_MPEGSampleEntryBox {
    GF_SampleEntryBox sample_entry;
    uint32_t internal_type;
};

#define GF_ISOM_BOX_TYPE_ENCS 0x656E6373
#define GF_ISOM_SAMPLE_ENTRY_MP4S 0x6D703473

#define ISOM_DECL_BOX_ALLOC(STRUCT_TYPE, BOX_TYPE) \
    STRUCT_TYPE *tmp = (STRUCT_TYPE*)malloc(sizeof(STRUCT_TYPE)); \
    if(tmp) { memset(tmp, 0, sizeof(STRUCT_TYPE)); tmp->sample_entry.box.type = BOX_TYPE; }

void gf_isom_sample_entry_init(GF_SampleEntryBox*);