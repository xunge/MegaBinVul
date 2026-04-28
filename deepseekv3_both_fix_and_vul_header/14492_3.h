#include <stdlib.h>

typedef unsigned int u32;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;
typedef struct GF_AVCConfig GF_AVCConfig;
typedef struct GF_List GF_List;

#define GF_EXPORT
#define GF_ISOM_AVCTYPE_NONE 0
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 0

struct GF_SampleDescriptionBox {
    GF_List *child_boxes;
};

struct GF_SampleTableBox {
    struct GF_SampleDescriptionBox *SampleDescription;
};

struct GF_MediaInformationBox {
    struct GF_SampleTableBox *sampleTable;
};

struct GF_MediaBox {
    struct GF_MediaInformationBox *information;
};

struct GF_TrackBox {
    struct GF_MediaBox *Media;
};

struct GF_AVCConfigurationBox {
    GF_AVCConfig *config;
};

struct GF_MPEGVisualSampleEntryBox {
    u32 internal_type;
    struct GF_AVCConfigurationBox *svc_config;
};

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
u32 gf_isom_get_avc_svc_type(GF_ISOFile *the_file, u32 trackNumber, u32 DescriptionIndex);
GF_AVCConfig *AVC_DuplicateConfig(GF_AVCConfig *config);
void *gf_list_get(GF_List *list, u32 position);