#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

typedef struct GF_3GPConfig {
    char data[1];
} GF_3GPConfig;

typedef struct GF_Box {
    u32 type;
} GF_Box;

typedef struct GF_SampleEntryBox {
    GF_Box box;
    u32 type;
    u32 internal_type;
} GF_SampleEntryBox;

typedef struct GF_3GPPConfigBox {
    GF_3GPConfig cfg;
} GF_3GPPConfigBox;

typedef struct GF_MPEGAudioSampleEntryBox {
    GF_SampleEntryBox entry;
    GF_3GPPConfigBox *cfg_3gpp;
} GF_MPEGAudioSampleEntryBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    GF_SampleEntryBox entry;
    GF_3GPPConfigBox *cfg_3gpp;
} GF_MPEGVisualSampleEntryBox;

typedef struct GF_SampleDescriptionBox {
    void *child_boxes;
} GF_SampleDescriptionBox;

typedef struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;

typedef struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_MediaBox {
    GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
} GF_TrackBox;

typedef struct GF_ISOFile {
    void *data;
} GF_ISOFile;

#define GF_EXPORT
#define GF_ISOM_SUBTYPE_3GP_AMR 0x73616D72
#define GF_ISOM_SUBTYPE_3GP_AMR_WB 0x73617762
#define GF_ISOM_SUBTYPE_3GP_EVRC 0x65767263
#define GF_ISOM_SUBTYPE_3GP_QCELP 0x71636C70
#define GF_ISOM_SUBTYPE_3GP_SMV 0x736D7670
#define GF_ISOM_SUBTYPE_3GP_H263 0x73323633
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 1
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 2

extern GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
extern void *gf_list_get(void *list, u32 index);
extern void *gf_malloc(size_t size);