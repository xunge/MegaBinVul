#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

typedef struct GF_Box {
    u32 type;
    void *cfg;
} GF_Box;

typedef struct GF_List GF_List;
typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_MediaInformationBox {
    struct GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_MediaBox {
    GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_SampleTableBox {
    struct GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;

typedef struct GF_SampleDescriptionBox {
    GF_List *child_boxes;
} GF_SampleDescriptionBox;

typedef struct {
    GF_Box *cfg_ac3;
    u32 internal_type;
} GF_MPEGAudioSampleEntryBox;

typedef struct {
    u32 type;
    struct {
        char cfg[64];
    } cfg;
} GF_AC3Config;

typedef struct {
    GF_MediaBox *Media;
} GF_TrackBox;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_DAC3 0
#define GF_ISOM_BOX_TYPE_DEC3 0
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 0

void *gf_malloc(size_t size);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
void *gf_list_get(GF_List *list, u32 position);